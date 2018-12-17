<?php
global $eltd_moose_options;
global $more;
$more = 0;


$blog_show_categories = "no";
if (isset($eltd_moose_options['blog_masonry_show_categories'])){
	$blog_show_categories = $eltd_moose_options['blog_masonry_show_categories'];
}
$blog_show_comments = "no";
if (isset($eltd_moose_options['blog_masonry_show_comments'])){
	$blog_show_comments = $eltd_moose_options['blog_masonry_show_comments'];
}

$blog_show_author = "no";
if (isset($eltd_moose_options['blog_masonry_show_author'])){
	$blog_show_author = $eltd_moose_options['blog_masonry_show_author'];
}
$blog_show_like = "no";
if (isset($eltd_moose_options['blog_masonry_show_like'])) {
	$blog_show_like = $eltd_moose_options['blog_masonry_show_like'];
}
$blog_show_ql_icon_mark = "yes";
$blog_title_holder_icon_class = "";
if (isset($eltd_moose_options['blog_masonry_show_ql_mark'])) {
	$blog_show_ql_icon_mark = $eltd_moose_options['blog_masonry_show_ql_mark'];
}

if ($blog_show_ql_icon_mark == "yes") {
	$blog_title_holder_icon_class = " with_icon_right";
}

$blog_show_date = "no";
if (isset($eltd_moose_options['blog_masonry_show_date'])) {
	$blog_show_date = $eltd_moose_options['blog_masonry_show_date'];
}

$blog_social_share_type = "dropdown";
if(isset($eltd_moose_options['blog_masonry_select_share_options_masonry_type'])){
	$blog_social_share_type = $eltd_moose_options['blog_masonry_select_share_options_masonry_type'];
}
$blog_show_social_share = "no";
if (isset($eltd_moose_options['enable_social_share'])&& $eltd_moose_options['enable_social_share'] =="yes"){
	if (isset($eltd_moose_options['post_types_names_post'])&& $eltd_moose_options['post_types_names_post'] =="post"){
		if (isset($eltd_moose_options['blog_masonry_show_share'])&& $blog_social_share_type == "dropdown") {
					$blog_show_social_share = $eltd_moose_options['blog_masonry_show_share'];
		}
	}
}

$blog_read_more_button_classes = '';
if (isset($eltd_moose_options['blog_masonry_read_more_button_icon']) && $eltd_moose_options['blog_masonry_read_more_button_icon'] == 'yes'){
    $blog_read_more_button_classes .= 'with_icon';
}

$_post_format = get_post_format();

$blog_masonry_type = "post_info_below_title";
if(isset($eltd_moose_options['blog_masonry_type'])){
	$blog_masonry_type = $eltd_moose_options['blog_masonry_type'];
}

$blog_ql_background_image = "no";
if(isset($eltd_moose_options['blog_masonry_ql_background_image'])){
	$blog_ql_background_image = $eltd_moose_options['blog_masonry_ql_background_image'];
}

