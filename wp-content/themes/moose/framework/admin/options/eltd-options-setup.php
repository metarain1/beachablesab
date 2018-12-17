<?php

add_action('after_setup_theme', 'eltd_moose_admin_map_init', 0);
function eltd_moose_admin_map_init() {
	global $eltd_moose_options;
	global $eltdFramework;
	global $eltd_moose_options_fontstyle;
	global $eltd_moose_options_fontweight;
	global $eltd_moose_options_texttransform;
	global $eltd_moose_options_fontdecoration;
	global $eltd_moose_options_arrows_type;
	global $eltd_moose_options_blockquote_type;
	global $eltd_moose_options_double_arrows_type;
	global $eltd_moose_options_arrows_up_type;
	require_once(get_template_directory().'/framework/admin/options/10.general/map.inc');
	require_once(get_template_directory().'/framework/admin/options/20.logo/map.inc');
	require_once(get_template_directory().'/framework/admin/options/30.header/map.inc');
    require_once(get_template_directory().'/framework/admin/options/40.title/map.inc');
    require_once(get_template_directory().'/framework/admin/options/50.content/map.inc');
	require_once(get_template_directory().'/framework/admin/options/60.footer/map.inc');
    require_once(get_template_directory().'/framework/admin/options/70.fonts/map.inc');
	require_once(get_template_directory().'/framework/admin/options/80.elements/map.inc');
	require_once(get_template_directory().'/framework/admin/options/90.blog/map.inc');
	require_once(get_template_directory().'/framework/admin/options/100.portfolio/map.inc');
	require_once(get_template_directory().'/framework/admin/options/110.slider/map.inc');
	require_once(get_template_directory().'/framework/admin/options/120.social/map.inc');
	require_once(get_template_directory().'/framework/admin/options/130.error404/map.inc');
	if(eltd_moose_visual_composer_installed() && version_compare(eltd_moose_get_vc_version(), '4.4.2') >= 0) {
		require_once(get_template_directory().'/framework/admin/options/140.visualcomposer/map.inc');
	} else {
		$eltdFramework->eltdOptions->addOption('enable_grid_elements','no');
	}
    if(eltd_moose_contact_form_7_installed()) {
        require_once(get_template_directory().'/framework/admin/options/150.contactform7/map.inc');
    }
	if(function_exists('is_woocommerce')){
		require_once(get_template_directory().'/framework/admin/options/160.woocommerce/map.inc');
	}
	require_once(get_template_directory().'/framework/admin/options/170.reset/map.inc');
}