<?php
if (!function_exists ('add_action')) {
    header('Status: 403 Forbidden');
    header('HTTP/1.1 403 Forbidden');
    exit();
}
class Elated_Moose_Import {

    public $message = "";
    public $attachments = false;
    function __construct() {
        add_action('admin_menu', array(&$this, 'eltd_admin_import'));
        add_action('admin_init', array(&$this, 'eltd_register_theme_settings'));

    }
    function eltd_register_theme_settings() {
        register_setting( 'eltd_options_import_page', 'eltd_options_import');
    }

    function init_eltd_import() {
        if(isset($_REQUEST['import_option'])) {
            $import_option = $_REQUEST['import_option'];
            if($import_option == 'content'){
                $this->import_content('proya_content.xml');
            }elseif($import_option == 'custom_sidebars') {
                $this->import_custom_sidebars('custom_sidebars.txt');
            } elseif($import_option == 'widgets') {
                $this->import_widgets('widgets.txt','custom_sidebars.txt');
            } elseif($import_option == 'options'){
                $this->import_options('options.txt');
            }elseif($import_option == 'menus'){
                $this->import_menus('menus.txt');
            }elseif($import_option == 'settingpages'){
                $this->import_settings_pages('settingpages.txt');
            }elseif($import_option == 'complete_content'){
                $this->import_content('proya_content.xml');
                $this->import_options('options.txt');
                $this->import_widgets('widgets.txt','custom_sidebars.txt');
                $this->import_menus('menus.txt');
                $this->import_settings_pages('settingpages.txt');
                $this->message = __("Content imported successfully", "eltd");
            }
        }
    }

    public function import_content($file){
        ob_start();
        $class_wp_importer = ABSPATH . 'wp-admin/includes/class-wp-importer.php';
        require_once($class_wp_importer);
        require_once(get_template_directory() . '/includes/import/class.wordpress-importer.php');
        $eltd_import = new WP_Import();
        set_time_limit(0);
        $path = get_template_directory() . '/includes/import/files/' . $file;

        $eltd_import->fetch_attachments = $this->attachments;
        $returned_value = $eltd_import->import($file);
        if(is_wp_error($returned_value)){
            $this->message = __("An Error Occurred During Import", "eltd");
        }
        else {
            $this->message = __("Content imported successfully", "eltd");
        }
        ob_get_clean();
    }

    public function import_widgets($file, $file2){
        $this->import_custom_sidebars($file2);
        $options = $this->file_options($file);
        foreach ((array) $options['widgets'] as $eltd_widget_id => $eltd_widget_data) {
            update_option( 'widget_' . $eltd_widget_id, $eltd_widget_data );
        }
        $this->import_sidebars_widgets($file);
        $this->message = __("Widgets imported successfully", "eltd");
    }

    public function import_sidebars_widgets($file){
        $eltd_sidebars = get_option("sidebars_widgets");
        unset($eltd_sidebars['array_version']);
        $data = $this->file_options($file);
        if ( is_array($data['sidebars']) ) {
            $eltd_sidebars = array_merge( (array) $eltd_sidebars, (array) $data['sidebars'] );
            unset($eltd_sidebars['wp_inactive_widgets']);
            $eltd_sidebars = array_merge(array('wp_inactive_widgets' => array()), $eltd_sidebars);
            $eltd_sidebars['array_version'] = 2;
            wp_set_sidebars_widgets($eltd_sidebars);
        }
    }

    public function import_custom_sidebars($file){
        $options = $this->file_options($file);
        update_option( 'eltd_sidebars', $options);
        $this->message = __("Custom sidebars imported successfully", "eltd");
    }

    public function import_options($file){
        $options = $this->file_options($file);
        update_option( 'eltd_options_moose', $options);
        $this->message = __("Options imported successfully", "eltd");
    }

    public function import_menus($file){
        global $wpdb;
        $eltd_terms_table = $wpdb->prefix . "terms";
        $this->menus_data = $this->file_options($file);
        $menu_array = array();
        foreach ($this->menus_data as $registered_menu => $menu_slug) {
            $term_rows = $wpdb->get_results($wpdb->prepare("SELECT * FROM $eltd_terms_table where slug=%s", $menu_slug), ARRAY_A);
            if(isset($term_rows[0]['term_id'])) {
                $term_id_by_slug = $term_rows[0]['term_id'];
            } else {
                $term_id_by_slug = null;
            }
            $menu_array[$registered_menu] = $term_id_by_slug;
        }
        set_theme_mod('nav_menu_locations', array_map('absint', $menu_array ) );

    }
    public function import_settings_pages($file){
        $pages = $this->file_options($file);
        foreach($pages as $eltd_page_option => $eltd_page_id){
            update_option( $eltd_page_option, $eltd_page_id);
        }
    }

