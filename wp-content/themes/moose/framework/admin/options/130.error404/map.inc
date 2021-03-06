<?php

$error404Page = new ElatedMooseAdminPage("13", "404 Error Page", "fa fa-exclamation-triangle");
$eltdFramework->eltdOptions->addAdminPage("error404Page",$error404Page);

//404 Page Options

$panel1 = new ElatedMoosePanel("404 Page Options","page_error_options_panel");
$error404Page->addChild("panel1",$panel1);

	$title_404 = new ElatedMooseField("text","404_title","","Title","Enter title for 404 page");
	$panel1->addChild("404_title",$title_404);

	$group1 = new ElatedMooseGroup("Title Style","Define title styles.");
	$panel1->addChild("group1",$group1);
		$row1 = new ElatedMooseRow();
		$group1->addChild("row1",$row1);
			$title_404_color = new ElatedMooseField("colorsimple","404_title_color","","Text Color","This is some description");
			$row1->addChild("404_title_color",$title_404_color);

			$title_404_font_size = new ElatedMooseField("textsimple","404_title_font_size","","Font Size (px)","This is some description");
			$row1->addChild("404_title_font_size",$title_404_font_size);

			$title_404_line_height = new ElatedMooseField("textsimple","404_title_line_height","","Line Height (px)","This is some description");
			$row1->addChild("404_title_line_height",$title_404_line_height);

			$title_404_text_transform = new ElatedMooseField("selectblanksimple","404_title_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
			$row1->addChild("404_title_text_transform",$title_404_text_transform);

		$row2 = new ElatedMooseRow(true);
		$group1->addChild("row2",$row2);
			$title_404_font_family = new ElatedMooseField("fontsimple","404_title_font_family","-1","Font Family","This is some description");
			$row2->addChild("404_title_font_family",$title_404_font_family);

			$title_404_font_style = new ElatedMooseField("selectblanksimple","404_title_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
			$row2->addChild("404_title_font_style",$title_404_font_style);

			$title_404_font_weight = new ElatedMooseField("selectblanksimple","404_title_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
			$row2->addChild("404_title_font_weight",$title_404_font_weight);

			$title_404_letter_spacing = new ElatedMooseField("textsimple","404_title_letter_spacing","","Letter Spacing (px)","This is some description");
			$row2->addChild("404_title_letter_spacing",$title_404_letter_spacing);


	$text_404 = new ElatedMooseField("text","404_text","","Text","Enter text for 404 page");
	$panel1->addChild("404_text",$text_404);

	$group2 = new ElatedMooseGroup("Text Style","Define text style");
	$panel1->addChild("group2",$group2);
		$row1 = new ElatedMooseRow();
		$group2->addChild("row1",$row1);
			$text_404_color = new ElatedMooseField("colorsimple","404_text_color","","Text Color","This is some description");
			$row1->addChild("404_text_color",$text_404_color);

			$text_404_font_size = new ElatedMooseField("textsimple","404_text_font_size","","Font Size (px)","This is some description");
			$row1->addChild("404_text_font_size",$text_404_font_size);

			$text_404_line_height = new ElatedMooseField("textsimple","404_text_line_height","","Line Height (px)","This is some description");
			$row1->addChild("404_title_line_height",$text_404_line_height);

			$text_404_text_transform = new ElatedMooseField("selectblanksimple","404_text_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
			$row1->addChild("404_text_text_transform",$text_404_text_transform);

		$row2 = new ElatedMooseRow(true);
		$group2->addChild("row2",$row2);
			$text_404_font_family = new ElatedMooseField("fontsimple","404_text_font_family","-1","Font Family","This is some description");
			$row2->addChild("404_text_font_family",$text_404_font_family);

			$text_404_font_style = new ElatedMooseField("selectblanksimple","404_text_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
			$row2->addChild("404_text_font_style",$text_404_font_style);

			$text_404_font_weight = new ElatedMooseField("selectblanksimple","404_text_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
			$row2->addChild("404_text_font_weight",$text_404_font_weight);

			$text_404_letter_spacing = new ElatedMooseField("textsimple","404_text_letter_spacing","","Letter Spacing (px)","This is some description");
			$row2->addChild("404_text_letter_spacing",$text_404_letter_spacing);


	
	$backlabel_404 = new ElatedMooseField("text","404_backlabel","","Back to Home Button Label",'Enter label for "Back to Home" button ');
	$panel1->addChild("404_backlabel",$backlabel_404);

