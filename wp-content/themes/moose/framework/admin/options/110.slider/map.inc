<?php

$slidersPage = new ElatedMooseAdminPage('_slider', 'Elated Slider', 'fa fa-arrows-h');
$eltdFramework->eltdOptions->addAdminPage('slider', $slidersPage);

//Elated Slider
$panel_navigation_style = new ElatedMoosePanel('General Style', 'general_style');
$slidersPage->addChild('general_style', $panel_navigation_style);

$qs_slider_height_mobile = new ElatedMooseField("text","qs_slider_height_mobile","","Slider Height For Mobile Devices (px)","Define slider height for mobile devices");
$panel_navigation_style->addChild("qs_slider_height_mobile",$qs_slider_height_mobile);

$qs_slider_preloader_background = new ElatedMooseField("color","qs_slider_preloader_background","","Slider Preloader Background Color","Define background color for slider preloader");
$panel_navigation_style->addChild("qs_slider_preloader_background",$qs_slider_preloader_background);

// Navigation Control Style
$panel_navigation_style = new ElatedMoosePanel('Navigation Bullets Style', 'panel_navigation_style');
$slidersPage->addChild('panel_navigation_style', $panel_navigation_style);

$group1 = new ElatedMooseGroup("Colors","Choose color styles for navigation bullets");
$panel_navigation_style->addChild("group1",$group1);

$row1 = new ElatedMooseRow();
$group1->addChild("row1",$row1);

$qs_navigation_control_color = new ElatedMooseField("colorsimple","qs_navigation_control_color","","Color","This is some description");
$row1->addChild("qs_navigation_control_color",$qs_navigation_control_color);

$qs_navigation_control_transparency = new ElatedMooseField("textsimple","qs_navigation_control_transparency","","Transparency (0-1)","This is some description");
$row1->addChild("qs_navigation_control_transparency",$qs_navigation_control_transparency);

$qs_navigation_control_active_color = new ElatedMooseField("colorsimple","qs_navigation_control_active_color","","Active Color","This is some description");
$row1->addChild("qs_navigation_control_active_color",$qs_navigation_control_active_color);

$qs_navigation_control_active_transparency = new ElatedMooseField("textsimple","qs_navigation_control_active_transparency","","Active Transparency(0-1)","This is some description");
$row1->addChild("qs_navigation_control_active_transparency",$qs_navigation_control_active_transparency);

$group2 = new ElatedMooseGroup("Size","Define size for navigation bullets controls (w=h in px)");
$panel_navigation_style->addChild("group2",$group2);

$row1 = new ElatedMooseRow();
$group2->addChild("row1",$row1);

$qs_navigation_control_size = new ElatedMooseField("textsimple","qs_navigation_control_size","","Size (px)","This is some description");
$row1->addChild("qs_navigation_control_size",$qs_navigation_control_size);

$qs_navigation_control_active_size = new ElatedMooseField("textsimple","qs_navigation_control_active_size","","Active Size (px)","This is some description");
$row1->addChild("qs_navigation_control_active_size",$qs_navigation_control_active_size);

$group3 = new ElatedMooseGroup("Border Style","Define border style for navigation bullets");
$panel_navigation_style->addChild("group3",$group3);

// Custom cursor navigation style

$panel_custom_cursor = new ElatedMoosePanel('Custom cursor navigation style', 'panel_custom_cursor');
$slidersPage->addChild('panel_navigation_bullet_style', $panel_custom_cursor);

$qs_enable_navigation_custom_cursor = new ElatedMooseField("yesno","qs_enable_navigation_custom_cursor","no","Enable Custom Cursor for Navigation","Enabling this option will display custom cursors for slider navigation", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_qs_enable_navigation_custom_cursor_container"));
$panel_custom_cursor->addChild("qs_enable_navigation_custom_cursor",$qs_enable_navigation_custom_cursor);


$qs_enable_navigation_custom_cursor_container = new ElatedMooseContainer("qs_enable_navigation_custom_cursor_container","qs_enable_navigation_custom_cursor","no");
$panel_custom_cursor->addChild("qs_enable_navigation_custom_cursor_container",$qs_enable_navigation_custom_cursor_container);

$cursor_image_left_right_area_size = new ElatedMooseField("text","cursor_image_left_right_area_size","","Clickable Left/Right Area Size (%)","Define size of clickable left/right slider area in relation to slider width (default value is 8%)", array(), array("col_width" => 3));
$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_left_right_area_size",$cursor_image_left_right_area_size);

$cursor_image_left_normal = new ElatedMooseField("image","cursor_image_left_normal","","Cursor Image 'Left' - Normal","Choose a default cursor 'Left' image to display ");
$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_left_normal",$cursor_image_left_normal);

$cursor_image_right_normal = new ElatedMooseField("image","cursor_image_right_normal","","Cursor Image 'Right' - Normal","Choose a default cursor 'Right' image to display ");
$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_right_normal",$cursor_image_right_normal);


$cursor_image_left_light = new ElatedMooseField("image","cursor_image_left_light","","Cursor Image 'Left' - Light","Choose a cursor 'Left' light image to display ");
$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_left_light",$cursor_image_left_light);

$cursor_image_right_light = new ElatedMooseField("image","cursor_image_right_light","","Cursor Image 'Right' - Light","Choose a cursor 'Right' light image to display ");
$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_right_light",$cursor_image_right_light);

$cursor_image_left_dark = new ElatedMooseField("image","cursor_image_left_dark","","Cursor Image 'Left' - Dark","Choose a cursor 'Left' dark image to display ");
$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_left_dark",$cursor_image_left_dark);

$cursor_image_right_dark = new ElatedMooseField("image","cursor_image_right_dark","","Cursor Image 'Right' - Dark","Choose a cursor 'Right' dark image to display ");
$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_right_dark",$cursor_image_right_dark);


$qs_enable_navigation_custom_cursor_grab = new ElatedMooseField("yesno","qs_enable_navigation_custom_cursor_grab","no","Enable Custom Cursor for 'Grab' Arrow","Enabling this option will display custom cursor for slider 'Grab' arrow", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_qs_enable_navigation_custom_cursor_grab_container"));
$qs_enable_navigation_custom_cursor_container->addChild("qs_enable_navigation_custom_cursor_grab",$qs_enable_navigation_custom_cursor_grab);

$qs_enable_navigation_custom_cursor_grab_container = new ElatedMooseContainer("qs_enable_navigation_custom_cursor_grab_container","qs_enable_navigation_custom_cursor_grab","no");
$qs_enable_navigation_custom_cursor_container->addChild("qs_enable_navigation_custom_cursor_grab_container",$qs_enable_navigation_custom_cursor_grab_container);

$cursor_image_grab_normal = new ElatedMooseField("image","cursor_image_grab_normal","","Cursor Image 'Grab' - Normal","Choose a default cursor 'Grab' image to display");
$qs_enable_navigation_custom_cursor_grab_container->addChild("cursor_image_grab_normal",$cursor_image_grab_normal);

$cursor_image_grab_light = new ElatedMooseField("image","cursor_image_grab_light","","Cursor Image 'Grab' - Light","Choose a cursor 'Grab' light image to display");
$qs_enable_navigation_custom_cursor_grab_container->addChild("cursor_image_grab_light",$cursor_image_grab_light);

$cursor_image_grab_dark = new ElatedMooseField("image","cursor_image_grab_dark","","Cursor Image 'Grab' - Dark","Choose a cursor 'Grab' dark image to display");
$qs_enable_navigation_custom_cursor_grab_container->addChild("cursor_image_grab_dark",$cursor_image_grab_dark);
