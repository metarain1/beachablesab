<!--<div class="post_comments_holder"><a class="post_comments" href="--><?php //comments_link(); ?><!--" target="_self">--><?php //comments_number('0 ' . __('Comments','eltd'), '1 '.__('Comment','eltd'), '% '.__('Comments','eltd') ); ?><!--</a></div>-->
<div class="post_comments_holder">
	<i class="icon-bubble"></i>
	<a class="post_comments" href="<?php comments_link(); ?>" target="_self">
		<?php comments_number('0 ' . __('Comments','eltd'), '1 '.__('Comment','eltd'), '% '.__('Comments','eltd') ); ?>
	</a>
</div>