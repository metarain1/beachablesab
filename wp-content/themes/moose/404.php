<?php 
	global $eltd_moose_options;
?>

<?php get_header(); ?>

	<?php get_template_part( 'title' ); ?>

	<div class="container">
	<?php if($eltd_moose_options['overlapping_content'] == 'yes') {?>
		<div class="overlapping_content"><div class="overlapping_content_inner">
	<?php } ?>
		<div class="container_inner eltd_404_page default_template_holder">
			<div class="page_not_found">
				<h2><?php if($eltd_moose_options['404_title'] != ""): echo esc_html($eltd_moose_options['404_title']); else: ?> <?php _e('404', 'eltd'); ?> <?php endif;?></h2>

                <h4><?php if($eltd_moose_options['404_text'] != ""): echo esc_html($eltd_moose_options['404_text']); else: ?> <?php _e('NOT FOUND', 'eltd'); ?> <?php endif;?></h4>


                <a style="" class="qbutton transparent qbutton_with_icon icon_right rotate_icon animate_button" target="_self" href="<?php echo esc_url(home_url('/')); ?>/">
                    <span class="text_holder"><span class="a_overlay"></span><span><?php if($eltd_moose_options['404_backlabel'] != ""): echo esc_html($eltd_moose_options['404_backlabel']); else: ?> <?php _e('Back to home', 'eltd'); ?> <?php endif;?></span><span class="hidden_text"><?php if($eltd_moose_options['404_backlabel'] != ""): echo esc_html($eltd_moose_options['404_backlabel']); else: ?> <?php _e('Back to home', 'eltd'); ?> <?php endif;?></span></span>
                    <span class="icon_holder"><span><i class="eltd_icon_simple_line_icon icon-arrow-up button_icon"></i></span><span class="hidden_icon"><i class="eltd_icon_simple_line_icon icon-arrow-up button_icon"></i></span></span>
                </a>


			</div>
		</div>
		<?php if($eltd_moose_options['overlapping_content'] == 'yes') {?>
				</div></div>
		<?php } ?>
	</div>
<?php get_footer(); ?>