<?php
/**
 * Single Product Thumbnails
 *
 * This template can be overridden by copying it to yourtheme/woocommerce/single-product/product-thumbnails.php.
 *
 * HOWEVER, on occasion WooCommerce will need to update template files and you
 * (the theme developer) will need to copy the new files to your theme to
 * maintain compatibility. We try to do this as little as possible, but it does
 * happen. When this occurs the version of the template file will be bumped and
 * the readme will list any important changes.
 * @see 	    https://docs.woocommerce.com/document/template-structure/
 * @author 		WooThemes
 * @package 	WooCommerce/Templates
 * @version     3.3.2
 */

defined( 'ABSPATH' ) || exit;

global $post, $product;

$attachment_ids = $product->get_gallery_image_ids();

if ( $attachment_ids && has_post_thumbnail() ) {
	?>

	<div class="single-product-slider-thumbs">
		<?php
		if ( has_post_thumbnail() ) {
			$image = get_the_post_thumbnail( $post->ID, apply_filters('single_product_small_thumbnail_size', 'shop_thumbnail') );
			echo apply_filters( 'woocommerce_single_product_image_thumbnail_html', sprintf( '%s', $image ) );
		} else {
			echo apply_filters( 'woocommerce_single_product_image_thumbnail_html', sprintf( '<img src="%s" alt="%s" />', wc_placeholder_img_src(), __( 'Placeholder', 'woocommerce' ) ) );
		}
		foreach ( $attachment_ids as $attachment_id ) {
			$image       = wp_get_attachment_image( $attachment_id, apply_filters( 'single_product_small_thumbnail_size', 'shop_thumbnail' ) );
			echo apply_filters( 'woocommerce_single_product_image_thumbnail_html', sprintf( '%s', $image ) );
		}
		?>
	</div>

	<?php
}
