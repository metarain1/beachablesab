<?php
global $eltdIconCollections;
$output = $title = $icon = $title_color = $title_hover_color = $mark_icon_color = $mark_icon_color_hover = $background_color = $background_hover_color = $border_color = $border_hover_color = $el_id = '';
$icon_pack = '';

$default_attrs = array(
	'title'						=> __("Accordion Title", "js_composer"),
	'title_color'				=> "",
	'title_hover_color'			=> "",
	'accordion_type'			=> "standard_accordion",
    'icon_custom_size'			=> "22",
	'icon_color'				=> "",
	'hover_icon_color'			=> "",
	'mark_icon_color'			=> "",
	'mark_icon_color_hover'		=> "",	
	'background_color'			=> "",
	'background_hover_color'	=> "",
	'border_color'			=> "",
	'border_hover_color'	=> "",
    'title_tag'					=> 'h6',
	'el_id' => ''
);

$default_attrs = array_merge($eltdIconCollections->getShortcodeParams(), $default_attrs);

extract(shortcode_atts($default_attrs, $atts));

$title = esc_html($title);
$title_color = esc_attr($title_color);
$title_tag = esc_attr($title_tag);
$mark_icon_color = esc_html($mark_icon_color);
$mark_icon_color_hover = esc_attr($mark_icon_color_hover);
$title_hover_color = esc_attr($title_hover_color);
$background_color = esc_attr($background_color);
$background_hover_color = esc_attr($background_hover_color);
$border_color = esc_attr($border_color);
$border_hover_color = esc_attr($border_hover_color);

$css_class = apply_filters(VC_SHORTCODE_CUSTOM_CSS_FILTER_TAG, 'wpb_accordion_section group', $this->settings['base']);
	$heading_styles = '';
	$data_attr = '';
	
	
	if($title_color != "") {
	   $data_attr .= " data-title-color='" . $title_color . "'";	
       $heading_styles .= "color: ".$title_color.";";
    }  
	
	if($title_hover_color != "") {
       $data_attr .= " data-title-hover-color='" . $title_hover_color . "'";
	}
	
	if($title_tag == ""){
    	$title_tag = "h4";
    }
	 	
	if($mark_icon_color != "") {		
	   $data_attr .= " data-mark-icon-color='" . $mark_icon_color . "'";
    }  
	
	if($mark_icon_color_hover != "") {
       $data_attr .= " data-mark-icon-hover-color='" . $mark_icon_color_hover . "'";
    }
	
	if($background_color != "") {
        $heading_styles .= " background-color: ".$background_color.";";
		$data_attr .= " data-background-color='" . $background_color . "'";
    }
	
	if($background_hover_color != "") {
       $data_attr .= " data-background-hover-color='" . $background_hover_color . "'";
    }
	
	if($border_color != "") {
        $heading_styles .= " border-color: ".$border_color.";";
		$data_attr .= " data-border-color='" . $border_color . "'";
    }
	
	if($border_hover_color != "") {
       $data_attr .= " data-border-hover-color='" . $border_hover_color . "'";
    }
	$accordion_class = '';
	if($accordion_type == "accordion_icon"){
		
		$accordion_class .= 'accordion_icon';
		$icons_param_array = array();
		if ($icon_pack !== '') {
			$icons_param_array[] = "icon_pack='" . $icon_pack . "'";
		}
		foreach ($eltdIconCollections->iconCollections as $icon_set) {
			if (${$icon_set->param}) {
				$icons_param_array[] = $icon_set->param . "='" . ${$icon_set->param} . "'";
			}
		}
		if($icon_custom_size != ''){
			$icons_param_array[] = "shape_size = '".$icon_custom_size."'";
			$icons_param_array[] = "custom_size = '".$icon_custom_size."'";
		}
		if($icon_color != ''){
			$icons_param_array[] = "icon_color = '".$icon_color."'";
		}
		if($hover_icon_color != ''){
			$icons_param_array[] = "hover_icon_color = '".$hover_icon_color."'";
		}
		$icons_param_array[] = "border_width = 0";
		
		
	}
	

    $output .= "\n\t\t\t\t" . '<'.$title_tag.' class="clearfix title-holder '.$accordion_class.'" style="'.$heading_styles.'" '. $data_attr .'>';
	if($accordion_type == "accordion_icon"){
		$output .= '<span class = "accordion_icon_holder">';	
		$output .= do_shortcode('[no_icons ' . implode(' ', $icons_param_array) . ']');
		$output .= '</span>'; //close accordion_icon_holder span
	}
	$output .= '<span class="tab-title"><span class="tab-title-inner">'.$title.'</span></span>';
	$output .= '<span class="accordion_mark right_mark">';
	$output .= '<span class="accordion_mark_icon">';
	$output .= '<span class="arrow_carrot-down"></span>';
	$output .= '<span class="arrow_carrot-up"></span>';
	$output .= '</span>'; //close accordion_mark_icon span
	$output .= '</span>'; //close accordion_mark span
	$output .= '</'.$title_tag.'>';
    $output .= "\n\t\t\t\t" . '<div ' . ( isset( $el_id ) && ! empty( $el_id ) ? "id='" . esc_attr( $el_id ) . "'" : "" ) . ' class="accordion_content">';
		$output .= "\n\t\t\t" . '<div class="accordion_content_inner">';
			$output .= ($content=='' || $content==' ') ? __("Empty section. Edit page to add content here.", "js_composer") : "\n\t\t\t\t" . wpb_js_remove_wpautop($content);
			$output .= "\n\t\t\t" . '</div>';
		 $output .= "\n\t\t\t\t" . '</div>' . $this->endBlockComment('.wpb_accordion_section') . "\n";

print $output;