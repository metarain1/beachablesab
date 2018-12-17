<?php
global $eltd_moose_options;
?>

<?php if(isset($eltd_moose_options['enable_social_share'])  && $eltd_moose_options['enable_social_share'] == "yes") { ?>
	<div class="portfolio_social_holder">
		<?php echo do_shortcode('[no_social_share]'); // XSS OK ?>
	</div> <!-- close div.portfolio_social_holder -->
<?php } ?>