?>
<?php
switch ($_post_format) {
	case "video":
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_image">
				<?php get_template_part('templates/blog/parts/post-format-video'); ?>
				<div class="post_corner_info_holder">
					<?php
					if ($blog_show_date == 'yes'){ ?>
					<div class="post_date_standard_holder">
						<span class="post_date_day"><?php the_time('d')?></span>
						<span class="post_date_month_year"><?php the_time('M Y')?></span>
					</div>
					<?php } ?>
					<?php
					if ($blog_show_comments == 'yes'){ ?>
					<div class="post_comments_standard_holder">
						<div class="post_comments_holder">
							<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
								<span class="post_comments_number"><?php comments_number('0 ', '1 ', '% '); ?></span>
								<span class="icon-bubble"></span>
							</a>
						</div>
					</div>
					<?php }
					?>
				</div>
			</div>
			<div class="post_text">
				<div class="post_text_inner">
					<h4>
						<a href="<?php the_permalink(); ?>" target="_self" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
					</h4>
					<?php if($blog_masonry_type == "post_info_below_title"){
						if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes") { ?>
							<div class="post_info">
								<?php eltd_moose_post_info(array('author' => $blog_show_author)); ?>
								<?php eltd_moose_post_info(array('category' => $blog_show_categories)); ?>
								<?php eltd_moose_post_info(array('share' => $blog_show_social_share)); ?>
							</div>
						<?php }} ?>
					<?php
						eltd_moose_excerpt();
						eltd_moose_read_more_button('blog_masonry_read_more_button',$blog_read_more_button_classes);
					?>

					<?php if($blog_masonry_type == "post_info_at_bottom"){
						if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes") { ?>
							<div class="post_info">
								<?php eltd_moose_post_info(array('author' => $blog_show_author)); ?>
								<?php eltd_moose_post_info(array('category' => $blog_show_categories)); ?>
								<?php eltd_moose_post_info(array('share' => $blog_show_social_share)); ?>
							</div>
						<?php }} ?>
				</div>
			</div>
		</article>

		<?php
		break;
	case "audio":
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">
				<?php if ( has_post_thumbnail() ) { ?>
					<div class="post_image">
						<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>">
							<?php the_post_thumbnail('full'); ?>
						</a>
						<div class="post_corner_info_holder">
							<?php
							if ($blog_show_date == 'yes'){ ?>
							<div class="post_date_standard_holder">
								<span class="post_date_day"><?php the_time('d')?></span>
								<span class="post_date_month_year"><?php the_time('M Y')?></span>
							</div>
							<?php } ?>
							<?php
							if ($blog_show_comments == 'yes'){ ?>
							<div class="post_comments_standard_holder">
								<div class="post_comments_holder">
									<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
										<span class="post_comments_number"><?php comments_number('0 ', '1 ', '% '); ?></span>
										<span class="icon-bubble"></span>
									</a>
								</div>
							</div>
							<?php }
							?>
						</div>
					</div>
				<?php } ?>
				<div class="audio_image">
					<audio class="blog_audio" src="<?php echo esc_url(get_post_meta(get_the_ID(), "audio_link", true)) ?>" controls="controls">
						<?php _e("Your browser don't support audio player","eltd"); ?>
					</audio>
				</div>
				<div class="post_text">
					<div class="post_text_inner">
						<h4>
							<a href="<?php the_permalink(); ?>" target="_self" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
						</h4>
						<?php if($blog_masonry_type == "post_info_below_title"){
							if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes") { ?>
								<div class="post_info">
									<?php eltd_moose_post_info(array('author' => $blog_show_author)); ?>
									<?php eltd_moose_post_info(array('category' => $blog_show_categories)); ?>
									<?php eltd_moose_post_info(array('share' => $blog_show_social_share)); ?>
								</div>
							<?php }} ?>
						<?php
							eltd_moose_excerpt();
                            eltd_moose_read_more_button('blog_masonry_read_more_button',$blog_read_more_button_classes);
						?>

						<?php if($blog_masonry_type == "post_info_at_bottom"){
							if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes") { ?>
								<div class="post_info">
									<?php eltd_moose_post_info(array('author' => $blog_show_author)); ?>
									<?php eltd_moose_post_info(array('category' => $blog_show_categories)); ?>
									<?php eltd_moose_post_info(array('share' => $blog_show_social_share)); ?>
								</div>
							<?php }} ?>
					</div>
				</div>
		</article>
		<?php
		break;
	case "link":
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">
				<div class="post_text  <?php if($blog_ql_background_image == "yes") { if ( has_post_thumbnail() ) { ?> link_image" style="background:url(<?php  echo wp_get_attachment_url(get_post_thumbnail_id()); ?>); <?php }} ?>">
					<div class="post_corner_info_holder">
						<?php
						if ($blog_show_date == 'yes'){ ?>
						<div class="post_date_standard_holder">
							<span class="post_date_day"><?php the_time('d')?></span>
							<span class="post_date_month_year"><?php the_time('M Y')?></span>
						</div>
						<?php } ?>
						<?php
						if ($blog_show_comments == 'yes'){ ?>
						<div class="post_comments_standard_holder">
							<div class="post_comments_holder">
								<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
									<span class="post_comments_number"><?php comments_number('0 ', '1 ', '% '); ?></span>
									<span class="icon-bubble"></span>
								</a>
							</div>
						</div>
						<?php }
						?>
					</div>
					<div class="post_text_inner">
						<?php if ($blog_show_ql_icon_mark == "yes") { ?>
							<div class="post_info_link_mark">
								<span aria-hidden="true" class="icon_link link_mark"></span>
							</div>
						<?php } ?>
						<div class="post_title<?php echo esc_attr($blog_title_holder_icon_class); ?>">
							<h3><a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a></h3>
						</div>
						<?php if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes") { ?>
							<div class="post_info">
								<?php eltd_moose_post_info(array('author' => $blog_show_author)); ?>
								<?php eltd_moose_post_info(array('category' => $blog_show_categories)); ?>
								<?php eltd_moose_post_info(array('share' => $blog_show_social_share)); ?>
							</div>
						<?php } ?>
					</div>
				</div>
			</div>
		</article>
		<?php
		break;
	case "gallery":
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_image">
				<?php get_template_part('templates/blog/parts/post-format-gallery-slider'); ?>
				<div class="post_corner_info_holder">
					<?php
					if ($blog_show_date == 'yes'){ ?>
					<div class="post_date_standard_holder">
						<span class="post_date_day"><?php the_time('d')?></span>
						<span class="post_date_month_year"><?php the_time('M Y')?></span>
					</div>
					<?php } ?>
					<?php
					if ($blog_show_comments == 'yes'){ ?>
					<div class="post_comments_standard_holder">
						<div class="post_comments_holder">
							<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
								<span class="post_comments_number"><?php comments_number('0 ', '1 ', '% '); ?></span>
								<span class="icon-bubble"></span>
							</a>
						</div>
					</div>
					<?php }
					?>
				</div>
			</div>
			<div class="post_text">
				<div class="post_text_inner">
					<h4>
						<a href="<?php the_permalink(); ?>" target="_self" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
					</h4>
					<?php if($blog_masonry_type == "post_info_below_title"){
						if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes") { ?>
							<div class="post_info">
								<?php eltd_moose_post_info(array('author' => $blog_show_author)); ?>
								<?php eltd_moose_post_info(array('category' => $blog_show_categories)); ?>
								<?php eltd_moose_post_info(array('share' => $blog_show_social_share)); ?>
							</div>
					<?php }} ?>
					<?php
						eltd_moose_excerpt();
                        eltd_moose_read_more_button('blog_masonry_read_more_button',$blog_read_more_button_classes);
					?>

					<?php if($blog_masonry_type == "post_info_at_bottom"){
						if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes") { ?>
							<div class="post_info">
								<?php eltd_moose_post_info(array('author' => $blog_show_author)); ?>
								<?php eltd_moose_post_info(array('category' => $blog_show_categories)); ?>
								<?php eltd_moose_post_info(array('share' => $blog_show_social_share)); ?>
							</div>
						<?php }} ?>
				</div>
			</div>
		</article>
		<?php
		break;
	case "quote":
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">
				<div class="post_text  <?php if($blog_ql_background_image == "yes") { if ( has_post_thumbnail() ) { ?> quote_image" style="background:url(<?php  echo wp_get_attachment_url(get_post_thumbnail_id()); ?>);<?php }} ?>">
					<div class="post_corner_info_holder">
						<?php
						if ($blog_show_date == 'yes'){ ?>
						<div class="post_date_standard_holder">
							<span class="post_date_day"><?php the_time('d')?></span>
							<span class="post_date_month_year"><?php the_time('M Y')?></span>
						</div>
						<?php } ?>
						<?php
						if ($blog_show_comments == 'yes'){ ?>
						<div class="post_comments_standard_holder">
							<div class="post_comments_holder">
								<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
									<span class="post_comments_number"><?php comments_number('0 ', '1 ', '% '); ?></span>
									<span class="icon-bubble"></span>
								</a>
							</div>
						</div>
						<?php }
						?>
					</div>
					<div class="post_text_inner">
						<?php if ($blog_show_ql_icon_mark == "yes") { ?>
							<div class="post_info_quote_mark">
								<span aria-hidden="true" class="icon_quotations quote_mark"></span>
							</div>
						<?php } ?>
						<div class="post_title<?php echo esc_attr($blog_title_holder_icon_class); ?>">
							<h3><a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>">
									<?php echo esc_html(get_post_meta(get_the_ID(), "quote_format", true)); ?>
								</a>
							</h3>
							<span class="quote_author">&mdash; <?php the_title(); ?></span>
						</div>
						<?php if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes") { ?>
							<div class="post_info">
								<?php eltd_moose_post_info(array('author' => $blog_show_author)); ?>
								<?php eltd_moose_post_info(array('category' => $blog_show_categories)); ?>
								<?php eltd_moose_post_info(array('share' => $blog_show_social_share)); ?>
							</div>
						<?php } ?>
					</div>
				</div>
			</div>
		</article>
		<?php
		break;
	default:
		?>
			<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
				<?php if ( has_post_thumbnail() ) { ?>
					<div class="post_image">
						<a href="<?php the_permalink(); ?>" target="_self" title="<?php the_title_attribute(); ?>">
							<?php the_post_thumbnail('full'); ?>
						</a>
						<div class="post_corner_info_holder">
							<?php
							if ($blog_show_date == 'yes'){ ?>
							<div class="post_date_standard_holder">
								<span class="post_date_day"><?php the_time('d')?></span>
								<span class="post_date_month_year"><?php the_time('M Y')?></span>
							</div>
							<?php } ?>
							<?php
							if ($blog_show_comments == 'yes'){ ?>
							<div class="post_comments_standard_holder">
								<div class="post_comments_holder">
									<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
										<span class="post_comments_number"><?php comments_number('0 ', '1 ', '% '); ?></span>
										<span class="icon-bubble"></span>
									</a>
								</div>
							</div>
							<?php }
							?>
						</div>
					</div>
				<?php } ?>
				<div class="post_text">
					<div class="post_text_inner">
						<h4>
							<a href="<?php the_permalink(); ?>" target="_self" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
						</h4>
						<?php if($blog_masonry_type == "post_info_below_title"){ 
							if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes") { ?>
								<div class="post_info">
									<?php eltd_moose_post_info(array('author' => $blog_show_author)); ?>
									<?php eltd_moose_post_info(array('category' => $blog_show_categories)); ?>
									<?php eltd_moose_post_info(array('share' => $blog_show_social_share)); ?>
								</div>
						<?php }} ?>
						<?php
							eltd_moose_excerpt();
                            eltd_moose_read_more_button('blog_masonry_read_more_button',$blog_read_more_button_classes);
						?>
													
						<?php if($blog_masonry_type == "post_info_at_bottom"){
							if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes") { ?>
								<div class="post_info">
									<?php eltd_moose_post_info(array('author' => $blog_show_author)); ?>
									<?php eltd_moose_post_info(array('category' => $blog_show_categories)); ?>
									<?php eltd_moose_post_info(array('share' => $blog_show_social_share)); ?>
								</div>
						<?php }} ?>
					</div>
				</div>
			</article>
		<?php
}
?>