    public function file_options($file){
        $file_content = "";
        $file_for_import = get_template_directory() . '/includes/import/files/' . $file;
        /*if ( file_exists($file_for_import) ) {
            $file_content = $this->eltd_file_contents($file_for_import);
        } else {
            $this->message = __("File doesn't exist", "eltd");
        }*/
        $file_content = $this->eltd_file_contents($file);
        if ($file_content) {
            $unserialized_content = unserialize(base64_decode($file_content));
            if ($unserialized_content) {
                return $unserialized_content;
            }
        }
        return false;
    }

    function eltd_file_contents( $path ) {
		$url      = "http://export.elated-themes.com/".$path;
		$response = wp_remote_get($url);
		$body     = wp_remote_retrieve_body($response);
		return $body;
    }

    function eltd_admin_import() {
        global $eltdFramework;

		$slug = "_tabimport";
		$this->pagehook = add_submenu_page(
			'eltd_moose_theme_menu',
			'Elated Options - Elated Import',                   // The value used to populate the browser's title bar when the menu page is active
			'Import',                   // The text of the menu in the administrator's sidebar
			'administrator',                  // What roles are able to access the menu
			'eltd_moose_theme_menu'.$slug,                // The ID used to bind submenu items to this menu
			array($eltdFramework->getSkin(), 'renderImport')
		);

        add_action('admin_print_scripts-'.$this->pagehook, 'eltd_moose_enqueue_admin_scripts');
        add_action('admin_print_styles-'.$this->pagehook, 'eltd_moose_enqueue_admin_styles');
        //$this->pagehook = add_menu_page('Elated Import', 'Elated Import', 'manage_options', 'eltd_options_import_page', array(&$this, 'eltd_generate_import_page'),'dashicons-download');
    }

}
global $eltd_import_object;
$eltd_import_object = new Elated_Moose_Import();



if(!function_exists('eltd_dataImport')){
    function eltd_dataImport(){
        global $eltd_import_object;

        if ($_POST['import_attachments'] == 1)
            $eltd_import_object->attachments = true;
        else
            $eltd_import_object->attachments = false;

        $folder = "moose1/";
        if (!empty($_POST['example']))
            $folder = $_POST['example']."/";

        $eltd_import_object->import_content($folder.$_POST['xml']);

        die();
    }

    add_action('wp_ajax_eltd_dataImport', 'eltd_dataImport');
}

if(!function_exists('eltd_widgetsImport')){
    function eltd_widgetsImport(){
        global $eltd_import_object;

        $folder = "moose1/";
        if (!empty($_POST['example']))
            $folder = $_POST['example']."/";

        $eltd_import_object->import_widgets($folder.'widgets.txt',$folder.'custom_sidebars.txt');

        die();
    }

    add_action('wp_ajax_eltd_widgetsImport', 'eltd_widgetsImport');
}

if(!function_exists('eltd_optionsImport')){
    function eltd_optionsImport(){
        global $eltd_import_object;

        $folder = "moose1/";
        if (!empty($_POST['example']))
            $folder = $_POST['example']."/";

        $eltd_import_object->import_options($folder.'options.txt');

        die();
    }

    add_action('wp_ajax_eltd_optionsImport', 'eltd_optionsImport');
}

if(!function_exists('eltd_otherImport')){
    function eltd_otherImport(){
        global $eltd_import_object;

        $folder = "moose1/";
        if (!empty($_POST['example']))
            $folder = $_POST['example']."/";

        $eltd_import_object->import_options($folder.'options.txt');
        $eltd_import_object->import_widgets($folder.'widgets.txt',$folder.'custom_sidebars.txt');
        $eltd_import_object->import_menus($folder.'menus.txt');
        $eltd_import_object->import_settings_pages($folder.'settingpages.txt');

        die();
    }

    add_action('wp_ajax_eltd_otherImport', 'eltd_otherImport');
}