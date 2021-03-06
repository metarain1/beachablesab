<?php

if(!function_exists('eltd_moose_title_classes')) {
	/**
	 * Function that adds classes to title div.
	 * All other functions are tied to it with add_filter function
	 * @param array $classes array of classes
	 */
	function eltd_moose_title_classes($classes = array()) {
		$classes = array();
		$classes = apply_filters('eltd_moose_title_classes', $classes);

		if(is_array($classes) && count($classes)) {
			echo implode(' ', $classes);
		}
	}
}

if(!function_exists('eltd_moose_title_fontsize')) {
	/**
	 * Function that adds class on title based on title position option
	 * Could be left, centered or right
	 * @param $classes original array of classes
	 * @return array changed array of classes
	 */
	function eltd_moose_title_fontsize($classes) {
		global $eltd_moose_options;
		global $wp_query;

		$id = $wp_query->get_queried_object_id();
		$page_title_fontsize_class = '';

		if(get_post_meta($id, "eltd_page_title_font_size", true) != ""){
		    $page_title_fontsize_class = "title_size_" . get_post_meta($id, "eltd_page_title_font_size", true);
		}else{
		    if(isset($eltd_moose_options['predefined_title_sizes'])) {
		        $page_title_fontsize_class = "title_size_" . $eltd_moose_options['predefined_title_sizes'];
		    }
		}

		$classes[] = $page_title_fontsize_class;

		return $classes;
	}

	add_filter('eltd_moose_title_classes', 'eltd_moose_title_fontsize');
}

if(!function_exists('eltd_moose_title_position_class')) {
	/**
	 * Function that adds class on title based on title position option
	 * Could be left, centered or right
	 * @param $classes original array of classes
	 * @return array changed array of classes
	 */
	function eltd_moose_title_position_class($classes) {
		global $eltd_moose_options;
		global $wp_query;

		//init variables
		$id 			= $wp_query->get_queried_object_id();
		$title_position = 'left';

		if(eltd_moose_is_woocommerce_page()) {
			$id = get_option('woocommerce_shop_page_id');
		}

		if(get_post_meta($id, "eltd_page_title_position", true) != "") {
			$title_position = get_post_meta($id, "eltd_page_title_position", true);

		} else {
			$title_position = $eltd_moose_options['page_title_position'];
		}

		$classes[] = 'position_'.$title_position;

		return $classes;
	}

	add_filter('eltd_moose_title_classes', 'eltd_moose_title_position_class');
}

if(!function_exists('eltd_moose_title_in_grid_class')) {
    /**
     * Function that adds class on title based on title in grid option
     * Could be enabled or disabled
     * @param $classes original array of classes
     * @return array changed array of classes
     */
    function eltd_moose_title_in_grid_class($classes) {
        global $eltd_moose_options;
        global $wp_query;

        //init variables
        $id 			= $wp_query->get_queried_object_id();
        $title_in_grid = '';

        if(eltd_moose_is_woocommerce_page()) {
            $id = get_option('woocommerce_shop_page_id');
        }

        if((get_post_meta($id, "eltd_title_content_in_grid", true) == "no")
            || ((get_post_meta($id, "eltd_title_content_in_grid", true) != "yes") && isset($eltd_moose_options['title_content_in_grid']) && $eltd_moose_options['title_content_in_grid'] == 'no')) {
            $classes[] = 'disable_title_in_grid';
        }

        return $classes;
    }

    add_filter('eltd_moose_title_classes', 'eltd_moose_title_in_grid_class');
}

if(!function_exists('eltd_moose_title_content_shadow')) {
    /**
     * Function that adds class on title based on title content area shadows
     * Could be enabled or disabled
     * @param $classes original array of classes
     * @return array changed array of classes
     */
    function eltd_moose_title_content_shadow($classes) {
        global $eltd_moose_options;
        global $wp_query;

        //init variables
        $id 			= $wp_query->get_queried_object_id();

        if(eltd_moose_is_woocommerce_page()) {
            $id = get_option('woocommerce_shop_page_id');
        }

        if((get_post_meta($id, "eltd_moose_title_content_shadow", true) == "yes")
            || ((get_post_meta($id, "eltd_moose_title_content_shadow", true) != "no") && isset($eltd_moose_options['title_content_shadows']) && $eltd_moose_options['title_content_shadows'] == 'yes')) {
            $classes[] = 'title_content_shadow';
        }

        return $classes;
    }

    add_filter('eltd_moose_title_classes', 'eltd_moose_title_content_shadow');
}

if(!function_exists('eltd_moose_title_with_paspartu')) {
    /**
     * Function that adds class on title based on title paspartu
     * Could be enabled or disabled (by default disabled)
     * @param $classes original array of classes
     * @return array changed array of classes
     */
    function eltd_moose_title_with_paspartu($classes) {
        global $eltd_moose_options;

        if((isset($eltd_moose_options['paspartu_below_tittle']) && $eltd_moose_options['paspartu_below_tittle'] == 'yes')) {
            $classes[] = 'paspartu_below_tittle';
        }

        return $classes;
    }

    add_filter('eltd_moose_title_classes', 'eltd_moose_title_with_paspartu');
}

