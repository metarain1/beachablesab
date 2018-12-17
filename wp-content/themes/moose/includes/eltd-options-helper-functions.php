<?php

if(!function_exists('eltd_moose_is_responsive_on')) {
    /**
     * Checks whether responsive mode is enabled in theme options
     * @return bool
     */
    function eltd_moose_is_responsive_on() {
        global $eltd_moose_options;

        return isset($eltd_moose_options['responsiveness']) && $eltd_moose_options['responsiveness'] !== 'no';
    }
}

if(!function_exists('eltd_moose_is_seo_enabled')) {
    /**
     * Checks if SEO is enabled in theme options
     * @return bool
     */
    function eltd_moose_is_seo_enabled() {
        global $eltd_moose_options;

        return isset($eltd_moose_options['disable_eltd_seo']) && $eltd_moose_options['disable_eltd_seo'] == 'no';
    }
}

if(!function_exists('eltd_moose_is_ios_format_detection_disabled')){
    /**
     * Checks whether iOS format detection is enabled in theme options
     * @return bool
     */
    function eltd_moose_is_ios_format_detection_disabled(){
        global $eltd_moose_options;

        return isset($eltd_moose_options['ios_format_detection']) && $eltd_moose_options['ios_format_detection'] == 'yes';
    }
}

if(!function_exists('eltd_moose_get_header_variables')) {
    function eltd_moose_get_header_variables() {
        global $eltd_moose_options;

        //init variables
        $id = eltd_moose_get_page_id();
        $loading_animation = true;
        $loading_image =  "";
        $enable_side_area = "yes";
        $enable_popup_menu = "no";
        $popup_menu_animation_style = '';
        $enable_fullscreen_search = "no";
        $fullscreen_search_animation = "fade";
        $fullscreen_search_in_header_top = "";
        $header_button_size = '';
        $paspartu_header_alignment = false;
        $header_in_grid = true;
        $header_bottom_class = ' header_in_grid';
        $menu_item_icon_position = "";
        $menu_position = "";
        $centered_logo = eltd_moose_is_logo_centered();
        $enable_border_top_bottom_menu = false;
        $menu_dropdown_appearance_class = "";
		$menu_hover_animation_class = "";
        $logo_wrapper_style = "";
        $divided_left_menu_padding = "";
        $divided_right_menu_padding = "";
        $display_header_top = "yes";
        $header_top_area_scroll = "no";
        $header_style = eltd_moose_get_header_style();
        $header_color_transparency_per_page = eltd_moose_get_header_transparency();
        $header_color_per_page = "";
        $header_top_color_per_page = "";
        $header_color_transparency_on_scroll = "";
        $header_bottom_border_style = '';
        $header_bottom_appearance = 'fixed';
        $header_transparency = '';
        $enable_vertical_menu = false;
        $enable_search_left_sidearea_right = false;
        $vertical_area_background_image = "";
        $vertical_menu_style = "toggle";
        $vertical_area_scroll = " with_scroll";
        $page_vertical_area_background_transparency = "";
        $page_vertical_area_background = "";
        $header_search_type = "";
        $frame_around_content_class = '';
        $content_class = '';
        $paspartu_additional_classes = '';
        $eltd_back_to_top_button_styles = '';

        if (isset($eltd_moose_options['loading_animation'])) {
            if($eltd_moose_options['loading_animation'] == "off") {
                $loading_animation = false;
            }
        }

        if (isset($eltd_moose_options['loading_image']) && $eltd_moose_options['loading_image'] != "") {
            $loading_image = $eltd_moose_options['loading_image'];
        }

        if (isset($eltd_moose_options['enable_side_area'])) {
            if($eltd_moose_options['enable_side_area'] == "no") {
                $enable_side_area = "no";
            }
        }

        if (isset($eltd_moose_options['enable_popup_menu'])) {
            if($eltd_moose_options['enable_popup_menu'] == "yes" && has_nav_menu('popup-navigation')) {
                $enable_popup_menu = "yes";
            }

            if (isset($eltd_moose_options['popup_menu_animation_style']) && !empty($eltd_moose_options['popup_menu_animation_style'])) {
                $popup_menu_animation_style = $eltd_moose_options['popup_menu_animation_style'];
            }
        }

        if(isset($eltd_moose_options['enable_search']) && $eltd_moose_options['enable_search'] == "yes" && isset($eltd_moose_options['search_type']) && $eltd_moose_options['search_type'] == "fullscreen_search" ){
            $enable_fullscreen_search="yes";
        }

        if(isset($eltd_moose_options['search_type']) && $eltd_moose_options['search_type'] == "fullscreen_search" && isset($eltd_moose_options['search_animation']) && $eltd_moose_options['search_animation'] !== "" ){
            $fullscreen_search_animation = $eltd_moose_options['search_animation'];
        }

        if(isset($eltd_moose_options['search_icon_in_header_top']) && $eltd_moose_options['search_icon_in_header_top'] == 'yes'){
        	$fullscreen_search_in_header_top = " fullscreen_search_in_header_top";
        }

        if(isset($eltd_moose_options['header_buttons_size'])){
            $header_button_size = $eltd_moose_options['header_buttons_size'];
        }

        if(isset($eltd_moose_options['paspartu_header_alignment'])
            && $eltd_moose_options['paspartu_header_alignment'] == 'yes'
            && isset($eltd_moose_options['paspartu'])
            && $eltd_moose_options['paspartu'] == 'yes') {
            $paspartu_header_alignment = true;
        }

        if ($eltd_moose_options['header_in_grid'] == "no" || $paspartu_header_alignment){
            $header_in_grid = false;
        }

        if($header_in_grid) {
            $header_bottom_class = ' header_in_grid';
        } else {
            $header_bottom_class = ' header_full_width';
        }

        if(isset($eltd_moose_options['menu_item_icon_position'])) {
            $menu_item_icon_position = $eltd_moose_options['menu_item_icon_position'];
        }

        if(isset($eltd_moose_options['menu_position'])) {
            $menu_position = $eltd_moose_options['menu_position'];
        }


        if(isset($eltd_moose_options['enable_border_top_bottom_menu']) && $eltd_moose_options['enable_border_top_bottom_menu'] == "yes") {
            $enable_border_top_bottom_menu = true;
        }

        if(isset($eltd_moose_options['menu_dropdown_appearance']) && $eltd_moose_options['menu_dropdown_appearance'] != "default"){
            $menu_dropdown_appearance_class = $eltd_moose_options['menu_dropdown_appearance'];
        }
		
		if(isset($eltd_moose_options['menu_item_hover_animation']) && $eltd_moose_options['menu_item_hover_animation'] != "default" ){
			$menu_hover_animation_class = $eltd_moose_options['menu_item_hover_animation'];
		}

        if(isset($eltd_moose_options['header_bottom_appearance']) && $eltd_moose_options['header_bottom_appearance'] == "stick_with_left_right_menu"){
            $logo_wrapper_style = 'width:'.(esc_attr($eltd_moose_options['logo_width'])/2).'px;';
            $divided_left_menu_padding = 'padding-right:'.(esc_attr($eltd_moose_options['logo_width'])/4).'px;';
            $divided_right_menu_padding = 'padding-left:'.(esc_attr($eltd_moose_options['logo_width'])/4).'px;';
        }

        if($eltd_moose_options['center_logo_image'] == "yes" && $eltd_moose_options['header_bottom_appearance'] == "regular"){
            $logo_wrapper_style = 'height:'.(esc_attr($eltd_moose_options['logo_height'])/2).'px;';
        }

        if(isset($eltd_moose_options['header_bottom_appearance']) && $eltd_moose_options['header_bottom_appearance'] == "fixed_top_header"){
            $logo_wrapper_style = 'height:'.(esc_attr($eltd_moose_options['logo_height'])/2).'px;';
        }

        if(isset($eltd_moose_options['header_top_area'])){
            $display_header_top = $eltd_moose_options['header_top_area'];
        }

        if(isset($eltd_moose_options['header_top_area_scroll'])){
            $header_top_area_scroll = $eltd_moose_options['header_top_area_scroll'];
        }

        if(get_post_meta($id, "eltd_header_color_per_page", true) != ""){
            if($header_color_transparency_per_page != ""){
                $header_background_color = eltd_moose_hex2rgb(esc_attr(get_post_meta($id, "eltd_header_color_per_page", true)));
                $header_color_per_page .= "background-color:rgba(" . $header_background_color[0] . ", " . $header_background_color[1] . ", " . $header_background_color[2] . ", " . $header_color_transparency_per_page . ");";
            }else{
                $header_color_per_page .= "background-color:" . esc_attr(get_post_meta($id, "eltd_header_color_per_page", true)) . ";";
            }
        } else if($header_color_transparency_per_page != "" && get_post_meta($id, "eltd_header_color_per_page", true) == ""){
            $header_background_color = $eltd_moose_options['header_background_color'] ? eltd_moose_hex2rgb(esc_attr($eltd_moose_options['header_background_color'])) : eltd_moose_hex2rgb("#ffffff");
            $header_color_per_page .= "background-color:rgba(" . $header_background_color[0] . ", " . $header_background_color[1] . ", " . $header_background_color[2] . ", " . $header_color_transparency_per_page . ");";
        }

        if(isset($eltd_moose_options['header_botom_border_in_grid']) && $eltd_moose_options['header_botom_border_in_grid'] != "yes" && get_post_meta($id, "eltd_header_bottom_border_color", true) != ""){
            $header_color_per_page .= "border-bottom: 1px solid ".esc_attr(get_post_meta($id, "eltd_header_bottom_border_color", true)).";";
        }

        if(get_post_meta($id, "eltd_header_color_per_page", true) != ""){
            if($header_color_transparency_per_page != ""){
                $header_background_color = eltd_moose_hex2rgb(esc_attr(get_post_meta($id, "eltd_header_color_per_page", true)));
                $header_top_color_per_page .= "background-color:rgba(" . esc_attr($header_background_color[0]) . ", " . esc_attr($header_background_color[1]) . ", " . esc_attr($header_background_color[2]) . ", " . esc_attr($header_color_transparency_per_page) . ");";
            }else{
                $header_top_color_per_page .= "background-color:" . esc_attr(get_post_meta($id, "eltd_header_color_per_page", true)) . ";";
            }
        } else if($header_color_transparency_per_page != "" && get_post_meta($id, "eltd_header_color_per_page", true) == ""){
            $header_background_color = $eltd_moose_options['header_top_background_color'] ? eltd_moose_hex2rgb(esc_attr($eltd_moose_options['header_top_background_color'])) : eltd_moose_hex2rgb("#ffffff");
            $header_top_color_per_page .= "background-color:rgba(" . esc_attr($header_background_color[0]) . ", " . esc_attr($header_background_color[1]) . ", " . esc_attr($header_background_color[2]) . ", " . esc_attr($header_color_transparency_per_page) . ");";
        }

        if(isset($eltd_moose_options['header_background_transparency_sticky']) && $eltd_moose_options['header_background_transparency_sticky'] != ""){
            $header_color_transparency_on_scroll = $eltd_moose_options['header_background_transparency_sticky'];
        }

        if(isset($eltd_moose_options['header_botom_border_in_grid']) && $eltd_moose_options['header_botom_border_in_grid'] == "yes" && get_post_meta($id, "eltd_header_bottom_border_color", true) != ""){
            $header_bottom_border_style = 'border-bottom: 1px solid '.esc_attr(get_post_meta($id, "eltd_header_bottom_border_color", true)).';';
        }

        if(isset($eltd_moose_options['header_bottom_appearance'])){
            $header_bottom_appearance = $eltd_moose_options['header_bottom_appearance'];
        }

        $per_page_header_transparency = esc_attr(get_post_meta($id, 'eltd_header_color_transparency_per_page', true));
        if($per_page_header_transparency !== '' && $per_page_header_transparency !== false) {
            $header_transparency = $per_page_header_transparency;
        } else {
            $header_transparency = esc_attr($eltd_moose_options['header_background_transparency_initial']);
        }

        if(eltd_moose_is_side_header()){
            $enable_vertical_menu = true;
        }

        if(isset($eltd_moose_options['header_bottom_appearance']) && $eltd_moose_options['header_bottom_appearance'] =='fixed_hiding'){
            if(isset($eltd_moose_options['search_left_sidearea_right']) && $eltd_moose_options['search_left_sidearea_right'] =='yes'){
                $enable_search_left_sidearea_right = true;
            }
        }else{
            if(isset($eltd_moose_options['search_left_sidearea_right_regular']) && $eltd_moose_options['search_left_sidearea_right_regular'] =='yes'){
                $enable_search_left_sidearea_right = true;
            }
        }

        if(isset($eltd_moose_options['vertical_area_background_image']) && $eltd_moose_options['vertical_area_background_image'] != "" && isset($eltd_moose_options['vertical_area_dropdown_showing']) && $eltd_moose_options['vertical_area_dropdown_showing'] != "side" && get_post_meta($id, "eltd_page_disable_vertical_area_background_image", true) != "yes") {
            $vertical_area_background_image = $eltd_moose_options['vertical_area_background_image'];
        }
        if(get_post_meta($id, "eltd_page_vertical_area_background_image", true) != "" && get_post_meta($id, "eltd_page_disable_vertical_area_background_image", true) != "yes" && isset($eltd_moose_options['vertical_area_dropdown_showing']) && $eltd_moose_options['vertical_area_dropdown_showing'] != "side"){
            $vertical_area_background_image = get_post_meta($id, "eltd_page_vertical_area_background_image", true);
        }

        $vertical_area_dropdown_showing = $eltd_moose_options['vertical_area_dropdown_showing'];

        switch($vertical_area_dropdown_showing){
            case 'hover':
                $vertical_menu_style = "toggle";
                break;
            case 'click':
                $vertical_menu_style = "toggle click";
                break;
            case 'side':
                $vertical_menu_style = "side";
                break;
            case 'to_content':
                $vertical_menu_style = "to_content";
                break;
            default:
                $vertical_menu_style = "toggle";

        }
        $vertical_area_scroll = " with_scroll";
        if ($vertical_area_dropdown_showing == 'to_content') {
            $vertical_area_scroll = "";
        }

        if(isset($eltd_moose_options['paspartu']) && $eltd_moose_options['paspartu'] == 'yes' && isset($eltd_moose_options['vertical_menu_inside_paspartu']) && $eltd_moose_options['vertical_menu_inside_paspartu'] == 'yes'){
            if($eltd_moose_options['vertical_area_background_transparency'] != "") {
                $page_vertical_area_background_transparency = esc_attr($eltd_moose_options['vertical_area_background_transparency']);
            }
            if(get_post_meta($id, "eltd_page_vertical_area_background_opacity", true) != ""){
                $page_vertical_area_background_transparency = esc_attr(get_post_meta($id, "eltd_page_vertical_area_background_opacity", true));
            }

            if(isset($eltd_moose_options['vertical_area_dropdown_showing']) && $eltd_moose_options['vertical_area_dropdown_showing'] == "side"){
                $page_vertical_area_background_transparency = 1;
            }
        }
        else if(isset($eltd_moose_options['paspartu']) && $eltd_moose_options['paspartu'] == 'no') {
            if($eltd_moose_options['vertical_area_background_transparency'] != "") {
                $page_vertical_area_background_transparency = esc_attr($eltd_moose_options['vertical_area_background_transparency']);
            }
            if(get_post_meta($id, "eltd_page_vertical_area_background_opacity", true) != ""){
                $page_vertical_area_background_transparency = esc_attr(get_post_meta($id, "eltd_page_vertical_area_background_opacity", true));
            }

            if(isset($eltd_moose_options['vertical_area_dropdown_showing']) && $eltd_moose_options['vertical_area_dropdown_showing'] == "side"){
                $page_vertical_area_background_transparency = 1;
            }
        }

        if(get_post_meta($id, "eltd_page_vertical_area_background", true) != ""){
            $page_vertical_area_background =esc_attr(get_post_meta($id, 'eltd_page_vertical_area_background', true));

        }else if(get_post_meta($id, "eltd_page_vertical_area_background", true) == ""){
            $page_vertical_area_background = $eltd_moose_options['vertical_area_background'];
        }

        $bkg_image="";
        $page_vertical_area_background_style = "";
        $page_vertical_area_background_transparency_style = "";
        if($vertical_area_background_image != ""){ $bkg_image = 'background-image:url('.esc_url($vertical_area_background_image).');'; }
        if($page_vertical_area_background != ""){ $page_vertical_area_background_style = 'background-color:'.esc_attr($page_vertical_area_background).';'; }
        if($page_vertical_area_background_transparency != ""){ $page_vertical_area_background_transparency_style = 'opacity:'.esc_attr($page_vertical_area_background_transparency).';'; }

        $vertical_area_menu_items_arrow = '';
        if (isset($eltd_moose_options['vertical_area_menu_items_arrow']) && $eltd_moose_options['vertical_area_menu_items_arrow'] =='yes' ){
            $vertical_area_menu_items_arrow = 'with_arrow';
        }

		$header_search_type = 'search_slides_from_top';
		if(isset($eltd_moose_options['search_type']) && $eltd_moose_options['search_type'] !== '') {
			$header_search_type = $eltd_moose_options['search_type'];
		}
		if(isset($eltd_moose_options['search_type']) && $eltd_moose_options['search_type'] == 'search_covers_header') {
			if (isset($eltd_moose_options['search_cover_only_bottom_yesno']) && $eltd_moose_options['search_cover_only_bottom_yesno']=='yes') {
				$header_search_type .= ' search_covers_only_bottom';
			}
		}
		if (isset($eltd_moose_options['search_icon_background_full_height']) && $eltd_moose_options['search_icon_background_full_height'] == 'yes'){
			$header_search_type .= ' search_icon_bckg_full';
		}

        if($eltd_moose_options['frame_around_content'] == 'yes'){
            $frame_around_content_class = 'frame_around_content';
        }

        if((get_post_meta(eltd_moose_get_page_id(), "eltd_revolution-slider", true) == "" && ($header_transparency == '' || $header_transparency == 1))  || get_post_meta($id, "eltd_enable_content_top_margin", true) == "yes" ){
            if($eltd_moose_options['header_bottom_appearance'] == "fixed" || $eltd_moose_options['header_bottom_appearance'] == "fixed_hiding" || $eltd_moose_options['header_bottom_appearance'] == "fixed fixed_minimal"){
                $content_class = "content_top_margin";
            }else {
                $content_class = "content_top_margin_none";
            }
        }

        if(isset($eltd_moose_options['header_bottom_appearance']) && ($eltd_moose_options['header_bottom_appearance'] == "stick" || $eltd_moose_options['header_bottom_appearance'] == "stick menu_bottom" || $eltd_moose_options['header_bottom_appearance'] == "stick_with_left_right_menu" || $eltd_moose_options['header_bottom_appearance'] == "stick compound")){
            if(get_post_meta(eltd_moose_get_page_id(), "eltd_page_hide_initial_sticky", true) !== ''){
                if(get_post_meta(eltd_moose_get_page_id(), "eltd_page_hide_initial_sticky", true) == 'yes'){
                    $content_class = " ";
                }
            }else if(isset($eltd_moose_options['hide_initial_sticky']) && $eltd_moose_options['hide_initial_sticky'] == 'yes') {
                $content_class = " ";
            }
        }


        if(eltd_moose_get_page_template_name() == "full_screen"){
            // solution for top header
            if(!eltd_moose_is_side_header()){
                if (($header_transparency == '' || $header_transparency == 1) || ($eltd_moose_options['header_bottom_appearance'] == "regular" || $eltd_moose_options['header_bottom_appearance'] == "fixed_top_header")) {
                    if ($eltd_moose_options['header_bottom_appearance'] == "fixed" || $eltd_moose_options['header_bottom_appearance'] == "fixed_hiding" || $eltd_moose_options['header_bottom_appearance'] == "fixed fixed_minimal") {
                        $content_class = "content_top_margin_none";
                    }
                    elseif($eltd_moose_options['header_bottom_appearance'] == 'stick menu_bottom'){
                        $content_class = ""; // delete class if exists
                    }
                    else {
                        $content_class = "content_top_margin_negative content_top_margin_none";
                    }
                }
            }

            // solution for paspartu on side and top header
            if((isset($eltd_moose_options['paspartu']) && $eltd_moose_options['paspartu'] == 'yes') && (isset($eltd_moose_options['paspartu_on_top']) && $eltd_moose_options['paspartu_on_top'] == 'yes')){
                if(isset($eltd_moose_options['paspartu_on_top_fixed']) && $eltd_moose_options['paspartu_on_top_fixed'] == 'yes'){
                    if(!(eltd_moose_is_side_header() && (isset($eltd_moose_options['vertical_menu_inside_paspartu']) && $eltd_moose_options['vertical_menu_inside_paspartu'] == 'yes'))){ // not for this case
                        $content_class .= " content_top_margin_vm_paspartu";
                    }
                }
                else{
                    // not resolved
                }
            }
        }

//check if there is slider added and set class to content div, this is used for content top margin in style_dynamic.php
        if(get_post_meta(eltd_moose_get_page_id(), "eltd_revolution-slider", true) != ""){
            $content_class .= " has_slider";
        }

        if(isset($eltd_moose_options['paspartu_on_top']) && $eltd_moose_options['paspartu_on_top'] == 'no'){
            $paspartu_additional_classes .= " disable_top_paspartu";
        }
        if(isset($eltd_moose_options['paspartu_on_bottom']) && $eltd_moose_options['paspartu_on_bottom'] == 'no'){
            $paspartu_additional_classes .= " disable_bottom_paspartu";
        }
        if(isset($eltd_moose_options['paspartu_on_bottom_slider']) && $eltd_moose_options['paspartu_on_bottom_slider'] == 'yes'){
            $paspartu_additional_classes .= " paspartu_on_bottom_slider";
        }
        if((isset($eltd_moose_options['paspartu_on_bottom']) && $eltd_moose_options['paspartu_on_bottom'] == 'yes' && isset($eltd_moose_options['paspartu_on_bottom_fixed']) && $eltd_moose_options['paspartu_on_bottom_fixed'] == 'yes') ||
           (eltd_moose_is_side_header() && isset($eltd_moose_options['vertical_menu_inside_paspartu']) && $eltd_moose_options['vertical_menu_inside_paspartu'] == 'yes')){
            $paspartu_additional_classes .= " paspartu_on_bottom_fixed";
        }

        if(isset($eltd_moose_options['back_to_top_position']) && !empty($eltd_moose_options['back_to_top_position'])) {
            $eltd_back_to_top_button_styles = $eltd_moose_options['back_to_top_position'];
        }

        return array(
            'id' => $id,
            'loading_animation' => $loading_animation,
            'loading_image' => $loading_image,
            'enable_side_area' => $enable_side_area,
            'enable_popup_menu' => $enable_popup_menu,
            'popup_menu_animation_style' => $popup_menu_animation_style,
            'enable_fullscreen_search' => $enable_fullscreen_search,
            'fullscreen_search_animation' => $fullscreen_search_animation,
            'fullscreen_search_in_header_top' => $fullscreen_search_in_header_top,
            'header_button_size' => $header_button_size,
            'header_in_grid' => $header_in_grid,
            'header_bottom_class' => $header_bottom_class,
            'menu_item_icon_position' => $menu_item_icon_position,
            'menu_position' => $menu_position,
            'centered_logo' => $centered_logo,
            'enable_border_top_bottom_menu' => $enable_border_top_bottom_menu,
            'menu_dropdown_appearance_class' => $menu_dropdown_appearance_class,
			'menu_hover_animation_class' => $menu_hover_animation_class,
            'logo_wrapper_style' => $logo_wrapper_style,
            'divided_left_menu_padding' => $divided_left_menu_padding,
            'divided_right_menu_padding' => $divided_right_menu_padding,
            'display_header_top' => $display_header_top,
            'header_top_area_scroll' => $header_top_area_scroll,
            'header_style' => $header_style,
            'header_color_transparency_per_page' => $header_color_transparency_per_page,
            'header_color_per_page' => $header_color_per_page,
            'header_top_color_per_page' => $header_top_color_per_page,
            'header_color_transparency_on_scroll' => $header_color_transparency_on_scroll,
            'header_bottom_border_style' => $header_bottom_border_style,
            'header_bottom_appearance' => $header_bottom_appearance,
            'header_transparency' => $header_transparency,
            'enable_vertical_menu' => $enable_vertical_menu,
            'enable_search_left_sidearea_right' => $enable_search_left_sidearea_right,
            'vertical_area_background_image' => $vertical_area_background_image,
            'vertical_menu_style' => $vertical_menu_style,
            'vertical_area_scroll' => $vertical_area_scroll,
            'page_vertical_area_background_transparency' => $page_vertical_area_background_transparency,
            'page_vertical_area_background' => $page_vertical_area_background,
            'bkg_image' => $bkg_image,
            'page_vertical_area_background_style' => $page_vertical_area_background_style,
            'page_vertical_area_background_transparency_style' => $page_vertical_area_background_transparency_style,
            'vertical_area_menu_items_arrow' => $vertical_area_menu_items_arrow,
            'header_search_type' => $header_search_type,
            'frame_around_content_class' => $frame_around_content_class,
            'content_class' => $content_class,
            'paspartu_additional_classes' => $paspartu_additional_classes,
            'eltd_back_to_top_button_styles' => $eltd_back_to_top_button_styles
        );
    }
}

