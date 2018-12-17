<?php
global $eltd_moose_options;
global $more;
$more = 0;

$blog_show_categories = "no";
if (isset($eltd_moose_options['blog_split_column_show_categories'])){
	$blog_show_categories = $eltd_moose_options['blog_split_column_show_categories'];
}

$blog_show_comments = "no";
if (isset($eltd_moose_options['blog_split_column_show_comments'])){
	$blog_show_comments = $eltd_moose_options['blog_split_column_show_comments'];
}

$blog_show_author = "yes";
if (isset($eltd_moose_options['blog_split_column_show_author'])){
	$blog_show_author = $eltd_moose_options['blog_split_column_show_author'];
}
$blog_show_like = "no";
if (isset($eltd_moose_options['blog_split_column_show_like'])) {
	$blog_show_like = $eltd_moose_options['blog_split_column_show_like'];
}

$blog_show_ql_icon_mark = "yes";
$blog_title_holder_icon_class = "";
if (isset($eltd_moose_options['blog_split_column_show_ql_mark'])) {
	$blog_show_ql_icon_mark = $eltd_moose_options['blog_split_column_show_ql_mark'];
}

if($blog_show_ql_icon_mark == "yes"){
	$blog_title_holder_icon_class = " with_icon_right";
}

$blog_show_date = "yes";
if (isset($eltd_moose_options['blog_split_column_show_date'])) {
	$blog_show_date = $eltd_moose_options['blog_split_column_show_date'];
}

$blog_social_share_type = "dropdown";
if(isset($eltd_moose_options['blog_split_column_select_share_option'])){
	$blog_social_share_type = $eltd_moose_options['blog_split_column_select_share_option'];
}
$blog_show_social_share = "no";
if (isset($eltd_moose_options['enable_social_share'])&& $eltd_moose_options['enable_social_share'] =="yes"){
	if (isset($eltd_moose_options['post_types_names_post'])&& $eltd_moose_options['post_types_names_post'] =="post"){
		if (isset($eltd_moose_options['blog_split_column_show_share']) && $blog_social_share_type == "dropdown") {
			$blog_show_social_share = $eltd_moose_options['blog_split_column_show_share'];
		}
	}
}

$blog_read_more_button_classes = 'transparent ';
if (isset($eltd_moose_options['blog_split_column_read_more_button_icon']) && $eltd_moose_options['blog_split_column_read_more_button_icon'] == 'yes'){
    $blog_read_more_button_classes .= 'with_icon';
}


$background_image_object = wp_get_attachment_image_src(get_post_thumbnail_id( get_the_ID()), 'eltd-moose-blog-image-format-link-quote');
$background_image_src = $background_image_object[0];


$blog_image_size = 'full';
if( isset($eltd_moose_options['blog_split_column_image_size']) && $eltd_moose_options['blog_split_column_image_size'] !== '') {
    $blog_image_size = 'eltd-moose-'.$eltd_moose_options['blog_split_column_image_size'];

}

if( $blog_image_size == 'custom'
    && isset($eltd_moose_options['blog_split_column_image_size_height']) && $eltd_moose_options['blog_split_column_image_size_height'] !== ''
    && isset($eltd_moose_options['blog_split_column_image_size_width']) && $eltd_moose_options['blog_split_column_image_size_width'] !== '') {

    $image_height = $eltd_moose_options['blog_split_column_image_size_height'];
    $image_width = $eltd_moose_options['blog_split_column_image_size_width'];

    $image_html = eltd_moose_generate_thumbnail(get_post_thumbnail_id(get_the_ID()),null,$image_width,$image_height);
}
else{
    $image_html = get_the_post_thumbnail(get_the_ID(), $blog_image_size);
}


$_post_format = get_post_format();



