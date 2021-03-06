<?php
	global $wp_query;
	global $eltd_moose_options;
    global $eltd_template_name;
	$id = $wp_query->get_queried_object_id();

	$category = get_post_meta($id, "eltd_choose-blog-category", true);
	$post_number = esc_attr(get_post_meta($id, "eltd_show-posts-per-page", true));

	if ( get_query_var('paged') ) { $paged = get_query_var('paged'); }
	elseif ( get_query_var('page') ) { $paged = get_query_var('page'); }
	else { $paged = 1; }

	$sidebar = $eltd_moose_options['category_blog_sidebar'];

	if(!is_archive()) {
		$blog_query = new WP_Query('post_type=post&paged=' . $paged . '&cat=' . $category . '&posts_per_page=' . $post_number);
	}else{
		$blog_query = $wp_query;
	}

	if(isset($eltd_moose_options['blog_page_range']) && $eltd_moose_options['blog_page_range'] != ""){
		$blog_page_range = esc_attr($eltd_moose_options['blog_page_range']);
	} else{
		$blog_page_range = $blog_query->max_num_pages;
	}
	
	$blog_style = "1";
	if(isset($eltd_moose_options['blog_style'])){
		$blog_style = $eltd_moose_options['blog_style'];
	}

	$filter = "no";
	if($eltd_template_name == "blog-masonry-gallery-full-width.php" || $eltd_template_name == "blog-masonry-gallery.php" || $blog_style==14 || $blog_style== 15) {
		if(isset($eltd_moose_options['blog_masonry_gallery_filter'])){
			$filter = $eltd_moose_options['blog_masonry_gallery_filter'];
		}
	}
	else {
		if(isset($eltd_moose_options['blog_masonry_filter'])){
			$filter = $eltd_moose_options['blog_masonry_filter'];
		}
	}
	
	
	$blog_masonry_type = "blog_masonry_standard";
	if(isset($eltd_moose_options['blog_masonry_choose_type'])){
		$blog_masonry_type = $eltd_moose_options['blog_masonry_choose_type'];
	} 

	$blog_list = "";
	if($eltd_template_name != "") {
		if($eltd_template_name == "blog-masonry.php"){
			$blog_list = "blog_masonry";
			$blog_list_class = "masonry";
		}elseif($eltd_template_name == "blog-split-column.php"){
			$blog_list = "blog_split_column";
			$blog_list_class = "blog_split_column";
		}elseif($eltd_template_name == "blog-masonry-full-width.php"){
			$blog_list = "blog_masonry";
			$blog_list_class = "masonry_full_width";
		}elseif($eltd_template_name == "blog-standard.php"){
            $blog_list = "blog_standard";
            $blog_list_class = "blog_standard_type";
        }elseif($eltd_template_name == "blog-standard-whole-post.php"){
			$blog_list = "blog_standard_whole_post";
			$blog_list_class = "blog_standard_type";
		}elseif($eltd_template_name == "blog-masonry-gallery.php"){
            $blog_list = "blog_masonry_gallery";
            $blog_list_class = "blog_masonry_gallery";// Check
        }elseif($eltd_template_name == "blog-masonry-gallery-full-width.php"){
            $blog_list = "blog_masonry_gallery";
            $blog_list_class = "blog_masonry_gallery masonry_gallery_full_width";// Check
        }else{
			$blog_list = "blog_standard";
			$blog_list_class = "blog_standard_type";
		}
	} else{
		if($blog_style=="1"){
			$blog_list = "blog_standard";
			$blog_list_class = "blog_standard_type";
		}elseif($blog_style=="2"){
			$blog_list = "blog_split_column";
			$blog_list_class = "blog_split_column";
        }elseif($blog_style=="3"){
			$blog_list = "blog_masonry";
			$blog_list_class = "masonry";
        }elseif($blog_style=="4"){
			$blog_list = "blog_masonry";
			$blog_list_class = "masonry_full_width";
        }elseif($blog_style=="9"){
			$blog_list = "blog_standard_whole_post";
			$blog_list_class = "blog_standard_type";
		}elseif($blog_style=="14"){
			$blog_list = "blog_masonry_gallery";
			$blog_list_class = "blog_masonry_gallery";
		}elseif($blog_style=="15"){
			$blog_list = "blog_masonry_gallery";
			$blog_list_class = "blog_masonry_gallery masonry_gallery_full_width";
		}else {
			$blog_list = "blog_standard";
			$blog_list_class = "blog_standard_type";
		}
	}

    $pagination_masonry = "pagination";
    if(isset($eltd_moose_options['pagination_masonry'])){
       $pagination_masonry = $eltd_moose_options['pagination_masonry'];
		if($blog_list == "blog_masonry") {
			$blog_list_class .= " masonry_" . $pagination_masonry;
		}
    }
	
	$pagination_masonry_gallery = "pagination";
    if(isset($eltd_moose_options['pagination_masonry_gallery'])){
       $pagination_masonry_gallery = $eltd_moose_options['pagination_masonry_gallery'];
	   $blog_list_class .= " masonry_" . $pagination_masonry_gallery;
    }
