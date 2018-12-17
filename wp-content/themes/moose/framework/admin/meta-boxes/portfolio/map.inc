<?php

$eltd_pages = array();
$pages = get_pages(); 
foreach($pages as $page) {
	$eltd_pages[$page->ID] = $page->post_title;
}

global $eltdIconCollections;

//Portfolio Images

$eltdPortfolioImages = new ElatedMooseMetaBox("portfolio_page", "Portfolio Images (multiple upload)");
$eltdFramework->eltdMetaBoxes->addMetaBox("portfolio_images",$eltdPortfolioImages);

	$eltd_portfolio_image_gallery = new ElatedMooseMultipleImages("eltd_portfolio-image-gallery","Portfolio Images","Choose your portfolio images");
	$eltdPortfolioImages->addChild("eltd_portfolio-image-gallery",$eltd_portfolio_image_gallery);

/*//Portfolio Images/Videos

$eltdPortfolioImagesVideos = new ElatedMooseMetaBox("portfolio_page", "Elated Portfolio Images/Videos (single upload)");
$eltdFramework->eltdMetaBoxes->addMetaBox("portfolio_images_videos",$eltdPortfolioImagesVideos);

	$eltd_portfolio_images_videos = new ElatedMooseImagesVideos("Portfolio Images/Videos","ThisIsDescription");
	$eltdPortfolioImagesVideos->addChild("eltd_portfolio_images_videos",$eltd_portfolio_images_videos);
*/
//Portfolio Images/Videos 2

$eltdPortfolioImagesVideos2 = new ElatedMooseMetaBox("portfolio_page", "Portfolio Images/Videos (single upload)");
$eltdFramework->eltdMetaBoxes->addMetaBox("portfolio_images_videos2",$eltdPortfolioImagesVideos2);

	$eltd_portfolio_images_videos2 = new ElatedMooseImagesVideosFramework("Portfolio Images/Videos 2","ThisIsDescription");
	$eltdPortfolioImagesVideos2->addChild("eltd_portfolio_images_videos2",$eltd_portfolio_images_videos2);

//Portfolio Additional Sidebar Items

$eltdAdditionalSidebarItems = new ElatedMooseMetaBox("portfolio_page", "Additional Portfolio Sidebar Items");
$eltdFramework->eltdMetaBoxes->addMetaBox("portfolio_properties",$eltdAdditionalSidebarItems);

	$eltd_portfolio_properties = new ElatedMooseOptionsFramework("Portfolio Properties","ThisIsDescription");
	$eltdAdditionalSidebarItems->addChild("eltd_portfolio_properties",$eltd_portfolio_properties);


//General

$eltdGeneral = new ElatedMooseMetaBox("portfolio_page", "General");
$eltdFramework->eltdMetaBoxes->addMetaBox("portfolio_general",$eltdGeneral);

	$eltd_page_background_color = new ElatedMooseMetaField("color","eltd_page_background_color","","Page Background Color","Choose the page background (body) color");
	$eltdGeneral->addChild("eltd_page_background_color",$eltd_page_background_color);

	$group1 = new ElatedMooseGroup("Content Style","Define styles for Content area");
	$eltdGeneral->addChild("group1",$group1);

		$row1 = new ElatedMooseRow();
		$group1->addChild("row1",$row1);

			$eltd_content_top_padding = new ElatedMooseMetaField("textsimple","eltd_content-top-padding","","Content Top Padding (px)","This option control content top padding.");
			$row1->addChild("eltd_content-top-padding",$eltd_content_top_padding);

			$eltd_content_top_padding_mobile = new ElatedMooseMetaField("selectblanksimple","eltd_content-top-padding-mobile","","Set this top padding for mobile header","", array(
		       "no" => "No",
		       "yes" => "Yes"
		      ));
			$row1->addChild("eltd_content-top-padding-mobile",$eltd_content_top_padding_mobile);

	$eltd_show_animation = new ElatedMooseMetaField("selectblank","eltd_show-animation","","Page Transition",'Choose a type of transition between loading pages.', array(
       "no_animation" => "No Animation",
       "updown" => "Up / Down",
       "fade" => "Fade",
		"updown_fade" => "Up/Down (In) / Fade (Out)",
       "leftright" => "Left / Right"
      ), array(), "enable_grid_elements", array("yes"));
	$eltdGeneral->addChild("eltd_show-animation",$eltd_show_animation);

	$page_transitions_notice = new ElatedMooseNotice("Page Transition",'Choose a a type of transition between loading pages. In order for animation to work properly, you must choose "Post name" in permalinks settings', "AJAX Page transitions are disabled due to VC Grid Elements", "enable_grid_elements","no");
	$eltdGeneral->addChild("page_transitions_notice",$page_transitions_notice);

	$eltd_revolution_slider = new ElatedMooseMetaField("text","eltd_revolution-slider","","Layer Slider or Elated Slider Shortcode","Copy and paste your shortcode located in Elated Slider -> Slider");
	$eltdGeneral->addChild("eltd_revolution-slider",$eltd_revolution_slider);

	$eltd_choose_portfolio_single_view = new ElatedMooseMetaField("selectblank","eltd_choose-portfolio-single-view","","Portfolio Type",'Choose a default type for Single Project pages', array(
		"small-images" => "Portfolio small images",
		"small-slider" => "Portfolio small slider",
		"big-images" => "Portfolio big images",
		"big-slider" => "Portfolio big slider",
		"custom" => "Portfolio custom",
		"full-width-custom" => "Portfolio full width custom",
		"gallery" => "Portfolio gallery"
	),
        array("dependence" => true,
            "hide" => array(
                ""=>"#eltdf_eltd_choose_number_of_portfolio_columns_container",
                "full-width-custom"=>"#eltdf_eltd_choose_number_of_portfolio_columns_container",
                "custom"=>"#eltdf_eltd_choose_number_of_portfolio_columns_container",
                "big-slider"=>"#eltdf_eltd_choose_number_of_portfolio_columns_container",
                "big-images"=>"#eltdf_eltd_choose_number_of_portfolio_columns_container",
                "small-slider"=>"#eltdf_eltd_choose_number_of_portfolio_columns_container",
                "small-images"=>"#eltdf_eltd_choose_number_of_portfolio_columns_container"
            ),
            "show" => array(
                "gallery"=>"#eltdf_eltd_choose_number_of_portfolio_columns_container")
        )
    );
	$eltdGeneral->addChild("eltd_choose-portfolio-single-view",$eltd_choose_portfolio_single_view);

    $eltd_choose_number_of_portfolio_columns_container = new ElatedMooseContainer("eltd_choose_number_of_portfolio_columns_container","eltd_choose-portfolio-single-view","no",array("", "1", "2", "3", "4", "5", "7"));
    $eltdGeneral->addChild("eltd_choose_number_of_portfolio_columns_container",$eltd_choose_number_of_portfolio_columns_container);

$eltd_choose_number_of_portfolio_columns = new ElatedMooseMetaField("selectblank","eltd_choose-number-of-portfolio-columns","","Number of Columns",'Choose the number of columns for Portfolio Gallery type', array(
		"2" => "2 Columns",
		"3" => "3 Columns",
		"4" => "4 Columns"
	));
    $eltd_choose_number_of_portfolio_columns_container->addChild("eltd_choose-number-of-portfolio-columns",$eltd_choose_number_of_portfolio_columns);

    $eltd_choose_portfolio_image_size = new ElatedMooseMetaField("select","eltd_choose-portfolio-image-size","full","Image Proportions",'Choose image proportions for Portfolio Gallery type', array(
        "full" => "Original Size",
        "portfolio-square" => "Square",
        "portfolio-landscape" => "Landscape",
        "portfolio-portrait" => "Portrait"
    ));

    $eltd_choose_number_of_portfolio_columns_container->addChild("eltd_choose-portfolio-image-size",$eltd_choose_portfolio_image_size);

    $eltd_choose_portfolio_list_page = new ElatedMooseMetaField("selectblank","eltd_choose-portfolio-list-page","",'"Back To" Link','Choose "Back To" page to link from portfolio Single Project page',$eltd_pages);
	$eltdGeneral->addChild("eltd_choose-portfolio-list-page",$eltd_choose_portfolio_list_page);

	$eltd_portfolio_external_link = new ElatedMooseMetaField("text","eltd_portfolio-external-link","","Portfolio External Link","Enter URL to link from Portfolio List page");
	$eltdGeneral->addChild("eltd_portfolio-external-link",$eltd_portfolio_external_link);

    $eltd_portfolio_lightbox_link = new ElatedMooseMetaField("text","eltd_portfolio-lightbox-link","","Portfolio Custom Lighbox Content","Enter URL to link custom image/video content inside lightbox");
    $eltdGeneral->addChild("eltd_portfolio-lightbox-link",$eltd_portfolio_lightbox_link);

	$eltd_portfolio_type_masonry_style = new ElatedMooseMetaField("select","eltd_portfolio_type_masonry_style","","Dimensions for Masonry",'Choose image layout when it appears in Masonry type portfolio lists', array(
		"default" => "Default",
		"large_width" => "Large width",
		"large_height" => "Large height",
		"large_width_height" => "Large width/height"
	));
	$eltdGeneral->addChild("eltd_portfolio_type_masonry_style",$eltd_portfolio_type_masonry_style);
	
	$eltd_portfolio_masonry_parallax = new ElatedMooseMetaField("select","eltd_portfolio_masonry_parallax","no","Set Masonry Item in Parallax","", array(
		"no" => "No",
		"yes" => "Yes"
	));
	$eltdGeneral->addChild("eltd_portfolio_masonry_parallax",$eltd_portfolio_masonry_parallax);
	
	$eltd_portfolio_disable_comments = new ElatedMooseMetaField("selectblank","eltd_portfolio-hide-comments","","Disable Comments","", array(
		"no" => "No",
		"yes" => "Yes"
	));
    $eltdGeneral->addChild("eltd_portfolio-hide-comments",$eltd_portfolio_disable_comments);

    $eltd_image_hover_container = new ElatedMooseGroup("Image Hover Style", "Define style for hover color");
	$eltdGeneral->addChild("eltd_image_hover_container", $eltd_image_hover_container);

		$row11 = new ElatedMooseRow();
		$eltd_image_hover_container->addChild("row11", $row11);

			$eltd_portfolio_hover_color = new ElatedMooseMetaField("colorsimple","eltd_portfolio-hover-color","","Portfolio Hover Color","");
			$row11->addChild("eltd_portfolio-hover-color",$eltd_portfolio_hover_color);

			$eltd_portfolio_hover_color_opacity = new ElatedMooseMetaField("textsimple","eltd_portfolio-hover-color-opacity","","Portfolio Hover Color Opacity","");
			$row11->addChild("eltd_portfolio-hover-color-opacity",$eltd_portfolio_hover_color_opacity);