if(!function_exists('eltd_moose_get_footer_variables')) {
    function eltd_moose_get_footer_variables() {
        global $eltd_moose_options;

        $id = eltd_moose_get_page_id();

        $footer_border_columns				= 'yes';
        $footer_top_border_color            = '';
        $footer_top_border_in_grid          = '';
        $footer_bottom_border_in_grid       = '';
        $footer_bottom_border_color         = '';
        $footer_bottom_border_bottom_color  = '';
        $footer_classes                     = '';
        $footer_classes_array               = array();
        $footer_in_grid                     = true;
        $display_footer_top                 = true;
        $footer_top_columns                 = 4;
        $footer_bottom_columns              = 3;

        if(isset($eltd_moose_options['footer_border_columns']) && $eltd_moose_options['footer_border_columns'] !== '') {
            $footer_border_columns = $eltd_moose_options['footer_border_columns'];
        }

        if(!empty($eltd_moose_options['footer_top_border_color'])) {
            if (isset($eltd_moose_options['footer_top_border_width']) && $eltd_moose_options['footer_top_border_width'] !== '') {
                $footer_border_height = $eltd_moose_options['footer_top_border_width'];
            } else {
                $footer_border_height = '1';
            }

            $footer_top_border_color = 'height: '.esc_attr($footer_border_height).'px;background-color: '.esc_attr($eltd_moose_options['footer_top_border_color']).';';
        }

        if(isset($eltd_moose_options['footer_top_border_in_grid']) && $eltd_moose_options['footer_top_border_in_grid'] == 'yes') {
            $footer_top_border_in_grid = 'in_grid';
        }

        if(isset($eltd_moose_options['footer_bottom_border_in_grid']) && $eltd_moose_options['footer_bottom_border_in_grid'] == 'yes') {
            $footer_bottom_border_in_grid = 'in_grid';
        }

        if(!empty($eltd_moose_options['footer_bottom_border_color'])) {
            if(!empty($eltd_moose_options['footer_bottom_border_width'])) {
                $footer_bottom_border_width = $eltd_moose_options['footer_bottom_border_width'].'px';
            }
            else{
                $footer_bottom_border_width = '1px';
            }

            $footer_bottom_border_color = 'height: '.esc_attr($footer_bottom_border_width).';background-color: '.esc_attr($eltd_moose_options['footer_bottom_border_color']).';';
        }


        if(!empty($eltd_moose_options['footer_bottom_border_bottom_color'])) {
            if(!empty($eltd_moose_options['footer_bottom_border_bottom_width'])) {
                $footer_bottom_border_bottom_width = $eltd_moose_options['footer_bottom_border_bottom_width'].'px';
            } else {
                $footer_bottom_border_bottom_width = '1px';
            }

            $footer_bottom_border_bottom_color = 'height: '.esc_attr($footer_bottom_border_bottom_width).';background-color: '.esc_attr($eltd_moose_options['footer_bottom_border_bottom_color']).';';
        }

        //is uncovering footer option set in theme options?
        if(isset($eltd_moose_options['uncovering_footer']) && $eltd_moose_options['uncovering_footer'] == "yes" && isset($eltd_moose_options['paspartu']) && $eltd_moose_options['paspartu'] == 'no') {
            //add uncovering footer class to array
            $footer_classes_array[] = 'uncover';
        }


        if(get_post_meta($id, "eltd_footer-disable", true) == "yes"){
            $footer_classes_array[] = 'disable_footer';
        }

        if($footer_border_columns == 'yes') {
            $footer_classes_array[] = 'footer_border_columns';
        }

        if(isset($eltd_moose_options['paspartu']) && $eltd_moose_options['paspartu'] == 'yes' && isset($eltd_moose_options['paspartu_footer_alignment']) && $eltd_moose_options['paspartu_footer_alignment'] == 'yes'){
            $footer_classes_array[]= 'paspartu_footer_alignment';
        }

        if($eltd_moose_options['overlapping_content'] == 'yes' && $eltd_moose_options['overlapping_bottom_content_amount'] !== "") {
            $footer_classes_array[]= 'footer_overlapped';
        }

        //is some class added to footer classes array?
        if(is_array($footer_classes_array) && count($footer_classes_array)) {
            //concat all classes and prefix it with class attribute
            $footer_classes = esc_attr(implode(' ', $footer_classes_array));
        }

        if(isset($eltd_moose_options['footer_in_grid'])){
            if ($eltd_moose_options['footer_in_grid'] != "yes") {
                $footer_in_grid = false;
            }
        }

        if (isset($eltd_moose_options['show_footer_top']) && $eltd_moose_options['show_footer_top'] == "no") {
            $display_footer_top = false;
        }

        if (isset($eltd_moose_options['footer_top_columns'])) {
            $footer_top_columns = $eltd_moose_options['footer_top_columns'];
        }

        if (isset($eltd_moose_options['footer_bottom_columns'])) {
            $footer_bottom_columns = $eltd_moose_options['footer_bottom_columns'];
        }

        return array(
            'footer_border_columns' => $footer_border_columns,
            'footer_top_border_color' => $footer_top_border_color,
            'footer_top_border_in_grid' => $footer_top_border_in_grid,
            'footer_bottom_border_in_grid' => $footer_bottom_border_in_grid,
            'footer_bottom_border_color' => $footer_bottom_border_color,
            'footer_bottom_border_bottom_color' => $footer_bottom_border_bottom_color,
            'footer_classes' => $footer_classes,
            'footer_in_grid' => $footer_in_grid,
            'display_footer_top' => $display_footer_top,
            'footer_top_columns' => $footer_top_columns,
            'footer_bottom_columns' => $footer_bottom_columns
        );
    }
}

