<?php
namespace ElatedCPT\CPT\Carousels\Shortcodes;

use ElatedCPT\Lib;

/**
 * Class Carousel
 * @package ElatedCPT\CPT\Carousels\Shortcodes
 */
class Carousel implements Lib\ShortcodeInterface {
    /**
     * @var string
     */
    private $base;

    public function __construct() {
        $this->base = 'no_carousel';

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
     * Maps shortcode to Visual Composer. Hooked on vc_before_init
     *
     * @see eltd_moose_cpt_get_carousel_slider_array_vc()
     */
    public function vcMap() {
        if(function_exists('vc_map')) {
            vc_map( array(
                "name" => "Elated Carousel",
                "base" => $this->base,
                "category" => 'by Elated',
                "icon" => "icon-wpb-carousel-slider extended-custom-icon",
                "allowed_container_element" => 'vc_row',
                "params" => array(
					array(
						"type" => "dropdown",
						"class" => "",
						"heading" => "Carousel Type",
						"param_name" => "type",
						"value" => array(
							"Default" => "",
							"Title and Text Visible" => "title_and_text"
						),
						"description" => ""
					),
                    array(
                        "type" => "dropdown",
                        "class" => "",
                        "heading" => "Carousel Slider",
                        "param_name" => "carousel",
                        "value" => eltd_moose_cpt_get_carousel_slider_array_vc(),
                        "description" => ""
                    ),
                    array(
                        "type" => "dropdown",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Order By",
                        "param_name" => "orderby",
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
                        "type" => "dropdown",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Number of items showing",
                        "param_name" => "number_of_items",
                        "value" => array(
                            "Default" => "",
                            "3" => "3",
                            "4" => "4",
                            "5" => "5",
                            "6" => "6"
                        ),
						"save_always" => true,
                        "description" => ""
                    ),
					array(
						"type" => "dropdown",
						"holder" => "div",
						"class" => "",
						"heading" => "Title Tag",
						"param_name" => "title_tag",
						"value" => array(
							"" => "",
							"h2" => "h2",
							"h3" => "h3",
							"h4" => "h4",
							"h5" => "h5",
							"h6" => "h6"
						),
						"description" => "Default tag is h5",
						"dependency" => array("element" => "type","value" => "title_and_text")
					),
                    array(
                        "type" => "dropdown",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Image Animation",
                        "param_name" => "image_animation",
                        "value" => array(
                            "Roll Over" => "roll_over",
                            "Image Change" => "image_change",
                            "Image Zoom" => "image_zoom",
                            "Image Jump" => "image_jump"
                        ),
						"save_always" => true,
                        "description" => "Note: Only on 'Roll Over' and 'Image Change', two images will be used"
                    ),
                    array(
                        "type" => "dropdown",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Show navigation?",
                        "param_name" => "show_navigation",
                        "value" => array(
                            "Yes" => "yes",
                            "No" => "no",
                        ),
						"save_always" => true,
                        "description" => ""
                    ),
                    array(
                        "type" => "dropdown",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Show Items In Two Rows?",
                        "param_name" => "show_in_two_rows",
                        "value" => array(
                            "No" => "",
                            "Yes" => "yes",
                        ),
                        "description" => ""
                    ),
                    array(
                        "type" => "textfield",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Margin Between Two Rows (px)",
                        "param_name" => "margin_between_rows",
                        "description" => "Default value is 50",
                        "dependency" => array('element' => "show_in_two_rows", 'value' => array('yes'))
                    ),
                    array(
                        "type" => "textfield",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Item Margin Left(px)",
                        "param_name" => "item_margin_left",
                        "description" => ""
                    ),
                    array(
                        "type" => "textfield",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Item Margin Right(px)",
                        "param_name" => "item_margin_right",
                        "description" => ""
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

        $args = array(
        	"type" => "",
            "carousel" => "",
            "orderby" => "date",
            "order" => "ASC",
            "number_of_items" => "",
            "title_tag" => "h3",
            "image_animation" => "roll_over",
            "show_navigation" => "",
            "show_in_two_rows" => "",
            "margin_between_rows" => "",
            "item_margin_left" => "",
            "item_margin_right" => ""
        );

        extract(shortcode_atts($args, $atts));

        $item_margin_style = array();
        $carousel_image_classes = "";

        if($image_animation == 'image_zoom'){
            $carousel_image_classes .= 'hover_zoom';
        }
		
		if($image_animation == 'image_jump'){
            $carousel_image_classes .= 'image_jump';
        }

        if($item_margin_left !=''){
            $item_margin_style[] = 'margin-left: '. $item_margin_left .'px';
        }

        if($item_margin_right !=''){
            $item_margin_style[] = 'margin-right: '. $item_margin_right .'px';
        }


        $item_margin_style_string = '';

        if(is_array($item_margin_style) && count($item_margin_style)) {
            $item_margin_style_string = 'style="'.implode(';', $item_margin_style).'"';
        }

        $data_attribute = "";
        if ($number_of_items !== "") {
            $data_attribute .= " data-number_of_items='" . $number_of_items. "'";
        }
		$headings_array = array('h2', 'h3', 'h4', 'h5', 'h6');
		//get correct heading value. If provided heading isn't valid get the default one
		$title_tag = (in_array($title_tag, $headings_array)) ? $title_tag : $args['title_tag'];

        $html = "";
        $margin_between_rows_style = '';

        if ($carousel != "") {
            $carousel_holder_classes = array();

            //roll_over animation
            if (($image_animation !== '') && ($image_animation == 'roll_over')) {
                $carousel_holder_classes[] = 'roll_over';
            }

            if ($show_in_two_rows == 'yes') {
                $carousel_holder_classes[] = 'two_rows';

                $margin_between_rows_style = '';
                if ($margin_between_rows != '') {
                    $valid_margin_between_rows = (strstr($margin_between_rows, 'px', true)) ? $margin_between_rows : $margin_between_rows . 'px';
                    $margin_between_rows_style = 'style="margin-bottom:' . $valid_margin_between_rows . ';"';
                }
            }

            $html .= "<div class='eltd_carousels_holder clearfix " . implode(' ', $carousel_holder_classes). "'><div class='eltd_carousels' " . $data_attribute . "><ul class='slides'>";

            $q = array('post_type' => 'carousels', 'carousels_category' => $carousel, 'orderby' => $orderby, 'order' => $order, 'posts_per_page' => '-1');

            query_posts($q);
            $have_posts = false;

            if (have_posts()) : $post_count = 1;
                $have_posts = true;
                while (have_posts()) : the_post();
					
					$carousel_image_hover_classes = "";
					
                    if (get_post_meta(get_the_ID(), "eltd_carousel-image", true) != "") {
                        $image = get_post_meta(get_the_ID(), "eltd_carousel-image", true);
                    } else {
                        $image = "";
                    }

                    if (($image_animation == '' || $image_animation == 'image_change' || $image_animation == 'roll_over') && get_post_meta(get_the_ID(), "eltd_carousel-hover-image", true) != "") {
                        $hover_image = get_post_meta(get_the_ID(), "eltd_carousel-hover-image", true);
                        $carousel_image_hover_classes .= " has_hover_image";
                    } else {
                        $hover_image = "";
                    }

                    if (get_post_meta(get_the_ID(), "eltd_carousel-item-text", true) != "") {
                        $text = get_post_meta(get_the_ID(), "eltd_carousel-item-text", true);
                    } else {
                        $text = "";
                    }

                    if (get_post_meta(get_the_ID(), "eltd_carousel-item-link", true) != "") {
                        $link = get_post_meta(get_the_ID(), "eltd_carousel-item-link", true);
                    } else {
                        $link = "";
                    }

                    if (get_post_meta(get_the_ID(), "eltd_carousel-item-target", true) != "") {
                        $target = get_post_meta(get_the_ID(), "eltd_carousel-item-target", true);
                    } else {
                        $target = "_self";
                    }

                    $title = get_the_title();

                    //is current item not on even position in array and two rows option is chosen?
                    if ($post_count % 2 !== 0 && $show_in_two_rows == 'yes') {
                        $html .= "<li class='item'>";
                    } elseif ($show_in_two_rows == '') {
                        $html .= "<li class='item'>";
                    }

                    $html .= '<div class="carousel_item_holder" ' . $margin_between_rows_style . '>';
                    $html .= '<div class="carousel_item_holder_inner" '.$item_margin_style_string.'>';

                    if ($link != "") {
                        $html .= "<a href='" . $link . "' target='" . $target . "'>";
                    }

                    if ($image != "") {
                        $html .= "<span class='first_image_holder " . $carousel_image_classes . ' ' .$carousel_image_hover_classes . "'><img src='" . $image . "' alt='" . $title . "'></span>";
                    }

                    if ($hover_image != "") {
                        $html .= "<span class='second_image_holder " . $carousel_image_classes . ' ' .$carousel_image_hover_classes . "'><img src='" . $hover_image . "' alt='" . $title . "'></span>";
                    }

                    if ($link != "") {
                        $html .= "</a>";
                    }

					if ($type == 'title_and_text'){
						$html .= '<div class = "carousel_title_text">';
						$html .= '<' . $title_tag . ' class = "carousel_title">' . esc_html($title) . '</' . $title_tag . '>';
						$html .= '<div class="carousel_separator"></div>';
						if ($text !== ''){
							$html .= '<p class = "carousel_text">' . esc_html($text) . '</p>';
						}
						$html .= '</div>';
					}

                    $html .= '</div>'; //close carousel_item_holder_inner div
                    $html .= '</div>'; //close carousel_item_holder div

                    //is current item on even position in array and two rows option is chosen?
                    if ($post_count % 2 == 0 && $show_in_two_rows == 'yes') {
                        $html .= "</li>";
                    } elseif ($show_in_two_rows == '') {
                        $html .= "</li>";
                    }

                    $post_count++;

                endwhile;

            else:
                $html .= __('Sorry, no posts matched your criteria.', 'eltd_cpt');
            endif;

            wp_reset_query();

            $html .= "</ul>";

            if ($show_navigation != 'no' && $have_posts) {

                $icon_navigation_class = 'arrow_carrot-';
                if (isset($eltd_moose_options['carousel_navigation_arrows_type']) && $eltd_moose_options['carousel_navigation_arrows_type'] != '') {
                    $icon_navigation_class = $eltd_moose_options['carousel_navigation_arrows_type'];
                }

                $direction_nav_classes = eltd_moose_horizontal_slider_icon_classes($icon_navigation_class);

                //generate navigation html
                $html .= '<ul class="caroufredsel-direction-nav">';

                $html .= '<li class="caroufredsel-prev-holder">';

                $html .= '<a id="caroufredsel-prev" class="eltd_carousel_prev caroufredsel-navigation-item caroufredsel-prev" href="javascript: void(0)">';

                $html .= '<span class="'.$direction_nav_classes['left_icon_class'].'"></span>';

                $html .= '</a>';

                $html .= '</li>'; //close li.caroufredsel-prev-holder

                $html .= '<li class="caroufredsel-next-holder">';
                $html .= '<a class="eltd_carousel_next caroufredsel-next caroufredsel-navigation-item" id="caroufredsel-next" href="javascript: void(0)">';

                $html .= '<span class="'.$direction_nav_classes['right_icon_class'].'"></span>';

                $html .= '</a>';

                $html .= '</li>'; //close li.caroufredsel-next-holder

                $html .= '</ul>'; //close ul.caroufredsel-direction-nav
            }
            $html .= "</div></div>";
        }

        return $html;
    }


}