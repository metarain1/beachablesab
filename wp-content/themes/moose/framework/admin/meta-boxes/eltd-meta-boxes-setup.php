<?php

add_action('after_setup_theme', 'eltd_meta_boxes_map_init', 1);
function eltd_meta_boxes_map_init() {
	global $eltd_moose_options;
	global $eltdFramework;
	global $eltd_moose_options_fontstyle;
	global $eltd_moose_options_fontweight;
	global $eltd_moose_options_texttransform;
	global $eltd_moose_options_fontdecoration;
	global $eltd_moose_options_arrows_type;
	global $eltd_moose_options_blockquote_type;
	require_once(get_template_directory().'/framework/admin/meta-boxes/page/map.inc');
	require_once(get_template_directory().'/framework/admin/meta-boxes/portfolio/map.inc');
	require_once(get_template_directory().'/framework/admin/meta-boxes/slides/map.inc');
	require_once(get_template_directory().'/framework/admin/meta-boxes/post/map.inc');
	require_once(get_template_directory().'/framework/admin/meta-boxes/testimonials/map.inc');
	require_once(get_template_directory().'/framework/admin/meta-boxes/carousels/map.inc');
	require_once(get_template_directory().'/framework/admin/meta-boxes/masonry_gallery/map.inc');
}