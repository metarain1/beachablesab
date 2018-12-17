<?php
/**
 * Single Product Meta
 *
 * This template can be overridden by copying it to yourtheme/woocommerce/single-product/meta.php.
 *
 * HOWEVER, on occasion WooCommerce will need to update template files and you
 * (the theme developer) will need to copy the new files to your theme to
 * maintain compatibility. We try to do this as little as possible, but it does
 * happen. When this occurs the version of the template file will be bumped and
 * the readme will list any important changes.
 *
 * @see 	    https://docs.woocommerce.com/document/template-structure/
 * @author 		WooThemes
 * @package 	WooCommerce/Templates
 * @version     3.0.0
 */

if ( ! defined( 'ABSPATH' ) ) {
	exit; // Exit if accessed directly
}

global  $product;

?>
<div class="product_meta">

	<?php do_action( 'woocommerce_product_meta_start' ); ?>

	<?php if ( wc_product_sku_enabled() && ( $product->get_sku() || $product->is_type( 'variable' ) ) ) : ?>

		<span class="sku_wrapper"><?php _e( 'SKU:', 'woocommerce' ); ?> <span class="sku"><?php echo ( $sku = $product->get_sku() ) ? $sku : __( 'N/A', 'woocommerce' ); ?></span></span>

	<?php endif; ?>

	<?php echo wp_kses(wc_get_product_category_list( $product->get_id(), '<span>,</span>  ', '<span class="posted_in"><span>' . _n( 'Category:', 'Categories:', count( $product->get_category_ids() ), 'woocommerce' ) . '</span>','</span>' ), array(
		'span' => array(
			'class' => true,
			'id' => true,
			'title' => true
		),
		'a' => array(
			'href' => true,
			'rel' => true,
			'id' => true,
			'class' => true,
			'title' => true
		)
	)); ?>

	<?php echo wp_kses(wc_get_product_tag_list( $product->get_id(), '<span>,</span>  ', '<span class="tagged_as"><span>' . _n( 'Tag:', 'Tags:', count( $product->get_tag_ids() ), 'woocommerce' ) . '</span>', '</span>' ), array(
		'span' => array(
			'class' => true,
			'id' => true,
			'title' => true
		),
		'a' => array(
			'href' => true,
			'rel' => true,
			'id' => true,
			'class' => true,
			'title' => true
		)
	)); ?>

	<?php do_action( 'woocommerce_product_meta_end' ); ?>

</div>