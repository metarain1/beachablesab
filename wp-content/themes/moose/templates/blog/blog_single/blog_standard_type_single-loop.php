<?php
global $eltd_moose_options;

$blog_show_comments = "yes";
if (isset($eltd_moose_options['blog_single_show_comments'])) {
    $blog_show_comments = $eltd_moose_options['blog_single_show_comments'];
}
$blog_show_author = "yes";
if (isset($eltd_moose_options['blog_author_info'])) {
    $blog_show_author = $eltd_moose_options['blog_author_info'];
}
$blog_show_like = "yes";
if (isset($eltd_moose_options['blog_single_show_like'])) {
    $blog_show_like = $eltd_moose_options['blog_single_show_like'];
}
$blog_show_date = "yes";
if (isset($eltd_moose_options['blog_single_show_date'])) {
    $blog_show_date = $eltd_moose_options['blog_single_show_date'];
}

$blog_social_share_type = "dropdown";
if(isset($eltd_moose_options['blog_single_select_share_option'])){
	$blog_social_share_type = $eltd_moose_options['blog_single_select_share_option'];
}
$blog_show_social_share = "yes";
if (isset($eltd_moose_options['enable_social_share'])&& ($eltd_moose_options['enable_social_share']) =="yes"){
    if (isset($eltd_moose_options['post_types_names_post'])&& $eltd_moose_options['post_types_names_post'] =="post"){
        if (isset($eltd_moose_options['blog_single_show_social_share'])) {
            $blog_show_social_share = $eltd_moose_options['blog_single_show_social_share'];
        }
    }
}
$blog_show_categories = "yes";
if (isset($eltd_moose_options['blog_single_show_category'])) {
    $blog_show_categories = $eltd_moose_options['blog_single_show_category'];
}
$blog_show_ql_icon = "yes";
$blog_title_holder_icon_class = "";
if (isset($eltd_moose_options['blog_single_show_ql_icon'])) {
    $blog_show_ql_icon = $eltd_moose_options['blog_single_show_ql_icon'];
}

if($blog_show_ql_icon == "yes"){
	$blog_title_holder_icon_class = " with_icon_right";
}

$blog_ql_background_image = "no";
if(isset($eltd_moose_options['blog_standard_type_ql_background_image'])){
	$blog_ql_background_image = $eltd_moose_options['blog_standard_type_ql_background_image'];
}
$background_image_object = wp_get_attachment_image_src(get_post_thumbnail_id( get_the_ID()), 'eltd-moose-blog-image-format-link-quote');
$background_image_src = $background_image_object[0];

$_post_format = get_post_format();

$background_image_html = '';
$background_image_html_class = '';
if($blog_ql_background_image == "yes"){
	if(get_post_meta(get_the_ID(), "eltd_hide-featured-image", true) != "yes"){		
		if($_post_format == "quote"){
			$background_image_html_class .=  ' quote_image';
		}elseif($_post_format == "link"){
			$background_image_html_class .=  ' link_image';
		}
		$background_image_html = 'background-image: url(' . esc_url($background_image_src) . ')';
	}
}
$gallery_position = "above_post_content";
if(get_post_meta(get_the_ID(), "gallery_position", true) !== ""){
	$gallery_position = get_post_meta(get_the_ID(), "gallery_position", true);
}

$blog_image_size = 'full';
if( isset($eltd_moose_options['blog_single_image_size']) && $eltd_moose_options['blog_single_image_size'] !== '') {
    $blog_image_size = 'eltd-moose-'.$eltd_moose_options['blog_single_image_size'];

}

if( $blog_image_size == 'custom'
    && isset($eltd_moose_options['blog_single_image_size_height']) && $eltd_moose_options['blog_single_image_size_height'] !== ''
    && isset($eltd_moose_options['blog_single_image_size_width']) && $eltd_moose_options['blog_single_image_size_width'] !== '') {

    $image_height = $eltd_moose_options['blog_single_image_size_height'];
    $image_width = $eltd_moose_options['blog_single_image_size_width'];

    $image_html = eltd_moose_generate_thumbnail(get_post_thumbnail_id(get_the_ID()),null,$image_width,$image_height);
}
else{
    $image_html = get_the_post_thumbnail(get_the_ID(), $blog_image_size);
}

