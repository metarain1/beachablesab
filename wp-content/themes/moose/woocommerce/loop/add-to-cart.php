<?php
/**
 * Loop Add to Cart
 *
 * This template can be overridden by copying it to yourtheme/woocommerce/loop/add-to-cart.php.
 *
 * HOWEVER, on occasion WooCommerce will need to update template files and you
 * (the theme developer) will need to copy the new files to your theme to
 * maintain compatibility. We try to do this as little as possible, but it does
 * happen. When this occurs the version of the template file will be bumped and
 * the readme will list any important changes.
 *
 * @see         https://docs.woocommerce.com/document/template-structure/
 * @author      WooThemes
 * @package     WooCommerce/Templates
 * @version     3.3.0
 */
if ( ! defined( 'ABSPATH' ) ) {
    exit;
}

global $product,$eltd_moose_options;

$animate_button_class='';
if(isset($eltd_moose_options['add_to_cart_button_hover_animation']) && ($eltd_moose_options['add_to_cart_button_hover_animation'] !== '')){
    $animate_button_class = $eltd_moose_options['add_to_cart_button_hover_animation'];
}

$type = "type1";
if(isset($eltd_moose_options['woo_products_list_type'])){
    $type = $eltd_moose_options['woo_products_list_type'];
}

$add_to_cart_text= $product->add_to_cart_text();
if ( $product->is_in_stock() ) {
    echo apply_filters( 'woocommerce_loop_add_to_cart_link',
        sprintf( '<a href="%s" rel="nofollow" data-product_id="%s" data-product_sku="%s" data-quantity="%s" class="'.$animate_button_class.' add-to-cart-button button %s %s"><i class="icon-handbag"></i><span class="text_wrap">%s</span></a>',
            esc_url( $product->add_to_cart_url() ),
            esc_attr( $product->get_id() ),
            esc_attr( $product->get_sku() ),
            esc_attr( isset( $quantity ) ? $quantity : 1 ),
            $product->is_purchasable() && $product->is_in_stock() ? 'add_to_cart_button' : '',
                esc_attr( isset( $class ) ? $class : 'button' ),
            esc_html( $add_to_cart_text )
        ),
        $product );
} else {
    echo apply_filters( 'woocommerce_loop_add_to_cart_link',
        sprintf( '<a href="%s" rel="nofollow" data-product_id="%s" data-product_sku="%s" data-quantity="%s" class="'.$animate_button_class.' add-to-cart-button button %s"><span class="text_wrap">%s</span></a>',
            esc_url( $product->add_to_cart_url() ),
            esc_attr( $product->get_id() ),
            esc_attr( $product->get_sku() ),
            esc_attr( isset( $quantity ) ? $quantity : 1 ),
            $product->is_purchasable() && $product->is_in_stock() ? 'add_to_cart_button' : '',
            esc_html( $add_to_cart_text )
        ),
        $product );
}


?>