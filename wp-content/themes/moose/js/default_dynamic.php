<?php
$absolute_path = explode('wp-content', $_SERVER['SCRIPT_FILENAME']);

if(count($absolute_path) == 1) {
    $absolute_path = explode('wp-admin', $_SERVER['SCRIPT_FILENAME']);
}

$wp_load = $absolute_path[0] . 'wp-load.php';
require_once($wp_load);

header('Content-type: application/x-javascript');
?>

var header_height = 110;
var min_header_height_scroll = 57;
var min_header_height_sticky = 60;
var scroll_amount_for_sticky = 85;
var min_header_height_fixed_hidden = 45;
var header_bottom_border_weight = 1;
var scroll_amount_for_fixed_hiding = 200;
var menu_item_margin = 0;
var large_menu_item_border = 0;
var element_appear_amount = -150;
var paspartu_width_init = 0.02;
var directionNavArrows = 'arrow_carrot-';
var directionNavArrowsTestimonials = 'fa fa-angle-';
var enable_navigation_on_full_screen_section = false;
<?php
if(is_admin_bar_showing()){
?>
var add_for_admin_bar = 32;
<?php
}else{
?>
var add_for_admin_bar = 0;
<?php
}
?>
<?php if(isset($eltd_moose_options['header_height'])){
	if ($eltd_moose_options['header_height'] !== '') { ?>
	header_height = <?php echo esc_attr($eltd_moose_options['header_height']); ?>;
<?php } } ?>
<?php if(isset($eltd_moose_options['header_height_scroll'])){
	if ($eltd_moose_options['header_height_scroll'] !== "") { ?>
	min_header_height_scroll = <?php echo esc_attr($eltd_moose_options['header_height_scroll']); ?>;
<?php } } ?>
<?php if(isset($eltd_moose_options['header_height_sticky'])){
	if ($eltd_moose_options['header_height_sticky'] !== "") { ?>
	min_header_height_sticky = <?php echo esc_attr($eltd_moose_options['header_height_sticky']); ?>;
<?php } } ?>
<?php if(isset($eltd_moose_options['scroll_amount_for_sticky'])){
	if (!empty($eltd_moose_options['scroll_amount_for_sticky'])) { ?>
	scroll_amount_for_sticky = <?php echo esc_attr($eltd_moose_options['scroll_amount_for_sticky']); ?>;
<?php } } ?>
<?php if(isset($eltd_moose_options['header_height_scroll_hidden'])){
    if (!empty($eltd_moose_options['header_height_scroll_hidden'])) { ?>
    min_header_height_fixed_hidden = <?php echo esc_attr($eltd_moose_options['header_height_scroll_hidden']); ?>;
<?php } } ?>

<?php if(isset($eltd_moose_options['scroll_amount_for_fixed_hiding'])){
    if (!empty($eltd_moose_options['scroll_amount_for_fixed_hiding'])) { ?>
        scroll_amount_for_fixed_hiding = <?php echo esc_attr($eltd_moose_options['scroll_amount_for_fixed_hiding']); ?>;
<?php } } ?>

<?php
if(isset($eltd_moose_options['enable_manu_item_border']) && $eltd_moose_options['enable_manu_item_border']=='yes' && isset($eltd_moose_options['menu_item_style']) && $eltd_moose_options['menu_item_style']=='large_item'){
    if(isset($eltd_moose_options['menu_item_border_style']) && $eltd_moose_options['menu_item_border_style']=='all_borders'){ ?>
		large_menu_item_border = <?php echo esc_attr($eltd_moose_options['menu_item_border_width'])*2;
	} ?>
	<?php if(isset($eltd_moose_options['menu_item_border_style']) && $eltd_moose_options['menu_item_border_style']=='top_bottom_borders'){ ?>
		large_menu_item_border = <?php echo esc_attr($eltd_moose_options['menu_item_border_width'])*2;
	} ?>
	<?php if(isset($eltd_moose_options['menu_item_border_style']) && $eltd_moose_options['menu_item_border_style']=='bottom_border'){ ?>
		large_menu_item_border = <?php  echo esc_attr($eltd_moose_options['menu_item_border_width']);
	} ?>
<?php } ?>