// Header

$eltdHeader = new ElatedMooseMetaBox("portfolio_page", "Header","vertical_area",array("yes"));
$eltdFramework->eltdMetaBoxes->addMetaBox("porfolio_header",$eltdHeader);

	$eltd_header_style = new ElatedMooseMetaField("selectblank","eltd_header-style","","Header Skin","Choose a header style to make header elements (logo, main menu, side menu button) in that predefined style", array(
       "light" => "Light",
       "dark" => "Dark"
      ));
	$eltdHeader->addChild("eltd_header-style",$eltd_header_style);

    $eltd_header_style_on_scroll = new ElatedMooseMetaField("selectblank","eltd_header-style-on-scroll","","Enable Header Style on Scroll","Enabling this option, header will change style on scroll (depending on row settings) to make header elements (logo, main menu, side menu button) in that style", array(
        "no" => "No",
        "yes" => "Yes"
    ));
    $eltdHeader->addChild("eltd_header-style-on-scroll",$eltd_header_style_on_scroll);

	$eltd_header_color_per_page = new ElatedMooseMetaField("color","eltd_header_color_per_page","","Initial Header Background Color","Choose a background color for header area");
	$eltdHeader->addChild("eltd_header_color_per_page",$eltd_header_color_per_page);

	$eltd_header_color_transparency_per_page = new ElatedMooseMetaField("text","eltd_header_color_transparency_per_page","","Initial Header Transparency","Choose a transparency for the header background color (0 = fully transparent, 1 = opaque)", array(), array("col_width" => 3));
	$eltdHeader->addChild("eltd_header_color_transparency_per_page",$eltd_header_color_transparency_per_page);

	$eltd_header_bottom_border_color = new ElatedMooseMetaField("color","eltd_header_bottom_border_color","","Initial Header Bottom Border Color","Choose a bottom border color for header area");
	$eltdHeader->addChild("eltd_header_bottom_border_color",$eltd_header_bottom_border_color);

	$eltd_page_scroll_amount_for_sticky = new ElatedMooseMetaField("text","eltd_page_scroll_amount_for_sticky","","Scroll amount for sticky header appearance (px)","Define scroll amount for sticky header appearance", array(), array("col_width" => 3),"header_bottom_appearance",array( "regular","fixed","fixed_hiding") );
	$eltdHeader->addChild("eltd_page_scroll_amount_for_sticky",$eltd_page_scroll_amount_for_sticky);
	
	$eltd_page_hide_initial_sticky = new ElatedMooseMetaField("selectblank","eltd_page_hide_initial_sticky","","Hide Sticky Header Initially","Enabling this option will initially hide the header, and it will only be displayed when the user scrolls down the page", array(
		"no" => "No",
		"yes" => "Yes"	
	));
	$eltdHeader->addChild("eltd_page_hide_initial_sticky",$eltd_page_hide_initial_sticky);

// Side Menu Area

$eltdLeftMenuArea = new ElatedMooseMetaBox("portfolio_page", "Side Menu Area","vertical_area",array("no"));
$eltdFramework->eltdMetaBoxes->addMetaBox("porfolio_left_menu",$eltdLeftMenuArea);

	$eltd_page_vertical_area_transparency = new ElatedMooseMetaField("selectblank","eltd_page_vertical_area_transparency","","Enable transparent side menu area","Enabling this option will make Left Menu background transparent ", array(
       "no" => "No",
       "yes" => "Yes"
      ));
	$eltdLeftMenuArea->addChild("eltd_page_vertical_area_transparency",$eltd_page_vertical_area_transparency);

	$eltd_page_vertical_area_background = new ElatedMooseMetaField("color","eltd_page_vertical_area_background","","Side Menu Area Background Color","Choose a color for Left Menu background");
	$eltdLeftMenuArea->addChild("eltd_page_vertical_area_background",$eltd_page_vertical_area_background);
	
	$eltd_page_vertical_area_background_opacity = new ElatedMooseMetaField("text","eltd_page_vertical_area_background_opacity","","Side Menu Area Background Opacity","Choose a opacity for the Side Menu Area Background (0 = fully transparent, 1 = opaque)", array(), array("col_width" => 3));
	$eltdLeftMenuArea->addChild("eltd_page_vertical_area_background_opacity",$eltd_page_vertical_area_background_opacity);
	
	$eltd_page_vertical_area_transparency_over_slider = new ElatedMooseMetaField("selectblank","eltd_page_vertical_area_transparency_over_slider","","Transparency Setting Takes Effect Only on Elated Slider","Enabling this option will ensure that the transparency set in the 'Side Menu Area Background Opacity' takes effect only when the side menu area is over the Elated Slider", array(
	   "no" => "No",
	   "yes" => "Yes"
	  ));
	$eltdLeftMenuArea->addChild("eltd_page_vertical_area_transparency_over_slider",$eltd_page_vertical_area_transparency_over_slider);

	$eltd_page_vertical_area_background_image = new ElatedMooseMetaField("image","eltd_page_vertical_area_background_image","","Side Menu Area Background Image","Choose an image for Left Menu background");
	$eltdLeftMenuArea->addChild("eltd_page_vertical_area_background_image",$eltd_page_vertical_area_background_image);
	
	$eltd_page_disable_vertical_area_background_image = new ElatedMooseMetaField("selectblank","eltd_page_disable_vertical_area_background_image","","Disable Side Menu Area Background Image","Enabling this option will hide background image in Side Menu", array(
	   "no" => "No",
	   "yes" => "Yes"
	  ));
	$eltdLeftMenuArea->addChild("eltd_page_disable_vertical_area_background_image",$eltd_page_disable_vertical_area_background_image);

// Title