if(!function_exists('eltd_moose_is_logo_centered')) {
    /**
     * Checks if logo is centered or not
     * @return bool
     */
    function eltd_moose_is_logo_centered() {
        global $eltd_moose_options;

        $centered_logo = false;

        if (isset($eltd_moose_options['center_logo_image'])) {
            if($eltd_moose_options['center_logo_image'] == "yes" && $eltd_moose_options['header_bottom_appearance'] !== "stick_with_left_right_menu") {
                $centered_logo = true;
            }
        }

        if(isset($eltd_moose_options['header_bottom_appearance']) && $eltd_moose_options['header_bottom_appearance'] == "fixed_hiding"){
            $centered_logo = true;
        }

        return $centered_logo;
    }
}

if(!function_exists('eltd_moose_get_header_style')) {
    /**
     * Returns current page header style. It first checks in current page meta field,
     * if that isn't set it checks in global options
     * @return mixed|string
     */
    function eltd_moose_get_header_style() {
        global $eltd_moose_options;

        $id = eltd_moose_get_page_id();
        $header_style = '';

        if(get_post_meta($id, "eltd_header-style", true) != "") {
            $header_style = get_post_meta($id, "eltd_header-style", true);
        } elseif(isset($eltd_moose_options['header_style'])) {
            $header_style = $eltd_moose_options['header_style'];
        }

        return $header_style;
    }
}

