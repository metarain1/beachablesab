<?php

require_once(get_template_directory().'/framework/lib/eltd.kses.php');
require_once(get_template_directory().'/framework/lib/eltd.layout.inc');
require_once(get_template_directory().'/framework/lib/google-fonts.inc');
require_once(get_template_directory().'/framework/lib/eltd.framework.php');
require_once(get_template_directory().'/framework/lib/eltd.functions.php');
require_once(get_template_directory().'/framework/lib/eltd.common.php');
require_once(get_template_directory().'/framework/lib/eltd.icons/eltd.icons.php');
require_once(get_template_directory().'/framework/admin/options/eltd-options-setup.php');
require_once(get_template_directory().'/framework/admin/meta-boxes/eltd-meta-boxes-setup.php');

global $eltdFramework;

if(!function_exists('eltd_moose_admin_scripts_init')) {
	/**
	 * Function that registers all scripts that are necessary for our back-end
	 */
	function eltd_moose_admin_scripts_init() {
		wp_register_style('eltdf-jquery-ui', get_template_directory_uri().'/framework/admin/assets/css/jquery-ui/jquery-ui.css');
		wp_register_script('eltdf-dependence', get_template_directory_uri().'/framework/admin/assets/js/eltdf-ui/eltdf-dependence.js');
		wp_register_script('eltdf-twitter-connect', get_template_directory_uri().'/framework/admin/assets/js/eltdf-twitter-connect.js');

        /**
         * @see ElatedSkinAbstract::registerScripts - hooked with 10
         * @see ElatedSkinAbstract::registerStyles - hooked with 10
         */
        do_action('eltd_moose_admin_scripts_init');
	}

	add_action('admin_init', 'eltd_moose_admin_scripts_init');
}

if(!function_exists('eltd_moose_enqueue_admin_styles')) {
	/**
	 * Function that enqueues styles for options page
	 */
	function eltd_moose_enqueue_admin_styles() {
		wp_enqueue_style('wp-color-picker');

        /**
         * @see ElatedSkinAbstract::enqueueStyles - hooked with 10
         */
        do_action('eltd_moose_enqueue_admin_styles');
	}
}

if(!function_exists('eltd_moose_enqueue_admin_scripts')) {
	/**
	 * Function that enqueues styles for options page
	 */
	function eltd_moose_enqueue_admin_scripts() {
		wp_enqueue_script('wp-color-picker');
		wp_enqueue_script('jquery-ui-datepicker');
		wp_enqueue_script('jquery-ui-accordion');
		wp_enqueue_script('common');
		wp_enqueue_script('wp-lists');
		wp_enqueue_script('postbox');
		wp_enqueue_media();
		wp_enqueue_script('eltdf-dependence');
		wp_enqueue_script('eltdf-twitter-connect');

        /**
         * @see ElatedSkinAbstract::enqueueScripts - hooked with 10
         */
        do_action('eltd_moose_enqueue_admin_scripts');
	}
}

if(!function_exists('eltd_moose_enqueue_meta_box_styles')) {
	/**
	 * Function that enqueues styles for meta boxes
	 */
	function eltd_moose_enqueue_meta_box_styles() {
		wp_enqueue_style( 'wp-color-picker' );

        /**
         * @see ElatedSkinAbstract::enqueueStyles - hooked with 10
         */
        do_action('eltd_moose_enqueue_meta_box_styles');
	}
}

if(!function_exists('eltd_moose_enqueue_meta_box_scripts')) {
	/**
	 * Function that enqueues scripts for meta boxes
	 */
	function eltd_moose_enqueue_meta_box_scripts() {
		wp_enqueue_script('wp-color-picker');
		wp_enqueue_script('jquery-ui-datepicker');
		wp_enqueue_script('jquery-ui-accordion');
		wp_enqueue_script('common');
		wp_enqueue_script('wp-lists');
		wp_enqueue_script('postbox');
		wp_enqueue_media();
		wp_enqueue_script('eltdf-dependence');

        /**
         * @see ElatedSkinAbstract::enqueueScripts - hooked with 10
         */
        do_action('eltd_moose_enqueue_meta_box_scripts');
	}
}

