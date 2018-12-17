<div class="date">
	<?php if(!eltd_moose_post_has_title()) { ?>
		<a href="<?php the_permalink() ?>">
	<?php } ?>

<!--	<span class="date_text">--><?php //_e('Posted on','eltd'); ?><!--</span>-->
	<span class="date_text">
		<i class="icon-calendar"></i>
	</span>
	<?php the_time(get_option('date_format')); ?>

	<?php if(!eltd_moose_post_has_title()) { ?>
		</a>
	<?php } ?>
</div>