?>
<?php
	switch ($_post_format) {
		case "video":
?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">
				<div class ="blog_title_post_info_holder">
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
									<span class="icon-bubble comment_icon"></span>									
								</a>
							</div>
						</div>
						<?php }
						?>
					</div>
					<div class="post_text">
						<div class="post_text_inner">
								<h2>
									<?php the_title(); ?>
								</h2>
								<?php if($blog_show_author == "yes" || $blog_show_categories == "yes" ) { ?>	
									<div class="post_info">
										<?php eltd_moose_post_info( array('author' => $blog_show_author) )?>
										<?php eltd_moose_post_info( array('category' => $blog_show_categories) )?>
									</div>
								<?php } ?>	
						</div>
					</div>					
				</div>
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
				 </div>
				<div class="post_content"><?php the_content(); ?></div>
			</div>
		</article>
<?php
		break;
		case "audio":
?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">				
                <div class ="blog_title_post_info_holder">
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
									<span class="icon-bubble comment_icon"></span>									
								</a>
							</div>
						</div>
						<?php }
						?>
					</div>
					<div class="post_text">
						<div class="post_text_inner">
								<h2>
									<?php the_title(); ?>
								</h2>
								<?php if($blog_show_author == "yes" || $blog_show_categories == "yes" ) { ?>	
									<div class="post_info">
										<?php eltd_moose_post_info( array('author' => $blog_show_author) )?>
										<?php eltd_moose_post_info( array('category' => $blog_show_categories) )?>
									</div>
								<?php } ?>	
						</div>
					</div>					
				</div>
				<?php if(get_post_meta(get_the_ID(), "eltd_hide-featured-image", true) != "yes") {
                     if ( has_post_thumbnail() ) { ?>
                        <div class="post_image">
                            <?php echo wp_kses($image_html, array(
                                'img' => array(
                                    'src' => true,
                                    'alt' => true,
                                    'width' => true,
                                    'height' => true,
                                    'draggable' => true
                                )
                            )); ?>
                        </div>
                <?php }} ?>
				<div class="audio_image">
					<audio class="blog_audio" src="<?php echo esc_url(get_post_meta(get_the_ID(), "audio_link", true)) ?>" controls="controls">
						<?php _e("Your browser don't support audio player","eltd"); ?>
					</audio>
				</div>
				<div class="post_content"><?php the_content(); ?></div>
			</div>
		</article>
<?php
		break;
		case "link":
?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
            <div class="post_content_holder">
                <div class="post_text_columns">
					<div class="post_text<?php echo esc_attr($background_image_html_class); ?>" <?php eltd_moose_inline_style($background_image_html); ?>>
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
										<span class="icon-bubble comment_icon"></span>
									</a>
								</div>
							</div>
							<?php }
							?>
						</div>
						<div class="post_text_inner">
							<?php if ($blog_show_ql_icon == "yes") { ?>
								<div class="post_info_link_mark">
									<span aria-hidden="true" class="icon_link link_mark"></span>
								</div>
							<?php } ?>
							<div class="post_title<?php echo esc_attr($blog_title_holder_icon_class); ?>">
								<?php $title_link = get_post_meta(get_the_ID(), "title_link", true) != '' ? esc_url(get_post_meta(get_the_ID(), "title_link", true)) : 'javascript: void(0)'; ?>
								<h3><a href="<?php echo esc_url($title_link); ?>"><?php the_title(); ?></a></h3>
							</div>							
							<?php if($blog_show_author == "yes" || $blog_show_categories == "yes") { ?>	
								<div class="post_info">
									<?php eltd_moose_post_info( array('author' => $blog_show_author) )?>
									<?php eltd_moose_post_info( array('category' => $blog_show_categories) )?>
								</div>
							<?php } ?>
						</div>
					</div>
					<div class="post_content"><?php the_content(); ?></div>
                </div>
            </div>
        </article>