if(!function_exists('eltd_moose_enqueue_nav_menu_script')) {
	/**
	 * Function that enqueues styles and scripts necessary for menu administration page.
	 * It checks $hook variable
	 * @param $hook string current page hook to check
	 */
	function eltd_moose_enqueue_nav_menu_script($hook) {
		if($hook == 'nav-menus.php') {
			wp_enqueue_script('eltdf-nav-menu', get_template_directory_uri().'/framework/admin/assets/js/eltdf-nav-menu.js');
			wp_enqueue_style('eltdf-nav-menu', get_template_directory_uri().'/framework/admin/assets/css/eltdf-nav-menu.css');
		}
	}

	add_action('admin_enqueue_scripts', 'eltd_moose_enqueue_nav_menu_script');
}


if(!function_exists('eltd_moose_enqueue_widgets_admin_script')) {
	/**
	 * Function that enqueues styles and scripts for admin widgets page.
	 * @param $hook string current page hook to check
	 */
	function eltd_moose_enqueue_widgets_admin_script($hook) {
		if($hook == 'widgets.php') {
			wp_enqueue_script('eltdf-dependence');
		}
	}

	add_action('admin_enqueue_scripts', 'eltd_moose_enqueue_widgets_admin_script');
}


if(!function_exists('eltd_moose_enqueue_styles_slider_taxonomy')) {
	/**
	 * Enqueue styles when on slider taxonomy page in admin
	 */
	function eltd_moose_enqueue_styles_slider_taxonomy() {
		if(isset($_GET['taxonomy']) && $_GET['taxonomy'] == 'slides_category') {
			eltd_moose_enqueue_admin_styles();
		}
	}

	add_action('admin_print_scripts-edit-tags.php', 'eltd_moose_enqueue_styles_slider_taxonomy');
}

if(!function_exists('eltdf_moose_init_theme_options_array')) {
	/**
	 * Function that merges $eltd_moose_options and default options array into one array.
	 *
	 * @see array_merge()
	 */
	function eltdf_moose_init_theme_options_array() {
		global $eltd_moose_options, $eltdFramework;

		$db_options = get_option('eltd_options_moose');

		//does eltd_options exists in db?
		if(is_array($db_options)) {
			//merge with default options
			$eltd_moose_options  = array_merge($eltdFramework->eltdOptions->options, get_option('eltd_options_moose'));
		} else {
			//options don't exists in db, take default ones
			$eltd_moose_options = $eltdFramework->eltdOptions->options;
		}
	}

	//priority needs to be greater than 0, because theme options are initialized on after_setup_theme 0
	add_action('after_setup_theme', 'eltdf_moose_init_theme_options_array', 2);
}

if(!function_exists('eltd_moose_init_theme_options')) {
	/**
	 * Function that sets $eltd_moose_options variable if it does'nt exists
	 */
	function eltd_moose_init_theme_options() {
		global $eltd_moose_options;
		global $eltdFramework;
		if(isset($eltd_moose_options['reset_to_defaults'])) {
			if( $eltd_moose_options['reset_to_defaults'] == 'yes' ) delete_option( "eltd_options_moose");
		}

		if (!get_option("eltd_options_moose")) {
			add_option( "eltd_options_moose",
				$eltdFramework->eltdOptions->options
			);

			$eltd_moose_options = $eltdFramework->eltdOptions->options;
		}
	}
}

if(!function_exists('eltd_moose_theme_menu')) {
	/**
	 * Function that generates admin menu for options page.
	 * It generates one admin page per options page.
	 */
	function eltd_moose_theme_menu() {
		global $eltdFramework;
		eltd_moose_init_theme_options();

		$page_hook_suffix = add_menu_page(
			'Elated Options',                   // The value used to populate the browser's title bar when the menu page is active
			'Elated Options',                   // The text of the menu in the administrator's sidebar
			'administrator',                  // What roles are able to access the menu
			'eltd_moose_theme_menu',                // The ID used to bind submenu items to this menu
			array($eltdFramework->getSkin(), 'renderOptions'), // The callback function used to render this menu
			$eltdFramework->getSkin()->getMenuIcon('options'),             // Icon For menu Item
			$eltdFramework->getSkin()->getMenuItemPosition('options')            // Position
		);

		foreach ($eltdFramework->eltdOptions->adminPages as $key=>$value ) {
			$slug = "";

			if (!empty($value->slug)) {
				$slug = "_tab".$value->slug;
			}

			$subpage_hook_suffix = add_submenu_page(
				'eltd_moose_theme_menu',
				'Elated Options - '.$value->title,                   // The value used to populate the browser's title bar when the menu page is active
				$value->title,                   // The text of the menu in the administrator's sidebar
				'administrator',                  // What roles are able to access the menu
				'eltd_moose_theme_menu'.$slug,                // The ID used to bind submenu items to this menu
				array($eltdFramework->getSkin(), 'renderOptions')
			);

			add_action('admin_print_scripts-'.$subpage_hook_suffix, 'eltd_moose_enqueue_admin_scripts');
			add_action('admin_print_styles-'.$subpage_hook_suffix, 'eltd_moose_enqueue_admin_styles');
		};

		add_action('admin_print_scripts-'.$page_hook_suffix, 'eltd_moose_enqueue_admin_scripts');
		add_action('admin_print_styles-'.$page_hook_suffix, 'eltd_moose_enqueue_admin_styles');
	}

	add_action( 'admin_menu', 'eltd_moose_theme_menu' );
}

