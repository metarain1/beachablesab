<?php
# Database Configuration
define( 'DB_NAME', 'wp_beachab' );
define( 'DB_USER', 'beachab' );
define( 'DB_PASSWORD', '9OK40vNaZkaPBTrljCoN' );
define( 'DB_HOST', '127.0.0.1' );
define( 'DB_HOST_SLAVE', '127.0.0.1' );
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', 'utf8_unicode_ci');
$table_prefix = 'wp_';

# Security Salts, Keys, Etc
define('AUTH_KEY',         'sD+wD>Qn_0K`GaE9wg4Zp3$>/Kem3XZ8@KZ4F{J K>a@g&(EG14U|;GlVLKy*#+Q');
define('SECURE_AUTH_KEY',  'N~1:&;20lMpM_X`Q:*_U8-~*|(Q=0R3#? 65Ei-||.CR&:I_3[4k(jsX^o863@a{');
define('LOGGED_IN_KEY',    '@el>2R@VbO+t^V:lRWl# iHE]JQ7z`pXfkD,`<Fk9*g2RN/L],veIo0xK;x0Mv|i');
define('NONCE_KEY',        'f},$2B(^qE@Zd+?8lCx@wild$gSt$o_vI}uc>CVW)(w@}~Rn+KwB@*7:$ce+~#qV');
define('AUTH_SALT',        '+rT>,~@*;imj>+r=%j@_=9<%#([IQd@6iM7vI@NOlUHj8E8}6K6Ou,-*%]`wp)fl');
define('SECURE_AUTH_SALT', '6bA)uOwSLf|.dG91G#z1og%eq!{Fv64 -9-2drK)_+!a>@*yRB[+f$B;U?k``|.c');
define('LOGGED_IN_SALT',   'x }XZvKC3A8tQ+>=gGPqj|sEf7QG+22b@ur@:7YoQx^=iy1L:{piAm+^*46T2+3q');
define('NONCE_SALT',       'Sa6mn,,+;=Z|B*Rn/%^@(cBs{+:z~5s W12Uvv/0Vj Qr)4sr=Q*e=/gPH.J8+Dk');


set_time_limit(300);

# Localized Language Stuff

define( 'WP_CACHE', TRUE );

define( 'WP_AUTO_UPDATE_CORE', false );

define( 'PWP_NAME', 'beachab' );

define( 'FS_METHOD', 'direct' );

define( 'FS_CHMOD_DIR', 0775 );

define( 'FS_CHMOD_FILE', 0664 );

define( 'PWP_ROOT_DIR', '/nas/wp' );

define( 'WPE_APIKEY', '4e71f2141acd7dbf6ab03522195655c861c2e44d' );

define( 'WPE_CLUSTER_ID', '120479' );

define( 'WPE_CLUSTER_TYPE', 'pod' );

define( 'WPE_ISP', true );

define( 'WPE_BPOD', false );

define( 'WPE_RO_FILESYSTEM', false );

define( 'WPE_LARGEFS_BUCKET', 'largefs.wpengine' );

define( 'WPE_SFTP_PORT', 2222 );

define( 'WPE_LBMASTER_IP', '' );

define( 'WPE_CDN_DISABLE_ALLOWED', true );

define( 'DISALLOW_FILE_MODS', FALSE );

define( 'DISALLOW_FILE_EDIT', FALSE );

define( 'DISABLE_WP_CRON', false );

define( 'WPE_FORCE_SSL_LOGIN', false );

define( 'FORCE_SSL_LOGIN', false );

/*SSLSTART*/ if ( isset($_SERVER['HTTP_X_WPE_SSL']) && $_SERVER['HTTP_X_WPE_SSL'] ) $_SERVER['HTTPS'] = 'on'; /*SSLEND*/

define( 'WPE_EXTERNAL_URL', false );

define( 'WP_POST_REVISIONS', FALSE );

define( 'WPE_WHITELABEL', 'wpengine' );

define( 'WP_TURN_OFF_ADMIN_BAR', false );

define( 'WPE_BETA_TESTER', false );

umask(0002);

$wpe_cdn_uris=array ( );

$wpe_no_cdn_uris=array ( );

$wpe_content_regexs=array ( );

$wpe_all_domains=array ( 0 => 'beachab.wpengine.com', );

$wpe_varnish_servers=array ( 0 => 'pod-120479', );

$wpe_special_ips=array ( 0 => '104.196.55.129', );

$wpe_ec_servers=array ( );

$wpe_netdna_domains=array ( );

$wpe_netdna_domains_secure=array ( );

$wpe_netdna_push_domains=array ( );

$wpe_domain_mappings=array ( );

$memcached_servers=array ( );
define('WPLANG','');

# WP Engine ID


# WP Engine Settings






# That's It. Pencils down
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');
require_once(ABSPATH . 'wp-settings.php');

$_wpe_preamble_path = null; if(false){}