$eltdTitle = new ElatedMooseMetaBox("portfolio_page", "Title");
$eltdFramework->eltdMetaBoxes->addMetaBox("porfolio_title",$eltdTitle);

	$eltd_show_page_title = new ElatedMooseMetaField("selectblank","eltd_show-page-title","","Show Title Area","Disabling this option will turn off page title area", array(
		"no" => "No",
		"yes" => "Yes"),
		array("dependence" => true,
			"hide" => array(
				"no"=>"#eltdf_eltd_page_title_area_container, #eltdf-meta-box-portfolio_title_animations"),
			"show" => array(
				""=>"#eltdf_eltd_page_title_area_container, #eltdf-meta-box-portfolio_title_animations",
				"yes"=>"#eltdf_eltd_page_title_area_container, #eltdf-meta-box-portfolio_title_animations") ));
	$eltdTitle->addChild("eltd_show-page-title",$eltd_show_page_title);

	$eltd_page_title_area_container = new ElatedMooseContainer("eltd_page_title_area_container","eltd_show-page-title","no");
	$eltdTitle->addChild("eltd_page_title_area_container",$eltd_page_title_area_container);

	$eltd_page_title_type = new ElatedMooseMetaField("selectblank","eltd_page_title_type","","Title Type","Choose title type for this page.",array(
		"standard_title" => "Standard",
		"breadcrumbs_title" => "Breadcrumbs"
	),array(
      	"dependence" => true,
      	"hide" => array("breadcrumbs_title" => "#eltdf_eltd_title_standard_container"),
      	"show" => array("standard_title" => "#eltdf_eltd_title_standard_container","" => "#eltdf_eltd_title_standard_container")
      ));
	$eltd_page_title_area_container->addChild("eltd_page_title_type",$eltd_page_title_type);

	$eltd_animate_page_title = new ElatedMooseMetaField("selectblank","eltd_animate_page_title","","Animations","Choose an animation for Title Area",array(
		"no" => "No animation",
		"text_right_left" => "Text right to left",
		"area_top_bottom" => "Title area top to bottom"
	));
	$eltd_page_title_area_container->addChild("eltd_animate_page_title",$eltd_animate_page_title);
	
	$eltd_page_page_title_vertical_aligment = new ElatedMooseMetaField("selectblank","eltd_page_page_title_vertical_aligment","","Vertical Alignment","Specify Title vertical alignment", array(
		"header_bottom" => "From Bottom of Header",
		"window_top" => "From Window Top"
	 ));
	$eltd_page_title_area_container->addChild("eltd_page_page_title_vertical_aligment",$eltd_page_page_title_vertical_aligment);
	
	$eltd_show_page_title_text = new ElatedMooseMetaField("selectblank","eltd_show_page_title_text","","Show Title Text","Disabling this option will turn off page title text", array(
		"no" => "No",
		"yes" => "Yes"),
		array("dependence" => true,
			"hide" => array(
				"no"=>"#eltdf_eltd_title_text_container, #eltdf_animation_page_page_title_container"),
			"show" => array(
				""=>"#eltdf_eltd_title_text_container, #eltdf_animation_page_page_title_container",
				"yes"=>"#eltdf_eltd_title_text_container, #eltdf_animation_page_page_title_container") ));
	$eltd_page_title_area_container->addChild("eltd_show_page_title_text",$eltd_show_page_title_text);

	$eltd_title_text_container = new ElatedMooseContainer("eltd_title_text_container","eltd_show_page_title_text","no");
	$eltd_page_title_area_container->addChild("eltd_title_text_container",$eltd_title_text_container);

	$eltd_page_title_position = new ElatedMooseMetaField("selectblank","eltd_page_title_position","","Title Text Alignment","Specify Title text alignment",array(
		"left" => "Left",
		"center" => "Center",
		"right" => "Right"
	));
	$eltd_title_text_container->addChild("eltd_page_title_position",$eltd_page_title_position);

	$group1 = new ElatedMooseGroup("Title Text Style","Define styles for text in Title Area");
	$eltd_title_text_container->addChild("group1",$group1);

	$row1 = new ElatedMooseRow();
	$group1->addChild("row1",$row1);

	$eltd_page_title_color = new ElatedMooseMetaField("colorsimple","eltd_page-title-color","","Text Color","ThisIsDescription");
	$row1->addChild("eltd_page-title-color",$eltd_page_title_color);

	$eltd_title_text_shadow = new ElatedMooseMetaField("selectblanksimple","eltd_title_text_shadow","","Text Shadow","ThisIsDescription",array(
		"no" => "No",
		"yes" => "yes"
	));
	$row1->addChild("eltd_title_text_shadow",$eltd_title_text_shadow);

	$eltd_title_standard_container = new ElatedMooseContainer("eltd_title_standard_container","eltd_page_title_type","breadcrumbs_title");
	$eltd_page_title_area_container->addChild("eltd_title_standard_container",$eltd_title_standard_container);

	$eltd_title_like_separator = new ElatedMooseMetaField("selectblank","eltd_title_like_separator","","Show Separator Around Title Text","Choose if you want title to look like separator with text",array(
			"no" => "No",
			"yes" => "Yes"
		), array("dependence" => true,
		 	"hide" => array(
				"no" => "#eltdf_eltd_title_like_separator_container",
				"" => "#eltdf_eltd_title_like_separator_container"
				),
		    "show" => array(
				"yes" => "#eltdf_eltd_title_like_separator_container"
				)
		  )
		);
	$eltd_title_standard_container->addChild("eltd_title_like_separator",$eltd_title_like_separator);

	$eltd_title_like_separator_container = new ElatedMooseContainer("eltd_title_like_separator_container","eltd_title_like_separator","", array('', 'no'));
	$eltd_title_standard_container->addChild("eltd_title_like_separator_container",$eltd_title_like_separator_container);

		$group1 = new ElatedMooseGroup("Line Styles", "Choose style for separator line");
		$eltd_title_like_separator_container->addChild("group1",$group1);

			$row1 = new ElatedMooseRow();
			$group1->addChild("row1",$row1);

				$eltd_title_like_separator_line_color = new ElatedMooseMetaField("colorsimple","eltd_title_like_separator_line_color","","Color","This is some description");
				$row1->addChild("eltd_title_like_separator_line_color",$eltd_title_like_separator_line_color);

				$eltd_title_like_separator_line_width = new ElatedMooseMetaField("textsimple","eltd_title_like_separator_line_width","","Width","This is some description");
				$row1->addChild("eltd_title_like_separator_line_width",$eltd_title_like_separator_line_width);

				$eltd_title_like_separator_line_thickness = new ElatedMooseMetaField("textsimple","eltd_title_like_separator_line_thickness","","Thickness","This is some description");
				$row1->addChild("eltd_title_like_separator_line_thickness",$eltd_title_like_separator_line_thickness);

				$eltd_title_like_separator_line_style = new ElatedMooseMetaField("selectsimple","eltd_title_like_separator_line_style","","Style","This is some description",array(
					"solid" => "Solid",
					"dashed" => "Dashed",
					"dotted" => "Dotted"
					));
				$row1->addChild("eltd_title_like_separator_line_style",$eltd_title_like_separator_line_style);

		$eltd_title_like_separator_margins = new ElatedMooseMetaField("text","eltd_title_like_separator_margins","","Margins for Title","Define left/right margins for title from separator");
		$eltd_title_like_separator_container->addChild("eltd_title_like_separator_margins",$eltd_title_like_separator_margins);

		$eltd_title_like_separator_line_dots = new ElatedMooseMetaField("selectblank","eltd_title_like_separator_line_dots","","Dots on The End of Lines","Enabling this option will give lines a dot next to title",array(
				"no" => "No",
				"yes" => "Yes"
			),array(
				"dependence" => true,
				"hide" => array("no" => "#eltdf_eltd_title_like_separator_dots_container"),
				"show" => array("yes" => "#eltdf_eltd_title_like_separator_dots_container","" => "#eltdf_eltd_title_like_separator_dots_container")
			));
		$eltd_title_like_separator_container->addChild("eltd_title_like_separator_line_dots",$eltd_title_like_separator_line_dots);

		$eltd_title_like_separator_dots_container = new ElatedMooseContainer("eltd_title_like_separator_dots_container","eltd_title_like_separator_line_dots","no");
		$eltd_title_like_separator_container->addChild("eltd_title_like_separator_dots_container",$eltd_title_like_separator_dots_container);

			$group1 = new ElatedMooseGroup("Dots Style","Choose style for dots");
			$eltd_title_like_separator_dots_container->addChild("group1",$group1);

				$row1 = new ElatedMooseRow();
				$group1->addChild("row1",$row1);

					$eltd_title_like_separator_dots_size = new ElatedMooseMetaField("textsimple","eltd_title_like_separator_dots_size","","Size (px)","This is some description");
					$row1->addChild("eltd_title_like_separator_dots_size",$eltd_title_like_separator_dots_size);

					$eltd_title_like_separator_dots_color = new ElatedMooseMetaField("colorsimple","eltd_title_like_separator_dots_color","","Color","This is some description");
					$row1->addChild("eltd_title_like_separator_dots_color",$eltd_title_like_separator_dots_color);
	
	//Subtitle like separator with text
	$eltd_subtitle_like_separator = new ElatedMooseMetaField("selectblank","eltd_subtitle_like_separator","","Show Separator Around Subtitle Text","Choose if you want title to look like separator with text",array(
			"no" => "No",
			"yes" => "Yes"
		), array("dependence" => true,
		 	"hide" => array(
				"no" => "#eltdf_eltd_subtitle_like_separator_container",
				"" => "#eltdf_eltd_subtitle_like_separator_container"
			),
		    "show" => array(
				"yes" => "#eltdf_eltd_subtitle_like_separator_container"
			)
		  )
		);
	$eltd_title_standard_container->addChild("eltd_subtitle_like_separator",$eltd_subtitle_like_separator);

	$eltd_subtitle_like_separator_container = new ElatedMooseContainer("eltd_subtitle_like_separator_container","eltd_subtitle_like_separator","", array('', 'no'));
	$eltd_title_standard_container->addChild("eltd_subtitle_like_separator_container",$eltd_subtitle_like_separator_container);

		$group1 = new ElatedMooseGroup("Line Styles", "Choose style for separator line");
		$eltd_subtitle_like_separator_container->addChild("group1",$group1);

			$row1 = new ElatedMooseRow();
			$group1->addChild("row1",$row1);

				$eltd_subtitle_like_separator_line_color = new ElatedMooseMetaField("colorsimple","eltd_subtitle_like_separator_line_color","","Color","This is some description");
				$row1->addChild("eltd_subtitle_like_separator_line_color",$eltd_subtitle_like_separator_line_color);

				$eltd_subtitle_like_separator_line_width = new ElatedMooseMetaField("textsimple","eltd_subtitle_like_separator_line_width","","Width","This is some description");
				$row1->addChild("eltd_subtitle_like_separator_line_width",$eltd_subtitle_like_separator_line_width);

				$eltd_subtitle_like_separator_line_thickness = new ElatedMooseMetaField("textsimple","eltd_subtitle_like_separator_line_thickness","","Thickness","This is some description");
				$row1->addChild("eltd_subtitle_like_separator_line_thickness",$eltd_subtitle_like_separator_line_thickness);

				$eltd_subtitle_like_separator_line_style = new ElatedMooseMetaField("selectsimple","eltd_subtitle_like_separator_line_style","","Style","This is some description",array(
					"solid" => "Solid",
					"dashed" => "Dashed",
					"dotted" => "Dotted"
					));
				$row1->addChild("eltd_subtitle_like_separator_line_style",$eltd_subtitle_like_separator_line_style);

		$eltd_subtitle_like_separator_margins = new ElatedMooseMetaField("text","eltd_subtitle_like_separator_margins","","Margins for Subitle","Define left/right margins for subtitle from separator");
		$eltd_subtitle_like_separator_container->addChild("eltd_subtitle_like_separator_margins",$eltd_subtitle_like_separator_margins);


	$eltd_page_title_background_color = new ElatedMooseMetaField("color","eltd_page-title-background-color","","Background Color","Choose background color for Title Area");
	$eltd_page_title_area_container->addChild("eltd_page-title-background-color",$eltd_page_title_background_color);

	$eltd_show_page_title_image = new ElatedMooseMetaField("yesno","eltd_show-page-title-image","no","Don't Show Background Image","Enable this option to hide background image in Title Area", array(), array("dependence" => true, "dependence_hide_on_yes" => "#eltdf_eltd_background_image_container", "dependence_show_on_yes" => ""));
	$eltd_page_title_area_container->addChild("eltd_show-page-title-image",$eltd_show_page_title_image);

	$eltd_background_image_container = new ElatedMooseContainer("eltd_background_image_container","eltd_show-page-title-image","yes");
	$eltd_page_title_area_container->addChild("eltd_background_image_container",$eltd_background_image_container);

	$eltd_title_image = new ElatedMooseMetaField("image","eltd_title-image","","Background Image","Choose a background image for Title Area");
	$eltd_background_image_container->addChild("eltd_title-image",$eltd_title_image);

	$eltd_title_overlay_image = new ElatedMooseMetaField("image","eltd_title-overlay-image","","Pattern Overlay Image","Choose an image to be used as pattern over Title Area");
	$eltd_background_image_container->addChild("eltd_title-overlay-image",$eltd_title_overlay_image);

	$eltd_responsive_title_image = new ElatedMooseMetaField("selectblank","eltd_responsive-title-image","","Responsive Background Image","Do you want to make Title background image responsive?", array(
			"no" => "No",
			"yes" => "Yes"),
		array("dependence" => true,
			"hide" => array(
				"yes"=>"#eltdf_eltd_responsive_title_image_container, #eltdf_eltd_title-height"),
			"show" => array(
				""=>"#eltdf_eltd_responsive_title_image_container, #eltdf_eltd_title-height",
				"no"=>"#eltdf_eltd_responsive_title_image_container, #eltdf_eltd_title-height") ));
	$eltd_background_image_container->addChild("eltd_responsive-title-image",$eltd_responsive_title_image);


	$eltd_responsive_title_image_container = new ElatedMooseContainer("eltd_responsive_title_image_container","eltd_responsive-title-image","yes");
	$eltd_background_image_container->addChild("eltd_responsive_title_image_container",$eltd_responsive_title_image_container);

	$eltd_fixed_title_image = new ElatedMooseMetaField("selectblank","eltd_fixed-title-image","","Parallax Background Image","Do you want background image to have parallax effect?", array(
		"no" => "No",
		"yes" => "Yes",
		"yes_zoom" => "Yes, with zoom out"
	));
	$eltd_responsive_title_image_container->addChild("eltd_fixed-title-image",$eltd_fixed_title_image);

	$eltd_title_height = new ElatedMooseMetaField("text","eltd_title-height","","Title Height (px)","Set a height for Title Area in pixels", array(), array("col_width" => 3));
	$eltd_page_title_area_container->addChild("eltd_title-height",$eltd_title_height);

