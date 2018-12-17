<?php 
global $eltd_moose_options;

$blog_hide_author = "";
if (isset($eltd_moose_options['blog_hide_author'])) {
    $blog_hide_author = $eltd_moose_options['blog_hide_author'];
}
?>
<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
	<div class="post_content_holder">
		<div class ="blog_title_post_info_holder">
			<div class="post_corner_info_holder">
				
				<div class="post_date_standard_holder">
					<span class="post_date_day"><?php the_time('d')?></span>
					<span class="post_date_month_year"><?php the_time('M Y')?></span>
				</div>
			</div>
			<div class="post_text">
				<div class="post_text_inner">
					<h2>
						<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
					</h2>
				</div>
			</div>
		</div>
		<?php if ( has_post_thumbnail() ) { ?>
			<div class="post_image">
				<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>">
					<?php the_post_thumbnail('full'); ?>
				</a>
			</div>
		<?php } ?>
		<div class="post_text">
			<div class="post_text_inner">
				<?php
					$my_excerpt = get_the_excerpt();
					if ($my_excerpt != '') {
						echo esc_html($my_excerpt);
					}
				?>
			</div>
		</div>
	</div>
</article>