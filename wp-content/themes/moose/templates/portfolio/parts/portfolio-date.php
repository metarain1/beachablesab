<?php
global $eltd_moose_options;

//get portfolio date value
$portfolio_hide_date = "";
if(isset($eltd_moose_options['portfolio_hide_date'])){
	$portfolio_hide_date = $eltd_moose_options['portfolio_hide_date'];
}

if($portfolio_hide_date != "yes"){

    $portfolio_info_tag             = 'h6';
    $portfolio_info_style           = '';

    //set info tag
    if (isset($eltd_moose_options['portfolio_info_tag']) && $eltd_moose_options['portfolio_title_tag'] != "" ) {
    	$portfolio_info_tag = $eltd_moose_options['portfolio_info_tag'];
    }

    //set style for info
    if ((isset($eltd_moose_options['portfolio_info_margin_bottom']) && $eltd_moose_options['portfolio_info_margin_bottom'] != '')
    || (isset($eltd_moose_options['portfolio_info_color']) && !empty($eltd_moose_options['portfolio_info_color']))) {

		if (isset($eltd_moose_options['portfolio_info_margin_bottom']) && $eltd_moose_options['portfolio_info_margin_bottom'] != '') {
			$portfolio_info_style .= 'margin-bottom:' . esc_attr($eltd_moose_options['portfolio_info_margin_bottom']) . 'px;';
		}

		if (isset($eltd_moose_options['portfolio_info_color']) && !empty($eltd_moose_options['portfolio_info_color'])) {
			$portfolio_info_style .= 'color:'.esc_attr($eltd_moose_options['portfolio_info_color']).';';
		}

    }

   ?>


	<div class="info portfolio_single_custom_date clearfix">
		<<?php echo esc_attr($portfolio_info_tag); ?> class="info_section_title" <?php eltd_moose_inline_style($portfolio_info_style); ?>><?php _e('Date','eltd'); ?></<?php echo esc_attr($portfolio_info_tag); ?>>
        <p><?php the_time(get_option('date_format')); ?></p>
	</div>
<?php } ?>