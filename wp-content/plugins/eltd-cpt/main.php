<?php
/*
Plugin Name: Elated CPT
Description: Plugin that adds all post types needed by our theme
Author: Elated Themes
Version: 1.0
*/

require_once 'load.php';

use ElatedCPT\CPT;
use ElatedCPT\Lib;

add_action('after_setup_theme', array(CPT\PostTypesRegister::getInstance(), 'register'));

Lib\ShortcodeLoader::getInstance()->load();

if(!function_exists('eltd_moose_cpt_activation')) {
    /**
     * Triggers when plugin is activated. It calls flush_rewrite_rules
     * and defines eltd_cpt_on_activate action
     */
    function eltd_moose_cpt_activation() {
        do_action('eltd_cpt_on_activate');

        ElatedCPT\CPT\PostTypesRegister::getInstance()->register();
        flush_rewrite_rules();
    }

    register_activation_hook(__FILE__, 'eltd_moose_cpt_activation');
}

if(!function_exists('eltd_moose_cpt_text_domain')) {
    /**
     * Loads plugin text domain so it can be used in translation
     */
    function eltd_moose_cpt_text_domain() {
        load_plugin_textdomain('eltd_cpt', false, ELATED_CPT_REL_PATH.'/languages');
    }

    add_action('plugins_loaded', 'eltd_moose_cpt_text_domain');
}