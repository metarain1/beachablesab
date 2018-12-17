<?php
namespace ElatedCPT\CPT\Carousels;

use ElatedCPT\Lib;

/**
 * Class CarouselRegister
 * @package ElatedCPT\CPT\Carousels
 */
class CarouselRegister implements Lib\PostTypeInterface {
    /**
     * @var string
     */
    private $base;
    /**
     * @var string
     */
    private $taxBase;

    public function __construct() {
        $this->base = 'carousels';
        $this->taxBase = 'carousels_category';
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
            $menuPosition = $eltdFramework->getSkin()->getMenuItemPosition('carousel');
            $menuIcon = $eltdFramework->getSkin()->getMenuIcon('carousel');
        }

        register_post_type($this->base,
            array(
                'labels'    => array(
                    'name'        => __('Elated Carousel','eltd_cpt' ),
                    'menu_name' => __('Elated Carousel','eltd_cpt' ),
                    'all_items' => __('Carousel Items','eltd_cpt' ),
                    'add_new' =>  __('Add New Carousel Item','eltd_cpt'),
                    'singular_name'   => __('Carousel Item','eltd_cpt' ),
                    'add_item'      => __('New Carousel Item','eltd_cpt'),
                    'add_new_item'    => __('Add New Carousel Item','eltd_cpt'),
                    'edit_item'     => __('Edit Carousel Item','eltd_cpt')
                ),
                'public'    =>  false,
                'show_in_menu'  =>  true,
                'rewrite'     =>  array('slug' => 'carousels'),
                'menu_position' =>  $menuPosition,
                'show_ui'   =>  true,
                'has_archive' =>  false,
                'hierarchical'  =>  false,
                'supports'    =>  array('title'),
                'menu_icon'  =>  $menuIcon
            )
        );
    }

    /**
     * Registers custom taxonomy with WordPress
     */
    private function registerTax() {
        $labels = array(
            'name' => __( 'Carousels', 'taxonomy general name' ),
            'singular_name' => __( 'Carousel', 'taxonomy singular name' ),
            'search_items' =>  __( 'Search Carousels','eltd_cpt' ),
            'all_items' => __( 'All Carousels','eltd_cpt' ),
            'parent_item' => __( 'Parent Carousel','eltd_cpt' ),
            'parent_item_colon' => __( 'Parent Carousel:','eltd_cpt' ),
            'edit_item' => __( 'Edit Carousel','eltd_cpt' ),
            'update_item' => __( 'Update Carousel','eltd_cpt' ),
            'add_new_item' => __( 'Add New Carousel','eltd_cpt' ),
            'new_item_name' => __( 'New Carousel Name','eltd_cpt' ),
            'menu_name' => __( 'Carousels','eltd_cpt' ),
        );

        register_taxonomy($this->taxBase, array($this->base), array(
            'hierarchical' => true,
            'labels' => $labels,
            'show_ui' => true,
            'query_var' => true,
            'show_admin_column' => true,
            'rewrite' => array( 'slug' => 'carousels-category' ),
        ));
    }

}