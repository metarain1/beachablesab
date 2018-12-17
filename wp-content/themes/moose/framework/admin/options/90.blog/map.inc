<?php

$blogPage = new ElatedMooseAdminPage("8", "Blog", "fa fa-files-o");
$eltdFramework->eltdOptions->addAdminPage("blogPage",$blogPage);

// Blog Post Lists - General

$panel1 = new ElatedMoosePanel("Blog Lists","post_lists_general_panel");
$blogPage->addChild("panel1",$panel1);

$blog_style = new ElatedMooseField("select","blog_style","1","Archive and Category Layout","Choose a default blog layout for archived Blog Post Lists and Category Blog Lists", array(
	"1"	=> "Blog: Standard",
	"2"	=> "Blog: Split Column",
	"3" => "Blog: Masonry",
	"4" => "Blog: Masonry Full Width",
	"9" => "Blog: Standard Whole Post",
	"14" => "Blog: Masonry Gallery",
	"15" => "Blog: Masonry Gallery Full Width"
));
$panel1->addChild("blog_style",$blog_style);

$category_blog_sidebar = new ElatedMooseField("select","category_blog_sidebar","default","Archive and Category Sidebar","Choose a sidebar layout for archived Blog Post Lists and Category Blog Lists", array(
	"default" => "No Sidebar",
	"1" => "Sidebar 1/3 right",
	"2" => "Sidebar 1/4 right",
	"3" => "Sidebar 1/3 left",
	"4" => "Sidebar 1/4 left"
));
$panel1->addChild("category_blog_sidebar",$category_blog_sidebar);

