<?php
$absolute_path = explode('wp-content', $_SERVER['SCRIPT_FILENAME']);

if(count($absolute_path) == 1) {
    $absolute_path = explode('wp-admin', $_SERVER['SCRIPT_FILENAME']);
}

$wp_load = $absolute_path[0] . 'wp-load.php';
require_once($wp_load);

header('Content-type: application/x-javascript');

?>

var $j = jQuery.noConflict();

$j(document).ready(function() {
	"use strict";

	<?php print $eltd_moose_options['custom_js']; ?>
});
