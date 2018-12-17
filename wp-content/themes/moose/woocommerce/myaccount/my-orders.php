<?php
/**
 * My Orders
 *
 * @deprecated  2.6.0 this template file is no longer used. My Account shortcode uses orders.php.
 */

if ( ! defined( 'ABSPATH' ) ) {
	exit;
}

$customer_orders = get_posts( apply_filters( 'woocommerce_my_account_my_orders_query', array(
	'numberposts' => $order_count,
	'meta_key'    => '_customer_user',
	'meta_value'  => get_current_user_id(),
	'post_type'   => wc_get_order_types( 'view-orders' ),
	'post_status' => array_keys( wc_get_order_statuses() )
) ) );

if ( $customer_orders ) : ?>

	<h2><?php echo apply_filters( 'woocommerce_my_account_my_orders_title', __( 'Recent Orders', 'woocommerce' ) ); ?></h2>

	<table class="shop_table my_account_orders">

		<thead>
			<tr>
				<th class="order-number"><span class="nobr"><?php _e( 'Order', 'woocommerce' ); ?></span></th>
				<th class="order-date"><span class="nobr"><?php _e( 'Date', 'woocommerce' ); ?></span></th>
				<th class="order-status"><span class="nobr"><?php _e( 'Status', 'woocommerce' ); ?></span></th>
				<th class="order-total"><span class="nobr"><?php _e( 'Total', 'woocommerce' ); ?></span></th>
				<th class="order-actions">&nbsp;</th>
			</tr>
		</thead>

		<tbody><?php
			foreach ( $customer_orders as $customer_order ) {
				$order = wc_get_order( $customer_order );
				$order->populate( $customer_order );
				$item_count = $order->get_item_count();

				?><tr class="order">
					<td class="order-number" data-title="<?php esc_attr_e( 'Order Number', 'woocommerce' ); ?>">
						<a href="<?php echo esc_url( $order->get_view_order_url() ); ?>">
							<?php echo _x( '#', 'hash before order number', 'woocommerce' ) . $order->get_order_number(); ?>
						</a>
					</td>
					<td class="order-date" data-title="<?php esc_attr_e( 'Date', 'woocommerce' ); ?>">
						<time datetime="<?php echo esc_attr( $order->get_date_created()->date( 'c' ) ); ?>"><?php echo esc_html( wc_format_datetime( $order->get_date_created() ) ); ?></time>
					</td>
					<td class="order-status" data-title="<?php esc_attr_e( 'Status', 'woocommerce' ); ?>" style="text-align:left; white-space:nowrap;">
						<?php echo esc_html(wc_get_order_status_name( $order->get_status() )); ?>
					</td>
					<td class="order-total" data-title="<?php esc_attr_e( 'Total', 'woocommerce' ); ?>">
						<?php
						/* translators: 1: formatted order total 2: total order items */
						printf( _n( '%1$s for %2$s item', '%1$s for %2$s items', $item_count, 'woocommerce' ), $order->get_formatted_order_total(), $item_count );
						?>
					</td>
					<td class="order-actions">
						<?php
							$actions = array();

							if ( in_array( $order->get_status(), apply_filters( 'woocommerce_valid_order_statuses_for_payment', array( 'pending', 'failed' ), $order ) ) ) {
								$actions['pay'] = array(
									'url'  => $order->get_checkout_payment_url(),
									'name' => __( 'Pay', 'woocommerce' )
								);
							}

							if ( in_array( $order->get_status(), apply_filters( 'woocommerce_valid_order_statuses_for_cancel', array( 'pending', 'failed' ), $order ) ) ) {
								$actions['cancel'] = array(
									'url'  => $order->get_cancel_order_url( wc_get_page_permalink( 'myaccount' ) ),
									'name' => __( 'Cancel', 'woocommerce' )
								);
							}

							$actions['view'] = array(
								'url'  => $order->get_view_order_url(),
								'name' => __( 'View', 'woocommerce' )
							);

							$actions = apply_filters( 'woocommerce_my_account_my_orders_actions', $actions, $order );

							if ($actions) {
								foreach ( $actions as $key => $action ) {
									echo '<a href="' . esc_url( $action['url'] ) . '" class="qbutton small ' . sanitize_html_class( $key ) . '">' . esc_html( $action['name'] ) . '</a>';
								}
							}
						?>
					</td>
				</tr><?php
			}
		?></tbody>

	</table>

<?php endif; ?>