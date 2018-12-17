<?php
/**
 * The template for displaying product content within loops
 *
 * This template can be overridden by copying it to yourtheme/woocommerce/content-product.php.
 *
 * HOWEVER, on occasion WooCommerce will need to update template files and you
 * (the theme developer) will need to copy the new files to your theme to
 * maintain compatibility. We try to do this as little as possible, but it does
 * happen. When this occurs the version of the template file will be bumped and
 * the readme will list any important changes.
 *
 * @see     https://docs.woocommerce.com/document/template-structure/
 * @package WooCommerce/Templates
 * @version 3.4.0
 */

if ( ! defined( 'ABSPATH' ) ) {
	exit; // Exit if accessed directly
}

global $product, $woocommerce_loop, $eltd_moose_options;

// Store loop count we're currently on
if ( empty( $woocommerce_loop['loop'] ) )
    $woocommerce_loop['loop'] = 0;

// Store column count for displaying the grid
if ( empty( $woocommerce_loop['columns'] ) )
    $woocommerce_loop['columns'] = apply_filters( 'loop_shop_columns', 4 );

// Ensure visibility
if ( ! $product || ! $product->is_visible() )
    return;

// Increase loop count
$woocommerce_loop['loop']++;

$products_list_type = 'type1';
if(isset($eltd_moose_options['woo_products_list_type'])){
	$products_list_type = $eltd_moose_options['woo_products_list_type'];
}

$product_image_src =  wp_get_attachment_image_src( get_post_thumbnail_id($product->get_id()), 'full');

$woo_products_enable_lighbox_icon_yes_no = "yes";

if(isset($eltd_moose_options['woo_products_enable_lighbox_icon'])){
	$woo_products_enable_lighbox_icon_yes_no =  $eltd_moose_options['woo_products_enable_lighbox_icon'];
}

$hide_separator = "no";
if(isset($eltd_moose_options['woo_products_title_separator_hide_title_separator'])){
	$hide_separator = $eltd_moose_options['woo_products_title_separator_hide_title_separator'];
}

$classes = array();

if ( 0 == ( $woocommerce_loop['loop'] - 1 ) % $woocommerce_loop['columns'] || 1 == $woocommerce_loop['columns'] )
    $classes[] = 'first';
if ( 0 == $woocommerce_loop['loop'] % $woocommerce_loop['columns'] )
    $classes[] = 'last';
?>

<?php
//Get product gallery images and take first for displaying on single product hover
$product_gallery_ids = $product->get_gallery_image_ids();
if (!empty($product_gallery_ids)) {
	//get product image url, shop catalog size
	$product_hover_image = wp_get_attachment_image_src( $product_gallery_ids[0], 'shop_catalog' );
}
?>

<?php switch($products_list_type) { 
	
	case 'type1': ?>
	<li <?php post_class( $classes ); ?>>
		<?php do_action( 'woocommerce_before_shop_loop_item' ); ?>
			<div class="top-product-section">
				<a href="<?php the_permalink(); ?>">
					<span class="image-wrapper">
					<?php
						/**
						 * woocommerce_before_shop_loop_item_title hook
						 *
						 * @hooked woocommerce_show_product_loop_sale_flash - 10
						 * @hooked woocommerce_template_loop_product_thumbnail - 10
						 */
						do_action( 'woocommerce_before_shop_loop_item_title' );

					if (isset($product_hover_image)) { ?>

						<span class="single-product-hover-image" style="background-image: url(<?php echo esc_url( $product_hover_image[0] );?>)"></span>

					<?php
					}
					?>
					</span>
				</a>
			</div>
			<div class="product_info_box clearfix">
				<div class="info-box">
					<span class="product-categories">
						<?php echo wp_kses(wc_get_product_category_list( $product->get_id(), ', ' ), array(
							'a' => array(
								'href' => true,
								'rel' => true,
								'class' => true,
								'title' => true,
								'id' => true
							)
						)); ?>
					</span>
					<a href="<?php the_permalink(); ?>" class="product-category">
						<span class="product-title"><?php the_title(); ?></span>
					</a>
					<?php
					/**
					 * woocommerce_after_shop_loop_item_title hook
					 *
					 * @hooked woocommerce_template_loop_rating - 5
					 */
					remove_action( 'woocommerce_after_shop_loop_item_title', 'woocommerce_template_loop_rating', 5); ?>

					<div class="product-price-switcher-holder">
						<div class="product-price-switcher-holder-inner">
							<?php
							do_action( 'woocommerce_after_shop_loop_item_title' );
							do_action('eltd_woocommerce_after_product_info');
							?>
						</div>
					</div>
					<?php
					if($hide_separator == "no") { ?>
						<div class="separator_holder"><span class="separator medium"></span></div>
					<?php }
					?>
				</div>
				<?php
					if($woo_products_enable_lighbox_icon_yes_no == "yes") { 
				?>
				<div class="shop_price_lightbox_holder">
					<div class="shop_lightbox">
						<a class="product_lightbox" title="<?php echo esc_attr(the_title()); ?>" href="<?php echo esc_url($product_image_src[0]); ?>" data-rel="prettyPhoto[single_pretty_photo]">
							<span class="fa-search"></span>
						</a>
					</div>
				</div>
				<?php } ?>				
			</div>
			<?php do_action( 'woocommerce_after_shop_loop_item' ); ?>
	</li>

<?php break; } ?>