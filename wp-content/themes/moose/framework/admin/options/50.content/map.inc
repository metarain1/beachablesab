<?php

$contentPage = new ElatedMooseAdminPage('_content', 'Content', 'fa fa-align-justify');
$eltdFramework->eltdOptions->addAdminPage('content', $contentPage);

$panel_general = new ElatedMoosePanel('General', 'general');
$contentPage->addChild('panel_general', $panel_general);

	$background_color = new ElatedMooseField("color","background_color","","Content Background Color","Choose the background color for page content area. Default color is #f5f5f5.");
	$panel_general->addChild("background_color",$background_color);

	$background_color_grid = new ElatedMooseField("color","background_color_grid","","Content Background Color for Templates in Grid","Choose the background color for the page templates in grid.");
	$panel_general->addChild("background_color_grid",$background_color_grid);

	$content_top_padding = new ElatedMooseField("text","content_top_padding","0","Content Top Padding (px)","Enter top padding for content area. If you set this value then it's important to set also Content top padding for mobile header value.", array(), array("col_width" => 3));
	$panel_general->addChild("content_top_padding",$content_top_padding);

    $content_top_padding_default_template = new ElatedMooseField("text","content_top_padding_default_template","80","Content Top Padding for Templates in Grid (px)","Enter top padding for content area for Templates in grid. If you set this value then it's important to set also Content top padding for mobile header value.", array(), array("col_width" => 3));
	$panel_general->addChild("content_top_padding_default_template",$content_top_padding_default_template);

	$content_top_padding_mobile = new ElatedMooseField("text","content_top_padding_mobile","44","Content Top Padding for Mobile Header (px)","Enter top padding for content area for Mobile Header.", array(), array("col_width" => 3));
	$panel_general->addChild("content_top_padding_mobile",$content_top_padding_mobile);

    $overlapping_content = new ElatedMooseField("yesno","overlapping_content","no","Enable Overlapping Content","Enabling this option will make content overlap title area or slider for set amount of pixels", array(),
        array("dependence" => true,
            "dependence_hide_on_yes" => "",
            "dependence_show_on_yes" => "#eltdf_overlapping_content_container"));
    $panel_general->addChild("overlapping_content",$overlapping_content);

    $overlapping_content_container = new ElatedMooseContainer("overlapping_content_container","overlapping_content","no");
    $panel_general->addChild("overlapping_content_container",$overlapping_content_container);

        $overlapping_top_content_amount = new ElatedMooseField("text","overlapping_top_content_amount","","Overlapping top amount (px)","Enter amount of pixels you would like content to overlap title area or slider (default is 40)", array(), array("col_width" => 1));
        $overlapping_content_container->addChild("overlapping_top_content_amount",$overlapping_top_content_amount);

        $overlapping_bottom_content_amount = new ElatedMooseField("text","overlapping_bottom_content_amount","","Overlapping bottom amount (px)","Enter amount of pixels you would like content to overlap footer (default is 40)", array(), array("col_width" => 1));
        $overlapping_content_container->addChild("overlapping_bottom_content_amount",$overlapping_bottom_content_amount);

        $overlapping_content_padding = new ElatedMooseField("text","overlapping_content_padding","","Overlapping left/right padding (px)","This option takes effect only on Default (in grid) templates", array(), array("col_width" => 1));
        $overlapping_content_container->addChild("overlapping_content_padding",$overlapping_content_padding);

        $animate_overlapping_content = new ElatedMooseField("yesno","animate_overlapping_content","no","Animate overlapping content","Enabling this option will turn on entry animation on overlapping content");
        $overlapping_content_container->addChild("animate_overlapping_content",$animate_overlapping_content);

        $frame_around_overlapping_content = new ElatedMooseField("yesno","frame_around_overlapping_content","no","Frame around overlapping content","Enabling this option will set a frame around the overlapping content", array(),
            array("dependence" => true,
                "dependence_hide_on_yes" => "",
                "dependence_show_on_yes" => "#eltdf_frame_around_overlapping_content_container"));
        $overlapping_content_container->addChild("frame_around_overlapping_content",$frame_around_overlapping_content);

        $frame_around_overlapping_content_container = new ElatedMooseContainer("frame_around_overlapping_content_container","frame_around_overlapping_content","no");
        $overlapping_content_container->addChild("frame_around_overlapping_content_container",$frame_around_overlapping_content_container);

            $frame_around_overlapping_content_width = new ElatedMooseField("text","frame_around_overlapping_content_width","","Frame width (px)","Enter the width of the frame (default is 15)", array(), array("col_width" => 1));
            $frame_around_overlapping_content_container->addChild("frame_around_overlapping_content_width",$frame_around_overlapping_content_width);

            $frame_around_overlapping_content_color = new ElatedMooseField("color","frame_around_overlapping_content_color","","Frame Color","Choose a color for frame");
            $frame_around_overlapping_content_container->addChild("frame_around_overlapping_content_color",$frame_around_overlapping_content_color);

            $frame_around_overlapping_content_pattern = new ElatedMooseField("image","frame_around_overlapping_content_pattern","","Pattern Image","Choose an image to be used as a pattern in the frame around the overlapping content");
            $frame_around_overlapping_content_container->addChild("frame_around_overlapping_content_pattern",$frame_around_overlapping_content_pattern);

	$content_grid_position = new ElatedMooseField("select","content_grid_position","","Position of Content in Grid","Set position of content in grid", array(
        "default" => "Default",
		"left" => "Left",
        "right" => "Right"
    ));
    $panel_general->addChild("content_grid_position",$content_grid_position);

    $content_predefined_width = new ElatedMooseField("select","content_predefined_width","","Initial Width of Content","Choose the initial width of content which is in grid (Applies to pages set to 'Default Template' and rows set to 'In Grid' )", array(
        "" => "1100px - default",
        "grid_1300" => "1300px",
		"grid_1200" => "1200px",
        "grid_1000" => "1000px",
        "grid_800" => "800px"
    ));
    $panel_general->addChild("content_predefined_width",$content_predefined_width);

