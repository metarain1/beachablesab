<?php
/*
Template Name: Blog: Standard Whole Post
*/
?>
<?php get_header(); ?>
<?php
global $wp_query;
global $eltd_template_name;
$id = $wp_query->get_queried_object_id();
$eltd_template_name = get_page_template_slug($id);
if ( get_query_var('paged') ) { $paged = get_query_var('paged'); }
elseif ( get_query_var('page') ) { $paged = get_query_var('page'); }
else { $paged = 1; }
$page_object = get_post( $id );
$eltd_content = $page_object->post_content;

$blog_content_position = "content_above_blog_list";
if(isset($eltd_moose_options['blog_standard_type_content_position'])){
	$blog_content_position = $eltd_moose_options['blog_standard_type_content_position'];
}

$sidebar = get_post_meta($id, "eltd_show-sidebar", true);

if(get_post_meta($id, "eltd_page_background_color", true) != ""){
    $background_color = 'background-color: '.esc_attr(get_post_meta($id, "eltd_page_background_color", true));
}else{
    $background_color = "";
}

$content_style = "";
if(get_post_meta($id, "eltd_content-top-padding", true) != ""){
    if(get_post_meta($id, "eltd_content-top-padding-mobile", true) == 'yes'){
        $content_style = "padding-top:".esc_attr(get_post_meta($id, "eltd_content-top-padding", true))."px !important";
    }else{
        $content_style = "padding-top:".esc_attr(get_post_meta($id, "eltd_content-top-padding", true))."px";
    }
}

if(isset($eltd_moose_options['blog_standard_type_number_of_chars']) && $eltd_moose_options['blog_standard_type_number_of_chars'] != "") {
    eltd_moose_set_blog_word_count(esc_attr($eltd_moose_options['blog_standard_type_number_of_chars']));
}

?>
<script>
	<?php if(get_post_meta($id, "eltd_page_scroll_amount_for_sticky", true)) { ?>
	page_scroll_amount_for_sticky = <?php echo esc_attr(get_post_meta($id, "eltd_page_scroll_amount_for_sticky", true)); ?>;
	<?php }else{ ?>
	page_scroll_amount_for_sticky = undefined
	<?php } ?>
</script>

<?php get_template_part( 'title' ); ?>
<?php get_template_part('slider'); ?>

    <div class="container" <?php eltd_moose_inline_style($background_color); ?>>
			<?php if($eltd_moose_options['overlapping_content'] == 'yes') {?>
				<div class="overlapping_content"><div class="overlapping_content_inner">
			<?php } ?>
        <div class="container_inner default_template_holder" <?php eltd_moose_inline_style($content_style); ?>>
            <?php if(($sidebar == "default")||($sidebar == "")) : ?>
                <?php
                echo apply_filters('the_content', wp_kses_post($eltd_content));
				get_template_part('templates/blog/blog', 'structure');
                ?>
            <?php elseif($sidebar == "1" || $sidebar == "2"): ?>
				<?php
					if($blog_content_position != "content_above_blog_list"){
						echo apply_filters('the_content', wp_kses_post($eltd_content));
					}
				?>
                <div class="<?php if($sidebar == "1"):?>two_columns_66_33<?php elseif($sidebar == "2") : ?>two_columns_75_25<?php endif; ?> background_color_sidebar grid2 clearfix">
                    <div class="column1 content_left_from_sidebar">
                        <div class="column_inner">
                            <?php
							if($blog_content_position == "content_above_blog_list"){
								echo apply_filters('the_content', wp_kses_post($eltd_content));
							}
							get_template_part('templates/blog/blog', 'structure');
                            ?>
                        </div>
                    </div>
                    <div class="column2">
                        <?php get_sidebar(); ?>
                    </div>
                </div>
            <?php elseif($sidebar == "3" || $sidebar == "4"): ?>
				<?php
					if($blog_content_position != "content_above_blog_list"){
						echo apply_filters('the_content', wp_kses_post($eltd_content));
					}
				?>
                <div class="<?php if($sidebar == "3"):?>two_columns_33_66<?php elseif($sidebar == "4") : ?>two_columns_25_75<?php endif; ?> background_color_sidebar grid2 clearfix">
                    <div class="column1">
                        <?php get_sidebar(); ?>
                    </div>
                    <div class="column2 content_right_from_sidebar">
                        <div class="column_inner">
                            <?php
                            if($blog_content_position == "content_above_blog_list"){
								echo apply_filters('the_content', wp_kses_post($eltd_content));
							}
							get_template_part('templates/blog/blog', 'structure');
                            ?>
                        </div>
                    </div>
                </div>
            <?php endif; ?>
        </div>
				<?php if($eltd_moose_options['overlapping_content'] == 'yes') {?>
					</div></div>
				<?php } ?>
    </div>
<?php get_footer(); ?>