if(!function_exists('eltd_moose_get_header_transparency')) {
    /**
     * Returns current page's header transparency. First it checks in current page custom field,
     * if not set it checks in global options
     * @return mixed|string
     */
    function eltd_moose_get_header_transparency() {
        global $eltd_moose_options;

        $id = eltd_moose_get_page_id();
        $header_color_transparency_per_page = '';


        if(get_post_meta($id, "eltd_header_color_transparency_per_page", true) != ""){
            $header_color_transparency_per_page = get_post_meta($id, "eltd_header_color_transparency_per_page", true);
        } elseif($eltd_moose_options['header_background_transparency_initial'] != "") {
            $header_color_transparency_per_page = $eltd_moose_options['header_background_transparency_initial'];
        }

        return $header_color_transparency_per_page;
    }
}

if(!function_exists('eltd_moose_is_top_header')) {
    /**
     * Checks if header type is top
     * @return bool
     */
    function eltd_moose_is_top_header() {
        global $eltd_moose_options;

		$top_header = false;
		
        if($eltd_moose_options['header_type'] == "top") {
            $top_header = true;
        }

        return $top_header;
    }
}

if(!function_exists('eltd_moose_is_side_header')) {
    /**
     * Checks if header type is side
     * @return bool
     */
    function eltd_moose_is_side_header() {
        global $eltd_moose_options;

		$side_header = false;
		
        if($eltd_moose_options['header_type'] == "side") {
            $side_header = true;
        }

        return $side_header;
    }
}

if(!function_exists('eltd_moose_space_around_content')) {
    /**
     * Checks if there is spacing around content
     * @return bool
     */
    function eltd_moose_space_around_content() {
        global $eltd_moose_options;

        $space_around_content = false;

        if($eltd_moose_options['boxed'] == "yes" && $eltd_moose_options['spacing_arround_content'] == "yes") {
            $space_around_content = true;
        }

        return $space_around_content;
    }
}

if(!function_exists('eltd_moose_include_footer_in_content')) {
    /**
     * Checks if footer is included in spacing
     * @return bool
     */
    function eltd_moose_include_footer_in_content() {
        global $eltd_moose_options;

        $include_footer_in_content = false;

        if($eltd_moose_options['boxed'] == "yes" && $eltd_moose_options['spacing_arround_content'] == "yes" && $eltd_moose_options['footer_in_content'] == "yes") {
            $include_footer_in_content = true;
        }

        return $include_footer_in_content;
    }
}