?>
<?php

	if(($blog_list == "blog_masonry" || $blog_list == "blog_masonry_gallery") && $filter == "yes") {
		get_template_part('templates/blog/masonry', 'filter');

	}

	$blog_masonry_columns = 'three_columns';
	if (isset($eltd_moose_options['blog_masonry_columns']) && $eltd_moose_options['blog_masonry_columns'] !== '') {
		$blog_masonry_columns = $eltd_moose_options['blog_masonry_columns'];
	}

	$blog_masonry_full_width_columns = 'five_columns';
	if (isset($eltd_moose_options['blog_masonry_full_width_columns']) && $eltd_moose_options['blog_masonry_full_width_columns'] !== '') {
		$blog_masonry_full_width_columns = $eltd_moose_options['blog_masonry_full_width_columns'];
	}
	
	$blog_masonry_gallery_column = 'two_columns';
	if (isset($eltd_moose_options['blog_masonry_gallery_columns']) && $eltd_moose_options['blog_masonry_gallery_columns'] !== '') {
		$blog_masonry_gallery_column = $eltd_moose_options['blog_masonry_gallery_columns'];
	}

	$blog_masonry_gallery_full_width_columns = 'three_columns';
	if (isset($eltd_moose_options['blog_masonry_gallery_full_width_columns']) && $eltd_moose_options['blog_masonry_gallery_full_width_columns'] !== '') {
		$blog_masonry_gallery_full_width_columns = $eltd_moose_options['blog_masonry_gallery_full_width_columns'];
	}
	
	if($eltd_template_name == "blog-masonry.php" || $blog_style == 3 ){
		$blog_list_class .= " " .$blog_masonry_columns;
	}
	
	if($eltd_template_name == "blog-masonry-full-width.php" || $blog_style == 4){
		$blog_list_class .= " " .$blog_masonry_full_width_columns;
	}

	if($eltd_template_name == "blog-masonry-gallery.php" || $blog_style == 14 ){
		$blog_list_class .= " " .$blog_masonry_gallery_column;
	}
	
	if($eltd_template_name == "blog-masonry-gallery-full-width.php" || $blog_style == 15){
		$blog_list_class .= " " .$blog_masonry_gallery_full_width_columns;
	}

	
	$icon_left_html =  "<i class='pagination_arrow arrow_carrot-left'></i>";
	if (isset($eltd_moose_options['pagination_arrows_type']) && $eltd_moose_options['pagination_arrows_type'] != '') {
		$icon_navigation_class = $eltd_moose_options['pagination_arrows_type'];
		$direction_nav_classes = eltd_moose_horizontal_slider_icon_classes($icon_navigation_class);
		$icon_left_html = '<span class="pagination_arrow ' . $direction_nav_classes['left_icon_class']. '"></span>';
	}
	
	$icon_left_html .= '<span class="pagination_label">';
	if (isset($eltd_moose_options['blog_pagination_previous_label']) && $eltd_moose_options['blog_pagination_previous_label'] != '') {
		$icon_left_html.= $eltd_moose_options['blog_pagination_previous_label'];
	}
	else{
		$icon_left_html .= "Previous";
	}
	$icon_left_html .= '</span>';


	$icon_right_html = '<span class="pagination_label">';
	if (isset($eltd_moose_options['blog_pagination_next_label']) && $eltd_moose_options['blog_pagination_next_label'] != '') {
		$icon_right_html .= $eltd_moose_options['blog_pagination_next_label'];
	}
	else {
		$icon_right_html .= "Next";
	}
	$icon_right_html .= '</span>';

	if (isset($eltd_moose_options['pagination_arrows_type']) && $eltd_moose_options['pagination_arrows_type'] != '') {
		$icon_navigation_class = $eltd_moose_options['pagination_arrows_type'];
		$direction_nav_classes = eltd_moose_horizontal_slider_icon_classes($icon_navigation_class);
		$icon_right_html .= '<span class="pagination_arrow ' . $direction_nav_classes['right_icon_class']. '"></span>';
	}
	else{
		$icon_right_html .=  "<i class='pagination_arrow arrow_carrot-right'></i>";
	}

	?>

	<div class="blog_holder <?php echo esc_attr($blog_list_class); ?>">
		
	<?php if($blog_list == "blog_masonry" || $blog_list == "blog_masonry_gallery" ) { ?>
		<div class="blog_holder_grid_sizer"></div>
		<div class="blog_holder_grid_gutter"></div>
	<?php } ?>
	<?php if($blog_query->have_posts()) : while ( $blog_query->have_posts() ) : $blog_query->the_post(); ?>
		<?php
			get_template_part('templates/blog/'.$blog_list, 'loop');
		?>
	<?php endwhile; ?>
	<?php if($blog_list != "blog_masonry" && $blog_list != "blog_masonry_gallery") {
		if ($eltd_moose_options['blog_pagination_type'] == 'standard'){
				eltd_moose_pagination($blog_query->max_num_pages, $blog_page_range, $paged);
			}
		elseif ($eltd_moose_options['blog_pagination_type'] == 'prev_and_next'){?>
			<div class="pagination_prev_and_next_only">
				<ul>
					<li class='prev'><?php echo wp_kses_post(get_previous_posts_link($icon_left_html, $blog_query->max_num_pages)); ?></li>
					<li class='next'><?php echo wp_kses_post(get_next_posts_link($icon_right_html, $blog_query->max_num_pages)); ?></li>
				</ul>
			</div>
		<?php } ?>
	<?php } ?>
	<?php else: //If no posts are present ?>
	<div class="entry">
			<p><?php _e('No posts were found.', 'eltd'); ?></p>
	</div>
	<?php endif; ?>