$eltd_border_top_title_area = new ElatedMooseMetaField("selectblank","eltd_border_top_title_area","","Top Border","Enabling this option will display top border on Title Area",
	array(
		"yes" => "Yes",
		"no" => "No"
	),
	array(
		"dependence" => true,
		"show" => array(
			"yes"=> "#eltdf_eltd_border_top_title_area_container"
		),
		"hide" => array(
			""=> "#eltdf_eltd_border_top_title_area_container",
			"no"=> "#eltdf_eltd_border_top_title_area_container"
		)
	)
);
$eltd_page_title_area_container->addChild("eltd_border_top_title_area",$eltd_border_top_title_area);

$eltd_border_top_title_area_container = new ElatedMooseContainer("eltd_border_top_title_area_container", "eltd_border_top_title_area", '', array('', 'no'));
$eltd_page_title_area_container->addChild("eltd_border_top_title_area_container",$eltd_border_top_title_area_container);

$eltd_enable_title_border_top_grid = new ElatedMooseMetaField("yesno","eltd_enable_title_border_top_grid","no","Enable Border in Grid","This option will show title top border in grid");
$eltd_border_top_title_area_container->addChild("eltd_enable_title_border_top_grid",$eltd_enable_title_border_top_grid);
$eltd_border_top_title_area_width = new ElatedMooseMetaField("text","eltd_border_top_title_area_width","","Top Border Width (px)","Choose a width for Title Area top border Note: If width has not been set, border top will not be displayed", array(), array("col_width" => 3));
$eltd_border_top_title_area_container->addChild("eltd_border_top_title_area_width",$eltd_border_top_title_area_width);
$eltd_border_top_title_area_color = new ElatedMooseMetaField("color","eltd_border_top_title_area_color","","Top Border Color","Choose a color for Title Area top border");
$eltd_border_top_title_area_container->addChild("eltd_border_top_title_area_color",$eltd_border_top_title_area_color);


$eltd_border_bottom_title_area = new ElatedMooseMetaField("selectblank","eltd_border_bottom_title_area","","Bottom Border","Enabling this option will display bottom border on Title Area",
	array(
		"yes" => "Yes",
		"no" => "No"
	),
	array(
		"dependence" => true,
		"show" => array(
			"yes"=> "#eltdf_eltd_border_bottom_title_area_container"
		),
		"hide" => array(
			""=> "#eltdf_eltd_border_bottom_title_area_container",
			"no"=> "#eltdf_eltd_border_bottom_title_area_container"
		)
	)
);
$eltd_page_title_area_container->addChild("eltd_border_bottom_title_area",$eltd_border_bottom_title_area);

$eltd_border_bottom_title_area_container = new ElatedMooseContainer("eltd_border_bottom_title_area_container","eltd_border_bottom_title_area", '', array('', 'no'));
$eltd_page_title_area_container->addChild("eltd_border_bottom_title_area_container",$eltd_border_bottom_title_area_container);

$eltd_enable_title_border_bottom_grid = new ElatedMooseMetaField("yesno","eltd_enable_title_border_bottom_grid","no","Enable Border in Grid","This option will show title bottom border in grid");
$eltd_border_bottom_title_area_container->addChild("eltd_enable_title_border_bottom_grid",$eltd_enable_title_border_bottom_grid);
$eltd_border_bottom_title_area_width = new ElatedMooseMetaField("text","eltd_border_bottom_title_area_width","","Bottom Border Width (px)","Choose a width for Title Area bottom border Note: If width has not been set, border bottom will not be displayed", array(), array("col_width" => 3));
$eltd_border_bottom_title_area_container->addChild("eltd_border_bottom_title_area_width",$eltd_border_bottom_title_area_width);
$eltd_border_bottom_title_area_color = new ElatedMooseMetaField("color","eltd_border_bottom_title_area_color","","Bottom Border Color","Choose a color for Title Area bottom border");
$eltd_border_bottom_title_area_container->addChild("eltd_border_bottom_title_area_color",$eltd_border_bottom_title_area_color);