if(!function_exists('eltd_moose_register_theme_settings')) {
	/**
	 * Function that registers setting that will be used to store theme options
	 */
	function eltd_moose_register_theme_settings() {
		register_setting( 'eltd_moose_theme_menu', 'eltd_options' );
	}

	add_action('admin_init', 'eltd_moose_register_theme_settings');
}

if(!function_exists('eltd_moose_get_admin_tab')) {
	/**
	 * Helper function that returns current tab from url.
	 * @return null
	 */
	function eltd_moose_get_admin_tab(){
		return isset($_GET['page']) ? eltd_moose_strafter($_GET['page'],'tab') : NULL;
	}
}

if(!function_exists('eltd_moose_strafter')) {
	/**
	 * Function that returns string that comes after found string
	 * @param $string string where to search
	 * @param $substring string what to search for
	 * @return null|string string that comes after found string
	 */
	function eltd_moose_strafter($string, $substring) {
		$pos = strpos($string, $substring);
		if ($pos === false) {
			return NULL;
		}

		return(substr($string, $pos+strlen($substring)));
	}
}

if(!function_exists('eltdf_moose_save_options')) {
	/**
	 * Function that saves theme options to db.
	 * It hooks to ajax wp_ajax_eltdf_save_options action.
	 */
	function eltdf_moose_save_options() {
		global $eltd_moose_options;
		global $eltdFramework;

		if(current_user_can('administrator')) {

			$_REQUEST = stripslashes_deep($_REQUEST);

	        unset($_REQUEST['action']);

	        check_ajax_referer('eltd_ajax_save_nonce', 'eltd_ajax_save_nonce');

			$eltd_moose_options = array_merge($eltd_moose_options, $_REQUEST);

			update_option( 'eltd_options_moose', $eltd_moose_options );

			do_action('eltd_after_theme_option_save');
			echo "Saved";

			die();
		}
	}

	add_action('wp_ajax_eltdf_moose_save_options', 'eltdf_moose_save_options');
}

if(!function_exists('eltd_moose_meta_box_add')) {
	/**
	 * Function that adds all defined meta boxes.
	 * It loops through array of created meta boxes and adds them
	 */
	function eltd_moose_meta_box_add() {
		global $eltdFramework;


		foreach ($eltdFramework->eltdMetaBoxes->metaBoxes as $key=>$box ) {
			$hidden = false;
			if (!empty($box->hidden_property)) {
				foreach ($box->hidden_values as $value) {
					if (eltdf_moose_option_get_value($box->hidden_property)==$value)
						$hidden = true;

				}
			}

			add_meta_box(
				'eltdf-meta-box-'.$key,
				$box->title,
                'eltdf_moose_render_meta_box',
				$box->scope,
				'advanced',
				'high',
				array( 'box' => $box)
			);

			if ($hidden) {
				add_filter( 'postbox_classes_'.$box->scope.'_eltdf-meta-box-'.$key, 'eltd_moose_meta_box_add_hidden_class' );
			}
		}
		if ( eltd_moose_is_gutenberg_installed() ) {
			eltd_moose_enqueue_meta_box_styles();
		  	eltd_moose_enqueue_meta_box_scripts();
		}else{
			add_action('admin_enqueue_scripts', 'eltd_moose_enqueue_meta_box_styles');
			add_action('admin_enqueue_scripts', 'eltd_moose_enqueue_meta_box_scripts');
		}
	}

	add_action('add_meta_boxes', 'eltd_moose_meta_box_add');
}

