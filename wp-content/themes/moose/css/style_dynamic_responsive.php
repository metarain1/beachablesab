<?php
$absolute_path = explode('wp-content', $_SERVER['SCRIPT_FILENAME']);

if(count($absolute_path) == 1) {
    $absolute_path = explode('wp-admin', $_SERVER['SCRIPT_FILENAME']);
}

$wp_load = $absolute_path[0] . 'wp-load.php';
require_once($wp_load);
 
header("Content-type: text/css; charset=utf-8");
?>

@media only screen and (max-width: 1000px){
	
	<?php if (!empty($eltd_moose_options['header_background_color'])) { ?>
	.header_bottom {
		background-color: <?php echo esc_attr($eltd_moose_options['header_background_color']);  ?>;
	}
	<?php } ?>
	<?php if (!empty($eltd_moose_options['mobile_background_color'])) { ?>
		.header_bottom,
		nav.mobile_menu{
				background-color: <?php echo esc_attr($eltd_moose_options['mobile_background_color']);  ?> !important;
		}
	<?php } ?>
	
	 <?php if (isset($eltd_moose_options['page_subtitle_fontsize']) && ($eltd_moose_options['page_subtitle_fontsize']) < 28 && ($eltd_moose_options['page_subtitle_fontsize']) !== '') { ?>
		.subtitle{
			font-size: <?php echo esc_attr($eltd_moose_options['page_subtitle_fontsize']) *0.8;  ?>px;
		}
	 <?php }?>
		
	<?php if(isset($eltd_moose_options['h1_fontsize']) && ($eltd_moose_options['h1_fontsize'])>80) { ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($eltd_moose_options['h1_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['page_title_fontsize']) && ($eltd_moose_options['page_title_fontsize'])>80) { ?>
		.title.title_size_small h1,
		.title.title_size_small h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($eltd_moose_options['page_title_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['page_title_medium_fontsize']) && ($eltd_moose_options['page_title_medium_fontsize'])>80) { ?>
		.title.title_size_medium h1,
		.title.title_size_medium h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($eltd_moose_options['page_title_medium_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['page_title_large_fontsize']) && ($eltd_moose_options['page_title_large_fontsize'])>80) { ?>
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($eltd_moose_options['page_title_large_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h2_fontsize']) && ($eltd_moose_options['h2_fontsize'])>70) { ?>
		.content h2{
			font-size:<?php echo esc_attr($eltd_moose_options['h2_fontsize'])*0.8; ?>px!important;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h2_lineheight']) && ($eltd_moose_options['h2_lineheight'])>70) { ?>
		.content h2{
			line-height: 1.3em!important;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h3_fontsize']) && ($eltd_moose_options['h3_fontsize'])>70) { ?>
		.content h3{
			font-size:<?php echo esc_attr($eltd_moose_options['h3_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h4_fontsize']) && ($eltd_moose_options['h4_fontsize'])>70) { ?>
		.content h4:not(.blockquote_text){
			font-size:<?php echo esc_attr($eltd_moose_options['h4_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h5_fontsize']) && ($eltd_moose_options['h5_fontsize'])>70) { ?>
		.content h5{
			font-size:<?php echo esc_attr($eltd_moose_options['h5_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h6_fontsize']) && ($eltd_moose_options['h6_fontsize'])>70) { ?>
		.content h6{
			font-size:<?php echo esc_attr($eltd_moose_options['h6_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
}

@media only screen and (min-width: 600px) and (max-width: 768px){
	<?php if(isset($eltd_moose_options['h1_fontsize']) && $eltd_moose_options['h1_fontsize'] != '') {
		$title_font_size = $eltd_moose_options['h1_fontsize'];
		if (($eltd_moose_options['h1_fontsize'])>80) {
			$title_font_size *= 0.5;
		}
		elseif (($eltd_moose_options['h1_fontsize'])>65) {
		 	$title_font_size *= 0.6;
		}
		elseif (($eltd_moose_options['h1_fontsize'])>50) {
		 	$title_font_size *= 0.7;
		}
		elseif (($eltd_moose_options['h1_fontsize'])>35) {
		 	$title_font_size *= 0.8;
		} ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['page_title_fontsize']) && ($eltd_moose_options['page_title_fontsize']) !== "") {
		$page_title_font_size = $eltd_moose_options['page_title_fontsize'];
		if (($eltd_moose_options['page_title_fontsize'])>80) {
			$page_title_font_size *= 0.5;
		}
		elseif (($eltd_moose_options['page_title_fontsize'])>65) {
		 	$page_title_font_size *= 0.6;
		}
		elseif (($eltd_moose_options['page_title_fontsize'])>50) {
		 	$page_title_font_size *= 0.7;
		}
		elseif (($eltd_moose_options['page_title_fontsize'])>35) {
		 	$page_title_font_size *= 0.8;
		} ?>
		.title.title_size_small h1,
		.title.title_size_small h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($page_title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['page_title_medium_fontsize']) && ($eltd_moose_options['page_title_medium_fontsize']) !== "") {
		$page_title_font_size = $eltd_moose_options['page_title_medium_fontsize'];
		if (($eltd_moose_options['page_title_medium_fontsize'])>80) {
			$page_title_font_size *= 0.5;
		}
		elseif (($eltd_moose_options['page_title_medium_fontsize'])>65) {
		 	$page_title_font_size *= 0.6;
		}
		elseif (($eltd_moose_options['page_title_medium_fontsize'])>50) {
		 	$page_title_font_size *= 0.7;
		}
		elseif (($eltd_moose_options['page_title_medium_fontsize'])>35) {
		 	$page_title_font_size *= 0.8;
		} ?>
		.title.title_size_medium h1,
		.title.title_size_medium h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($page_title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['page_title_large_fontsize']) && ($eltd_moose_options['page_title_large_fontsize']) !== "") {
		$page_title_font_size = $eltd_moose_options['page_title_large_fontsize'];
		if (($eltd_moose_options['page_title_large_fontsize'])>80) {
			$page_title_font_size *= 0.5;
		}
		elseif (($eltd_moose_options['page_title_large_fontsize'])>65) {
		 	$page_title_font_size *= 0.6;
		}
		elseif (($eltd_moose_options['page_title_large_fontsize'])>50) {
		 	$page_title_font_size *= 0.7;
		}
		elseif (($eltd_moose_options['page_title_large_fontsize'])>35) {
		 	$page_title_font_size *= 0.8;
		} ?>
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($page_title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h2_fontsize']) && ($eltd_moose_options['h2_fontsize'])>35) { ?>
		.content h2{
			font-size:<?php echo esc_attr($eltd_moose_options['h2_fontsize'])*0.7; ?>px!important;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h2_lineheight']) && ($eltd_moose_options['h2_lineheight'])>45) { ?>
		.content h2{
			line-height: 1.3em!important;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h3_fontsize']) && ($eltd_moose_options['h3_fontsize'])>35) { ?>
		.content h3{
			font-size:<?php echo esc_attr($eltd_moose_options['h3_fontsize'])*0.7; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h4_fontsize']) && ($eltd_moose_options['h4_fontsize'])>35) { ?>
		.content h4{
			font-size:<?php echo esc_attr($eltd_moose_options['h4_fontsize'])*0.7; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h5_fontsize']) && ($eltd_moose_options['h5_fontsize'])>35) { ?>
		.content h5{
			font-size:<?php echo esc_attr($eltd_moose_options['h5_fontsize'])*0.7; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h6_fontsize']) && ($eltd_moose_options['h6_fontsize'])>35) { ?>
		.content h6{
			font-size:<?php echo esc_attr($eltd_moose_options['h6_fontsize'])*0.7; ?>px;
		}
	<?php } ?>
	
	<?php if (isset($eltd_moose_options['page_subtitle_fontsize']) && ($eltd_moose_options['page_subtitle_fontsize']) < 28 && ($eltd_moose_options['page_subtitle_fontsize']) !== '') { ?>
		.subtitle{
			font-size: <?php echo esc_attr($eltd_moose_options['page_subtitle_fontsize']) *0.8;  ?>px;
		}
	 <?php } ?>
}

@media only screen and (min-width: 480px) and (max-width: 768px){
	<?php if (isset($eltd_moose_options['parallax_minheight']) && !empty($eltd_moose_options['parallax_minheight'])) { ?>
        section.parallax_section_holder{
		height: auto !important;
		min-height: <?php echo esc_attr($eltd_moose_options['parallax_minheight']); ?>px !important;
	}
	<?php } ?>
	
	<?php if (isset($eltd_moose_options['header_background_color_mobile']) &&  !empty($eltd_moose_options['header_background_color_mobile'])) { ?>
	header
	{
		 background-color: <?php echo esc_attr($eltd_moose_options['header_background_color_mobile']);  ?> !important;
		 background-image:none;
	}
	<?php } ?>
}

@media only screen and (max-width: 600px){
	<?php if(isset($eltd_moose_options['h1_fontsize']) && $eltd_moose_options['h1_fontsize'] !== '') {
		$title_font_size = $eltd_moose_options['h1_fontsize'];
		if (($eltd_moose_options['h1_fontsize'])>80) {
			$title_font_size *= 0.4;
		}
		elseif (($eltd_moose_options['h1_fontsize'])>65) {
		 	$title_font_size *= 0.5;
		}
		elseif (($eltd_moose_options['h1_fontsize'])>50) {
		 	$title_font_size *= 0.6;
		}
		elseif (($eltd_moose_options['h1_fontsize'])>35) {
		 	$title_font_size *= 0.7;
		} ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['page_title_fontsize']) && ($eltd_moose_options['page_title_fontsize']) !== '') {
		$page_title_font_size = $eltd_moose_options['page_title_fontsize'];
		if (($eltd_moose_options['page_title_fontsize'])>80) {
			$page_title_font_size *= 0.4;
		}
		elseif (($eltd_moose_options['page_title_fontsize'])>65) {
		 	$page_title_font_size *= 0.5;
		}
		elseif (($eltd_moose_options['page_title_fontsize'])>50) {
		 	$page_title_font_size *= 0.6;
		}
		elseif (($eltd_moose_options['page_title_fontsize'])>35) {
		 	$page_title_font_size *= 0.7;
		} ?>
		.title.title_size_small h1,
		.title.title_size_small h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($page_title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['page_title_medium_fontsize']) && ($eltd_moose_options['page_title_medium_fontsize']) !== "") {
		$page_title_font_size = $eltd_moose_options['page_title_medium_fontsize'];
		if (($eltd_moose_options['page_title_medium_fontsize'])>80) {
			$page_title_font_size *= 0.4;
		}
		elseif (($eltd_moose_options['page_title_medium_fontsize'])>65) {
		 	$page_title_font_size *= 0.5;
		}
		elseif (($eltd_moose_options['page_title_medium_fontsize'])>50) {
		 	$page_title_font_size *= 0.6;
		}
		elseif (($eltd_moose_options['page_title_medium_fontsize'])>35) {
		 	$page_title_font_size *= 0.7;
		} ?>
		.title.title_size_medium h1,
		.title.title_size_medium h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($page_title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['page_title_large_fontsize']) && ($eltd_moose_options['page_title_large_fontsize']) !== "") {
		$page_title_font_size = $eltd_moose_options['page_title_large_fontsize'];
		if (($eltd_moose_options['page_title_large_fontsize'])>80) {
			$page_title_font_size *= 0.4;
		}
		elseif (($eltd_moose_options['page_title_large_fontsize'])>65) {
		 	$page_title_font_size *= 0.5;
		}
		elseif (($eltd_moose_options['page_title_large_fontsize'])>50) {
		 	$page_title_font_size *= 0.6;
		}
		elseif (($eltd_moose_options['page_title_large_fontsize'])>35) {
		 	$page_title_font_size *= 0.7;
		} ?>
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($page_title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h2_fontsize']) && ($eltd_moose_options['h2_fontsize'])>30) { ?>
			.content h2{
				font-size:<?php echo esc_attr($eltd_moose_options['h2_fontsize'])*0.5; ?>px!important;
			}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h2_lineheight']) && ($eltd_moose_options['h2_lineheight'])>45) { ?>
		.content h2{
			line-height: 1.3em!important;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h3_fontsize']) && ($eltd_moose_options['h3_fontsize'])>30) { ?>
		.content h3{
			font-size:<?php echo esc_attr($eltd_moose_options['h3_fontsize'])*0.5; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h4_fontsize']) && ($eltd_moose_options['h4_fontsize'])>30) { ?>
		.content h4{
			font-size:<?php echo esc_attr($eltd_moose_options['h4_fontsize'])*0.5; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h5_fontsize']) && ($eltd_moose_options['h5_fontsize'])>30) { ?>
		.content h5{
			font-size:<?php echo esc_attr($eltd_moose_options['h5_fontsize'])*0.5; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h6_fontsize']) && ($eltd_moose_options['h6_fontsize'])>30) { ?>
		.content h6{
			font-size:<?php echo esc_attr($eltd_moose_options['h6_fontsize'])*0.5; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['title_span_background_color']) && !empty($eltd_moose_options['title_span_background_color'])) { ?>
		.title h1 span{
			padding: 0 5px;
		}
	<?php } ?>
}

@media only screen and (max-width: 480px){

	<?php if(isset($eltd_moose_options['h1_fontsize']) && $eltd_moose_options['h1_fontsize'] !== '') {
		$title_font_size = $eltd_moose_options['h1_fontsize'];
		if (($eltd_moose_options['h1_fontsize'])>65) {
		 	$title_font_size *= 0.4;
		}
		elseif (($eltd_moose_options['h1_fontsize'])>50) {
		 	$title_font_size *= 0.5;
		}
		elseif (($eltd_moose_options['h1_fontsize'])>35) {
		 	$title_font_size *= 0.6;
		} ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['page_title_fontsize']) && ($eltd_moose_options['page_title_fontsize']) !== '') {
		$page_title_font_size = $eltd_moose_options['page_title_fontsize'];
		if (($eltd_moose_options['page_title_fontsize'])>65) {
		 	$page_title_font_size *= 0.3;
		}
		elseif (($eltd_moose_options['page_title_fontsize'])>50) {
		 	$page_title_font_size *= 0.4;
		}
		elseif (($eltd_moose_options['page_title_fontsize'])>35) {
		 	$page_title_font_size *= 0.5;
		}
		elseif (($eltd_moose_options['page_title_fontsize'])>20) {
			$page_title_font_size *= 0.6;
		} ?>
		.title.title_size_small h1,
		.title.title_size_small h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($page_title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['page_title_medium_fontsize']) && ($eltd_moose_options['page_title_medium_fontsize']) !== '') {
		$page_title_font_size = $eltd_moose_options['page_title_medium_fontsize'];
		if (($eltd_moose_options['page_title_medium_fontsize'])>65) {
		 	$page_title_font_size *= 0.3;
		}
		elseif (($eltd_moose_options['page_title_medium_fontsize'])>50) {
		 	$page_title_font_size *= 0.4;
		}
		elseif (($eltd_moose_options['page_title_medium_fontsize'])>35) {
		 	$page_title_font_size *= 0.5;
		}
		elseif (($eltd_moose_options['page_title_medium_fontsize'])>20) {
			$page_title_font_size *= 0.6;
		} ?>
		.title.title_size_medium h1,
		.title.title_size_medium h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($page_title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['page_title_large_fontsize']) && ($eltd_moose_options['page_title_large_fontsize']) !== '') {
		$page_title_font_size = $eltd_moose_options['page_title_large_fontsize'];
		if (($eltd_moose_options['page_title_large_fontsize'])>65) {
		 	$page_title_font_size *= 0.3;
		}
		elseif (($eltd_moose_options['page_title_large_fontsize'])>50) {
		 	$page_title_font_size *= 0.4;
		}
		elseif (($eltd_moose_options['page_title_large_fontsize'])>35) {
		 	$page_title_font_size *= 0.5;
		}
		elseif (($eltd_moose_options['page_title_large_fontsize'])>20) {
			$page_title_font_size *= 0.6;
		} ?>
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($page_title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h2_fontsize']) && ($eltd_moose_options['h2_fontsize'])>30) { ?>
			.content h2{
				font-size:<?php echo esc_attr($eltd_moose_options['h2_fontsize'])*0.4; ?>px!important;
			}
	<?php }
		elseif(isset($eltd_moose_options['h2_fontsize']) && ($eltd_moose_options['h2_fontsize'])>20) { ?>
			.content h2{
				font-size:<?php echo esc_attr($eltd_moose_options['h2_fontsize'])*0.6; ?>px!important;
			}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h3_fontsize']) && ($eltd_moose_options['h3_fontsize'])>30) { ?>
		.content h3{
			font-size:<?php echo esc_attr($eltd_moose_options['h3_fontsize'])*0.4; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h4_fontsize']) && ($eltd_moose_options['h4_fontsize'])>30) { ?>
		.content h4{
			font-size:<?php echo esc_attr($eltd_moose_options['h4_fontsize'])*0.4; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h5_fontsize']) && ($eltd_moose_options['h5_fontsize'])>30) { ?>
		.content h5{
			font-size:<?php echo esc_attr($eltd_moose_options['h5_fontsize'])*0.4; ?>px;
		}
	<?php } ?>
	<?php if(isset($eltd_moose_options['h6_fontsize']) && ($eltd_moose_options['h6_fontsize'])>35) { ?>
		.content h6{
			font-size:<?php echo esc_attr($eltd_moose_options['h6_fontsize'])*0.4; ?>px;
		}
	<?php } ?>
		
	<?php if (isset($eltd_moose_options['parallax_minheight']) && !empty($eltd_moose_options['parallax_minheight'])) { ?>
	section.parallax_section_holder{
		height: auto !important;
		min-height: <?php echo esc_attr($eltd_moose_options['parallax_minheight']); ?>px !important;
	}
	<?php } ?>
	
	
	<?php if (isset($eltd_moose_options['header_background_color_mobile']) &&  !empty($eltd_moose_options['header_background_color_mobile'])) { ?>
	header
	{
		 background-color: <?php echo esc_attr($eltd_moose_options['header_background_color_mobile']);  ?> !important;
		 background-image:none;
	}
	<?php } ?>

	<?php
		if(isset($eltd_moose_options['masonry_gallery_square_big_title_font_size']) && ($eltd_moose_options['masonry_gallery_square_big_title_font_size']) > 30) { ?>
		        .masonry_gallery_item.square_big h3 {
	        		font-size: <?php echo esc_attr($eltd_moose_options['masonry_gallery_square_big_title_font_size'])*0.7; ?>px;
	    		}
		<?php }
	?>
}