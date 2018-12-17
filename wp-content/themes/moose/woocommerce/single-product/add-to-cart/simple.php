<?php
/**
 * Simple product add to cart
 *
 * This template can be overridden by copying it to yourtheme/woocommerce/single-product/add-to-cart/simple.php.
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

global $product; $eltd_moose_options;

if ( ! $product->is_purchasable() ) {
	return;
}

echo wc_get_stock_html( $product );

?>

<?php if ( $product->is_in_stock() ) : ?>
	
	<?php do_action( 'woocommerce_before_add_to_cart_form' ); ?>

	<form class="cart" method="post" enctype='multipart/form-data'>
        <div class="cart_inner_holder">
	 	<?php
			/**
			 * @since 2.1.0.
			 */
			do_action( 'woocommerce_before_add_to_cart_button' );

			/**
			 * @since 3.0.0.
			 */
			do_action( 'woocommerce_before_add_to_cart_quantity' );
		?>

	 	<?php
			woocommerce_quantity_input( array(
				'min_value'   => apply_filters( 'woocommerce_quantity_input_min', $product->get_min_purchase_quantity(), $product ),
				'max_value'   => apply_filters( 'woocommerce_quantity_input_max', $product->get_max_purchase_quantity(), $product ),
				'input_value' => isset( $_POST['quantity'] ) ? wc_stock_amount( $_POST['quantity'] ) : $product->get_min_purchase_quantity(),
			) );

		/**
		 * @since 3.0.0.
		 */
		do_action( 'woocommerce_after_add_to_cart_quantity' );
	 	?>
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
	 	<input type="hidden" name="add-to-cart" value="<?php echo esc_attr( $product->get_id() ); ?>" />
		<button type="submit" class="single_add_to_cart_button transparent qbutton button alt <?php echo esc_attr($button_classes)?> qbutton_with_icon icon_right">
			<span class="text_holder">
				<span class="a_overlay" ></span>
				<span><?php echo esc_html($product->single_add_to_cart_text()); ?></span>
				<span  class="hidden_text"><?php echo esc_html($product->single_add_to_cart_text()); ?></span>
			</span>
			<span class="icon_holder">
				<span><i class="eltd_icon_simple_line_icon icon-basket button_icon" style="width: inherit; "></i></span>
				<span class="hidden_icon"><i class="eltd_icon_simple_line_icon icon-basket button_icon" style="width: inherit; "></i></span>					
			</span>
		</button>
		<?php do_action( 'woocommerce_after_add_to_cart_button' ); ?>
        </div>
	</form>

	<?php do_action( 'woocommerce_after_add_to_cart_form' ); ?>

<?php endif; ?>