<?php

$args = array();

//Start slider
$html = '<div class="eltd-info-card-slider">';

//Slider inner holder
$html .= '<div class="eltd-info-card-slider-holder">';
$html .= do_shortcode( $content );
$html .= '</div>';
//Slider inner holder end

//Slider pagination
$html .= '<div class="eltd-info-card-slider-pagination"></div>';
//Slider pagination end

$html .= '</div>';
//Slider end

print $html;