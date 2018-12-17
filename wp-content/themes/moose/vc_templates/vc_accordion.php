<?php
$output = $title = $interval = $el_class = $collapsible = $active_tab = $style = '';
//
   
extract(shortcode_atts(array(
    'title' => '',
    'interval' => 0,
    'el_class' => '',
    'collapsible' => 'no',
    'active_tab' => '',
    'accordion_border_radius' => '',
	'accordion_section_border_radius' => '',
	'accordion_section_height'	=> '',
	'style' => 'accordion',
    'background_transparency' => "no"
), $atts));

$accordion_border_radius = esc_attr($accordion_border_radius);
$accordion_section_border_radius = esc_attr($accordion_section_border_radius);
$accordion_section_height = esc_attr($accordion_section_height);


$el_class = esc_attr($el_class);
$active_tab = esc_attr($active_tab);

$data_attr = "";
$data_attr .= " data-active-tab='" . $active_tab . "'";
$data_attr .= " data-collapsible='" . $collapsible . "'";

if($accordion_border_radius != "" && ($style=="boxed_accordion" || $style=="boxed_toggle")) {
    $data_attr .= " data-border-radius='" . $accordion_border_radius . "'";
}

if($accordion_section_border_radius != "") {
    $data_attr .= " data-section-border-radius='" . $accordion_section_border_radius . "'";
}

if($accordion_section_height != "") {
    $data_attr .= " data-section-height='" . $accordion_section_height . "'";
}


//define accordion type classes
$acc_class = "";
switch($style) {
    case "toggle":
        $acc_class .= "toggle";
        break;
    case "boxed_accordion":
        $acc_class .= "accordion boxed";
        break;
    case "boxed_toggle":
        $acc_class .= "toggle boxed";
        break;
    default:
        $acc_class = "accordion";
}

$acc_class .= " accordion_show_icon";

if($background_transparency == "yes"){
    $acc_class .= " transparent";
}


$el_class = $this->getExtraClass($el_class);
$css_class = apply_filters(VC_SHORTCODE_CUSTOM_CSS_FILTER_TAG, 'eltd_accordion_holder clearfix wpb_content_element '. $acc_class ." " . $el_class.' not-column-inherit', $this->settings['base']);


$output .= "\n\t".'<div class="'.$css_class.'" '. $data_attr .'>';
$output .= "\n\t\t\t".wpb_js_remove_wpautop($content);
$output .= "\n\t".'</div> '.$this->endBlockComment('.wpb_accordion');

print $output;