$pagination = new ElatedMooseField("yesno","pagination","yes","Pagination","Enabling this option will display pagination links on bottom of Blog Post List", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_hide_pagination_list_container"));
$panel1->addChild("pagination",$pagination);

$blog_hide_pagination_list_container = new ElatedMooseContainer("blog_hide_pagination_list_container","pagination","");
$panel1->addChild("blog_hide_pagination_list_container",$blog_hide_pagination_list_container);

$blog_pagination_type = new ElatedMooseField("select","blog_pagination_type","standard","Pagination type","Choose type of pagination",array(
	"standard" => "Standard",
	"prev_and_next" => "Only Previous and Next"
	),array(
	"dependence" => true,
	"hide" => array("prev_and_next" => "#eltdf_blog_page_range_container", "standard" => "#eltdf_blog_pagination_text_container"),
	"show" => array("standard" => "#eltdf_blog_page_range_container", "prev_and_next" => "#eltdf_blog_pagination_text_container")
	));
$blog_hide_pagination_list_container->addChild("blog_pagination_type",$blog_pagination_type);

$blog_page_range_container = new ElatedMooseContainer("blog_page_range_container","blog_pagination_type","prev_and_next");
$blog_hide_pagination_list_container->addChild("blog_page_range_container",$blog_page_range_container);

	$blog_page_range = new ElatedMooseField("text","blog_page_range","","Pagination Range limit","Enter a number that will limit pagination to a certain range of links",array(), array("col_width" => 3));
	$blog_page_range_container->addChild("blog_page_range",$blog_page_range);

$blog_pagination_text_container = new ElatedMooseContainer("blog_pagination_text_container","blog_pagination_type","standard");
$blog_hide_pagination_list_container->addChild("blog_pagination_text_container",$blog_pagination_text_container);

	$group17 = new ElatedMooseGroup("Labels for Buttons","Enter labels you want for Previous and Next buttons (Previous and Next are standard labels)");
	$blog_pagination_text_container->addChild("group17",$group17);

		$row1 = new ElatedMooseRow();
		$group17->addChild("row1",$row1);

			$blog_pagination_previous_label = new ElatedMooseField("textsimple","blog_pagination_previous_label","","Previous Label","This is some description");
			$row1->addChild("blog_pagination_previous_label",$blog_pagination_previous_label);

			$blog_pagination_next_label = new ElatedMooseField("textsimple","blog_pagination_next_label","","Next Label","This is some description");
			$row1->addChild("blog_pagination_next_label",$blog_pagination_next_label);

$blog_pagination_border_above_yesno = new ElatedMooseField("yesno","blog_pagination_border_above_yesno","no","Border Above Pagination","Enabling this option will display border above pagination",array(),array(
	"dependence" => true,
	"dependence_show_on_yes" => "#eltdf_blog_pagination_border_container"
	));
$blog_page_range_container->addChild("blog_pagination_border_above_yesno",$blog_pagination_border_above_yesno);

$blog_pagination_border_container = new ElatedMooseContainer("blog_pagination_border_container","blog_pagination_border_above_yesno","no");
$blog_page_range_container->addChild("blog_pagination_border_container",$blog_pagination_border_container);

	$group18 = new ElatedMooseGroup("Border Style","Define style for border top on pagination");
	$blog_pagination_border_container->addChild("group18",$group18);

		$row1 = new ElatedMooseRow();
		$group18->addChild("row1",$row1);

			$blog_pgn_border_color = new ElatedMooseField("colorsimple","blog_pgn_border_color","","Color","This is some description");
			$row1->addChild("blog_pgn_border_color",$blog_pgn_border_color);

			$blog_pgn_border_width = new ElatedMooseField("textsimple","blog_pgn_border_width","","Width (px)","This is some description");
			$row1->addChild("blog_pgn_border_width",$blog_pgn_border_width);

			$blog_pgn_border_style = new ElatedMooseField("selectsimple","blog_pgn_border_style","","Style","This is some description",array(
				"solid" => "Solid",
				"dotted" => "Dotted",
				"dashed" => "Dashed"
				));
			$row1->addChild("blog_pgn_border_style",$blog_pgn_border_style);

	$blog_pagination_border_margin = new ElatedMooseField("text","blog_pagination_border_margin","","Margin from Border (px)","Set margin from border to pagination buttons",array(),array("col_width" => 3));
	$blog_pagination_border_container->addChild("blog_pagination_border_margin",$blog_pagination_border_margin);

$number_of_chars = new ElatedMooseField("text","number_of_chars","45","Number of Words in Excerpt",' Enter a number of words in excerpt (article summary)', array(), array("col_width" => 3));
$panel1->addChild("number_of_chars",$number_of_chars);

// Blog Single

$panel20 = new ElatedMoosePanel("Blog Single", "blog_single_panel");
$blogPage->addChild("panel20",$panel20);

$blog_single_sidebar = new ElatedMooseField("select","blog_single_sidebar","default","Sidebar Layout","Choose a sidebar layout for Blog Single pages", array(
	"default" => "No Sidebar",
	"1" => "Sidebar 1/3 right",
	"2" => "Sidebar 1/4 right",
	"3" => "Sidebar 1/3 left",
	"4" => "Sidebar 1/4 left"
));
$panel20->addChild("blog_single_sidebar",$blog_single_sidebar);

$custom_sidebars = eltd_moose_get_custom_sidebars();

$blog_single_sidebar_custom_display = new ElatedMooseField("selectblank","blog_single_sidebar_custom_display","","Sidebar to Display","Choose a sidebar to display on Blog Single pages", $custom_sidebars);
$panel20->addChild("blog_single_sidebar_custom_display",$blog_single_sidebar_custom_display);

$blog_single_image_size = new ElatedMooseField("select","blog_single_image_size","full","Blog Image Size","Choose image size for Blog Single pages", array(
    "full" => "Default",
    "portfolio-landscape" => "Landscape",
    "portfolio-portrait" => "Portrait",
    "custom" => "Custom"
),
    array("dependence" => true,
        "hide" => array(
            "full"=>"#eltdf_blog_single_image_size_container",
            "portfolio-landscape"=>"#eltdf_blog_single_image_size_container",
            "portfolio-portrait"=>"#eltdf_blog_single_image_size_container",
            "custom"=>""
        ),
        "show" => array(
            "full"=>"",
            "portfolio-landscape"=>"",
            "portfolio-portrait"=>"",
            "custom"=>"#eltdf_blog_single_image_size_container"
        )
    )
);
$panel20->addChild("blog_single_image_size",$blog_single_image_size);

$blog_single_image_size_container = new ElatedMooseContainer("blog_single_image_size_container","blog_single_image_size","", array( "full","portfolio-landscape","portfolio-portrait"));
$panel20->addChild("blog_single_image_size_container",$blog_single_image_size_container);

$blog_single_image_size_height = new ElatedMooseField("text","blog_single_image_size_height","","Image Height (px)","Enter width (in pixels) for Custom Image for Blog Single", array(), array("col_width" => 3));
$blog_single_image_size_container->addChild("blog_single_image_size_height",$blog_single_image_size_height);

$blog_single_image_size_width = new ElatedMooseField("text","blog_single_image_size_width","","Image Width (px)","Enter width (in pixels) for Custom Image for Blog Single", array(), array("col_width" => 3));
$blog_single_image_size_container->addChild("blog_single_image_size_width",$blog_single_image_size_width);

$blog_single_show_ql_icon = new ElatedMooseField("yesno","blog_single_show_ql_icon","yes","Enable Quote/Link Icon","Enabling this option will show Quote/Link Icon on Blog Single posts");
$panel20->addChild("blog_single_show_ql_icon",$blog_single_show_ql_icon);

$blog_single_navigation = new ElatedMooseField("yesno","blog_single_navigation","no","Enable Prev/Next Single Post Navigation Links","Enable navigation links through the blog posts (left and right arrows will appear)", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_hide_pagination_container"));
$panel20->addChild("blog_single_navigation",$blog_single_navigation);

$blog_hide_pagination_container = new ElatedMooseContainer("blog_hide_pagination_container","blog_single_navigation","no");
$panel20->addChild("blog_hide_pagination_container",$blog_hide_pagination_container);

$blog_navigation_through_same_category = new ElatedMooseField("yesno","blog_navigation_through_same_category","no","Enable Navigation Only in Current Category","Limit your navigation only through current category");
$blog_hide_pagination_container->addChild("blog_navigation_through_same_category",$blog_navigation_through_same_category);

$blog_single_title_tags = new ElatedMooseField("select","blog_single_title_tags","h5","Headlines Below Post Content",'Choose a tag for headlines below post content ("Tags", "Post a comment", etc)', array(
	"h2" => "h2",
	"h3" => "h3",
	"h4" => "h4",
	"h5" => "h5",
	"h6" => "h6"
));
$panel20->addChild("blog_single_title_tags",$blog_single_title_tags);

$post_info_data_single = new ElatedMooseTitle("post_info_data_single", "Post Info Data Fields");
$panel20->addChild("post_info_data_single", $post_info_data_single);

$blog_single_show_date = new ElatedMooseField("yesno","blog_single_show_date","yes","Show Date","Enabling this option will show date on Blog Single posts");
$panel20->addChild("blog_single_show_date",$blog_single_show_date);

$blog_single_show_like = new ElatedMooseField("yesno","blog_single_show_like","yes","Show Like","Enabling this option will turn on 'Likes' on Blog Single posts");
$panel20->addChild("blog_single_show_like",$blog_single_show_like);

$blog_single_show_social_share = new ElatedMooseField("yesno","blog_single_show_social_share","yes","Show Share","Enabling this option will show share on Single Post", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_single_share_options_container"));
$panel20->addChild("blog_single_show_social_share",$blog_single_show_social_share);

$blog_single_share_options_container = new ElatedMooseContainer("blog_single_share_options_container","blog_single_show_social_share","no");
$panel20->addChild("blog_single_share_options_container",$blog_single_share_options_container);

$blog_single_select_share_option = new ElatedMooseField("select","blog_single_select_share_option","dropdown","Social Share Style","Choose Social Share Style for Single Post",array(
	"dropdown" => "Social Share Dropdown",
	"list" => "Social Share List"
));

$blog_single_share_options_container->addChild("blog_single_select_share_option",$blog_single_select_share_option);

$blog_single_show_category = new ElatedMooseField("yesno","blog_single_show_category","yes","Show Category","Enabling this option will show category/categories on Blog Single posts");
$panel20->addChild("blog_single_show_category",$blog_single_show_category);

$blog_single_show_time = new ElatedMooseField("yesno","blog_single_show_time","yes","Show Time","Enabling this option will show time on Blog Single posts for Meta Info Featured on Side Template","",array("blog_standard_type","blog_date_in_title","blog_post_info_hierarchical","blog_split_column", "blog_masonry"));
$panel20->addChild("blog_single_show_time",$blog_single_show_time);

$blog_author_info = new ElatedMooseField("yesno","blog_author_info","yes","Show Author Info","Enabling this option will display author name and descriptions on Blog Single pages", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_enable_blog_author_info_container"));
$panel20->addChild("blog_author_info",$blog_author_info);

$enable_blog_author_info_container = new ElatedMooseContainer("enable_blog_author_info_container","blog_author_info","no");
$panel20->addChild("enable_blog_author_info_container",$enable_blog_author_info_container);

$enable_author_info_email = new ElatedMooseField("yesno","enable_author_info_email","no","Show Author Email","Enabling this option will show author email");
$enable_blog_author_info_container->addChild("enable_author_info_email",$enable_author_info_email);

$group1 = new ElatedMooseGroup("Blog Single Author Info Box Style","Set styles for author info box on single post pages");
$enable_blog_author_info_container->addChild("group1",$group1);

$row1 = new ElatedMooseRow();
$group1->addChild("row1",$row1);

$blog_single_post_author_info_border_color = new ElatedMooseField("colorsimple","blog_single_post_author_info_border_color","","Border Color","This is some description");
$row1->addChild("blog_single_post_author_info_border_color",$blog_single_post_author_info_border_color);

$blog_single_post_author_info_back_color = new ElatedMooseField("colorsimple","blog_single_post_author_info_back_color","","Background Color","This is some description");
$row1->addChild("blog_single_post_author_info_back_color",$blog_single_post_author_info_back_color);


$group2 = new ElatedMooseGroup("Blog Single Author Info Title Style","Set styles for author info title on single post pages");
$enable_blog_author_info_container->addChild("group2",$group2);	
		
$row1 = new ElatedMooseRow();
$group2->addChild("row1",$row1);
	
$blog_single_post_author_info_title_color = new ElatedMooseField("colorsimple","blog_single_post_author_info_title_color","","Text Color","This is some description");
$row1->addChild("blog_single_post_author_info_title_color",$blog_single_post_author_info_title_color);
			
$blog_single_post_author_info_title_font_family = new ElatedMooseField("fontsimple","blog_single_post_author_info_title_font_family","-1","Font Family","This is some description");
$row1->addChild("blog_single_post_author_info_title_font_family",$blog_single_post_author_info_title_font_family);

$blog_single_post_author_info_title_fontsize = new ElatedMooseField("textsimple","blog_single_post_author_info_title_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_single_post_author_info_title_fontsize",$blog_single_post_author_info_title_fontsize);

$blog_single_post_author_info_title_lineheight = new ElatedMooseField("textsimple","blog_single_post_author_info_title_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_single_post_author_info_title_lineheight",$blog_single_post_author_info_title_lineheight);

$row2 = new ElatedMooseRow(true);
$group2->addChild("row2",$row2);			

$blog_single_post_author_info_title_fontstyle = new ElatedMooseField("selectblanksimple","blog_single_post_author_info_title_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_single_post_author_info_title_fontstyle",$blog_single_post_author_info_title_fontstyle);

$blog_single_post_author_info_title_fontweight = new ElatedMooseField("selectblanksimple","blog_single_post_author_info_title_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_single_post_author_info_title_fontweight",$blog_single_post_author_info_title_fontweight);

$blog_single_post_author_info_title_texttransform = new ElatedMooseField("selectblanksimple","blog_single_post_author_info_title_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_single_post_author_info_title_texttransform",$blog_single_post_author_info_title_texttransform);

$blog_single_post_author_info_title_letterspacing = new ElatedMooseField("textsimple","blog_single_post_author_info_title_letterspacing","","Letter Spacing (px)","This is some description");
$row2->addChild("blog_single_post_author_info_title_letterspacing",$blog_single_post_author_info_title_letterspacing);
			
$row3 = new ElatedMooseRow();
$group2->addChild("row3",$row3);
		
$blog_single_post_author_info_title_margin_bottom = new ElatedMooseField("textsimple","blog_single_post_author_info_title_margin_bottom","","Margin Bottom for Author Info Title (px)","This is some description");
$row3->addChild("blog_single_post_author_info_title_margin_bottom",$blog_single_post_author_info_title_margin_bottom);
	
$group3 = new ElatedMooseGroup("Blog Single Author Info Text Style","Set styles for author info text on single post pages");
$enable_blog_author_info_container->addChild("group3",$group3);	
		
$row1 = new ElatedMooseRow();
$group3->addChild("row1",$row1);
	
$blog_single_post_author_info_text_color = new ElatedMooseField("colorsimple","blog_single_post_author_info_text_color","","Text Color","This is some description");
$row1->addChild("blog_single_post_author_info_text_color",$blog_single_post_author_info_text_color);
			
$blog_single_post_author_info_text_font_family = new ElatedMooseField("fontsimple","blog_single_post_author_info_text_font_family","-1","Font Family","This is some description");
$row1->addChild("blog_single_post_author_info_text_font_family",$blog_single_post_author_info_text_font_family);

$blog_single_post_author_info_text_fontsize = new ElatedMooseField("textsimple","blog_single_post_author_info_text_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_single_post_author_info_text_fontsize",$blog_single_post_author_info_text_fontsize);

$blog_single_post_author_info_text_lineheight = new ElatedMooseField("textsimple","blog_single_post_author_info_text_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_single_post_author_info_text_lineheight",$blog_single_post_author_info_text_lineheight);

$row2 = new ElatedMooseRow(true);
$group3->addChild("row2",$row2);			

$blog_single_post_author_info_text_fontstyle = new ElatedMooseField("selectblanksimple","blog_single_post_author_info_text_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_single_post_author_info_text_fontstyle",$blog_single_post_author_info_text_fontstyle);

$blog_single_post_author_info_text_fontweight = new ElatedMooseField("selectblanksimple","blog_single_post_author_info_text_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_single_post_author_info_text_fontweight",$blog_single_post_author_info_text_fontweight);

$blog_single_post_author_info_text_texttransform = new ElatedMooseField("selectblanksimple","blog_single_post_author_info_text_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_single_post_author_info_text_texttransform",$blog_single_post_author_info_text_texttransform);

$blog_single_post_author_info_text_letterspacing = new ElatedMooseField("textsimple","blog_single_post_author_info_text_letterspacing","","Letter Spacing (px)","This is some description");
$row2->addChild("blog_single_post_author_info_text_letterspacing",$blog_single_post_author_info_text_letterspacing);

$blog_single_show_comments = new ElatedMooseField("yesno","blog_single_show_comments","yes","Show Comments","Enabling this option will show comments on Blog Single posts", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_enable_blog_comments_container"));
	$panel20->addChild("blog_single_show_comments",$blog_single_show_comments);

	$enable_blog_comments_container = new ElatedMooseContainer("enable_blog_comments_container","blog_single_show_comments","no");
	$panel20->addChild("enable_blog_comments_container",$enable_blog_comments_container);
	
	$group1 = new ElatedMooseGroup("Comments Box Style","Set styles for comments box on single post pages");
	$enable_blog_comments_container->addChild("group1",$group1);

		$row1 = new ElatedMooseRow();
		$group1->addChild("row1",$row1);
			
			$blog_single_post_comments_border_color = new ElatedMooseField("colorsimple","blog_single_post_comments_border_color","","Border Color","This is some description");
			$row1->addChild("blog_single_post_comments_border_color",$blog_single_post_comments_border_color);
			
			$blog_single_post_comments_back_color = new ElatedMooseField("colorsimple","blog_single_post_comments_back_color","","Background Color","This is some description");
			$row1->addChild("blog_single_post_comments_back_color",$blog_single_post_comments_back_color);
	
	$group2 = new ElatedMooseGroup("Comments Color Style","Set styles for comments on single post pages");
	$enable_blog_comments_container->addChild("group2",$group2);
		
		$row1 = new ElatedMooseRow();
		$group2->addChild("row1",$row1);
	
			$blog_single_post_comments_title_color = new ElatedMooseField("colorsimple","blog_single_post_comments_title_color","","Title Color","This is some description");
			$row1->addChild("blog_single_post_comments_title_color",$blog_single_post_comments_title_color);
			
			$blog_single_post_comments_text_color = new ElatedMooseField("colorsimple","blog_single_post_comments_text_color","","Text Color","This is some description");
			$row1->addChild("blog_single_post_comments_text_color",$blog_single_post_comments_text_color);
			
			$blog_single_post_comments_link_color = new ElatedMooseField("colorsimple","blog_single_post_comments_link_color","","Link Color","This is some description");
			$row1->addChild("blog_single_post_comments_link_color",$blog_single_post_comments_link_color);	
			
			$blog_single_post_comments_date_color = new ElatedMooseField("colorsimple","blog_single_post_comments_date_color","","Date Color","This is some description");
			$row1->addChild("blog_single_post_comments_date_color",$blog_single_post_comments_date_color);				
	
// Advanced Options

$panel_advanced_options = new ElatedMoosePanel("Advanced Options","panel_advanced_options");
$blogPage->addChild("panel_advanced_options",$panel_advanced_options);

$blog_standard_type_show_options = new ElatedMooseField("yesno","blog_standard_type_show_options","no","Show Standard Template Options","Editing these options will have affect on Post List & Single Post", array(),
	array("dependence" => true,
		"dependence_hide_on_yes" => "",
		"dependence_show_on_yes" => "#eltdf_blog_standard_type_post_lists"));
$panel_advanced_options->addChild("blog_standard_type_show_options",$blog_standard_type_show_options);

$blog_split_column_show_options = new ElatedMooseField("yesno","blog_split_column_show_options","no","Show Split Column Template Options","Editing these options will have affect on Post List & Single Post", array(),
	array("dependence" => true,
		"dependence_hide_on_yes" => "",
		"dependence_show_on_yes" => "#eltdf_blog_split_column_post_lists"));
$panel_advanced_options->addChild("blog_split_column_show_options",$blog_split_column_show_options);

$blog_masonry_show_options = new ElatedMooseField("yesno","blog_masonry_show_options","no","Show Masonry & Masonry Full Width Template Options","Editing these options will have affect on Post List & Single Post", array(),
	array("dependence" => true,
		"dependence_hide_on_yes" => "",
		"dependence_show_on_yes" => "#eltdf_blog_masonry_post_lists"));
$panel_advanced_options->addChild("blog_masonry_show_options", $blog_masonry_show_options);

$blog_masonry_gallery_show_options = new ElatedMooseField("yesno","blog_masonry_gallery_show_options","no","Show Masonry Gallery and Masonry Gallery Full Width Template Options","Editing these options will have affect on Post List & Single Post", array(),
    array("dependence" => true,
        "dependence_hide_on_yes" => "",
        "dependence_show_on_yes" => "#eltdf_blog_masonry_gallery_post_lists"));
$panel_advanced_options->addChild("blog_masonry_gallery_show_options", $blog_masonry_gallery_show_options);

$blog_vertical_loop_show_options = new ElatedMooseField("yesno","blog_vertical_loop_show_options","no","Show Vertical Loop Template Options","Editing these options will have affect on Post List & Single Post", array(),
	array("dependence" => true,
		"dependence_hide_on_yes" => "",
		"dependence_show_on_yes" => "#eltdf_blog_vertical_loop_post_lists"));
$panel_advanced_options->addChild("blog_vertical_loop_show_options",$blog_vertical_loop_show_options);

// Blog Post List - Blog: Masonry
$panel10 = new ElatedMoosePanel("Blog List Templates Options: Masonry & Masonry Full Width","blog_masonry_post_lists", "blog_masonry_show_options", "no");
$blogPage->addChild("panel10",$panel10);


$blog_masonry_number_of_chars = new ElatedMooseField("text","blog_masonry_number_of_chars","45","Number of Words in Excerpt",' Enter a number of words in excerpt (article summary)', array(), array("col_width" => 3));
$panel10->addChild("blog_masonry_number_of_chars",$blog_masonry_number_of_chars);

$blog_masonry_read_more_button = new ElatedMooseField("yesno","blog_masonry_read_more_button","no","Read More Button","Enable Read More Button", array(),
    array("dependence" => true,
        "dependence_hide_on_yes" => "",
        "dependence_show_on_yes" => "#eltdf_blog_masonry_read_more_button_container"));
$panel10->addChild("blog_masonry_read_more_button",$blog_masonry_read_more_button);

$blog_masonry_read_more_button_container = new ElatedMooseContainer("blog_masonry_read_more_button_container","blog_masonry_read_more_button","no");
$panel10->addChild("blog_masonry_read_more_button_container",$blog_masonry_read_more_button_container);

$blog_masonry_read_more_button_icon = new ElatedMooseField("yesno","blog_masonry_read_more_button_icon","no","Enable Icon","Enabling this option will place icon in read more button", array(),
    array("dependence" => true,
        "dependence_hide_on_yes" => "",
        "dependence_show_on_yes" => "#eltdf_blog_masonry_read_more_button_icon_container"));
$blog_masonry_read_more_button_container->addChild("blog_masonry_read_more_button_icon",$blog_masonry_read_more_button_icon);

$blog_masonry_read_more_button_icon_container = new ElatedMooseContainer("blog_masonry_read_more_button_icon_container","blog_masonry_read_more_button_icon","no");
$blog_masonry_read_more_button_container->addChild("blog_masonry_read_more_button_icon_container",$blog_masonry_read_more_button_icon_container);

//init icon pack hide and show array. It will be populated dinamically from collections array
$blog_masonry_read_more_button_icon_pack_hide_array = array();
$blog_masonry_read_more_button_icon_pack_show_array = array();

//do we have some collection added in collections array?
if(is_array($eltdIconCollections->iconCollections) && count($eltdIconCollections->iconCollections)) {
    //get collections params array. It will contain values of 'param' property for each collection
    $blog_masonry_read_more_button_icon_collections_params = $eltdIconCollections->getIconCollectionsParams();

    //foreach collection generate hide and show array
    foreach ($eltdIconCollections->iconCollections as $dep_collection_key => $dep_collection_object) {
        $blog_masonry_read_more_button_icon_pack_hide_array[$dep_collection_key] = '';

        //we need to include only current collection in show string as it is the only one that needs to show
        $blog_masonry_read_more_button_icon_pack_show_array[$dep_collection_key] = '#eltdf_blog_masonry_read_more_button_icon_'.$dep_collection_object->param.'_container';

        //for all collections param generate hide string
        foreach ($blog_masonry_read_more_button_icon_collections_params as $blog_masonry_read_more_button_icon_collections_param) {
            //we don't need to include current one, because it needs to be shown, not hidden
            if($blog_masonry_read_more_button_icon_collections_param !== $dep_collection_object->param) {
                $blog_masonry_read_more_button_icon_pack_hide_array[$dep_collection_key].= '#eltdf_blog_masonry_read_more_button_icon_'.$blog_masonry_read_more_button_icon_collections_param.'_container,';
            }
        }

        //remove remaining ',' character
        $blog_masonry_read_more_button_icon_pack_hide_array[$dep_collection_key] = rtrim($blog_masonry_read_more_button_icon_pack_hide_array[$dep_collection_key], ',');
    }

}

$blog_masonry_read_more_button_icon_pack = new ElatedMooseField(
    "select",
    "blog_masonry_read_more_button_icon_pack",
    "font_awesome",
    "Icon Pack",
    "Choose icon pack for show load more button",
    $eltdIconCollections->getIconCollections(),
    array(
        "dependence" => true,
        "hide" => $blog_masonry_read_more_button_icon_pack_hide_array,
        "show" => $blog_masonry_read_more_button_icon_pack_show_array
    ));

$blog_masonry_read_more_button_icon_container->addChild("blog_masonry_read_more_button_icon_pack", $blog_masonry_read_more_button_icon_pack);

if(is_array($eltdIconCollections->iconCollections) && count($eltdIconCollections->iconCollections)) {
    //foreach icon collection we need to generate separate container that will have dependency set
    //it will have one field inside with icons dropdown
    foreach ($eltdIconCollections->iconCollections as $collection_key => $collection_object) {
        $icons_array = $collection_object->getIconsArray();

        //get icon collection keys (keys from collections array, e.g 'font_awesome', 'font_elegant' etc.)
        $icon_collections_keys = $eltdIconCollections->getIconCollectionsKeys();

        //unset current one, because it doesn't have to be included in dependency that hides icon container
        unset($icon_collections_keys[array_search($collection_key, $icon_collections_keys)]);

        $blog_masonry_read_more_button_icon_hide_values = $icon_collections_keys;
        $blog_icon_container = new ElatedMooseContainer("blog_masonry_read_more_button_icon_".$collection_object->param."_container", "blog_masonry_read_more_button_icon_pack", "", $blog_masonry_read_more_button_icon_hide_values);
        $blog_masonry_read_more_button_icon = new ElatedMooseField("select", "blog_masonry_read_more_button_icon_".$collection_object->param, "", "Button Icon","Choose Button Icon", $icons_array, array("col_width" => 3));
        $blog_icon_container->addChild("blog_masonry_read_more_button_icon_".$collection_object->param, $blog_masonry_read_more_button_icon);

        $blog_masonry_read_more_button_icon_container->addChild("blog_masonry_read_more_button_icon_".$collection_object->param."_container", $blog_icon_container);
    }

}


$pagination_masonry = new ElatedMooseField("select","pagination_masonry","pagination","Pagination on Masonry",'Choose a pagination style for "Masonry" Blog List', array(
	"pagination" => "Pagination",
	"load_more" => "Load More",
	"infinite_scroll" => "Infinite Scroll"
));
$panel10->addChild("pagination_masonry",$pagination_masonry);

$blog_masonry_columns = new ElatedMooseField('select', 'blog_masonry_columns', '', 'Masonry Blog Columns', 'Choose a number of columns for "Masonry" Blog List without sidebar', array(
	'two_columns' => '2',
	'three_columns' => '3'
));
$panel10->addChild('blog_masonry_columns', $blog_masonry_columns);

$blog_masonry_full_width_columns = new ElatedMooseField('select', 'blog_masonry_full_width_columns', '', 'Full Width Masonry Blog Columns', 'Choose a number of columns for "Masonry" Blog List', array(
	'three_columns' => '3',
	'four_columns' => '4',
	'five_columns' => '5'
));
$panel10->addChild('blog_masonry_full_width_columns', $blog_masonry_full_width_columns);

$blog_masonry_full_width_margin = new ElatedMooseField("text","blog_masonry_full_width_margin","","Full Width Masonry Margin",'Please insert margin in px (i.e. 5px), or in % (i.e 5%)', array(), array("col_width" => 3));
$panel10->addChild("blog_masonry_full_width_margin",$blog_masonry_full_width_margin);

$blog_masonry_filter = new ElatedMooseField("yesno","blog_masonry_filter","no","Show Category Filter on Masonry",'Enabling this option will display a Category Filter on "Masonry" Blog List', array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_masonry_filter_container"));
$panel10->addChild("blog_masonry_filter",$blog_masonry_filter);

$blog_masonry_filter_container = new ElatedMooseContainer("blog_masonry_filter_container","blog_masonry_filter","no");
$panel10->addChild("blog_masonry_filter_container",$blog_masonry_filter_container);


// Blog Masonry Filter
$blog_masonry_filter_background_color = new ElatedMooseField("color","blog_masonry_filter_background_color","","Background Color","Choose color for background of filter area",array(), array("col_width" => 3));
$blog_masonry_filter_container->addChild("blog_masonry_filter_background_color",$blog_masonry_filter_background_color);

$blog_masonry_filter_height = new ElatedMooseField("text","blog_masonry_filter_height","","Height (px)","Enter height for filter area",array(), array("col_width" => 3));
$blog_masonry_filter_container->addChild("blog_masonry_filter_height", $blog_masonry_filter_height);

$blog_masonry_filter_margin_bottom = new ElatedMooseField("text","blog_masonry_filter_margin_bottom","","Bottom Margin (px)","Enter bottom margin for filter area. Default value is 36",array(), array("col_width" => 3));
$blog_masonry_filter_container->addChild("blog_masonry_filter_margin_bottom",$blog_masonry_filter_margin_bottom);

$blog_masonry_filter_alignment = new ElatedMooseField("select","blog_masonry_filter_alignment","","Horizontal Alignment","Choose filter alignment", array(
	"left" => "Left",
	"center" => "Center",
	"right" => "Right"
));
$blog_masonry_filter_container->addChild("blog_masonry_filter_alignment",$blog_masonry_filter_alignment);

$blog_masonry_enable_filter_title = new ElatedMooseField("yesno","blog_masonry_enable_filter_title","no","Enable Filter Title","Enabling this option will show category filter title");
$blog_masonry_filter_container->addChild("blog_masonry_enable_filter_title",$blog_masonry_enable_filter_title);

$group1 = new ElatedMooseGroup("Title","Define text styles for filter title");
$blog_masonry_filter_container->addChild("group1",$group1);

$row1 = new ElatedMooseRow();
$group1->addChild("row1",$row1);
$blog_masonry_filter_title_color = new ElatedMooseField("colorsimple","blog_masonry_filter_title_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_filter_title_color",$blog_masonry_filter_title_color);
$blog_masonry_filter_title_font_size = new ElatedMooseField("textsimple","blog_masonry_filter_title_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_masonry_filter_title_font_size",$blog_masonry_filter_title_font_size);
$blog_masonry_filter_title_line_height = new ElatedMooseField("textsimple","blog_masonry_filter_title_line_height","","Line Height (px)","This is some description");
$row1->addChild("blog_masonry_filter_title_line_height",$blog_masonry_filter_title_line_height);
$blog_masonry_filter_title_text_transform = new ElatedMooseField("selectblanksimple","blog_masonry_filter_title_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row1->addChild("blog_masonry_filter_title_text_transform",$blog_masonry_filter_title_text_transform);

$row2 = new ElatedMooseRow(true);
$group1->addChild("row2",$row2);
$blog_masonry_filter_title_font_family = new ElatedMooseField("fontsimple","blog_masonry_filter_title_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_masonry_filter_title_font_family",$blog_masonry_filter_title_font_family);
$blog_masonry_filter_title_font_style = new ElatedMooseField("selectblanksimple","blog_masonry_filter_title_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_masonry_filter_title_font_style",$blog_masonry_filter_title_font_style);
$blog_masonry_filter_title_font_weight = new ElatedMooseField("selectblanksimple","blog_masonry_filter_title_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_masonry_filter_title_font_weight",$blog_masonry_filter_title_font_weight);
$blog_masonry_filter_title_letter_spacing = new ElatedMooseField("textsimple","blog_masonry_filter_title_letter_spacing","","Letter Spacing (px)","This is some description");
$row2->addChild("blog_masonry_filter_title_letter_spacing",$blog_masonry_filter_title_letter_spacing);

$group2 = new ElatedMooseGroup("Categories","Define text styles for filter categories");
$blog_masonry_filter_container->addChild("group2",$group2);

$row1 = new ElatedMooseRow();
$group2->addChild("row1",$row1);
$blog_masonry_filter_color = new ElatedMooseField("colorsimple","blog_masonry_filter_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_filter_color",$blog_masonry_filter_color);
$blog_masonry_filter_hovercolor = new ElatedMooseField("colorsimple","blog_masonry_filter_hovercolor","","Hover/Active Color","This is some description");
$row1->addChild("blog_masonry_filter_hovercolor",$blog_masonry_filter_hovercolor);
$blog_masonry_filter_font_size = new ElatedMooseField("textsimple","blog_masonry_filter_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_masonry_filter_font_size",$blog_masonry_filter_font_size);
$blog_masonry_filter_line_height = new ElatedMooseField("textsimple","blog_masonry_filter_line_height","","Line Height (px)","This is some description");
$row1->addChild("blog_masonry_filter_line_height",$blog_masonry_filter_line_height);

$row2 = new ElatedMooseRow(true);
$group2->addChild("row2",$row2);
$blog_masonry_filter_font_family = new ElatedMooseField("fontsimple","blog_masonry_filter_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_masonry_filter_font_family",$blog_masonry_filter_font_family);
$blog_masonry_filter_font_style = new ElatedMooseField("selectblanksimple","blog_masonry_filter_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_masonry_filter_font_style",$blog_masonry_filter_font_style);
$blog_masonry_filter_font_weight = new ElatedMooseField("selectblanksimple","blog_masonry_filter_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_masonry_filter_font_weight",$blog_masonry_filter_font_weight);
$blog_masonry_filter_text_transform = new ElatedMooseField("selectblanksimple","blog_masonry_filter_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_masonry_filter_text_transform",$blog_masonry_filter_text_transform);

$row3 = new ElatedMooseRow(true);
$group2->addChild("row3",$row3);
$blog_masonry_filter_letter_spacing = new ElatedMooseField("textsimple","blog_masonry_filter_letter_spacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_masonry_filter_letter_spacing",$blog_masonry_filter_letter_spacing);

$blog_masonry_filter_disable_separator = new ElatedMooseField("yesno","blog_masonry_filter_disable_separator","yes","Disable Separator Between Categories","Disabling this option will remove separator between filter categories.");
$blog_masonry_filter_container->addChild("blog_masonry_filter_disable_separator",$blog_masonry_filter_disable_separator);

$blog_masonry_type = new ElatedMooseField("select","blog_masonry_type","post_info_below_title","Post Info Position","Choose Post Info Position for Masonry Blog List", array(
	"post_info_below_title" => "Post Info Section Below Title",
	"post_info_at_bottom" => "Post Info Section at Bottom"
));
$panel10->addChild("blog_masonry_type",$blog_masonry_type);

$blog_masonry_content_position = new ElatedMooseField("select","blog_masonry_content_position","content_above_blog_list","Content Position","Choose content position for blog list template when sidebar is enabled. Note: This settings in only for template, not for archive pages", array(
	"content_above_blog_list" => "Content Above Blog List",
	"content_above_blog_list_and_sidebar" => "Content Above Blog List and Sidebar"
));
$panel10->addChild("blog_masonry_content_position",$blog_masonry_content_position);

$blog_masonry_post_meta_data_section = new ElatedMooseTitle("blog_masonry_post_meta_data_section", "Post Info Data Fields");
$panel10->addChild("blog_masonry_post_meta_data_section", $blog_masonry_post_meta_data_section);

$blog_masonry_show_categories= new ElatedMooseField("yesno","blog_masonry_show_categories","no","Show Categories","Enabling this option will Show Categories on Post List");
$panel10->addChild("blog_masonry_show_categories",$blog_masonry_show_categories);

$blog_masonry_show_comments = new ElatedMooseField("yesno","blog_masonry_show_comments","yes","Show Comments","Enabling this option will Show Comments on Post List");
$panel10->addChild("blog_masonry_show_comments",$blog_masonry_show_comments);

$blog_masonry_show_author = new ElatedMooseField("yesno","blog_masonry_show_author","no","Show Author Name","Enabling this option will show author name on Post List and Blog Post Single");
$panel10->addChild("blog_masonry_show_author",$blog_masonry_show_author);

$blog_masonry_show_date = new ElatedMooseField("yesno","blog_masonry_show_date","no","Show Date","Enabling this option will show date on Post List");
$panel10->addChild("blog_masonry_hide_date",$blog_masonry_show_date);

$blog_masonry_show_share = new ElatedMooseField("yesno","blog_masonry_show_share","no","Show Share","Enabling this option will show share on Post List", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_masonry_share_options_container"));
$panel10->addChild("blog_masonry_show_share",$blog_masonry_show_share);

$blog_masonry_share_options_container = new ElatedMooseContainer("blog_masonry_share_options_container","blog_masonry_show_share","no");
$panel10->addChild("blog_masonry_share_options_container",$blog_masonry_share_options_container);

$blog_masonry_select_share_options_masonry_type = new ElatedMooseField("select","blog_masonry_select_share_options_masonry_type","dropdown","Social Share Style","Choose Social Share Style for Masonry Type",array(
	"dropdown" => "Social Share Dropdown",
	"list" => "Social Share List"
), array("dependence" => true,
	"show" => array("list"=>"#eltdf_blog_masonry_share_list_type_options_container","dropdown" => "#eltdf_blog_masonry_share_dropdown_type_options_container"),
	"hide" => array("dropdown"=>"#eltdf_blog_masonry_share_list_type_options_container","list" => "#eltdf_blog_masonry_share_dropdown_type_options_container"),
	));

$blog_masonry_share_options_container->addChild("blog_masonry_select_share_options_masonry_type",$blog_masonry_select_share_options_masonry_type);

$blog_masonry_share_list_type_options_container = new ElatedMooseContainer("blog_masonry_share_list_type_options_container","blog_masonry_select_share_options_masonry_type","dropdown");
$blog_masonry_share_options_container->addChild("blog_masonry_share_list_type_options_container",$blog_masonry_share_list_type_options_container);
	
	$blog_masonry_share_hld_hover_icon_color = new ElatedMooseField("color","blog_masonry_share_hld_hover_icon_color","","Icon color on Quote/Link Holder Hover","Choose icon color for share list when the quote/link holder is hovered over");
	$blog_masonry_share_list_type_options_container->addChild("blog_masonry_share_hld_hover_icon_color",$blog_masonry_share_hld_hover_icon_color);

$blog_masonry_share_dropdown_type_options_container = new ElatedMooseContainer("blog_masonry_share_dropdown_type_options_container","blog_masonry_select_share_options_masonry_type","list");
$blog_masonry_share_options_container->addChild("blog_masonry_share_dropdown_type_options_container",$blog_masonry_share_dropdown_type_options_container);

	$blog_masonry_share_background_color = new ElatedMooseField("color","blog_masonry_share_background_color","","Background Color","Choose background color for share dropdown");
	$blog_masonry_share_dropdown_type_options_container->addChild("blog_masonry_share_background_color",$blog_masonry_share_background_color);

	$blog_masonry_share_background_color_link_post_type = new ElatedMooseField("color","blog_masonry_share_background_color_link_post_type","","Background Color on Quote/Link Post Type","Choose background color for share dropdown");
	$blog_masonry_share_dropdown_type_options_container->addChild("blog_masonry_share_background_color_link_post_type",$blog_masonry_share_background_color_link_post_type);

$blog_masonry_share_icon_color = new ElatedMooseField("color","blog_masonry_share_icon_color","","Icon Color","Choose icon color for share dropdown and list");
$blog_masonry_share_options_container->addChild("blog_masonry_share_icon_color",$blog_masonry_share_icon_color);

$blog_masonry_share_icon_hover_color = new ElatedMooseField("color","blog_masonry_share_icon_hover_color","","Icon Hover Color","Choose icon hover color for share dropdown and list");
$blog_masonry_share_options_container->addChild("blog_masonry_share_icon_hover_color",$blog_masonry_share_icon_hover_color);

$blog_masonry_share_icon_color_link_post_type = new ElatedMooseField("color","blog_masonry_share_icon_color_link_post_type","","Icon Color for Quote/Link Post Type","Choose icon color for share dropdown and list");
$blog_masonry_share_options_container->addChild("blog_masonry_share_icon_color_link_post_type",$blog_masonry_share_icon_color_link_post_type);

$blog_masonry_share_icon_hover_color_link_post_type = new ElatedMooseField("color","blog_masonry_share_icon_hover_color_link_post_type","","Icon Hover Color for Quote/Link Post Type","Choose icon hover color for share dropdown and list");
$blog_masonry_share_options_container->addChild("blog_masonry_share_icon_hover_color_link_post_type",$blog_masonry_share_icon_hover_color_link_post_type);

$blog_masonry_show_like = new ElatedMooseField("yesno","blog_masonry_show_like","no","Show Likes",'Enabling this option will turn on "Likes"');
$panel10->addChild("blog_masonry_show_like",$blog_masonry_show_like);

$blog_masonry_post_design_style = new ElatedMooseTitle("blog_masonry_post_design_style", "Post Design Style");
$panel10->addChild("blog_masonry_post_design_style", $blog_masonry_post_design_style);

$blog_masonry_post_alignment = new ElatedMooseField("select","blog_masonry_post_alignment","","Post Alignment","Choose alignment for whole post",array(
	"left" => "Left",
	"center" => "Center",
	"right" => "Right"
));
$panel10->addChild("blog_masonry_post_alignment",$blog_masonry_post_alignment);

$blog_masonry_enable_text_box = new ElatedMooseField("yesno","blog_masonry_enable_text_box","no","Enable Boxed Styled Post Content","Enable post text boxed features", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_masonry_enable_text_box_container"));
$panel10->addChild("blog_masonry_enable_text_box",$blog_masonry_enable_text_box);

$blog_masonry_enable_text_box_container = new ElatedMooseContainer("blog_masonry_enable_text_box_container","blog_masonry_enable_text_box","no");
$panel10->addChild("blog_masonry_enable_text_box_container",$blog_masonry_enable_text_box_container);

$blog_masonry_box_background_color = new ElatedMooseField("color","blog_masonry_box_background_color","","Background Color","Choose background color for post text box");
$blog_masonry_enable_text_box_container->addChild("blog_masonry_box_background_color",$blog_masonry_box_background_color);

$blog_masonry_box_border_color = new ElatedMooseField("color","blog_masonry_box_border_color","","Border Color","Choose border color for post text box");
$blog_masonry_enable_text_box_container->addChild("blog_masonry_box_border_color",$blog_masonry_box_border_color);

$blog_masonry_box_padding = new ElatedMooseField("text","blog_masonry_box_padding","","Text box padding","Please insert padding in format (top right bottom left) i.e. 5px 5px 5px 5px", array(), array("col_width" => 3));
$blog_masonry_enable_text_box_container->addChild("blog_masonry_box_padding",$blog_masonry_box_padding);

$group7 = new ElatedMooseGroup("Paragraph","Set paragraph color");
$panel10->addChild("group7",$group7);

$blog_masonry_paragraph_color = new ElatedMooseField("colorsimple","blog_masonry_paragraph_color","","Color","This is some description");
$group7->addChild("blog_masonry_paragraph_color",$blog_masonry_paragraph_color);

$group1 = new ElatedMooseGroup("Quote/Link Background","Set background of Quote/Link post type");
$panel10->addChild("group1",$group1);

$row1 = new ElatedMooseRow();
$group1->addChild("row1",$row1);

$blog_masonry_ql_background_image = new ElatedMooseField("yesnosimple","blog_masonry_ql_background_image","yes","Background Image","");
$row1->addChild("blog_masonry_ql_background_image",$blog_masonry_ql_background_image);

$blog_masonry_ql_background_color = new ElatedMooseField("colorsimple","blog_masonry_ql_background_color","","Background Color","Default color is #ffffff.");
$row1->addChild("blog_masonry_ql_background_color",$blog_masonry_ql_background_color);

$blog_masonry_ql_hover_background_color = new ElatedMooseField("colorsimple","blog_masonry_ql_hover_background_color","","Background Hover Color","Default color is #e6ae48.");
$row1->addChild("blog_masonry_ql_hover_background_color",$blog_masonry_ql_hover_background_color);

$blog_masonry_show_ql_mark = new ElatedMooseField("yesno","blog_masonry_show_ql_mark","yes","Enable Quote/Link Icon","Show Icons for quote/link post format", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_masonry_show_ql_mark_container"));
$panel10->addChild("blog_masonry_show_ql_mark",$blog_masonry_show_ql_mark);

$blog_masonry_show_ql_mark_container = new ElatedMooseContainer("blog_masonry_show_ql_mark_container","blog_masonry_show_ql_mark","no");
$panel10->addChild("blog_masonry_show_ql_mark_container",$blog_masonry_show_ql_mark_container);

$row1 = new ElatedMooseRow();
$blog_masonry_show_ql_mark_container->addChild("row1",$row1);

$blog_masonry_ql_mark_color = new ElatedMooseField("color","blog_masonry_ql_mark_color","","Icon Color","Choose icon color for quote/link post");
$row1->addChild("blog_masonry_ql_mark_color",$blog_masonry_ql_mark_color);

$blog_masonry_ql_mark_hover_color = new ElatedMooseField("color","blog_masonry_ql_mark_hover_color","","Icon Hover Color","Choose hover icon color for quote/link post.");
$row1->addChild("blog_masonry_ql_mark_hover_color",$blog_masonry_ql_mark_hover_color);

$group8 = new ElatedMooseGroup("Blog List Spacing","Set spacing for blog layouts");
$panel10->addChild("group8",$group8);

$row1 = new ElatedMooseRow();
$group8->addChild("row1",$row1);

$blog_masonry_image_margin_bottom = new ElatedMooseField("textsimple","blog_masonry_image_margin_bottom","","Margin Under Image (px)","This is some description");
$row1->addChild("blog_masonry_image_margin_bottom",$blog_masonry_image_margin_bottom);

$blog_masonry_title_margin_bottom = new ElatedMooseField("textsimple","blog_masonry_title_margin_bottom","","Margin Under Title (px)","This is some description");
$row1->addChild("blog_masonry_title_margin_bottom",$blog_masonry_title_margin_bottom);

$blog_masonry_post_info_margin_bottom = new ElatedMooseField("textsimple","blog_masonry_post_info_margin_bottom","","Margin Under Post Info (px)","This is some description");
$row1->addChild("blog_masonry_post_info_margin_bottom",$blog_masonry_post_info_margin_bottom);

$blog_masonry_read_more_margin_top = new ElatedMooseField("textsimple","blog_masonry_read_more_margin_top","","Margin Above Read More Button (px)","This is some description");
$row1->addChild("blog_masonry_read_more_margin_top",$blog_masonry_read_more_margin_top);

$row2 = new ElatedMooseRow();
$group8->addChild("row2",$row2);

$blog_masonry_social_share_list_margin_top = new ElatedMooseField("textsimple","blog_masonry_social_share_list_margin_top","","Margin Above Social Share List Holder (px)","This is some description");
$row2->addChild("blog_masonry_social_share_list_margin_top",$blog_masonry_social_share_list_margin_top);

$blog_masonry_article_margin_bottom = new ElatedMooseField("textsimple","blog_masonry_article_margin_bottom","","Margin Between Articles (px)","This is some description");
$row2->addChild("blog_masonry_article_margin_bottom",$blog_masonry_article_margin_bottom);

$blog_masonry_post_info_bottom_margin_top = new ElatedMooseField("textsimple","blog_masonry_post_info_bottom_margin_top","","Margin Above Post Info When Post Info is on the bottom (px)","This is some description");
$row2->addChild("blog_masonry_post_info_bottom_margin_top",$blog_masonry_post_info_bottom_margin_top);

$group9 = new ElatedMooseGroup("Blog List Spacing for Quote and Link Post Type","Set spacing for blog layouts");
$panel10->addChild("group9",$group9);

$row1 = new ElatedMooseRow();
$group9->addChild("row1",$row1);

$blog_masonry_ql_title_margin_bottom = new ElatedMooseField("textsimple","blog_masonry_ql_title_margin_bottom","","Margin Under Title (px)","This is some description");
$row1->addChild("blog_masonry_ql_title_margin_bottom",$blog_masonry_ql_title_margin_bottom);

$blog_masonry_ql_quote_author_margin_bottom = new ElatedMooseField("textsimple","blog_masonry_ql_quote_author_margin_bottom","","Margin Under Quote Author (px)","This is some description");
$row1->addChild("blog_masonry_ql_quote_author_margin_bottom",$blog_masonry_ql_quote_author_margin_bottom);

$blog_masonry_ql_social_share_list_margin_top = new ElatedMooseField("textsimple","blog_masonry_ql_social_share_list_margin_top","","Margin Above Social Share List Holder (px)","This is some description");
$row1->addChild("blog_masonry_ql_social_share_list_margin_top",$blog_masonry_ql_social_share_list_margin_top);


$group10 = new ElatedMooseGroup("Border Arround Article","Set border style for articles");
$panel10->addChild("group10",$group10);

$row1 = new ElatedMooseRow();
$group10->addChild("row1",$row1);

$blog_masonry_article_border_width = new ElatedMooseField("textsimple","blog_masonry_article_border_width","","Border Width (px)","This is some description");
$row1->addChild("blog_masonry_article_border_width",$blog_masonry_article_border_width);

$blog_masonry_article_border_color = new ElatedMooseField("colorsimple","blog_masonry_article_border_color","","Border Color","This is some description");
$row1->addChild("blog_masonry_article_border_color",$blog_masonry_article_border_color);

$post_text_styling= new ElatedMooseTitle("post_text_styling", "Post Text Style");
$panel10->addChild("post_text_styling", $post_text_styling);

$group2 = new ElatedMooseGroup("Post Title","Define title styles in this blog post template.");
$panel10->addChild("group2",$group2);

$row1 = new ElatedMooseRow();
$group2->addChild("row1",$row1);

$blog_masonry_title_color = new ElatedMooseField("colorsimple","blog_masonry_title_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_title_color",$blog_masonry_title_color);

$blog_masonry_title_hover_color = new ElatedMooseField("colorsimple","blog_masonry_title_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_masonry_title_hover_color",$blog_masonry_title_hover_color);

$blog_masonry_title_fontsize = new ElatedMooseField("textsimple","blog_masonry_title_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_masonry_title_fontsize",$blog_masonry_title_fontsize);

$row2 = new ElatedMooseRow(true);
$group2->addChild("row2",$row2);


$blog_masonry_title_lineheight = new ElatedMooseField("textsimple","blog_masonry_title_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_masonry_title_lineheight",$blog_masonry_title_lineheight);

$blog_masonry_title_google_fonts = new ElatedMooseField("fontsimple","blog_masonry_title_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_masonry_title_google_fonts",$blog_masonry_title_google_fonts);

$blog_masonry_title_fontstyle = new ElatedMooseField("selectblanksimple","blog_masonry_title_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_masonry_title_fontstyle",$blog_masonry_title_fontstyle);

$blog_masonry_title_fontweight = new ElatedMooseField("selectblanksimple","blog_masonry_title_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_masonry_title_fontweight",$blog_masonry_title_fontweight);

$row3 = new ElatedMooseRow(true);
$group2->addChild("row3",$row3);


$blog_masonry_title_texttransform = new ElatedMooseField("selectblanksimple","blog_masonry_title_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_masonry_title_texttransform",$blog_masonry_title_texttransform);

$blog_masonry_title_letterspacing = new ElatedMooseField("textsimple","blog_masonry_title_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_masonry_title_letterspacing",$blog_masonry_title_letterspacing);

$group4 = new ElatedMooseGroup("Post Info Data","Define post info text styles (date, category names etc.) Note: Single Posts will take the same styles as in list");
$panel10->addChild("group4",$group4);

$row1 = new ElatedMooseRow();
$group4->addChild("row1",$row1);

$blog_masonry_info_color = new ElatedMooseField("colorsimple","blog_masonry_info_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_info_color",$blog_masonry_info_color);

$blog_masonry_info_link_color = new ElatedMooseField("colorsimple","blog_masonry_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_masonry_info_link_color",$blog_masonry_info_link_color);

$blog_masonry_info_hover_color = new ElatedMooseField("colorsimple","blog_masonry_info_hover_color","","Link Hover Color","This is some description");
$row1->addChild("blog_masonry_info_hover_color",$blog_masonry_info_hover_color);

$blog_masonry_info_fontsize = new ElatedMooseField("textsimple","blog_masonry_info_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_masonry_info_fontsize",$blog_masonry_info_fontsize);

$row2 = new ElatedMooseRow(true);
$group4->addChild("row2",$row2);


$blog_masonry_info_lineheight = new ElatedMooseField("textsimple","blog_masonry_info_lineheight","","Line Height (px)","This is some description");
$row2->addChild("blog_masonry_info_lineheight",$blog_masonry_info_lineheight);

$blog_masonry_info_google_fonts = new ElatedMooseField("fontsimple","blog_masonry_info_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_masonry_info_google_fonts",$blog_masonry_info_google_fonts);

$blog_masonry_info_fontstyle = new ElatedMooseField("selectblanksimple","blog_masonry_info_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_masonry_info_fontstyle",$blog_masonry_info_fontstyle);

$blog_masonry_info_fontweight = new ElatedMooseField("selectblanksimple","blog_masonry_info_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_masonry_info_fontweight",$blog_masonry_info_fontweight);

$row3 = new ElatedMooseRow(true);
$group4->addChild("row3",$row3);

$blog_masonry_info_link_fontweight = new ElatedMooseField("selectblanksimple","blog_masonry_info_link_fontweight","","Link Font Weight","This is some description",$eltd_moose_options_fontweight);
$row3->addChild("blog_masonry_info_link_fontweight",$blog_masonry_info_link_fontweight);

$blog_masonry_info_texttransform = new ElatedMooseField("selectblanksimple","blog_masonry_info_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row3->addChild("blog_masonry_info_texttransform",$blog_masonry_info_texttransform);

$blog_masonry_info_letterspacing = new ElatedMooseField("textsimple","blog_masonry_info_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_masonry_info_letterspacing",$blog_masonry_info_letterspacing);

$group3 = new ElatedMooseGroup("Quote/Link Title Style","Define title styles for Quote/Link articles");
$panel10->addChild("group3",$group3);

$row1 = new ElatedMooseRow();
$group3->addChild("row1",$row1);

$blog_masonry_ql_title_color = new ElatedMooseField("colorsimple","blog_masonry_ql_title_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_ql_title_color",$blog_masonry_ql_title_color);

$blog_masonry_ql_title_hover_color = new ElatedMooseField("colorsimple","blog_masonry_ql_title_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_masonry_ql_title_hover_color",$blog_masonry_ql_title_hover_color);

$blog_masonry_ql_title_fontsize = new ElatedMooseField("textsimple","blog_masonry_ql_title_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_masonry_ql_title_font_size",$blog_masonry_ql_title_fontsize);

$blog_masonry_ql_title_lineheight = new ElatedMooseField("textsimple","blog_masonry_ql_title_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_masonry_ql_title_lineheight",$blog_masonry_ql_title_lineheight);

$row2 = new ElatedMooseRow(true);
$group3->addChild("row2",$row2);

$blog_masonry_ql_title_texttransform = new ElatedMooseField("selectblanksimple","blog_masonry_ql_title_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_masonry_ql_title_texttransform",$blog_masonry_ql_title_texttransform);

$blog_masonry_ql_title_google_fonts = new ElatedMooseField("fontsimple","blog_masonry_ql_title_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_masonry_ql_title_google_fonts",$blog_masonry_ql_title_google_fonts);

$blog_masonry_ql_title_fontstyle = new ElatedMooseField("selectblanksimple","blog_masonry_ql_title_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_masonry_ql_title_fontstyle",$blog_masonry_ql_title_fontstyle);

$blog_masonry_ql_title_fontweight = new ElatedMooseField("selectblanksimple","blog_masonry_ql_title_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_masonry_ql_title_fontweight",$blog_masonry_ql_title_fontweight);

$row3 = new ElatedMooseRow(true);
$group3->addChild("row3",$row3);

$blog_masonry_ql_title_letterspacing = new ElatedMooseField("textsimple","blog_masonry_ql_title_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_masonry_ql_title_letterspacing",$blog_masonry_ql_title_letterspacing);

$group5 = new ElatedMooseGroup("Quote/Link Post Info Data","Define quote/link post info text styles (date, category names etc.) Note: Single Posts will take the same styles as in list.");
$panel10->addChild("group5",$group5);

$row1 = new ElatedMooseRow();
$group5->addChild("row1",$row1);

$blog_masonry_ql_info_color = new ElatedMooseField("colorsimple","blog_masonry_ql_info_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_ql_info_color",$blog_masonry_ql_info_color);

$blog_masonry_ql_info_link_color = new ElatedMooseField("colorsimple","blog_masonry_ql_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_masonry_ql_info_link_color",$blog_masonry_ql_info_link_color);

$blog_masonry_ql_info_hover_color = new ElatedMooseField("colorsimple","blog_masonry_ql_info_hover_color","","Hover Color","This is some description");
$row1->addChild("blog_masonry_ql_info_hover_color",$blog_masonry_ql_info_hover_color);

$blog_masonry_ql_info_fontsize = new ElatedMooseField("textsimple","blog_masonry_ql_info_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_masonry_ql_info_fontsize",$blog_masonry_ql_info_fontsize);

$row2 = new ElatedMooseRow(true);
$group5->addChild("row2",$row2);

$blog_masonry_ql_info_lineheight = new ElatedMooseField("textsimple","blog_masonry_ql_info_lineheight","","Line Height (px)","This is some description");
$row2->addChild("blog_masonry_ql_info_lineheight",$blog_masonry_ql_info_lineheight);

$blog_masonry_ql_info_google_fonts = new ElatedMooseField("fontsimple","blog_masonry_ql_info_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_masonry_ql_info_google_fonts",$blog_masonry_ql_info_google_fonts);

$blog_masonry_ql_info_fontstyle = new ElatedMooseField("selectblanksimple","blog_masonry_ql_info_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_masonry_ql_info_fontstyle",$blog_masonry_ql_info_fontstyle);

$blog_masonry_ql_info_fontweight = new ElatedMooseField("selectblanksimple","blog_masonry_ql_info_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_masonry_ql_info_fontweight",$blog_masonry_ql_info_fontweight);

$row3 = new ElatedMooseRow(true);
$group5->addChild("row3",$row3);

$blog_masonry_ql_info_link_fontweight = new ElatedMooseField("selectblanksimple","blog_masonry_ql_info_link_fontweight","","Link Font Weight","This is some description",$eltd_moose_options_fontweight);
$row3->addChild("blog_masonry_ql_info_link_fontweight",$blog_masonry_ql_info_link_fontweight);

$blog_masonry_ql_info_texttransform = new ElatedMooseField("selectblanksimple","blog_masonry_ql_info_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row3->addChild("blog_masonry_ql_info_texttransform",$blog_masonry_ql_info_texttransform);

$blog_masonry_ql_info_letterspacing = new ElatedMooseField("textsimple","blog_masonry_ql_info_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_masonry_ql_info_letterspacing",$blog_masonry_ql_info_letterspacing);

$group6 = new ElatedMooseGroup("Quote Author Style","Define author styles for Quote articles");
$panel10->addChild("group6",$group6);

$row1 = new ElatedMooseRow();
$group6->addChild("row1",$row1);

$blog_masonry_ql_author_color = new ElatedMooseField("colorsimple","blog_masonry_ql_author_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_ql_author_color",$blog_masonry_ql_author_color);

$blog_masonry_ql_author_hover_color = new ElatedMooseField("colorsimple","blog_masonry_ql_author_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_masonry_ql_author_hover_color",$blog_masonry_ql_author_hover_color);

$blog_masonry_ql_author_fontsize = new ElatedMooseField("textsimple","blog_masonry_ql_author_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_masonry_ql_author_font_size",$blog_masonry_ql_author_fontsize);

$blog_masonry_ql_author_lineheight = new ElatedMooseField("textsimple","blog_masonry_ql_author_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_masonry_ql_author_lineheight",$blog_masonry_ql_author_lineheight);

$row2 = new ElatedMooseRow(true);
$group6->addChild("row2",$row2);

$blog_masonry_ql_author_texttransform = new ElatedMooseField("selectblanksimple","blog_masonry_ql_author_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_masonry_ql_author_texttransform",$blog_masonry_ql_author_texttransform);

$blog_masonry_ql_author_google_fonts = new ElatedMooseField("fontsimple","blog_masonry_ql_author_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_masonry_ql_author_google_fonts",$blog_masonry_ql_author_google_fonts);

$blog_masonry_ql_author_fontstyle = new ElatedMooseField("selectblanksimple","blog_masonry_ql_author_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_masonry_ql_author_fontstyle",$blog_masonry_ql_author_fontstyle);

$blog_masonry_ql_author_fontweight = new ElatedMooseField("selectblanksimple","blog_masonry_ql_author_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_masonry_ql_author_fontweight",$blog_masonry_ql_author_fontweight);

$row3 = new ElatedMooseRow(true);
$group6->addChild("row3",$row3);

$blog_masonry_ql_author_letterspacing = new ElatedMooseField("textsimple","blog_masonry_ql_author_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_masonry_ql_author_letterspacing",$blog_masonry_ql_author_letterspacing);

$group14 = new ElatedMooseGroup("Date Style","Define style for date box");
$panel10->addChild("group14",$group14);

$row1 = new ElatedMooseRow();
$group14->addChild("row1",$row1);

$blog_masonry_corner_date_color = new ElatedMooseField("colorsimple","blog_masonry_corner_date_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_corner_date_color",$blog_masonry_corner_date_color);

$blog_masonry_corner_date_bckg_color = new ElatedMooseField("colorsimple","blog_masonry_corner_date_bckg_color","","Background Color","This is some description");
$row1->addChild("blog_masonry_corner_date_bckg_color",$blog_masonry_corner_date_bckg_color);

$group15 = new ElatedMooseGroup("Comments Style","Define style for comments box");
$panel10->addChild("group15",$group15);

$row1 = new ElatedMooseRow();
$group15->addChild("row1",$row1);

$blog_masonry_corner_comments_color = new ElatedMooseField("colorsimple","blog_masonry_corner_comments_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_corner_comments_color",$blog_masonry_corner_comments_color);

$blog_masonry_corner_comments_bckg_color = new ElatedMooseField("colorsimple","blog_masonry_corner_comments_bckg_color","","Background Color","This is some description");
$row1->addChild("blog_masonry_corner_comments_bckg_color",$blog_masonry_corner_comments_bckg_color);

// Blog Post List - Blog: Split Column
$panel11 = new ElatedMoosePanel("Blog List Template Options: Split Column","blog_split_column_post_lists", "blog_split_column_show_options", "no");
$blogPage->addChild("panel11",$panel11);

$blog_split_column_number_of_chars = new ElatedMooseField("text","blog_split_column_number_of_chars","45","Number of Words in Excerpt",' Enter a number of words in excerpt (article summary)', array(), array("col_width" => 3));
$panel11->addChild("blog_split_column_number_of_chars",$blog_split_column_number_of_chars);

$blog_split_column_image_size = new ElatedMooseField("select","blog_split_column_image_size","full","Blog Image Size","Choose image size for Post List", array(
    "full" => "Default",
    "portfolio-landscape" => "Landscape",
    "portfolio-portrait" => "Portrait",
    "custom" => "Custom"
),
    array("dependence" => true,
        "hide" => array(
            "full"=>"#eltdf_blog_split_column_image_size_container",
            "portfolio-landscape"=>"#eltdf_blog_split_column_image_size_container",
            "portfolio-portrait"=>"#eltdf_blog_split_column_image_size_container",
            "custom"=>""
        ),
        "show" => array(
            "full"=>"",
            "portfolio-landscape"=>"",
            "portfolio-portrait"=>"",
            "custom"=>"#eltdf_blog_split_column_image_size_container"
        )
    )
);
$panel11->addChild("blog_split_column_image_size",$blog_split_column_image_size);

$blog_split_column_image_size_container = new ElatedMooseContainer("blog_split_column_image_size_container","blog_split_column_image_size","", array( "full","portfolio-landscape","portfolio-portrait"));
$panel11->addChild("blog_split_column_image_size_container",$blog_split_column_image_size_container);

$blog_split_column_image_size_height = new ElatedMooseField("text","blog_split_column_image_size_height","","Image Height (px)","Enter width (in pixels) for Custom Image for Post List", array(), array("col_width" => 3));
$blog_split_column_image_size_container->addChild("blog_split_column_image_size_height",$blog_split_column_image_size_height);

$blog_split_column_image_size_width = new ElatedMooseField("text","blog_split_column_image_size_width","","Image Width (px)","Enter width (in pixels) for Custom Image for Post List", array(), array("col_width" => 3));
$blog_split_column_image_size_container->addChild("blog_split_column_image_size_width",$blog_split_column_image_size_width);

$blog_split_column_read_more_button = new ElatedMooseField("yesno","blog_split_column_read_more_button","yes","Read More Button","Enable Read More Button", array(),
    array("dependence" => true,
        "dependence_hide_on_yes" => "",
        "dependence_show_on_yes" => "#eltdf_blog_split_column_read_more_button_container"));
$panel11->addChild("blog_split_column_read_more_button",$blog_split_column_read_more_button);

$blog_split_column_read_more_button_container = new ElatedMooseContainer("blog_split_column_read_more_button_container","blog_split_column_read_more_button","no");
$panel11->addChild("blog_split_column_read_more_button_container",$blog_split_column_read_more_button_container);

$blog_split_column_read_more_button_icon = new ElatedMooseField("yesno","blog_split_column_read_more_button_icon","no","Enable Icon","Enabling this option will place icon in read more button", array(),
    array("dependence" => true,
        "dependence_hide_on_yes" => "",
        "dependence_show_on_yes" => "#eltdf_blog_split_column_read_more_button_icon_container"));
$blog_split_column_read_more_button_container->addChild("blog_split_column_read_more_button_icon",$blog_split_column_read_more_button_icon);

$blog_split_column_read_more_button_icon_container = new ElatedMooseContainer("blog_split_column_read_more_button_icon_container","blog_split_column_read_more_button_icon","no");
$blog_split_column_read_more_button_container->addChild("blog_split_column_read_more_button_icon_container",$blog_split_column_read_more_button_icon_container);

//init icon pack hide and show array. It will be populated dinamically from collections array
$blog_split_column_read_more_button_icon_pack_hide_array = array();
$blog_split_column_read_more_button_icon_pack_show_array = array();

//do we have some collection added in collections array?
if(is_array($eltdIconCollections->iconCollections) && count($eltdIconCollections->iconCollections)) {
    //get collections params array. It will contain values of 'param' property for each collection
    $blog_split_column_read_more_button_icon_collections_params = $eltdIconCollections->getIconCollectionsParams();

    //foreach collection generate hide and show array
    foreach ($eltdIconCollections->iconCollections as $dep_collection_key => $dep_collection_object) {
        $blog_split_column_read_more_button_icon_pack_hide_array[$dep_collection_key] = '';

        //we need to include only current collection in show string as it is the only one that needs to show
        $blog_split_column_read_more_button_icon_pack_show_array[$dep_collection_key] = '#eltdf_blog_split_column_read_more_button_icon_'.$dep_collection_object->param.'_container';

        //for all collections param generate hide string
        foreach ($blog_split_column_read_more_button_icon_collections_params as $blog_split_column_read_more_button_icon_collections_param) {
            //we don't need to include current one, because it needs to be shown, not hidden
            if($blog_split_column_read_more_button_icon_collections_param !== $dep_collection_object->param) {
                $blog_split_column_read_more_button_icon_pack_hide_array[$dep_collection_key].= '#eltdf_blog_split_column_read_more_button_icon_'.$blog_split_column_read_more_button_icon_collections_param.'_container,';
            }
        }

        //remove remaining ',' character
        $blog_split_column_read_more_button_icon_pack_hide_array[$dep_collection_key] = rtrim($blog_split_column_read_more_button_icon_pack_hide_array[$dep_collection_key], ',');
    }

}

$blog_split_column_read_more_button_icon_pack = new ElatedMooseField(
    "select",
    "blog_split_column_read_more_button_icon_pack",
    "font_awesome",
    "Icon Pack",
    "Choose icon pack for show load more button",
    $eltdIconCollections->getIconCollections(),
    array(
        "dependence" => true,
        "hide" => $blog_split_column_read_more_button_icon_pack_hide_array,
        "show" => $blog_split_column_read_more_button_icon_pack_show_array
    ));

$blog_split_column_read_more_button_icon_container->addChild("blog_split_column_read_more_button_icon_pack", $blog_split_column_read_more_button_icon_pack);

if(is_array($eltdIconCollections->iconCollections) && count($eltdIconCollections->iconCollections)) {
    //foreach icon collection we need to generate separate container that will have dependency set
    //it will have one field inside with icons dropdown
    foreach ($eltdIconCollections->iconCollections as $collection_key => $collection_object) {
        $icons_array = $collection_object->getIconsArray();

        //get icon collection keys (keys from collections array, e.g 'font_awesome', 'font_elegant' etc.)
        $icon_collections_keys = $eltdIconCollections->getIconCollectionsKeys();

        //unset current one, because it doesn't have to be included in dependency that hides icon container
        unset($icon_collections_keys[array_search($collection_key, $icon_collections_keys)]);

        $blog_split_column_read_more_button_icon_hide_values = $icon_collections_keys;
        $blog_icon_container = new ElatedMooseContainer("blog_split_column_read_more_button_icon_".$collection_object->param."_container", "blog_split_column_read_more_button_icon_pack", "", $blog_split_column_read_more_button_icon_hide_values);
        $blog_split_column_read_more_button_icon = new ElatedMooseField("select", "blog_split_column_read_more_button_icon_".$collection_object->param, "", "Button Icon","Choose Button Icon", $icons_array, array("col_width" => 3));
        $blog_icon_container->addChild("blog_split_column_read_more_button_icon_".$collection_object->param, $blog_split_column_read_more_button_icon);

        $blog_split_column_read_more_button_icon_container->addChild("blog_split_column_read_more_button_icon_".$collection_object->param."_container", $blog_icon_container);
    }

}


$blog_split_column_content_position = new ElatedMooseField("select","blog_split_column_content_position","content_above_blog_list","Content Position","Choose content position for blog list template when sidebar is enabled. Note: This settings in only for template, not for archive pages", array(
	"content_above_blog_list" => "Content Above Blog List",
	"content_above_blog_list_and_sidebar" => "Content Above Blog List and Sidebar"
));
$panel11->addChild("blog_split_column_content_position",$blog_split_column_content_position);

$blog_split_column_post_meta_data_section = new ElatedMooseTitle("blog_split_column_post_meta_data_section", "Post Info Data Fields");
$panel11->addChild("blog_split_column_post_meta_data_section", $blog_split_column_post_meta_data_section);

$blog_split_column_show_categories = new ElatedMooseField("yesno","blog_split_column_show_categories","no","Show Categories","Enabling this option will Show Categories on Post List");
$panel11->addChild("blog_split_column_show_categories",$blog_split_column_show_categories);

$blog_split_column_show_comments = new ElatedMooseField("yesno","blog_split_column_show_comments","yes","Show Comments","Enabling this option will Show Comments on Post List");
$panel11->addChild("blog_split_column_show_comments",$blog_split_column_show_comments);

$blog_split_column_show_author = new ElatedMooseField("yesno","blog_split_column_show_author","yes","Show Author Name","Enabling this option will show author name on Post List and Blog Post Single");
$panel11->addChild("blog_split_column_show_author",$blog_split_column_show_author);

$blog_split_column_show_date = new ElatedMooseField("yesno","blog_split_column_show_date","yes","Show Date","Enabling this option will show date on Post List");
$panel11->addChild("blog_split_column_hide_date",$blog_split_column_show_date);

$blog_split_column_show_share = new ElatedMooseField("yesno","blog_split_column_show_share","no","Show Share","Enabling this option will show share on Post List", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_split_column_share_options_container"));
$panel11->addChild("blog_split_column_show_share",$blog_split_column_show_share);

$blog_split_column_share_options_container = new ElatedMooseContainer("blog_split_column_share_options_container","blog_split_column_show_share","no");
$panel11->addChild("blog_split_column_share_options_container",$blog_split_column_share_options_container);

$blog_split_column_select_share_option = new ElatedMooseField("select","blog_split_column_select_share_option","dropdown","Social Share Style","Choose Social Share Style for Split Column Type",array(
	"dropdown" => "Social Share Dropdown",
	"list" => "Social Share List"
));

$blog_split_column_share_options_container->addChild("blog_split_column_select_share_option",$blog_split_column_select_share_option);

$blog_split_column_share_icon_color = new ElatedMooseField("color","blog_split_column_share_icon_color","","Icon Color","Choose icon color for share dropdown");
$blog_split_column_share_options_container->addChild("blog_split_column_share_icon_color",$blog_split_column_share_icon_color);

$blog_split_column_share_hld_hover_icon_color = new ElatedMooseField("color","blog_split_column_share_hld_hover_icon_color","","Icon color on Quote/Link Holder Hover","Choose icon color for share dropdown when the quote/link holder is hovered over");
$blog_split_column_share_options_container->addChild("blog_split_column_share_hld_hover_icon_color",$blog_split_column_share_hld_hover_icon_color);

$blog_split_column_share_icon_hover_color = new ElatedMooseField("color","blog_split_column_share_icon_hover_color","","Icon Hover Color","Choose icon hover color for share dropdown");
$blog_split_column_share_options_container->addChild("blog_split_column_share_icon_hover_color",$blog_split_column_share_icon_hover_color);

$blog_split_column_share_background_color = new ElatedMooseField("color","blog_split_column_share_background_color","","Background Color","Choose background color for share dropdown list field");
$blog_split_column_share_options_container->addChild("blog_split_column_share_background_color",$blog_split_column_share_background_color);

$blog_split_column_show_like = new ElatedMooseField("yesno","blog_split_column_show_like","no","Show Likes",'Enabling this option will turn on "Likes"');
$panel11->addChild("blog_split_column_show_like",$blog_split_column_show_like);

$blog_split_column_post_design_style = new ElatedMooseTitle("blog_split_column_post_design_style", "Post Design Style");
$panel11->addChild("blog_split_column_post_design_style", $blog_split_column_post_design_style);

$blog_split_column_enable_text_box = new ElatedMooseField("yesno","blog_split_column_enable_text_box","no","Enable Boxed Styled Post Content","Enable post text boxed features", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_split_column_enable_text_box_container"));
$panel11->addChild("blog_split_column_enable_text_box",$blog_split_column_enable_text_box);

$blog_split_column_enable_text_box_container = new ElatedMooseContainer("blog_split_column_enable_text_box_container","blog_split_column_enable_text_box","no");
$panel11->addChild("blog_split_column_enable_text_box_container",$blog_split_column_enable_text_box_container);

$blog_split_column_box_background_color = new ElatedMooseField("color","blog_split_column_box_background_color","","Background Color","Choose background color for post text box");
$blog_split_column_enable_text_box_container->addChild("blog_split_column_box_background_color",$blog_split_column_box_background_color);

$blog_split_column_box_border_color = new ElatedMooseField("color","blog_split_column_box_border_color","","Border Color","Choose border color for post text box");
$blog_split_column_enable_text_box_container->addChild("blog_split_column_box_border_color",$blog_split_column_box_border_color);

$blog_split_column_box_padding = new ElatedMooseField("text","blog_split_column_box_padding","","Text box padding","Please insert padding in format (top right bottom left) i.e. 5px 5px 5px 5px", array(), array("col_width" => 3));
$blog_split_column_enable_text_box_container->addChild("blog_split_column_box_padding",$blog_split_column_box_padding);

$group8 = new ElatedMooseGroup("Paragraph","Set paragraph color");
$panel11->addChild("group8",$group8);

$blog_split_column_paragraph_color = new ElatedMooseField("colorsimple","blog_split_column_paragraph_color","","Color","This is some description");
$group8->addChild("blog_split_column_paragraph_color",$blog_split_column_paragraph_color);

$group1 = new ElatedMooseGroup("Quote/Link Background","Set background of Quote/Link post type");
$panel11->addChild("group1",$group1);

$row1 = new ElatedMooseRow();
$group1->addChild("row1",$row1);

$blog_split_column_ql_background_color = new ElatedMooseField("colorsimple","blog_split_column_ql_background_color","","Background Color","Default color is #ffffff.");
$row1->addChild("blog_split_column_ql_background_color",$blog_split_column_ql_background_color);

$blog_split_column_ql_hover_background_color = new ElatedMooseField("colorsimple","blog_split_column_ql_hover_background_color","","Background Hover Color","Default color is #e6ae48.");
$row1->addChild("blog_split_column_ql_hover_background_color",$blog_split_column_ql_hover_background_color);

$blog_split_column_show_ql_mark = new ElatedMooseField("yesno","blog_split_column_show_ql_mark","yes","Enable Quote/Link Icon","Show Icons for Quote/Link Post Format", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_split_column_show_ql_mark_container"));
$panel11->addChild("blog_split_column_show_ql_mark",$blog_split_column_show_ql_mark);

$blog_split_column_show_ql_mark_container = new ElatedMooseContainer("blog_split_column_show_ql_mark_container","blog_split_column_show_ql_mark","no");
$panel11->addChild("blog_split_column_show_ql_mark_container",$blog_split_column_show_ql_mark_container);

$row1 = new ElatedMooseRow();
$blog_split_column_show_ql_mark_container->addChild("row1",$row1);

$blog_split_column_ql_mark_color = new ElatedMooseField("color","blog_split_column_ql_mark_color","","Icon Color","Choose icon color for quote/link post.");
$row1->addChild("blog_split_column_ql_mark_color",$blog_split_column_ql_mark_color);

$blog_split_column_ql_mark_hover_color = new ElatedMooseField("color","blog_split_column_ql_mark_hover_color","","Icon Hover Color","Choose hover icon color for quote/link post.");
$row1->addChild("blog_split_column_ql_mark_hover_color",$blog_split_column_ql_mark_hover_color);

$group9 = new ElatedMooseGroup("Blog List Spacing","Set spacing for blog layouts");
$panel11->addChild("group9",$group9);

$row1 = new ElatedMooseRow();
$group9->addChild("row1",$row1);

$blog_split_column_title_margin_bottom = new ElatedMooseField("textsimple","blog_split_column_title_margin_bottom","","Margin Under Title (px)","This is some description");
$row1->addChild("blog_split_column_title_margin_bottom",$blog_split_column_title_margin_bottom);

$blog_split_column_post_info_margin_bottom = new ElatedMooseField("textsimple","blog_split_column_post_info_margin_bottom","","Margin Under Post Info (px)","This is some description");
$row1->addChild("blog_split_column_post_info_margin_bottom",$blog_split_column_post_info_margin_bottom);

$blog_split_column_read_more_margin_top = new ElatedMooseField("textsimple","blog_split_column_read_more_margin_top","","Margin Above Read More Button (px)","This is some description");
$row1->addChild("blog_split_column_read_more_margin_top",$blog_split_column_read_more_margin_top);

$blog_split_column_social_share_list_margin_top = new ElatedMooseField("textsimple","blog_split_column_social_share_list_margin_top","","Margin Above Social Share List (px)","This is some description");
$row1->addChild("blog_split_column_social_share_list_margin_top",$blog_split_column_social_share_list_margin_top);

$row2 = new ElatedMooseRow();
$group9->addChild("row2",$row2);

$blog_split_column_article_margin_bottom = new ElatedMooseField("textsimple","blog_split_column_article_margin_bottom","","Margin Between Articles (px)","This is some description");
$row1->addChild("blog_split_column_article_margin_bottom",$blog_split_column_article_margin_bottom);

$group10 = new ElatedMooseGroup("Blog List Spacing for Quote and Link Post Type","Set spacing for blog layouts");
$panel11->addChild("group10",$group10);

$row1 = new ElatedMooseRow();
$group10->addChild("row1",$row1);

$blog_split_column_ql_title_margin_bottom = new ElatedMooseField("textsimple","blog_split_column_ql_title_margin_bottom","","Margin Under Title (px)","This is some description");
$row1->addChild("blog_split_column_ql_title_margin_bottom",$blog_split_column_ql_title_margin_bottom);

$blog_split_column_ql_quote_author_margin_bottom = new ElatedMooseField("textsimple","blog_split_column_ql_quote_author_margin_bottom","","Margin Under Quote Author (px)","This is some description");
$row1->addChild("blog_split_column_ql_quote_author_margin_bottom",$blog_split_column_ql_quote_author_margin_bottom);

$blog_split_column_ql_share_list_margin_top = new ElatedMooseField("textsimple","blog_split_column_ql_share_list_margin_top","","Margin Above Social Share List (px)","This is some description");
$row1->addChild("blog_split_column_ql_share_list_margin_top",$blog_split_column_ql_share_list_margin_top);

$post_text_styling= new ElatedMooseTitle("post_text_styling", "Post Text Style");
$panel11->addChild("post_text_styling", $post_text_styling);

$group2 = new ElatedMooseGroup("Post Title","Define title styles in this blog post template.");
$panel11->addChild("group2",$group2);

$row1 = new ElatedMooseRow();
$group2->addChild("row1",$row1);

$blog_split_column_title_color = new ElatedMooseField("colorsimple","blog_split_column_title_color","","Text Color","This is some description");
$row1->addChild("blog_split_column_title_color",$blog_split_column_title_color);

$blog_split_column_title_hover_color = new ElatedMooseField("colorsimple","blog_split_column_title_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_split_column_title_hover_color",$blog_split_column_title_hover_color);

$blog_split_column_title_fontsize = new ElatedMooseField("textsimple","blog_split_column_title_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_split_column_title_fontsize",$blog_split_column_title_fontsize);

$blog_split_column_title_lineheight = new ElatedMooseField("textsimple","blog_split_column_title_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_split_column_title_lineheight",$blog_split_column_title_lineheight);

$row2 = new ElatedMooseRow(true);
$group2->addChild("row2",$row2);

$blog_split_column_title_google_fonts = new ElatedMooseField("fontsimple","blog_split_column_title_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_split_column_title_google_fonts",$blog_split_column_title_google_fonts);

$blog_split_column_title_fontstyle = new ElatedMooseField("selectblanksimple","blog_split_column_title_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_split_column_title_fontstyle",$blog_split_column_title_fontstyle);

$blog_split_column_title_fontweight = new ElatedMooseField("selectblanksimple","blog_split_column_title_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_split_column_title_fontweight",$blog_split_column_title_fontweight);

$blog_split_column_title_texttransform = new ElatedMooseField("selectblanksimple","blog_split_column_title_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_split_column_title_texttransform",$blog_split_column_title_texttransform);

$row3 = new ElatedMooseRow(true);
$group2->addChild("row3",$row3);

$blog_split_column_title_letterspacing = new ElatedMooseField("textsimple","blog_split_column_title_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_split_column_title_letterspacing",$blog_split_column_title_letterspacing);

$group4 = new ElatedMooseGroup("Post Info Data","Define post info text styles (date, category names etc.) Note: Single Posts will take the same styles as in list");
$panel11->addChild("group4",$group4);

$row1 = new ElatedMooseRow();
$group4->addChild("row1",$row1);

$blog_split_column_info_color = new ElatedMooseField("colorsimple","blog_split_column_info_color","","Text Color","This is some description");
$row1->addChild("blog_split_column_info_color",$blog_split_column_info_color);

$blog_split_column_info_link_color = new ElatedMooseField("colorsimple","blog_split_column_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_split_column_info_link_color",$blog_split_column_info_link_color);

$blog_split_column_info_hover_color = new ElatedMooseField("colorsimple","blog_split_column_info_hover_color","","Link Hover Color","This is some description");
$row1->addChild("blog_split_column_info_hover_color",$blog_split_column_info_hover_color);

$blog_split_column_info_fontsize = new ElatedMooseField("textsimple","blog_split_column_info_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_split_column_info_fontsize",$blog_split_column_info_fontsize);

$row2 = new ElatedMooseRow(true);
$group4->addChild("row2",$row2);

$blog_split_column_info_lineheight = new ElatedMooseField("textsimple","blog_split_column_info_lineheight","","Line Height (px)","This is some description");
$row2->addChild("blog_split_column_info_lineheight",$blog_split_column_info_lineheight);

$blog_split_column_info_google_fonts = new ElatedMooseField("fontsimple","blog_split_column_info_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_split_column_info_google_fonts",$blog_split_column_info_google_fonts);

$blog_split_column_info_fontstyle = new ElatedMooseField("selectblanksimple","blog_split_column_info_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_split_column_info_fontstyle",$blog_split_column_info_fontstyle);

$blog_split_column_info_fontweight = new ElatedMooseField("selectblanksimple","blog_split_column_info_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_split_column_info_fontweight",$blog_split_column_info_fontweight);

$row3 = new ElatedMooseRow(true);
$group4->addChild("row3",$row3);

$blog_split_column_info_link_fontweight = new ElatedMooseField("selectblanksimple","blog_split_column_info_link_fontweight","","Link Font Weight","This is some description",$eltd_moose_options_fontweight);
$row3->addChild("blog_split_column_info_link_fontweight",$blog_split_column_info_link_fontweight);

$blog_split_column_info_texttransform = new ElatedMooseField("selectblanksimple","blog_split_column_info_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row3->addChild("blog_split_column_info_texttransform",$blog_split_column_info_texttransform);

$blog_split_column_info_letterspacing = new ElatedMooseField("textsimple","blog_split_column_info_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_split_column_info_letterspacing",$blog_split_column_info_letterspacing);

$group3 = new ElatedMooseGroup("Quote/Link Title Style","Define title styles for Quote/Link articles");
$panel11->addChild("group3",$group3);

$row1 = new ElatedMooseRow();
$group3->addChild("row1",$row1);


$blog_split_column_ql_title_color = new ElatedMooseField("colorsimple","blog_split_column_ql_title_color","","Text Color","This is some description");
$row1->addChild("blog_split_column_ql_title_color",$blog_split_column_ql_title_color);

$blog_split_column_ql_title_hover_color = new ElatedMooseField("colorsimple","blog_split_column_ql_title_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_split_column_ql_title_hover_color",$blog_split_column_ql_title_hover_color);

$blog_split_column_ql_title_fontsize = new ElatedMooseField("textsimple","blog_split_column_ql_title_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_split_column_ql_title_font_size",$blog_split_column_ql_title_fontsize);


$row2 = new ElatedMooseRow(true);
$group3->addChild("row2",$row2);


$blog_split_column_ql_title_lineheight = new ElatedMooseField("textsimple","blog_split_column_ql_title_lineheight","","Line Height (px)","This is some description");
$row2->addChild("blog_split_column_ql_title_lineheight",$blog_split_column_ql_title_lineheight);

$blog_split_column_ql_title_google_fonts = new ElatedMooseField("fontsimple","blog_split_column_ql_title_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_split_column_ql_title_google_fonts",$blog_split_column_ql_title_google_fonts);

$blog_split_column_ql_title_fontstyle = new ElatedMooseField("selectblanksimple","blog_split_column_ql_title_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_split_column_ql_title_fontstyle",$blog_split_column_ql_title_fontstyle);

$blog_split_column_ql_title_fontweight = new ElatedMooseField("selectblanksimple","blog_split_column_ql_title_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_split_column_ql_title_fontweight",$blog_split_column_ql_title_fontweight);

$row3 = new ElatedMooseRow(true);
$group3->addChild("row3",$row3);

$blog_split_column_ql_title_texttransform = new ElatedMooseField("selectblanksimple","blog_split_column_ql_title_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row3->addChild("blog_split_column_ql_title_texttransform",$blog_split_column_ql_title_texttransform);

$blog_split_column_ql_title_letterspacing = new ElatedMooseField("textsimple","blog_split_column_ql_title_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_split_column_ql_title_letterspacing",$blog_split_column_ql_title_letterspacing);


$group5 = new ElatedMooseGroup("Quote/Link Post Info Data","Define quote/link post info text styles (date, category names etc.) Note: Single Posts will take the same styles as in list.");
$panel11->addChild("group5",$group5);

$row1 = new ElatedMooseRow();
$group5->addChild("row1",$row1);

$blog_split_column_ql_info_color = new ElatedMooseField("colorsimple","blog_split_column_ql_info_color","","Text Color","This is some description");
$row1->addChild("blog_split_column_ql_info_color",$blog_split_column_ql_info_color);

$blog_split_column_ql_info_link_color = new ElatedMooseField("colorsimple","blog_split_column_ql_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_split_column_ql_info_link_color",$blog_split_column_ql_info_link_color);

$blog_split_column_ql_info_hover_color = new ElatedMooseField("colorsimple","blog_split_column_ql_info_hover_color","","Link Hover Color","This is some description");
$row1->addChild("blog_split_column_ql_info_hover_color",$blog_split_column_ql_info_hover_color);

$blog_split_column_ql_info_fontsize = new ElatedMooseField("textsimple","blog_split_column_ql_info_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_split_column_ql_info_fontsize",$blog_split_column_ql_info_fontsize);

$row2 = new ElatedMooseRow(true);
$group5->addChild("row2",$row2);

$blog_split_column_ql_info_lineheight = new ElatedMooseField("textsimple","blog_split_column_ql_info_lineheight","","Line Height (px)","This is some description");
$row2->addChild("blog_split_column_ql_info_lineheight",$blog_split_column_ql_info_lineheight);

$blog_split_column_ql_info_google_fonts = new ElatedMooseField("fontsimple","blog_split_column_ql_info_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_split_column_ql_info_google_fonts",$blog_split_column_ql_info_google_fonts);

$blog_split_column_ql_info_fontstyle = new ElatedMooseField("selectblanksimple","blog_split_column_ql_info_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_split_column_ql_info_fontstyle",$blog_split_column_ql_info_fontstyle);

$blog_split_column_ql_info_fontweight = new ElatedMooseField("selectblanksimple","blog_split_column_ql_info_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_split_column_ql_info_fontweight",$blog_split_column_ql_info_fontweight);

$row3 = new ElatedMooseRow(true);
$group5->addChild("row3",$row3);

$blog_split_column_ql_info_link_fontweight = new ElatedMooseField("selectblanksimple","blog_split_column_ql_info_link_fontweight","","Link Font Weight","This is some description",$eltd_moose_options_fontweight);
$row3->addChild("blog_split_column_ql_info_link_fontweight",$blog_split_column_ql_info_link_fontweight);

$blog_split_column_ql_info_texttransform = new ElatedMooseField("selectblanksimple","blog_split_column_ql_info_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row3->addChild("blog_split_column_ql_info_texttransform",$blog_split_column_ql_info_texttransform);

$blog_split_column_ql_info_letterspacing = new ElatedMooseField("textsimple","blog_split_column_ql_info_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_split_column_ql_info_letterspacing",$blog_split_column_ql_info_letterspacing);

$group6 = new ElatedMooseGroup("Quote Author Style","Define author styles for Quote articles");
$panel11->addChild("group6",$group6);

$row1 = new ElatedMooseRow();
$group6->addChild("row1",$row1);

$blog_split_column_ql_author_color = new ElatedMooseField("colorsimple","blog_split_column_ql_author_color","","Text Color","This is some description");
$row1->addChild("blog_split_column_ql_author_color",$blog_split_column_ql_author_color);

$blog_split_column_ql_author_hover_color = new ElatedMooseField("colorsimple","blog_split_column_ql_author_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_split_column_ql_author_hover_color",$blog_split_column_ql_author_hover_color);

$blog_split_column_ql_author_fontsize = new ElatedMooseField("textsimple","blog_split_column_ql_author_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_split_column_ql_author_font_size",$blog_split_column_ql_author_fontsize);

$blog_split_column_ql_author_lineheight = new ElatedMooseField("textsimple","blog_split_column_ql_author_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_split_column_ql_author_lineheight",$blog_split_column_ql_author_lineheight);

$row2 = new ElatedMooseRow(true);
$group6->addChild("row2",$row2);

$blog_split_column_ql_author_texttransform = new ElatedMooseField("selectblanksimple","blog_split_column_ql_author_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_split_column_ql_author_texttransform",$blog_split_column_ql_author_texttransform);

$blog_split_column_ql_author_google_fonts = new ElatedMooseField("fontsimple","blog_split_column_ql_author_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_split_column_ql_author_google_fonts",$blog_split_column_ql_author_google_fonts);

$blog_split_column_ql_author_fontstyle = new ElatedMooseField("selectblanksimple","blog_split_column_ql_author_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_split_column_ql_author_fontstyle",$blog_split_column_ql_author_fontstyle);

$blog_split_column_ql_author_fontweight = new ElatedMooseField("selectblanksimple","blog_split_column_ql_author_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_split_column_ql_author_fontweight",$blog_split_column_ql_author_fontweight);

$row3 = new ElatedMooseRow(true);
$group6->addChild("row3",$row3);

$blog_split_column_ql_author_letterspacing = new ElatedMooseField("textsimple","blog_split_column_ql_author_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_split_column_ql_author_letterspacing",$blog_split_column_ql_author_letterspacing);

$group14 = new ElatedMooseGroup("Date Style","Define style for date box");
$panel11->addChild("group14",$group14);

$row1 = new ElatedMooseRow();
$group14->addChild("row1",$row1);

$blog_split_column_corner_date_color = new ElatedMooseField("colorsimple","blog_split_column_corner_date_color","","Text Color","This is some description");
$row1->addChild("blog_split_column_corner_date_color",$blog_split_column_corner_date_color);

$blog_split_column_corner_date_bckg_color = new ElatedMooseField("colorsimple","blog_split_column_corner_date_bckg_color","","Background Color","This is some description");
$row1->addChild("blog_split_column_corner_date_bckg_color",$blog_split_column_corner_date_bckg_color);

$group15 = new ElatedMooseGroup("Comments Style","Define style for comments box");
$panel11->addChild("group15",$group15);

$row1 = new ElatedMooseRow();
$group15->addChild("row1",$row1);

$blog_split_column_corner_comments_color = new ElatedMooseField("colorsimple","blog_split_column_corner_comments_color","","Text Color","This is some description");
$row1->addChild("blog_split_column_corner_comments_color",$blog_split_column_corner_comments_color);

$blog_split_column_corner_comments_bckg_color = new ElatedMooseField("colorsimple","blog_split_column_corner_comments_bckg_color","","Background Color","This is some description");
$row1->addChild("blog_split_column_corner_comments_bckg_color",$blog_split_column_corner_comments_bckg_color);

// Blog Post List - Blog: Standard
$panel21 = new ElatedMoosePanel("Blog List Template Options: Standard","blog_standard_type_post_lists", "blog_standard_type_show_options", "no");
$blogPage->addChild("panel21",$panel21);

$blog_standard_type_number_of_chars = new ElatedMooseField("text","blog_standard_type_number_of_chars","45","Number of Words in Excerpt",' Enter a number of words in excerpt (article summary)', array(), array("col_width" => 3));
$panel21->addChild("blog_standard_type_number_of_chars",$blog_standard_type_number_of_chars);

$blog_standard_type_image_size = new ElatedMooseField("select","blog_standard_type_image_size","full","Blog Image Size","Choose image size for Post List", array(
    "full" => "Default",
    "portfolio-landscape" => "Landscape",
    "portfolio-portrait" => "Portrait",
    "custom" => "Custom"
),
    array("dependence" => true,
        "hide" => array(
            "full"=>"#eltdf_blog_standard_type_image_size_container",
            "portfolio-landscape"=>"#eltdf_blog_standard_type_image_size_container",
            "portfolio-portrait"=>"#eltdf_blog_standard_type_image_size_container",
            "custom"=>""
        ),
        "show" => array(
            "full"=>"",
            "portfolio-landscape"=>"",
            "portfolio-portrait"=>"",
            "custom"=>"#eltdf_blog_standard_type_image_size_container"
        )
    )
);
$panel21->addChild("blog_standard_type_image_size",$blog_standard_type_image_size);

$blog_standard_type_image_size_container = new ElatedMooseContainer("blog_standard_type_image_size_container","blog_standard_type_image_size","", array( "full","portfolio-landscape","portfolio-portrait"));
$panel21->addChild("blog_standard_type_image_size_container",$blog_standard_type_image_size_container);

$blog_standard_type_image_size_height = new ElatedMooseField("text","blog_standard_type_image_size_height","","Image Height (px)","Enter width (in pixels) for Custom Image for Post List", array(), array("col_width" => 3));
$blog_standard_type_image_size_container->addChild("blog_standard_type_image_size_height",$blog_standard_type_image_size_height);

$blog_standard_type_image_size_width = new ElatedMooseField("text","blog_standard_type_image_size_width","","Image Width (px)","Enter width (in pixels) for Custom Image for Post List", array(), array("col_width" => 3));
$blog_standard_type_image_size_container->addChild("blog_standard_type_image_size_width",$blog_standard_type_image_size_width);

$blog_standard_type_read_more_button = new ElatedMooseField("yesno","blog_standard_type_read_more_button","yes","Read More Button","Enable Read More Button", array(),
    array("dependence" => true,
        "dependence_hide_on_yes" => "",
        "dependence_show_on_yes" => "#eltdf_blog_standard_type_read_more_button_container"));
$panel21->addChild("blog_standard_type_read_more_button",$blog_standard_type_read_more_button);

$blog_standard_type_read_more_button_container = new ElatedMooseContainer("blog_standard_type_read_more_button_container","blog_standard_type_read_more_button","no");
$panel21->addChild("blog_standard_type_read_more_button_container",$blog_standard_type_read_more_button_container);

$blog_standard_type_read_more_button_icon = new ElatedMooseField("yesno","blog_standard_type_read_more_button_icon","no","Enable Icon","Enabling this option will place icon in read more button", array(),
    array("dependence" => true,
        "dependence_hide_on_yes" => "",
        "dependence_show_on_yes" => "#eltdf_blog_standard_type_read_more_button_icon_container"));
$blog_standard_type_read_more_button_container->addChild("blog_standard_type_read_more_button_icon",$blog_standard_type_read_more_button_icon);

$blog_standard_type_read_more_button_icon_container = new ElatedMooseContainer("blog_standard_type_read_more_button_icon_container","blog_standard_type_read_more_button_icon","no");
$blog_standard_type_read_more_button_container->addChild("blog_standard_type_read_more_button_icon_container",$blog_standard_type_read_more_button_icon_container);

//init icon pack hide and show array. It will be populated dinamically from collections array
$blog_standard_type_read_more_button_icon_pack_hide_array = array();
$blog_standard_type_read_more_button_icon_pack_show_array = array();

//do we have some collection added in collections array?
if(is_array($eltdIconCollections->iconCollections) && count($eltdIconCollections->iconCollections)) {
    //get collections params array. It will contain values of 'param' property for each collection
    $blog_standard_type_read_more_button_icon_collections_params = $eltdIconCollections->getIconCollectionsParams();

    //foreach collection generate hide and show array
    foreach ($eltdIconCollections->iconCollections as $dep_collection_key => $dep_collection_object) {
        $blog_standard_type_read_more_button_icon_pack_hide_array[$dep_collection_key] = '';

        //we need to include only current collection in show string as it is the only one that needs to show
        $blog_standard_type_read_more_button_icon_pack_show_array[$dep_collection_key] = '#eltdf_blog_standard_type_read_more_button_icon_'.$dep_collection_object->param.'_container';

        //for all collections param generate hide string
        foreach ($blog_standard_type_read_more_button_icon_collections_params as $blog_standard_type_read_more_button_icon_collections_param) {
            //we don't need to include current one, because it needs to be shown, not hidden
            if($blog_standard_type_read_more_button_icon_collections_param !== $dep_collection_object->param) {
                $blog_standard_type_read_more_button_icon_pack_hide_array[$dep_collection_key].= '#eltdf_blog_standard_type_read_more_button_icon_'.$blog_standard_type_read_more_button_icon_collections_param.'_container,';
            }
        }

        //remove remaining ',' character
        $blog_standard_type_read_more_button_icon_pack_hide_array[$dep_collection_key] = rtrim($blog_standard_type_read_more_button_icon_pack_hide_array[$dep_collection_key], ',');
    }

}

$blog_standard_type_read_more_button_icon_pack = new ElatedMooseField(
    "select",
    "blog_standard_type_read_more_button_icon_pack",
    "font_awesome",
    "Icon Pack",
    "Choose icon pack for show load more button",
    $eltdIconCollections->getIconCollections(),
    array(
        "dependence" => true,
        "hide" => $blog_standard_type_read_more_button_icon_pack_hide_array,
        "show" => $blog_standard_type_read_more_button_icon_pack_show_array
    ));

$blog_standard_type_read_more_button_icon_container->addChild("blog_standard_type_read_more_button_icon_pack", $blog_standard_type_read_more_button_icon_pack);

if(is_array($eltdIconCollections->iconCollections) && count($eltdIconCollections->iconCollections)) {
    //foreach icon collection we need to generate separate container that will have dependency set
    //it will have one field inside with icons dropdown
    foreach ($eltdIconCollections->iconCollections as $collection_key => $collection_object) {
        $icons_array = $collection_object->getIconsArray();

        //get icon collection keys (keys from collections array, e.g 'font_awesome', 'font_elegant' etc.)
        $icon_collections_keys = $eltdIconCollections->getIconCollectionsKeys();

        //unset current one, because it doesn't have to be included in dependency that hides icon container
        unset($icon_collections_keys[array_search($collection_key, $icon_collections_keys)]);

        $blog_standard_type_read_more_button_icon_hide_values = $icon_collections_keys;
        $blog_icon_container = new ElatedMooseContainer("blog_standard_type_read_more_button_icon_".$collection_object->param."_container", "blog_standard_type_read_more_button_icon_pack", "", $blog_standard_type_read_more_button_icon_hide_values);
        $blog_standard_type_read_more_button_icon = new ElatedMooseField("select", "blog_standard_type_read_more_button_icon_".$collection_object->param, "", "Button Icon","Choose Button Icon", $icons_array, array("col_width" => 3));
        $blog_icon_container->addChild("blog_standard_type_read_more_button_icon_".$collection_object->param, $blog_standard_type_read_more_button_icon);

        $blog_standard_type_read_more_button_icon_container->addChild("blog_standard_type_read_more_button_icon_".$collection_object->param."_container", $blog_icon_container);
    }

}


$blog_standard_type_content_position = new ElatedMooseField("select","blog_standard_type_content_position","content_above_blog_list","Content Position","Choose content position for blog list template when sidebar is enabled. Note: This settings in only for template, not for archive pages", array(
	"content_above_blog_list" => "Content Above Blog List",
	"content_above_blog_list_and_sidebar" => "Content Above Blog List and Sidebar"
));
$panel21->addChild("blog_standard_type_content_position",$blog_standard_type_content_position);

$blog_standard_type_post_meta_data_section = new ElatedMooseTitle("blog_standard_type_post_meta_data_section", "Post Info Data Fields");
$panel21->addChild("blog_standard_type_post_meta_data_section", $blog_standard_type_post_meta_data_section);

$blog_standard_type_show_categories = new ElatedMooseField("yesno","blog_standard_type_show_categories","yes","Show Categories","Enabling this option will Show Categories on Post List");
$panel21->addChild("blog_standard_type_show_categories",$blog_standard_type_show_categories);

$blog_standard_type_show_comments = new ElatedMooseField("yesno","blog_standard_type_show_comments","yes","Show Comments","Enabling this option will Show Comments on Post List");
$panel21->addChild("blog_standard_type_show_comments",$blog_standard_type_show_comments);

$blog_standard_type_show_author = new ElatedMooseField("yesno","blog_standard_type_show_author","yes","Show Author Name","Enabling this option will show author name on Post List and Blog Post Single");
$panel21->addChild("blog_standard_type_show_author",$blog_standard_type_show_author);

$blog_standard_type_show_date = new ElatedMooseField("yesno","blog_standard_type_show_date","yes","Show Date","Enabling this option will show date on Post List");
$panel21->addChild("blog_standard_type_hide_date",$blog_standard_type_show_date);

$blog_standard_type_show_share = new ElatedMooseField("yesno","blog_standard_type_show_share","no","Show Share","Enabling this option will show share on Post List", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_standard_type_share_options_container"));
$panel21->addChild("blog_standard_type_show_share",$blog_standard_type_show_share);

$blog_standard_type_share_options_container = new ElatedMooseContainer("blog_standard_type_share_options_container","blog_standard_type_show_share","no");
$panel21->addChild("blog_standard_type_share_options_container",$blog_standard_type_share_options_container);

$blog_standard_type_select_share_option = new ElatedMooseField("select","blog_standard_type_select_share_option","dropdown","Social Share Style","Choose Social Share Style for Standard Type",array(
	"dropdown" => "Social Share Dropdown",
	"list" => "Social Share List"
), array("dependence" => true,
	"hide" => array("dropdown" => "#eltdf_blog_standard_type_share_list_type_container", "list" => "#eltdf_blog_standard_type_share_dropdown_type_container"),
	"show" => array("dropdown" => "#eltdf_blog_standard_type_share_dropdown_type_container", "list" => "#eltdf_blog_standard_type_share_list_type_container")
));

$blog_standard_type_share_options_container->addChild("blog_standard_type_select_share_option",$blog_standard_type_select_share_option);

$blog_standard_type_share_list_type_container = new ElatedMooseContainer("blog_standard_type_share_list_type_container","blog_standard_type_select_share_option", "dropdown");
$blog_standard_type_share_options_container->addChild("blog_standard_type_share_list_type_container",$blog_standard_type_share_list_type_container);

	$blog_standard_type_share_hld_hover_icon_color = new ElatedMooseField("color","blog_standard_type_share_hld_hover_icon_color","","Icon color on Quote/Link Holder Hover","Choose icon color for list share type when the quote/link holder is hovered over");
	$blog_standard_type_share_list_type_container->addChild("blog_standard_type_share_hld_hover_icon_color",$blog_standard_type_share_hld_hover_icon_color);

$blog_standard_type_share_dropdown_type_container = new ElatedMooseContainer("blog_standard_type_share_dropdown_type_container","blog_standard_type_select_share_option", "list");
$blog_standard_type_share_options_container->addChild("blog_standard_type_share_dropdown_type_container",$blog_standard_type_share_dropdown_type_container);

	$blog_standard_type_share_background_color = new ElatedMooseField("color","blog_standard_type_share_background_color","","Background Color","Choose background color for dropdown share type");
	$blog_standard_type_share_dropdown_type_container->addChild("blog_standard_type_share_background_color",$blog_standard_type_share_background_color);

	$blog_standard_type_share_background_color_link_post_type = new ElatedMooseField("color","blog_standard_type_share_background_color_link_post_type","","Background Color on Quote/Link Post Type","Choose background color for dropdown share type on quote post type");
	$blog_standard_type_share_dropdown_type_container->addChild("blog_standard_type_share_background_color_link_post_type",$blog_standard_type_share_background_color_link_post_type);

$blog_standard_type_share_icon_color = new ElatedMooseField("color","blog_standard_type_share_icon_color","","Icon Color","Choose icon color for dropdown and list share type");
$blog_standard_type_share_options_container->addChild("blog_standard_type_share_icon_color",$blog_standard_type_share_icon_color);

$blog_standard_type_share_icon_hover_color = new ElatedMooseField("color","blog_standard_type_share_icon_hover_color","","Icon Hover Color","Choose icon hover color for dropdown and list Share Type");
$blog_standard_type_share_options_container->addChild("blog_standard_type_share_icon_hover_color",$blog_standard_type_share_icon_hover_color);

$blog_standard_type_share_icon_color_link_post_type = new ElatedMooseField("color","blog_standard_type_share_icon_color_link_post_type","","Icon Color For Quote/Link Post Type","Choose icon color for dropdown and list share type for quote post type");
$blog_standard_type_share_options_container->addChild("blog_standard_type_share_icon_color_link_post_type",$blog_standard_type_share_icon_color_link_post_type);

$blog_standard_type_share_icon_hover_color_link_post_type  = new ElatedMooseField("color","blog_standard_type_share_icon_hover_color_link_post_type","","Icon Hover Color For Quote/Link Post Type","Choose icon hover color for dropdown and list Share Type for quote post type");
$blog_standard_type_share_options_container->addChild("blog_standard_type_share_icon_hover_color_link_post_type",$blog_standard_type_share_icon_hover_color_link_post_type);

$blog_standard_type_show_like = new ElatedMooseField("yesno","blog_standard_type_show_like","no","Show Likes",'Enabling this option will turn on "Likes"');
$panel21->addChild("blog_standard_type_show_like",$blog_standard_type_show_like);

$blog_standard_type_post_design_style = new ElatedMooseTitle("blog_standard_type_post_design_style", "Post Design Style");
$panel21->addChild("blog_standard_type_post_design_style", $blog_standard_type_post_design_style);

$blog_standard_type_enable_text_box = new ElatedMooseField("yesno","blog_standard_type_enable_text_box","no","Enable Boxed Styled Post Content","Enable post text boxed features", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_standard_type_enable_text_box_container"));
$panel21->addChild("blog_standard_type_enable_text_box",$blog_standard_type_enable_text_box);

$blog_standard_type_enable_text_box_container = new ElatedMooseContainer("blog_standard_type_enable_text_box_container","blog_standard_type_enable_text_box","no");
$panel21->addChild("blog_standard_type_enable_text_box_container",$blog_standard_type_enable_text_box_container);

$blog_standard_type_box_background_color = new ElatedMooseField("color","blog_standard_type_box_background_color","","Background Color","Choose background color for post text box");
$blog_standard_type_enable_text_box_container->addChild("blog_standard_type_box_background_color",$blog_standard_type_box_background_color);

$blog_standard_type_box_border_color = new ElatedMooseField("color","blog_standard_type_box_border_color","","Border Color","Choose border color for post text box");
$blog_standard_type_enable_text_box_container->addChild("blog_standard_type_box_border_color",$blog_standard_type_box_border_color);

$blog_standard_type_box_padding = new ElatedMooseField("text","blog_standard_type_box_padding","","Text box padding","Please insert padding in format (top right bottom left) i.e. 5px 5px 5px 5px", array(), array("col_width" => 3));
$blog_standard_type_enable_text_box_container->addChild("blog_standard_type_box_padding",$blog_standard_type_box_padding);

$group10 = new ElatedMooseGroup("Paragraph","Set paragraph color");
$panel21->addChild("group10",$group10);

$blog_standard_type_paragraph_color = new ElatedMooseField("colorsimple","blog_standard_type_paragraph_color","","Color","This is some description");
$group10->addChild("blog_standard_type_paragraph_color",$blog_standard_type_paragraph_color);

$group1 = new ElatedMooseGroup("Quote/Link Background","Set background of Quote/Link post type");
$panel21->addChild("group1",$group1);

$row1 = new ElatedMooseRow();
$group1->addChild("row1",$row1);

$blog_standard_type_ql_background_image = new ElatedMooseField("yesnosimple","blog_standard_type_ql_background_image","yes","Background Image","");
$row1->addChild("blog_standard_type_ql_background_image",$blog_standard_type_ql_background_image);

$blog_standard_type_ql_background_color = new ElatedMooseField("colorsimple","blog_standard_type_ql_background_color","","Background Color","Default color is #ffffff.");
$row1->addChild("blog_standard_type_ql_background_color",$blog_standard_type_ql_background_color);

$blog_standard_type_ql_hover_background_color = new ElatedMooseField("colorsimple","blog_standard_type_ql_hover_background_color","","Background Hover Color","Default color is #e6ae48.");
$row1->addChild("blog_standard_type_ql_hover_background_color",$blog_standard_type_ql_hover_background_color);

$blog_standard_type_show_ql_mark = new ElatedMooseField("yesno","blog_standard_type_show_ql_mark","yes","Enable Quote/Link Icon","Show Icons for Quote/Link Post Format", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_standard_type_show_ql_mark_container"));
$panel21->addChild("blog_standard_type_show_ql_mark",$blog_standard_type_show_ql_mark);

$blog_standard_type_show_ql_mark_container = new ElatedMooseContainer("blog_standard_type_show_ql_mark_container","blog_standard_type_show_ql_mark","no");
$panel21->addChild("blog_standard_type_show_ql_mark_container",$blog_standard_type_show_ql_mark_container);

$row1 = new ElatedMooseRow();
$blog_standard_type_show_ql_mark_container->addChild("row1",$row1);

$blog_standard_type_ql_mark_color = new ElatedMooseField("color","blog_standard_type_ql_mark_color","","Icon Color","Choose icon color for quote/link post.");
$row1->addChild("blog_standard_type_ql_mark_color",$blog_standard_type_ql_mark_color);

$blog_standard_type_ql_mark_hover_color = new ElatedMooseField("color","blog_standard_type_ql_mark_hover_color","","Icon Hover Color","Choose hover icon color for quote/link post.");
$row1->addChild("blog_standard_type_ql_mark_hover_color",$blog_standard_type_ql_mark_hover_color);

$group11 = new ElatedMooseGroup("Blog List Spacing","Set spacing for blog layouts");
$panel21->addChild("group11",$group11);

$row1 = new ElatedMooseRow();
$group11->addChild("row1",$row1);

$blog_standard_type_image_margin_bottom = new ElatedMooseField("textsimple","blog_standard_type_image_margin_bottom","","Margin Under Image (px)","This is some description");
$row1->addChild("blog_standard_type_image_margin_bottom",$blog_standard_type_image_margin_bottom);

$blog_standard_type_title_margin_bottom = new ElatedMooseField("textsimple","blog_standard_type_title_margin_bottom","","Margin Under Title (px)","This is some description");
$row1->addChild("blog_standard_type_title_margin_bottom",$blog_standard_type_title_margin_bottom);

$blog_standard_type_read_more_margin_top = new ElatedMooseField("textsimple","blog_standard_type_read_more_margin_top","","Margin Above Read More Button (px)","This is some description");
$row1->addChild("blog_standard_type_read_more_margin_top",$blog_standard_type_read_more_margin_top);

$blog_standard_type_post_info_margin_bottom = new ElatedMooseField("textsimple","blog_standard_type_post_info_margin_bottom","","Margin Under Post Info (px)","This is some description");
$row1->addChild("blog_standard_type_post_info_margin_bottom",$blog_standard_type_post_info_margin_bottom);

$row2 = new ElatedMooseRow();
$group11->addChild("row2",$row2);

$blog_standard_type_article_margin_bottom = new ElatedMooseField("textsimple","blog_standard_type_article_margin_bottom","","Margin Between Articles (px)","This is some description");
$row2->addChild("blog_standard_type_article_margin_bottom",$blog_standard_type_article_margin_bottom);

$blog_standard_type_single_article_social_share_list_margin_top = new ElatedMooseField("textsimple","blog_standard_type_single_article_social_share_list_margin_top","","Margin Above Social Share List Holder (px)","This is some description");
$row2->addChild("blog_standard_type_single_article_social_share_list_margin_top",$blog_standard_type_single_article_social_share_list_margin_top);

$group12 = new ElatedMooseGroup("Blog List Spacing for Quote and Link Post Type","Set spacing for blog layouts");
$panel21->addChild("group12",$group12);

$row1 = new ElatedMooseRow();
$group12->addChild("row1",$row1);

$blog_standard_type_ql_title_margin_bottom = new ElatedMooseField("textsimple","blog_standard_type_ql_title_margin_bottom","","Margin Under Title (px)","This is some description");
$row1->addChild("blog_standard_type_ql_title_margin_bottom",$blog_standard_type_ql_title_margin_bottom);

$blog_standard_type_ql_social_share_list_margin_top = new ElatedMooseField("textsimple","blog_standard_type_ql_social_share_list_margin_top","","Margin Above Social Share List (px)","This is some description");
$row1->addChild("blog_standard_type_ql_social_share_list_margin_top",$blog_standard_type_ql_social_share_list_margin_top);

$blog_standard_type_ql_quote_author_margin_bottom = new ElatedMooseField("textsimple","blog_standard_type_ql_quote_author_margin_bottom","","Margin Under Quote Author (px)","This is some description");
$row1->addChild("blog_standard_type_ql_quote_author_margin_bottom",$blog_standard_type_ql_quote_author_margin_bottom);

$post_text_styling= new ElatedMooseTitle("post_text_styling", "Post Text Style");
$panel21->addChild("post_text_styling", $post_text_styling);

$group5 = new ElatedMooseGroup("Post Title","Define title styles in this blog post template.");
$panel21->addChild("group5",$group5);

$row1 = new ElatedMooseRow();
$group5->addChild("row1",$row1);

$blog_standard_type_title_color = new ElatedMooseField("colorsimple","blog_standard_type_title_color","","Text Color","This is some description");
$row1->addChild("blog_standard_type_title_color",$blog_standard_type_title_color);

$blog_standard_type_title_hover_color = new ElatedMooseField("colorsimple","blog_standard_type_title_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_standard_type_title_hover_color",$blog_standard_type_title_hover_color);

$blog_standard_type_title_fontsize = new ElatedMooseField("textsimple","blog_standard_type_title_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_standard_type_title_fontsize",$blog_standard_type_title_fontsize);

$blog_standard_type_title_lineheight = new ElatedMooseField("textsimple","blog_standard_type_title_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_standard_type_title_lineheight",$blog_standard_type_title_lineheight);

$row2 = new ElatedMooseRow(true);
$group5->addChild("row2",$row2);

$blog_standard_type_title_texttransform = new ElatedMooseField("selectblanksimple","blog_standard_type_title_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_standard_type_title_texttransform",$blog_standard_type_title_texttransform);

$blog_standard_type_title_google_fonts = new ElatedMooseField("fontsimple","blog_standard_type_title_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_standard_type_title_google_fonts",$blog_standard_type_title_google_fonts);

$blog_standard_type_title_fontstyle = new ElatedMooseField("selectblanksimple","blog_standard_type_title_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_standard_type_title_fontstyle",$blog_standard_type_title_fontstyle);

$blog_standard_type_title_fontweight = new ElatedMooseField("selectblanksimple","blog_standard_type_title_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_standard_type_title_fontweight",$blog_standard_type_title_fontweight);

$row3 = new ElatedMooseRow(true);
$group5->addChild("row3",$row3);

$blog_standard_type_title_letterspacing = new ElatedMooseField("textsimple","blog_standard_type_title_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_standard_type_title_letterspacing",$blog_standard_type_title_letterspacing);

$group7 = new ElatedMooseGroup("Post Info Data","Define post info text styles (date, category names etc.) Note: Single Posts will take the same styles as in list");
$panel21->addChild("group7",$group7);

$row1 = new ElatedMooseRow();
$group7->addChild("row1",$row1);

$blog_standard_type_info_color = new ElatedMooseField("colorsimple","blog_standard_type_info_color","","Text Color","This is some description");
$row1->addChild("blog_standard_type_info_color",$blog_standard_type_info_color);

$blog_standard_type_info_link_color = new ElatedMooseField("colorsimple","blog_standard_type_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_standard_type_info_link_color",$blog_standard_type_info_link_color);

$blog_standard_type_info_hover_color = new ElatedMooseField("colorsimple","blog_standard_type_info_hover_color","","Link Hover Color","This is some description");
$row1->addChild("blog_standard_type_info_hover_color",$blog_standard_type_info_hover_color);

$blog_standard_type_info_fontsize = new ElatedMooseField("textsimple","blog_standard_type_info_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_standard_type_info_fontsize",$blog_standard_type_info_fontsize);

$row2 = new ElatedMooseRow(true);
$group7->addChild("row2",$row2);

$blog_standard_type_info_lineheight = new ElatedMooseField("textsimple","blog_standard_type_info_lineheight","","Line Height (px)","This is some description");
$row2->addChild("blog_standard_type_info_lineheight",$blog_standard_type_info_lineheight);

$blog_standard_type_info_google_fonts = new ElatedMooseField("fontsimple","blog_standard_type_info_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_standard_type_info_google_fonts",$blog_standard_type_info_google_fonts);

$blog_standard_type_info_fontstyle = new ElatedMooseField("selectblanksimple","blog_standard_type_info_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_standard_type_info_fontstyle",$blog_standard_type_info_fontstyle);

$blog_standard_type_info_fontweight = new ElatedMooseField("selectblanksimple","blog_standard_type_info_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_standard_type_info_fontweight",$blog_standard_type_info_fontweight);

$row3 = new ElatedMooseRow(true);
$group7->addChild("row3",$row3);

$blog_standard_type_info_link_fontweight = new ElatedMooseField("selectblanksimple","blog_standard_type_info_link_fontweight","","Link Font Weight","This is some description",$eltd_moose_options_fontweight);
$row3->addChild("blog_standard_type_info_link_fontweight",$blog_standard_type_info_link_fontweight);

$blog_standard_type_info_texttransform = new ElatedMooseField("selectblanksimple","blog_standard_type_info_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row3->addChild("blog_standard_type_info_texttransform",$blog_standard_type_info_texttransform);

$blog_standard_type_info_letterspacing = new ElatedMooseField("textsimple","blog_standard_type_info_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_standard_type_info_letterspacing",$blog_standard_type_info_letterspacing);

$group2 = new ElatedMooseGroup("Date Style","Define style for date box");
$panel21->addChild("group2",$group2);

	$row1 = new ElatedMooseRow();
	$group2->addChild("row1",$row1);

		$blog_standard_type_date_color = new ElatedMooseField("colorsimple","blog_standard_type_date_color","","Text Color","This is some description");
		$row1->addChild("blog_standard_type_date_color",$blog_standard_type_date_color);
	
		$blog_standard_type_date_bckg_color = new ElatedMooseField("colorsimple","blog_standard_type_date_bckg_color","","Background Color","This is some description");
		$row1->addChild("blog_standard_type_date_bckg_color",$blog_standard_type_date_bckg_color);

$group3 = new ElatedMooseGroup("Comments Style","Define style for comments box");
$panel21->addChild("group3",$group3);

	$row1 = new ElatedMooseRow();
	$group3->addChild("row1",$row1);

		$blog_standard_type_cmmt_color = new ElatedMooseField("colorsimple","blog_standard_type_cmmt_color","","Text Color","This is some description");
		$row1->addChild("blog_standard_type_cmmt_color",$blog_standard_type_cmmt_color);
	
		$blog_standard_type_cmmt_bckg_color = new ElatedMooseField("colorsimple","blog_standard_type_cmmt_bckg_color","","Background Color","This is some description");
		$row1->addChild("blog_standard_type_cmmt_bckg_color",$blog_standard_type_cmmt_bckg_color);

$group6 = new ElatedMooseGroup("Quote/Link Title Style","Define title styles for Quote/Link articles");
$panel21->addChild("group6",$group6);

$row1 = new ElatedMooseRow();
$group6->addChild("row1",$row1);

$blog_standard_type_ql_title_color = new ElatedMooseField("colorsimple","blog_standard_type_ql_title_color","","Text Color","This is some description");
$row1->addChild("blog_standard_type_ql_title_color",$blog_standard_type_ql_title_color);

$blog_standard_type_ql_title_hover_color = new ElatedMooseField("colorsimple","blog_standard_type_ql_title_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_standard_type_ql_title_hover_color",$blog_standard_type_ql_title_hover_color);

$blog_standard_type_ql_title_fontsize = new ElatedMooseField("textsimple","blog_standard_type_ql_title_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_standard_type_ql_title_font_size",$blog_standard_type_ql_title_fontsize);

$blog_standard_type_ql_title_lineheight = new ElatedMooseField("textsimple","blog_standard_type_ql_title_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_standard_type_ql_title_lineheight",$blog_standard_type_ql_title_lineheight);


$row2 = new ElatedMooseRow(true);
$group6->addChild("row2",$row2);

$blog_standard_type_ql_title_texttransform = new ElatedMooseField("selectblanksimple","blog_standard_type_ql_title_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_standard_type_ql_title_texttransform",$blog_standard_type_ql_title_texttransform);

$blog_standard_type_ql_title_google_fonts = new ElatedMooseField("fontsimple","blog_standard_type_ql_title_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_standard_type_ql_title_google_fonts",$blog_standard_type_ql_title_google_fonts);

$blog_standard_type_ql_title_fontstyle = new ElatedMooseField("selectblanksimple","blog_standard_type_ql_title_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_standard_type_ql_title_fontstyle",$blog_standard_type_ql_title_fontstyle);

$blog_standard_type_ql_title_fontweight = new ElatedMooseField("selectblanksimple","blog_standard_type_ql_title_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_standard_type_ql_title_fontweight",$blog_standard_type_ql_title_fontweight);

$row3 = new ElatedMooseRow(true);
$group6->addChild("row3",$row3);

$blog_standard_type_ql_title_letterspacing = new ElatedMooseField("textsimple","blog_standard_type_ql_title_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_standard_type_ql_title_letterspacing",$blog_standard_type_ql_title_letterspacing);

$group8 = new ElatedMooseGroup("Quote/Link Post Info Data","Define quote/link post info text styles (date, category names etc.) Note: Single Posts will take the same styles as in list.");
$panel21->addChild("group8",$group8);

$row1 = new ElatedMooseRow();
$group8->addChild("row1",$row1);

$blog_standard_type_ql_info_color = new ElatedMooseField("colorsimple","blog_standard_type_ql_info_color","","Text Color","This is some description");
$row1->addChild("blog_standard_type_ql_info_color",$blog_standard_type_ql_info_color);

$blog_standard_type_ql_info_link_color = new ElatedMooseField("colorsimple","blog_standard_type_ql_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_standard_type_ql_info_link_color",$blog_standard_type_ql_info_link_color);

$blog_standard_type_ql_info_hover_color = new ElatedMooseField("colorsimple","blog_standard_type_ql_info_hover_color","","Hover Color","This is some description");
$row1->addChild("blog_standard_type_ql_info_hover_color",$blog_standard_type_ql_info_hover_color);

$blog_standard_type_ql_info_fontsize = new ElatedMooseField("textsimple","blog_standard_type_ql_info_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_standard_type_ql_info_fontsize",$blog_standard_type_ql_info_fontsize);

$row2 = new ElatedMooseRow(true);
$group8->addChild("row2",$row2);


$blog_standard_type_ql_info_lineheight = new ElatedMooseField("textsimple","blog_standard_type_ql_info_lineheight","","Line Height (px)","This is some description");
$row2->addChild("blog_standard_type_ql_info_lineheight",$blog_standard_type_ql_info_lineheight);

$blog_standard_type_ql_info_google_fonts = new ElatedMooseField("fontsimple","blog_standard_type_ql_info_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_standard_type_ql_info_google_fonts",$blog_standard_type_ql_info_google_fonts);

$blog_standard_type_ql_info_fontstyle = new ElatedMooseField("selectblanksimple","blog_standard_type_ql_info_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_standard_type_ql_info_fontstyle",$blog_standard_type_ql_info_fontstyle);

$blog_standard_type_ql_info_fontweight = new ElatedMooseField("selectblanksimple","blog_standard_type_ql_info_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_standard_type_ql_info_fontweight",$blog_standard_type_ql_info_fontweight);

$row3 = new ElatedMooseRow(true);
$group8->addChild("row3",$row3);

$blog_standard_type_ql_info_link_fontweight = new ElatedMooseField("selectblanksimple","blog_standard_type_ql_info_link_fontweight","","Link Font Weight","This is some description",$eltd_moose_options_fontweight);
$row3->addChild("blog_standard_type_ql_info_link_fontweight",$blog_standard_type_ql_info_link_fontweight);

$blog_standard_type_ql_info_texttransform = new ElatedMooseField("selectblanksimple","blog_standard_type_ql_info_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row3->addChild("blog_standard_type_ql_info_texttransform",$blog_standard_type_ql_info_texttransform);

$blog_standard_type_ql_info_letterspacing = new ElatedMooseField("textsimple","blog_standard_type_ql_info_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_standard_type_ql_info_letterspacing",$blog_standard_type_ql_info_letterspacing);

$group9 = new ElatedMooseGroup("Quote Author Style","Define author styles for Quote articles");
$panel21->addChild("group9",$group9);

$row1 = new ElatedMooseRow();
$group9->addChild("row1",$row1);

$blog_standard_type_ql_author_color = new ElatedMooseField("colorsimple","blog_standard_type_ql_author_color","","Text Color","This is some description");
$row1->addChild("blog_standard_type_ql_author_color",$blog_standard_type_ql_author_color);

$blog_standard_type_ql_author_hover_color = new ElatedMooseField("colorsimple","blog_standard_type_ql_author_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_standard_type_ql_author_hover_color",$blog_standard_type_ql_author_hover_color);

$blog_standard_type_ql_author_fontsize = new ElatedMooseField("textsimple","blog_standard_type_ql_author_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_standard_type_ql_author_font_size",$blog_standard_type_ql_author_fontsize);

$blog_standard_type_ql_author_lineheight = new ElatedMooseField("textsimple","blog_standard_type_ql_author_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_standard_type_ql_author_lineheight",$blog_standard_type_ql_author_lineheight);


$row2 = new ElatedMooseRow(true);
$group9->addChild("row2",$row2);

$blog_standard_type_ql_author_texttransform = new ElatedMooseField("selectblanksimple","blog_standard_type_ql_author_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_standard_type_ql_author_texttransform",$blog_standard_type_ql_author_texttransform);

$blog_standard_type_ql_author_google_fonts = new ElatedMooseField("fontsimple","blog_standard_type_ql_author_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_standard_type_ql_author_google_fonts",$blog_standard_type_ql_author_google_fonts);

$blog_standard_type_ql_author_fontstyle = new ElatedMooseField("selectblanksimple","blog_standard_type_ql_author_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_standard_type_ql_author_fontstyle",$blog_standard_type_ql_author_fontstyle);

$blog_standard_type_ql_author_fontweight = new ElatedMooseField("selectblanksimple","blog_standard_type_ql_author_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_standard_type_ql_author_fontweight",$blog_standard_type_ql_author_fontweight);

$row3 = new ElatedMooseRow(true);
$group9->addChild("row3",$row3);

$blog_standard_type_ql_author_letterspacing = new ElatedMooseField("textsimple","blog_standard_type_ql_author_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_standard_type_ql_author_letterspacing",$blog_standard_type_ql_author_letterspacing);

// Blog Post List - Blog: Vertical Loop
$panel22 = new ElatedMoosePanel("Blog List Template Options: Vertical Loop","blog_vertical_loop_post_lists", "blog_vertical_loop_show_options", "no");
$blogPage->addChild("panel22",$panel22);

$blog_vertical_loop_type_number_of_chars = new ElatedMooseField("text","blog_vertical_loop_type_number_of_chars","45","Number of Words in Excerpt",' Enter a number of words in excerpt (article summary)', array(), array("col_width" => 3));
$panel22->addChild("blog_vertical_loop_type_number_of_chars",$blog_vertical_loop_type_number_of_chars);

$blog_vertical_loop_type_post_meta_data_section = new ElatedMooseTitle("blog_vertical_loop_type_post_meta_data_section", "Post Info Data Fields");
$panel22->addChild("blog_vertical_loop_type_post_meta_data_section", $blog_vertical_loop_type_post_meta_data_section);

$blog_vertical_loop_type_show_categories = new ElatedMooseField("yesno","blog_vertical_loop_type_show_categories","yes","Show Categories","Enabling this option will Show Categories on Post List");
$panel22->addChild("blog_vertical_loop_type_show_categories",$blog_vertical_loop_type_show_categories);

$blog_vertical_loop_type_show_comments = new ElatedMooseField("yesno","blog_vertical_loop_type_show_comments","no","Show Comments","Enabling this option will Show Comments on Post List");
$panel22->addChild("blog_vertical_loop_type_show_comments",$blog_vertical_loop_type_show_comments);

$blog_vertical_loop_type_show_author = new ElatedMooseField("yesno","blog_vertical_loop_type_show_author","yes","Show Author Name","Enabling this option will show author name on Post List and Blog Post Single");
$panel22->addChild("blog_vertical_loop_type_show_author",$blog_vertical_loop_type_show_author);

$blog_vertical_loop_type_show_date = new ElatedMooseField("yesno","blog_vertical_loop_type_show_date","yes","Show Date","Enabling this option will show date on Post List");
$panel22->addChild("blog_vertical_loop_type_hide_date",$blog_vertical_loop_type_show_date);

$blog_vertical_loop_type_show_share = new ElatedMooseField("yesno","blog_vertical_loop_type_show_share","no","Show Share","Enabling this option will show share on Post List", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_vertical_loop_type_share_options_container"));
$panel22->addChild("blog_vertical_loop_type_show_share",$blog_vertical_loop_type_show_share);

$blog_vertical_loop_type_share_options_container = new ElatedMooseContainer("blog_vertical_loop_type_share_options_container","blog_vertical_loop_type_show_share","no");
$panel22->addChild("blog_vertical_loop_type_share_options_container",$blog_vertical_loop_type_share_options_container);

$blog_vertical_loop_type_select_share_option = new ElatedMooseField("select","blog_vertical_loop_type_select_share_option","dropdown","Social Share Style","Choose Social Share Style for Standard Type",array(
	"dropdown" => "Social Share Dropdown",
	"list" => "Social Share List"
));

$blog_vertical_loop_type_share_options_container->addChild("blog_vertical_loop_type_select_share_option",$blog_vertical_loop_type_select_share_option);

$blog_vertical_loop_type_share_icon_color = new ElatedMooseField("color","blog_vertical_loop_type_share_icon_color","","Icon Color","Choose icon color for dropdown and list share type");
$blog_vertical_loop_type_share_options_container->addChild("blog_vertical_loop_type_share_icon_color",$blog_vertical_loop_type_share_icon_color);

$blog_vertical_loop_type_share_icon_hover_color = new ElatedMooseField("color","blog_vertical_loop_type_share_icon_hover_color","","Icon Hover Color","Choose icon hover color for dropdown and list Share Type");
$blog_vertical_loop_type_share_options_container->addChild("blog_vertical_loop_type_share_icon_hover_color",$blog_vertical_loop_type_share_icon_hover_color);

$blog_vertical_loop_type_share_background_color = new ElatedMooseField("color","blog_vertical_loop_type_share_background_color","","Background Color","Choose background color for dropdown share type");
$blog_vertical_loop_type_share_options_container->addChild("blog_vertical_loop_type_share_background_color",$blog_vertical_loop_type_share_background_color);

$blog_vertical_loop_type_show_like = new ElatedMooseField("yesno","blog_vertical_loop_type_show_like","no","Show Likes",'Enabling this option will turn on "Likes"');
$panel22->addChild("blog_vertical_loop_type_show_like",$blog_vertical_loop_type_show_like);

$blog_vertical_loop_type_post_design_style = new ElatedMooseTitle("blog_vertical_loop_type_post_design_style", "Post Design Style");
$panel22->addChild("blog_vertical_loop_type_post_design_style", $blog_vertical_loop_type_post_design_style);

$blog_vertical_loop_type_enable_clapper = new ElatedMooseField("yesno","blog_vertical_loop_type_enable_clapper","no","Clapper Effect","The featured image of the first blog post opens on scroll in clapper fashion to reveal the blog content.");
$panel22->addChild("blog_vertical_loop_type_enable_clapper",$blog_vertical_loop_type_enable_clapper);

$blog_vertical_loop_type_enable_text_box = new ElatedMooseField("yesno","blog_vertical_loop_type_enable_text_box","no","Enable Boxed Styled Post Content","Enable post text boxed features", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_vertical_loop_type_enable_text_box_container"));
$panel22->addChild("blog_vertical_loop_type_enable_text_box",$blog_vertical_loop_type_enable_text_box);

$blog_vertical_loop_type_enable_text_box_container = new ElatedMooseContainer("blog_vertical_loop_type_enable_text_box_container","blog_vertical_loop_type_enable_text_box","no");
$panel22->addChild("blog_vertical_loop_type_enable_text_box_container",$blog_vertical_loop_type_enable_text_box_container);

$blog_vertical_loop_type_box_background_color = new ElatedMooseField("color","blog_vertical_loop_type_box_background_color","","Background Color","Choose background color for post text box");
$blog_vertical_loop_type_enable_text_box_container->addChild("blog_vertical_loop_type_box_background_color",$blog_vertical_loop_type_box_background_color);

$blog_vertical_loop_type_box_border_color = new ElatedMooseField("color","blog_vertical_loop_type_box_border_color","","Border Color","Choose border color for post text box");
$blog_vertical_loop_type_enable_text_box_container->addChild("blog_vertical_loop_type_box_border_color",$blog_vertical_loop_type_box_border_color);

$blog_vertical_loop_type_box_padding = new ElatedMooseField("text","blog_vertical_loop_type_box_padding","","Text box padding","Please insert padding in format (top right bottom left) i.e. 5px 5px 5px 5px", array(), array("col_width" => 3));
$blog_vertical_loop_type_enable_text_box_container->addChild("blog_vertical_loop_type_box_padding",$blog_vertical_loop_type_box_padding);

$group1 = new ElatedMooseGroup("Quote/Link Background","Set background of Quote/Link post type");
$panel22->addChild("group1",$group1);

$row1 = new ElatedMooseRow();
$group1->addChild("row1",$row1);

$blog_vertical_loop_type_ql_background_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_ql_background_color","","Background Color","Default color is #ffffff.");
$row1->addChild("blog_vertical_loop_type_ql_background_color",$blog_vertical_loop_type_ql_background_color);

$blog_vertical_loop_type_ql_hover_background_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_ql_hover_background_color","","Background Hover Color","Default color is #e6ae48.");
$row1->addChild("blog_vertical_loop_type_ql_hover_background_color",$blog_vertical_loop_type_ql_hover_background_color);

$blog_vertical_loop_type_show_ql_mark = new ElatedMooseField("yesno","blog_vertical_loop_type_show_ql_mark","yes","Enable Quote/Link Icon","Show Icons for Quote/Link Post Format", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_vertical_loop_type_show_ql_mark_container"));
$panel22->addChild("blog_vertical_loop_type_show_ql_mark",$blog_vertical_loop_type_show_ql_mark);

$blog_vertical_loop_type_show_ql_mark_container = new ElatedMooseContainer("blog_vertical_loop_type_show_ql_mark_container","blog_vertical_loop_type_show_ql_mark","no");
$panel22->addChild("blog_vertical_loop_type_show_ql_mark_container",$blog_vertical_loop_type_show_ql_mark_container);

$row1 = new ElatedMooseRow();
$blog_vertical_loop_type_show_ql_mark_container->addChild("row1",$row1);

$blog_vertical_loop_type_ql_mark_color = new ElatedMooseField("color","blog_vertical_loop_type_ql_mark_color","","Icon Color","Choose icon color for quote/link post.");
$row1->addChild("blog_vertical_loop_type_ql_mark_color",$blog_vertical_loop_type_ql_mark_color);

$blog_vertical_loop_type_ql_mark_hover_color = new ElatedMooseField("color","blog_vertical_loop_type_ql_mark_hover_color","","Icon Hover Color","Choose hover icon color for quote/link post.");
$row1->addChild("blog_vertical_loop_type_ql_mark_hover_color",$blog_vertical_loop_type_ql_mark_hover_color);

$blog_vertical_loop_type_image_height = new ElatedMooseField("text","blog_vertical_loop_type_image_height","","Image Height","Define image height for current and next article",array(), array("col_width" => 3));
$panel22->addChild("blog_vertical_loop_type_image_height",$blog_vertical_loop_type_image_height);

$group11 = new ElatedMooseGroup("Blog List Spacing","Set spacing for blog layouts");
$panel22->addChild("group11",$group11);

$row1 = new ElatedMooseRow();
$group11->addChild("row1",$row1);

$blog_vertical_loop_type_image_margin_bottom = new ElatedMooseField("textsimple","blog_vertical_loop_type_image_margin_bottom","","Margin Under Image (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_image_margin_bottom",$blog_vertical_loop_type_image_margin_bottom);

$blog_vertical_loop_type_title_margin_bottom = new ElatedMooseField("textsimple","blog_vertical_loop_type_title_margin_bottom","","Margin Under Title (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_title_margin_bottom",$blog_vertical_loop_type_title_margin_bottom);

$blog_vertical_loop_type_post_info_margin_bottom = new ElatedMooseField("textsimple","blog_vertical_loop_type_post_info_margin_bottom","","Margin Under Post Info (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_post_info_margin_bottom",$blog_vertical_loop_type_post_info_margin_bottom);

$blog_vertical_loop_type_article_margin_bottom = new ElatedMooseField("textsimple","blog_vertical_loop_type_article_margin_bottom","","Margin Between Articles (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_article_margin_bottom",$blog_vertical_loop_type_article_margin_bottom);

$row2 = new ElatedMooseRow();
$group11->addChild("row2",$row2);

$blog_vertical_loop_type_single_article_social_share_list_margin_top = new ElatedMooseField("textsimple","blog_vertical_loop_type_single_article_social_share_list_margin_top","","Margin Above Social Share List Holder (px)","This is some description");
$row2->addChild("blog_vertical_loop_type_single_article_social_share_list_margin_top",$blog_vertical_loop_type_single_article_social_share_list_margin_top);

$group12 = new ElatedMooseGroup("Blog List Spacing for Quote and Link Post Type","Set spacing for blog layouts");
$panel22->addChild("group12",$group12);

$row1 = new ElatedMooseRow();
$group12->addChild("row1",$row1);

$blog_vertical_loop_type_ql_title_margin_bottom = new ElatedMooseField("textsimple","blog_vertical_loop_type_ql_title_margin_bottom","","Margin Under Title (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_title_margin_bottom",$blog_vertical_loop_type_ql_title_margin_bottom);

$blog_vertical_loop_type_ql_social_share_list_margin_top = new ElatedMooseField("textsimple","blog_vertical_loop_type_ql_social_share_list_margin_top","","Margin Above Social Share List (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_social_share_list_margin_top",$blog_vertical_loop_type_ql_social_share_list_margin_top);

$blog_vertical_loop_type_ql_quote_author_margin_bottom = new ElatedMooseField("textsimple","blog_vertical_loop_type_ql_quote_author_margin_bottom","","Margin Under Quote Author (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_quote_author_margin_bottom",$blog_vertical_loop_type_ql_quote_author_margin_bottom);

$post_text_styling= new ElatedMooseTitle("post_text_styling", "Post Text Style");
$panel22->addChild("post_text_styling", $post_text_styling);

$group5 = new ElatedMooseGroup("Post Title","Define title styles in this blog post template.");
$panel22->addChild("group5",$group5);

$row1 = new ElatedMooseRow();
$group5->addChild("row1",$row1);

$blog_vertical_loop_type_title_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_title_color","","Text Color","This is some description");
$row1->addChild("blog_vertical_loop_type_title_color",$blog_vertical_loop_type_title_color);

$blog_vertical_loop_type_title_hover_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_title_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_vertical_loop_type_title_hover_color",$blog_vertical_loop_type_title_hover_color);

$blog_vertical_loop_type_title_fontsize = new ElatedMooseField("textsimple","blog_vertical_loop_type_title_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_title_fontsize",$blog_vertical_loop_type_title_fontsize);

$blog_vertical_loop_type_title_lineheight = new ElatedMooseField("textsimple","blog_vertical_loop_type_title_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_title_lineheight",$blog_vertical_loop_type_title_lineheight);

$row2 = new ElatedMooseRow(true);
$group5->addChild("row2",$row2);

$blog_vertical_loop_type_title_texttransform = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_title_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_vertical_loop_type_title_texttransform",$blog_vertical_loop_type_title_texttransform);

$blog_vertical_loop_type_title_google_fonts = new ElatedMooseField("fontsimple","blog_vertical_loop_type_title_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_vertical_loop_type_title_google_fonts",$blog_vertical_loop_type_title_google_fonts);

$blog_vertical_loop_type_title_fontstyle = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_title_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_vertical_loop_type_title_fontstyle",$blog_vertical_loop_type_title_fontstyle);

$blog_vertical_loop_type_title_fontweight = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_title_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_vertical_loop_type_title_fontweight",$blog_vertical_loop_type_title_fontweight);

$row3 = new ElatedMooseRow(true);
$group5->addChild("row3",$row3);

$blog_vertical_loop_type_title_letterspacing = new ElatedMooseField("textsimple","blog_vertical_loop_type_title_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_vertical_loop_type_title_letterspacing",$blog_vertical_loop_type_title_letterspacing);

$group20 = new ElatedMooseGroup("Post subtitle","Define subtitle styles in this blog post template.");
$panel22->addChild("group20",$group20);

$row1 = new ElatedMooseRow();
$group20->addChild("row1",$row1);

$blog_vertical_loop_type_subtitle_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_subtitle_color","","Text Color","This is some description");
$row1->addChild("blog_vertical_loop_type_subtitle_color",$blog_vertical_loop_type_subtitle_color);

$blog_vertical_loop_type_subtitle_hover_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_subtitle_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_vertical_loop_type_subtitle_hover_color",$blog_vertical_loop_type_subtitle_hover_color);

$blog_vertical_loop_type_subtitle_fontsize = new ElatedMooseField("textsimple","blog_vertical_loop_type_subtitle_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_subtitle_fontsize",$blog_vertical_loop_type_subtitle_fontsize);

$blog_vertical_loop_type_subtitle_lineheight = new ElatedMooseField("textsimple","blog_vertical_loop_type_subtitle_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_subtitle_lineheight",$blog_vertical_loop_type_subtitle_lineheight);

$row2 = new ElatedMooseRow(true);
$group20->addChild("row2",$row2);

$blog_vertical_loop_type_subtitle_texttransform = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_subtitle_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_vertical_loop_type_subtitle_texttransform",$blog_vertical_loop_type_subtitle_texttransform);

$blog_vertical_loop_type_subtitle_google_fonts = new ElatedMooseField("fontsimple","blog_vertical_loop_type_subtitle_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_vertical_loop_type_subtitle_google_fonts",$blog_vertical_loop_type_subtitle_google_fonts);

$blog_vertical_loop_type_subtitle_fontstyle = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_subtitle_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_vertical_loop_type_subtitle_fontstyle",$blog_vertical_loop_type_subtitle_fontstyle);

$blog_vertical_loop_type_subtitle_fontweight = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_subtitle_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_vertical_loop_type_subtitle_fontweight",$blog_vertical_loop_type_subtitle_fontweight);

$row3 = new ElatedMooseRow(true);
$group20->addChild("row3",$row3);

$blog_vertical_loop_type_subtitle_letterspacing = new ElatedMooseField("textsimple","blog_vertical_loop_type_subtitle_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_vertical_loop_type_subtitle_letterspacing",$blog_vertical_loop_type_subtitle_letterspacing);

$group7 = new ElatedMooseGroup("Post Info Data","Define post info text styles (date, category names etc.) Note: Single Posts will take the same styles as in list");
$panel22->addChild("group7",$group7);

$row1 = new ElatedMooseRow();
$group7->addChild("row1",$row1);

$blog_vertical_loop_type_info_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_info_color","","Text Color","This is some description");
$row1->addChild("blog_vertical_loop_type_info_color",$blog_vertical_loop_type_info_color);

$blog_vertical_loop_type_info_link_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_vertical_loop_type_info_link_color",$blog_vertical_loop_type_info_link_color);

$blog_vertical_loop_type_info_hover_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_info_hover_color","","Link Hover Color","This is some description");
$row1->addChild("blog_vertical_loop_type_info_hover_color",$blog_vertical_loop_type_info_hover_color);

$blog_vertical_loop_type_info_fontsize = new ElatedMooseField("textsimple","blog_vertical_loop_type_info_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_info_fontsize",$blog_vertical_loop_type_info_fontsize);

$row2 = new ElatedMooseRow(true);
$group7->addChild("row2",$row2);

$blog_vertical_loop_type_info_lineheight = new ElatedMooseField("textsimple","blog_vertical_loop_type_info_lineheight","","Line Height (px)","This is some description");
$row2->addChild("blog_vertical_loop_type_info_lineheight",$blog_vertical_loop_type_info_lineheight);

$blog_vertical_loop_type_info_google_fonts = new ElatedMooseField("fontsimple","blog_vertical_loop_type_info_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_vertical_loop_type_info_google_fonts",$blog_vertical_loop_type_info_google_fonts);

$blog_vertical_loop_type_info_fontstyle = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_info_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_vertical_loop_type_info_fontstyle",$blog_vertical_loop_type_info_fontstyle);

$blog_vertical_loop_type_info_fontweight = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_info_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_vertical_loop_type_info_fontweight",$blog_vertical_loop_type_info_fontweight);

$row3 = new ElatedMooseRow(true);
$group7->addChild("row3",$row3);

$blog_vertical_loop_type_info_texttransform = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_info_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row3->addChild("blog_vertical_loop_type_info_texttransform",$blog_vertical_loop_type_info_texttransform);

$blog_vertical_loop_type_info_letterspacing = new ElatedMooseField("textsimple","blog_vertical_loop_type_info_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_vertical_loop_type_info_letterspacing",$blog_vertical_loop_type_info_letterspacing);

$group6 = new ElatedMooseGroup("Quote/Link Title Style","Define title styles for Quote/Link articles");
$panel22->addChild("group6",$group6);

$row1 = new ElatedMooseRow();
$group6->addChild("row1",$row1);

$blog_vertical_loop_type_ql_title_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_ql_title_color","","Text Color","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_title_color",$blog_vertical_loop_type_ql_title_color);

$blog_vertical_loop_type_ql_title_hover_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_ql_title_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_title_hover_color",$blog_vertical_loop_type_ql_title_hover_color);

$blog_vertical_loop_type_ql_title_fontsize = new ElatedMooseField("textsimple","blog_vertical_loop_type_ql_title_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_title_font_size",$blog_vertical_loop_type_ql_title_fontsize);

$blog_vertical_loop_type_ql_title_lineheight = new ElatedMooseField("textsimple","blog_vertical_loop_type_ql_title_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_title_lineheight",$blog_vertical_loop_type_ql_title_lineheight);


$row2 = new ElatedMooseRow(true);
$group6->addChild("row2",$row2);

$blog_vertical_loop_type_ql_title_texttransform = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_ql_title_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_vertical_loop_type_ql_title_texttransform",$blog_vertical_loop_type_ql_title_texttransform);

$blog_vertical_loop_type_ql_title_google_fonts = new ElatedMooseField("fontsimple","blog_vertical_loop_type_ql_title_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_vertical_loop_type_ql_title_google_fonts",$blog_vertical_loop_type_ql_title_google_fonts);

$blog_vertical_loop_type_ql_title_fontstyle = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_ql_title_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_vertical_loop_type_ql_title_fontstyle",$blog_vertical_loop_type_ql_title_fontstyle);

$blog_vertical_loop_type_ql_title_fontweight = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_ql_title_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_vertical_loop_type_ql_title_fontweight",$blog_vertical_loop_type_ql_title_fontweight);

$row3 = new ElatedMooseRow(true);
$group6->addChild("row3",$row3);

$blog_vertical_loop_type_ql_title_letterspacing = new ElatedMooseField("textsimple","blog_vertical_loop_type_ql_title_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_vertical_loop_type_ql_title_letterspacing",$blog_vertical_loop_type_ql_title_letterspacing);

$group8 = new ElatedMooseGroup("Quote/Link Post Info Data","Define quote/link post info text styles (date, category names etc.) Note: Single Posts will take the same styles as in list.");
$panel22->addChild("group8",$group8);

$row1 = new ElatedMooseRow();
$group8->addChild("row1",$row1);

$blog_vertical_loop_type_ql_info_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_ql_info_color","","Text Color","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_info_color",$blog_vertical_loop_type_ql_info_color);

$blog_vertical_loop_type_ql_info_link_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_ql_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_info_link_color",$blog_vertical_loop_type_ql_info_link_color);

$blog_vertical_loop_type_ql_info_hover_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_ql_info_hover_color","","Hover Color","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_info_hover_color",$blog_vertical_loop_type_ql_info_hover_color);

$blog_vertical_loop_type_ql_info_fontsize = new ElatedMooseField("textsimple","blog_vertical_loop_type_ql_info_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_info_fontsize",$blog_vertical_loop_type_ql_info_fontsize);

$row2 = new ElatedMooseRow(true);
$group8->addChild("row2",$row2);


$blog_vertical_loop_type_ql_info_lineheight = new ElatedMooseField("textsimple","blog_vertical_loop_type_ql_info_lineheight","","Line Height (px)","This is some description");
$row2->addChild("blog_vertical_loop_type_ql_info_lineheight",$blog_vertical_loop_type_ql_info_lineheight);

$blog_vertical_loop_type_ql_info_google_fonts = new ElatedMooseField("fontsimple","blog_vertical_loop_type_ql_info_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_vertical_loop_type_ql_info_google_fonts",$blog_vertical_loop_type_ql_info_google_fonts);

$blog_vertical_loop_type_ql_info_fontstyle = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_ql_info_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_vertical_loop_type_ql_info_fontstyle",$blog_vertical_loop_type_ql_info_fontstyle);

$blog_vertical_loop_type_ql_info_fontweight = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_ql_info_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_vertical_loop_type_ql_info_fontweight",$blog_vertical_loop_type_ql_info_fontweight);

$row3 = new ElatedMooseRow(true);
$group8->addChild("row3",$row3);

$blog_vertical_loop_type_ql_info_texttransform = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_ql_info_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row3->addChild("blog_vertical_loop_type_ql_info_texttransform",$blog_vertical_loop_type_ql_info_texttransform);

$blog_vertical_loop_type_ql_info_letterspacing = new ElatedMooseField("textsimple","blog_vertical_loop_type_ql_info_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_vertical_loop_type_ql_info_letterspacing",$blog_vertical_loop_type_ql_info_letterspacing);

$group9 = new ElatedMooseGroup("Quote Author Style","Define author styles for Quote articles");
$panel22->addChild("group9",$group9);

$row1 = new ElatedMooseRow();
$group9->addChild("row1",$row1);

$blog_vertical_loop_type_ql_author_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_ql_author_color","","Text Color","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_author_color",$blog_vertical_loop_type_ql_author_color);

$blog_vertical_loop_type_ql_author_hover_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_ql_author_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_author_hover_color",$blog_vertical_loop_type_ql_author_hover_color);

$blog_vertical_loop_type_ql_author_fontsize = new ElatedMooseField("textsimple","blog_vertical_loop_type_ql_author_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_author_font_size",$blog_vertical_loop_type_ql_author_fontsize);

$blog_vertical_loop_type_ql_author_lineheight = new ElatedMooseField("textsimple","blog_vertical_loop_type_ql_author_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_ql_author_lineheight",$blog_vertical_loop_type_ql_author_lineheight);


$row2 = new ElatedMooseRow(true);
$group9->addChild("row2",$row2);

$blog_vertical_loop_type_ql_author_texttransform = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_ql_author_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_vertical_loop_type_ql_author_texttransform",$blog_vertical_loop_type_ql_author_texttransform);

$blog_vertical_loop_type_ql_author_google_fonts = new ElatedMooseField("fontsimple","blog_vertical_loop_type_ql_author_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_vertical_loop_type_ql_author_google_fonts",$blog_vertical_loop_type_ql_author_google_fonts);

$blog_vertical_loop_type_ql_author_fontstyle = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_ql_author_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_vertical_loop_type_ql_author_fontstyle",$blog_vertical_loop_type_ql_author_fontstyle);

$blog_vertical_loop_type_ql_author_fontweight = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_ql_author_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_vertical_loop_type_ql_author_fontweight",$blog_vertical_loop_type_ql_author_fontweight);

$row3 = new ElatedMooseRow(true);
$group9->addChild("row3",$row3);

$blog_vertical_loop_type_ql_author_letterspacing = new ElatedMooseField("textsimple","blog_vertical_loop_type_ql_author_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_vertical_loop_type_ql_author_letterspacing",$blog_vertical_loop_type_ql_author_letterspacing);

$post_vertical_loop_type_next_article_title = new ElatedMooseTitle("post_vertical_loop_type_next_article_title", "Next Article Styles");
$panel22->addChild("post_vertical_loop_type_next_article_title", $post_vertical_loop_type_next_article_title);

$group10 = new ElatedMooseGroup("Title Style","Define title styles for article");
$panel22->addChild("group10",$group10);

$row1 = new ElatedMooseRow();
$group10->addChild("row1",$row1);

$blog_vertical_loop_type_next_article_title_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_next_article_title_color","","Text Color","This is some description");
$row1->addChild("blog_vertical_loop_type_next_article_title_color",$blog_vertical_loop_type_next_article_title_color);

$blog_vertical_loop_type_next_article_title_fontsize = new ElatedMooseField("textsimple","blog_vertical_loop_type_next_article_title_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_next_article_title_fontsize",$blog_vertical_loop_type_next_article_title_fontsize);

$blog_vertical_loop_type_next_article_title_lineheight = new ElatedMooseField("textsimple","blog_vertical_loop_type_next_article_title_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_next_article_title_lineheight",$blog_vertical_loop_type_next_article_title_lineheight);

$blog_vertical_loop_type_next_article_title_texttransform = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_next_article_title_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row1->addChild("blog_vertical_loop_type_next_article_title_texttransform",$blog_vertical_loop_type_next_article_title_texttransform);

$row2 = new ElatedMooseRow(true);
$group10->addChild("row2",$row2);

$blog_vertical_loop_type_next_article_title_google_fonts = new ElatedMooseField("fontsimple","blog_vertical_loop_type_next_article_title_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_vertical_loop_type_next_article_title_google_fonts",$blog_vertical_loop_type_next_article_title_google_fonts);

$blog_vertical_loop_type_next_article_title_fontstyle = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_next_article_title_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_vertical_loop_type_next_article_title_fontstyle",$blog_vertical_loop_type_next_article_title_fontstyle);

$blog_vertical_loop_type_next_article_title_fontweight = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_next_article_title_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_vertical_loop_type_next_article_title_fontweight",$blog_vertical_loop_type_next_article_title_fontweight);

$blog_vertical_loop_type_next_article_title_letterspacing = new ElatedMooseField("textsimple","blog_vertical_loop_type_next_article_title_letterspacing","","Letter Spacing (px)","This is some description");
$row2->addChild("blog_vertical_loop_type_next_article_title_letterspacing",$blog_vertical_loop_type_next_article_title_letterspacing);

$row3 = new ElatedMooseRow(true);
$group10->addChild("row3",$row3);

$blog_vertical_loop_type_next_article_title_position = new ElatedMooseField("selectsimple","blog_vertical_loop_type_next_article_title_position","dropdown","Title Position","Choose title position for next article",array(
	"center" => "Center",
	"left" => "Left",
	"right" => "Right"
));

$row3->addChild("blog_vertical_loop_type_next_article_title_position",$blog_vertical_loop_type_next_article_title_position);

$group19 = new ElatedMooseGroup("Subtitle Style","Define subtitle styles for article");
$panel22->addChild("group19",$group19);

$row1 = new ElatedMooseRow();
$group19->addChild("row1",$row1);

$blog_vertical_loop_type_next_article_subtitle_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_next_article_subtitle_color","","Text Color");
$row1->addChild("blog_vertical_loop_type_next_article_subtitle_color",$blog_vertical_loop_type_next_article_subtitle_color);

$blog_vertical_loop_type_next_article_subtitle_fontsize = new ElatedMooseField("textsimple","blog_vertical_loop_type_next_article_subtitle_fontsize","","Font Size (px)");
$row1->addChild("blog_vertical_loop_type_next_article_subtitle_fontsize",$blog_vertical_loop_type_next_article_subtitle_fontsize);

$blog_vertical_loop_type_next_article_subtitle_lineheight = new ElatedMooseField("textsimple","blog_vertical_loop_type_next_article_subtitle_lineheight","","Line Height (px)");
$row1->addChild("blog_vertical_loop_type_next_article_subtitle_lineheight",$blog_vertical_loop_type_next_article_subtitle_lineheight);

$blog_vertical_loop_type_next_article_subtitle_texttransform = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_next_article_subtitle_texttransform","","Text Transform","",$eltd_moose_options_texttransform);
$row1->addChild("blog_vertical_loop_type_next_article_subtitle_texttransform",$blog_vertical_loop_type_next_article_subtitle_texttransform);

$row2 = new ElatedMooseRow(true);
$group19->addChild("row2",$row2);

$blog_vertical_loop_type_next_article_subtitle_google_fonts = new ElatedMooseField("fontsimple","blog_vertical_loop_type_next_article_subtitle_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_vertical_loop_type_next_article_subtitle_google_fonts",$blog_vertical_loop_type_next_article_subtitle_google_fonts);

$blog_vertical_loop_type_next_article_subtitle_fontstyle = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_next_article_subtitle_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_vertical_loop_type_next_article_subtitle_fontstyle",$blog_vertical_loop_type_next_article_subtitle_fontstyle);

$blog_vertical_loop_type_next_article_subtitle_fontweight = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_next_article_subtitle_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_vertical_loop_type_next_article_subtitle_fontweight",$blog_vertical_loop_type_next_article_subtitle_fontweight);

$blog_vertical_loop_type_next_article_subtitle_letterspacing = new ElatedMooseField("textsimple","blog_vertical_loop_type_next_article_subtitle_letterspacing","","Letter Spacing (px)","This is some description");
$row2->addChild("blog_vertical_loop_type_next_article_subtitle_letterspacing",$blog_vertical_loop_type_next_article_subtitle_letterspacing);

$row3 = new ElatedMooseRow(true);
$group19->addChild("row3",$row3);

$blog_vertical_loop_type_next_article_subtitle_position = new ElatedMooseField("selectsimple","blog_vertical_loop_type_next_article_subtitle_position","dropdown","Subtitle Position","Choose subtitle position for next article",array(
	"center" => "Center",
	"left" => "Left",
	"right" => "Right"
));
$row3->addChild("blog_vertical_loop_type_next_article_subtitle_position",$blog_vertical_loop_type_next_article_subtitle_position);

$group14 = new ElatedMooseGroup("Post Info Data","Define post info text styles");
$panel22->addChild("group14",$group14);

$row1 = new ElatedMooseRow();
$group14->addChild("row1",$row1);

$blog_vertical_loop_type_next_info_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_next_info_color","","Text Color","This is some description");
$row1->addChild("blog_vertical_loop_type_next_info_color",$blog_vertical_loop_type_next_info_color);

$blog_vertical_loop_type_next_info_link_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_next_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_vertical_loop_type_next_info_link_color",$blog_vertical_loop_type_next_info_link_color);

$blog_vertical_loop_type_next_info_hover_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_next_info_hover_color","","Link Hover Color","This is some description");
$row1->addChild("blog_vertical_loop_type_next_info_hover_color",$blog_vertical_loop_type_next_info_hover_color);

$blog_vertical_loop_type_next_info_fontsize = new ElatedMooseField("textsimple","blog_vertical_loop_type_next_info_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_vertical_loop_type_next_info_fontsize",$blog_vertical_loop_type_next_info_fontsize);

$row2 = new ElatedMooseRow(true);
$group14->addChild("row2",$row2);

$blog_vertical_loop_type_next_info_lineheight = new ElatedMooseField("textsimple","blog_vertical_loop_type_next_info_lineheight","","Line Height (px)","This is some description");
$row2->addChild("blog_vertical_loop_type_next_info_lineheight",$blog_vertical_loop_type_next_info_lineheight);

$blog_vertical_loop_type_next_info_google_fonts = new ElatedMooseField("fontsimple","blog_vertical_loop_type_next_info_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_vertical_loop_type_next_info_google_fonts",$blog_vertical_loop_type_next_info_google_fonts);

$blog_vertical_loop_type_next_info_fontstyle = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_next_info_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_vertical_loop_type_next_info_fontstyle",$blog_vertical_loop_type_next_info_fontstyle);

$blog_vertical_loop_type_next_info_fontweight = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_next_info_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_vertical_loop_type_next_info_fontweight",$blog_vertical_loop_type_next_info_fontweight);

$row3 = new ElatedMooseRow(true);
$group14->addChild("row3",$row3);

$blog_vertical_loop_type_next_info_texttransform = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_next_info_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row3->addChild("blog_vertical_loop_type_next_info_texttransform",$blog_vertical_loop_type_next_info_texttransform);

$blog_vertical_loop_type_next_info_letterspacing = new ElatedMooseField("textsimple","blog_vertical_loop_type_next_info_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_vertical_loop_type_next_info_letterspacing",$blog_vertical_loop_type_next_info_letterspacing);

$post_vertical_loop_type_next_previous_arrow_title = new ElatedMooseTitle("post_vertical_loop_type_next_previous_arrow_title", "Previous/Next Article Arrow Style");
$panel22->addChild("post_vertical_loop_type_next_previous_arrow_title", $post_vertical_loop_type_next_previous_arrow_title);

$group13 = new ElatedMooseGroup("Article Arrow Style","Define arrow styles for next article");
$panel22->addChild("group13",$group13);

$row1 = new ElatedMooseRow();
$group13->addChild("row1",$row1);

$blog_vertical_loop_type_next_article_arrow_background_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_next_article_arrow_background_color","","Background Color","This is some description");
$row1->addChild("blog_vertical_loop_type_next_article_arrow_background_color",$blog_vertical_loop_type_next_article_arrow_background_color);

$blog_vertical_loop_type_next_article_arrow_color = new ElatedMooseField("colorsimple","blog_vertical_loop_type_next_article_arrow_color","","Arrow Color","This is some description");
$row1->addChild("blog_vertical_loop_type_next_article_arrow_color",$blog_vertical_loop_type_next_article_arrow_color);

$blog_vertical_loop_type_next_article_arrow_bckg_hover_clr = new ElatedMooseField("colorsimple","blog_vertical_loop_type_next_article_arrow_bckg_hover_clr","","Background Hover Color","This is some description");
$row1->addChild("blog_vertical_loop_type_next_article_arrow_bckg_hover_clr",$blog_vertical_loop_type_next_article_arrow_bckg_hover_clr);

$blog_vertical_loop_type_next_article_arrow_color_hover = new ElatedMooseField("colorsimple","blog_vertical_loop_type_next_article_arrow_color_hover","","Arrow Hover Color","This is some description");
$row1->addChild("blog_vertical_loop_type_next_article_arrow_color_hover",$blog_vertical_loop_type_next_article_arrow_color_hover);

$row2 = new ElatedMooseRow();
$group13->addChild("row2",$row2);

$blog_vertical_loop_type_next_article_arrow_size = new ElatedMooseField("textsimple","blog_vertical_loop_type_next_article_arrow_size","","Arrow Size","This is some description");
$row2->addChild("blog_vertical_loop_type_next_article_arrow_size",$blog_vertical_loop_type_next_article_arrow_size);

$blog_vertical_loop_type_next_article_font_weight = new ElatedMooseField("selectblanksimple","blog_vertical_loop_type_next_article_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_vertical_loop_type_next_article_font_weight",$blog_vertical_loop_type_next_article_font_weight);

// Blog Post List - Blog: Masonry Gallery
$panel23 = new ElatedMoosePanel("Blog List Templates Options: Masonry Gallery & Masonry Gallery Full Width","blog_masonry_gallery_post_lists", "blog_masonry_gallery_show_options", "no");
$blogPage->addChild("panel23",$panel23);

$blog_masonry_gallery_number_of_chars = new ElatedMooseField("text","blog_masonry_gallery_number_of_chars","45","Number of Words in Excerpt",' Enter a number of words in excerpt (article summary)', array(), array("col_width" => 3));
$panel23->addChild("blog_masonry_gallery_number_of_chars",$blog_masonry_gallery_number_of_chars);

$blog_masonry_gallery_read_more_button = new ElatedMooseField("yesno","blog_masonry_gallery_read_more_button","no","Read More Button","Enable Read More Button", array(),
    array("dependence" => true,
        "dependence_hide_on_yes" => "",
        "dependence_show_on_yes" => "#eltdf_blog_masonry_gallery_read_more_button_container"));
$panel23->addChild("blog_masonry_gallery_read_more_button",$blog_masonry_gallery_read_more_button);

$blog_masonry_gallery_read_more_button_container = new ElatedMooseContainer("blog_masonry_gallery_read_more_button_container","blog_masonry_gallery_read_more_button","no");
$panel23->addChild("blog_masonry_gallery_read_more_button_container",$blog_masonry_gallery_read_more_button_container);

$blog_masonry_gallery_read_more_button_icon = new ElatedMooseField("yesno","blog_masonry_gallery_read_more_button_icon","no","Enable Icon","Enabling this option will place icon in read more button", array(),
    array("dependence" => true,
        "dependence_hide_on_yes" => "",
        "dependence_show_on_yes" => "#eltdf_blog_masonry_gallery_read_more_button_icon_container"));
$blog_masonry_gallery_read_more_button_container->addChild("blog_masonry_gallery_read_more_button_icon",$blog_masonry_gallery_read_more_button_icon);

$blog_masonry_gallery_read_more_button_icon_container = new ElatedMooseContainer("blog_masonry_gallery_read_more_button_icon_container","blog_masonry_gallery_read_more_button_icon","no");
$blog_masonry_gallery_read_more_button_container->addChild("blog_masonry_gallery_read_more_button_icon_container",$blog_masonry_gallery_read_more_button_icon_container);

//init icon pack hide and show array. It will be populated dinamically from collections array
$blog_masonry_gallery_read_more_button_icon_pack_hide_array = array();
$blog_masonry_gallery_read_more_button_icon_pack_show_array = array();

//do we have some collection added in collections array?
if(is_array($eltdIconCollections->iconCollections) && count($eltdIconCollections->iconCollections)) {
    //get collections params array. It will contain values of 'param' property for each collection
    $blog_masonry_gallery_read_more_button_icon_collections_params = $eltdIconCollections->getIconCollectionsParams();

    //foreach collection generate hide and show array
    foreach ($eltdIconCollections->iconCollections as $dep_collection_key => $dep_collection_object) {
        $blog_masonry_gallery_read_more_button_icon_pack_hide_array[$dep_collection_key] = '';

        //we need to include only current collection in show string as it is the only one that needs to show
        $blog_masonry_gallery_read_more_button_icon_pack_show_array[$dep_collection_key] = '#eltdf_blog_masonry_gallery_read_more_button_icon_'.$dep_collection_object->param.'_container';

        //for all collections param generate hide string
        foreach ($blog_masonry_gallery_read_more_button_icon_collections_params as $blog_masonry_gallery_read_more_button_icon_collections_param) {
            //we don't need to include current one, because it needs to be shown, not hidden
            if($blog_masonry_gallery_read_more_button_icon_collections_param !== $dep_collection_object->param) {
                $blog_masonry_gallery_read_more_button_icon_pack_hide_array[$dep_collection_key].= '#eltdf_blog_masonry_gallery_read_more_button_icon_'.$blog_masonry_gallery_read_more_button_icon_collections_param.'_container,';
            }
        }

        //remove remaining ',' character
        $blog_masonry_gallery_read_more_button_icon_pack_hide_array[$dep_collection_key] = rtrim($blog_masonry_gallery_read_more_button_icon_pack_hide_array[$dep_collection_key], ',');
    }

}

$blog_masonry_gallery_read_more_button_icon_pack = new ElatedMooseField(
    "select",
    "blog_masonry_gallery_read_more_button_icon_pack",
    "font_awesome",
    "Icon Pack",
    "Choose icon pack for show load more button",
    $eltdIconCollections->getIconCollections(),
    array(
        "dependence" => true,
        "hide" => $blog_masonry_gallery_read_more_button_icon_pack_hide_array,
        "show" => $blog_masonry_gallery_read_more_button_icon_pack_show_array
    ));

$blog_masonry_gallery_read_more_button_icon_container->addChild("blog_masonry_gallery_read_more_button_icon_pack", $blog_masonry_gallery_read_more_button_icon_pack);

if(is_array($eltdIconCollections->iconCollections) && count($eltdIconCollections->iconCollections)) {
    //foreach icon collection we need to generate separate container that will have dependency set
    //it will have one field inside with icons dropdown
    foreach ($eltdIconCollections->iconCollections as $collection_key => $collection_object) {
        $icons_array = $collection_object->getIconsArray();

        //get icon collection keys (keys from collections array, e.g 'font_awesome', 'font_elegant' etc.)
        $icon_collections_keys = $eltdIconCollections->getIconCollectionsKeys();

        //unset current one, because it doesn't have to be included in dependency that hides icon container
        unset($icon_collections_keys[array_search($collection_key, $icon_collections_keys)]);

        $blog_masonry_gallery_read_more_button_icon_hide_values = $icon_collections_keys;
        $blog_icon_container = new ElatedMooseContainer("blog_masonry_gallery_read_more_button_icon_".$collection_object->param."_container", "blog_masonry_gallery_read_more_button_icon_pack", "", $blog_masonry_gallery_read_more_button_icon_hide_values);
        $blog_masonry_gallery_read_more_button_icon = new ElatedMooseField("select", "blog_masonry_gallery_read_more_button_icon_".$collection_object->param, "", "Button Icon","Choose Button Icon", $icons_array, array("col_width" => 3));
        $blog_icon_container->addChild("blog_masonry_gallery_read_more_button_icon_".$collection_object->param, $blog_masonry_gallery_read_more_button_icon);

        $blog_masonry_gallery_read_more_button_icon_container->addChild("blog_masonry_gallery_read_more_button_icon_".$collection_object->param."_container", $blog_icon_container);
    }

}


$pagination_masonry_gallery = new ElatedMooseField("select","pagination_masonry_gallery","pagination","Pagination on Masonry",'Choose a pagination style for "Masonry" Blog List', array(
	"pagination" => "Pagination",
	"load_more" => "Load More",
	"infinite_scroll" => "Infinite Scroll"
));
$panel23->addChild("pagination_masonry_gallery",$pagination_masonry_gallery);

$blog_masonry_gallery_columns = new ElatedMooseField('select', 'blog_masonry_gallery_columns', 'two_columns', 'Masonry Blog Columns', 'Choose a number of columns for "Masonry" Blog List without sidebar', array(
	'two_columns' => '2',
	'three_columns' => '3',
	'four_columns'	=> '4'
));
$panel23->addChild('blog_masonry_gallery_columns', $blog_masonry_gallery_columns);

$blog_masonry_gallery_full_width_columns = new ElatedMooseField('select', 'blog_masonry_gallery_full_width_columns', 'three_columns', 'Full Width Masonry Blog Columns', 'Choose a number of columns for "Masonry" Blog List', array(
	'three_columns' => '3',
	'four_columns' => '4',
	'five_columns' => '5'
));
$panel23->addChild('blog_masonry_gallery_full_width_columns', $blog_masonry_gallery_full_width_columns);

$blog_masonry_gallery_full_width_margin = new ElatedMooseField("text","blog_masonry_gallery_full_width_margin","","Full Width Masonry Margin",'Please insert margin in px i.e. 5px, or in % i.e 5%', array(), array("col_width" => 3));
$panel23->addChild("blog_masonry_gallery_full_width_margin",$blog_masonry_gallery_full_width_margin);

$blog_masonry_gallery_filter = new ElatedMooseField("yesno","blog_masonry_gallery_filter","no","Show Category Filter on Masonry",'Enabling this option will display a Category Filter on "Masonry" Blog List', array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_masonry_gallery_filter_container"));
$panel23->addChild("blog_masonry_gallery_filter",$blog_masonry_gallery_filter);

$blog_masonry_gallery_filter_container = new ElatedMooseContainer("blog_masonry_gallery_filter_container","blog_masonry_gallery_filter","no");
$panel23->addChild("blog_masonry_gallery_filter_container",$blog_masonry_gallery_filter_container);


// Blog Masonry Filter
$blog_masonry_gallery_filter_background_color = new ElatedMooseField("color","blog_masonry_gallery_filter_background_color","","Background Color","Choose color for background of filter area",array(), array("col_width" => 3));
$blog_masonry_gallery_filter_container->addChild("blog_masonry_gallery_filter_background_color",$blog_masonry_gallery_filter_background_color);

$blog_masonry_gallery_filter_height = new ElatedMooseField("text","blog_masonry_gallery_filter_height","","Height (px)","Enter height for filter area",array(), array("col_width" => 3));
$blog_masonry_gallery_filter_container->addChild("blog_masonry_gallery_filter_height", $blog_masonry_gallery_filter_height);

$blog_masonry_gallery_filter_margin_bottom = new ElatedMooseField("text","blog_masonry_gallery_filter_margin_bottom","","Bottom Margin (px)","Enter bottom margin for filter area. Default value is 36",array(), array("col_width" => 3));
$blog_masonry_gallery_filter_container->addChild("blog_masonry_gallery_filter_margin_bottom",$blog_masonry_gallery_filter_margin_bottom);

$blog_masonry_gallery_filter_alignment = new ElatedMooseField("select","blog_masonry_gallery_filter_alignment","","Horizontal Alignment","Choose filter alignment", array(
	"left" => "Left",
	"center" => "Center",
	"right" => "Right"
));
$blog_masonry_gallery_filter_container->addChild("blog_masonry_gallery_filter_alignment",$blog_masonry_gallery_filter_alignment);

$blog_masonry_gallery_enable_filter_title = new ElatedMooseField("yesno","blog_masonry_gallery_enable_filter_title","no","Enable Filter Title","Enabling this option will show category filter title");
$blog_masonry_gallery_filter_container->addChild("blog_masonry_gallery_enable_filter_title",$blog_masonry_gallery_enable_filter_title);

$group1 = new ElatedMooseGroup("Title","Define text styles for filter title");
$blog_masonry_gallery_filter_container->addChild("group1",$group1);

$row1 = new ElatedMooseRow();
$group1->addChild("row1",$row1);
$blog_masonry_gallery_filter_title_color = new ElatedMooseField("colorsimple","blog_masonry_gallery_filter_title_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_gallery_filter_title_color",$blog_masonry_gallery_filter_title_color);
$blog_masonry_gallery_filter_title_font_size = new ElatedMooseField("textsimple","blog_masonry_gallery_filter_title_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_masonry_gallery_filter_title_font_size",$blog_masonry_gallery_filter_title_font_size);
$blog_masonry_gallery_filter_title_line_height = new ElatedMooseField("textsimple","blog_masonry_gallery_filter_title_line_height","","Line Height (px)","This is some description");
$row1->addChild("blog_masonry_gallery_filter_title_line_height",$blog_masonry_gallery_filter_title_line_height);
$blog_masonry_gallery_filter_title_text_transform = new ElatedMooseField("selectblanksimple","blog_masonry_gallery_filter_title_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row1->addChild("blog_masonry_gallery_filter_title_text_transform",$blog_masonry_gallery_filter_title_text_transform);

$row2 = new ElatedMooseRow(true);
$group1->addChild("row2",$row2);
$blog_masonry_gallery_filter_title_font_family = new ElatedMooseField("fontsimple","blog_masonry_gallery_filter_title_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_masonry_gallery_filter_title_font_family",$blog_masonry_gallery_filter_title_font_family);
$blog_masonry_gallery_filter_title_font_style = new ElatedMooseField("selectblanksimple","blog_masonry_gallery_filter_title_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_masonry_gallery_filter_title_font_style",$blog_masonry_gallery_filter_title_font_style);
$blog_masonry_gallery_filter_title_font_weight = new ElatedMooseField("selectblanksimple","blog_masonry_gallery_filter_title_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_masonry_gallery_filter_title_font_weight",$blog_masonry_gallery_filter_title_font_weight);
$blog_masonry_gallery_filter_title_letter_spacing = new ElatedMooseField("textsimple","blog_masonry_gallery_filter_title_letter_spacing","","Letter Spacing (px)","This is some description");
$row2->addChild("blog_masonry_gallery_filter_title_letter_spacing",$blog_masonry_gallery_filter_title_letter_spacing);

$group2 = new ElatedMooseGroup("Categories","Define text styles for filter categories");
$blog_masonry_gallery_filter_container->addChild("group2",$group2);

$row1 = new ElatedMooseRow();
$group2->addChild("row1",$row1);
$blog_masonry_gallery_filter_color = new ElatedMooseField("colorsimple","blog_masonry_gallery_filter_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_gallery_filter_color",$blog_masonry_gallery_filter_color);
$blog_masonry_gallery_filter_hovercolor = new ElatedMooseField("colorsimple","blog_masonry_gallery_filter_hovercolor","","Hover/Active Color","This is some description");
$row1->addChild("blog_masonry_gallery_filter_hovercolor",$blog_masonry_gallery_filter_hovercolor);
$blog_masonry_gallery_filter_font_size = new ElatedMooseField("textsimple","blog_masonry_gallery_filter_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_masonry_gallery_filter_font_size",$blog_masonry_gallery_filter_font_size);
$blog_masonry_gallery_filter_line_height = new ElatedMooseField("textsimple","blog_masonry_gallery_filter_line_height","","Line Height (px)","This is some description");
$row1->addChild("blog_masonry_gallery_filter_line_height",$blog_masonry_gallery_filter_line_height);

$row2 = new ElatedMooseRow(true);
$group2->addChild("row2",$row2);
$blog_masonry_gallery_filter_font_family = new ElatedMooseField("fontsimple","blog_masonry_gallery_filter_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_masonry_gallery_filter_font_family",$blog_masonry_gallery_filter_font_family);
$blog_masonry_gallery_filter_font_style = new ElatedMooseField("selectblanksimple","blog_masonry_gallery_filter_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_masonry_gallery_filter_font_style",$blog_masonry_gallery_filter_font_style);
$blog_masonry_gallery_filter_font_weight = new ElatedMooseField("selectblanksimple","blog_masonry_gallery_filter_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_masonry_gallery_filter_font_weight",$blog_masonry_gallery_filter_font_weight);
$blog_masonry_gallery_filter_text_transform = new ElatedMooseField("selectblanksimple","blog_masonry_gallery_filter_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_masonry_gallery_filter_text_transform",$blog_masonry_gallery_filter_text_transform);

$row3 = new ElatedMooseRow(true);
$group2->addChild("row3",$row3);

$blog_masonry_gallery_filter_letter_spacing = new ElatedMooseField("textsimple","blog_masonry_gallery_filter_letter_spacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_masonry_gallery_filter_letter_spacing",$blog_masonry_gallery_filter_letter_spacing);

$blog_masonry_gallery_filter_disable_separator = new ElatedMooseField("yesno","blog_masonry_gallery_filter_disable_separator","yes","Disable Separator Between Categories","Disabling this option will remove separator between filter categories.");
$blog_masonry_gallery_filter_container->addChild("blog_masonry_gallery_filter_disable_separator",$blog_masonry_gallery_filter_disable_separator);

$blog_masonry_gallery_content_position = new ElatedMooseField("select","blog_masonry_gallery_content_position","content_above_blog_list","Content Position","Choose content position for blog list template when sidebar is enabled. Note: This settings in only for template, not for archive pages", array(
	"content_above_blog_list" => "Content Above Blog List",
	"content_above_blog_list_and_sidebar" => "Content Above Blog List and Sidebar"
));
$panel23->addChild("blog_masonry_gallery_content_position",$blog_masonry_gallery_content_position);

$blog_masonry_gallery_post_meta_data_section = new ElatedMooseTitle("blog_masonry_gallery_post_meta_data_section", "Post Info Data Fields");
$panel23->addChild("blog_masonry_gallery_post_meta_data_section", $blog_masonry_gallery_post_meta_data_section);

$blog_masonry_gallery_show_categories= new ElatedMooseField("yesno","blog_masonry_gallery_show_categories","no","Show Categories","Enabling this option will Show Categories on Post List");
$panel23->addChild("blog_masonry_gallery_show_categories",$blog_masonry_gallery_show_categories);

$blog_masonry_gallery_show_comments = new ElatedMooseField("yesno","blog_masonry_gallery_show_comments","no","Show Comments","Enabling this option will Show Comments on Post List");
$panel23->addChild("blog_masonry_gallery_show_comments",$blog_masonry_gallery_show_comments);

$blog_masonry_gallery_show_author = new ElatedMooseField("yesno","blog_masonry_gallery_show_author","no","Show Author Name","Enabling this option will show author name on Post List and Blog Post Single");
$panel23->addChild("blog_masonry_gallery_show_author",$blog_masonry_gallery_show_author);

$blog_masonry_gallery_show_date = new ElatedMooseField("yesno","blog_masonry_gallery_show_date","no","Show Date","Enabling this option will show date on Post List");
$panel23->addChild("blog_masonry_gallery_show_date",$blog_masonry_gallery_show_date);

$blog_masonry_gallery_show_share = new ElatedMooseField("yesno","blog_masonry_gallery_show_share","no","Show Share","Enabling this option will show share on Post List", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_masonry_gallery_share_options_container"));
$panel23->addChild("blog_masonry_gallery_show_share",$blog_masonry_gallery_show_share);

$blog_masonry_gallery_share_options_container = new ElatedMooseContainer("blog_masonry_gallery_share_options_container","blog_masonry_gallery_show_share","no");
$panel23->addChild("blog_masonry_gallery_share_options_container",$blog_masonry_gallery_share_options_container);

$blog_masonry_gallery_select_share_options_masonry_type = new ElatedMooseField("select","blog_masonry_gallery_select_share_options_masonry_type","dropdown","Social Share Style","Choose Social Share Style for Masonry Type",array(
	"dropdown" => "Social Share Dropdown",
	"list" => "Social Share List"
));

$blog_masonry_gallery_share_options_container->addChild("blog_masonry_gallery_select_share_options_masonry_type",$blog_masonry_gallery_select_share_options_masonry_type);

$blog_masonry_gallery_share_icon_color = new ElatedMooseField("color","blog_masonry_gallery_share_icon_color","","Icon Color","Choose icon color for share dropdown");
$blog_masonry_gallery_share_options_container->addChild("blog_masonry_gallery_share_icon_color",$blog_masonry_gallery_share_icon_color);

$blog_masonry_gallery_share_hld_hover_icon_color = new ElatedMooseField("color","blog_masonry_gallery_share_hld_hover_icon_color","","Icon color on Quote/Link Holder Hover","Choose icon color for share dropdown when the quote/link holder is hovered over");
$blog_masonry_gallery_share_options_container->addChild("blog_masonry_gallery_share_hld_hover_icon_color",$blog_masonry_gallery_share_hld_hover_icon_color);

$blog_masonry_gallery_share_icon_hover_color = new ElatedMooseField("color","blog_masonry_gallery_share_icon_hover_color","","Icon Hover Color","Choose icon hover color for share dropdown");
$blog_masonry_gallery_share_options_container->addChild("blog_masonry_gallery_share_icon_hover_color",$blog_masonry_gallery_share_icon_hover_color);

$blog_masonry_gallery_share_background_color = new ElatedMooseField("color","blog_masonry_gallery_share_background_color","","Background Color","Choose background color for share dropdown list field");
$blog_masonry_gallery_share_options_container->addChild("blog_masonry_gallery_share_background_color",$blog_masonry_gallery_share_background_color);

$blog_masonry_gallery_show_like = new ElatedMooseField("yesno","blog_masonry_gallery_show_like","no","Show Likes",'Enabling this option will turn on "Likes"');
$panel23->addChild("blog_masonry_gallery_show_like",$blog_masonry_gallery_show_like);

$blog_masonry_gallery_post_design_style = new ElatedMooseTitle("blog_masonry_gallery_post_design_style", "Post Design Style");
$panel23->addChild("blog_masonry_gallery_post_design_style", $blog_masonry_gallery_post_design_style);

$blog_masonry_gallery_post_alignment = new ElatedMooseField("select","blog_masonry_gallery_post_alignment","center","Post Alignment","Choose alignment for whole post",array(
	"left" => "Left",
	"center" => "Center",
	"right" => "Right"
));
$panel23->addChild("blog_masonry_gallery_post_alignment",$blog_masonry_gallery_post_alignment);

$blog_masonry_gallery_show_article_icon = new ElatedMooseField("yesno","blog_masonry_gallery_show_article_icon","yes","Enable Article Icon","Enabling this option will show article icon", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_blog_masonry_gallery_show_article_icon_container"));
$panel23->addChild("blog_masonry_gallery_show_article_icon",$blog_masonry_gallery_show_article_icon);

$blog_masonry_gallery_show_article_icon_container = new ElatedMooseContainer("blog_masonry_gallery_show_article_icon_container","blog_masonry_gallery_show_article_icon","no");
$panel23->addChild("blog_masonry_gallery_show_article_icon_container",$blog_masonry_gallery_show_article_icon_container);

$row1 = new ElatedMooseRow();
$blog_masonry_gallery_show_article_icon_container->addChild("row1",$row1);

$blog_masonry_gallery_article_mark_color = new ElatedMooseField("color","blog_masonry_gallery_article_mark_color","","Icon Color","Choose icon color");
$row1->addChild("blog_masonry_gallery_article_mark_color",$blog_masonry_gallery_article_mark_color);

$blog_masonry_gallery_article_mark_hover_color = new ElatedMooseField("color","blog_masonry_gallery_article_mark_hover_color","","Icon Hover Color","Choose hover icon color");
$row1->addChild("blog_masonry_gallery_article_mark_hover_color",$blog_masonry_gallery_article_mark_hover_color);

$blog_masonry_gallery_overlay_group = new ElatedMooseGroup('Hover Overlay Style', 'Define Hover Overlay Style');
$panel23->addChild('blog_masonry_gallery_overlay_group', $blog_masonry_gallery_overlay_group);

        $row1 = new ElatedMooseRow();
        $blog_masonry_gallery_overlay_group->addChild('row1', $row1);

            $blog_masonry_gallery_overlay_color = new ElatedMooseField('colorsimple', 'blog_masonry_gallery_overlay_color', '', 'Color');
            $row1->addChild('blog_masonry_gallery_overlay_color', $blog_masonry_gallery_overlay_color);

            $blog_masonry_gallery_overlay_transparency = new ElatedMooseField('textsimple', 'blog_masonry_gallery_overlay_transparency', '', 'Transparency (0=full - 1=opaque)');
            $row1->addChild('blog_masonry_gallery_overlay_transparency', $blog_masonry_gallery_overlay_transparency);
		

$group8 = new ElatedMooseGroup("Blog List Spacing","Set spacing for blog layouts");
$panel23->addChild("group8",$group8);

$row1 = new ElatedMooseRow();
$group8->addChild("row1",$row1);

$blog_masonry_gallery_icon_margin_bottom = new ElatedMooseField("textsimple","blog_masonry_gallery_icon_margin_bottom","","Margin Under Icon Holder (px)","This is some description");
$row1->addChild("blog_masonry_gallery_icon_margin_bottom",$blog_masonry_gallery_icon_margin_bottom);

$blog_masonry_gallery_post_info_margin_top = new ElatedMooseField("textsimple","blog_masonry_gallery_post_info_margin_top","","Margin Above Post Info (px)","This is some description");
$row1->addChild("blog_masonry_gallery_post_info_margin_top",$blog_masonry_gallery_post_info_margin_top);

$blog_masonry_gallery_read_more_margin_top = new ElatedMooseField("textsimple","blog_masonry_gallery_read_more_margin_top","","Margin Above Read More Button (px)","This is some description");
$row1->addChild("blog_masonry_gallery_read_more_margin_top",$blog_masonry_gallery_read_more_margin_top);

$blog_masonry_gallery_social_share_list_margin_top = new ElatedMooseField("textsimple","blog_masonry_gallery_social_share_list_margin_top","","Margin Above Social Share List Holder (px)","This is some description");
$row1->addChild("blog_masonry_gallery_social_share_list_margin_top",$blog_masonry_gallery_social_share_list_margin_top);

$post_text_styling= new ElatedMooseTitle("post_text_styling", "Post Text Style");
$panel23->addChild("post_text_styling", $post_text_styling);

$group2 = new ElatedMooseGroup("Post Title","Define title styles in this blog post template.");
$panel23->addChild("group2",$group2);

$row1 = new ElatedMooseRow();
$group2->addChild("row1",$row1);

$blog_masonry_gallery_title_color = new ElatedMooseField("colorsimple","blog_masonry_gallery_title_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_gallery_title_color",$blog_masonry_gallery_title_color);

$blog_masonry_gallery_title_hover_color = new ElatedMooseField("colorsimple","blog_masonry_gallery_title_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_masonry_gallery_title_hover_color",$blog_masonry_gallery_title_hover_color);

$blog_masonry_gallery_title_fontsize = new ElatedMooseField("textsimple","blog_masonry_gallery_title_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_masonry_gallery_title_fontsize",$blog_masonry_gallery_title_fontsize);

$row2 = new ElatedMooseRow(true);
$group2->addChild("row2",$row2);

$blog_masonry_gallery_title_lineheight = new ElatedMooseField("textsimple","blog_masonry_gallery_title_lineheight","","Line Height (px)","This is some description");
$row1->addChild("blog_masonry_gallery_title_lineheight",$blog_masonry_gallery_title_lineheight);

$blog_masonry_gallery_title_google_fonts = new ElatedMooseField("fontsimple","blog_masonry_gallery_title_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_masonry_gallery_title_google_fonts",$blog_masonry_gallery_title_google_fonts);

$blog_masonry_gallery_title_fontstyle = new ElatedMooseField("selectblanksimple","blog_masonry_gallery_title_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_masonry_gallery_title_fontstyle",$blog_masonry_gallery_title_fontstyle);

$blog_masonry_gallery_title_fontweight = new ElatedMooseField("selectblanksimple","blog_masonry_gallery_title_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_masonry_gallery_title_fontweight",$blog_masonry_gallery_title_fontweight);

$row3 = new ElatedMooseRow(true);
$group2->addChild("row3",$row3);


$blog_masonry_gallery_title_texttransform = new ElatedMooseField("selectblanksimple","blog_masonry_gallery_title_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_masonry_gallery_title_texttransform",$blog_masonry_gallery_title_texttransform);

$blog_masonry_gallery_title_letterspacing = new ElatedMooseField("textsimple","blog_masonry_gallery_title_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_masonry_gallery_title_letterspacing",$blog_masonry_gallery_title_letterspacing);

$group4 = new ElatedMooseGroup("Post Info Data","Define post info text styles (date, category names etc.) Note: Single Posts will take the same styles as in list");
$panel23->addChild("group4",$group4);

$row1 = new ElatedMooseRow();
$group4->addChild("row1",$row1);

$blog_masonry_gallery_info_color = new ElatedMooseField("colorsimple","blog_masonry_gallery_info_color","","Text Color","This is some description");
$row1->addChild("blog_masonry_gallery_info_color",$blog_masonry_gallery_info_color);

$blog_masonry_gallery_info_link_color = new ElatedMooseField("colorsimple","blog_masonry_gallery_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_masonry_gallery_info_link_color",$blog_masonry_gallery_info_link_color);

$blog_masonry_gallery_info_hover_color = new ElatedMooseField("colorsimple","blog_masonry_gallery_info_hover_color","","Hover Color","This is some description");
$row1->addChild("blog_masonry_gallery_info_hover_color",$blog_masonry_gallery_info_hover_color);

$blog_masonry_gallery_info_fontsize = new ElatedMooseField("textsimple","blog_masonry_gallery_info_fontsize","","Font Size (px)","This is some description");
$row1->addChild("blog_masonry_gallery_info_fontsize",$blog_masonry_gallery_info_fontsize);

$row2 = new ElatedMooseRow(true);
$group4->addChild("row2",$row2);


$blog_masonry_gallery_info_lineheight = new ElatedMooseField("textsimple","blog_masonry_gallery_info_lineheight","","Line Height (px)","This is some description");
$row2->addChild("blog_masonry_gallery_info_lineheight",$blog_masonry_gallery_info_lineheight);

$blog_masonry_gallery_info_google_fonts = new ElatedMooseField("fontsimple","blog_masonry_gallery_info_google_fonts","-1","Font Family","This is some description");
$row2->addChild("blog_masonry_gallery_info_google_fonts",$blog_masonry_gallery_info_google_fonts);

$blog_masonry_gallery_info_fontstyle = new ElatedMooseField("selectblanksimple","blog_masonry_gallery_info_fontstyle","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_masonry_gallery_info_fontstyle",$blog_masonry_gallery_info_fontstyle);

$blog_masonry_gallery_info_fontweight = new ElatedMooseField("selectblanksimple","blog_masonry_gallery_info_fontweight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_masonry_gallery_info_fontweight",$blog_masonry_gallery_info_fontweight);

$row3 = new ElatedMooseRow(true);
$group4->addChild("row3",$row3);

$blog_masonry_gallery_info_texttransform = new ElatedMooseField("selectblanksimple","blog_masonry_gallery_info_texttransform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row3->addChild("blog_masonry_gallery_info_texttransform",$blog_masonry_gallery_info_texttransform);

$blog_masonry_gallery_info_letterspacing = new ElatedMooseField("textsimple","blog_masonry_gallery_info_letterspacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_masonry_gallery_info_letterspacing",$blog_masonry_gallery_info_letterspacing);

//Blog List

$panel28 = new ElatedMoosePanel("Blog List Shortcode","blog_list_panel");
$blogPage->addChild("panel28",$panel28);

//Blog List Boxes

$blog_list_boxes_section_subtitle = new ElatedMooseTitle("blog_list_boxes_section_subtitle", "Blog List - Boxes");
$panel28->addChild("blog_list_boxes_section_subtitle", $blog_list_boxes_section_subtitle);

$group6 = new ElatedMooseGroup("Blog List Padding","Enter Boxes Blog List padding");
$panel28->addChild("group6",$group6);
$row1 = new ElatedMooseRow();
$group6->addChild("row1",$row1);

$blog_list_boxes_padding_top = new ElatedMooseField("textsimple","blog_list_boxes_padding_top","","Padding Top (px)","This is some description");
$row1->addChild("blog_list_boxes_padding_top",$blog_list_boxes_padding_top);

$blog_list_boxes_padding_right = new ElatedMooseField("textsimple","blog_list_boxes_padding_right","","Padding Right (px)","This is some description");
$row1->addChild("blog_list_boxes_padding_right",$blog_list_boxes_padding_right);

$blog_list_boxes_padding_bottom = new ElatedMooseField("textsimple","blog_list_boxes_padding_bottom","","Padding Bottom (px)","This is some description");
$row1->addChild("blog_list_boxes_padding_bottom",$blog_list_boxes_padding_bottom);

$blog_list_boxes_padding_left = new ElatedMooseField("textsimple","blog_list_boxes_padding_left","","Padding Left (px)","This is some description");
$row1->addChild("blog_list_boxes_padding_left",$blog_list_boxes_padding_left);

$group16 = new ElatedMooseGroup("Blog List Spacing","Define blog list spacing");
$panel28->addChild("group16",$group16);

$row1 = new ElatedMooseRow();
$group16->addChild("row1",$row1);

$blog_list_boxes_title_margin_bottom = new ElatedMooseField("textsimple","blog_list_boxes_title_margin_bottom","","Margin Under Title (px)","This is some description");
$row1->addChild("blog_list_boxes_title_margin_bottom",$blog_list_boxes_title_margin_bottom);

$blog_list_boxes_post_info_margin_bottom = new ElatedMooseField("textsimple","blog_list_boxes_post_info_margin_bottom","","Margin Under Post Info (px)","This is some description");
$row1->addChild("blog_list_boxes_post_info_margin_bottom",$blog_list_boxes_post_info_margin_bottom);

$blog_list_boxes_read_more_margin_top = new ElatedMooseField("textsimple","blog_list_boxes_read_more_margin_top","","Margin Above Read More Button (px)","This is some description");
$row1->addChild("blog_list_boxes_read_more_margin_top",$blog_list_boxes_read_more_margin_top);

$group17 = new ElatedMooseGroup("Blog List Title","Define Blog List title style");
$panel28->addChild("group17",$group17);

$row1 = new ElatedMooseRow();
$group17->addChild("row1",$row1);

$blog_list_boxes_title_color = new ElatedMooseField("colorsimple","blog_list_boxes_title_color","","Text Color","This is some description");
$row1->addChild("blog_list_boxes_title_color",$blog_list_boxes_title_color);

$blog_list_boxes_title_hover_color = new ElatedMooseField("colorsimple","blog_list_boxes_title_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_list_boxes_title_hover_color",$blog_list_boxes_title_hover_color);

$blog_list_boxes_title_font_size = new ElatedMooseField("textsimple","blog_list_boxes_title_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_list_boxes_title_font_size",$blog_list_boxes_title_font_size);

$blog_list_boxes_title_line_height = new ElatedMooseField("textsimple","blog_list_boxes_title_line_height","","Line Height (px)","This is some description");
$row1->addChild("blog_list_boxes_title_line_height",$blog_list_boxes_title_line_height);

$row2 = new ElatedMooseRow();
$group17->addChild("row2",$row2);

$blog_list_boxes_title_text_transform = new ElatedMooseField("selectblanksimple","blog_list_boxes_title_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_list_boxes_title_text_transform",$blog_list_boxes_title_text_transform);

$blog_list_boxes_title_font_family = new ElatedMooseField("fontsimple","blog_list_boxes_title_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_list_boxes_title_font_family",$blog_list_boxes_title_font_family);

$blog_list_boxes_title_font_style = new ElatedMooseField("selectblanksimple","blog_list_boxes_title_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_list_boxes_title_font_style",$blog_list_boxes_title_font_style);

$blog_list_boxes_title_font_weight = new ElatedMooseField("selectblanksimple","blog_list_boxes_title_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_list_boxes_title_font_weight",$blog_list_boxes_title_font_weight);


$row3 = new ElatedMooseRow();
$group17->addChild("row3",$row3);

$blog_list_boxes_title_letter_spacing = new ElatedMooseField("textsimple","blog_list_boxes_title_letter_spacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_list_boxes_title_letter_spacing",$blog_list_boxes_title_letter_spacing);


$group18 = new ElatedMooseGroup("Blog List Post Info","Define blog list post info style");
$panel28->addChild("group18",$group18);

$row1 = new ElatedMooseRow();
$group18->addChild("row1",$row1);

$blog_list_boxes_post_info_color = new ElatedMooseField("colorsimple","blog_list_boxes_post_info_color","","Text Color","This is some description");
$row1->addChild("blog_list_boxes_post_info_color",$blog_list_boxes_post_info_color);

$blog_list_boxes_post_info_link_color = new ElatedMooseField("colorsimple","blog_list_boxes_post_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_list_boxes_post_info_link_color",$blog_list_boxes_post_info_link_color);

$blog_list_boxes_post_info_link_hover_color = new ElatedMooseField("colorsimple","blog_list_boxes_post_info_link_hover_color","","Link Hover Color","This is some description");
$row1->addChild("blog_list_boxes_post_info_link_hover_color",$blog_list_boxes_post_info_link_hover_color);

$blog_list_boxes_post_info_font_size = new ElatedMooseField("textsimple","blog_list_boxes_post_info_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_list_boxes_post_info_font_size",$blog_list_boxes_post_info_font_size);


$row2 = new ElatedMooseRow();
$group18->addChild("row2",$row2);

$blog_list_boxes_post_info_line_height = new ElatedMooseField("textsimple","blog_list_boxes_post_info_line_height","","Line Height (px)","This is some description");
$row2->addChild("blog_list_boxes_post_info_line_height",$blog_list_boxes_post_info_line_height);

$blog_list_boxes_post_info_text_transform = new ElatedMooseField("selectblanksimple","blog_list_boxes_post_info_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_list_boxes_post_info_text_transform",$blog_list_boxes_post_info_text_transform);

$blog_list_boxes_post_info_font_family = new ElatedMooseField("fontsimple","blog_list_boxes_post_info_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_list_boxes_post_info_font_family",$blog_list_boxes_post_info_font_family);

$blog_list_boxes_post_info_font_style = new ElatedMooseField("selectblanksimple","blog_list_boxes_post_info_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_list_boxes_post_info_font_style",$blog_list_boxes_post_info_font_style);

$row3 = new ElatedMooseRow();
$group18->addChild("row3",$row3);

$blog_list_boxes_post_info_font_weight = new ElatedMooseField("selectblanksimple","blog_list_boxes_post_info_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row3->addChild("blog_list_boxes_post_info_font_weight",$blog_list_boxes_post_info_font_weight);

$blog_list_boxes_post_info_link_font_weight = new ElatedMooseField("selectblanksimple","blog_list_boxes_post_info_link_font_weight","","Link Font Weight","This is some description",$eltd_moose_options_fontweight);
$row3->addChild("blog_list_boxes_post_info_link_font_weight",$blog_list_boxes_post_info_link_font_weight);

$blog_list_boxes_post_info_letter_spacing = new ElatedMooseField("textsimple","blog_list_boxes_post_info_letter_spacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_list_boxes_post_info_letter_spacing",$blog_list_boxes_post_info_letter_spacing);

$group23 = new ElatedMooseGroup("Blog List Date Style","Define blog list date box style");
$panel28->addChild("group23",$group23);

$row1 = new ElatedMooseRow();
$group23->addChild("row1",$row1);

$blog_list_boxes_date_color = new ElatedMooseField("colorsimple","blog_list_boxes_date_color","","Text Color", "Choose color for date");
$row1->addChild("blog_list_boxes_date_color",$blog_list_boxes_date_color);

$blog_list_boxes_date_bckg_color = new ElatedMooseField("colorsimple","blog_list_boxes_date_bckg_color","","Background Color", "Choose color for date background");
$row1->addChild("blog_list_boxes_date_bckg_color",$blog_list_boxes_date_bckg_color);

$group24 = new ElatedMooseGroup("Blog List Comments Style","Define blog list comments box style");
$panel28->addChild("group24",$group24);

$row1 = new ElatedMooseRow();
$group24->addChild("row1",$row1);

$blog_list_boxes_comments_color = new ElatedMooseField("colorsimple","blog_list_boxes_comments_color","","Text Color", "Choose color for date");
$row1->addChild("blog_list_boxes_comments_color",$blog_list_boxes_comments_color);

$blog_list_boxes_comments_bckg_color = new ElatedMooseField("colorsimple","blog_list_boxes_comments_bckg_color","","Background Color", "Choose color for date background");
$row1->addChild("blog_list_boxes_comments_bckg_color",$blog_list_boxes_comments_bckg_color);

$blog_list_minimal_subtitle = new ElatedMooseTitle("blog_list_minimal_subtitle", "Blog List - Minimal");
$panel28->addChild("blog_list_minimal_subtitle", $blog_list_minimal_subtitle);

$group5 = new ElatedMooseGroup("Blog List Spacing","Define blog list spacing");
$panel28->addChild("group5",$group5);

$row1 = new ElatedMooseRow(true);
$group5->addChild("row1",$row1);

$blog_list_minimal_title_margin_bottom = new ElatedMooseField("textsimple","blog_list_minimal_title_margin_bottom","","Margin Under Title (px)","This is some description");
$row1->addChild("blog_list_minimal_title_margin_bottom",$blog_list_minimal_title_margin_bottom);

$blog_list_minimal_post_info_margin_bottom = new ElatedMooseField("textsimple","blog_list_minimal_post_info_margin_bottom","","Margin Under Post Info (px)","This is some description");
$row1->addChild("blog_list_minimal_post_info_margin_bottom",$blog_list_minimal_post_info_margin_bottom);

$blog_list_minimal_read_more_margin_top = new ElatedMooseField("textsimple","blog_list_minimal_read_more_margin_top","","Margin Above Read More Button (px)","This is some description");
$row1->addChild("blog_list_minimal_read_more_margin_top",$blog_list_minimal_read_more_margin_top);

// Image in left box

$image_in_left_box = new ElatedMooseTitle("image_in_left_box", "Blog List - Image in Left Box");
$panel28->addChild("image_in_left_box", $image_in_left_box);

$group28 = new ElatedMooseGroup("Blog List Title","Define Blog List title style");
$panel28->addChild("group28",$group28);
$row1 = new ElatedMooseRow();
$group28->addChild("row1",$row1);

$blog_list_img_in_lbox_title_color = new ElatedMooseField("colorsimple","blog_list_img_in_lbox_title_color","","Text Color","This is some description");
$row1->addChild("blog_list_img_in_lbox_title_color",$blog_list_img_in_lbox_title_color);

$blog_list_img_in_lbox_title_hover_color = new ElatedMooseField("colorsimple","blog_list_img_in_lbox_title_hover_color","","Text Hover Color","This is some description");
$row1->addChild("blog_list_img_in_lbox_title_hover_color",$blog_list_img_in_lbox_title_hover_color);

$blog_list_img_in_lbox_title_font_size = new ElatedMooseField("textsimple","blog_list_img_in_lbox_title_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_list_img_in_lbox_title_font_size",$blog_list_img_in_lbox_title_font_size);

$blog_list_img_in_lbox_title_line_height = new ElatedMooseField("textsimple","blog_list_img_in_lbox_title_line_height","","Line Height (px)","This is some description");
$row1->addChild("blog_list_img_in_lbox_title_line_height",$blog_list_img_in_lbox_title_line_height);

$row2 = new ElatedMooseRow(true);
$group28->addChild("row2",$row2);

$blog_list_img_in_lbox_title_text_transform = new ElatedMooseField("selectblanksimple","blog_list_img_in_lbox_title_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_list_img_in_lbox_title_text_transform",$blog_list_img_in_lbox_title_text_transform);

$blog_list_img_in_lbox_title_font_family = new ElatedMooseField("fontsimple","blog_list_img_in_lbox_title_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_list_img_in_lbox_title_font_family",$blog_list_img_in_lbox_title_font_family);

$blog_list_img_in_lbox_title_font_style = new ElatedMooseField("selectblanksimple","blog_list_img_in_lbox_title_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_list_img_in_lbox_title_font_style",$blog_list_img_in_lbox_title_font_style);

$blog_list_img_in_lbox_title_font_weight = new ElatedMooseField("selectblanksimple","blog_list_img_in_lbox_title_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_list_img_in_lbox_title_font_weight",$blog_list_img_in_lbox_title_font_weight);


$row3 = new ElatedMooseRow(true);
$group28->addChild("row3",$row3);

$blog_list_img_in_lbox_title_letter_spacing = new ElatedMooseField("textsimple","blog_list_img_in_lbox_title_letter_spacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_list_img_in_lbox_title_letter_spacing",$blog_list_img_in_lbox_title_letter_spacing);


$group29 = new ElatedMooseGroup("Blog List Post Info","Define blog list post info style");
$panel28->addChild("group29",$group29);
$row1 = new ElatedMooseRow();
$group29->addChild("row1",$row1);

$blog_list_img_in_lbox_post_info_color = new ElatedMooseField("colorsimple","blog_list_img_in_lbox_post_info_color","","Text Color","This is some description");
$row1->addChild("blog_list_img_in_lbox_post_info_color",$blog_list_img_in_lbox_post_info_color);

$blog_list_img_in_lbox_post_info_link_color = new ElatedMooseField("colorsimple","blog_list_img_in_lbox_post_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_list_img_in_lbox_post_info_link_color",$blog_list_img_in_lbox_post_info_link_color);

$blog_list_img_in_lbox_post_info_link_hover_color = new ElatedMooseField("colorsimple","blog_list_img_in_lbox_post_info_link_hover_color","","Link Hover Color","This is some description");
$row1->addChild("blog_list_img_in_lbox_post_info_link_hover_color",$blog_list_img_in_lbox_post_info_link_hover_color);

$blog_list_img_in_lbox_post_info_font_size = new ElatedMooseField("textsimple","blog_list_img_in_lbox_post_info_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_list_img_in_lbox_post_info_font_size",$blog_list_img_in_lbox_post_info_font_size);


$row2 = new ElatedMooseRow(true);
$group29->addChild("row2",$row2);

$blog_list_img_in_lbox_post_info_line_height = new ElatedMooseField("textsimple","blog_list_img_in_lbox_post_info_line_height","","Line Height (px)","This is some description");
$row2->addChild("blog_list_img_in_lbox_post_info_line_height",$blog_list_img_in_lbox_post_info_line_height);

$blog_list_img_in_lbox_post_info_text_transform = new ElatedMooseField("selectblanksimple","blog_list_img_in_lbox_post_info_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_list_img_in_lbox_post_info_text_transform",$blog_list_img_in_lbox_post_info_text_transform);

$blog_list_img_in_lbox_post_info_font_family = new ElatedMooseField("fontsimple","blog_list_img_in_lbox_post_info_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_list_img_in_lbox_post_info_font_family",$blog_list_img_in_lbox_post_info_font_family);

$blog_list_img_in_lbox_post_info_font_style = new ElatedMooseField("selectblanksimple","blog_list_img_in_lbox_post_info_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_list_img_in_lbox_post_info_font_style",$blog_list_img_in_lbox_post_info_font_style);

$row3 = new ElatedMooseRow(true);
$group29->addChild("row3",$row3);

$blog_list_img_in_lbox_post_info_font_weight = new ElatedMooseField("selectblanksimple","blog_list_img_in_lbox_post_info_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row3->addChild("blog_list_img_in_lbox_post_info_font_weight",$blog_list_img_in_lbox_post_info_font_weight);

$blog_list_img_in_lbox_post_info_letter_spacing = new ElatedMooseField("textsimple","blog_list_img_in_lbox_post_info_letter_spacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_list_img_in_lbox_post_info_letter_spacing",$blog_list_img_in_lbox_post_info_letter_spacing);

$group30 = new ElatedMooseGroup("Blog List Date Style","Define blog list date style");
$panel28->addChild("group30",$group30);
$row1 = new ElatedMooseRow();
$group30->addChild("row1",$row1);

$blog_list_img_in_lbox_date_color = new ElatedMooseField("colorsimple","blog_list_img_in_lbox_date_color","","Text Color","This is some description");
$row1->addChild("blog_list_img_in_lbox_date_color",$blog_list_img_in_lbox_date_color);

$blog_list_img_in_lbox_date_font_size = new ElatedMooseField("textsimple","blog_list_img_in_lbox_date_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_list_img_in_lbox_date_font_size",$blog_list_img_in_lbox_date_font_size);

$blog_list_img_in_lbox_date_line_height = new ElatedMooseField("textsimple","blog_list_img_in_lbox_date_line_height","","Line Height (px)","This is some description");
$row1->addChild("blog_list_img_in_lbox_date_line_height",$blog_list_img_in_lbox_date_line_height);

$blog_list_img_in_lbox_date_text_transform = new ElatedMooseField("selectblanksimple","blog_list_img_in_lbox_date_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row1->addChild("blog_list_img_in_lbox_date_text_transform",$blog_list_img_in_lbox_date_text_transform);

$row2 = new ElatedMooseRow(true);
$group30->addChild("row2",$row2);

$blog_list_img_in_lbox_date_font_family = new ElatedMooseField("fontsimple","blog_list_img_in_lbox_date_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_list_img_in_lbox_date_font_family",$blog_list_img_in_lbox_date_font_family);

$blog_list_img_in_lbox_date_font_style = new ElatedMooseField("selectblanksimple","blog_list_img_in_lbox_date_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_list_img_in_lbox_date_font_style",$blog_list_img_in_lbox_date_font_style);

$blog_list_img_in_lbox_date_font_weight = new ElatedMooseField("selectblanksimple","blog_list_img_in_lbox_date_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_list_img_in_lbox_date_font_weight",$blog_list_img_in_lbox_date_font_weight);

$blog_list_img_in_lbox_date_letter_spacing = new ElatedMooseField("textsimple","blog_list_img_in_lbox_date_letter_spacing","","Letter Spacing (px)","This is some description");
$row2->addChild("blog_list_img_in_lbox_date_letter_spacing",$blog_list_img_in_lbox_date_letter_spacing);

$group31 = new ElatedMooseGroup("Blog List Spacing","Define blog list spacing");
$panel28->addChild("group31",$group31);

$row1 = new ElatedMooseRow(true);
$group31->addChild("row1",$row1);

$blog_list_img_in_lbox_title_margin_bttm = new ElatedMooseField("textsimple","blog_list_img_in_lbox_title_margin_bttm","","Margin Under Title (px)","This is some description");
$row1->addChild("blog_list_img_in_lbox_title_margin_bttm",$blog_list_img_in_lbox_title_margin_bttm);

$blog_list_img_in_lbox_post_info_margin_bttm = new ElatedMooseField("textsimple","blog_list_img_in_lbox_post_info_margin_bttm","","Margin Under Post Info (px)","This is some description");
$row1->addChild("blog_list_img_in_lbox_post_info_margin_bttm",$blog_list_img_in_lbox_post_info_margin_bttm);

$blog_list_img_in_lbox_read_more_margin_top = new ElatedMooseField("textsimple","blog_list_img_in_lbox_read_more_margin_top","","Margin Above Read More Button (px)","This is some description");
$row1->addChild("blog_list_img_in_lbox_read_more_margin_top",$blog_list_img_in_lbox_read_more_margin_top);

/*** Blog Carousel ***/

$panel31 = new ElatedMoosePanel("Blog Carousel","blog_slider");
$blogPage->addChild("panel31",$panel31);

$blog_slider_default_and_with_info_always_title = new ElatedMooseTitle("blog_slider_default_and_with_info_always_title","Default and Post Info Visible");
$panel31->addChild("blog_slider_default_and_with_info_always_title",$blog_slider_default_and_with_info_always_title);

$group23 = new ElatedMooseGroup("Title style", "Blog Carousel title style");
$panel31->addChild("group23",$group23);

$row1 = new ElatedMooseRow();
$group23->addChild("row1",$row1);

$blog_slider_title_color = new ElatedMooseField("colorsimple","blog_slider_title_color","","Title Color","This is some description");
$row1->addChild("blog_slider_title_color",$blog_slider_title_color);

$blog_slider_title_hover_color = new ElatedMooseField("colorsimple","blog_slider_title_hover_color","","Title Hover Color","This is some description");
$row1->addChild("blog_slider_title_hover_color",$blog_slider_title_hover_color);

$blog_slider_title_font_size = new ElatedMooseField("textsimple","blog_slider_title_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_slider_title_font_size",$blog_slider_title_font_size);

$blog_slider_title_line_height = new ElatedMooseField("textsimple","blog_slider_title_line_height","","Line Height (px)","This is some description");
$row1->addChild("blog_slider_title_line_height",$blog_slider_title_line_height);

$row2 = new ElatedMooseRow();
$group23->addChild("row2",$row2);

$blog_slider_title_text_transform = new ElatedMooseField("selectblanksimple","blog_slider_title_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_slider_title_text_transform",$blog_slider_title_text_transform);

$blog_slider_title_font_family = new ElatedMooseField("fontsimple","blog_slider_title_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_slider_title_font_family",$blog_slider_title_font_family);

$blog_slider_title_font_style = new ElatedMooseField("selectblanksimple","blog_slider_title_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_slider_title_font_style",$blog_slider_title_font_style);

$blog_slider_title_font_weight = new ElatedMooseField("selectblanksimple","blog_slider_title_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_slider_title_font_weight",$blog_slider_title_font_weight);


$row3 = new ElatedMooseRow();
$group23->addChild("row3",$row3);

$blog_slider_title_letter_spacing = new ElatedMooseField("textsimple","blog_slider_title_letter_spacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_slider_title_letter_spacing",$blog_slider_title_letter_spacing);

$group24 = new ElatedMooseGroup("Category style", "Blog Carousel categories style");
$panel31->addChild("group24",$group24);

$row1 = new ElatedMooseRow();
$group24->addChild("row1",$row1);

$blog_slider_category_color = new ElatedMooseField("colorsimple","blog_slider_category_color","","Category Color","This is some description");
$row1->addChild("blog_slider_category_color",$blog_slider_category_color);

$blog_slider_category_hover_color = new ElatedMooseField("colorsimple","blog_slider_category_hover_color","","Category Hover Color","This is some description");
$row1->addChild("blog_slider_category_hover_color",$blog_slider_category_hover_color);

$blog_slider_category_font_size = new ElatedMooseField("textsimple","blog_slider_category_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_slider_category_font_size",$blog_slider_category_font_size);

$blog_slider_category_line_height = new ElatedMooseField("textsimple","blog_slider_category_line_height","","Line Height (px)","This is some description");
$row1->addChild("blog_slider_category_line_height",$blog_slider_category_line_height);

$row2 = new ElatedMooseRow();
$group24->addChild("row2",$row2);

$blog_slider_category_text_transform = new ElatedMooseField("selectblanksimple","blog_slider_category_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_slider_category_text_transform",$blog_slider_category_text_transform);

$blog_slider_category_font_family = new ElatedMooseField("fontsimple","blog_slider_category_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_slider_category_font_family",$blog_slider_category_font_family);

$blog_slider_category_font_style = new ElatedMooseField("selectblanksimple","blog_slider_category_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_slider_category_font_style",$blog_slider_category_font_style);

$blog_slider_category_font_weight = new ElatedMooseField("selectblanksimple","blog_slider_category_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_slider_category_font_weight",$blog_slider_category_font_weight);


$row3 = new ElatedMooseRow();
$group24->addChild("row3",$row3);

$blog_slider_category_letter_spacing = new ElatedMooseField("textsimple","blog_slider_category_letter_spacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_slider_category_letter_spacing",$blog_slider_category_letter_spacing);

$group25 = new ElatedMooseGroup("Date style", "Blog Carousel date style");
$panel31->addChild("group25",$group25);

$row1 = new ElatedMooseRow();
$group25->addChild("row1",$row1);

$blog_slider_date_color = new ElatedMooseField("colorsimple","blog_slider_date_color","","Date Color","This is some description");
$row1->addChild("blog_slider_date_color",$blog_slider_date_color);

$blog_slider_date_font_size = new ElatedMooseField("textsimple","blog_slider_date_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_slider_date_font_size",$blog_slider_date_font_size);

$blog_slider_date_line_height = new ElatedMooseField("textsimple","blog_slider_date_line_height","","Line Height (px)","This is some description");
$row1->addChild("blog_slider_date_line_height",$blog_slider_date_line_height);

$blog_slider_date_text_transform = new ElatedMooseField("selectblanksimple","blog_slider_date_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row1->addChild("blog_slider_date_text_transform",$blog_slider_date_text_transform);

$row2 = new ElatedMooseRow();
$group25->addChild("row2",$row2);

$blog_slider_date_font_family = new ElatedMooseField("fontsimple","blog_slider_date_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_slider_date_font_family",$blog_slider_date_font_family);

$blog_slider_date_font_style = new ElatedMooseField("selectblanksimple","blog_slider_date_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_slider_date_font_style",$blog_slider_date_font_style);

$blog_slider_date_font_weight = new ElatedMooseField("selectblanksimple","blog_slider_date_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_slider_date_font_weight",$blog_slider_date_font_weight);

$blog_slider_date_letter_spacing = new ElatedMooseField("textsimple","blog_slider_date_letter_spacing","","Letter Spacing (px)","This is some description");
$row2->addChild("blog_slider_date_letter_spacing",$blog_slider_date_letter_spacing);


$blog_slider_info_in_bottom_title = new ElatedMooseTitle("blog_slider_info_in_bottom_title","Post Info in Bottom");
$panel31->addChild("blog_slider_info_in_bottom_title",$blog_slider_info_in_bottom_title);

$group26 = new ElatedMooseGroup("Title style", "Blog Carousel title style");
$panel31->addChild("group26",$group26);

$row1 = new ElatedMooseRow();
$group26->addChild("row1",$row1);

$blog_slider_post_info_in_bottom_title_color = new ElatedMooseField("colorsimple","blog_slider_post_info_in_bottom_title_color","","Title Color","This is some description");
$row1->addChild("blog_slider_post_info_in_bottom_title_color",$blog_slider_post_info_in_bottom_title_color);

$blog_slider_post_info_in_bottom_title_hover_color = new ElatedMooseField("colorsimple","blog_slider_post_info_in_bottom_title_hover_color","","Title Hover Color","This is some description");
$row1->addChild("blog_slider_post_info_in_bottom_title_hover_color",$blog_slider_post_info_in_bottom_title_hover_color);

$blog_slider_post_info_in_bottom_title_font_size = new ElatedMooseField("textsimple","blog_slider_post_info_in_bottom_title_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_slider_post_info_in_bottom_title_font_size",$blog_slider_post_info_in_bottom_title_font_size);

$blog_slider_post_info_in_bottom_title_line_height = new ElatedMooseField("textsimple","blog_slider_post_info_in_bottom_title_line_height","","Line Height (px)","This is some description");
$row1->addChild("blog_slider_post_info_in_bottom_title_line_height",$blog_slider_post_info_in_bottom_title_line_height);

$row2 = new ElatedMooseRow();
$group26->addChild("row2",$row2);

$blog_slider_post_info_in_bottom_title_text_transform = new ElatedMooseField("selectblanksimple","blog_slider_post_info_in_bottom_title_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_slider_post_info_in_bottom_title_text_transform",$blog_slider_post_info_in_bottom_title_text_transform);

$blog_slider_post_info_in_bottom_title_font_family = new ElatedMooseField("fontsimple","blog_slider_post_info_in_bottom_title_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_slider_post_info_in_bottom_title_font_family",$blog_slider_post_info_in_bottom_title_font_family);

$blog_slider_post_info_in_bottom_title_font_style = new ElatedMooseField("selectblanksimple","blog_slider_post_info_in_bottom_title_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_slider_post_info_in_bottom_title_font_style",$blog_slider_post_info_in_bottom_title_font_style);

$blog_slider_post_info_in_bottom_title_font_weight = new ElatedMooseField("selectblanksimple","blog_slider_post_info_in_bottom_title_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_slider_post_info_in_bottom_title_font_weight",$blog_slider_post_info_in_bottom_title_font_weight);

$row3 = new ElatedMooseRow();
$group26->addChild("row3",$row3);

$blog_slider_post_info_in_bottom_title_letter_spacing = new ElatedMooseField("textsimple","blog_slider_post_info_in_bottom_title_letter_spacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_slider_post_info_in_bottom_title_letter_spacing",$blog_slider_post_info_in_bottom_title_letter_spacing);

$group27 = new ElatedMooseGroup("Post Info style", "Blog Carousel post info style");
$panel31->addChild("group27",$group27);

$row1 = new ElatedMooseRow();
$group27->addChild("row1",$row1);

$blog_slider_post_info_in_bottom_post_info_color = new ElatedMooseField("colorsimple","blog_slider_post_info_in_bottom_post_info_color","","Text Color","This is some description");
$row1->addChild("blog_slider_post_info_in_bottom_post_info_color",$blog_slider_post_info_in_bottom_post_info_color);

$blog_slider_post_info_in_bottom_post_info_link_color = new ElatedMooseField("colorsimple","blog_slider_post_info_in_bottom_post_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_slider_post_info_in_bottom_post_info_link_color",$blog_slider_post_info_in_bottom_post_info_link_color);

$blog_slider_post_info_in_bottom_post_info_link_hover_color = new ElatedMooseField("colorsimple","blog_slider_post_info_in_bottom_post_info_link_hover_color","","Link Hover Color","This is some description");
$row1->addChild("blog_slider_post_info_in_bottom_post_info_link_hover_color",$blog_slider_post_info_in_bottom_post_info_link_hover_color);

$blog_slider_post_info_in_bottom_post_info_font_size = new ElatedMooseField("textsimple","blog_slider_post_info_in_bottom_post_info_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_slider_post_info_in_bottom_post_info_font_size",$blog_slider_post_info_in_bottom_post_info_font_size);

$row2 = new ElatedMooseRow();
$group27->addChild("row2",$row2);

$blog_slider_post_info_in_bottom_post_info_line_height = new ElatedMooseField("textsimple","blog_slider_post_info_in_bottom_post_info_line_height","","Line Height (px)","This is some description");
$row2->addChild("blog_slider_post_info_in_bottom_post_info_line_height",$blog_slider_post_info_in_bottom_post_info_line_height);

$blog_slider_post_info_in_bottom_post_info_text_transform = new ElatedMooseField("selectblanksimple","blog_slider_post_info_in_bottom_post_info_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_slider_post_info_in_bottom_post_info_text_transform",$blog_slider_post_info_in_bottom_post_info_text_transform);

$blog_slider_post_info_in_bottom_post_info_font_family = new ElatedMooseField("fontsimple","blog_slider_post_info_in_bottom_post_info_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_slider_post_info_in_bottom_post_info_font_family",$blog_slider_post_info_in_bottom_post_info_font_family);

$blog_slider_post_info_in_bottom_post_info_font_style = new ElatedMooseField("selectblanksimple","blog_slider_post_info_in_bottom_post_info_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_slider_post_info_in_bottom_post_info_font_style",$blog_slider_post_info_in_bottom_post_info_font_style);

$row3 = new ElatedMooseRow();
$group27->addChild("row3",$row3);

$blog_slider_post_info_in_bottom_post_info_font_weight = new ElatedMooseField("selectblanksimple","blog_slider_post_info_in_bottom_post_info_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row3->addChild("blog_slider_post_info_in_bottom_post_info_font_weight",$blog_slider_post_info_in_bottom_post_info_font_weight);

$blog_slider_post_info_in_bottom_post_info_letter_spacing = new ElatedMooseField("textsimple","blog_slider_post_info_in_bottom_post_info_letter_spacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_slider_post_info_in_bottom_post_info_letter_spacing",$blog_slider_post_info_in_bottom_post_info_letter_spacing);

/*** Blog Slider ***/

$panel32 = new ElatedMoosePanel("Blog Slider","blog_slider_simple_simple");
$blogPage->addChild("panel32",$panel32);

$blog_slider_simple_simple_box = new ElatedMooseTitle("blog_slider_simple_simple_box","Box Style");
$panel32->addChild("blog_slider_simple_simple_box",$blog_slider_simple_simple_box);

$blog_slider_simple_box_back_color = new ElatedMooseField("color","blog_slider_simple_box_back_color","","Background Color","Choose background color",array(), array("col_width" => 3));
$panel32->addChild("blog_slider_simple_box_back_color",$blog_slider_simple_box_back_color);

$blog_slider_simple_box_opacity = new ElatedMooseField("text","blog_slider_simple_box_opacity","","Background Opacity","Choose a transparency for the shader background color (0 = fully transparent, 1 = opaque)",array(), array("col_width" => 3));
$panel32->addChild("blog_slider_simple_box_opacity",$blog_slider_simple_box_opacity);

$blog_slider_simple_box_padding = new ElatedMooseField("text","blog_slider_simple_box_padding","","Box Padding","Please insert padding in format (top right bottom left) i.e. 5px 5px 5px 5px or 5% 5% 5% 5%", array(), array("col_width" => 3));
$panel32->addChild("blog_slider_simple_box_padding",$blog_slider_simple_box_padding);

$blog_slider_simple_box_border_color = new ElatedMooseField("color","blog_slider_simple_box_border_color","","Box Border Color","Choose border color", array(), array("col_width" => 3));
$panel32->addChild("blog_slider_simple_box_border_color",$blog_slider_simple_box_border_color);

$blog_slider_simple_simple_spacing = new ElatedMooseTitle("blog_slider_simple_simple_spacing","Blog simple slider spacing");
$panel32->addChild("blog_slider_simple_simple_spacing",$blog_slider_simple_simple_spacing);

$blog_slider_simple_info_margin_top = new ElatedMooseField("text","blog_slider_simple_info_margin_top","","Post Info Margin Top (px)","Define post info margin top", array(), array("col_width" => 3));
$panel32->addChild("blog_slider_simple_info_margin_top",$blog_slider_simple_info_margin_top);

$blog_slider_simple_read_more_margin_top = new ElatedMooseField("text","blog_slider_simple_read_more_margin_top","","Read More Margin Top (px)","Define read more margin top", array(), array("col_width" => 3));
$panel32->addChild("blog_slider_simple_read_more_margin_top",$blog_slider_simple_read_more_margin_top);

$blog_slider_simple_simple_text = new ElatedMooseTitle("blog_slider_simple_simple_text","Post Text Style");
$panel32->addChild("blog_slider_simple_simple_text",$blog_slider_simple_simple_text);

$group_title = new ElatedMooseGroup("Title style", "Blog slider title style");
$panel32->addChild("group_title",$group_title);

$row1 = new ElatedMooseRow();
$group_title->addChild("row1",$row1);

$blog_slider_simple_title_color = new ElatedMooseField("colorsimple","blog_slider_simple_title_color","","Title Color","This is some description");
$row1->addChild("blog_slider_simple_title_color",$blog_slider_simple_title_color);

$blog_slider_simple_title_hover_color = new ElatedMooseField("colorsimple","blog_slider_simple_title_hover_color","","Title Hover Color","This is some description");
$row1->addChild("blog_slider_simple_title_hover_color",$blog_slider_simple_title_hover_color);

$blog_slider_simple_title_font_size = new ElatedMooseField("textsimple","blog_slider_simple_title_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_slider_simple_title_font_size",$blog_slider_simple_title_font_size);

$blog_slider_simple_title_line_height = new ElatedMooseField("textsimple","blog_slider_simple_title_line_height","","Line Height (px)","This is some description");
$row1->addChild("blog_slider_simple_title_line_height",$blog_slider_simple_title_line_height);

$row2 = new ElatedMooseRow();
$group_title->addChild("row2",$row2);

$blog_slider_simple_title_text_transform = new ElatedMooseField("selectblanksimple","blog_slider_simple_title_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_slider_simple_title_text_transform",$blog_slider_simple_title_text_transform);

$blog_slider_simple_title_font_family = new ElatedMooseField("fontsimple","blog_slider_simple_title_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_slider_simple_title_font_family",$blog_slider_simple_title_font_family);

$blog_slider_simple_title_font_style = new ElatedMooseField("selectblanksimple","blog_slider_simple_title_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_slider_simple_title_font_style",$blog_slider_simple_title_font_style);

$blog_slider_simple_title_font_weight = new ElatedMooseField("selectblanksimple","blog_slider_simple_title_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row2->addChild("blog_slider_simple_title_font_weight",$blog_slider_simple_title_font_weight);


$row3 = new ElatedMooseRow();
$group_title->addChild("row3",$row3);

$blog_slider_simple_title_letter_spacing = new ElatedMooseField("textsimple","blog_slider_simple_title_letter_spacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_slider_simple_title_letter_spacing",$blog_slider_simple_title_letter_spacing);

$group_post_info = new ElatedMooseGroup("Post Info Style", "Blog slider post info style");
$panel32->addChild("group_post_info",$group_post_info);

$row1 = new ElatedMooseRow();
$group_post_info->addChild("row1",$row1);

$blog_slider_simple_info_color = new ElatedMooseField("colorsimple","blog_slider_simple_info_color","","Color","This is some description");
$row1->addChild("blog_slider_simple_info_color",$blog_slider_simple_info_color);

$blog_slider_simple_info_link_color = new ElatedMooseField("colorsimple","blog_slider_simple_info_link_color","","Link Color","This is some description");
$row1->addChild("blog_slider_simple_info_link_color",$blog_slider_simple_info_link_color);

$blog_slider_simple_info_hover_color = new ElatedMooseField("colorsimple","blog_slider_simple_info_hover_color","","Link Hover Color","This is some description");
$row1->addChild("blog_slider_simple_info_hover_color",$blog_slider_simple_info_hover_color);

$blog_slider_simple_info_font_size = new ElatedMooseField("textsimple","blog_slider_simple_info_font_size","","Font Size (px)","This is some description");
$row1->addChild("blog_slider_simple_info_font_size",$blog_slider_simple_info_font_size);

$row2 = new ElatedMooseRow();
$group_post_info->addChild("row2",$row2);

$blog_slider_simple_info_line_height = new ElatedMooseField("textsimple","blog_slider_simple_info_line_height","","Line Height (px)","This is some description");
$row2->addChild("blog_slider_simple_info_line_height",$blog_slider_simple_info_line_height);

$blog_slider_simple_info_text_transform = new ElatedMooseField("selectblanksimple","blog_slider_simple_info_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
$row2->addChild("blog_slider_simple_info_text_transform",$blog_slider_simple_info_text_transform);

$blog_slider_simple_info_font_family = new ElatedMooseField("fontsimple","blog_slider_simple_info_font_family","-1","Font Family","This is some description");
$row2->addChild("blog_slider_simple_info_font_family",$blog_slider_simple_info_font_family);

$blog_slider_simple_info_font_style = new ElatedMooseField("selectblanksimple","blog_slider_simple_info_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
$row2->addChild("blog_slider_simple_info_font_style",$blog_slider_simple_info_font_style);

$row3 = new ElatedMooseRow();
$group_post_info->addChild("row3",$row3);

$blog_slider_simple_info_font_weight = new ElatedMooseField("selectblanksimple","blog_slider_simple_info_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
$row3->addChild("blog_slider_simple_info_font_weight",$blog_slider_simple_info_font_weight);

$blog_slider_simple_info_letter_spacing = new ElatedMooseField("textsimple","blog_slider_simple_info_letter_spacing","","Letter Spacing (px)","This is some description");
$row3->addChild("blog_slider_simple_info_letter_spacing",$blog_slider_simple_info_letter_spacing);