<?php
		break;
		case "gallery":
?>
		<article id="post-<?php the_ID(); ?>">
			<div class="post_content_holder">
				<div class ="blog_title_post_info_holder">
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
									<span class="icon-bubble comment_icon"></span>									
								</a>
							</div>
						</div>
						<?php }
						?>
					</div>
					<div class="post_text">
						<div class="post_text_inner">
								<h2>
									<?php the_title(); ?>
								</h2>
								<?php if($blog_show_author == "yes" || $blog_show_categories == "yes" ) { ?>	
									<div class="post_info">
										<?php eltd_moose_post_info( array('author' => $blog_show_author) )?>
										<?php eltd_moose_post_info( array('category' => $blog_show_categories) )?>
									</div>
								<?php } ?>	
						</div>
					</div>					
				</div>
				<div class = "post_image">
					<?php get_template_part('templates/blog/parts/post-format-gallery-slider'); ?>
				</div>
				<div class="post_content"><?php the_content(); ?></div>
            </div>
		</article>
<?php
		break;
		case "quote":
?>
            <article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
                <div class="post_content_holder">
                    <div class="post_text_columns">
                        <div class="post_text<?php echo esc_attr($background_image_html_class); ?>" <?php eltd_moose_inline_style($background_image_html); ?>>
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
											<span class="icon-bubble comment_icon"></span>
										</a>
									</div>
								</div>
								<?php }
								?>
							</div>
                            <div class="post_text_inner">
								<?php if ($blog_show_ql_icon == "yes") { ?>
									<div class="post_info_quote_mark">
										<span aria-hidden="true" class="icon_quotations quote_mark"></span>
									</div>
								<?php } ?>
								<div class="post_title<?php echo esc_attr($blog_title_holder_icon_class); ?>">
									<h3>
										<?php echo esc_html(get_post_meta(get_the_ID(), "quote_format", true)); ?>
									</h3>								
									<span class="quote_author">&mdash; <?php the_title(); ?></span>
								</div>
								<?php if($blog_show_author == "yes" || $blog_show_categories == "yes") { ?>	
									<div class="post_info">
										<?php eltd_moose_post_info( array('author' => $blog_show_author) )?>
										<?php eltd_moose_post_info( array('category' => $blog_show_categories) )?>
									</div>
								<?php } ?>  
                            </div>
                        </div>
						<div class="post_content"><?php the_content(); ?></div>
                    </div>
                </div>
            </article>
<?php
		break;
		default:
?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">
				<div class ="blog_title_post_info_holder">
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
									<span class="icon-bubble comment_icon"></span>									
								</a>
							</div>
						</div>
						<?php }
						?>
					</div>
					<div class="post_text">
						<div class="post_text_inner">
								<h2>
									<?php the_title(); ?>
								</h2>
								<?php if($blog_show_author == "yes" || $blog_show_categories == "yes" ) { ?>	
									<div class="post_info">
										<?php eltd_moose_post_info( array('author' => $blog_show_author) )?>
										<?php eltd_moose_post_info( array('category' => $blog_show_categories) )?>
									</div>
								<?php } ?>	
						</div>
					</div>					
				</div>
                <?php if(get_post_meta(get_the_ID(), "eltd_hide-featured-image", true) != "yes") {
                    if ( has_post_thumbnail() ) { ?>
                        <div class="post_image">
                            <?php echo wp_kses($image_html, array(
                                'img' => array(
                                    'src' => true,
                                    'alt' => true,
                                    'width' => true,
                                    'height' => true,
                                    'draggable' => true
                                )
                            )); ?>							
                        </div>
				<?php }} ?>
				<div class="post_content"><?php the_content(); ?></div>				
			</div>
		</article>
<?php
}
?>