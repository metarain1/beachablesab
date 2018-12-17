<?php
/**
 * External product add to cart
 *
 * This template can be overridden by copying it to yourtheme/woocommerce/single-product/add-to-cart/external.php.
 *
 * HOWEVER, on occasion WooCommerce will need to update template files and you
 * (the theme developer) will need to copy the new files to your theme to
 * maintain compatibility. We try to do this as little as possible, but it does
 * happen. When this occurs the version of the template file will be bumped and
 * the readme will list any important changes.
 *
 * @see https://docs.woocommerce.com/document/template-structure/
 * @package WooCommerce/Templates
 * @version 3.4.0
 */

defined( 'ABSPATH' ) || exit;

?>

<?php do_action( 'woocommerce_before_add_to_cart_button' ); ?>
<?php 
	global $eltd_moose_options; $eltdIconCollections ;
	$button_classes = '';
	if(isset($eltd_moose_options['button_hover_animation'])){
		if($eltd_moose_options['button_hover_animation'] !== ''){
			$button_classes .= " {$eltd_moose_options['button_hover_animation']}";
			$button_classes .= " animate_button";
		}
	}
?>
<p class="cart">
	<a href="<?php echo esc_url( $product_url ); ?>" rel="nofollow" class="single_add_to_cart_button transparent qbutton button alt <?php echo esc_attr($button_classes)?> qbutton_with_icon icon_right">
		<span class="text_holder">
			<span class="a_overlay" ></span>
			<span><?php echo esc_html($button_text); ?></span>
			<span  class="hidden_text"><?php echo esc_html($button_text); ?></span>
		</span>
		<span class="icon_holder">
			<span><i class="eltd_icon_simple_line_icon icon-basket button_icon" style="width: inherit; "></i></span>
			<span class="hidden_icon"><i class="eltd_icon_simple_line_icon icon-basket button_icon" style="width: inherit; "></i></span>					
		</span>
	</a>
</p>
<?php do_action( 'woocommerce_after_add_to_cart_button' ); ?>