<?php
/**
 * Created by PhpStorm.
 * User: korisnik
 * Date: 30/3/2015
 * Time: 11:25 AM
 */

namespace ElatedCPT\CPT\MasonryGallery;

use ElatedCPT\Lib;

/**
 * Class MasonryGalleryRegister
 * @package ElatedCPT\CPT\MasonryGallery
 */
class MasonryGalleryRegister implements Lib\PostTypeInterface  {
    /**
     * @var string
     */
    private $base;

    public function __construct() {
        $this->base = 'masonry_gallery';
        $this->taxBase = 'masonry_gallery_category';
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
			$menuPosition = $eltdFramework->getSkin()->getMenuItemPosition('masonry_gallery');
			$menuIcon = $eltdFramework->getSkin()->getMenuIcon('masonry_gallery');
		}

        register_post_type($this->base,
            array(
                'labels' 		=> array(
                    'name' 				=> __('Masonry Gallery','eltd_cpt' ),
                    'all_items'			=> __('Masonry Gallery Items','eltd_cpt'),
                    'singular_name' 	=> __('Masonry Gallery Item','eltd_cpt' ),
                    'add_item'			=> __('New Masonry Gallery Item','eltd_cpt'),
                    'add_new_item' 		=> __('Add New Masonry Gallery Item','eltd_cpt'),
                    'edit_item' 		=> __('Edit Masonry Gallery Item','eltd_cpt')
                ),
                'public'		=>	false,
                'show_in_menu'	=>	true,
                'rewrite' 		=> 	array('slug' => 'masonry_gallery'),
                'menu_position' => 	$menuPosition,
                'menu_icon' 	=> 	$menuIcon,
                'show_ui'		=>	true,
                'has_archive'	=>	false,
                'hierarchical'	=>	false,
                'supports'		=>	array('title', 'thumbnail')
            )
        );
    }

    /**
     * Registers custom taxonomy with WordPress
     */
    private function registerTax() {
        $labels = array(
            'name' => __( 'Masonry Gallery Categories', 'taxonomy general name' ),
            'singular_name' => __( 'Masonry Gallery Category', 'taxonomy singular name' ),
            'search_items' =>  __( 'Search Masonry Gallery Categories','eltd_cpt' ),
            'all_items' => __( 'All Masonry Gallery Categories','eltd_cpt' ),
            'parent_item' => __( 'Parent Masonry Gallery Category','eltd_cpt' ),
            'parent_item_colon' => __( 'Parent Masonry Gallery Category:','eltd_cpt' ),
            'edit_item' => __( 'Edit Masonry Gallery Category','eltd_cpt' ),
            'update_item' => __( 'Update Masonry Gallery Category','eltd_cpt' ),
            'add_new_item' => __( 'Add New Masonry Gallery Category','eltd_cpt' ),
            'new_item_name' => __( 'New Masonry Gallery Category Name','eltd_cpt' ),
            'menu_name' => __( 'Masonry Gallery Categories','eltd_cpt' ),
        );

        register_taxonomy($this->taxBase, array($this->base), array(
            'hierarchical' => true,
            'labels' => $labels,
            'show_ui' => true,
            'query_var' => true,
            'show_admin_column' => true,
            'rewrite' => array( 'slug' => 'masonry-gallery-category' ),
        ));
    }
}