//Separator

	$eltd_title_separator = new ElatedMooseMetaField("selectblank","eltd_title_separator","","Show Title Separator","Enabling this option will display a separator underneath Title", array(
			"no" => "No",
			"yes" => "Yes"
		),
		array("dependence" => true,
			"hide" => array(
				"" => "#eltdf_eltd_title_separator_container",
				"no" => "#eltdf_eltd_title_separator_container"
			),
			"show" => array(
				"yes" => "#eltdf_eltd_title_separator_container"
			)
		));
	$eltd_title_standard_container->addChild("eltd_title_separator",$eltd_title_separator);

	$eltd_title_separator_container = new ElatedMooseContainer("eltd_title_separator_container","eltd_title_separator","", array('', 'no'));
	$eltd_title_standard_container->addChild("eltd_title_separator_container",$eltd_title_separator_container);

		$eltd_title_separator_format = new ElatedMooseMetaField("select","eltd_title_separator_format","","Format","Choose a format (type) of separator", array(
				"" => "",
                "normal" => "Normal",
                "with_icon" => "With Icon",
                "with_custom_icon" => "With Custom Icon"
        ), array(
        "dependence" => true,
        "hide" => array(
        	"" => "#eltdf_eltd_separator_with_icon_container, #eltdf_eltd_separator_with_custom_icon_container",
        	"normal" => "#eltdf_eltd_separator_with_icon_container, #eltdf_eltd_separator_with_custom_icon_container",
        	"with_custom_icon" => "#eltdf_eltd_separator_with_icon_container",
        	"with_icon" => "#eltdf_eltd_separator_with_custom_icon_container"),
        "show" => array("with_icon" => "#eltdf_eltd_separator_with_icon_container", "with_custom_icon" => "#eltdf_eltd_separator_with_custom_icon_container" )));

        $eltd_title_separator_container->addChild("eltd_title_separator_format",$eltd_title_separator_format);

        $eltd_separator_with_icon_container = new ElatedMooseContainer("eltd_separator_with_icon_container","eltd_title_separator_format","normal",array("normal","with_custom_icon",""));
		$eltd_title_separator_container->addChild("eltd_separator_with_icon_container",$eltd_separator_with_icon_container);

             //init icon pack hide and show array. It will be populated dinamically from collections array
			$separator_icon_pack_hide_array = array();
			$separator_icon_pack_show_array = array();
			$separator_icon_pack_hide_array[""] = "";

			//do we have some collection added in collections array?
			if(is_array($eltdIconCollections->iconCollections) && count($eltdIconCollections->iconCollections)) {
				//get collections params array. It will contain values of 'param' property for each collection
				$separator_icon_collections_params = $eltdIconCollections->getIconCollectionsParams();

				//foreach collection generate hide and show array
				foreach ($eltdIconCollections->iconCollections as $dep_collection_key => $dep_collection_object) {
					$separator_icon_pack_hide_array[$dep_collection_key] = '';

					//we need to include only current collection in show string as it is the only one that needs to show
					$separator_icon_pack_show_array[$dep_collection_key] = '#eltdf_eltd_separator_icon_'.$dep_collection_object->param.'_container';
					$separator_icon_pack_hide_array[""] .= '#eltdf_eltd_separator_icon_'.$dep_collection_object->param.'_container,';

					//for all collections param generate hide string
					foreach ($separator_icon_collections_params as $separator_icon_collections_param) {
						//we don't need to include current one, because it needs to be shown, not hidden
						if($separator_icon_collections_param !== $dep_collection_object->param) {
							$separator_icon_pack_hide_array[$dep_collection_key].= '#eltdf_eltd_separator_icon_'.$separator_icon_collections_param.'_container,';
						}
					}

					//remove remaining ',' character
					$separator_icon_pack_hide_array[$dep_collection_key] = rtrim($separator_icon_pack_hide_array[$dep_collection_key], ',');

				}

				$separator_icon_pack_hide_array[""] = rtrim($separator_icon_pack_hide_array[""], ',');

			}

			$eltd_separator_icon_pack = new ElatedMooseMetaField(
				"selectblank",
				"eltd_separator_icon_pack",
				"",
				"Separator Icon Pack",
				"Choose icon pack for separator",
				$eltdIconCollections->getIconCollections(),
				array(
					"dependence" => true,
					"hide" => $separator_icon_pack_hide_array,
					"show" => $separator_icon_pack_show_array
				));

			$eltd_separator_with_icon_container->addChild("eltd_separator_icon_pack", $eltd_separator_icon_pack);


			if(is_array($eltdIconCollections->iconCollections) && count($eltdIconCollections->iconCollections)) {
				//foreach icon collection we need to generate separate container that will have dependency set
				//it will have one field inside with icons dropdown
				foreach ($eltdIconCollections->iconCollections as $collection_key => $collection_object) {
					$icons_array = $collection_object->getIconsArray();

					//get icon collection keys (keys from collections array, e.g 'font_awesome', 'font_elegant' etc.)
					$icon_collections_keys = $eltdIconCollections->getIconCollectionsKeys();

					//unset current one, because it doesn't have to be included in dependency that hides icon container
					unset($icon_collections_keys[array_search($collection_key, $icon_collections_keys)]);

					$separator_icon_hide_values = $icon_collections_keys;
					$separator_icon_hide_values[] = "";
					$eltd_separator_icon_container = new ElatedMooseContainer("eltd_separator_icon_".$collection_object->param."_container", "eltd_separator_icon_pack", "", $separator_icon_hide_values);
					$eltd_separator_icon = new ElatedMooseMetaField("select", "eltd_separator_icon_".$collection_object->param, "", "Separator Icon","Choose Separator Icon", $icons_array, array("col_width" => 3));
					$eltd_separator_icon_container->addChild("eltd_separator_icon_".$collection_object->param, $eltd_separator_icon);

					$eltd_separator_with_icon_container->addChild("eltd_separator_icon_".$collection_object->param."_container", $eltd_separator_icon_container);
				}

			}

			$group1 = new ElatedMooseGroup("Icon Style", "Choose icon style");
			$eltd_separator_with_icon_container->addChild("group1",$group1);

				$row1 = new ElatedMooseRow();
				$group1->addChild("row1",$row1);

					$eltd_title_separator_icon_color = new ElatedMooseMetaField("colorsimple","eltd_title_separator_icon_color","","Color","Choose a color of icon for Title separator");
					$row1->addChild("eltd_title_separator_icon_color",$eltd_title_separator_icon_color);

					$eltd_title_separator_icon_hover_color = new ElatedMooseMetaField("colorsimple","eltd_title_separator_icon_hover_color","","Hover Color","Choose a hover color of icon for Title separator");
					$row1->addChild("eltd_title_separator_icon_hover_color",$eltd_title_separator_icon_hover_color);

					$eltd_title_separator_icon_custom_size = new ElatedMooseMetaField("textsimple","eltd_title_separator_icon_custom_size","","Icon Size","Choose size of icon");
					$row1->addChild("eltd_title_separator_icon_custom_size",$eltd_title_separator_icon_custom_size);

			$group2 = new ElatedMooseGroup("Icon Position and Margin","Choose icon position and left(right) margin");
			$eltd_separator_with_icon_container->addChild("group2",$group2);

				$row1 = new ElatedMooseRow();
				$group2->addChild("row1",$row1);

					$eltd_title_separator_icon_position = new ElatedMooseMetaField("selectsimple","eltd_title_separator_icon_position","","Icon Position","Choose a position for an icon", array(
		                "left" => "Left",
		                "center" => "Center",
		                "right" => "Right"
		        	));
		        	$row1->addChild("eltd_title_separator_icon_position",$eltd_title_separator_icon_position);

		        	$eltd_title_separator_icon_margins = new ElatedMooseMetaField("textsimple","eltd_title_separator_icon_margins","","Margins (px)","Enter margin that will refer to left and right margin of the icon");
		        	$row1->addChild("eltd_title_separator_icon_margins",$eltd_title_separator_icon_margins);

        	$eltd_title_separator_icon_type = new ElatedMooseMetaField("selectblank","eltd_title_separator_icon_type","","Icon Type","Choose icon type", array(
                "normal" => "Normal",
                "circle" => "Circle",
                "square" => "Square"
        	),array("dependence" => true,
        		"hide" => array("normal" => "#eltdf_eltd_title_separator_types_container", "" => "#eltdf_eltd_title_separator_types_container"),
        		"show" => array("circle" => "#eltdf_eltd_title_separator_types_container","square" => "#eltdf_eltd_title_separator_types_container")));
        	$eltd_separator_with_icon_container->addChild("eltd_title_separator_icon_type",$eltd_title_separator_icon_type);

        	$eltd_title_separator_types_container = new ElatedMooseContainer("eltd_title_separator_types_container","eltd_title_separator_icon_type","",array("","normal"));
			$eltd_separator_with_icon_container->addChild("eltd_title_separator_types_container",$eltd_title_separator_types_container);

				$group1 = new ElatedMooseGroup("Border Style", "Define border style for icon");
				$eltd_title_separator_types_container->addChild("group1",$group1);

					$row1 = new ElatedMooseRow();
					$group1->addChild("row1",$row1);

						$eltd_title_separator_icon_border_radius = new ElatedMooseMetaField("textsimple","eltd_title_separator_icon_border_radius","","Border Radius (px)","Enter border radius for icon");
                		$row1->addChild("eltd_title_separator_icon_border_radius",$eltd_title_separator_icon_border_radius);

                		$eltd_title_separator_icon_border_width = new ElatedMooseMetaField("textsimple","eltd_title_separator_icon_border_width","","Border Width (px)","Enter border width for icon");
                		$row1->addChild("eltd_title_separator_icon_border_width",$eltd_title_separator_icon_border_width);

                		$eltd_title_separator_icon_border_color = new ElatedMooseMetaField("colorsimple","eltd_title_separator_icon_border_color","","Border Color","Enter border color for icon");
                		$row1->addChild("eltd_title_separator_icon_border_color",$eltd_title_separator_icon_border_color);

                		$eltd_title_separator_icon_border_hover_color = new ElatedMooseMetaField("colorsimple","eltd_title_separator_icon_border_hover_color","","Border Hover Color","Enter border color for icon");
                		$row1->addChild("eltd_title_separator_icon_border_hover_color",$eltd_title_separator_icon_border_hover_color);

                $group2 = new ElatedMooseGroup("Additional Icon Style","Choose adition icon styling");
                $eltd_title_separator_types_container->addChild("group2",$group2);

                	$row1 = new ElatedMooseRow();
                	$group2->addChild("row1",$row1);

                		$eltd_title_separator_icon_shape_size = new ElatedMooseMetaField("textsimple","eltd_title_separator_icon_shape_size","","Shape Size (px)","This is some description");
                		$row1->addChild("eltd_title_separator_icon_shape_size",$eltd_title_separator_icon_shape_size);

                		$eltd_title_separator_icon_background_color = new ElatedMooseMetaField("colorsimple","eltd_title_separator_icon_background_color","","Background Color","This is some description");
                		$row1->addChild("eltd_title_separator_icon_background_color",$eltd_title_separator_icon_background_color);

                		$eltd_title_separator_icon_background_hover_color = new ElatedMooseMetaField("colorsimple","eltd_title_separator_icon_background_hover_color","","Background Hover Color","This is some description");
                		$row1->addChild("eltd_title_separator_icon_background_hover_color",$eltd_title_separator_icon_background_hover_color);		                		

        $eltd_separator_with_custom_icon_container = new ElatedMooseContainer("eltd_separator_with_custom_icon_container","eltd_title_separator_format","normal",array("normal","with_icon",""));
        $eltd_title_separator_container->addChild("eltd_separator_with_custom_icon_container",$eltd_separator_with_custom_icon_container);

        	$eltd_separator_custom_icon = new ElatedMooseMetaField("image","eltd_separator_custom_icon","","Custom Icon","Choose custom icon for separator");
        	$eltd_separator_with_custom_icon_container->addChild("eltd_separator_custom_icon",$eltd_separator_custom_icon);

        $eltd_title_separator_type = new ElatedMooseMetaField("select","eltd_title_separator_type","","Type","Choose a Title separator line style", array( "" => "",
                "solid" => "Solid",
                "dashed" => "Dashed"
        ));
        $eltd_title_separator_container->addChild("eltd_title_separator_type",$eltd_title_separator_type);

        $eltd_title_separator_position = new ElatedMooseMetaField("select","eltd_title_separator_position","","Position","Choose a Title separator position", array( "" => "",
                "above" => "Above Title",
                "below" => "Below Title"
        ));
        $eltd_title_separator_container->addChild("eltd_title_separator_position",$eltd_title_separator_position);

        $eltd_title_separator_color = new ElatedMooseMetaField("color","eltd_title_separator_color","","Color","Choose a color for Title separator");
        $eltd_title_separator_container->addChild("eltd_title_separator_color",$eltd_title_separator_color);

        $group1 = new ElatedMooseGroup("Size",'Define size for Title separator');
        $eltd_title_separator_container->addChild("group1",$group1);

        $row1 = new ElatedMooseRow();
        $group1->addChild("row1",$row1);

                $eltd_title_separator_thickness = new ElatedMooseMetaField("textsimple","eltd_title_separator_thickness","","Thickness (px)","This is some description");
                $row1->addChild("eltd_title_separator_thickness",$eltd_title_separator_thickness);

                $eltd_title_separator_width = new ElatedMooseMetaField("textsimple","eltd_title_separator_width","","Width (px)","This is some description");
                $row1->addChild("eltd_title_separator_width",$eltd_title_separator_width);

        $group2 = new ElatedMooseGroup("Margin",'Add space at top and bottom of Title separator');
        $eltd_title_separator_container->addChild("group2",$group2);

        $row1 = new ElatedMooseRow();
        $group2->addChild("row1",$row1);

                $eltd_title_separator_topmargin = new ElatedMooseMetaField("textsimple","eltd_title_separator_topmargin","","Top Margin (px)","This is some description");
                $row1->addChild("eltd_title_separator_topmargin",$eltd_title_separator_topmargin);

                $eltd_title_separator_bottommargin = new ElatedMooseMetaField("textsimple","eltd_title_separator_bottommargin","","Bottom Margin (px)","This is some description");
                $row1->addChild("eltd_title_separator_bottommargin",$eltd_title_separator_bottommargin);
	
	$eltd_title_graphics = new ElatedMooseMetaField("image","eltd_title-graphics","","Title Graphics","Choose a graphic for Title Area, appearing above title");
	$eltd_title_standard_container->addChild("eltd_title-graphics",$eltd_title_graphics);

	$eltd_enable_breadcrumbs = new ElatedMooseMetaField("selectblank","eltd_enable_breadcrumbs","","Enable Breadcrumbs","Do you want to display breadcrumbs in title area?", array(
		"no" => "No",
		"yes" => "Yes"
	), array("dependence" => true,
		"hide" => array(
			"" => "#eltdf_animation_page_page_title_breadcrumbs_container",
			"no"=>"#eltdf_animation_page_page_title_breadcrumbs_container"),
		"show" => array(
			"yes"=>"#eltdf_animation_page_page_title_breadcrumbs_container") ));
	$eltd_page_title_area_container->addChild("eltd_enable_breadcrumbs",$eltd_enable_breadcrumbs);

	$eltd_page_breadcrumbs_color = new ElatedMooseMetaField("color","eltd_page_breadcrumbs_color","","Breadcrumbs Color","Choose a color for breadcrumbs text ");
	$eltd_page_title_area_container->addChild("eltd_page_breadcrumbs_color",$eltd_page_breadcrumbs_color);

	$eltd_page_subtitle = new ElatedMooseMetaField("text","eltd_page_subtitle","","Subtitle Text","Enter your subtitle text");
	$eltd_page_title_area_container->addChild("eltd_page_subtitle",$eltd_page_subtitle);
	
	$eltd_page_subtitle_position = new ElatedMooseMetaField("selectblank","eltd_page_subtitle_position","","Subtitle Position","Choose a Subtitle position", array(
			"below_title" => "Below Title",
			"above_title" => "Above Title"
	));
	$eltd_page_title_area_container->addChild("eltd_page_subtitle_position",$eltd_page_subtitle_position);

	$eltd_page_subtitle_color = new ElatedMooseMetaField("color","eltd_page_subtitle_color","","Subtitle Text Color","Choose a color for subtitle text");
	$eltd_page_title_area_container->addChild("eltd_page_subtitle_color",$eltd_page_subtitle_color);

	$eltd_page_subtitle_text_size = new ElatedMooseMetaField("selectblank","eltd_page_subtitle_text_size","","Subtitle Text Size","Size for subtitle text", array(
		'small_subtitle' => 'Small',
		'medium_subtitle' => 'Medium',
		'large_subtitle' => 'Large'
	));
	$eltd_page_title_area_container->addChild("eltd_page_subtitle_text_size",$eltd_page_subtitle_text_size);

	$eltd_title_content_style = new ElatedMooseGroup("Title Content Style", "Define style for title area content");
	$eltd_page_title_area_container->addChild("eltd_title_content_style", $eltd_title_content_style);

		$row1 = new ElatedMooseRow();
		$eltd_title_content_style->addChild("row1", $row1);

			$eltd_title_area_content_background_color = new ElatedMooseMetaField("colorsimple","eltd_title_area_content_background_color","","Title Area Content Background Color","Choose a background color for Title Area Content");
			$row1->addChild("eltd_title_area_content_background_color",$eltd_title_area_content_background_color);

			$eltd_title_area_content_opacity = new ElatedMooseMetaField("textsimple","eltd_title_area_content_opacity","","Title Area Content Background Color Opacity","Choose a transparency for the content area background color (0 = fully transparent, 1 = opaque)");
			$row1->addChild("eltd_title_area_content_opacity",$eltd_title_area_content_opacity);

    $eltd_title_content_in_grid = new ElatedMooseMetaField("yesno","eltd_title_content_in_grid","","Title Area Content In Grid","This option will show title area content in grid");
    $eltd_page_title_area_container->addChild("eltd_title_content_in_grid",$eltd_title_content_in_grid);

    $eltd_title_content_shadow = new ElatedMooseMetaField("yesno","eltd_moose_title_content_shadow","","Show Title Content Area Shadows","Enabling this option will show shadows on title content area");
    $eltd_page_title_area_container->addChild("eltd_moose_title_content_shadow",$eltd_title_content_shadow);

    $title_area_padding_group = new ElatedMooseGroup("Title Area Content Padding","Define padding for title area content");
	$eltd_page_title_area_container->addChild("title_area_padding_group",$title_area_padding_group);

		$row1 = new ElatedMooseRow();
		$title_area_padding_group->addChild("row1",$row1);

			$eltd_title_content_top_padding = new ElatedMooseMetaField("textsimple","eltd_title_content_top_padding","","Top Padding","This is some description.");
			$row1->addChild("eltd_title_content_top_padding",$eltd_title_content_top_padding);

			$eltd_title_content_right_padding = new ElatedMooseMetaField("textsimple","eltd_title_content_right_padding","","Right Padding","This is some description.");
			$row1->addChild("eltd_title_content_right_padding",$eltd_title_content_right_padding);

			$eltd_title_content_bottom_padding = new ElatedMooseMetaField("textsimple","eltd_title_content_bottom_padding","","Bottom Padding","This is some description.");
			$row1->addChild("eltd_title_content_bottom_padding",$eltd_title_content_bottom_padding);

			$eltd_title_content_left_padding = new ElatedMooseMetaField("textsimple","eltd_title_content_left_padding","","Left Padding","This is some description.");
			$row1->addChild("eltd_title_content_left_padding",$eltd_title_content_left_padding);

	$eltd_title_style = new ElatedMooseGroup("Title Style", "Define style for title");
	$eltd_page_title_area_container->addChild("eltd_title_style", $eltd_title_style);

		$row1 = new ElatedMooseRow();
		$eltd_title_style->addChild("row1", $row1);

			$eltd_title_background_color = new ElatedMooseMetaField("colorsimple","eltd_title_background_color","","Title Background Color","Choose a background color for Title");
			$row1->addChild("eltd_title_background_color",$eltd_title_background_color);

			$eltd_title_opacity = new ElatedMooseMetaField("textsimple","eltd_title_opacity","","Title Background Color Opacity","Choose a transparency for the title background color (0 = fully transparent, 1 = opaque)");
			$row1->addChild("eltd_title_opacity",$eltd_title_opacity);

	$title_padding_group = new ElatedMooseGroup("Padding","Define padding for title (When using separator around title, only right margin is counted for left/right margin)");
    $eltd_page_title_area_container->addChild("title_padding_group",$title_padding_group);
        
        $row1 = new ElatedMooseRow(true);
        $title_padding_group->addChild("row1",$row1);

			$eltd_title_top_padding = new ElatedMooseMetaField("textsimple","eltd_title_top_padding","","Top Padding (px)","This is some description.");
			$row1->addChild("eltd_title_top_padding",$eltd_title_top_padding);	

			$eltd_title_right_padding = new ElatedMooseMetaField("textsimple","eltd_title_right_padding","","Right Padding (px)","This is some description.");
			$row1->addChild("eltd_title_right_padding",$eltd_title_right_padding);	

			$eltd_title_bottom_padding = new ElatedMooseMetaField("textsimple","eltd_title_bottom_padding","","Bottom Padding (px)","This is some description.");
			$row1->addChild("eltd_title_bottom_padding",$eltd_title_bottom_padding);	

			$eltd_title_left_padding = new ElatedMooseMetaField("textsimple","eltd_title_left_padding","","Left Padding (px)","This is some description.");
			$row1->addChild("eltd_title_left_padding",$eltd_title_left_padding);

	$eltd_subtitle_style = new ElatedMooseGroup("Subtitle Style", "Define style for subtitle (When using separator around subtitle, only right margin is counted for left/right margin)");
	$eltd_page_title_area_container->addChild("eltd_subtitle_style", $eltd_subtitle_style);

		$row1 = new ElatedMooseRow();
		$eltd_subtitle_style->addChild("row1", $row1);	

			$eltd_subtitle_background_color = new ElatedMooseMetaField("colorsimple","eltd_subtitle_background_color","","Subtitle Background Color","Choose a background color for Subtitle");
			$row1->addChild("eltd_subtitle_background_color",$eltd_subtitle_background_color);

			$eltd_subtitle_opacity = new ElatedMooseMetaField("textsimple","eltd_subtitle_opacity","","Subtitle Background Color Opacity","Choose a transparency for the subtitle background color (0 = fully transparent, 1 = opaque)");
			$row1->addChild("eltd_subtitle_opacity",$eltd_subtitle_opacity);

	$subtitle_padding_group = new ElatedMooseGroup("Padding","Define padding for subtitle");
    $eltd_page_title_area_container->addChild("subtitle_padding_group",$subtitle_padding_group);
        $row1 = new ElatedMooseRow(true);
        $subtitle_padding_group->addChild("row1",$row1);

			$eltd_subtitle_top_padding = new ElatedMooseMetaField("textsimple","eltd_subtitle_top_padding","","Top Padding (px)","This is some description.");
			$row1->addChild("eltd_subtitle_top_padding",$eltd_subtitle_top_padding);

			$eltd_subtitle_right_padding = new ElatedMooseMetaField("textsimple","eltd_subtitle_right_padding","","Right Padding (px)","This is some description.");
			$row1->addChild("eltd_subtitle_right_padding",$eltd_subtitle_right_padding);

			$eltd_subtitle_bottom_padding = new ElatedMooseMetaField("textsimple","eltd_subtitle_bottom_padding","","Bottom Padding (px)","This is some description.");
			$row1->addChild("eltd_subtitle_bottom_padding",$eltd_subtitle_bottom_padding);

			$eltd_subtitle_left_padding = new ElatedMooseMetaField("textsimple","eltd_subtitle_left_padding","","Left Padding (px)","This is some description.");
			$row1->addChild("eltd_subtitle_left_padding",$eltd_subtitle_left_padding);


