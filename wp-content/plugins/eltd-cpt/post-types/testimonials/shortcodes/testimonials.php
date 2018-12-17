<?php

namespace ElatedCPT\CPT\Testimonials\Shortcodes;


use ElatedCPT\Lib;
/**
 * Class Testimonials
 * @package ElatedCPT\CPT\Testimonials\Shortcodes
 */
class Testimonials implements Lib\ShortcodeInterface {
    /**
     * @var string
     */
    private $base;
	
    public function __construct() {
        $this->base = 'no_testimonials';

        add_action('vc_before_init', array($this, 'vcMap'));
    }

    /**
     * Returns base for shortcode
     * @return string
     */
    public function getBase() {
        return $this->base;
    }

    /**
     * Maps shortcode to Visual Composer
     *
     * @see vc_map()
     */
    public function vcMap() {
        if(function_exists('vc_map')) {
			global $eltdIconCollections;
			
			$icons_array= array();
			if(eltd_moose_cpt_theme_installed()) {
				$icons_array = $eltdIconCollections->getVCParamsArray(array("element" => "testimonial_type", "value" => array("with_icon", "carousel")), '', false);
			}
			
            vc_map( array(
                "name" => "Testimonials",
                "base" => $this->base,
                "category" => 'by Elated',
                "icon" => "icon-wpb-testimonials extended-custom-icon",
                "allowed_container_element" => 'vc_row',
                "params" => array_merge(
					array(
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Type",
							"param_name" => "testimonial_type",
							"value" => array(
								"Carousel" => "carousel",
								"Vertically Aligned" => "image_above",
								"Horizontally Aligned" => "image_left",
								"Horizontally Aligned With Icon" => "with_icon"
							),
							"save_always" => true,
							"description" => ""
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Category",
							"param_name" => "category",
							"value" => "",
							"description" => "Category Slug (leave empty for all)"
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Order By",
							"param_name" => "order_by",
							"value" => array(
								"" => "",
								"Title" => "title",
								"Date" => "date"
							),
							"description" => ""
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Order",
							"param_name" => "order",
							"value" => array(
								"" => "",
								"ASC" => "ASC",
								"DESC" => "DESC",
							),
							"description" => ""
						),
										array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Number",
							"param_name" => "number",
							"value" => "",
							"description" => "Number of Testimonials"
						),
					),
					$icons_array,
					array(
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Icon Font Size",
							"param_name" => "icon_font_size",
							"value" => "",
							"description" => "",
							"dependency" => array("element" => "testimonial_type", "value" => array("with_icon", "carousel"))
						),
						array(
							"type" => "colorpicker",
							"holder" => "div",
							"class" => "",
							"heading" => "Icon Color",
							"param_name" => "icon_color",
							"description" => "",
							"dependency" => array("element" => "testimonial_type", "value" => array("with_icon", "carousel"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Show Title",
							"param_name" => "show_title",
							"value" => array(
								"Yes" => "yes",
								"No" => "no"
							),
							"save_always" => true,
							"description" => ""
						),
						array(
							"type" => "colorpicker",
							"holder" => "div",
							"class" => "",
							"heading" => "Title Color",
							"param_name" => "title_color",
							"description" => "",
							"dependency" => array("element" => "show_title", "value" => array("yes"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Show Title Separator",
							"param_name" => "show_title_separator",
							"value" => array(
								"No" => "no",
								"Yes" => "yes"
							),
							"save_always" => true,
							"description" => ""
						),
						array(
							"type" => "colorpicker",
							"holder" => "div",
							"class" => "",
							"heading" => "Separator Color",
							"param_name" => "separator_color",
							"description" => "",
							"dependency" => array("element" => "show_title_separator", "value" => array("yes"))
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Separator Width",
							"param_name" => "separator_width",
							"description" => "",
							"dependency" => array("element" => "show_title_separator", "value" => array("yes"))
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Separator Height",
							"param_name" => "separator_height",
							"description" => "",
							"dependency" => array("element" => "show_title_separator", "value" => array("yes"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Text Align",
							"param_name" => "text_align",
							"value" => array(
								"Left"   => "left_align",
								"Center" => "center_align",
								"Right"  => "right_align"
							),
							"save_always" => true
						),
						array(
							"type" => "colorpicker",
							"holder" => "div",
							"class" => "",
							"heading" => "Text Color",
							"param_name" => "text_color",
							"description" => ""
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Text Font Family",
							"param_name" => "text_font_family",
							"description" => ""
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Text Font Size",
							"param_name" => "text_font_size",
							"description" => ""
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Text Line Height (px)",
							"param_name" => "text_line_height",
							"description" => ""
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Text Font Style",
							"param_name" => "text_font_style",
							"value" => array(
								"" => "",
								"Normal" => "normal",
								"Italic" => "italic"
							)
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Text Top Padding",
							"param_name" => "text_top_padding",
							"description" => ""
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Text Bottom Padding",
							"param_name" => "text_bottom_padding",
							"description" => ""
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Show Author",
							"param_name" => "show_author",
							"value" => array(
								"Yes" => "yes",
								"No" => "no"
							),
							"save_always" => true,
							"description" => ""
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Author Position",
							"param_name" => "author_position",
							"value" => array(
								"Below Text" => "below_text",
								"Above Text" => "above_text"
							),
							"save_always" => true,
							"description" => "Not working for carousel type",
							"dependency" => array("element" => "show_author", "value" => array("yes"))
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Author Text Font Family",
							"param_name" => "author_text_font_family",
							"description" => "",
							"dependency" => array("element" => "show_author", "value" => array("yes"))
						),
						array(
							"type" => "colorpicker",
							"holder" => "div",
							"class" => "",
							"heading" => "Author Text Color",
							"param_name" => "author_text_color",
							"description" => "",
							"dependency" => array("element" => "show_author", "value" => array("yes"))
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Author Font Size (px)",
							"param_name" => "author_font_size",
							"description" => "",
							"dependency" => array("element" => "show_author", "value" => array("yes"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Author Font Weigth",
							"param_name" => "author_font_weight",
							"value" => array(
								"Default" => "",
								"Thin 100" => "100",
								"Extra-Light 200" => "200",
								"Light 300" => "300",
								"Regular 400" => "400",
								"Medium 500" => "500",
								"Semi-Bold 600" => "600",
								"Bold 700" => "700",
								"Extra-Bold 800" => "800",
								"Ultra-Bold 900" => "900"
							),
							"description" => "",
							"dependency" => array("element" => "show_author", "value" => array("yes"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Author Font Style",
							"param_name" => "author_font_style",
							"value" => array(
								"" => "",
								"Normal" => "normal",
								"Italic" => "italic"
							),
							"description" => "",
							"dependency" => array("element" => "show_author", "value" => array("yes"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Show Author Job Position",
							"param_name" => "show_position",
							"value" => array(
								"No" => "no",
								"Yes" => "yes"
							),
							"save_always" => true,
							"dependency" => array("element" => "show_author", "value" => array("yes")),
							"description" => ""
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Job Position Placement",
							"param_name" => "job_position_placement",
							"value" => array(
								"In line with name" => "inline",
								"Below name" => "below"
							),
							"save_always" => true,
							"dependency" => array("element" => "show_position", "value" => array("yes")),
							"description" => ""
						),
						array(
							"type" => "colorpicker",
							"holder" => "div",
							"class" => "",
							"heading" => "Job Color",
							"param_name" => "job_color",
							"dependency" => array("element" => "show_position", "value" => array("yes")),
							"description" => ""
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Job Font size (px)",
							"param_name" => "job_font_size",
							"dependency" => array("element" => "show_position", "value" => array("yes")),
							"description" => ""
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Job Font style",
							"param_name" => "job_font_style",
							"value" => array(
								"" => "",
								"Normal" => "normal",
								"Italic" => "italic"
							),
							"dependency" => array("element" => "show_position", "value" => array("yes")),
							"description" => ""
						),
						array(
							"type" => "colorpicker",
							"holder" => "div",
							"class" => "",
							"heading" => "Top Holder Color",
							"param_name" => "top_holder_color",
							"dependency" => array("element" => "testimonial_type", "value" => array("carousel")),
							"description" => ""
						),
						array(
							"type" => "colorpicker",
							"holder" => "div",
							"class" => "",
							"heading" => "Bottom Holder Color",
							"param_name" => "bottom_holder_color",
							"dependency" => array("element" => "testimonial_type", "value" => array("carousel")),
							"description" => ""
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Show Image",
							"param_name" => "show_image",
							"value" => array(
								"Yes" => "yes",
								"No" => "no"
							),
							"save_always" => true,
							"dependency" => array(
								"element" => "testimonial_type",
								"value" => array(
									"image_above",
									"image_left"
								)
							),
							"description" => ""
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Image Position Related to Testimonial Content",
							"param_name" => "image_position",
							"value" => array(
								"Top" => "top",
								"Bottom" => "bottom"
							),
							"save_always" => true,
							"description" => "",
							"dependency" => array("element" => "testimonial_type", "value" => array("image_above"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Image Position Related to Testimonial Slide",
							"param_name" => "image_position_slide",
							"value" => array(
								"Over the Edge" => "over",
								"Inside" => "inside"
							),
							"save_always" => true,
							"description" => "Image size when the image position is over the edge of testimonial slide is fixed (113x113px). Image size when the image position is inside of testimonial slide is original.",
							"dependency" => array("element" => "testimonial_type", "value" => array("image_above"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Show Image Border",
							"param_name" => "show_image_border",
							"value" => array(
								"No" => "no",
								"Yes" => "yes"
							),
							"save_always" => true,
							"description" => "",
							"dependency" => array("element" => "testimonial_type", "value" => array("image_above"))
						),

						array(
							"type" => "colorpicker",
							"holder" => "div",
							"class" => "",
							"heading" => "Image Border Color",
							"param_name" => "image_border_color",
							"description" => "",
							"dependency" => array("element" => "show_image_border", "value" => array("yes"))
						),

						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Image Border Width",
							"param_name" => "image_border_width",
							"description" => "",
							"dependency" => array("element" => "show_image_border", "value" => array("yes"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Show Navigation Arrows",
							"param_name" => "show_navigation_arrows",
							"value" => array(
								"No" => "no",
								"Yes" => "yes"
							),
							"save_always" => true,
							"description" => "",
							"dependency" => array("element" => "testimonial_type", "value" => array("image_above"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Show Navigation",
							"param_name" => "show_navigation",
							"value" => array(
								"No" => "no",
								"Yes" => "yes"
							),
							"save_always" => true,
							"description" => "",
							"dependency" => array("element" => "testimonial_type", "value" => array("image_above", "carousel"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Navigation Outer Border",
							"param_name" => "navigation_outer_border",
							"value" => array(
								"No" => "no",
								"Yes" => "yes"
							),
							"save_always" => true,
							"description" => "",
							"dependency" => array("element" => "show_navigation", "value" => array("yes"))
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Image Holder Width (%)",
							"param_name" => "image_holder_width",
							"dependency" => array("element" => "testimonial_type", "value" => array("image_left"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Choose Navigation Type",
							"param_name" => "navigation_type",
							"value" => array(
								"None" => "none",
								"Arrows" => "arrows",
								"Buttons" => "buttons"
							),
							"save_always" => true,
							"description" => "",
							"dependency" => array("element" => "testimonial_type", "value" => array("image_left"))
						),
						array(
							"type" => "dropdown",
							"holder" => "div",
							"class" => "",
							"heading" => "Auto rotate slides",
							"param_name" => "auto_rotate_slides",
							"value" => array(
								"3"         => "3",
								"5"         => "5",
								"10"        => "10",
								"15"        => "15",
								"Disable"   => "0"
							),
							"save_always" => true,
							"description" => ""
						),
						array(
							"type" => "textfield",
							"holder" => "div",
							"class" => "",
							"heading" => "Animation speed",
							"param_name" => "animation_speed",
							"value" => "",
							"description" => "Speed of slide animation in miliseconds"
						)
					)
				)
			) );
        }
    }

    /**
     * Renders shortcodes HTML
     *
     * @param $atts array of shortcode params
     * @param $content string shortcode content
     * @return string
     */
    public function render($atts, $content = null) {
        global $eltd_moose_options;
        global $eltdIconCollections;

        $deafult_args = array(
			"testimonial_type" => "carousel",
            "number" => "-1",
            "category" => "",
			"order_by" => "date",
            "order" => "ASC",
            "icon_font_size" => "",
            "icon_color" => "",
            "show_title" => "",
            "title_color" => "",
            "show_title_separator" => "no",
            "separator_color" => "",
            "separator_width" => "",
            "separator_height" => "",
            "text_color" => "",
            "text_font_size" => "",
			"text_font_family" => "",
            "text_line_height" => "",
            "text_font_style" => "",
			"text_top_padding" => "",
			"text_bottom_padding" => "",
            "show_author" => "yes",
            "author_position" => "below_text",
            "author_text_color" => "",
			"author_text_font_family" => "",
            "author_font_size" => "",
			"author_font_weight" => "",
			"author_font_style" => "",
            "show_position" => "no",
            "job_position_placement" => "",
            "job_color" => "",
            "job_font_size" => "",
            "job_font_style" => "",
            "top_holder_color" => "",
            "bottom_holder_color" => "",
            "text_align" => "left_align",
            "show_navigation" => "no",
            "navigation_outer_border" => "no",
            "show_navigation_arrows" => "no",
            "navigation_type" => "arrows",
            "auto_rotate_slides" => "",
            "animation_speed" => "",			
			"image_holder_width" => "",
            "show_image" => "yes",
            "image_position" => "top",
            "show_image_border" => "no",
            "image_border_color" => "",
            "image_border_width" => "",
            "image_position_slide" => ""
        );
		
		$args = array_merge($deafult_args, $eltdIconCollections->getShortcodeParams());

        extract(shortcode_atts($args, $atts));
		
        $number = esc_attr($number);
        $category = esc_attr($category);
        $icon_font_size = esc_attr($icon_font_size);
        $icon_color = esc_attr($icon_color);
        $title_color = esc_attr($title_color);
        $separator_color = esc_attr($separator_color);
        $separator_width = esc_attr($separator_width);
        $separator_height = esc_attr($separator_height);
        $text_color = esc_attr($text_color);
		$text_font_family = esc_attr($text_font_family);
        $text_font_size = esc_attr($text_font_size);
        $text_font_style = esc_attr($text_font_style);
		$text_top_padding = esc_attr($text_top_padding);
		$text_bottom_padding = esc_attr($text_bottom_padding);
        $author_text_color = esc_attr($author_text_color);
		$author_text_font_family = esc_attr($author_text_font_family);
		$author_font_weight = esc_attr($author_font_weight);
		$author_font_style = esc_attr($author_font_style);
        $job_color = esc_attr($job_color);
        $job_font_size = esc_attr($job_font_size);
        $job_font_style = esc_attr($job_font_style);
        $top_holder_color = esc_attr($top_holder_color);
        $bottom_holder_color = esc_attr($bottom_holder_color);
        $animation_speed = esc_attr($animation_speed);
        $image_border_color = esc_attr($image_border_color);
        $image_border_width = esc_attr($image_border_width);
		$image_holder_width =  esc_attr($image_holder_width);
		
        $html = "";
        $html_author = "";		
        $add_icon = '';
        $testimonial_p_style = "";
        $testimonial_separator_style = "";
        $testimonial_title_style = "";
        $testimonial_icon_style = "";
        $navigation_button_radius = "";
        $testimonial_name_styles = "";
        $testimonials_clasess = "";
        $image_clasess = "";
        $testimonial_image_border_style = "";
        $job_style = "";
        $top_holder_style = "";
        $bottom_holder_style = "";
		$data_attr = '';

        if ($testimonial_type == "image_left") {
	        if ($navigation_type != 'none') {
	        	if ($navigation_type == 'arrows') {
	        		$show_navigation_arrows = 'yes';
	        		$show_navigation = 'no';
	        	}
	        	else {
	        		$show_navigation_arrows = 'no';
	        		$show_navigation = 'yes';
	        	}
	        }
		}

        if ($show_navigation_arrows == "yes") {
            $testimonials_clasess .= ' with_arrows';
        }

		if ($testimonial_type != "") {
			$testimonials_clasess .= ' ' . $testimonial_type;
		}

		if ($show_image == "yes") {
			$testimonials_clasess .= ' show_images';
		}
		
		if ($job_position_placement == "inline") {
			$testimonials_clasess .= ' job_position_inline';
		}
		elseif ( $job_position_placement == "below") {
			$testimonials_clasess .= ' job_position_below';
		}
		
		if($navigation_outer_border == 'yes') {
			$testimonials_clasess .= ' navigation_outer_border';
		}
		
		if($image_holder_width != '' && $testimonial_type == "image_left"){
			$data_attr .= " data-image-holder-width ='" . $image_holder_width . "'";
		}

        if ($testimonial_type == 'image_above'){
	        if ($show_image == "yes" && $image_position == "top") {
	            $image_clasess .= ' image_top';
	        }

	        if ($show_image == "yes" && $image_position == "bottom") {
	            $image_clasess .= ' image_bottom';
	        }

	        if ($show_image == "yes" && $image_position_slide == "inside") {
	            $image_clasess .= ' relative_position';
	        }

	        if ($show_image == "yes" && $image_position_slide == "over") {
	            $image_clasess .= ' absolute_position';
	        }
	    }

        if ($separator_color != "") {
            $testimonial_separator_style .= "background-color: " . $separator_color . ";";
        }
        if ($separator_width != "") {
            $testimonial_separator_style .= "width: " . $separator_width . "px;";
        }
        if ($separator_height != "") {
            $testimonial_separator_style .= "height: " . $separator_height . "px;";
        }
        if ($title_color != "") {
            $testimonial_title_style .= "color: " . $title_color . ";";
        }

        if ( $show_image_border == "yes" ) {
            if ($image_border_color != "") {
                $testimonial_image_border_style .= "border-color: " . $image_border_color . ";";
            }

            if ($image_border_width != "") {
                $testimonial_image_border_style .= "border-width: " . $image_border_width . "px;";
            }
        }
		
		if ($icon_pack != "") {
			$testimonial_icon_style = '';
			$icon_collection_obj = $eltdIconCollections->getIconCollection($icon_pack);

			if ($icon_font_size != "") {
				$testimonial_icon_style .= 'font-size: ' . $icon_font_size . 'px;';
			}
			
			if ($icon_color != "") {
				$testimonial_icon_style .= "color:" . $icon_color . ";";
			}

			if (method_exists($icon_collection_obj, 'render')) {
				$add_icon .= $icon_collection_obj->render(${$icon_collection_obj->param}, array(
					'icon_attributes' => array(
						'style' => $testimonial_icon_style,
						'class' => 'show_load_more_icon'
					)
				));
			}

		}

        if ($text_font_size != "" || $text_color != "" || $text_top_padding != "" || $text_bottom_padding != "" || $text_font_style != "" || $text_line_height != "" || $text_font_family !="") {
            $testimonial_p_style = " style='";
			if ($text_font_family != "") {
                $testimonial_p_style .= "font-family:" . $text_font_family . "!important;";
            }
            if ($text_font_size != "") {
                $testimonial_p_style .= "font-size:" . $text_font_size . "px;";
            }
            if ($text_font_style != "") {
                $testimonial_p_style .= "font-style:" . $text_font_style . ";";
            }
			if ($text_line_height != "") {
				$text_line_height = (strstr($text_line_height, 'px', true)) ? $text_line_height : $text_line_height . 'px';
				$testimonial_p_style .= "line-height:" . $text_line_height . ";";
			}
            if ($text_color != "") {
                $testimonial_p_style .= "color:" . $text_color . ";";
            }
            if ($text_top_padding != "") {
				$testimonial_p_style .= "padding-top:" . $text_top_padding . "px;";
			}
			if ($text_bottom_padding != "") {
				 $testimonial_p_style .= "padding-bottom:" . $text_bottom_padding . "px;";
			}
            $testimonial_p_style .= "'";
        }

        if ($author_text_color != "") {
            $testimonial_name_styles .= "color: " . $author_text_color . ";";
        }
		if ($author_text_font_family != "") {
            $testimonial_name_styles .= "font-family: " . $author_text_font_family . ";";
        }
        if ($author_font_size != "") {
            $author_font_size = (strstr($author_font_size, 'px', true)) ? $author_font_size : $author_font_size . 'px';
            $testimonial_name_styles .= "font-size: " . $author_font_size . ";";
        }		
		if ($author_font_weight != "") {
            $testimonial_name_styles .= "font-weight: " . $author_font_weight . ";";
        }
		if ($author_font_style != "") {
            $testimonial_name_styles .= "font-style: " . $author_font_style . ";";
        }

        if ($job_color != "") {
            $job_style .= 'color: '.$job_color.';';
        }
        if ($job_font_size != "") {
            $job_font_size = (strstr($job_font_size, 'px', true)) ? $job_font_size : $job_font_size . 'px';
            $job_style .= 'font-size: '.$job_font_size.'px;';
        }
        if ($job_font_style != "") {
            $job_style .= 'font-style: '.$job_font_style.';';
        }
		if ($top_holder_color != "") {
            $top_holder_style .= ' background-color: '.$top_holder_color.';';
        }
		if ($bottom_holder_color != "") {
            $bottom_holder_style .= ' background-color: '.$bottom_holder_color.';';
        }

        $args = array(
            'post_type' => 'testimonials',
            'orderby' => $order_by,
            'order' => $order,
            'posts_per_page' => $number
        );

        if ($category != "") {
            $args['testimonials_category'] = $category;
        }


        $html .= "<div class='testimonials_holder clearfix'>";
        $html .= '<div class="testimonials testimonials_carousel ' . $testimonials_clasess . '" data-show-navigation="' . $show_navigation . '" data-show-navigation-arrows="' . $show_navigation_arrows . '" data-animation-speed="' . $animation_speed . '" data-auto-rotate-slides="' . $auto_rotate_slides . '">';
        $html .= '<ul class="slides">';

        query_posts($args);
        if (have_posts()) :
			$post_number = 0;
            while (have_posts()) : the_post();
                $author = get_post_meta(get_the_ID(), "eltd_testimonial-author", true);
                $text = get_post_meta(get_the_ID(), "eltd_testimonial-text", true);
                $title = get_post_meta(get_the_ID(), "eltd_testimonial_title", true);
                $job = get_post_meta(get_the_ID(), "eltd_testimonial_author_position", true);
				$post_number += 1;

				if ($testimonial_type != "carousel"){
					$html .= '<li id="testimonials' . get_the_ID() . '" class="testimonial_content ' . $text_align . ' ' . $image_clasess . '">';
				}
				else if($testimonial_type == "carousel" && ($post_number % 3) == 1){
					$html .= '<li id="testimonials' . get_the_ID() . '" class="testimonial_content ' . $text_align . ' ' . $image_clasess . '">';
				}

                switch ($testimonial_type) {
                	case 'image_left':
                		
                		$html .= '<div class = "testimonial_image_left_holder" '.$data_attr.'>';
		                if ($show_image == "yes" && has_post_thumbnail(get_the_ID())) {
		                    $html .= '<div class="testimonial_image_holder" style="' . $testimonial_image_border_style . '">' . get_the_post_thumbnail(get_the_ID()) . '</div>';
		                }
		                $html .= '<div class="testimonial_content_inner"';

		                $html .= '>';
		                $html .= '<div class="testimonial_text_holder ' . $text_align . '">';

		                if ($show_author == "yes") {
		                    $html_author = '<p class="testimonial_author" style="' . $testimonial_name_styles . '">- ' . $author;
		                    if ($show_position == "yes" && $job !== '') {
		                        if( $job_position_placement == "inline" ) {
		                            $html_author .= ', <span class="testimonials_job" style="'.$job_style.'">'.$job.'</span>';
		                        }
		                        elseif ( $job_position_placement == "below") {
		                            $html_author .= '<span class="testimonials_job below" style="'.$job_style.'">'.$job.'</span>';
		                        }
		                    }
		                    $html_author .= '</p>';
		                }

		                $testimonial_text_inner_class = '';
		                if($show_title == "no") {
		                    $testimonial_text_inner_class .= ' without_title';
		                }

		                $html .= '<div class="testimonial_text_inner'. $testimonial_text_inner_class .'">';
		                if ($show_title == "yes") {
		                    $html .= '<p class="testimonial_title" style="' . $testimonial_title_style . '">' . $title . '</p>';
		                }
		                if ($show_title_separator == "yes") {
		                    $html .= '<span class="testimonial_separator" style="' . $testimonial_separator_style . '"></span>';
		                }
		                if ($author_position == "below_text") {
		                    $html .= '<p class="testimonial_text"' . $testimonial_p_style . '>' . trim($text) . '</p>';
		                    $html .= $html_author;
		                } elseif ($author_position == "above_text") {
		                    $html .= $html_author;
		                    $html .= '<p class="testimonial_text"' . $testimonial_p_style . '>' . trim($text) . '</p>';
		                }


		                $html .= '</div>'; //close testimonial_text_inner
		                $html .= '</div>'; //close testimonial_text_holder
		                $html .= '</div>'; //close testimonial_image_left_holder

		                $html .= '</div>'; //close testimonial_content_inner
		                break;
                	
                	case 'image_above':
                		if ($show_image == "yes" && !($image_position == "bottom" && $image_position_slide == "inside")) {
		                    $html .= '<div class="testimonial_image_holder" style="' . $testimonial_image_border_style . '">' . get_the_post_thumbnail(get_the_ID()) . '</div>';
		                }
		                $html .= '<div class="testimonial_content_inner"';

		                $html .= '>';
		                $html .= '<div class="testimonial_text_holder ' . $text_align . '">';

		                if ($show_author == "yes") {
		                    $html_author = '<p class="testimonial_author" style="' . $testimonial_name_styles . '">- ' . $author;
		                    if ($show_position == "yes" && $job !== '') {
		                        if( $job_position_placement == "inline" ) {
		                            $html_author .= ', <span class="testimonials_job" style="'.$job_style.'">'.$job.'</span>';
		                        }
		                        elseif ( $job_position_placement == "below") {
		                            $html_author .= '<span class="testimonials_job below" style="'.$job_style.'">'.$job.'</span>';
		                        }
		                    }
		                    $html_author .= '</p>';
		                }

		                $testimonial_text_inner_class = '';
		                if($show_title == "no") {
		                    $testimonial_text_inner_class .= ' without_title';
		                }

		                $html .= '<div class="testimonial_text_inner'. $testimonial_text_inner_class .'">';
		                if ($show_title == "yes") {
		                    $html .= '<p class="testimonial_title" style="' . $testimonial_title_style . '">' . $title . '</p>';
		                }
		                if ($show_title_separator == "yes") {
		                    $html .= '<span class="testimonial_separator" style="' . $testimonial_separator_style . '"></span>';
		                }
		                if ($author_position == "below_text") {
		                    $html .= '<p class="testimonial_text"' . $testimonial_p_style . '>' . trim($text) . '</p>';
		                    $html .= $html_author;
		                } elseif ($author_position == "above_text") {
		                    $html .= $html_author;
		                    $html .= '<p class="testimonial_text"' . $testimonial_p_style . '>' . trim($text) . '</p>';
		                }


		                $html .= '</div>'; //close testimonial_text_inner
		                $html .= '</div>'; //close testimonial_text_holder

		                $html .= '</div>'; //close testimonial_content_inner
		                if ($show_image == "yes" && $image_position == "bottom" && $image_position_slide == "inside") {
		                    $html .= '<div class="testimonial_image_holder" style="' . $testimonial_image_border_style . '">' . get_the_post_thumbnail(get_the_ID()) . '</div>';
		                }
                		break;
						
					case 'with_icon':
						$html .= '<div class = "testimonial_with_icon_holder" '.$data_attr.'>';			               
						$html .= '<div class="testimonial_icon_holder">';
						$html .= $add_icon;
						$html .= '</span>';							
						$html .= '</div>';		               
		                $html .= '<div class="testimonial_content_inner">';
		                $html .= '<div class="testimonial_text_holder ' . $text_align . '">';

		                if ($show_author == "yes") {
		                    $html_author = '<p class="testimonial_author" style="' . $testimonial_name_styles . '">- ' . $author;
		                    if ($show_position == "yes" && $job !== '') {
		                        if( $job_position_placement == "inline" ) {
		                            $html_author .= ', <span class="testimonials_job" style="'.$job_style.'">'.$job.'</span>';
		                        }
		                        elseif ( $job_position_placement == "below") {
		                            $html_author .= '<span class="testimonials_job below" style="'.$job_style.'">'.$job.'</span>';
		                        }
		                    }
		                    $html_author .= '</p>';
		                }

		                $testimonial_text_inner_class = '';
		                if($show_title == "no") {
		                    $testimonial_text_inner_class .= ' without_title';
		                }

		                $html .= '<div class="testimonial_text_inner'. $testimonial_text_inner_class .'">';
		                if ($show_title == "yes" && $title != "") {
		                    $html .= '<p class="testimonial_title" style="' . $testimonial_title_style . '">' . $title . '</p>';
		                }
		                if ($show_title_separator == "yes") {
		                    $html .= '<span class="testimonial_separator" style="' . $testimonial_separator_style . '"></span>';
		                }
		                if ($author_position == "below_text") {
		                    $html .= '<p class="testimonial_text"' . $testimonial_p_style . '>' . trim($text) . '</p>';
		                    $html .= $html_author;
		                } elseif ($author_position == "above_text") {
		                    $html .= $html_author;
		                    $html .= '<p class="testimonial_text"' . $testimonial_p_style . '>' . trim($text) . '</p>';
		                }


		                $html .= '</div>'; //close testimonial_text_inner
		                $html .= '</div>'; //close testimonial_text_holder
		                $html .= '</div>'; //close testimonial_image_left_holder

		                $html .= '</div>'; //close testimonial_content_inner
		                break;
					
					case 'carousel':
					
						if ($show_author == "yes") {
		                    $html_author = '<p class="testimonial_author" style="' . $testimonial_name_styles . '"> ' . $author;
		                    if ($show_position == "yes" && $job !== '') {
		                        if( $job_position_placement == "inline" ) {
		                            $html_author .= ', <span class="testimonials_job" style="'.$job_style.'">'.$job.'</span>';
		                        }
		                        elseif ( $job_position_placement == "below") {
		                            $html_author .= '<span class="testimonials_job below" style="'.$job_style.'">'.$job.'</span>';
		                        }
		                    }
		                    $html_author .= '</p>';
		                }
						
						$html_text = '';
						if ($show_title == "yes" && $title != "") {
							$html_text .= '<p class="testimonial_title" style="' . $testimonial_title_style . '">' . $title . '</p>';
		                }
		                if ($show_title_separator == "yes") {
		                    $html_text .= '<span class="testimonial_separator" style="' . $testimonial_separator_style . '"></span>';
		                }
						$html_text .= '<p class="testimonial_text"' . $testimonial_p_style . '>' . trim($text) . '</p>';
					
						$html .= '<div class="testimonials_carousel_holder carousel_three">'; //open testimonial holder
						$html .= '<div class="testimonial_content_inner">';	//open testimonial content
						$html .= '<div class="testimonial_top_holder" style="' . $top_holder_style . '">'; // open top holder
						$html .= '<div class="testimonial_image_holder">';	// open image holder
						$html .= get_the_post_thumbnail(get_the_ID());	// image goes here
						$html .= '</div>'; // close image holder
						$html .= '<div class="testimonial_text_inner">'; // open text holder
						$html .= $html_text;	// text goes here
						$html .= '</div>';	// close text holder
						$html .= '</div>';	// close top holder
						$html .= '<div class="testimonial_bottom_holder" style="' . $bottom_holder_style . '">';	// open bottom holder
						$html .= '<div class="testimonial_icon_holder">'; // open icon holder
						$html .= $add_icon;	// icon goes here
						$html .= '</div>'; // close icon holder
						$html .= '<div class="testimonial_author_holder">'; // open author holder
						$html .= $html_author;	// author goes here
						$html .= '</div>';	// close author holder
						$html .= '</div>';	// close bottom holder
						$html .= '</div>';	// close testimonial content
						$html .= '</div>'; // close testimonial holder
						break;

                	default:
		                if ($show_image == "yes" && !($image_position == "bottom" && $image_position_slide == "inside")) {
		                    $html .= '<div class="testimonial_image_holder" style="' . $testimonial_image_border_style . '">' . get_the_post_thumbnail(get_the_ID()) . '</div>';
		                }
		                $html .= '<div class="testimonial_content_inner"';

		                $html .= '>';
		                $html .= '<div class="testimonial_text_holder ' . $text_align . '">';

		                if ($show_author == "yes") {
		                    $html_author = '<p class="testimonial_author" style="' . $testimonial_name_styles . '">- ' . $author;
		                    if ($show_position == "yes" && $job !== '') {
		                        if( $job_position_placement == "inline" ) {
		                            $html_author .= ', <span class="testimonials_job" style="'.$job_style.'">'.$job.'</span>';
		                        }
		                        elseif ( $job_position_placement == "below") {
		                            $html_author .= '<span class="testimonials_job below" style="'.$job_style.'">'.$job.'</span>';
		                        }
		                    }
		                    $html_author .= '</p>';
		                }

		                $testimonial_text_inner_class = '';
		                if($show_title == "no") {
		                    $testimonial_text_inner_class .= ' without_title';
		                }

		                $html .= '<div class="testimonial_text_inner'. $testimonial_text_inner_class .'">';
		                if ($show_title == "yes") {
		                    $html .= '<p class="testimonial_title" style="' . $testimonial_title_style . '">' . $title . '</p>';
		                }
		                if ($show_title_separator == "yes") {
		                    $html .= '<span class="testimonial_separator" style="' . $testimonial_separator_style . '"></span>';
		                }
		                if ($author_position == "below_text") {
		                    $html .= '<p class="testimonial_text"' . $testimonial_p_style . '>' . trim($text) . '</p>';
		                    $html .= $html_author;
		                } elseif ($author_position == "above_text") {
		                    $html .= $html_author;
		                    $html .= '<p class="testimonial_text"' . $testimonial_p_style . '>' . trim($text) . '</p>';
		                }


		                $html .= '</div>'; //close testimonial_text_inner
		                $html .= '</div>'; //close testimonial_text_holder

		                $html .= '</div>'; //close testimonial_content_inner
		                if ($show_image == "yes" && $image_position == "bottom" && $image_position_slide == "inside") {
		                    $html .= '<div class="testimonial_image_holder" style="' . $testimonial_image_border_style . '">' . get_the_post_thumbnail(get_the_ID()) . '</div>';
		                }
                		break;
                }

                if ($testimonial_type != "carousel"){
					$html .= '</li>'; //close testimonials
				}
				else if($testimonial_type == "carousel" && ($post_number % 3) == 0){
					$html .= '</li>'; //close testimonials
				}
            endwhile;
        else:
            $html .= __('Sorry, no posts matched your criteria.', 'eltd_cpt');
        endif;

        wp_reset_query();
        $html .= '</ul>'; //close slides
        $html .= '</div>';
        $html .= '</div>';
        return $html;
    }
}