<?php
namespace ElatedCPT\CPT\Portfolio;

use ElatedCPT\Lib\PostTypeInterface;

/**
 * Class PortfolioRegister
 * @package ElatedCPT\CPT\Portfolio
 */
class PortfolioRegister implements PostTypeInterface {
    /**
     * @var string
     */
    private $base;

    public function __construct() {
        $this->base = 'portfolio_page';
        $this->taxBase = 'portfolio_category';

        add_filter('single_template', array($this, 'registerSingleTemplate'));
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
        $this->registerTagTax();
    }

    /**
     * Registers portfolio single template if one does'nt exists in theme.
     * Hooked to single_template filter
     * @param $single string current template
     * @return string string changed template
     */
    public function registerSingleTemplate($single) {
        global $post;

        if($post->post_type == $this->base) {
            if(!file_exists(get_template_directory().'/single-portfolio_page.php')) {
                return ELATED_CPT_CPT_PATH.'/portfolio/templates/single-'.$this->base.'.php';
            }
        }

        return $single;
    }

    /**
     * Registers custom post type with WordPress
     */
    private function registerPostType() {
        global $eltdFramework, $eltd_moose_options;

        $menuPosition = 5;
        $menuIcon = 'dashicons-admin-post';
        $slug = 'portfolio_page';

        if(eltd_moose_cpt_theme_installed()) {
            $menuPosition = $eltdFramework->getSkin()->getMenuItemPosition('portfolio');
            $menuIcon = $eltdFramework->getSkin()->getMenuIcon('portfolio');

            if(isset($eltd_moose_options['portfolio_single_slug'])) {
                if($eltd_moose_options['portfolio_single_slug'] != ""){
                    $slug = $eltd_moose_options['portfolio_single_slug'];
                }
            }
        }

        register_post_type( 'portfolio_page',
            array(
                'labels' => array(
                    'name' => __( 'Portfolio','eltd_cpt' ),
                    'singular_name' => __( 'Portfolio Item','eltd_cpt' ),
                    'add_item' => __('New Portfolio Item','eltd_cpt'),
                    'add_new_item' => __('Add New Portfolio Item','eltd_cpt'),
                    'edit_item' => __('Edit Portfolio Item','eltd_cpt')
                ),
                'public' => true,
                'has_archive' => true,
                'rewrite' => array('slug' => $slug),
                'menu_position' => $menuPosition,
                'show_ui' => true,
                'supports' => array('author', 'title', 'editor', 'thumbnail', 'excerpt', 'page-attributes', 'comments'),
                'menu_icon'  =>  $menuIcon
            )
        );
    }

    /**
     * Registers custom taxonomy with WordPress
     */
    private function registerTax() {
        $labels = array(
            'name' => __( 'Portfolio Categories', 'taxonomy general name' ),
            'singular_name' => __( 'Portfolio Category', 'taxonomy singular name' ),
            'search_items' =>  __( 'Search Portfolio Categories','eltd_cpt' ),
            'all_items' => __( 'All Portfolio Categories','eltd_cpt' ),
            'parent_item' => __( 'Parent Portfolio Category','eltd_cpt' ),
            'parent_item_colon' => __( 'Parent Portfolio Category:','eltd_cpt' ),
            'edit_item' => __( 'Edit Portfolio Category','eltd_cpt' ),
            'update_item' => __( 'Update Portfolio Category','eltd_cpt' ),
            'add_new_item' => __( 'Add New Portfolio Category','eltd_cpt' ),
            'new_item_name' => __( 'New Portfolio Category Name','eltd_cpt' ),
            'menu_name' => __( 'Portfolio Categories','eltd_cpt' ),
        );

        register_taxonomy($this->taxBase, array($this->base), array(
            'hierarchical' => true,
            'labels' => $labels,
            'show_ui' => true,
            'query_var' => true,
            'rewrite' => array( 'slug' => 'portfolio-category' ),
        ));
    }

    /**
     * Registers custom tag taxonomy with WordPress
     */
    private function registerTagTax() {
        $labels = array(
            'name' => __( 'Portfolio Tags', 'taxonomy general name' ),
            'singular_name' => __( 'Portfolio Tag', 'taxonomy singular name' ),
            'search_items' =>  __( 'Search Portfolio Tags','eltd_cpt' ),
            'all_items' => __( 'All Portfolio Tags','eltd_cpt' ),
            'parent_item' => __( 'Parent Portfolio Tag','eltd_cpt' ),
            'parent_item_colon' => __( 'Parent Portfolio Tags:','eltd_cpt' ),
            'edit_item' => __( 'Edit Portfolio Tag','eltd_cpt' ),
            'update_item' => __( 'Update Portfolio Tag','eltd_cpt' ),
            'add_new_item' => __( 'Add New Portfolio Tag','eltd_cpt' ),
            'new_item_name' => __( 'New Portfolio Tag Name','eltd_cpt' ),
            'menu_name' => __( 'Portfolio Tags','eltd_cpt' ),
        );

        register_taxonomy('portfolio_tag',array($this->base), array(
            'hierarchical' => false,
            'labels' => $labels,
            'show_ui' => true,
            'query_var' => true,
            'rewrite' => array( 'slug' => 'portfolio-tag' ),
        ));
    }
}