if(!function_exists('eltd_moose_title_background_image_classes')) {
	function eltd_moose_title_background_image_classes($classes) {
		global $eltd_moose_options;
		global $wp_query;

		//init variables
		$id 					= $wp_query->get_queried_object_id();
		$is_img_responsive 		= '';
		$is_image_fixed			= '';
		$is_image_fixed_array 	= array('yes', 'yes_zoom');
		$show_title_img			= true;
		$title_img				= '';

		if(eltd_moose_is_woocommerce_page()) {
			$id = get_option('woocommerce_shop_page_id');
		}

		//is responsive image is set for current page?
		if(get_post_meta($id, "eltd_responsive-title-image", true) != "") {
			$is_img_responsive = get_post_meta($id, "eltd_responsive-title-image", true);
		} else {
			//take value from theme options
			$is_img_responsive = $eltd_moose_options['responsive_title_image'];
		}

		//is title image chosen for current page?
		if(get_post_meta($id, "eltd_title-image", true) != ""){
			$title_img = get_post_meta($id, "eltd_title-image", true);
		}else{
			//take image that is set in theme options
			$title_img = $eltd_moose_options['title_image'];
		}

		//is image set to be fixed for current page?
		if(get_post_meta($id, "eltd_fixed-title-image", true) != ""){
			$is_image_fixed = get_post_meta($id, "eltd_fixed-title-image", true);
		}else{
			//take setting from theme options
			$is_image_fixed = $eltd_moose_options['fixed_title_image'];
		}

		//is title image hidden for current page?
		if(get_post_meta($id, "eltd_show-page-title-image", true) == "yes") {
			$show_title_img = false;
		}

		//is title image set and visible?
		if($title_img !== '' && $show_title_img == true) {
			//is image not responsive and parallax title is set?
            $classes[] = 'preload_background';

            if($is_img_responsive == 'no' && in_array($is_image_fixed, $is_image_fixed_array)) {
				$classes[] = 'has_fixed_background';

				if($is_image_fixed == 'yes_zoom') {
					$classes[] = 'zoom_out';
				}
			}
			//is image not responsive and parallax title isn't set?
			elseif($is_img_responsive == 'no') {
				$classes[] = 'has_background';
			}
		}

		return $classes;
	}

	add_filter('eltd_moose_title_classes', 'eltd_moose_title_background_image_classes');
}

if(!function_exists('eltd_moose_title_text_is_hidden_class')) {
	function eltd_moose_title_text_is_hidden_class($classes) {
		global $eltd_moose_options;
		global $wp_query;
		$is_title_text_visible = true;

		//init variables
		$id = $wp_query->get_queried_object_id();

		if(eltd_moose_is_woocommerce_page()) {
			$id = get_option('woocommerce_shop_page_id');
		}
		
		
		if(get_post_meta($id, "eltd_show_page_title_text", true) == 'yes') {
			$is_title_text_visible = true;
		} elseif(get_post_meta($id, "eltd_show_page_title_text", true) == 'no') {
			$is_title_text_visible = false;
		} elseif(get_post_meta($id, "eltd_show_page_title_text", true) == '' && (isset($eltd_moose_options['show_page_title_text']) && $eltd_moose_options['show_page_title_text'] == 'yes')) {
			$is_title_text_visible = true;
		} elseif(get_post_meta($id, "eltd_show_page_title_text", true) == '' && (isset($eltd_moose_options['show_page_title_text']) && $eltd_moose_options['show_page_title_text'] == 'no')) {
			$is_title_text_visible = false;
		} elseif(isset($eltd_moose_options['show_page_title_text']) && $eltd_moose_options['show_page_title_text'] == 'yes') {
			$is_title_text_visible = true;
		}

		if(!$is_title_text_visible) {
			$classes[] = 'without_title_text';
		}

		return $classes;
	}

	add_filter('eltd_moose_title_classes', 'eltd_moose_title_text_is_hidden_class');
}

if(!function_exists('eltd_moose_title_breadcrumb_type_class')) {
    function eltd_moose_title_breadcrumb_type_class($classes) {
        global $eltd_moose_options;
        global $wp_query;

        //init variables
        $id 			= $wp_query->get_queried_object_id();

		if(eltd_moose_is_woocommerce_page()) {
			$id = get_option('woocommerce_shop_page_id');
		}

        $title_type = "standard_title";
        if(get_post_meta($id, "eltd_page_title_type", true) != ""){
            $title_type = get_post_meta($id, "eltd_page_title_type", true);
        }else if(is_404()){
            $title_type = "breadcrumbs_title";
        }else{
            $title_type = $eltd_moose_options['title_type'];
        }

        $classes[] = $title_type;

        return $classes;
    }

    add_filter('eltd_moose_title_classes', 'eltd_moose_title_breadcrumb_type_class');
}

if(!function_exists('eltd_moose_title_background_color_class')) {
	function eltd_moose_title_background_color_class($classes) {
		global $eltd_moose_options;
		global $wp_query;

		//init variables
		$id 			= $wp_query->get_queried_object_id();
		$title_image	= '';
		$title_bg_color = '';

		if(eltd_moose_is_woocommerce_page()) {
			$id = get_option('woocommerce_shop_page_id');
		}

		//is title image chosen for current page?
		if(get_post_meta($id, "eltd_title-image", true) != ""){
			$title_img = get_post_meta($id, "eltd_title-image", true);
		}else{
			//take image that is set in theme options
			$title_img = $eltd_moose_options['title_image'];
		}

		//is title background color set?
		if(get_post_meta($id, "eltd_page-title-background-color", true) != ""){
			$title_bg_color = get_post_meta($id, "eltd_page-title-background-color", true);
		}else{
			//take background color from
			$title_bg_color = $eltd_moose_options['title_background_color'];
		}

		if($title_bg_color !== '' && $title_img === '') {
			$classes[] = 'with_background_color';
		}

		return $classes;
	}

	add_filter('eltd_moose_title_classes', 'eltd_moose_title_background_color_class');
}