//Portfolio Title Animations
$eltdTitleAnimations = new ElatedMooseMetaBox('portfolio_page', 'Title Animations', 'eltd_show-page-title', array('no'));
$eltdFramework->eltdMetaBoxes->addMetaBox('portfolio_title_animations', $eltdTitleAnimations);

//Whole title content animation
$page_page_title_whole_content_animations = new ElatedMooseMetaField('selectblank', 'page_page_title_whole_content_animations', '', 'Enable Whole Title Content Animation', 'This option will enable whole title content animation', array(
	'no' => 'No',
	'yes' => 'Yes'
),
	array(
		'dependence' => true,
		'hide' => array(
			'' => '#eltdf_page_page_title_whole_content_animations_container',
			'no' => '#eltdf_page_page_title_whole_content_animations_container'
		),
		'show' => array(
			'yes' => '#eltdf_page_page_title_whole_content_animations_container'
		)
	));
$eltdTitleAnimations->addChild('page_page_title_whole_content_animations', $page_page_title_whole_content_animations);

$page_page_title_whole_content_animations_container = new ElatedMooseContainer('page_page_title_whole_content_animations_container', 'page_page_title_whole_content_animations', '', array('', 'no'));
$eltdTitleAnimations->addChild('page_page_title_whole_content_animations_container', $page_page_title_whole_content_animations_container);

$page_page_title_whole_content_animations_data_start = new ElatedMooseGroup('Scrolling Animation Start Point', 'These are properties for the first keyframe in scrolling animation');
$page_page_title_whole_content_animations_container->addChild('page_page_title_whole_content_animations_data_start', $page_page_title_whole_content_animations_data_start);

$row1 = new ElatedMooseRow();
$page_page_title_whole_content_animations_data_start->addChild('row1', $row1);

$page_page_title_whole_content_data_start = new ElatedMooseMetaField('textsimple', 'page_page_title_whole_content_data_start', '', 'Scrollbar Top Distance (px)');
$row1->addChild('page_page_title_whole_content_data_start', $page_page_title_whole_content_data_start);

$page_page_title_whole_content_start_custom_style = new ElatedMooseMetaField('textareasimple', 'page_page_title_whole_content_start_custom_style', '', 'Enter CSS declarations separated by semicolons');
$row1->addChild('page_page_title_whole_content_start_custom_style', $page_page_title_whole_content_start_custom_style);

$page_page_title_whole_content_animations_data_end = new ElatedMooseGroup('Scrolling Animation End Point', 'These are properties for the last keyframe in scrolling animation');
$page_page_title_whole_content_animations_container->addChild('page_page_title_whole_content_animations_data_end', $page_page_title_whole_content_animations_data_end);