</div>
<?php if($blog_list == "blog_masonry") {
    if($pagination_masonry == "load_more") {
		if (get_next_posts_link(null, $blog_query->max_num_pages)) { ?>
			<div class="blog_load_more_button_holder">
				<div class="blog_load_more_button"><span data-rel="<?php echo esc_attr($blog_query->max_num_pages); ?>"><?php echo wp_kses_post(get_next_posts_link(__('Show more', 'eltd'), $blog_query->max_num_pages)); ?></span></div>
			</div>
		<?php } ?>
	 <?php } elseif($pagination_masonry == "infinite_scroll") { ?>
		<div class="blog_infinite_scroll_button"><span data-rel="<?php echo esc_attr($blog_query->max_num_pages); ?>"><?php echo wp_kses_post(get_next_posts_link(__('Show more', 'eltd'), $blog_query->max_num_pages)); ?></span></div>
    <?php }else { ?>
        <?php if($eltd_moose_options['blog_pagination_type'] == 'standard' && $eltd_moose_options['pagination'] != "0") {
				eltd_moose_pagination($blog_query->max_num_pages, $blog_page_range, $paged);
            }
        	elseif ($eltd_moose_options['blog_pagination_type'] == 'prev_and_next'){ ?>
				<div class="pagination_prev_and_next_only">
					<ul>
						<li class='prev'><?php echo wp_kses_post(get_previous_posts_link($icon_left_html, $blog_query->max_num_pages)); ?></li>
						<li class='next'><?php echo wp_kses_post(get_next_posts_link($icon_right_html, $blog_query->max_num_pages)); ?></li>
					</ul>
				</div>
		<?php } ?>
    <?php } ?>
<?php } ?>
<?php if($blog_list == "blog_masonry_gallery") {
    if($pagination_masonry_gallery == "load_more") {
		if (get_next_posts_link(null, $blog_query->max_num_pages)) { ?>
			<div class="blog_load_more_button_holder">
				<div class="blog_load_more_button"><span data-rel="<?php echo esc_attr($blog_query->max_num_pages); ?>"><?php echo wp_kses_post(get_next_posts_link(__('Show more', 'eltd'), $blog_query->max_num_pages)); ?></span></div>
			</div>
		<?php } ?>
	 <?php } elseif($pagination_masonry_gallery == "infinite_scroll") { ?>
		<div class="blog_infinite_scroll_button"><span data-rel="<?php echo esc_attr($blog_query->max_num_pages); ?>"><?php echo wp_kses_post(get_next_posts_link(__('Show more', 'eltd'), $blog_query->max_num_pages)); ?></span></div>
    <?php }else { ?>
        <?php if($eltd_moose_options['blog_pagination_type'] == 'standard' && $eltd_moose_options['pagination'] != "0") {
				eltd_moose_pagination($blog_query->max_num_pages, $blog_page_range, $paged);
            }
        	elseif ($eltd_moose_options['blog_pagination_type'] == 'prev_and_next'){ ?>
				<div class="pagination_prev_and_next_only">
					<ul>
						<li class='prev'><?php echo wp_kses_post(get_previous_posts_link($icon_left_html, $blog_query->max_num_pages)); ?></li>
						<li class='next'><?php echo wp_kses_post(get_next_posts_link($icon_right_html, $blog_query->max_num_pages)); ?></li>
					</ul>
				</div>
		<?php } ?>
    <?php } ?>
<?php } ?>
<?php wp_reset_postdata(); ?>