?>
<?php
switch ($_post_format) {
	case "video":		
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">								
				<div class="post_content_column">
					<div class="post_image">						
						<?php $_video_type = get_post_meta(get_the_ID(), "video_format_choose", true);?>
						<?php if($_video_type == "youtube") { ?>
							<iframe  src="//www.youtube.com/embed/<?php echo esc_attr(get_post_meta(get_the_ID(), "video_format_link", true));  ?>?wmode=transparent" wmode="Opaque" frameborder="0" allowfullscreen></iframe>
						<?php } elseif ($_video_type == "vimeo"){ ?>
							<iframe src="//player.vimeo.com/video/<?php echo esc_attr(get_post_meta(get_the_ID(), "video_format_link", true));  ?>?title=0&amp;byline=0&amp;portrait=0" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>
						<?php } elseif ($_video_type == "self"){ ?>
							<div class="video">
								<div class="mobile-video-image" style="background-image: url(<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_image", true));  ?>);"></div>
								<div class="video-wrap"  >
									<video class="video" poster="<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_image", true));  ?>" preload="auto">
										<?php if(get_post_meta(get_the_ID(), "video_format_webm", true) != "") { ?> <source type="video/webm" src="<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_webm", true));  ?>"> <?php } ?>
										<?php if(get_post_meta(get_the_ID(), "video_format_mp4", true) != "") { ?> <source type="video/mp4" src="<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_mp4", true));  ?>"> <?php } ?>
										<?php if(get_post_meta(get_the_ID(), "video_format_ogv", true) != "") { ?> <source type="video/ogg" src="<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_ogv", true));  ?>"> <?php } ?>
										<object width="320" height="240" type="application/x-shockwave-flash" data="<?php echo esc_url(get_template_directory_uri().'/js/flashmediaelement.swf'); ?>">
											<param name="movie" value="<?php echo esc_url(get_template_directory_uri().'/js/flashmediaelement.swf'); ?>" />
											<param name="flashvars" value="controls=true&file=<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_mp4", true));  ?>" />
											<img src="<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_image", true));  ?>" width="1920" height="800" title="No video playback capabilities" alt="Video thumb" />
										</object>
									</video>
								</div>
							</div>
						<?php } ?>
						<div class="post_corner_info_holder">
							<?php
							if ($blog_show_date == 'yes'){ ?>
							<div class="post_date_standard_holder">
								<span class="post_date_month"><?php the_time('M')?></span>
								<span class="post_date_day"><?php the_time('d')?></span>
								<span class="post_date_year"><?php the_time('Y')?></span>
							</div>
							<?php } ?>
							<?php
							if ($blog_show_comments == 'yes'){ ?>
							<div class="post_comments_standard_holder">
								<div class="post_comments_holder">
									<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
										<span class="post_comments_number"><?php comments_number('0 ', '1 ', '% '); ?></span>
										<span class="post_comments_text"><?php comments_number(__('comments','eltd'),__('comment','eltd'),__('comments','eltd') ); ?></span>
									</a>
								</div>
							</div>
							<?php }
							?>
						</div>						
					</div>
				</div>
				<div class="post_content_column text-wrapper">
					<div class="post_text">
						<div class="post_text_inner">
							<h2>
								<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
							</h2>
							<?php if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes" || $blog_show_like == "yes") { ?>
								<div class="post_info">
									<?php eltd_moose_post_info(array('author' => $blog_show_author, 'share' => $blog_show_social_share, 'category' => $blog_show_categories, 'like' => $blog_show_like)); ?>
								</div>
							<?php } ?>
							<?php
								eltd_moose_excerpt();
                                eltd_moose_read_more_button('blog_split_column_read_more_button',$blog_read_more_button_classes);
							?>
							<?php if(isset($eltd_moose_options['blog_split_column_show_share']) && $eltd_moose_options['blog_split_column_show_share'] == "yes" && $blog_social_share_type == "list") {
								echo do_shortcode('[no_social_share_list]'); // XSS OK
							}; ?>	
						</div>
					</div>
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
					<div class="post_content_column">
						<div class="post_image">
							<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>">
                                <?php echo wp_kses($image_html, array(
                                    'img' => array(
                                        'src' => true,
                                        'alt' => true,
                                        'width' => true,
                                        'height' => true,
                                        'draggable' => true
                                    )
                                )); ?>
							</a>
							<div class="post_corner_info_holder">
								<?php
								if ($blog_show_date == 'yes'){ ?>
								<div class="post_date_standard_holder">
									<span class="post_date_month"><?php the_time('M')?></span>
									<span class="post_date_day"><?php the_time('d')?></span>
									<span class="post_date_year"><?php the_time('Y')?></span>
								</div>
								<?php } ?>
								<?php
								if ($blog_show_comments == 'yes'){ ?>
								<div class="post_comments_standard_holder">
									<div class="post_comments_holder">
										<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
											<span class="post_comments_number"><?php comments_number('0 ', '1 ', '% '); ?></span>
											<span class="post_comments_text"><?php comments_number(__('comments','eltd'),__('comment','eltd'),__('comments','eltd') ); ?></span>
										</a>
									</div>
								</div>
								<?php }
								?>
							</div>
						</div>
					</div>	
				<?php } ?>				
				<div class="post_content_column text-wrapper <?php  if (!has_post_thumbnail()) echo " split_column_full_width";?>">
					<div class="audio_image">
						<audio class="blog_audio" src="<?php echo esc_url(get_post_meta(get_the_ID(), "audio_link", true)) ?>" controls="controls">
							<?php _e("Your browser don't support audio player","eltd"); ?>
						</audio>
					</div>
					<div class="post_text">
						<div class="post_text_inner">
							<h2>
								<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
							</h2>
							<?php if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes" || $blog_show_like == "yes") { ?>
								<div class="post_info">
									<?php eltd_moose_post_info(array('author' => $blog_show_author, 'share' => $blog_show_social_share, 'category' => $blog_show_categories, 'like' => $blog_show_like)); ?>
								</div>
							<?php } ?>
							<?php
								eltd_moose_excerpt();
                                eltd_moose_read_more_button('blog_split_column_read_more_button',$blog_read_more_button_classes);
                            ?>
							<?php if(isset($eltd_moose_options['blog_split_column_show_share']) && $eltd_moose_options['blog_split_column_show_share'] == "yes" && $blog_social_share_type == "list") {
								echo do_shortcode('[no_social_share_list]'); // XSS OK
							}; ?>	
						</div>
					</div>
				</div>	
			</div>
		</article>
		<?php
		break;
	case "link":
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">
				<?php if ( has_post_thumbnail() ) { ?>
					<div class="post_content_column">
						<div class="post_image">
							<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>">
                                <?php echo wp_kses($image_html, array(
                                    'img' => array(
                                        'src' => true,
                                        'alt' => true,
                                        'width' => true,
                                        'height' => true,
                                        'draggable' => true
                                    )
                                )); ?>
							</a>
							<div class="post_corner_info_holder">
								<?php
								if ($blog_show_date == 'yes'){ ?>
								<div class="post_date_standard_holder">
									<span class="post_date_month"><?php the_time('M')?></span>
									<span class="post_date_day"><?php the_time('d')?></span>
									<span class="post_date_year"><?php the_time('Y')?></span>
								</div>
								<?php } ?>
								<?php
								if ($blog_show_comments == 'yes'){ ?>
								<div class="post_comments_standard_holder">
									<div class="post_comments_holder">
										<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
											<span class="post_comments_number"><?php comments_number('0 ', '1 ', '% '); ?></span>
											<span class="post_comments_text"><?php comments_number(__('comments','eltd'),__('comment','eltd'),__('comments','eltd') ); ?></span>
										</a>
									</div>
								</div>
								<?php }
								?>
							</div>
						</div>
					</div>	
				<?php } ?>
				<div class="post_content_column text-wrapper<?php  if (!has_post_thumbnail()) echo " split_column_full_width";?>">
					<div class="post_text">
						<div class="post_text_inner">
							<?php if ($blog_show_ql_icon_mark == "yes") { ?>
								<div class="post_info_link_mark">
									<span aria-hidden="true" class="icon_link link_mark"></span>
								</div>
							<?php } ?>
							<div class="post_title<?php echo esc_attr($blog_title_holder_icon_class); ?>">
								<h3>
									<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
								</h3>
							</div>
							<?php if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes" || $blog_show_like == "yes") { ?>
								<div class="post_info">
									<?php eltd_moose_post_info(array('author' => $blog_show_author, 'share' => $blog_show_social_share, 'category' => $blog_show_categories, 'like' => $blog_show_like)); ?>
								</div>
							<?php } ?>
							<?php if(isset($eltd_moose_options['blog_split_column_show_share']) && $eltd_moose_options['blog_split_column_show_share'] == "yes" && $blog_social_share_type == "list") {
								echo do_shortcode('[no_social_share_list]'); // XSS OK
							}; ?>
						</div>
					</div>
				</div>	
			</div>
		</article>
		<?php
		break;
	case "gallery":
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">
				<div class="post_content_column">
					<div class="post_image">
						<?php get_template_part('templates/blog/parts/post-format-gallery-slider'); ?>
						<div class="post_corner_info_holder">
							<?php
							if ($blog_show_date == 'yes'){ ?>
							<div class="post_date_standard_holder">
								<span class="post_date_month"><?php the_time('M')?></span>
								<span class="post_date_day"><?php the_time('d')?></span>
								<span class="post_date_year"><?php the_time('Y')?></span>
							</div>
							<?php } ?>
							<?php
							if ($blog_show_comments == 'yes'){ ?>
							<div class="post_comments_standard_holder">
								<div class="post_comments_holder">
									<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
										<span class="post_comments_number"><?php comments_number('0 ', '1 ', '% '); ?></span>
										<span class="post_comments_text"><?php comments_number(__('comments','eltd'),__('comment','eltd'),__('comments','eltd') ); ?></span>
									</a>
								</div>
							</div>
							<?php }
							?>
						</div>
					</div>
				</div>
				<div class="post_content_column text-wrapper<?php  if (!has_post_thumbnail()) echo " split_column_full_width";?>">
					<div class="post_text">
						<div class="post_text_inner">
							<h2>
								<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
							</h2>
							<?php if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes" || $blog_show_like == "yes") { ?>
								<div class="post_info">
									<?php eltd_moose_post_info(array('author' => $blog_show_author, 'share' => $blog_show_social_share, 'category' => $blog_show_categories, 'like' => $blog_show_like)); ?>
								</div>
							<?php } ?>
							<?php
								eltd_moose_excerpt();
                                eltd_moose_read_more_button('blog_split_column_read_more_button',$blog_read_more_button_classes);
                            ?>
							<?php if(isset($eltd_moose_options['blog_split_column_show_share']) && $eltd_moose_options['blog_split_column_show_share'] == "yes" && $blog_social_share_type == "list") {
								echo do_shortcode('[no_social_share_list]'); // XSS OK
							}; ?>	
						</div>
					</div>
				</div>
			</div>	
		</article>
		<?php
		break;
	case "quote":
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">
				<?php if ( has_post_thumbnail() ) { ?>
					<div class="post_content_column">
						<div class="post_image">
							<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>">
                                <?php echo wp_kses($image_html, array(
                                    'img' => array(
                                        'src' => true,
                                        'alt' => true,
                                        'width' => true,
                                        'height' => true,
                                        'draggable' => true
                                    )
                                )); ?>
							</a>
							<div class="post_corner_info_holder">
								<?php
								if ($blog_show_date == 'yes'){ ?>
								<div class="post_date_standard_holder">
									<span class="post_date_month"><?php the_time('M')?></span>
									<span class="post_date_day"><?php the_time('d')?></span>
									<span class="post_date_year"><?php the_time('Y')?></span>
								</div>
								<?php } ?>
								<?php
								if ($blog_show_comments == 'yes'){ ?>
								<div class="post_comments_standard_holder">
									<div class="post_comments_holder">
										<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
											<span class="post_comments_number"><?php comments_number('0 ', '1 ', '% '); ?></span>
											<span class="post_comments_text"><?php comments_number(__('comments','eltd'),__('comment','eltd'),__('comments','eltd') ); ?></span>
										</a>
									</div>
								</div>
								<?php }
								?>
							</div>
						</div>
					</div>	
				<?php } ?>
				<div class="post_content_column text-wrapper<?php  if (!has_post_thumbnail()) echo " split_column_full_width";?>">
					<div class="post_text">
						<div class="post_text_inner">
							<?php if ($blog_show_ql_icon_mark == "yes") { ?>
								<div class="post_info_quote_mark">
									<span aria-hidden="true" class="icon_quotations quote_mark"></span>
								</div>
							<?php } ?>
							<div class="post_title<?php echo esc_attr($blog_title_holder_icon_class); ?>">
								<h3>
									<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php echo esc_html(get_post_meta(get_the_ID(), "quote_format", true)); ?></a>
								</h3>
								<span class="quote_author"><?php the_title(); ?></span>
							</div>
							<?php if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes" || $blog_show_like == "yes") { ?>
								<div class="post_info">
									<?php eltd_moose_post_info(array('author' => $blog_show_author, 'share' => $blog_show_social_share, 'category' => $blog_show_categories, 'like' => $blog_show_like)); ?>
								</div>
							<?php } ?>
							<?php if(isset($eltd_moose_options['blog_split_column_show_share']) && $eltd_moose_options['blog_split_column_show_share'] == "yes" && $blog_social_share_type == "list") {
								echo do_shortcode('[no_social_share_list]'); // XSS OK
							}; ?>
						</div>
					</div>
				</div>	
			</div>
		</article>
		<?php
		break;
	default:
		?>
			<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
				<div class="post_content_holder">
					<?php if ( has_post_thumbnail() ) { ?>
						<div class="post_content_column">						
								<div class="post_image">
									<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>">
                                        <?php echo wp_kses($image_html, array(
                                            'img' => array(
                                                'src' => true,
                                                'alt' => true,
                                                'width' => true,
                                                'height' => true,
                                                'draggable' => true
                                            )
                                        )); ?>
									</a>
									<div class="post_corner_info_holder">
										<?php
										if ($blog_show_date == 'yes'){ ?>
										<div class="post_date_standard_holder">
											<span class="post_date_month"><?php the_time('M')?></span>
											<span class="post_date_day"><?php the_time('d')?></span>
											<span class="post_date_year"><?php the_time('Y')?></span>
										</div>
										<?php } ?>
										<?php
										if ($blog_show_comments == 'yes'){ ?>
										<div class="post_comments_standard_holder">
											<div class="post_comments_holder">
												<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
													<span class="post_comments_number"><?php comments_number('0 ', '1 ', '% '); ?></span>
													<span class="post_comments_text"><?php comments_number(__('comments','eltd'),__('comment','eltd'),__('comments','eltd') ); ?></span>
												</a>
											</div>
										</div>
										<?php }
										?>
									</div>
								</div>
						</div>
					<?php } ?>					
					<div class="post_content_column text-wrapper<?php  if (!has_post_thumbnail()) echo " split_column_full_width";?>">
						<div class="post_text">
							<div class="post_text_inner">
								<h2>
									<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
								</h2>
								<?php if($blog_show_author == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes" || $blog_show_like == "yes") { ?>
									<div class="post_info">
										<?php eltd_moose_post_info(array('author' => $blog_show_author, 'share' => $blog_show_social_share, 'category' => $blog_show_categories, 'like' => $blog_show_like)); ?>
									</div>
								<?php } ?>
								<?php
									eltd_moose_excerpt();
                                    eltd_moose_read_more_button('blog_split_column_read_more_button',$blog_read_more_button_classes);
                                ?>
								<?php if(isset($eltd_moose_options['blog_split_column_show_share']) && $eltd_moose_options['blog_split_column_show_share'] == "yes" && $blog_social_share_type == "list") {
									echo do_shortcode('[no_social_share_list]'); // XSS OK
								}; ?>
							</div>
						</div>
					</div>
				</div>
			</article>
		<?php
}
?>