$row2 = new ElatedMooseRow();
$page_page_title_whole_content_animations_data_end->addChild('row2', $row2);

$page_page_title_whole_content_data_end = new ElatedMooseMetaField('textsimple', 'page_page_title_whole_content_data_end', '', 'Scrollbar Top Distance (px)');
$row2->addChild('page_page_title_whole_content_data_end', $page_page_title_whole_content_data_end);

$page_page_title_whole_content_end_custom_style = new ElatedMooseMetaField('textareasimple', 'page_page_title_whole_content_end_custom_style', '', 'Enter CSS declarations separated by semicolons');
$row2->addChild('page_page_title_whole_content_end_custom_style', $page_page_title_whole_content_end_custom_style);

//Title Animations
$animation_page_page_title_container = new ElatedMooseContainerNoStyle('animation_page_page_title_container', 'eltd_show_page_title_text', 'no');
$eltdTitleAnimations->addChild('animation_page_page_title_container', $animation_page_page_title_container);

$page_page_title_animations = new ElatedMooseMetaField('selectblank', 'page_page_title_animations', '', 'Enable Page Title Animations', 'This option will enable Page Title Scroll Animations',
	array(
		'no' => 'No',
		'yes' => 'Yes'
	),
	array(
		'dependence' => true,
		'hide' => array(
			'' => '#eltdf_page_page_title_animations_container',
			'no' => '#eltdf_page_page_title_animations_container'
		),
		'show' => array(
			'yes' => '#eltdf_page_page_title_animations_container'
		) ));

$animation_page_page_title_container->addChild('page_page_title_animations', $page_page_title_animations);

$page_page_title_animations_container = new ElatedMooseContainer('page_page_title_animations_container', 'page_page_title_animations', '', array('', 'no'));
$animation_page_page_title_container->addChild('page_page_title_animations_container', $page_page_title_animations_container);

$page_page_title_animations_data_start = new ElatedMooseGroup('Scrolling Animation Start Point', 'These are properties for the first keyframe in scrolling animation');
$page_page_title_animations_container->addChild('page_page_title_animations_data_start', $page_page_title_animations_data_start);

$row1 = new ElatedMooseRow();
$page_page_title_animations_data_start->addChild('row1', $row1);

$page_page_title_data_start = new ElatedMooseMetaField('textsimple', 'page_page_title_data_start', '', 'Scrollbar Top Distance (px)');
$row1->addChild('page_page_title_data_start', $page_page_title_data_start);

$page_page_title_start_custom_style = new ElatedMooseMetaField('textareasimple', 'page_page_title_start_custom_style', '', 'Enter CSS declarations separated by semicolons');
$row1->addChild('page_page_title_start_custom_style', $page_page_title_start_custom_style);

$page_page_title_animations_data_end = new ElatedMooseGroup('Scrolling Animation End Point', 'These are properties for the last keyframe in scrolling animation');
$page_page_title_animations_container->addChild('page_page_title_animations_data_end', $page_page_title_animations_data_end);

$row2 = new ElatedMooseRow();
$page_page_title_animations_data_end->addChild('row2', $row2);

$page_page_title_data_end = new ElatedMooseMetaField('textsimple', 'page_page_title_data_end', '', 'Scrollbar Top Distance (px)');
$row2->addChild('page_page_title_data_end', $page_page_title_data_end);

$page_page_title_end_custom_style = new ElatedMooseMetaField('textareasimple', 'page_page_title_end_custom_style', '', 'Enter CSS declarations separated by semicolons');
$row2->addChild('page_page_title_end_custom_style', $page_page_title_end_custom_style);

//Title Separator Animations
$page_page_title_separator_animations = new ElatedMooseMetaField('selectblank', 'page_page_title_separator_animations', '', 'Enable Page Separator Title Animations', 'This option will enable Page Title Separator Scroll Animations',
	array(
		'no' => 'No',
		'yes' => 'Yes'
	),
	array(
		'dependence' => true,
		'hide' => array(
			'' => '#eltdf_page_page_title_separator_animations_container',
			'no' => '#eltdf_page_page_title_separator_animations_container'
		),
		'show' => array(
			'yes' => '#eltdf_page_page_title_separator_animations_container'
		)
	));
$eltdTitleAnimations->addChild('page_page_title_separator_animations', $page_page_title_separator_animations);

$page_page_title_separator_animations_container = new ElatedMooseContainer('page_page_title_separator_animations_container', 'page_page_title_separator_animations', '', array('no', ''));
$eltdTitleAnimations->addChild('page_page_title_separator_animations_container', $page_page_title_separator_animations_container);

$page_page_title_separator_animations_data_start = new ElatedMooseGroup('Scrolling Animation Start Point', 'These are properties for the first keyframe in scrolling animation');
$page_page_title_separator_animations_container->addChild('page_page_title_separator_animations_data_start', $page_page_title_separator_animations_data_start);

$row1 = new ElatedMooseRow();
$page_page_title_separator_animations_data_start->addChild('row1', $row1);

$page_page_title_separator_data_start = new ElatedMooseMetaField('textsimple', 'page_page_title_separator_data_start', '', 'Scrollbar Top Distance (px)');
$row1->addChild('page_page_title_separator_data_start', $page_page_title_separator_data_start);

$page_page_title_separator_start_custom_style = new ElatedMooseMetaField('textareasimple', 'page_page_title_separator_start_custom_style', '', 'Enter CSS declarations separated by semicolons');
$row1->addChild('page_page_title_separator_start_custom_style', $page_page_title_separator_start_custom_style);

$page_page_title_separator_animations_data_end = new ElatedMooseGroup('Scrolling Animation End Point', 'These are properties for the last keyframe in scrolling animation');
$page_page_title_separator_animations_container->addChild('page_page_title_separator_animations_data_end', $page_page_title_separator_animations_data_end);

$row2 = new ElatedMooseRow();
$page_page_title_separator_animations_data_end->addChild('row2', $row2);

$page_page_title_separator_data_end = new ElatedMooseMetaField('textsimple', 'page_page_title_separator_data_end', '', 'Scrollbar Top Distance (px)');
$row2->addChild('page_page_title_separator_data_end', $page_page_title_separator_data_end);

$page_page_title_separator_end_custom_style = new ElatedMooseMetaField('textareasimple', 'page_page_title_separator_end_custom_style', '', 'Enter CSS declarations separated by semicolons');
$row2->addChild('page_page_title_separator_end_custom_style', $page_page_title_separator_end_custom_style);

//Subtitle Animations
$page_page_subtitle_animations = new ElatedMooseMetaField('selectblank', 'page_page_subtitle_animations', '', 'Enable Page Subtitle Animations', 'This option will enable Page Subtitle Scroll Animations',
	array(
		'no' => 'No',
		'yes' => 'Yes'
	),
	array(
		'dependence' => true,
		'hide' => array(
			'' => '#eltdf_page_page_subtitle_animations_container',
			'no' => '#eltdf_page_page_subtitle_animations_container'
		),
		'show' => array(
			'yes' => '#eltdf_page_page_subtitle_animations_container'
		)
	));
$eltdTitleAnimations->addChild('page_page_subtitle_animations', $page_page_subtitle_animations);

$page_page_subtitle_animations_container = new ElatedMooseContainer('page_page_subtitle_animations_container', 'page_page_subtitle_animations', '', array('', 'no'));
$eltdTitleAnimations->addChild('page_page_subtitle_animations_container', $page_page_subtitle_animations_container);

$page_page_subtitle_animations_data_start = new ElatedMooseGroup('Scrolling Animation Start Point', 'These are properties for the first keyframe in scrolling animation');
$page_page_subtitle_animations_container->addChild('page_page_subtitle_animations_data_start', $page_page_subtitle_animations_data_start);

$row1 = new ElatedMooseRow();
$page_page_subtitle_animations_data_start->addChild('row1', $row1);

$page_page_subtitle_data_start = new ElatedMooseMetaField('textsimple', 'page_page_subtitle_data_start', '', 'Scrollbar Top Distance (px)');
$row1->addChild('page_page_subtitle_data_start', $page_page_subtitle_data_start);

$page_page_subtitle_start_custom_style = new ElatedMooseMetaField('textareasimple', 'page_page_subtitle_start_custom_style', '', 'Enter CSS declarations separated by semicolons');
$row1->addChild('page_page_subtitle_start_custom_style', $page_page_subtitle_start_custom_style);

$page_page_subtitle_animations_data_end = new ElatedMooseGroup('Scrolling Animation End Point', 'These are properties for the last keyframe in scrolling animation');
$page_page_subtitle_animations_container->addChild('page_page_subtitle_animations_data_end', $page_page_subtitle_animations_data_end);

$row2 = new ElatedMooseRow();
$page_page_subtitle_animations_data_end->addChild('row2', $row2);

$page_page_subtitle_data_end = new ElatedMooseMetaField('textsimple', 'page_page_subtitle_data_end', '', 'Scrollbar Top Distance (px)');
$row2->addChild('page_page_subtitle_data_end', $page_page_subtitle_data_end);

$page_page_subtitle_end_custom_style = new ElatedMooseMetaField('textareasimple', 'page_page_subtitle_end_custom_style', '', 'Enter CSS declarations separated by semicolons');
$row2->addChild('page_page_subtitle_end_custom_style', $page_page_subtitle_end_custom_style);

//Graphic Animations
$page_page_title_graphic_animations = new ElatedMooseMetaField('selectblank', 'page_page_title_graphic_animations', '', 'Enable Page Title Graphic Animations', 'This option will enable Page Title Graphic Scroll Animations',
	array(
		'no' => 'No',
		'yes' => 'Yes'
	),
	array(
		'dependence' => true,
		'hide' => array(
			'' => '#eltdf_page_page_title_graphic_animations_container',
			'no' => '#eltdf_page_page_title_graphic_animations_container'
		),
		'show' => array(
			'yes' => '#eltdf_page_page_title_graphic_animations_container'
		)
	));
$eltdTitleAnimations->addChild('page_page_title_graphic_animations', $page_page_title_graphic_animations);

$page_page_title_graphic_animations_container = new ElatedMooseContainer('page_page_title_graphic_animations_container', 'page_page_title_graphic_animations', '', array('', 'no'));
$eltdTitleAnimations->addChild('page_page_title_graphic_animations_container', $page_page_title_graphic_animations_container);

