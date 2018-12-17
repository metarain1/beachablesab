<?php
/**
 * Created by PhpStorm.
 * User: korisnik
 * Date: 30/3/2015
 * Time: 12:26 PM
 */

namespace ElatedCPT\CPT\MasonryGallery\Shortcodes;


use ElatedCPT\Lib\ShortcodeInterface;

/**
 * Class MasonryGallery
 * @package ElatedCPT\CPT\MasonryGallery\Shortcodes
 */
class MasonryGallery implements ShortcodeInterface {
    /**
     * @var string
     */
    private $base;

    public function __construct() {
        $this->base = 'no_masonry_gallery';

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
     * @see vc_map
     */
    public function vcMap() {
        if(function_exists('vc_map')) {
            vc_map( array(
                "name" => "Masonry Gallery",
                "base" => "no_masonry_gallery",
                "category" => 'by Elated',
                "icon" => "icon-wpb-masonry-gallery extended-custom-icon",
                "allowed_container_element" => 'vc_row',
                "params" => array(
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
                        "type" => "textfield",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Number",
                        "param_name" => "number",
                        "value" => "",
                        "description" => "Number of Masonry Gallery Items"
                    ),
                    array(
                        "type" => "dropdown",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Number of columns",
                        "param_name" => "column_number",
                        "value" => array(
                            "4" => "4",
                            "3" => "3"
                        ),
						"save_always" => true,
                        "description" => ""
                    ),
                    array(
                        "type" => "dropdown",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Order",
                        "param_name" => "order",
                        "value" => array(
                            "DESC" => "DESC",
                            "ASC" => "ASC"
                        ),
						"save_always" => true,
                        "description" => ""
                    ),
					array(
                        "type" => "textfield",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Parallax Item Speed",
                        "param_name" => "parallax_item_speed",
                        "value" => "",
                        "description" => 'This option only takes effect on portfolio items on which "Set Masonry Item in Parallax" is set to "Yes", default value is 0.3'
                    ),
					array(
                        "type" => "textfield",
                        "holder" => "div",
                        "class" => "",
                        "heading" => "Parallax Item Offset",
                        "param_name" => "parallax_item_offset",
                        "value" => "",
                        "description" => 'This option only takes effect on portfolio items on which "Set Masonry Item in Parallax" is set to "Yes", default value is 0'
                    ),
                )
            ));
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
		global $wp_query;
        $default_args = array(
            'category' => '',
            'number' => -1,
			'column_number' => 4,
            'order' => 'DESC',
			'parallax_item_speed' => '0.3',
			'parallax_item_offset' => '0',
        );

        extract(shortcode_atts($default_args, $atts));
		
		$parallax_item_speed = esc_attr($parallax_item_speed);
		$parallax_item_offset = esc_attr($parallax_item_offset);
		
        $html = '';

        /* Query for items */
        $query_args = array(
            'post_type' => 'masonry_gallery',
            'orderby' => 'date',
            'order' => $order,
            'posts_per_page' => $number
        );

        if ($category != "") {
            $query_args['masonry_gallery_category'] = $category;
        }
        $query = new $wp_query( $query_args );
		
		switch ($number) {
			case 1:
				$item_number_class = 'one_column';
			break;
			case 2:
				$item_number_class = 'two_columns';
			break;
			case 3:
				$item_number_class = 'three_columns';
			break;
			default:
				$item_number_class = '';
			break;	
		}

		if ( $column_number == 3 ) {
			$column_class = 'masonry_three_columns';
		} else {
			$column_class = '';
		}

        $html .= '<div class="masonry_gallery_holder ' . $item_number_class . ' ' . $column_class . '" data-parallax_item_speed="'.$parallax_item_speed.'" data-parallax_item_offset="'.$parallax_item_offset.'"><div class="grid-sizer"></div>';

        if ($query->have_posts()) :
            while ( $query->have_posts() ) : $query->the_post();

                $item_type = '';
                $item_class = '';
                $item_subtitle = '';
                $item_text = '';
                $item_link = '';
                $item_button_label = '';
                $item_icon = '';
                $item_link_target = '_self';
				$item_parallax_class = "";
				$item_align = "center";

                if (get_post_meta(get_the_ID(), 'eltd_masonry_gallery_item_type', true) !== '') {
                    $item_type = get_post_meta(get_the_ID(), 'eltd_masonry_gallery_item_type', true);
                }
                if (get_post_meta(get_the_ID(), 'eltd_masonry_gallery_item_size', true) !== '') {
                    $item_class = get_post_meta(get_the_ID(), 'eltd_masonry_gallery_item_size', true);
                }
                if (get_post_meta(get_the_ID(), 'eltd_masonry_gallery_item_subtitle', true) !== '') {
                    $item_subtitle = get_post_meta(get_the_ID(), 'eltd_masonry_gallery_item_subtitle', true);
                }
                if (get_post_meta(get_the_ID(), 'eltd_masonry_gallery_item_text', true) !== '') {
                    $item_text = get_post_meta(get_the_ID(), 'eltd_masonry_gallery_item_text', true);
                }
                if (get_post_meta(get_the_ID(), 'eltd_masonry_gallery_item_link', true) !== '') {
                    $item_link = get_post_meta(get_the_ID(), 'eltd_masonry_gallery_item_link', true);
                }
                if (get_post_meta(get_the_ID(), 'eltd_masonry_gallery_item_link_target', true) !== '') {
                    $item_link_target = get_post_meta(get_the_ID(), 'eltd_masonry_gallery_item_link_target', true);
                }
				$masonry_parallax = get_post_meta(get_the_ID(), "eltd_masonry_item_parallax", true);
				$subtitle_separator = get_post_meta(get_the_ID(), "eltd_masonry_item_subtitle_separator", true);
				
				if($masonry_parallax == "yes"){
					$item_parallax_class = " parallax_item";
				}

                switch ($item_class) {
                    case 'square_big':
                        $gallery_thumb_size = 'elated-moose-portfolio-masonry-large';
						if (isset($eltd_moose_options['masonry_gallery_square_big_text_align']) && $eltd_moose_options['masonry_gallery_square_big_text_align'] !== ''){
							$item_align = $eltd_moose_options['masonry_gallery_square_big_text_align'];
						}
                        break;
                    case 'square_small':
                        $gallery_thumb_size = 'elated-moose-portfolio-square';
                        if (isset($eltd_moose_options['masonry_gallery_square_small_text_align']) && $eltd_moose_options['masonry_gallery_square_small_text_align'] !== ''){
							$item_align = $eltd_moose_options['masonry_gallery_square_small_text_align'];
						}
                        break;
                    case 'rectangle_portrait':
                        $gallery_thumb_size = 'elated-moose-portfolio-masonry-tall';
                        if (isset($eltd_moose_options['masonry_gallery_rectangle_portrait_text_align']) && $eltd_moose_options['masonry_gallery_rectangle_portrait_text_align'] !== ''){
							$item_align = $eltd_moose_options['masonry_gallery_rectangle_portrait_text_align'];
						}
                        break;
                    case 'rectangle_landscape':
                        $gallery_thumb_size = 'elated-moose-portfolio-masonry-wide';
                        if (isset($eltd_moose_options['masonry_gallery_rectangle_landscape_text_align']) && $eltd_moose_options['masonry_gallery_rectangle_landscape_text_align'] !== ''){
							$item_align = $eltd_moose_options['masonry_gallery_rectangle_landscape_text_align'];
						}
                        break;
                    default:
                        $gallery_thumb_size = 'elated-moose-portfolio-square';
                        if (isset($eltd_moose_options['masonry_gallery_square_small_text_align']) && $eltd_moose_options['masonry_gallery_square_small_text_align'] !== ''){
							$item_align = $eltd_moose_options['masonry_gallery_square_small_text_align'];
						}
                        break;
                }

                $html .= '<article class="masonry_gallery_item ' . esc_attr($item_class) . ' ' .esc_attr($item_type). ' '. esc_attr($item_parallax_class) .'">';

                switch($item_type) {
                    case 'with_button':

                        //With Button Type
                        if (get_post_meta(get_the_ID(), 'eltd_masonry_gallery_button_label', true) !== '') {
                            $item_button_label = get_post_meta(get_the_ID(), 'eltd_masonry_gallery_button_label', true);
                        }

                        if (has_post_thumbnail()) {
                            $html .= '<div class = "masonry_gallery_image_holder">';
                            $html .= get_the_post_thumbnail(get_the_ID(),$gallery_thumb_size);
                            $html .= '</div>';
                        }

                        $html .= '<div class="masonry_gallery_item_outer">';

                        $html .= '<div class="masonry_gallery_item_inner"><div class="masonry_gallery_item_content">';

						if ($item_subtitle !== ''){
							$html .= '<div class="masonry_gallery_item_subtitle">';
							if ($subtitle_separator == 'yes'){
								$html .= do_shortcode('[vc_text_separator text_in_box="no" title="' . $item_subtitle . '" text_position="' . $item_align . '" ]');
							}
							else{
								$html .= '<span>' . $item_subtitle . '</span>';
							}
							$html .= '</div>';
						}
                        $html .= '<h3>' . get_the_title() . '</h3>';
                        $html .= '<p class="masonry_gallery_item_text">' . esc_html($item_text) . '</p>';
						
						//Get icon pack
						$button_icon_pack = '';
						$button_icon = '';
						$button_array = array();
						
                        if (get_post_meta(get_the_ID(), "eltd_masonry_gallery_item_with_icon_icon_pack", true) != ''){

                            $button_icon_pack = get_post_meta(get_the_ID(), "eltd_masonry_gallery_item_with_icon_icon_pack", true);

                            $icon_collection_obj = $eltdIconCollections->getIconCollection($button_icon_pack);

                            //Get icon pack param
                            $item_icon_param = $icon_collection_obj->param;

                            //Get icon
                            if (get_post_meta(get_the_ID(), "eltd_masonry_gallery_item_with_icon_".$item_icon_param, true) !== '') {
                                $button_icon = get_post_meta(get_the_ID(), "eltd_masonry_gallery_item_with_icon_".$item_icon_param, true);
                            }
							
							if ($button_icon_pack !== '') {
								$button_array[] = "icon_pack='" . $button_icon_pack . "'";
							}
							if ($item_icon_param) {
									$button_array[] = $item_icon_param . "='" . $button_icon . "'";
							}							
                        }
                        if ($item_link !== '' && $item_button_label !== '') {
							$button_array[] = "text='".$item_button_label."'";
							$button_array[] = "link='".$item_link."'";							
							$html .= do_shortcode('[no_button ' . implode(' ', $button_array) . ']');
                            //$html .= '<a href="'.esc_url($item_link).'" class="qbutton masonry_gallery_item_button" target="'.esc_attr($item_link_target).'">'.$item_button_label.'</a>';
                        }

                        $html .= '</div></div>';

                        $html .= '</div>';

                        break;

                    case 'with_icon':

                        //With Icon Type
                        if ($item_link !== '') {
                            $html .= '<a href="'.esc_url($item_link).'" target="'.esc_attr($item_link_target).'">';
                        }

                        if (has_post_thumbnail()) {
                            $html .= '<div class = "masonry_gallery_image_holder">';
                            $html .= get_the_post_thumbnail(get_the_ID(),$gallery_thumb_size);
                            $html .= '</div>';
                        }

                        $html .= '<div class="masonry_gallery_item_outer">';

                        $html .= '<div class="masonry_gallery_item_inner">';

                        $html .= '<div class="masonry_gallery_item_content">';

                        //Get icon pack
                        if (get_post_meta(get_the_ID(), "eltd_masonry_gallery_item_with_icon_icon_pack", true) != ''){

                            $item_icon_pack = get_post_meta(get_the_ID(), "eltd_masonry_gallery_item_with_icon_icon_pack", true);

                            $icon_collection_obj = $eltdIconCollections->getIconCollection($item_icon_pack);

                            //Get icon pack param
                            $item_icon_param = $icon_collection_obj->param;

                            //Get icon
                            if (get_post_meta(get_the_ID(), "eltd_masonry_gallery_item_with_icon_".$item_icon_param, true) !== '') {
                                $item_icon = get_post_meta(get_the_ID(), "eltd_masonry_gallery_item_with_icon_".$item_icon_param, true);
                            }

                            //Render icon
                            if (method_exists($icon_collection_obj, 'render') && $item_icon !== '') {
                                $html .= '<div class="masonry_gallery_item_icon">'.$icon_collection_obj->render($item_icon).'</div>';
                            }

                        }

						if ($item_subtitle !== ''){
							$html .= '<div class="masonry_gallery_item_subtitle">';
							if ($subtitle_separator == 'yes'){
								$html .= do_shortcode('[vc_text_separator text_in_box="no" title="' . $item_subtitle . '" text_position="' . $item_align . '" ]');
							}
							else{
								$html .= '<span>' . $item_subtitle . '</span>';
							}
							$html .= '</div>';
						}

                        $html .= '<h3>' . get_the_title() . '</h3>';
                        $html .= '<p class="masonry_gallery_item_text">' . esc_html($item_text) . '</p>';


                        $html .= '</div></div>';

                        $html .= '</div>';

                        if ($item_link !== '') {
                            $html .= '</a>';
                        }
                        break;

                    case 'standard':

                        //Only image
                        if ($item_link !== '') {
                            $html .= '<a href="'.esc_url($item_link).'" target="'.esc_attr($item_link_target).'">';
                        }

                        

                        if (has_post_thumbnail()) {
                            $html .= '<div class = "masonry_gallery_image_holder">';
                            $html .= get_the_post_thumbnail(get_the_ID(),$gallery_thumb_size);
                            $html .= '</div>';
                        }


                        $html .= '<div class="masonry_gallery_item_outer">';

                        $html .= '<div class="masonry_gallery_item_inner">';

                        $html .= '<div class="masonry_gallery_item_content">';

						if ($item_subtitle !== ''){
							$html .= '<div class="masonry_gallery_item_subtitle">';
							if ($subtitle_separator == 'yes'){
								$html .= do_shortcode('[vc_text_separator text_in_box="no" title="' . $item_subtitle . '" text_position="' . $item_align . '" ]');
							}
							else{
								$html .= '<span>' . $item_subtitle . '</span>';
							}
							$html .= '</div>';
						}

                        $html .= '<h3>' . get_the_title() . '</h3>';
						$html .= '<p class="masonry_gallery_item_text">' . esc_html($item_text) . '</p>';

                        $html .= '</div></div>';

                        $html .= '</div>';

                        if ($item_link !== '') {
                            $html .= '</a>';
                        }

                 

                        break;
                }

                $html .= '</article>';

            endwhile;
        else:
            $html .= __('Sorry, no posts matched your criteria.', 'eltd_cpt');
        endif;

        $html .= '</div>';

        return $html;
    }


}