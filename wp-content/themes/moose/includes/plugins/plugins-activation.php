<?php
/**
 * Include the TGM_Plugin_Activation class.
 */
require_once dirname( __FILE__ ) . '/class-tgm-plugin-activation.php';
add_action( 'tgmpa_register', 'eltd_register_theme_included_plugins' );

if(!function_exists('eltd_register_theme_included_plugins')) {

	/**
	 * Registers theme required and optional plugins. Hooks to tgmpa_register hook
	 */

	function eltd_register_theme_included_plugins()	{

		$plugins = array(
			array(
	            'name'			=> 'Elated CPT', // The plugin name
	            'slug'			=> 'eltd-cpt', // The plugin slug (typically the folder name)
	            'source'			=> get_template_directory() . '/plugins/eltd-cpt.zip', // The plugin source
	            'required'			=> true, // If false, the plugin is only 'recommended' instead of required
	            'version'			=> '1.0', // E.g. 1.0.0. If set, the active plugin must be this version or higher,
	            // otherwise a notice is presented
	            'force_activation'		=> false, // If true, plugin is activated upon theme activation and cannot be deactivated until theme switch
	            'force_deactivation'	=> false, // If true, plugin is deactivated upon theme switch, useful for theme-specific plugins
	            'external_url'		=> '', // If set, overrides default API URL and points to an external URL
	        ),
			array(
				'name'					=>  esc_html__('WPBakery Page Builder', 'eltd'),
				'slug'					=> 'js_composer',
				'source'				=> get_template_directory() . '/plugins/js_composer.zip', // The plugin source
				'required'				=> true,
				'version'				=> '5.5.2',
				'force_activation'		=> false,
				'force_deactivation'	=> false,
				'external_url'			=> '',
			),
			array(
				'name'     				=> esc_html__('LayerSlider WP', 'eltd'),
				'slug'     				=> 'LayerSlider',
				'source'   				=> get_template_directory() . '/plugins/layersliderwp-6.7.6.installable.zip',
				'required' 				=> true,
				'version' 				=> '',
				'force_activation' 		=> false,
				'force_deactivation' 	=> false,
				'external_url' 			=> ''
			),
			array(
				'name'         			=> esc_html__('Envato Market', 'eltd'),
				'slug'         			=> 'envato-market', // The plugin slug (typically the folder name).
				'source'       			=> get_template_directory() . '/plugins/envato-market.zip', // The plugin source.
				'required'     			=> true,
				'force_activation' 		=> false,
				'force_deactivation' 	=> false,
				'external_url' 			=> '',
			),
			 array(
	            'name'			=> 'Elated Twitter Feed', // The plugin name
	            'slug'			=> 'eltd-twitter-feed', // The plugin slug (typically the folder name)
	            'source'			=> get_template_directory() . '/plugins/eltd-twitter-feed.zip', // The plugin source
	            'required'			=> false, // If false, the plugin is only 'recommended' instead of required
	            'version'			=> '1.0', // E.g. 1.0.0. If set, the active plugin must be this version or higher,
	            // otherwise a notice is presented
	            'force_activation'		=> false, // If true, plugin is activated upon theme activation and cannot be deactivated until theme switch
	            'force_deactivation'	=> false, // If true, plugin is deactivated upon theme switch, useful for theme-specific plugins
	            'external_url'		=> '', // If set, overrides default API URL and points to an external URL
	        ),
			array(
		        'name'         			=> esc_html__( 'WooCommerce', 'eltd' ),
		        'slug'         			=> 'woocommerce',
		        'external_url' 			=> 'https://wordpress.org/plugins/woocommerce/',
		        'required'     			=> false
	        ),
	        array(
		        'name'         			=> esc_html__( 'Contact Form 7', 'eltd' ),
		        'slug'         			=> 'contact-form-7',
		        'external_url' 			=> 'https://wordpress.org/plugins/contact-form-7/',
		        'required'     			=> false
	        )
		);


		$config = array(
			'domain'			=> 'eltd',
			'default_path'		=> '',
			'parent_slug'		=> 'themes.php',
			'capability'		=> 'edit_theme_options',
			'menu'				=> 'install-required-plugins',
			'has_notices'		=> true,
			'is_automatic'		=> false,
			'message'			=> '',
			'strings'			=> array(
				'page_title'						=> esc_html__('Install Required Plugins', 'eltd'),
				'menu_title'						=> esc_html__('Install Plugins', 'eltd'),
				'installing'						=> esc_html__('Installing Plugin: %s', 'eltd'),
				'oops'								=> esc_html__('Something went wrong with the plugin API.', 'eltd'),
				'notice_can_install_required'		=> _n_noop('This theme requires the following plugin: %1$s.', 'This theme requires the following plugins: %1$s.', 'eltd'),
				'notice_can_install_recommended'	=> _n_noop('This theme recommends the following plugin: %1$s.', 'This theme recommends the following plugins: %1$s.', 'eltd'),
				'notice_cannot_install'				=> _n_noop('Sorry, but you do not have the correct permissions to install the %s plugin. Contact the administrator of this site for help on getting the plugin installed.', 'Sorry, but you do not have the correct permissions to install the %s plugins. Contact the administrator of this site for help on getting the plugins installed.', 'eltd'),
				'notice_can_activate_required'		=> _n_noop('The following required plugin is currently inactive: %1$s.', 'The following required plugins are currently inactive: %1$s.', 'eltd'),
				'notice_can_activate_recommended'	=> _n_noop('The following recommended plugin is currently inactive: %1$s.', 'The following recommended plugins are currently inactive: %1$s.', 'eltd'),
				'notice_cannot_activate'			=> _n_noop('Sorry, but you do not have the correct permissions to activate the %s plugin. Contact the administrator of this site for help on getting the plugin activated.', 'Sorry, but you do not have the correct permissions to activate the %s plugins. Contact the administrator of this site for help on getting the plugins activated.', 'eltd'),
				'notice_ask_to_update'				=> _n_noop('The following plugin needs to be updated to its latest version to ensure maximum compatibility with this theme: %1$s.', 'The following plugins need to be updated to their latest version to ensure maximum compatibility with this theme: %1$s.', 'eltd'),
				'notice_cannot_update'				=> _n_noop('Sorry, but you do not have the correct permissions to update the %s plugin. Contact the administrator of this site for help on getting the plugin updated.', 'Sorry, but you do not have the correct permissions to update the %s plugins. Contact the administrator of this site for help on getting the plugins updated.', 'eltd'),
				'install_link'						=> _n_noop('Begin installing plugin', 'Begin installing plugins', 'eltd'),
				'activate_link'						=> _n_noop('Activate installed plugin', 'Activate installed plugins', 'eltd'),
				'return'							=> esc_html__('Return to Required Plugins Installer', 'eltd'),
				'plugin_activated'					=> esc_html__('Plugin activated successfully.', 'eltd'),
				'complete'							=> esc_html__('All plugins installed and activated successfully. %s', 'eltd'),
				'nag_type'							=> 'updated'
			)
		);
		tgmpa($plugins, $config);
	}
}

/**
 * Force Visual Composer to initialize as "built into the theme". This will hide certain tabs under the Settings->Visual Composer page
 */
if(function_exists('vc_set_as_theme')) vc_set_as_theme(true);

// Initialising Shortcodes
if (class_exists('WPBakeryVisualComposerAbstract')) {
	function requireVcExtend(){
		require_once locate_template('/extendvc/extend-vc.inc');
	}
	add_action('after_setup_theme', 'requireVcExtend',2);
}
?>