$page_page_title_graphic_animations_data_start = new ElatedMooseGroup('Scrolling Animation Start Point', 'These are properties for the first keyframe in scrolling animation');
$page_page_title_graphic_animations_container->addChild('page_page_title_graphic_animations_data_start', $page_page_title_graphic_animations_data_start);

$row1 = new ElatedMooseRow();
$page_page_title_graphic_animations_data_start->addChild('row1', $row1);

$page_page_title_graphic_data_start = new ElatedMooseMetaField('textsimple', 'page_page_title_graphic_data_start', '', 'Scrollbar Top Distance (px)');
$row1->addChild('page_page_title_graphic_data_start', $page_page_title_graphic_data_start);

$page_page_title_graphic_start_custom_style = new ElatedMooseMetaField('textareasimple', 'page_page_title_graphic_start_custom_style', '', 'Enter CSS declarations separated by semicolons');
$row1->addChild('page_page_title_graphic_start_custom_style', $page_page_title_graphic_start_custom_style);

$page_page_title_graphic_animations_data_end = new ElatedMooseGroup('Scrolling Animation End Point', 'These are properties for the last keyframe in scrolling animation');
$page_page_title_graphic_animations_container->addChild('page_page_title_graphic_animations_data_end', $page_page_title_graphic_animations_data_end);

$row2 = new ElatedMooseRow();
$page_page_title_graphic_animations_data_end->addChild('row2', $row2);

$page_page_title_graphic_data_end = new ElatedMooseMetaField('textsimple', 'page_page_title_graphic_data_end', '', 'Scrollbar Top Distance (px)');
$row2->addChild('page_page_title_graphic_data_end', $page_page_title_graphic_data_end);

$page_page_title_graphic_end_custom_style = new ElatedMooseMetaField('textareasimple', 'page_page_title_graphic_end_custom_style', '', 'Enter CSS declarations separated by semicolons');
$row2->addChild('page_page_title_graphic_end_custom_style', $page_page_title_graphic_end_custom_style);

//Breadcrumb animations
$animation_page_page_title_breadcrumbs_container = new ElatedMooseContainerNoStyle('animation_page_page_title_breadcrumbs_container', 'eltd_enable_breadcrumbs', 'no');
$eltdTitleAnimations->addChild('animation_page_page_title_breadcrumbs_container', $animation_page_page_title_breadcrumbs_container);

$page_page_title_breadcrumbs_animations = new ElatedMooseMetaField('selectblank', 'page_page_title_breadcrumbs_animations', '', 'Enable Page Title Breadcrumbs Animations', 'This option will enable Page Title Breadcrumbs Scroll Animations',
	array(
		'no' => 'No',
		'yes' => 'Yes'
	),
	array(
		'dependence' => true,
		'hide' => array(
			'' => '#eltdf_page_page_title_breadcrumbs_animations_container',
			'no' => '#eltdf_page_page_title_breadcrumbs_animations_container'
		),
		'show' => array(
			'yes' => '#eltdf_page_page_title_breadcrumbs_animations_container'
		)
	));
$animation_page_page_title_breadcrumbs_container->addChild('page_page_title_breadcrumbs_animations', $page_page_title_breadcrumbs_animations);

$page_page_title_breadcrumbs_animations_container = new ElatedMooseContainer('page_page_title_breadcrumbs_animations_container', 'page_page_title_breadcrumbs_animations', '', array('', 'no'));
$animation_page_page_title_breadcrumbs_container->addChild('page_page_title_breadcrumbs_animations_container', $page_page_title_breadcrumbs_animations_container);

$page_page_title_breadcrumbs_animations_data_start = new ElatedMooseGroup('Scrolling Animation Start Point', 'These are properties for the first keyframe in scrolling animation');
$page_page_title_breadcrumbs_animations_container->addChild('page_page_title_breadcrumbs_animations_data_start', $page_page_title_breadcrumbs_animations_data_start);

$row1 = new ElatedMooseRow();
$page_page_title_breadcrumbs_animations_data_start->addChild('row1', $row1);

$page_page_title_breadcrumbs_data_start = new ElatedMooseMetaField('textsimple', 'page_page_title_breadcrumbs_data_start', '', 'Scrollbar Top Distance (px)');
$row1->addChild('page_page_title_breadcrumbs_data_start', $page_page_title_breadcrumbs_data_start);

$page_page_title_breadcrumbs_start_custom_style = new ElatedMooseMetaField('textareasimple', 'page_page_title_breadcrumbs_start_custom_style', '', 'Enter CSS declarations separated by semicolons');
$row1->addChild('page_page_title_breadcrumbs_start_custom_style', $page_page_title_breadcrumbs_start_custom_style);

$page_page_title_breadcrumbs_animations_data_end = new ElatedMooseGroup('Scrolling Animation End Point', 'These are properties for the last keyframe in scrolling animation');
$page_page_title_breadcrumbs_animations_container->addChild('page_page_title_breadcrumbs_animations_data_end', $page_page_title_breadcrumbs_animations_data_end);

$row2 = new ElatedMooseRow();
$page_page_title_breadcrumbs_animations_data_end->addChild('row2', $row2);

$page_page_title_breadcrumbs_data_end = new ElatedMooseMetaField('textsimple', 'page_page_title_breadcrumbs_data_end', '', 'Scrollbar Top Distance (px)');
$row2->addChild('page_page_title_breadcrumbs_data_end', $page_page_title_breadcrumbs_data_end);

$page_page_title_breadcrumbs_end_custom_style = new ElatedMooseMetaField('textareasimple', 'page_page_title_breadcrumbs_end_custom_style', '', 'Enter CSS declarations separated by semicolons');
$row2->addChild('page_page_title_breadcrumbs_end_custom_style', $page_page_title_breadcrumbs_end_custom_style);




// Content Bottom

$eltdContentBottom = new ElatedMooseMetaBox("portfolio_page", "Content Bottom");
$eltdFramework->eltdMetaBoxes->addMetaBox("portfolio_content_bottom_page",$eltdContentBottom);

	$eltd_enable_content_bottom_area = new ElatedMooseMetaField("selectblank","eltd_enable_content_bottom_area","","Show Content Bottom Area","Do you want to show content bottom area?", array(
       "no" => "No",
       "yes" => "Yes"
      ),
      array("dependence" => true,
      	"hide" => array(
      		"no"=>"#eltdf_eltd_enable_content_bottom_area_container",
			""=>"#eltdf_eltd_enable_content_bottom_area_container"),
      	"show" => array(
      		"yes"=>"#eltdf_eltd_enable_content_bottom_area_container") ));
	$eltdContentBottom->addChild("eltd_enable_content_bottom_area",$eltd_enable_content_bottom_area);
	
	$eltd_enable_content_bottom_area_container = new ElatedMooseContainer("eltd_enable_content_bottom_area_container","eltd_enable_content_bottom_area","no",array("", "no"));
	$eltdContentBottom->addChild("eltd_enable_content_bottom_area_container",$eltd_enable_content_bottom_area_container);

		$eltd_content_bottom_background_color = new ElatedMooseMetaField("color","eltd_content_bottom_background_color","","Background Color","Choose a color for content bottom area");
		$eltd_enable_content_bottom_area_container->addChild("eltd_content_bottom_background_color",$eltd_content_bottom_background_color);
	
		$eltd_choose_content_bottom_sidebar = new ElatedMooseMetaField("selectblank","eltd_choose_content_bottom_sidebar","","Custom Widget","Choose Custom Widget area to display",$eltd_custom_sidebars);
		$eltd_enable_content_bottom_area_container->addChild("eltd_choose_content_bottom_sidebar",$eltd_choose_content_bottom_sidebar);
	
		$eltd_content_bottom_sidebar_in_grid = new ElatedMooseMetaField("selectblank","eltd_content_bottom_sidebar_in_grid","","Display in Grid","Enabling this option will place Content Bottom in grid",array(
	       "no" => "No",
	       "yes" => "Yes"
	      ));
		$eltd_enable_content_bottom_area_container->addChild("eltd_content_bottom_sidebar_in_grid",$eltd_content_bottom_sidebar_in_grid);

// Side Bar Area

$eltdSideBar = new ElatedMooseMetaBox("portfolio_page", "Sidebar");
$eltdFramework->eltdMetaBoxes->addMetaBox("portfolio_side_bar",$eltdSideBar);

	$eltd_show_sidebar = new ElatedMooseMetaField("selectblank","eltd_portfolio_show_sidebar","default","Layout","Choose the sidebar layout",array( "default" => "Default",
       "1" => "Sidebar 1/3 right",
       "2" => "Sidebar 1/4 right",
       "3" => "Sidebar 1/3 left",
       "4" => "Sidebar 1/4 left",
      ));
	$eltdSideBar->addChild("eltd_portfolio_show_sidebar",$eltd_show_sidebar);

	$eltd_choose_sidebar = new ElatedMooseMetaField("selectblank","eltd_choose-sidebar","default","Choose Widget Area in Sidebar","Choose Custom Widget area to display in Sidebar", $eltd_custom_sidebars);
	$eltdSideBar->addChild("eltd_choose-sidebar",$eltd_choose_sidebar);

// Footer

$eltdFooter = new ElatedMooseMetaBox("portfolio_page", "Footer");
$eltdFramework->eltdMetaBoxes->addMetaBox("portfolio_footer",$eltdFooter);

    $eltd_footer_disable = new ElatedMooseMetaField("yesno","eltd_footer-disable","no","Disable Footer for this Page",
        "Enabling this option will hide footer on your page");
    $eltdFooter->addChild("eltd_footer-disable",$eltd_footer_disable);


// SEO

$eltdSeo = new ElatedMooseMetaBox("portfolio_page", "SEO");
$eltdFramework->eltdMetaBoxes->addMetaBox("portfolio_seo",$eltdSeo);

	$seo_title = new ElatedMooseMetaField("text","eltd_seo_title","","SEO Title","Enter custom Title for this page");
	$eltdSeo->addChild("eltd_seo_title",$seo_title);

	$seo_keywords = new ElatedMooseMetaField("text","eltd_seo_keywords","","SEO Keywords","Enter the list of keywords separated by commas");
	$eltdSeo->addChild("eltd_seo_keywords",$seo_keywords);

	$seo_description = new ElatedMooseMetaField("textarea","eltd_seo_description","","SEO Description","Enter meta description for this page");
	$eltdSeo->addChild("eltd_seo_description",$seo_description);