//Content Bottom Area

$panel_content_bottom = new ElatedMoosePanel("Content Bottom Area","content_bottom_area_panel");
$contentPage->addChild("panel_content_bottom",$panel_content_bottom);

$enable_content_bottom_area = new ElatedMooseField("yesno","enable_content_bottom_area","no","Enable Content Bottom Area","This option will enable Content Bottom area on pages", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_enable_content_bottom_area_container"));
$panel_content_bottom->addChild("enable_content_bottom_area",$enable_content_bottom_area);

$enable_content_bottom_area_container = new ElatedMooseContainer("enable_content_bottom_area_container","enable_content_bottom_area","no");
$panel_content_bottom->addChild("enable_content_bottom_area_container",$enable_content_bottom_area_container);

$custom_sidebars = eltd_moose_get_custom_sidebars();

$content_bottom_sidebar_custom_display = new ElatedMooseField("selectblank","content_bottom_sidebar_custom_display","","Sidebar to Display","Choose a Content Bottom sidebar to display", $custom_sidebars);
$enable_content_bottom_area_container->addChild("content_bottom_sidebar_custom_display",$content_bottom_sidebar_custom_display);

$content_bottom_in_grid = new ElatedMooseField("yesno","content_bottom_in_grid","yes","Display in Grid","Enabling this option will place Content Bottom in grid");
$enable_content_bottom_area_container->addChild("content_bottom_in_grid",$content_bottom_in_grid);

$content_bottom_background_color = new ElatedMooseField("color","content_bottom_background_color","","Background Color","Choose a background color for Content Bottom area");
$enable_content_bottom_area_container->addChild("content_bottom_background_color",$content_bottom_background_color);