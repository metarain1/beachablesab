<?php

global $eltdIconCollections;
//Masonry Gallery Metaboxes

//General settings for text, buttons, links
$eltdMasonryGalleryItemGeneral = new ElatedMooseMetaBox("masonry_gallery", "Masonry Gallery General");
$eltdFramework->eltdMetaBoxes->addMetaBox("masonry_gallery_item_general",$eltdMasonryGalleryItemGeneral);

	$eltd_masonry_gallery_item_subtitle = new ElatedMooseMetaField('text', 'eltd_masonry_gallery_item_subtitle', '', 'Subtitle', '');
	$eltdMasonryGalleryItemGeneral->addChild('eltd_masonry_gallery_item_subtitle', $eltd_masonry_gallery_item_subtitle);

	$eltd_masonry_gallery_item_text = new ElatedMooseMetaField('text', 'eltd_masonry_gallery_item_text', '', 'Text', '');
	$eltdMasonryGalleryItemGeneral->addChild('eltd_masonry_gallery_item_text', $eltd_masonry_gallery_item_text);

	$eltd_masonry_gallery_item_link = new ElatedMooseMetaField('text', 'eltd_masonry_gallery_item_link', '', 'Link', '');
	$eltdMasonryGalleryItemGeneral->addChild('eltd_masonry_gallery_item_link', $eltd_masonry_gallery_item_link);

	$eltd_masonry_gallery_item_link_target = new ElatedMooseMetaField('select', 'eltd_masonry_gallery_item_link_target', '_self', 'Link target', '', array(
		'_self' => 'Self',
		'_blank' => 'Blank'
	));
	$eltdMasonryGalleryItemGeneral->addChild('eltd_masonry_gallery_item_link_target', $eltd_masonry_gallery_item_link_target);
	
	$eltd_masonry_item_parallax = new ElatedMooseMetaField("select","eltd_masonry_item_parallax","no","Set Item in Parallax","", array(
		"no" => "No",
		"yes" => "Yes"
	));
	$eltdMasonryGalleryItemGeneral->addChild("eltd_masonry_item_parallax",$eltd_masonry_item_parallax);

	$eltd_masonry_item_subtitle_separator = new ElatedMooseMetaField("select","eltd_masonry_item_subtitle_separator","no","Enable Separator Around Subtitle","", array(
		"no" => "No",
		"yes" => "Yes"
	));
	$eltdMasonryGalleryItemGeneral->addChild("eltd_masonry_item_subtitle_separator",$eltd_masonry_item_subtitle_separator);
	
	//Masonry Gallery Style - Size, Type
	$section_style_title = new ElatedMooseTitle('section_style_title', 'Masonry Gallery Item Style');
	$eltdMasonryGalleryItemGeneral->addChild('section_style_title', $section_style_title);

	$eltd_masonry_gallery_item_size = new ElatedMooseMetaField('select', 'eltd_masonry_gallery_item_size', 'square_small', 'Size', 'size', array(
		'square_small' => 'Square Small',
		'square_big' => 'Square Big',		
		'rectangle_portrait' => 'Rectangle Portrait',
		'rectangle_landscape' => 'Rectangle Landscape'
	));
	$eltdMasonryGalleryItemGeneral->addChild('eltd_masonry_gallery_item_size', $eltd_masonry_gallery_item_size);

	$eltd_masonry_gallery_item_type = new ElatedMooseMetaField('select', 'eltd_masonry_gallery_item_type', 'with_button', 'Type', 'type', array(
		'with_button' => 'With Button',
		'with_icon' => 'With Icon',
		'standard' => 'Standard'
	),
	array(
		'dependence' => true,
		'hide' => array(
			'with_button' => '',
			'with_icon' => '#eltdf_eltd_masonry_gallery_item_button_type_container',
			'standard' => '#eltdf_eltd_masonry_gallery_item_button_type_container, #eltdf_eltd_masonry_gallery_item_icon_type_container'
		),
		'show' => array(
			'with_button' => '#eltdf_eltd_masonry_gallery_item_button_type_container','#eltdf_eltd_masonry_gallery_item_icon_type_container',
			'with_icon' => '#eltdf_eltd_masonry_gallery_item_icon_type_container',
			'standard' => ''
		)
	));
	$eltdMasonryGalleryItemGeneral->addChild('eltd_masonry_gallery_item_type', $eltd_masonry_gallery_item_type);

	$eltd_masonry_gallery_item_button_type_container = new ElatedMooseContainer('eltd_masonry_gallery_item_button_type_container', 'eltd_masonry_gallery_item_type', '', array('standard', 'with_icon'));
	$eltdMasonryGalleryItemGeneral->addChild('eltd_masonry_gallery_item_button_type_container', $eltd_masonry_gallery_item_button_type_container);

		$eltd_masonry_gallery_button_label = new ElatedMooseMetaField('text', 'eltd_masonry_gallery_button_label', '', 'Button Label', '');
		$eltd_masonry_gallery_item_button_type_container->addChild('eltd_masonry_gallery_button_label', $eltd_masonry_gallery_button_label);

	$eltd_masonry_gallery_item_icon_type_container = new ElatedMooseContainer('eltd_masonry_gallery_item_icon_type_container', 'eltd_masonry_gallery_item_type', '', array('standard'));
	$eltdMasonryGalleryItemGeneral->addChild('eltd_masonry_gallery_item_icon_type_container', $eltd_masonry_gallery_item_icon_type_container);
	//Icon Packages
	$eltd_masonry_gallery_item_icon_hide_array = array();
	$eltd_masonry_gallery_item_icon_show_array = array();

	if(is_array($eltdIconCollections->iconCollections) && count($eltdIconCollections->iconCollections)) {

		$eltd_masonry_gallery_item_icon_collection_params = $eltdIconCollections->getIconCollectionsParams();

		foreach ($eltdIconCollections->iconCollections as $dep_collection_key => $dep_collection_object) {

			$eltd_masonry_gallery_item_icon_hide_array[$dep_collection_key] = '';

			$eltd_masonry_gallery_item_icon_show_array[$dep_collection_key] = '#eltdf_eltd_masonry_gallery_item_with_icon_'.$dep_collection_object->param.'_container';

			foreach ($eltd_masonry_gallery_item_icon_collection_params as $eltd_masonry_gallery_item_icon_collection_param) {

				if($eltd_masonry_gallery_item_icon_collection_param !== $dep_collection_object->param) {
					$eltd_masonry_gallery_item_icon_hide_array[$dep_collection_key].= '#eltdf_eltd_masonry_gallery_item_with_icon_'.$eltd_masonry_gallery_item_icon_collection_param.'_container,';
				}

			}

			$eltd_masonry_gallery_item_icon_hide_array[$dep_collection_key] = rtrim($eltd_masonry_gallery_item_icon_hide_array[$dep_collection_key], ',');
		}

	}

	$eltd_masonry_gallery_item_with_icon_icon_pack = new ElatedMooseMetaField(
		'select',
		'eltd_masonry_gallery_item_with_icon_icon_pack',
		'font_awesome',
		'Icon Package',
		'Choose Icon Package',
		$eltdIconCollections->getIconCollections(),
		array(
			'dependence' => true,
			'hide' => $eltd_masonry_gallery_item_icon_hide_array,
			'show' => $eltd_masonry_gallery_item_icon_show_array
		)
	);
	$eltd_masonry_gallery_item_icon_type_container->addChild('eltd_masonry_gallery_item_with_icon_icon_pack', $eltd_masonry_gallery_item_with_icon_icon_pack);

	if(is_array($eltdIconCollections->iconCollections) && count($eltdIconCollections->iconCollections)) {

		foreach ($eltdIconCollections->iconCollections as $collection_key => $collection_object) {
			$icons_array = $collection_object->getIconsArray();

			$icon_collections_keys = $eltdIconCollections->getIconCollectionsKeys();

			unset($icon_collections_keys[array_search($collection_key, $icon_collections_keys)]);

			$eltd_masonry_gallery_item_icon_hide_values = $icon_collections_keys;

			$eltd_masonry_gallery_item_icon_pack_container = new ElatedMooseContainer('eltd_masonry_gallery_item_with_icon_'.$collection_object->param.'_container', 'eltd_masonry_gallery_item_with_icon_icon_pack', '', $eltd_masonry_gallery_item_icon_hide_values);
			$eltd_masonry_gallery_item_icon_type_container->addChild('eltd_masonry_gallery_item_with_icon_'.$collection_object->param.'_container', $eltd_masonry_gallery_item_icon_pack_container);

			$eltd_masonry_gallery_item_with_icon_icon_type = new ElatedMooseMetaField('select', 'eltd_masonry_gallery_item_with_icon_'.$collection_object->param, '', $collection_object->title, 'Icon Package', $icons_array);
			$eltd_masonry_gallery_item_icon_pack_container->addChild('eltd_masonry_gallery_item_with_icon_'.$collection_object->param, $eltd_masonry_gallery_item_with_icon_icon_type);

		}

	}