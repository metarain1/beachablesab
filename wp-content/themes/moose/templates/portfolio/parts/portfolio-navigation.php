<?php
global $eltd_moose_options;

$enable_navigation = true;
if (isset($eltd_moose_options['portfolio_hide_pagination']) && $eltd_moose_options['portfolio_hide_pagination'] == "yes"){
    $enable_navigation = false;
}

$navigation_through_category = false;
if (isset($eltd_moose_options['portfolio_navigation_through_same_category']) && $eltd_moose_options['portfolio_navigation_through_same_category'] == "yes")
    $navigation_through_category = true;
?>

<?php

$icon_navigation_class = "fa fa-angle-";

if (isset($eltd_moose_options['portfolio_single_navigation_arrows_type']) && $eltd_moose_options['portfolio_single_navigation_arrows_type'] != '') {
    $icon_navigation_class = $eltd_moose_options['portfolio_single_navigation_arrows_type'];
}

$direction_nav_classes = eltd_moose_horizontal_slider_icon_classes($icon_navigation_class);


$back_to_button_code = '<span class="icon-grid"></span>';

if ($eltd_moose_options['portfolio_back_to_button_choice'] == 'icon'){
    if (isset($eltd_moose_options['portfolio_back_to_button_icon']) && $eltd_moose_options['portfolio_back_to_button_icon'] != '') {
        $back_to_button = $eltd_moose_options['portfolio_back_to_button_icon'];
        $back_to_button_code = '<span class="' . $back_to_button . '"></span>';
    }
}
elseif ($eltd_moose_options['portfolio_back_to_button_choice'] == 'custom_icon') {
    if (isset($eltd_moose_options['portfolio_back_to_button_custom_icon']) && $eltd_moose_options['portfolio_back_to_button_custom_icon'] != '') {
        $back_to_button_code = '<span class="portfolio_single_nav_custom"></span>';
    }
}


?>

<?php if($enable_navigation){ ?>
    <div class="portfolio_navigation">
        <div class="portfolio_navigation_inner">
            <?php if(get_previous_post() != ""){ ?>  
                <div class="portfolio_prev">
                    <?php
                    if($navigation_through_category){
                        previous_post_link('%link','<span class="' .$direction_nav_classes['left_icon_class']. '"></span><span class="hidden_left_nav ' .$direction_nav_classes['left_icon_class']. '"></span>', true,'','portfolio_category');
                    } else {
                        previous_post_link('%link','<span class="' .$direction_nav_classes['left_icon_class']. '"></span><span class="hidden_left_nav ' .$direction_nav_classes['left_icon_class']. '"></span>');
                    }
                    ?>
                </div> <!-- close div.portfolio_prev -->
                <span class="portfolio_prev_label"><?php _e("Previous", "eltd") ?></span>
            <?php } ?>
            <?php if(get_post_meta(get_the_ID(), "eltd_choose-portfolio-list-page", true) != "") { ?>
                <div class="portfolio_button">
                    <a href="<?php echo esc_url(get_permalink(get_post_meta(get_the_ID(), "eltd_choose-portfolio-list-page", true))); ?>">
                    <?php echo wp_kses($back_to_button_code,array(
                        'span' => array("class" => true),
                        'i' => array("class"=> true),
                    ));?>
                    <?php echo wp_kses($back_to_button_code,array(
                        'span' => array("class" => true),
                        'i' => array("class"=> true),
                    ));?>
                </a>
                </div> <!-- close div.portfolio_button -->
            <?php } ?>
            <?php if(get_next_post() != ""){ ?>
                <div class="portfolio_next">
                    <?php
                    if($navigation_through_category){
                        next_post_link('%link','<span class="' .$direction_nav_classes['right_icon_class']. '"></span><span class="hidden_right_nav ' .$direction_nav_classes['right_icon_class']. '"></span>', true,'','portfolio_category');
                    } else {
                        next_post_link('%link','<span class="' .$direction_nav_classes['right_icon_class']. '"></span><span class="hidden_right_nav ' .$direction_nav_classes['right_icon_class']. '"></span>');
                    }
                    ?>
                </div> <!-- close div.portfolio_next -->
                <span class="portfolio_next_label"><?php _e("Next", "eltd") ?></span>
            <?php } ?>
        </div>
    </div> <!-- close div.portfolio_navigation -->
<?php } ?>	