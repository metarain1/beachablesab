<?php
namespace ElatedCPT\CPT\Slider;

use ElatedCPT\Lib;

/**
 * Class SliderRegister
 * @package ElatedCPT\CPT\Slider
 */
class SliderRegister implements Lib\PostTypeInterface {
    /**
     * @var string
     */
    private $base;

    public function __construct() {
        $this->base = 'slides';
        $this->taxBase = 'slides_category';
    }

    /**
     * @return string
     */
    public function getBase() {
        return $this->base;
    }

    /**
     * Registers custom post type with WordPress
     */
    public function register() {
        $this->registerPostType();
        $this->registerTax();
    }

    /**
     * Registers custom post type with WordPress
     */
    private function registerPostType() {
        global $eltdFramework;

        $menuPosition = 5;
        $menuIcon = 'dashicons-admin-post';

        if(eltd_moose_cpt_theme_installed()) {
            $menuPosition = $eltdFramework->getSkin()->getMenuItemPosition('slider');
            $menuIcon = $eltdFramework->getSkin()->getMenuIcon('slider');
        }

        register_post_type($this->base,
            array(
                'labels' 		=> array(
                    'name' 				=> __('Elated Slider','eltd_cpt' ),
                    'menu_name'	=> __('Elated Slider','eltd_cpt' ),
                    'all_items'	=> __('Slides','eltd_cpt' ),
                    'add_new' =>  __('Add New Slide','eltd_cpt'),
                    'singular_name' 	=> __('Slide','eltd_cpt' ),
                    'add_item'			=> __('New Slide','eltd_cpt'),
                    'add_new_item' 		=> __('Add New Slide','eltd_cpt'),
                    'edit_item' 		=> __('Edit Slide','eltd_cpt')
                ),
                'public'		=>	false,
                'show_in_menu'	=>	true,
                'rewrite' 		=> 	array('slug' => 'slides'),
                'menu_position' => 	$menuPosition,
                'show_ui'		=>	true,
                'has_archive'	=>	false,
                'hierarchical'	=>	false,
                'supports'		=>	array('title', 'thumbnail', 'page-attributes'),
                'menu_icon'  =>  $menuIcon
            )
        );
    }

    /**
     * Registers custom taxonomy with WordPress
     */
    private function registerTax() {
        $labels = array(
            'name' => __( 'Sliders', 'taxonomy general name' ),
            'singular_name' => __( 'Slider', 'taxonomy singular name' ),
            'search_items' =>  __( 'Search Sliders','eltd_cpt' ),
            'all_items' => __( 'All Sliders','eltd_cpt' ),
            'parent_item' => __( 'Parent Slider','eltd_cpt' ),
            'parent_item_colon' => __( 'Parent Slider:','eltd_cpt' ),
            'edit_item' => __( 'Edit Slider','eltd_cpt' ),
            'update_item' => __( 'Update Slider','eltd_cpt' ),
            'add_new_item' => __( 'Add New Slider','eltd_cpt' ),
            'new_item_name' => __( 'New Slider Name','eltd_cpt' ),
            'menu_name' => __( 'Sliders','eltd_cpt' ),
        );

        register_taxonomy($this->taxBase, array($this->base), array(
            'hierarchical' => true,
            'labels' => $labels,
            'show_ui' => true,
            'query_var' => true,
            'show_admin_column' => true,
            'rewrite' => array( 'slug' => 'slides-category' ),
        ));
    }
}