<?php

$footerPage = new ElatedMooseAdminPage("3", "Footer", "fa fa-sort-amount-asc");
$eltdFramework->eltdOptions->addAdminPage("footer",$footerPage);

        $panel10 = new ElatedMoosePanel("Footer","footer_panel");
        $footerPage->addChild("panel10",$panel10);

                $uncovering_footer = new ElatedMooseField("yesno","uncovering_footer","no","Uncovering Footer","Enabling this option will make Footer gradually appear on scroll");
                $panel10->addChild("uncovering_footer",$uncovering_footer);

                $footer_in_grid = new ElatedMooseField("yesno","footer_in_grid","yes","Footer in Grid","Enabling this option will place Footer content in grid",array(),array(
                    "dependence" => true,
                    "dependence_hide_on_yes" => "",
                    "dependence_show_on_yes" => "#eltdf_footer_grid_background_container"
                    ));
                $panel10->addChild("footer_in_grid",$footer_in_grid);

                $footer_main_image_background = new ElatedMooseField("image","footer_main_image_background","","Footer Background Image","Choose footer background image");
                $panel10->addChild("footer_main_image_background",$footer_main_image_background);

                $show_footer_top = new ElatedMooseField("yesno","show_footer_top","yes","Show Footer Top","Enabling this option will show Footer Top area", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_show_footer_top_container"));
                $panel10->addChild("show_footer_top",$show_footer_top);

                $show_footer_top_container = new ElatedMooseContainer("show_footer_top_container","show_footer_top","no");
                $panel10->addChild("show_footer_top_container",$show_footer_top_container);

                        $footer_top_columns_alignment = new ElatedMooseField("select","footer_top_columns_alignment","","Footer Top Columns Alignment","Text Alignment in Footer Columns", array(
                            "left" => "Left",
                            "center" => "Center",
                            "right" => "Right"
                        ));
                        $show_footer_top_container->addChild("footer_top_columns_alignment",$footer_top_columns_alignment);

                $footer_top_columns = new ElatedMooseField("select","footer_top_columns","4","Footer Top Columns","Choose number of columns for Footer Top area", array(
                        "1" => "1",
                        "2" => "2",
                        "3" => "3",
                        "5" => "3(25%+25%+50%)",
                        "6" => "3(50%+25%+25%)",
                        "4" => "4"
                    ),
                    array("dependence" => true,
                        "hide" => array(
                            "1"=>"#eltdf_footer_top_column2_alignment_container,#eltdf_footer_top_column3_alignment_container,#eltdf_footer_top_column4_alignment_container",
                            "2"=>"#eltdf_footer_top_column3_alignment_container,#eltdf_footer_top_column4_alignment_container",
                            "3"=>"#eltdf_footer_top_column4_alignment_container",
                            "4"=>"",
                            "5"=>"#eltdf_footer_top_column4_alignment_container",
                            "6"=>"#eltdf_footer_top_column4_alignment_container"),
                        "show" => array(
                            "1"=>"#eltdf_footer_top_column1_alignment_container",
                            "2"=>"#eltdf_footer_top_column1_alignment_container,#eltdf_footer_top_column2_alignment_container",
                            "3"=>"#eltdf_footer_top_column1_alignment_container,#eltdf_footer_top_column2_alignment_container,#eltdf_footer_top_column3_alignment_container",
                            "4"=>"#eltdf_footer_top_column1_alignment_container,#eltdf_footer_top_column2_alignment_container,#eltdf_footer_top_column3_alignment_container,#eltdf_footer_top_column4_alignment_container",
                            "5"=>"#eltdf_footer_top_column1_alignment_container,#eltdf_footer_top_column2_alignment_container,#eltdf_footer_top_column3_alignment_container",
                            "6"=>"#eltdf_footer_top_column1_alignment_container,#eltdf_footer_top_column2_alignment_container,#eltdf_footer_top_column3_alignment_container",
                        )
                    ));
                $show_footer_top_container->addChild("footer_top_columns",$footer_top_columns);

                        $footer_top_column1_alignment_container = new ElatedMooseContainer("footer_top_column1_alignment_container","footer_top_columns","");
                        $show_footer_top_container->addChild("footer_top_column1_alignment_container",$footer_top_column1_alignment_container);

                                $footer_top_column1_alignment = new ElatedMooseField("select","footer_top_column1_alignment","","Footer Top First Column Alignment","This option will overwrite 'Footer Top Columns Alignment'", array(
                                    "" => "Default",
                                    "left" => "Left",
                                    "center" => "Center",
                                    "right" => "Right"
                                ), array("col_width" => 3));
                                $footer_top_column1_alignment_container->addChild("footer_top_column1_alignment",$footer_top_column1_alignment);

                        $footer_top_column2_alignment_container = new ElatedMooseContainer("footer_top_column2_alignment_container","footer_top_columns","1");
                        $show_footer_top_container->addChild("footer_top_column2_alignment_container",$footer_top_column2_alignment_container);

                                $footer_top_column2_alignment = new ElatedMooseField("select","footer_top_column2_alignment","","Footer Top Second Column Alignment","This option will overwrite 'Footer Top Columns Alignment'", array(
                                    "" => "Default",
                                    "left" => "Left",
                                    "center" => "Center",
                                    "right" => "Right"
                                ), array("col_width" => 3));
                                $footer_top_column2_alignment_container->addChild("footer_top_column2_alignment",$footer_top_column2_alignment);

                        $footer_top_column3_alignment_container = new ElatedMooseContainer("footer_top_column3_alignment_container","footer_top_columns","1",array("1","2"));
                        $show_footer_top_container->addChild("footer_top_column3_alignment_container",$footer_top_column3_alignment_container);

                                $footer_top_column3_alignment = new ElatedMooseField("select","footer_top_column3_alignment","","Footer Top Third Column Alignment","This option will overwrite 'Footer Top Columns Alignment'", array(
                                    "" => "Default",
                                    "left" => "Left",
                                    "center" => "Center",
                                    "right" => "Right"
                                ), array("col_width" => 3));
                                $footer_top_column3_alignment_container->addChild("footer_top_column3_alignment",$footer_top_column3_alignment);

                        $footer_top_column4_alignment_container = new ElatedMooseContainer("footer_top_column4_alignment_container","footer_top_columns","1",array("1","2","3","5","6"));
                        $show_footer_top_container->addChild("footer_top_column4_alignment_container",$footer_top_column4_alignment_container);

                                $footer_top_column4_alignment = new ElatedMooseField("select","footer_top_column4_alignment","","Footer Top Fourth Column Alignment","This option will overwrite 'Footer Top Columns Alignment'", array(
                                    "" => "Default",
                                    "left" => "Left",
                                    "center" => "Center",
                                    "right" => "Right"
                                ), array("col_width" => 3));
                                $footer_top_column4_alignment_container->addChild("footer_top_column4_alignment",$footer_top_column4_alignment);

                        $footer_border_columns = new ElatedMooseField("yesno","footer_border_columns","yes","Border Between Columns","Disabling this option will remove border between footer columns.", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_footer_border_columns_holder"));
                        $show_footer_top_container->addChild("footer_border_columns",$footer_border_columns);

                                $footer_border_columns_holder = new ElatedMooseContainer("footer_border_columns_holder","footer_border_columns","no");
                                $show_footer_top_container->addChild("footer_border_columns_holder",$footer_border_columns_holder);

                                        $footer_border_columns_color = new ElatedMooseField("color","footer_border_columns_color","","Border Color Between Columns","Choose a color for border in footer columns.");
                                        $footer_border_columns_holder->addChild("footer_border_columns_color",$footer_border_columns_color);

                        $footer_bottom_border_element = new ElatedMooseField("yesno","footer_bottom_border_element","yes","Border Bottom on Elements","Enabling this option will add border bottom on footer elements.", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_footer_bottom_border_element_holder"));
                        $show_footer_top_container->addChild("footer_bottom_border_element",$footer_bottom_border_element);

                                $footer_bottom_border_element_holder = new ElatedMooseContainer("footer_bottom_border_element_holder","footer_bottom_border_element","no");
                                $show_footer_top_container->addChild("footer_bottom_border_element_holder",$footer_bottom_border_element_holder);

                                        $footer_bottom_border_element_color = new ElatedMooseField("color","footer_bottom_border_element_color","","Border Bottom Color","Choose a color for border in footer columns.");
                                        $footer_bottom_border_element_holder->addChild("footer_bottom_border_element_color",$footer_bottom_border_element_color);

                $group1 = new ElatedMooseGroup("Footer Top Area Style","Configure style for Footer Top area");
                $show_footer_top_container->addChild("group1",$group1);

                        $row1 = new ElatedMooseRow();
                        $group1->addChild("row1",$row1);
                                $footer_top_background_color = new ElatedMooseField("colorsimple","footer_top_background_color","","Background Color","This is some description");
                                $row1->addChild("footer_top_background_color",$footer_top_background_color);

                                $footer_top_border_color = new ElatedMooseField("colorsimple","footer_top_border_color","","Top Border Color","This is some description");
                                $row1->addChild("footer_top_border_color",$footer_top_border_color);

                                $footer_top_border_width = new ElatedMooseField("textsimple","footer_top_border_width","","Top Border Width (px)","This is some description");
                                $row1->addChild("footer_top_border_width",$footer_top_border_width);

                                $footer_top_border_in_grid = new ElatedMooseField("yesnosimple","footer_top_border_in_grid","no","Set Top Border In Grid","");
                                $row1->addChild("footer_top_border_in_grid",$footer_top_border_in_grid);

                        $row2 = new ElatedMooseRow(true);
                        $group1->addChild("row2",$row2);

                                $footer_top_padding = new ElatedMooseField("textsimple","footer_top_padding","","Top Padding (px)","This is some description");
                                $row2->addChild("footer_top_padding",$footer_top_padding);

                                $footer_bottom_padding = new ElatedMooseField("textsimple","footer_bottom_padding","","Bottom Padding (px)","This is some description");
                                $row2->addChild("footer_bottom_padding",$footer_bottom_padding);

                                $footer_left_padding = new ElatedMooseField("textsimple","footer_left_padding","","Left Padding (px)","This is some description");
                                $row2->addChild("footer_left_padding",$footer_left_padding);

                                $footer_right_padding = new ElatedMooseField("textsimple","footer_right_padding","","Right Padding (px)","This is some description");
                                $row2->addChild("footer_right_padding",$footer_right_padding);

                $footer_grid_background_container = new ElatedMooseContainer("footer_grid_background_container","footer_in_grid","no");
                $show_footer_top_container->addChild("footer_grid_background_container",$footer_grid_background_container);

                        $footer_top_background_color_in_grid = new ElatedMooseField("color","footer_top_background_color_in_grid","","Grid Background Color","Choose background color for grid on footer top");
                        $footer_grid_background_container->addChild("footer_top_background_color_in_grid",$footer_top_background_color_in_grid);

                $footer_image_background = new ElatedMooseField("image","footer_image_background","","Footer Top Background Image","Choose footer top background image");
                $show_footer_top_container->addChild("footer_image_background",$footer_image_background);

				$group2 = new ElatedMooseGroup("Footer Top Title Style","Configure style for Footer Top Title");
                $show_footer_top_container->addChild("group2",$group2);

                        $row1 = new ElatedMooseRow();
                        $group2->addChild("row1",$row1);

                                $footer_title_color = new ElatedMooseField("colorsimple","footer_title_color","","Text Color","This is some description");
                                $row1->addChild("footer_title_color",$footer_title_color);

                                $footer_title_font_size = new ElatedMooseField("textsimple","footer_title_font_size","","Font Size (px)","This is some description");
                                $row1->addChild("footer_title_font_size",$footer_title_font_size);

                                $footer_title_line_height = new ElatedMooseField("textsimple","footer_title_line_height","","Line Height (px)","This is some description");
                                $row1->addChild("footer_title_line_height",$footer_title_line_height);

                                $footer_title_text_transform = new ElatedMooseField("selectblanksimple","footer_title_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
                                $row1->addChild("footer_title_text_transform",$footer_title_text_transform);

                        $row2 = new ElatedMooseRow(true);
                        $group2->addChild("row2",$row2);
                                $footer_title_font_family = new ElatedMooseField("fontsimple","footer_title_font_family","-1","Font Family","This is some description");
                                $row2->addChild("footer_title_font_family",$footer_title_font_family);

                                $footer_title_font_style = new ElatedMooseField("selectblanksimple","footer_title_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
                                $row2->addChild("footer_title_font_style",$footer_title_font_style);

                                $footer_title_font_weight = new ElatedMooseField("selectblanksimple","footer_title_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
                                $row2->addChild("footer_title_font_weight",$footer_title_font_weight);

                                $footer_title_letter_spacing = new ElatedMooseField("textsimple","footer_title_letter_spacing","","Letter Spacing (px)","This is some description");
                                $row2->addChild("footer_title_letter_spacing",$footer_title_letter_spacing);

                $group3 = new ElatedMooseGroup("Footer Top Text Style","Configure style for Footer Top text");
                $show_footer_top_container->addChild("group3",$group3);

                        $row1 = new ElatedMooseRow();
                        $group3->addChild("row1",$row1);
                                $footer_top_text_color = new ElatedMooseField("colorsimple","footer_top_text_color","","Text Color","This is some description");
                                $row1->addChild("footer_top_text_color",$footer_top_text_color);

                                $footer_top_text_font_size = new ElatedMooseField("textsimple","footer_top_text_font_size","","Font Size (px)","This is some description");
                                $row1->addChild("footer_top_text_font_size",$footer_top_text_font_size);

                                $footer_top_text_line_height = new ElatedMooseField("textsimple","footer_top_text_line_height","","Line Height (px)","This is some description");
                                $row1->addChild("footer_top_text_line_height",$footer_top_text_line_height);

                                $footer_top_text_text_transform = new ElatedMooseField("selectblanksimple","footer_top_text_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
                                $row1->addChild("footer_top_text_text_transform",$footer_top_text_text_transform);

                        $row2 = new ElatedMooseRow(true);
                        $group3->addChild("row2",$row2);
                                $footer_top_text_font_family = new ElatedMooseField("fontsimple","footer_top_text_font_family","-1","Font Family","This is some description");
                                $row2->addChild("footer_top_text_font_family",$footer_top_text_font_family);

                                $footer_top_text_font_style = new ElatedMooseField("selectblanksimple","footer_top_text_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
                                $row2->addChild("footer_top_text_font_style",$footer_top_text_font_style);

                                $footer_top_text_font_weight = new ElatedMooseField("selectblanksimple","footer_top_text_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
                                $row2->addChild("footer_top_text_font_weight",$footer_top_text_font_weight);

                                $footer_top_text_letter_spacing = new ElatedMooseField("textsimple","footer_top_text_letter_spacing","","Letter Spacing (px)","This is some description");
                                $row2->addChild("footer_top_text_letter_spacing",$footer_top_text_letter_spacing);

                $group4 = new ElatedMooseGroup("Footer Top Link Style","Configure style for Footer Top link");
                $show_footer_top_container->addChild("group4",$group4);

                        $row1 = new ElatedMooseRow();
                        $group4->addChild("row1",$row1);
                                $footer_top_link_color = new ElatedMooseField("colorsimple","footer_top_link_color","","Text Color","This is some description");
                                $row1->addChild("footer_top_link_color",$footer_top_link_color);

                                $footer_top_link_font_size = new ElatedMooseField("textsimple","footer_top_link_font_size","","Font Size (px)","This is some description");
                                $row1->addChild("footer_top_link_font_size",$footer_top_link_font_size);

                                $footer_top_link_line_height = new ElatedMooseField("textsimple","footer_top_link_line_height","","Line Height (px)","This is some description");
                                $row1->addChild("footer_top_link_line_height",$footer_top_link_line_height);

                                $footer_top_link_text_transform = new ElatedMooseField("selectblanksimple","footer_top_link_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
                                $row1->addChild("footer_top_link_text_transform",$footer_top_link_text_transform);

                        $row2 = new ElatedMooseRow(true);
                        $group4->addChild("row2",$row2);
                                $footer_top_link_font_family = new ElatedMooseField("fontsimple","footer_top_link_font_family","-1","Font Family","This is some description");
                                $row2->addChild("footer_top_link_font_family",$footer_top_link_font_family);

                                $footer_top_link_font_style = new ElatedMooseField("selectblanksimple","footer_top_link_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
                                $row2->addChild("footer_top_link_font_style",$footer_top_link_font_style);

                                $footer_top_link_font_weight = new ElatedMooseField("selectblanksimple","footer_top_link_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
                                $row2->addChild("footer_top_link_font_weight",$footer_top_link_font_weight);

                                $footer_top_link_letter_spacing = new ElatedMooseField("textsimple","footer_top_link_letter_spacing","","Letter Spacing (px)","This is some description");
                                $row2->addChild("footer_top_link_letter_spacing",$footer_top_link_letter_spacing);

                        $row3 = new ElatedMooseRow(true);
                        $group4->addChild("row3",$row3);
                                $footer_top_link_hover_color = new ElatedMooseField("colorsimple","footer_top_link_hover_color","","Hover Text Color","This is some description");
                                $row3->addChild("footer_top_link_hover_color",$footer_top_link_hover_color);


        $footer_text = new ElatedMooseField("yesno","footer_text","yes","Show Footer Bottom","Enabling this option will show Footer Bottom area", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#eltdf_footer_text_container"));
        $panel10->addChild("footer_text",$footer_text);

        $footer_text_container = new ElatedMooseContainer("footer_text_container","footer_text","no");
        $panel10->addChild("footer_text_container",$footer_text_container);

                $footer_bottom_columns = new ElatedMooseField("select","footer_bottom_columns","3","Footer Bottom Columns","Choose number of columns for Footer Bottom area", array(
                    "1" => "1",
                    "2" => "2",
                    "3" => "3"
                ));
                $footer_text_container->addChild("footer_bottom_columns",$footer_bottom_columns);

                $group5 = new ElatedMooseGroup("Footer Bottom Area Style","Configure style for Footer Bottom area");
                $footer_text_container->addChild("group5",$group5);

                        $row1 = new ElatedMooseRow();
                        $group5->addChild("row1",$row1);
                                $footer_bottom_height = new ElatedMooseField("textsimple","footer_bottom_height","","Height (px)","This is some description");
                                $row1->addChild("footer_bottom_height",$footer_bottom_height);
                                $footer_bottom_background_color = new ElatedMooseField("colorsimple","footer_bottom_background_color","","Background Color","This is some description");
                                $row1->addChild("footer_bottom_background_color",$footer_bottom_background_color);

                                $footer_bottom_border_in_grid = new ElatedMooseField("yesnosimple","footer_bottom_border_in_grid","no","Set Top Border In Grid","");
                                $row1->addChild("footer_bottom_border_in_grid",$footer_bottom_border_in_grid);

                        $row2 = new ElatedMooseRow(true);
                        $group5->addChild("row2",$row2);

                                $footer_bottom_border_color = new ElatedMooseField("colorsimple","footer_bottom_border_color","","Top Border Color","This is some description");
                                $row2->addChild("footer_bottom_border_color",$footer_bottom_border_color);
                                $footer_bottom_border_width = new ElatedMooseField("textsimple","footer_bottom_border_width","","Top Border Width (px)","This is some description");
                                $row2->addChild("footer_bottom_border_width",$footer_bottom_border_width);
                                $footer_bottom_border_bottom_color = new ElatedMooseField("colorsimple","footer_bottom_border_bottom_color","","Bottom Border Color","This is some description");
                                $row2->addChild("footer_bottom_border_bottom_color",$footer_bottom_border_bottom_color);
                                $footer_bottom_border_bottom_width = new ElatedMooseField("textsimple","footer_bottom_border_bottom_width","","Bottom Border Width (px)","This is some description");
                                $row2->addChild("footer_bottom_border_bottom_width",$footer_bottom_border_bottom_width);

                        $row3 = new ElatedMooseRow(true);
                        $group5->addChild("row3",$row3);

                                $footer_bottom_top_padding = new ElatedMooseField("textsimple","footer_bottom_top_padding","","Top Padding (px)","This is some description");
                                $row3->addChild("footer_bottom_top_padding",$footer_bottom_top_padding);
                                $footer_bottom_bottom_padding = new ElatedMooseField("textsimple","footer_bottom_bottom_padding","","Bottom Padding (px)","This is some description");
                                $row3->addChild("footer_bottom_bottom_padding",$footer_bottom_bottom_padding);
                                $footer_bottom_left_padding = new ElatedMooseField("textsimple","footer_bottom_left_padding","","Left Padding (px)","This is some description");
                                $row3->addChild("footer_bottom_left_padding",$footer_bottom_left_padding);
                                $footer_bottom_right_padding = new ElatedMooseField("textsimple","footer_bottom_right_padding","","Right Padding (px)","This is some description");
                                $row3->addChild("footer_bottom_right_padding",$footer_bottom_right_padding);

                    $footer_bottom_image_background = new ElatedMooseField("image","footer_bottom_image_background","","Footer Bottom Background Image","Choose footer bottom background image");
                    $footer_text_container->addChild("footer_bottom_image_background",$footer_bottom_image_background);


                $group6 = new ElatedMooseGroup("Footer Bottom Text Style","Configure style for Footer Bottom text");
                $footer_text_container->addChild("group6",$group6);

                        $row1 = new ElatedMooseRow();
                        $group6->addChild("row1",$row1);

                                $footer_bottom_text_color = new ElatedMooseField("colorsimple","footer_bottom_text_color","","Text Color","This is some description");
                                $row1->addChild("footer_bottom_text_color",$footer_bottom_text_color);

                                $footer_bottom_text_font_size = new ElatedMooseField("textsimple","footer_bottom_text_font_size","","Font Size (px)","This is some description");
                                $row1->addChild("footer_bottom_text_font_size",$footer_bottom_text_font_size);

                                $footer_bottom_text_line_height = new ElatedMooseField("textsimple","footer_bottom_text_line_height","","Line Height (px)","This is some description");
                                $row1->addChild("footer_bottom_text_line_height",$footer_bottom_text_line_height);

                                $footer_bottom_text_text_transform = new ElatedMooseField("selectblanksimple","footer_bottom_text_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
                                $row1->addChild("footer_bottom_text_text_transform",$footer_bottom_text_text_transform);

                        $row2 = new ElatedMooseRow(true);
                        $group6->addChild("row2",$row2);

                                $footer_bottom_text_font_family = new ElatedMooseField("fontsimple","footer_bottom_text_font_family","-1","Font Family","This is some description");
                                $row2->addChild("footer_bottom_text_font_family",$footer_bottom_text_font_family);

                                $footer_bottom_text_font_style = new ElatedMooseField("selectblanksimple","footer_bottom_text_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
                                $row2->addChild("footer_bottom_text_font_style",$footer_bottom_text_font_style);

                                $footer_bottom_text_font_weight = new ElatedMooseField("selectblanksimple","footer_bottom_text_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
                                $row2->addChild("footer_bottom_text_font_weight",$footer_bottom_text_font_weight);

                                $footer_bottom_text_letter_spacing = new ElatedMooseField("textsimple","footer_bottom_text_letter_spacing","","Letter Spacing (px)","This is some description");
                                $row2->addChild("footer_bottom_text_letter_spacing",$footer_bottom_text_letter_spacing);

                $group7 = new ElatedMooseGroup("Footer Bottom Link Style","Configure style for Footer Bottom link");
                $footer_text_container->addChild("group7",$group7);

                        $row1 = new ElatedMooseRow();
                        $group7->addChild("row1",$row1);

                                $footer_bottom_link_color = new ElatedMooseField("colorsimple","footer_bottom_link_color","","Text Color","This is some description");
                                $row1->addChild("footer_bottom_link_color",$footer_bottom_link_color);

                                $footer_bottom_link_font_size = new ElatedMooseField("textsimple","footer_bottom_link_font_size","","Font Size (px)","This is some description");
                                $row1->addChild("footer_bottom_link_font_size",$footer_bottom_link_font_size);

                                $footer_bottom_link_line_height = new ElatedMooseField("textsimple","footer_bottom_link_line_height","","Line Height (px)","This is some description");
                                $row1->addChild("footer_bottom_link_line_height",$footer_bottom_link_line_height);

                                $footer_bottom_link_text_transform = new ElatedMooseField("selectblanksimple","footer_bottom_link_text_transform","","Text Transform","This is some description",$eltd_moose_options_texttransform);
                                $row1->addChild("footer_bottom_link_text_transform",$footer_bottom_link_text_transform);

                        $row2 = new ElatedMooseRow(true);
                        $group7->addChild("row2",$row2);

                                $footer_bottom_link_font_family = new ElatedMooseField("fontsimple","footer_bottom_link_font_family","-1","Font Family","This is some description");
                                $row2->addChild("footer_bottom_link_font_family",$footer_bottom_link_font_family);

                                $footer_bottom_link_font_style = new ElatedMooseField("selectblanksimple","footer_bottom_link_font_style","","Font Style","This is some description",$eltd_moose_options_fontstyle);
                                $row2->addChild("footer_bottom_link_font_style",$footer_bottom_link_font_style);

                                $footer_bottom_link_font_weight = new ElatedMooseField("selectblanksimple","footer_bottom_link_font_weight","","Font Weight","This is some description",$eltd_moose_options_fontweight);
                                $row2->addChild("footer_bottom_link_font_weight",$footer_bottom_link_font_weight);

                                $footer_bottom_link_letter_spacing = new ElatedMooseField("textsimple","footer_bottom_link_letter_spacing","","Letter Spacing (px)","This is some description");
                                $row2->addChild("footer_bottom_link_letter_spacing",$footer_bottom_link_letter_spacing);

                        $row3 = new ElatedMooseRow(true);
                        $group7->addChild("row3",$row3);

                                $footer_bottom_link_hover_color = new ElatedMooseField("colorsimple","footer_bottom_link_hover_color","","Hover Text Color","This is some description");
                                $row3->addChild("footer_bottom_link_hover_color",$footer_bottom_link_hover_color);

				$footer_bottom_menu_separator = new ElatedMooseField("yesno","footer_bottom_menu_separator","no","Enable Separator Between Menu Items","Enable this option to show separator between menu items in footer bottom",array(),array(
					"dependence" => true,
					"dependence_hide_on_yes" => "",
					"dependence_show_on_yes" => "#eltdf_footer_bottom_menu_separator_container"
					));
				$footer_text_container->addChild("footer_bottom_menu_separator",$footer_bottom_menu_separator);

				$footer_bottom_menu_separator_container = new ElatedMooseContainer("footer_bottom_menu_separator_container","footer_bottom_menu_separator","no");
				$footer_text_container->addChild("footer_bottom_menu_separator_container",$footer_bottom_menu_separator_container);

					$footer_bottom_menu_separator_color = new ElatedMooseField("color","footer_bottom_menu_separator_color","","Separator Color","Choose color for separator between menu items");
					$footer_bottom_menu_separator_container->addChild("footer_bottom_menu_separator_color",$footer_bottom_menu_separator_color);