<?php

global $eltdIconCollections;

$args = array(
	'title' => '',
	'icon_pack' => '',
	'front_side_content' => '',
	'back_side_content' => '',
	'link' => '',
	'link_text' => '',
 	'link_target' => ''
);

$args = array_merge($args, $eltdIconCollections->getShortcodeParams());

extract(shortcode_atts($args, $atts));

$title = esc_attr($title);
$front_side_content = esc_attr($front_side_content);
$back_side_content = esc_attr($back_side_content);
$link = esc_url($link);
$link_text = esc_attr($link_text);

$html = '<div class="eltd-info-card-slider-item">';

//Front side of card
$html .= '<div class="front-side">';

$icon_collection_obj = $eltdIconCollections->getIconCollection($icon_pack);

if (method_exists($icon_collection_obj, 'render')) {

	$html .= $icon_collection_obj->render(${$icon_collection_obj->param}, array(
		'icon_attributes' => array(
			'class' => 'eltd-info-card-icon'
		)
	));

}

$html .= '<h5>' . $title . '</h5>';
$html .= '<p>' . $front_side_content . '</p>';
$html .= '</div>';
//Front side of card end

//Back side of card
$html .= '<div class="back-side">';
$html .= '<div class="back-side-inner">';
$html .= '<p>' . $back_side_content . '</p>';

if ( $link !== '' ) {

	//Default button styles
	$button_style_array = array();
	$button_style_array[] = 'style="white"';
	$button_style_array[] = 'background_color="transparent"';
	$button_style_array[] = 'button_hover_animation="default"';
	$button_style_array[] = 'icon_pack="font_elegant"';
	$button_style_array[] = 'fe_icon="arrow_carrot-2right"';
	$button_style_array[] = 'icon_font_size="19"';
	$button_style_array[] = 'icon_color="#ffffff"';
	$button_style_array[] = 'color="#ffffff"';
	$button_style_array[] = 'border_color="#ffffff"';
	$button_style_array[] = 'margin="35px 0 0 0"';

	$button_style_array[] = 'link="' . $link . '"';
	if ( $link_text !== '' ) {
		$button_style_array[] = 'text="' . $link_text . '"';
	}

	$button_style_array[] = 'target="' . $link_target . '"';

	$button_style = implode(' ', $button_style_array);

	$html .= do_shortcode('[no_button ' . $button_style . ']');
}

$html .= '</div></div>';
//Back side of card end

$html .= '</div>';

print $html;