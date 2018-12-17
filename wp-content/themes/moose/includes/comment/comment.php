<?php

if (!function_exists('eltd_moose_comment')) {
function eltd_moose_comment($comment, $args, $depth) {
	$GLOBALS['comment'] = $comment; 

	global $eltd_moose_options, $post;
	$title_tag="h5";

	if(isset($eltd_moose_options['blog_single_title_tags'])){
		$title_tag = $eltd_moose_options['blog_single_title_tags'];
	}
	$headings_array = array('h2', 'h3', 'h4', 'h5', 'h6');
	//get correct heading value
	$title_tag = (in_array($title_tag, $headings_array)) ? $title_tag : 'h5';

	$is_pingback_comment = $comment->comment_type == 'pingback';
	$is_author_comment  = $post->post_author == $comment->user_id;

	$comment_class = 'comment clearfix';

	if($is_author_comment) {
		$comment_class .= ' post_author_comment';
	}

	if($is_pingback_comment) {
		$comment_class .= ' pingback-comment';
	}

	?>

	<li>
		<div class="<?php echo esc_attr($comment_class); ?>">
			<span class ="comment_connect_line"></span>
			<?php if(!$is_pingback_comment) { ?>
				<div class="image"> <?php echo eltd_moose_kses_img(get_avatar($comment, 102)); ?> </div>
			<?php } ?>
			<div class ="text_wrapper">	
				<div class="text">
					<div class = "comment_left_arrow" ></div>
					<div class = "comment_top_arrow" ></div>				
					<div class="comment_info">
						<<?php echo esc_attr($title_tag);?> class="name">
							<?php if($is_pingback_comment) { _e('Pingback:', 'eltd'); } ?>
							<?php echo wp_kses_post(get_comment_author_link()); ?>
							<?php if($is_author_comment) { ?>
								<i class="fa fa-user post-author-comment-icon"></i>
							<?php } ?>
						</<?php echo esc_attr($title_tag); ?>>					
					</div>
					<?php if(!$is_pingback_comment) { ?>
						<div class="text_holder" id="comment-<?php echo comment_ID(); ?>">
							<?php comment_text(); ?>
						</div>
						<div class = "comment_info_bottom clearfix">
							<div class="comment_date">
								<span class = "icon-calendar comment_date_icon"></span>
								<span class ="comment_date_format"><?php comment_time('F j, Y'); ?> </span>
							</div>
							<div class = "comment-reply-wrapper">
								<span class="icon-action-undo comment_reply_icon"></span>
								<?php							
									comment_reply_link( array_merge( $args, array('depth' => $depth, 'max_depth' => $args['max_depth']) ) );
									edit_comment_link();
								?>
							</div>
						</div>	
					<?php } ?>
				</div>
			</div>	
		</div>
	<?php //li tag will be closed by WordPress after looping through child elements ?>

	<?php
	}
}
?>