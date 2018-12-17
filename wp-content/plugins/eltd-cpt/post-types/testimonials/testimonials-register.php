<?php
namespace ElatedCPT\CPT\Testimonials;

use ElatedCPT\Lib;


/**
 * Class TestimonialsRegister
 * @package ElatedCPT\CPT\Testimonials
 */
class TestimonialsRegister implements Lib\PostTypeInterface {
    /**
     * @var string
     */
    private $base;

    public function __construct() {
        $this->base = 'testimonials';
        $this->taxBase = 'testimonials_category';
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
     * Regsiters custom post type with WordPress
     */
    private function registerPostType() {
        global $eltdFramework;

        $menuPosition = 5;
        $menuIcon = 'dashicons-admin-post';

        if(eltd_moose_cpt_theme_installed()) {
            $menuPosition = $eltdFramework->getSkin()->getMenuItemPosition('testimonial');
            $menuIcon = $eltdFramework->getSkin()->getMenuIcon('testimonial');
        }

        register_post_type('testimonials',
            array(
                'labels' 		=> array(
                    'name' 				=> __('Testimonials','eltd_cpt' ),
                    'singular_name' 	=> __('Testimonial','eltd_cpt' ),
                    'add_item'			=> __('New Testimonial','eltd_cpt'),
                    'add_new_item' 		=> __('Add New Testimonial','eltd_cpt'),
                    'edit_item' 		=> __('Edit Testimonial','eltd_cpt')
                ),
                'public'		=>	false,
                'show_in_menu'	=>	true,
                'rewrite' 		=> 	array('slug' => 'testimonials'),
                'menu_position' => 	$menuPosition,
                'show_ui'		=>	true,
                'has_archive'	=>	false,
                'hierarchical'	=>	false,
                'supports'		=>	array('title', 'thumbnail'),
                'menu_icon'  =>  $menuIcon
            )
        );
    }

    /**
     * Registers custom taxonomy with WordPress
     */
    private function registerTax() {
        $labels = array(
            'name' => __( 'Testimonials Categories', 'taxonomy general name' ),
            'singular_name' => __( 'Testimonial Category', 'taxonomy singular name' ),
            'search_items' =>  __( 'Search Testimonials Categories','eltd_cpt' ),
            'all_items' => __( 'All Testimonials Categories','eltd_cpt' ),
            'parent_item' => __( 'Parent Testimonial Category','eltd_cpt' ),
            'parent_item_colon' => __( 'Parent Testimonial Category:','eltd_cpt' ),
            'edit_item' => __( 'Edit Testimonials Category','eltd_cpt' ),
            'update_item' => __( 'Update Testimonials Category','eltd_cpt' ),
            'add_new_item' => __( 'Add New Testimonials Category','eltd_cpt' ),
            'new_item_name' => __( 'New Testimonials Category Name','eltd_cpt' ),
            'menu_name' => __( 'Testimonials Categories','eltd_cpt' ),
        );

        register_taxonomy($this->taxBase, array($this->base), array(
            'hierarchical' => true,
            'labels' => $labels,
            'show_ui' => true,
            'query_var' => true,
            'show_admin_column' => true,
            'rewrite' => array( 'slug' => 'testimonials-category' ),
        ));
    }

}