if(!function_exists('eltd_moose_meta_box_save')) {
	/**
	 * Function that saves meta box to postmeta table
	 * @param $post_id int id of post that meta box is being saved
	 * @param $post WP_Post current post object
	 */
	function eltd_moose_meta_box_save( $post_id, $post ) {
		global $eltdFramework;

		$postTypes = array( "page", "post", "portfolio_page", "testimonials", "slides", "carousels", "masonry_gallery");

		if (!isset( $_POST[ '_wpnonce' ])) {
			return;
		}

		if (!current_user_can('edit_post', $post_id)) {
			return;
		}

		if (!in_array($post->post_type, $postTypes)) {
			return;
		}

		foreach ($eltdFramework->eltdMetaBoxes->options as $key=>$box ) {

			if (isset($_POST[$key]) && trim($_POST[$key] !== '')) {

				$value = $_POST[$key];

				update_post_meta( $post_id, $key, $value );
			} else {
				delete_post_meta( $post_id, $key );
			}
		}

		$portfolios = false;
		if (isset($_POST['optionLabel'])) {
			foreach ($_POST['optionLabel'] as $key => $value) {
				$portfolios_val[$key] = array('optionLabel'=>$value,'optionValue'=>$_POST['optionValue'][$key],'optionUrl'=>$_POST['optionUrl'][$key],'optionlabelordernumber'=>$_POST['optionlabelordernumber'][$key]);
				$portfolios = true;

			}
		}

		if ($portfolios) {
			update_post_meta( $post_id,  'eltd_portfolios', $portfolios_val );
		} else {
			delete_post_meta( $post_id, 'eltd_portfolios' );
		}

		$portfolio_images = false;
		if (isset($_POST['portfolioimg'])) {
			foreach ($_POST['portfolioimg'] as $key => $value) {
				$portfolio_images_val[$key] = array('portfolioimg'=>$_POST['portfolioimg'][$key],'portfoliotitle'=>$_POST['portfoliotitle'][$key],'portfolioimgordernumber'=>$_POST['portfolioimgordernumber'][$key], 'portfoliovideotype'=>$_POST['portfoliovideotype'][$key], 'portfoliovideoid'=>$_POST['portfoliovideoid'][$key], 'portfoliovideoimage'=>$_POST['portfoliovideoimage'][$key], 'portfoliovideowebm'=>$_POST['portfoliovideowebm'][$key], 'portfoliovideomp4'=>$_POST['portfoliovideomp4'][$key], 'portfoliovideoogv'=>$_POST['portfoliovideoogv'][$key], 'portfolioimgtype'=>$_POST['portfolioimgtype'][$key] );
				$portfolio_images = true;
			}
		}


		if ($portfolio_images) {
			update_post_meta( $post_id,  'eltd_portfolio_images', $portfolio_images_val );
		} else {
			delete_post_meta( $post_id,  'eltd_portfolio_images' );
		}
	}

	add_action( 'save_post', 'eltd_moose_meta_box_save', 1, 2 );
}

if(!function_exists('eltdf_moose_render_meta_box')) {
	/**
	 * Function that renders meta box
	 * @param $post WP_Post post object
	 * @param $metabox array array of current meta box parameters
	 */
	function eltdf_moose_render_meta_box($post, $metabox) {?>
		<div class="eltdf-meta-box eltdf-page">
			<div class="eltdf-meta-box-holder">

				<?php $metabox["args"]["box"]->render(); ?>

			</div>
		</div>
	<?php
	}
}

if(!function_exists('eltd_moose_meta_box_add_hidden_class')) {
	/**
	 * Function that adds class that will initially hide meta box
	 * @param array $classes array of classes
	 * @return array modified array of classes
	 */
	function eltd_moose_meta_box_add_hidden_class( $classes=array() ) {
		if( !in_array( 'eltdf-meta-box-hidden', $classes ) )
			$classes[] = 'eltdf-meta-box-hidden';

		return $classes;
	}

}