<?php if(isset($eltd_moose_options['element_appear_amount']) && $eltd_moose_options['element_appear_amount'] !== ""){ ?>
    element_appear_amount = -<?php echo esc_attr($eltd_moose_options['element_appear_amount']); ?>;
<?php } ?>

<?php if(isset($eltd_moose_options['paspartu_width']) && $eltd_moose_options['paspartu_width'] !== ""){ ?>
    paspartu_width_init = <?php echo esc_attr($eltd_moose_options['paspartu_width'])/100; ?>;
<?php } ?>

var logo_height = 130; // moose logo height
var logo_width = 280; // moose logo width
	<?php 
		$logo_width = $eltd_moose_options['logo_width'];
		$logo_height = $eltd_moose_options['logo_height'];
	?>
    logo_width = <?php echo esc_attr($logo_width); ?>;
    logo_height = <?php echo esc_attr($logo_height); ?>;

<?php if(isset($eltd_moose_options['menu_margin_left_right'])){
	if ($eltd_moose_options['menu_margin_left_right'] !== '') { ?>
		menu_item_margin = <?php echo esc_attr($eltd_moose_options['menu_margin_left_right']); ?>;
<?php } } ?>
	
<?php if(isset($eltd_moose_options['header_top_area'])){
if ($eltd_moose_options['header_top_area'] == "yes") { ?>
<?php if(isset($eltd_moose_options['header_top_height']) && $eltd_moose_options['header_top_height'] !== ""){?>
header_top_height= <?php echo esc_attr($eltd_moose_options['header_top_height']);?>;
<?php } else { ?>
header_top_height = 36;
<?php } ?>
<?php } else { ?>
	header_top_height = 0;
<?php } }?>
var loading_text;
loading_text = '<?php _e('Loading new posts...', 'eltd'); ?>';
var finished_text;
finished_text = '<?php _e('No more posts', 'eltd'); ?>';

var piechartcolor;
piechartcolor	= "#e5735c";

<?php if(isset($eltd_moose_options['first_color']) && !empty($eltd_moose_options['first_color'])){ ?>
	piechartcolor = "<?php echo esc_attr($eltd_moose_options['first_color']); ?>";
<?php } ?>

<?php if(isset($eltd_moose_options['single_slider_navigation_arrows_type']) && $eltd_moose_options['single_slider_navigation_arrows_type'] != '') { ?>
	directionNavArrows = '<?php echo esc_attr($eltd_moose_options['single_slider_navigation_arrows_type']); ?>';
<?php } ?>

<?php if(isset($eltd_moose_options['testimonials_arrows_type']) && $eltd_moose_options['testimonials_arrows_type'] != '') { ?>
	directionNavArrowsTestimonials = '<?php echo esc_attr($eltd_moose_options['testimonials_arrows_type']); ?>';
<?php } ?>

<?php if(isset($eltd_moose_options['fs_navigation_slider_vertical_section_type']) && ($eltd_moose_options['fs_navigation_slider_vertical_section_type'] == 'bullets') || ($eltd_moose_options['fs_navigation_slider_vertical_section_type'] == 'both')) { ?>
    enable_navigation_on_full_screen_section = true;
<?php } ?>


var no_ajax_pages = [];
var eltd_root = '<?php echo home_url('/'); ?>';
var theme_root = '<?php echo ELATED_ROOT; ?>/';
<?php if($eltd_moose_options['header_style'] != ''){ ?>
var header_style_admin = "<?php echo esc_attr($eltd_moose_options['header_style']); ?>";
<?php }else{ ?>
var header_style_admin = "";
<?php } ?>
if(typeof no_ajax_obj !== 'undefined') {
no_ajax_pages = no_ajax_obj.no_ajax_pages;
}