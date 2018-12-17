<?php
global $eltd_moose_options;

$title_tag="h5";
if(isset($eltd_moose_options['blog_single_title_tags'])){
    $title_tag = $eltd_moose_options['blog_single_title_tags'];
}
$headings_array = array('h2', 'h3', 'h4', 'h5', 'h6');
//get correct heading value
$title_tag = (in_array($title_tag, $headings_array)) ? $title_tag : 'h5';

$blog_author_info="yes";
if (isset($eltd_moose_options['blog_author_info'])) {
    $blog_author_info = $eltd_moose_options['blog_author_info'];
}

$pagination_classes = '';
if( isset($eltd_moose_options['pagination_type']) && $eltd_moose_options['pagination_type'] == 'standard' ) {
	if( isset($eltd_moose_options['pagination_standard_position']) && $eltd_moose_options['pagination_standard_position'] !== '' ) {
		$pagination_classes .= "standard_".esc_attr($eltd_moose_options['pagination_standard_position']);
	}
}
elseif ( isset($eltd_moose_options['pagination_type']) && $eltd_moose_options['pagination_type'] == 'arrows_on_sides' ) {
	$pagination_classes .= "arrows_on_sides";
}
$blog_social_share_type = "dropdown";
if(isset($eltd_moose_options['blog_single_select_share_option'])){
	$blog_social_share_type = $eltd_moose_options['blog_single_select_share_option'];
}
$blog_show_social_share = "no";
if (isset($eltd_moose_options['enable_social_share'])&& ($eltd_moose_options['enable_social_share']) =="yes"){
    if (isset($eltd_moose_options['post_types_names_post'])&& $eltd_moose_options['post_types_names_post'] =="post"){
        if (isset($eltd_moose_options['blog_single_show_social_share'])) {
            $blog_show_social_share = $eltd_moose_options['blog_single_show_social_share'];
        }
    }
}
$blog_show_like = "yes";
if (isset($eltd_moose_options['blog_single_show_like'])) {
    $blog_show_like = $eltd_moose_options['blog_single_show_like'];
}
?>
<?php
get_template_part('templates/blog/blog_single/blog_standard_type_single', 'loop');
?>

<?php if( has_tag()) { ?>
    <div class="single_tags clearfix">
        <div class="tags_text">
            <<?php echo esc_attr($title_tag);?> class="single_tags_heading"><?php _e('Tags:', 'eltd'); ?></<?php echo esc_attr($title_tag);?>>
            <?php the_tags('', '', ''); ?>
        </div>
    </div>
<?php } ?>
<?php
$args_pages = array(
    'before'           => '<div class="single_links_pages ' .$pagination_classes. '"><div class="single_links_pages_inner">',
    'after'            => '</div></div>',
    'link_before'      => '<span>',
    'link_after'       => '</span>',
    'pagelink'         => '%'
);

wp_link_pages($args_pages);
get_template_part('templates/blog/blog_single/blog-navigation');
?>
<?php if($blog_author_info == "yes") {

    $enable_author_info_email = "no";
    if (isset($eltd_moose_options['enable_author_info_email']) && $eltd_moose_options['enable_author_info_email'] == "yes") {
        $enable_author_info_email = "yes";
    }
	$author_facebook_page = $author_twitter_page = $author_dribbble_page = '';
	if(get_the_author_meta('facebook') != ''){
		$author_facebook_page = get_the_author_meta('facebook');
	}
	if(get_the_author_meta('twitter') != ''){
		$author_twitter_page = get_the_author_meta('twitter');
	}
	if(get_the_author_meta('dribbble') != ''){
		$author_dribbble_page = get_the_author_meta('dribbble');
	}

    ?>
    <div class="author_description">
        <div class="author_description_inner">
            <div class="image">
                <?php echo eltd_moose_kses_img(get_avatar(get_the_author_meta( 'ID' ), 112)); ?>
            </div>
            <div class="author_text_holder">					
				<<?php echo esc_attr($title_tag); ?> class="author_name">
					<span class = "author_name_text"><?php _e('AUTHOR: ','eltd')?></span>
					<?php
					if(get_the_author_meta('first_name') != "" || get_the_author_meta('last_name') != "") {
						echo esc_attr(get_the_author_meta('first_name')) . " " . esc_attr(get_the_author_meta('last_name'));
					} else {
						echo esc_attr(get_the_author_meta('display_name'));
					}
					?>
				</<?php echo esc_attr($title_tag);?>>
                <?php if(get_the_author_meta('description') != "") { ?>
                    <div class="author_text">
                        <p><?php echo esc_attr(get_the_author_meta('description')); ?></p>
                    </div>
                <?php } ?>
				<?php if($enable_author_info_email == "yes" && is_email(get_the_author_meta('email'))){ ?>
                    <span class="author_email"><?php echo sanitize_email(get_the_author_meta('email')); ?></span>
                <?php } ?>
				<?php if($author_facebook_page != '' || $author_twitter_page !='' || $author_dribbble_page != ''){ ?>
					<div class ="author_social_holder clearfix">
						<?php if($author_facebook_page != '') { ?>
							<div class="author_social_inner facebook_inner">
								<a href="<?php echo esc_attr($author_facebook_page)?>" target="blank">
									<span class="social_facebook"></span>
								</a>
							</div>	
						<?php } ?>
						<?php if($author_twitter_page != '') { ?>
							<div class="author_social_inner twitter_inner">
								<a href="<?php echo esc_attr($author_twitter_page)?>" target="blank">
									<span class="social_twitter"></span>
								</a>
							</div>	
						<?php } ?>
						<?php if($author_dribbble_page != '') { ?>
							<div class="author_social_inner twitter_inner">
								<a href="<?php echo esc_attr($author_dribbble_page)?>" target="blank">
									<span class="social_dribbble"></span>
								</a>
							</div>	
						<?php } ?>
					</div>	
				<?php } ?>	
            </div>
        </div>
    </div>
<?php } ?>
<div class="post_info_bottom">
	<?php 	
	if($blog_social_share_type == "dropdown"){
		eltd_moose_post_info(array('share' => $blog_show_social_share));
	}elseif($blog_social_share_type == "list"){
		echo do_shortcode('[no_social_share_list]'); // XSS OK
	}?>	
	<div class = "blog_print">
		<a href="#" class = "blog_print_wrapper">
			<span class="icon-printer print_icon"></span>
			<span class="blog-print-text"><?php _e('Print Post', 'eltd')?></span>
		</a>
	</div>

	<?php if($blog_show_like == "yes"){
		eltd_moose_post_info(array('like' => $blog_show_like));
	}
	?>
</div>