if(!function_exists('eltd_moose_remove_default_custom_fields')) {
	/**
	 * Function that removes default WordPress custom fields interface
	 */
	function eltd_moose_remove_default_custom_fields() {
		foreach ( array( 'normal', 'advanced', 'side' ) as $context ) {
			foreach ( array( "page", "post", "portfolio_page", "testimonials", "slides", "carousels" ) as $postType ) {
				remove_meta_box( 'postcustom', $postType, $context );
			}
		}
	}

	add_action('do_meta_boxes', 'eltd_moose_remove_default_custom_fields');
}


if(!function_exists('eltd_moose_get_custom_sidebars')) {
	/**
	 * Function that returns all custom made sidebars.
	 *
	 * @uses get_option()
	 * @return array array of custom made sidebars where key and value are sidebar name
	 */
	function eltd_moose_get_custom_sidebars() {
		$custom_sidebars = get_option('eltd_sidebars');
		$formatted_array = array();

		if(is_array($custom_sidebars) && count($custom_sidebars)) {
			foreach ($custom_sidebars as $custom_sidebar) {
				$formatted_array[sanitize_title($custom_sidebar)] = $custom_sidebar;
			}
		}

		return $formatted_array;
	}
}

if(!function_exists('eltd_moose_generate_icon_pack_options')) {
    /**
     * Generates options HTML for each icon in given icon pack
     * Hooked to wp_ajax_update_admin_nav_icon_options action
     */
    function eltd_moose_generate_icon_pack_options() {
        global $eltdIconCollections;

        $html = '';
        $icon_pack = isset($_POST['icon_pack']) ? $_POST['icon_pack'] : '';
        $collections_object = $eltdIconCollections->getIconCollection($icon_pack);

        if($collections_object) {
            $icons = $collections_object->getIconsArray();
            if(is_array($icons) && count($icons)) {
                foreach ($icons as $key => $icon) {
                    $html .= '<option value="'.esc_attr($key).'">'.esc_html($key).'</option>';
                }
            }
        }

        print $html;
    }

    add_action('wp_ajax_update_admin_nav_icon_options', 'eltd_moose_generate_icon_pack_options');
}

if(!function_exists('eltd_moose_admin_notice')) {
    /**
     * Prints admin notice. It checks if notice has been disabled and if it hasn't then it displays it
     * @param $id string id of notice. It will be used to store notice dismis
     * @param $message string message to show to the user
     * @param $class string HTML class of notice
     * @param bool $is_dismisable whether notice is dismisable or not
     */
    function eltd_moose_admin_notice($id, $message, $class, $is_dismisable = true) {
        $is_dismised = get_user_meta(get_current_user_id(), 'dismis_'.$id);

        //if notice isn't dismissed
        if(!$is_dismised && is_admin()) {
            echo '<div style="display: block;" class="'.esc_attr($class).' is-dismissible notice">';
            echo '<p>';

            echo wp_kses_post($message);

            if($is_dismisable) {
                echo '<strong style="display: block; margin-top: 7px;"><a href="'.esc_url(add_query_arg('eltd_dismis_notice', $id)).'">'.__('Dismiss this notice', 'eltd').'</a></strong>';
            }

            echo '</p>';

            echo '</div>';
        }

    }
}

if(!function_exists('eltd_moose_save_dismisable_notice')) {
    /**
     * Updates user meta with dismisable notice. Hooks to admin_init action
     * in order to check this on every page request in admin
     */
    function eltd_moose_save_dismisable_notice() {
        if(is_admin() && !empty($_GET['eltd_dismis_notice'])) {
            $notice_id = sanitize_key($_GET['eltd_dismis_notice']);
            $current_user_id = get_current_user_id();

            update_user_meta($current_user_id, 'dismis_'.$notice_id, 1);
        }
    }

    add_action('admin_init', 'eltd_moose_save_dismisable_notice');
}

if(!function_exists('eltd_moose_hook_twitter_request_ajax')) {
    /**
     * Wrapper function for obtaining twitter request token.
     * Hooks to wp_ajax_eltd_twitter_obtain_request_token ajax action
     *
     * @see ElatedTwitterApi::obtainRequestToken()
     */
    function eltd_moose_hook_twitter_request_ajax() {
        ElatedTwitterApi::getInstance()->obtainRequestToken();
    }

    add_action('wp_ajax_eltd_twitter_obtain_request_token', 'eltd_moose_hook_twitter_request_ajax');
}
?>