<?php

/*
   Interface: iElatedMooseLayoutNode
   A interface that implements Layout Node methods
*/
interface iElatedMooseLayoutNode
{
	public function hasChidren();
	public function getChild($key);
	public function addChild($key, $value);
}

/*
   Interface: iElatedMooseRender
   A interface that implements Render methods
*/
interface iElatedMooseRender
{
	public function render($factory);
}

/*
   Class: ElatedMoosePanel
   A class that initializes Elated Panel
*/
class ElatedMoosePanel implements iElatedMooseLayoutNode, iElatedMooseRender {

	public $children;
	public $title;
	public $name;
	public $hidden_property;
	public $hidden_value;
	public $hidden_values;

	function __construct($title="",$name="",$hidden_property="",$hidden_value="",$hidden_values=array()) {
		$this->children = array();
		$this->title = $title;
		$this->name = $name;
		$this->hidden_property = $hidden_property;
		$this->hidden_value = $hidden_value;
		$this->hidden_values = $hidden_values;
	}

	public function hasChidren() {
		return (count($this->children) > 0)?true:false;
	}

	public function getChild($key) {
		return $this->children[$key];
	}

	public function addChild($key, $value) {
		$this->children[$key] = $value;
	}

	public function render($factory) {
		$hidden = false;
		if (!empty($this->hidden_property)){
			if (eltdf_moose_option_get_value($this->hidden_property)==$this->hidden_value)
				$hidden = true;
			else {
				foreach ($this->hidden_values as $value) {
					if (eltdf_moose_option_get_value($this->hidden_property)==$value)
						$hidden = true;

				}
			}
		}
		?>
		<div class="eltdf-page-form-section-holder" id="eltdf_<?php echo esc_attr($this->name); ?>"<?php if ($hidden) { ?> style="display: none"<?php } ?>>
			<h3 class="eltdf-page-section-title"><?php echo esc_html($this->title); ?></h3>
			<?php
			foreach ($this->children as $child) {
				$this->renderChild($child, $factory);
			}
			?>
		</div>
	<?php
	}

	public function renderChild(iElatedMooseRender $child, $factory) {
		$child->render($factory);
	}
}

/*
   Class: ElatedMooseContainer
   A class that initializes Elated Container
*/
class ElatedMooseContainer implements iElatedMooseLayoutNode, iElatedMooseRender {

	public $children;
	public $name;
	public $hidden_property;
	public $hidden_value;
	public $hidden_values;

	function __construct($name="",$hidden_property="",$hidden_value="",$hidden_values=array()) {
		$this->children = array();
		$this->name = $name;
		$this->hidden_property = $hidden_property;
		$this->hidden_value = $hidden_value;
		$this->hidden_values = $hidden_values;
	}

	public function hasChidren() {
		return (count($this->children) > 0)?true:false;
	}

	public function getChild($key) {
		return $this->children[$key];
	}

	public function addChild($key, $value) {
		$this->children[$key] = $value;
	}

	public function render($factory) {
		$hidden = false;
		if (!empty($this->hidden_property)){
			if (eltdf_moose_option_get_value($this->hidden_property)==$this->hidden_value)
				$hidden = true;
			else {
				foreach ($this->hidden_values as $value) {
					if (eltdf_moose_option_get_value($this->hidden_property)==$value)
						$hidden = true;

				}
			}
		}
		?>
		<div class="eltdf-page-form-container-holder" id="eltdf_<?php echo esc_attr($this->name); ?>"<?php if ($hidden) { ?> style="display: none"<?php } ?>>
			<?php
			foreach ($this->children as $child) {
				$this->renderChild($child, $factory);
			}
			?>
		</div>
	<?php
	}

	public function renderChild(iElatedMooseRender $child, $factory) {
		$child->render($factory);
	}
}


/*
   Class: ElatedMooseContainerNoStyle
   A class that initializes Elated Container without css classes
*/
class ElatedMooseContainerNoStyle implements iElatedMooseLayoutNode, iElatedMooseRender {

	public $children;
	public $name;
	public $hidden_property;
	public $hidden_value;
	public $hidden_values;

	function __construct($name="",$hidden_property="",$hidden_value="",$hidden_values=array()) {
		$this->children = array();
		$this->name = $name;
		$this->hidden_property = $hidden_property;
		$this->hidden_value = $hidden_value;
		$this->hidden_values = $hidden_values;
	}

	public function hasChidren() {
		return (count($this->children) > 0)?true:false;
	}

	public function getChild($key) {
		return $this->children[$key];
	}

	public function addChild($key, $value) {
		$this->children[$key] = $value;
	}

	public function render($factory) {
		$hidden = false;
		if (!empty($this->hidden_property)){
			if (eltdf_moose_option_get_value($this->hidden_property)==$this->hidden_value)
				$hidden = true;
			else {
				foreach ($this->hidden_values as $value) {
					if (eltdf_moose_option_get_value($this->hidden_property)==$value)
						$hidden = true;

				}
			}
		}
		?>
		<div id="eltdf_<?php echo esc_attr($this->name); ?>"<?php if ($hidden) { ?> style="display: none"<?php } ?>>
			<?php
			foreach ($this->children as $child) {
				$this->renderChild($child, $factory);
			}
			?>
		</div>
	<?php
	}

	public function renderChild(iElatedMooseRender $child, $factory) {
		$child->render($factory);
	}
}

/*
   Class: ElatedMooseGroup
   A class that initializes Elated Group
*/
class ElatedMooseGroup implements iElatedMooseLayoutNode, iElatedMooseRender {

	public $children;
	public $title;
	public $description;

	function __construct($title="",$description="") {
		$this->children = array();
		$this->title = $title;
		$this->description = $description;
	}

	public function hasChidren() {
		return (count($this->children) > 0)?true:false;
	}

	public function getChild($key) {
		return $this->children[$key];
	}

	public function addChild($key, $value) {
		$this->children[$key] = $value;
	}

	public function render($factory) {
		?>

		<div class="eltdf-page-form-section">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($this->title); ?></h4>

				<p><?php echo esc_html($this->description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->

			<div class="eltdf-section-content">
				<div class="container-fluid">
					<?php
					foreach ($this->children as $child) {
						$this->renderChild($child, $factory);
					}
					?>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php
	}

	public function renderChild(iElatedMooseRender $child, $factory) {
		$child->render($factory);
	}
}

/*
   Class: ElatedMooseNotice
   A class that initializes Elated Notice
*/
class ElatedMooseNotice implements iElatedMooseRender {

	public $children;
	public $title;
	public $description;
	public $notice;
	public $hidden_property;
	public $hidden_value;
	public $hidden_values;

	function __construct($title="",$description="",$notice="",$hidden_property="",$hidden_value="",$hidden_values=array()) {
		$this->children = array();
		$this->title = $title;
		$this->description = $description;
		$this->notice = $notice;
		$this->hidden_property = $hidden_property;
		$this->hidden_value = $hidden_value;
		$this->hidden_values = $hidden_values;
	}

	public function render($factory) {
		$hidden = false;
		if (!empty($this->hidden_property)){
			if (eltdf_moose_option_get_value($this->hidden_property)==$this->hidden_value)
				$hidden = true;
			else {
				foreach ($this->hidden_values as $value) {
					if (eltdf_moose_option_get_value($this->hidden_property)==$value)
						$hidden = true;

				}
			}
		}
		?>

		<div class="eltdf-page-form-section"<?php if ($hidden) { ?> style="display: none"<?php } ?>>


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($this->title); ?></h4>

				<p><?php echo esc_html($this->description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->

			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="alert alert-warning">
						<?php echo esc_html($this->notice); ?>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php
	}
}

/*
   Class: ElatedMooseRow
   A class that initializes Elated Row
*/
class ElatedMooseRow implements iElatedMooseLayoutNode, iElatedMooseRender {

	public $children;
	public $next;

	function __construct($next=false) {
		$this->children = array();
		$this->next = $next;
	}

	public function hasChidren() {
		return (count($this->children) > 0)?true:false;
	}

	public function getChild($key) {
		return $this->children[$key];
	}

	public function addChild($key, $value) {
		$this->children[$key] = $value;
	}

	public function render($factory) {
		?>
		<div class="row<?php if ($this->next) echo " next-row"; ?>">
			<?php
			foreach ($this->children as $child) {
				$this->renderChild($child, $factory);
			}
			?>
		</div>
	<?php
	}

	public function renderChild(iElatedMooseRender $child, $factory) {
		$child->render($factory);
	}
}

/*
   Class: ElatedMooseTitle
   A class that initializes Elated Title
*/
class ElatedMooseTitle implements iElatedMooseRender {
	private $name;
	private $title;
	public $hidden_property;
	public $hidden_values = array();

	function __construct($name="",$title="",$hidden_property="",$hidden_value="") {
		$this->title = $title;
		$this->name = $name;
		$this->hidden_property = $hidden_property;
		$this->hidden_value = $hidden_value;
	}

	public function render($factory) {
		$hidden = false;
		if (!empty($this->hidden_property)){
			if (eltdf_moose_option_get_value($this->hidden_property)==$this->hidden_value)
				$hidden = true;
		}
		?>
		<h5 class="eltdf-page-section-subtitle" id="eltdf_<?php echo esc_attr($this->name); ?>"<?php if ($hidden) { ?> style="display: none"<?php } ?>><?php echo esc_html($this->title); ?></h5>
	<?php
	}
}

/*
   Class: ElatedMooseField
   A class that initializes Elated Field
*/
class ElatedMooseField implements iElatedMooseRender {
	private $type;
	private $name;
	private $default_value;
	private $label;
	private $description;
	private $options = array();
	private $args = array();
	public $hidden_property;
	public $hidden_values = array();


	function __construct($type,$name,$default_value="",$label="",$description="", $options = array(), $args = array(),$hidden_property="", $hidden_values = array()) {		
		global $eltdFramework;
		$this->type = $type;
		$this->name = $name;
		$this->default_value = $default_value;
		$this->label = $label;
		$this->description = $description;
		$this->options = $options;
		$this->args = $args;
		$this->hidden_property = $hidden_property;
		$this->hidden_values = $hidden_values;
		$eltdFramework->eltdOptions->addOption($this->name,$this->default_value, $type);
	}

	public function render($factory) {
		$hidden = false;
		if (!empty($this->hidden_property)){
			foreach ($this->hidden_values as $value) {
				if (eltdf_moose_option_get_value($this->hidden_property)==$value)
					$hidden = true;

			}
		}
		$factory->render( $this->type, $this->name, $this->label, $this->description, $this->options, $this->args, $hidden );
	}
}

/*
   Class: ElatedMooseMetaField
   A class that initializes Elated Meta Field
*/
class ElatedMooseMetaField implements iElatedMooseRender {
	private $type;
	private $name;
	private $default_value;
	private $label;
	private $description;
	private $options = array();
	private $args = array();
	public $hidden_property;
	public $hidden_values = array();


	function __construct($type,$name,$default_value="",$label="",$description="", $options = array(), $args = array(),$hidden_property="", $hidden_values = array()) {
		global $eltdFramework;
		$this->type = $type;
		$this->name = $name;
		$this->default_value = $default_value;
		$this->label = $label;
		$this->description = $description;
		$this->options = $options;
		$this->args = $args;
		$this->hidden_property = $hidden_property;
		$this->hidden_values = $hidden_values;
		$eltdFramework->eltdMetaBoxes->addOption($this->name,$this->default_value);
	}

	public function render($factory) {
		$hidden = false;
		if (!empty($this->hidden_property)){
			foreach ($this->hidden_values as $value) {
				if (eltdf_moose_option_get_value($this->hidden_property)==$value)
					$hidden = true;

			}
		}
		$factory->render( $this->type, $this->name, $this->label, $this->description, $this->options, $this->args, $hidden );
	}
}

abstract class ElatedMooseFieldType {

	abstract public function render( $name, $label="",$description="", $options = array(), $args = array(), $hidden = false );

}

class ElatedMooseFieldText extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		$col_width = 12;
		if(isset($args["col_width"]))
			$col_width = $args["col_width"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>"<?php if ($hidden) { ?> style="display: none"<?php } ?>>


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->

			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-<?php echo esc_attr($col_width); ?>">
							<input type="text"
								   class="form-control eltdf-input eltdf-form-element"
								   name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(htmlspecialchars(eltdf_moose_option_get_value($name))); ?>"
								   placeholder=""/></div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldTextSimple extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		?>


		<div class="col-lg-3" id="eltdf_<?php echo esc_attr($name); ?>"<?php if ($hidden) { ?> style="display: none"<?php } ?>>
			<em class="eltdf-field-description"><?php echo esc_html($label); ?></em>
			<input type="text"
				   class="form-control eltdf-input eltdf-form-element"
				   name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(htmlspecialchars(eltdf_moose_option_get_value($name))); ?>"
				   placeholder=""/></div>
	<?php

	}

}

class ElatedMooseFieldTextArea extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		?>

		<div class="eltdf-page-form-section">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->


			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<textarea class="form-control eltdf-form-element"
									  name="<?php echo esc_attr($name); ?>"
									  rows="5"><?php echo esc_html(htmlspecialchars(eltdf_moose_option_get_value($name))); ?></textarea>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldTextAreaSimple extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		?>

		<div class="col-lg-3">
			<em class="eltdf-field-description"><?php echo esc_html($label); ?></em>
			<textarea class="form-control eltdf-form-element"
					  name="<?php echo esc_attr($name); ?>"
					  rows="5"><?php echo esc_html(eltdf_moose_option_get_value($name)); ?></textarea>
		</div>
	<?php

	}

}

class ElatedMooseFieldColor extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->

			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<input type="text" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>" class="my-color-field"/>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldColorSimple extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		?>

		<div class="col-lg-3" id="eltdf_<?php echo esc_attr($name); ?>"<?php if ($hidden) { ?> style="display: none"<?php } ?>>
			<em class="eltdf-field-description"><?php echo esc_html($label); ?></em>
			<input type="text" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>" class="my-color-field"/>
		</div>
	<?php

	}

}

class ElatedMooseFieldImage extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		?>

		<div class="eltdf-page-form-section">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->

			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<div class="eltdf-media-uploader">
								<div<?php if (!eltdf_moose_option_has_value($name)) { ?> style="display: none"<?php } ?>
									class="eltdf-media-image-holder">
									<img src="<?php if (eltdf_moose_option_has_value($name)) { echo esc_url(eltdf_moose_get_attachment_thumb_url(eltdf_moose_option_get_value($name))); } ?>" alt=""
										 class="eltdf-media-image img-thumbnail"/>
								</div>
								<div style="display: none"
									 class="eltdf-media-meta-fields">
									<input type="hidden" class="eltdf-media-upload-url"
										   name="<?php echo esc_attr($name); ?>"
										   value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
								</div>
								<a class="eltdf-media-upload-btn btn btn-sm btn-primary"
								   href="javascript:void(0)"
								   data-frame-title="<?php _e('Select Image', 'eltd'); ?>"
								   data-frame-button-text="<?php _e('Select Image', 'eltd'); ?>"><?php _e('Upload', 'eltd'); ?></a>
								<a style="display: none;" href="javascript: void(0)"
								   class="eltdf-media-remove-btn btn btn-default btn-sm"><?php _e('Remove', 'eltd'); ?></a>
							</div>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldImageSimple extends ElatedMooseFieldType {

    public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
        ?>


        <div class="col-lg-3" id="eltdf_<?php echo esc_attr($name); ?>"<?php if ($hidden) { ?> style="display: none"<?php } ?>>
            <em class="eltdf-field-description"><?php echo esc_html($label); ?></em>
            <div class="eltdf-media-uploader">
                <div<?php if (!eltdf_moose_option_has_value($name)) { ?> style="display: none"<?php } ?>
                    class="eltdf-media-image-holder">
                    <img src="<?php if (eltdf_moose_option_has_value($name)) { echo esc_url(eltdf_moose_get_attachment_thumb_url(eltdf_moose_option_get_value($name))); } ?>" alt=""
                         class="eltdf-media-image img-thumbnail"/>
                </div>
                <div style="display: none"
                     class="eltdf-media-meta-fields">
                    <input type="hidden" class="eltdf-media-upload-url"
                           name="<?php echo esc_attr($name); ?>"
                           value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
                </div>
                <a class="eltdf-media-upload-btn btn btn-sm btn-primary"
                   href="javascript:void(0)"
                   data-frame-title="<?php _e('Select Image', 'eltd'); ?>"
                   data-frame-button-text="<?php _e('Select Image', 'eltd'); ?>"><?php _e('Upload', 'eltd'); ?></a>
                <a style="display: none;" href="javascript: void(0)"
                   class="eltdf-media-remove-btn btn btn-default btn-sm"><?php _e('Remove', 'eltd'); ?></a>
            </div>
        </div>
    <?php

    }

}

class ElatedMooseFieldFont extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		global $eltd_moose_fonts_array;
		?>

		<div class="eltdf-page-form-section">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-3">
							<select class="form-control eltdf-form-element"
									name="<?php echo esc_attr($name); ?>">
								<option value="-1">Default</option>
								<?php foreach($eltd_moose_fonts_array as $fontArray) { ?>
									<option <?php if (eltdf_moose_option_get_value($name) == str_replace(' ', '+', $fontArray["family"])) { echo "selected='selected'"; } ?>  value="<?php echo esc_attr(str_replace(' ', '+', $fontArray["family"])); ?>"><?php echo esc_html($fontArray["family"]); ?></option>
								<?php } ?>
							</select>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldFontSimple extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		global $eltd_moose_fonts_array;
		?>


		<div class="col-lg-3">
			<em class="eltdf-field-description"><?php echo esc_html($label); ?></em>
			<select class="form-control eltdf-form-element"
					name="<?php echo esc_attr($name); ?>">
				<option value="-1">Default</option>
				<?php foreach($eltd_moose_fonts_array as $fontArray) { ?>
					<option <?php if (eltdf_moose_option_get_value($name) == str_replace(' ', '+', $fontArray["family"])) { echo "selected='selected'"; } ?>  value="<?php echo esc_attr(str_replace(' ', '+', $fontArray["family"])); ?>"><?php echo esc_html($fontArray["family"]); ?></option>
				<?php } ?>
			</select>
		</div>
	<?php

	}

}

class ElatedMooseFieldSelect extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$show = array();
		if(isset($args["show"]))
			$show = $args["show"];
		$hide = array();
		if(isset($args["hide"]))
			$hide = $args["hide"];
		?>

		<div class="eltdf-page-form-section"<?php if ($hidden) { ?> style="display: none"<?php } ?>>


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-3">
							<select class="form-control eltdf-form-element<?php if ($dependence) { echo " dependence"; } ?>"
								<?php foreach($show as $key=>$value) { ?>
									data-show-<?php echo str_replace(' ', '',$key); ?>="<?php echo esc_attr($value); ?>"
								<?php } ?>
								<?php foreach($hide as $key=>$value) { ?>
									data-hide-<?php echo str_replace(' ', '',$key); ?>="<?php echo esc_attr($value); ?>"
								<?php } ?>
									name="<?php echo esc_attr($name); ?>">
								<?php foreach($options as $key=>$value) { if ($key == "-1") $key = ""; ?>
									<option <?php if (eltdf_moose_option_get_value($name) == $key) { echo "selected='selected'"; } ?>  value="<?php echo esc_attr($key); ?>"><?php echo esc_html($value); ?></option>
								<?php } ?>
							</select>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldSelectBlank extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$show = array();
		if(isset($args["show"]))
			$show = $args["show"];
		$hide = array();
		if(isset($args["hide"]))
			$hide = $args["hide"];
		?>

		<div class="eltdf-page-form-section"<?php if ($hidden) { ?> style="display: none"<?php } ?>>


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-3">
							<select class="form-control eltdf-form-element<?php if ($dependence) { echo " dependence"; } ?>"
								<?php foreach($show as $key=>$value) { ?>
									data-show-<?php echo str_replace(' ', '',$key); ?>="<?php echo esc_attr($value); ?>"
								<?php } ?>
								<?php foreach($hide as $key=>$value) { ?>
									data-hide-<?php echo str_replace(' ', '',$key); ?>="<?php echo esc_attr($value); ?>"
								<?php } ?>
									name="<?php echo esc_attr($name); ?>">
								<option <?php if (eltdf_moose_option_get_value($name) == "") { echo "selected='selected'"; } ?>  value=""></option>
								<?php foreach($options as $key=>$value) { if ($key == "-1") $key = ""; ?>
									<option <?php if (eltdf_moose_option_get_value($name) == $key) { echo "selected='selected'"; } ?>  value="<?php echo esc_attr($key); ?>"><?php echo esc_html($value); ?></option>
								<?php } ?>
							</select>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldSelectSimple extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
        $dependence = false;
        if(isset($args["dependence"]))
            $dependence = true;
        $show = array();
        if(isset($args["show"]))
            $show = $args["show"];
        $hide = array();
        if(isset($args["hide"]))
            $hide = $args["hide"];
        ?>


		<div class="col-lg-3">
			<em class="eltdf-field-description"><?php echo esc_html($label); ?></em>
            <select class="form-control eltdf-form-element<?php if ($dependence) { echo " dependence"; } ?>"
                <?php foreach($show as $key=>$value) { ?>
                    data-show-<?php echo str_replace(' ', '',$key); ?>="<?php echo esc_attr($value); ?>"
                <?php } ?>
                <?php foreach($hide as $key=>$value) { ?>
                    data-hide-<?php echo str_replace(' ', '',$key); ?>="<?php echo esc_attr($value); ?>"
                <?php } ?>
                    name="<?php echo esc_attr($name); ?>">
                <option <?php if (eltdf_moose_option_get_value($name) == "") { echo "selected='selected'"; } ?>  value=""></option>
                <?php foreach($options as $key=>$value) { if ($key == "-1") $key = ""; ?>
                    <option <?php if (eltdf_moose_option_get_value($name) == $key) { echo "selected='selected'"; } ?>  value="<?php echo esc_attr($key); ?>"><?php echo esc_html($value); ?></option>
                <?php } ?>
            </select>
		</div>
	<?php

	}

}

class ElatedMooseFieldSelectBlankSimple extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
        $dependence = false;
        if(isset($args["dependence"]))
            $dependence = true;
        $show = array();
        if(isset($args["show"]))
            $show = $args["show"];
        $hide = array();
        if(isset($args["hide"]))
            $hide = $args["hide"];
        ?>


		<div class="col-lg-3">
			<em class="eltdf-field-description"><?php echo esc_html($label); ?></em>
            <select class="form-control eltdf-form-element<?php if ($dependence) { echo " dependence"; } ?>"
                <?php foreach($show as $key=>$value) { ?>
                    data-show-<?php echo str_replace(' ', '',$key); ?>="<?php echo esc_attr($value); ?>"
                <?php } ?>
                <?php foreach($hide as $key=>$value) { ?>
                    data-hide-<?php echo str_replace(' ', '',$key); ?>="<?php echo esc_attr($value); ?>"
                <?php } ?>
                    name="<?php echo esc_attr($name); ?>">
                <option <?php if (eltdf_moose_option_get_value($name) == "") { echo "selected='selected'"; } ?>  value=""></option>
                <?php foreach($options as $key=>$value) { if ($key == "-1") $key = ""; ?>
                    <option <?php if (eltdf_moose_option_get_value($name) == $key) { echo "selected='selected'"; } ?>  value="<?php echo esc_attr($key); ?>"><?php echo esc_html($value); ?></option>
                <?php } ?>
            </select>
		</div>
	<?php

	}

}

class ElatedMooseFieldYesNo extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$dependence_hide_on_yes = "";
		if(isset($args["dependence_hide_on_yes"]))
			$dependence_hide_on_yes = $args["dependence_hide_on_yes"];
		$dependence_show_on_yes = "";
		if(isset($args["dependence_show_on_yes"]))
			$dependence_show_on_yes = $args["dependence_show_on_yes"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<p class="field switch">
								<label data-hide="<?php echo esc_attr($dependence_hide_on_yes); ?>" data-show="<?php echo esc_attr($dependence_show_on_yes); ?>"
									   class="cb-enable<?php if (eltdf_moose_option_get_value($name) == "yes") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Yes', 'eltd') ?></span></label>
								<label data-hide="<?php echo esc_attr($dependence_show_on_yes); ?>" data-show="<?php echo esc_attr($dependence_hide_on_yes); ?>"
									   class="cb-disable<?php if (eltdf_moose_option_get_value($name) == "no") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('No', 'eltd') ?></span></label>
								<input type="checkbox" id="checkbox" class="checkbox"
									   name="<?php echo esc_attr($name); ?>_yesno" value="yes"<?php if (eltdf_moose_option_get_value($name) == "yes") { echo " selected"; } ?>/>
								<input type="hidden" class="checkboxhidden_yesno" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
							</p>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}
}

class ElatedMooseFieldYesNoSimple extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$dependence_hide_on_yes = "";
		if(isset($args["dependence_hide_on_yes"]))
			$dependence_hide_on_yes = $args["dependence_hide_on_yes"];
		$dependence_show_on_yes = "";
		if(isset($args["dependence_show_on_yes"]))
			$dependence_show_on_yes = $args["dependence_show_on_yes"];
		?>

		<div class="col-lg-3">
			<em class="eltdf-field-description"><?php echo esc_html($label); ?></em>
			<p class="field switch">
				<label data-hide="<?php echo esc_attr($dependence_hide_on_yes); ?>" data-show="<?php echo esc_attr($dependence_show_on_yes); ?>"
					   class="cb-enable<?php if (eltdf_moose_option_get_value($name) == "yes") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Yes', 'eltd') ?></span></label>
				<label data-hide="<?php echo esc_attr($dependence_show_on_yes); ?>" data-show="<?php echo esc_attr($dependence_hide_on_yes); ?>"
					   class="cb-disable<?php if (eltdf_moose_option_get_value($name) == "no") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('No', 'eltd') ?></span></label>
				<input type="checkbox" id="checkbox" class="checkbox"
					   name="<?php echo esc_attr($name); ?>_yesno" value="yes"<?php if (eltdf_moose_option_get_value($name) == "yes") { echo " selected"; } ?>/>
				<input type="hidden" class="checkboxhidden_yesno" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
			</p>
		</div>
	<?php

	}
}

class ElatedMooseFieldOnOff extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$dependence_hide_on_yes = "";
		if(isset($args["dependence_hide_on_yes"]))
			$dependence_hide_on_yes = $args["dependence_hide_on_yes"];
		$dependence_show_on_yes = "";
		if(isset($args["dependence_show_on_yes"]))
			$dependence_show_on_yes = $args["dependence_show_on_yes"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">

							<p class="field switch">
								<label data-hide="<?php echo esc_attr($dependence_hide_on_yes); ?>" data-show="<?php echo esc_attr($dependence_show_on_yes); ?>"
									   class="cb-enable<?php if (eltdf_moose_option_get_value($name) == "on") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('On', 'eltd') ?></span></label>
								<label data-hide="<?php echo esc_attr($dependence_show_on_yes); ?>" data-show="<?php echo esc_attr($dependence_hide_on_yes); ?>"
									   class="cb-disable<?php if (eltdf_moose_option_get_value($name) == "off") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Off', 'eltd') ?></span></label>
								<input type="checkbox" id="checkbox" class="checkbox"
									   name="<?php echo esc_attr($name); ?>_onoff" value="on"<?php if (eltdf_moose_option_get_value($name) == "on") { echo " selected"; } ?>/>
								<input type="hidden" class="checkboxhidden_onoff" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
							</p>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldPortfolioFollow extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$dependence_hide_on_yes = "";
		if(isset($args["dependence_hide_on_yes"]))
			$dependence_hide_on_yes = $args["dependence_hide_on_yes"];
		$dependence_show_on_yes = "";
		if(isset($args["dependence_show_on_yes"]))
			$dependence_show_on_yes = $args["dependence_show_on_yes"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<p class="field switch">
								<label data-hide="<?php echo esc_attr($dependence_hide_on_yes); ?>" data-show="<?php echo esc_attr($dependence_show_on_yes); ?>"
									   class="cb-enable<?php if (eltdf_moose_option_get_value($name) == "portfolio_single_follow") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Yes', 'eltd') ?></span></label>
								<label data-hide="<?php echo esc_attr($dependence_show_on_yes); ?>" data-show="<?php echo esc_attr($dependence_hide_on_yes); ?>"
									   class="cb-disable<?php if (eltdf_moose_option_get_value($name) == "portfolio_single_no_follow") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('No', 'eltd') ?></span></label>
								<input type="checkbox" id="checkbox" class="checkbox"
									   name="<?php echo esc_attr($name); ?>_portfoliofollow" value="portfolio_single_follow"<?php if (eltdf_moose_option_get_value($name) == "portfolio_single_follow") { echo " selected"; } ?>/>
								<input type="hidden" class="checkboxhidden_portfoliofollow" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
							</p>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldZeroOne extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$dependence_hide_on_yes = "";
		if(isset($args["dependence_hide_on_yes"]))
			$dependence_hide_on_yes = $args["dependence_hide_on_yes"];
		$dependence_show_on_yes = "";
		if(isset($args["dependence_show_on_yes"]))
			$dependence_show_on_yes = $args["dependence_show_on_yes"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">

							<p class="field switch">
								<label data-hide="<?php echo esc_attr($dependence_hide_on_yes); ?>" data-show="<?php echo esc_attr($dependence_show_on_yes); ?>"
									   class="cb-enable<?php if (eltdf_moose_option_get_value($name) == "1") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Yes', 'eltd') ?></span></label>
								<label data-hide="<?php echo esc_attr($dependence_show_on_yes); ?>" data-show="<?php echo esc_attr($dependence_hide_on_yes); ?>"
									   class="cb-disable<?php if (eltdf_moose_option_get_value($name) == "0") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('No', 'eltd') ?></span></label>
								<input type="checkbox" id="checkbox" class="checkbox"
									   name="<?php echo esc_attr($name); ?>_zeroone" value="1"<?php if (eltdf_moose_option_get_value($name) == "1") { echo " selected"; } ?>/>
								<input type="hidden" class="checkboxhidden_zeroone" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
							</p>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldImageVideo extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$dependence_hide_on_yes = "";
		if(isset($args["dependence_hide_on_yes"]))
			$dependence_hide_on_yes = $args["dependence_hide_on_yes"];
		$dependence_show_on_yes = "";
		if(isset($args["dependence_show_on_yes"]))
			$dependence_show_on_yes = $args["dependence_show_on_yes"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<p class="field switch switch-type">
								<label data-hide="<?php echo esc_attr($dependence_hide_on_yes); ?>" data-show="<?php echo esc_attr($dependence_show_on_yes); ?>"
									   class="cb-enable<?php if (eltdf_moose_option_get_value($name) == "image") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Image', 'eltd') ?></span></label>
								<label data-hide="<?php echo esc_attr($dependence_show_on_yes); ?>" data-show="<?php echo esc_attr($dependence_hide_on_yes); ?>"
									   class="cb-disable<?php if (eltdf_moose_option_get_value($name) == "video") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Video', 'eltd') ?></span></label>
								<input type="checkbox" id="checkbox" class="checkbox"
									   name="<?php echo esc_attr($name); ?>_imagevideo" value="image"<?php if (eltdf_moose_option_get_value($name) == "image") { echo " selected"; } ?>/>
								<input type="hidden" class="checkboxhidden_imagevideo" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
							</p>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldYesEmpty extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$dependence_hide_on_yes = "";
		if(isset($args["dependence_hide_on_yes"]))
			$dependence_hide_on_yes = $args["dependence_hide_on_yes"];
		$dependence_show_on_yes = "";
		if(isset($args["dependence_show_on_yes"]))
			$dependence_show_on_yes = $args["dependence_show_on_yes"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<p class="field switch">
								<label data-hide="<?php echo esc_attr($dependence_hide_on_yes); ?>" data-show="<?php echo esc_attr($dependence_show_on_yes); ?>"
									   class="cb-enable<?php if (eltdf_moose_option_get_value($name) == "yes") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Yes', 'eltd') ?></span></label>
								<label data-hide="<?php echo esc_attr($dependence_show_on_yes); ?>" data-show="<?php echo esc_attr($dependence_hide_on_yes); ?>"
									   class="cb-disable<?php if (eltdf_moose_option_get_value($name) == "") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('No', 'eltd') ?></span></label>
								<input type="checkbox" id="checkbox" class="checkbox"
									   name="<?php echo esc_attr($name); ?>_yesempty" value="yes"<?php if (eltdf_moose_option_get_value($name) == "yes") { echo " selected"; } ?>/>
								<input type="hidden" class="checkboxhidden_yesempty" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
							</p>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldFlagPage extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$dependence_hide_on_yes = "";
		if(isset($args["dependence_hide_on_yes"]))
			$dependence_hide_on_yes = $args["dependence_hide_on_yes"];
		$dependence_show_on_yes = "";
		if(isset($args["dependence_show_on_yes"]))
			$dependence_show_on_yes = $args["dependence_show_on_yes"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<p class="field switch">
								<label data-hide="<?php echo esc_attr($dependence_hide_on_yes); ?>" data-show="<?php echo esc_attr($dependence_show_on_yes); ?>"
									   class="cb-enable<?php if (eltdf_moose_option_get_value($name) == "page") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Yes', 'eltd') ?></span></label>
								<label data-hide="<?php echo esc_attr($dependence_show_on_yes); ?>" data-show="<?php echo esc_attr($dependence_hide_on_yes); ?>"
									   class="cb-disable<?php if (eltdf_moose_option_get_value($name) == "") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('No', 'eltd') ?></span></label>
								<input type="checkbox" id="checkbox" class="checkbox"
									   name="<?php echo esc_attr($name); ?>_flagpage" value="page"<?php if (eltdf_moose_option_get_value($name) == "page") { echo " selected"; } ?>/>
								<input type="hidden" class="checkboxhidden_flagpage" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
							</p>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldFlagPost extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$dependence_hide_on_yes = "";
		if(isset($args["dependence_hide_on_yes"]))
			$dependence_hide_on_yes = $args["dependence_hide_on_yes"];
		$dependence_show_on_yes = "";
		if(isset($args["dependence_show_on_yes"]))
			$dependence_show_on_yes = $args["dependence_show_on_yes"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<p class="field switch">
								<label data-hide="<?php echo esc_attr($dependence_hide_on_yes); ?>" data-show="<?php echo esc_attr($dependence_show_on_yes); ?>"
									   class="cb-enable<?php if (eltdf_moose_option_get_value($name) == "post") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Yes', 'eltd') ?></span></label>
								<label data-hide="<?php echo esc_attr($dependence_show_on_yes); ?>" data-show="<?php echo esc_attr($dependence_hide_on_yes); ?>"
									   class="cb-disable<?php if (eltdf_moose_option_get_value($name) == "") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('No', 'eltd') ?></span></label>
								<input type="checkbox" id="checkbox" class="checkbox"
									   name="<?php echo esc_attr($name); ?>_flagpost" value="post"<?php if (eltdf_moose_option_get_value($name) == "post") { echo " selected"; } ?>/>
								<input type="hidden" class="checkboxhidden_flagpost" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
							</p>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldFlagMedia extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$dependence_hide_on_yes = "";
		if(isset($args["dependence_hide_on_yes"]))
			$dependence_hide_on_yes = $args["dependence_hide_on_yes"];
		$dependence_show_on_yes = "";
		if(isset($args["dependence_show_on_yes"]))
			$dependence_show_on_yes = $args["dependence_show_on_yes"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<p class="field switch">
								<label data-hide="<?php echo esc_attr($dependence_hide_on_yes); ?>" data-show="<?php echo esc_attr($dependence_show_on_yes); ?>"
									   class="cb-enable<?php if (eltdf_moose_option_get_value($name) == "attachment") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Yes', 'eltd') ?></span></label>
								<label data-hide="<?php echo esc_attr($dependence_show_on_yes); ?>" data-show="<?php echo esc_attr($dependence_hide_on_yes); ?>"
									   class="cb-disable<?php if (eltdf_moose_option_get_value($name) == "") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('No', 'eltd') ?></span></label>
								<input type="checkbox" id="checkbox" class="checkbox"
									   name="<?php echo esc_attr($name); ?>_flagmedia" value="attachment"<?php if (eltdf_moose_option_get_value($name) == "attachment") { echo " selected"; } ?>/>
								<input type="hidden" class="checkboxhidden_flagmedia" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
							</p>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldFlagPortfolio extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$dependence_hide_on_yes = "";
		if(isset($args["dependence_hide_on_yes"]))
			$dependence_hide_on_yes = $args["dependence_hide_on_yes"];
		$dependence_show_on_yes = "";
		if(isset($args["dependence_show_on_yes"]))
			$dependence_show_on_yes = $args["dependence_show_on_yes"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<p class="field switch">
								<label data-hide="<?php echo esc_attr($dependence_hide_on_yes); ?>" data-show="<?php echo esc_attr($dependence_show_on_yes); ?>"
									   class="cb-enable<?php if (eltdf_moose_option_get_value($name) == "portfolio_page") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Yes', 'eltd') ?></span></label>
								<label data-hide="<?php echo esc_attr($dependence_show_on_yes); ?>" data-show="<?php echo esc_attr($dependence_hide_on_yes); ?>"
									   class="cb-disable<?php if (eltdf_moose_option_get_value($name) == "") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('No', 'eltd') ?></span></label>
								<input type="checkbox" id="checkbox" class="checkbox"
									   name="<?php echo esc_attr($name); ?>_flagportfolio" value="portfolio_page"<?php if (eltdf_moose_option_get_value($name) == "portfolio_page") { echo " selected"; } ?>/>
								<input type="hidden" class="checkboxhidden_flagportfolio" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
							</p>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldFlagProduct extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		global $eltd_moose_options;
		$dependence = false;
		if(isset($args["dependence"]))
			$dependence = true;
		$dependence_hide_on_yes = "";
		if(isset($args["dependence_hide_on_yes"]))
			$dependence_hide_on_yes = $args["dependence_hide_on_yes"];
		$dependence_show_on_yes = "";
		if(isset($args["dependence_show_on_yes"]))
			$dependence_show_on_yes = $args["dependence_show_on_yes"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->



			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<p class="field switch">
								<label data-hide="<?php echo esc_attr($dependence_hide_on_yes); ?>" data-show="<?php echo esc_attr($dependence_show_on_yes); ?>"
									   class="cb-enable<?php if (eltdf_moose_option_get_value($name) == "product") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('Yes', 'eltd') ?></span></label>
								<label data-hide="<?php echo esc_attr($dependence_show_on_yes); ?>" data-show="<?php echo esc_attr($dependence_hide_on_yes); ?>"
									   class="cb-disable<?php if (eltdf_moose_option_get_value($name) == "") { echo " selected"; } ?><?php if ($dependence) { echo " dependence"; } ?>"><span><?php _e('No', 'eltd') ?></span></label>
								<input type="checkbox" id="checkbox" class="checkbox"
									   name="<?php echo esc_attr($name); ?>_flagproduct" value="product"<?php if (eltdf_moose_option_get_value($name) == "product") { echo " selected"; } ?>/>
								<input type="hidden" class="checkboxhidden_flagproduct" name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>
							</p>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldRange extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		$range_min = 0;
		$range_max = 1;
		$range_step = 0.01;
		$range_decimals = 2;
		if(isset($args["range_min"]))
			$range_min = $args["range_min"];
		if(isset($args["range_max"]))
			$range_max = $args["range_max"];
		if(isset($args["range_step"]))
			$range_step = $args["range_step"];
		if(isset($args["range_decimals"]))
			$range_decimals = $args["range_decimals"];
		?>

		<div class="eltdf-page-form-section">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->

			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<div class="eltdf-slider-range-wrapper">
								<div class="form-inline">
									<input type="text"
										   class="form-control eltdf-form-element eltdf-form-element-xsmall pull-left eltdf-slider-range-value"
										   name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>

									<div class="eltdf-slider-range small"
										 data-step="<?php echo esc_attr($range_step); ?>" data-min="<?php echo esc_attr($range_min); ?>" data-max="<?php echo esc_attr($range_max); ?>" data-decimals="<?php echo esc_attr($range_decimals); ?>" data-start="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"></div>
								</div>

							</div>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}

class ElatedMooseFieldRangeSimple extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		?>

		<div class="col-lg-3" id="eltdf_<?php echo esc_attr($name); ?>"<?php if ($hidden) { ?> style="display: none"<?php } ?>>
			<div class="eltdf-slider-range-wrapper">
				<div class="form-inline">
					<em class="eltdf-field-description"><?php echo esc_html($label); ?></em>
					<input type="text"
						   class="form-control eltdf-form-element eltdf-form-element-xxsmall pull-left eltdf-slider-range-value"
						   name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"/>

					<div class="eltdf-slider-range xsmall"
						 data-step="0.01" data-max="1" data-start="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"></div>
				</div>

			</div>
		</div>
	<?php

	}

}

class ElatedMooseFieldRadio extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {

		$checked = "";
		if ($default_value == $value)
			$checked = "checked";
		$html = '<input type="radio" name="'.$name.'" value="'.$default_value.'" '.$checked.' /> '.$label.'<br />';
		echo wp_kses($html, array(
			'input' => array(
				'type' => true,
				'name' => true,
				'value' => true,
				'checked' => true
			),
			'br' => true
		));

	}

}

class ElatedMooseFieldCheckBox extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {

		$checked = "";
		if ($default_value == $value)
			$checked = "checked";
		$html = '<input type="checkbox" name="'.$name.'" value="'.$default_value.'" '.$checked.' /> '.$label.'<br />';
		echo wp_kses($html, array(
			'input' => array(
				'type' => true,
				'name' => true,
				'value' => true,
				'checked' => true
			),
			'br' => true
		));

	}

}

class ElatedMooseFieldDate extends ElatedMooseFieldType {

	public function render( $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {
		$col_width = 2;
		if(isset($args["col_width"]))
			$col_width = $args["col_width"];
		?>

		<div class="eltdf-page-form-section" id="eltdf_<?php echo esc_attr($name); ?>"<?php if ($hidden) { ?> style="display: none"<?php } ?>>


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($label); ?></h4>

				<p><?php echo esc_html($description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->

			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-<?php echo esc_attr($col_width); ?>">
							<input type="text"
								   id = "portfolio_date"
								   class="datepicker form-control eltdf-input eltdf-form-element"
								   name="<?php echo esc_attr($name); ?>" value="<?php echo esc_attr(eltdf_moose_option_get_value($name)); ?>"
								/></div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}

}


class ElatedMooseFieldFactory {

	public function render( $field_type, $name, $label="", $description="", $options = array(), $args = array(), $hidden = false ) {


		switch ( strtolower( $field_type ) ) {

			case 'text':
				$field = new ElatedMooseFieldText();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'textsimple':
				$field = new ElatedMooseFieldTextSimple();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'textarea':
				$field = new ElatedMooseFieldTextArea();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'textareasimple':
				$field = new ElatedMooseFieldTextAreaSimple();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'color':
				$field = new ElatedMooseFieldColor();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'colorsimple':
				$field = new ElatedMooseFieldColorSimple();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'image':
				$field = new ElatedMooseFieldImage();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

            case 'imagesimple':
				$field = new ElatedMooseFieldImageSimple();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'font':
				$field = new ElatedMooseFieldFont();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'fontsimple':
				$field = new ElatedMooseFieldFontSimple();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'select':
				$field = new ElatedMooseFieldSelect();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'selectblank':
				$field = new ElatedMooseFieldSelectBlank();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'selectsimple':
				$field = new ElatedMooseFieldSelectSimple();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'selectblanksimple':
				$field = new ElatedMooseFieldSelectBlankSimple();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'yesno':
				$field = new ElatedMooseFieldYesNo();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'yesnosimple':
				$field = new ElatedMooseFieldYesNoSimple();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'onoff':
				$field = new ElatedMooseFieldOnOff();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'portfoliofollow':
				$field = new ElatedMooseFieldPortfolioFollow();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'zeroone':
				$field = new ElatedMooseFieldZeroOne();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'imagevideo':
				$field = new ElatedMooseFieldImageVideo();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'yesempty':
				$field = new ElatedMooseFieldYesEmpty();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'flagpost':
				$field = new ElatedMooseFieldFlagPost();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'flagpage':
				$field = new ElatedMooseFieldFlagPage();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'flagmedia':
				$field = new ElatedMooseFieldFlagMedia();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'flagportfolio':
				$field = new ElatedMooseFieldFlagPortfolio();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'flagproduct':
				$field = new ElatedMooseFieldFlagProduct();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'range':
				$field = new ElatedMooseFieldRange();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'rangesimple':
				$field = new ElatedMooseFieldRangeSimple();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'radio':
				$field = new ElatedMooseFieldRadio();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'checkbox':
				$field = new ElatedMooseFieldCheckBox();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			case 'date':
				$field = new ElatedMooseFieldDate();
				$field->render( $name, $label, $description, $options, $args, $hidden );
				break;

			default:
				break;

		}

	}

}

/*
   Class: ElatedMooseMultipleImages
   A class that initializes Elated Multiple Images
*/
class ElatedMooseMultipleImages implements iElatedMooseRender {
	private $name;
	private $label;
	private $description;


	function __construct($name,$label="",$description="") {
		global $eltdFramework;
		$this->name = $name;
		$this->label = $label;
		$this->description = $description;
		$eltdFramework->eltdMetaBoxes->addOption($this->name,"");
	}

	public function render($factory) {
		global $post;
		?>

		<div class="eltdf-page-form-section">


			<div class="eltdf-field-desc">
				<h4><?php echo esc_html($this->label); ?></h4>

				<p><?php echo esc_html($this->description); ?></p>
			</div>
			<!-- close div.eltdf-field-desc -->

			<div class="eltdf-section-content">
				<div class="container-fluid">
					<div class="row">
						<div class="col-lg-12">
							<ul class="eltd-gallery-images-holder clearfix">
								<?php
								$image_gallery_val = get_post_meta( $post->ID, $this->name , true );
								if($image_gallery_val!='' ) $image_gallery_array=explode(',',$image_gallery_val);

								if(isset($image_gallery_array) && count($image_gallery_array)!=0):

									foreach($image_gallery_array as $gimg_id):

										$gimage_wp = wp_get_attachment_image_src($gimg_id,'thumbnail', true);
										echo '<li class="eltd-gallery-image-holder"><img src="'.esc_url($gimage_wp[0]).'"/></li>';

									endforeach;

								endif;
								?>
							</ul>
							<input type="hidden" value="<?php echo esc_attr($image_gallery_val); ?>" id="<?php echo esc_attr( $this->name) ?>" name="<?php echo esc_attr( $this->name) ?>">
							<div class="eltdf-gallery-uploader">
								<a class="eltdf-gallery-upload-btn btn btn-sm btn-primary"
								   href="javascript:void(0)"><?php _e('Upload', 'eltd'); ?></a>
								<a class="eltdf-gallery-clear-btn btn btn-sm btn-default pull-right"
								   href="javascript:void(0)"><?php _e('Remove All', 'eltd'); ?></a>
							</div>
						</div>
					</div>
				</div>
			</div>
			<!-- close div.eltdf-section-content -->

		</div>
	<?php

	}
}

/*
   Class: ElatedMooseImagesVideos
   A class that initializes Elated Images Videos
*/
class ElatedMooseImagesVideos implements iElatedMooseRender {
	private $label;
	private $description;


	function __construct($label="",$description="") {
		$this->label = $label;
		$this->description = $description;
	}

	public function render($factory) {
		global $post;
		?>
		<div class="eltdf_hidden_portfolio_images" style="display: none">
			<div class="eltdf-page-form-section">


				<div class="eltdf-field-desc">
					<h4><?php echo esc_html($this->label); ?></h4>

					<p><?php echo esc_html($this->description); ?></p>
				</div>
				<!-- close div.eltdf-field-desc -->

				<div class="eltdf-section-content">
					<div class="container-fluid">
						<div class="row">
							<div class="col-lg-2">
								<em class="eltdf-field-description">Order Number</em>
								<input type="text"
									   class="form-control eltdf-input eltdf-form-element"
									   id="portfolioimgordernumber_x"
									   name="portfolioimgordernumber_x"
									   placeholder=""/></div>
							<div class="col-lg-10">
								<em class="eltdf-field-description">Image/Video title (only for gallery layout - Portfolio Style 6)</em>
								<input type="text"
									   class="form-control eltdf-input eltdf-form-element"
									   id="portfoliotitle_x"
									   name="portfoliotitle_x"
									   placeholder=""/></div>
						</div>
						<div class="row next-row">
							<div class="col-lg-12">
								<em class="eltdf-field-description">Image</em>
								<div class="eltdf-media-uploader">
									<div style="display: none"
										 class="eltdf-media-image-holder">
										<img src="" alt=""
											 class="eltdf-media-image img-thumbnail"/>
									</div>
									<div style="display: none"
										 class="eltdf-media-meta-fields">
										<input type="hidden" class="eltdf-media-upload-url"
											   name="portfolioimg_x"
											   id="portfolioimg_x"/>
										<input type="hidden"
											   class="eltdf-media-upload-height"
											   name="eltd_options_theme[media-upload][height]"
											   value=""/>
										<input type="hidden"
											   class="eltdf-media-upload-width"
											   name="eltd_options_theme[media-upload][width]"
											   value=""/>
									</div>
									<a class="eltdf-media-upload-btn btn btn-sm btn-primary"
									   href="javascript:void(0)"
									   data-frame-title="<?php _e('Select Image', 'eltd'); ?>"
									   data-frame-button-text="<?php _e('Select Image', 'eltd'); ?>"><?php _e('Upload', 'eltd'); ?></a>
									<a style="display: none;" href="javascript: void(0)"
									   class="eltdf-media-remove-btn btn btn-default btn-sm"><?php _e('Remove', 'eltd'); ?></a>
								</div>
							</div>
						</div>
						<div class="row next-row">
							<div class="col-lg-3">
								<em class="eltdf-field-description">Video type</em>
								<select class="form-control eltdf-form-element eltdf-portfoliovideotype"
										name="portfoliovideotype_x" id="portfoliovideotype_x">
									<option value=""></option>
									<option value="youtube">Youtube</option>
									<option value="vimeo">Vimeo</option>
									<option value="self">Self hosted</option>
								</select>
							</div>
							<div class="col-lg-3">
								<em class="eltdf-field-description">Video ID</em>
								<input type="text"
									   class="form-control eltdf-input eltdf-form-element"
									   id="portfoliovideoid_x"
									   name="portfoliovideoid_x"
									   placeholder=""/></div>
						</div>
						<div class="row next-row">
							<div class="col-lg-12">
								<em class="eltdf-field-description">Video image</em>
								<div class="eltdf-media-uploader">
									<div style="display: none"
										 class="eltdf-media-image-holder">
										<img src="" alt=""
											 class="eltdf-media-image img-thumbnail"/>
									</div>
									<div style="display: none"
										 class="eltdf-media-meta-fields">
										<input type="hidden" class="eltdf-media-upload-url"
											   name="portfoliovideoimage_x"
											   id="portfoliovideoimage_x"/>
										<input type="hidden"
											   class="eltdf-media-upload-height"
											   name="eltd_options_theme[media-upload][height]"
											   value=""/>
										<input type="hidden"
											   class="eltdf-media-upload-width"
											   name="eltd_options_theme[media-upload][width]"
											   value=""/>
									</div>
									<a class="eltdf-media-upload-btn btn btn-sm btn-primary"
									   href="javascript:void(0)"
									   data-frame-title="<?php _e('Select Image', 'eltd'); ?>"
									   data-frame-button-text="<?php _e('Select Image', 'eltd'); ?>"><?php _e('Upload', 'eltd'); ?></a>
									<a style="display: none;" href="javascript: void(0)"
									   class="eltdf-media-remove-btn btn btn-default btn-sm"><?php _e('Remove', 'eltd'); ?></a>
								</div>
							</div>
						</div>
						<div class="row next-row">
							<div class="col-lg-4">
								<em class="eltdf-field-description">Video webm</em>
								<input type="text"
									   class="form-control eltdf-input eltdf-form-element"
									   id="portfoliovideowebm_x"
									   name="portfoliovideowebm_x"
									   placeholder=""/></div>
							<div class="col-lg-4">
								<em class="eltdf-field-description">Video mp4</em>
								<input type="text"
									   class="form-control eltdf-input eltdf-form-element"
									   id="portfoliovideomp4_x"
									   name="portfoliovideomp4_x"
									   placeholder=""/></div>
							<div class="col-lg-4">
								<em class="eltdf-field-description">Video ogv</em>
								<input type="text"
									   class="form-control eltdf-input eltdf-form-element"
									   id="portfoliovideoogv_x"
									   name="portfoliovideoogv_x"
									   placeholder=""/></div>
						</div>
						<div class="row next-row">
							<div class="col-lg-12">
								<a class="eltdf_remove_image btn btn-sm btn-primary" href="/" onclick="javascript: return false;">Remove portfolio image/video</a>
							</div>
						</div>



					</div>
				</div>
				<!-- close div.eltdf-section-content -->

			</div>
		</div>

		<?php
		$no = 1;
		$portfolio_images = get_post_meta( $post->ID, 'eltd_portfolio_images', true );
		if (count($portfolio_images)>1) {
			usort($portfolio_images, "eltdMooseComparePortfolioImages");
		}
		while (isset($portfolio_images[$no-1])) {
			$portfolio_image = $portfolio_images[$no-1];
			?>
			<div class="eltdf_portfolio_image" rel="<?php echo esc_attr($no); ?>" style="display: block;">

				<div class="eltdf-page-form-section">


					<div class="eltdf-field-desc">
						<h4><?php echo esc_html($this->label); ?></h4>

						<p><?php echo esc_html($this->description); ?></p>
					</div>
					<!-- close div.eltdf-field-desc -->

					<div class="eltdf-section-content">
						<div class="container-fluid">
							<div class="row">
								<div class="col-lg-2">
									<em class="eltdf-field-description">Order Number</em>
									<input type="text"
										   class="form-control eltdf-input eltdf-form-element"
										   id="portfolioimgordernumber_<?php echo esc_attr($no); ?>"
										   name="portfolioimgordernumber[]" value="<?php echo isset($portfolio_image['portfolioimgordernumber']) ? esc_attr(stripslashes($portfolio_image['portfolioimgordernumber'])) : ""; ?>"
										   placeholder=""/></div>
								<div class="col-lg-10">
									<em class="eltdf-field-description">Image/Video title (only for gallery layout - Portfolio Style 6)</em>
									<input type="text"
										   class="form-control eltdf-input eltdf-form-element"
										   id="portfoliotitle_<?php echo esc_attr($no); ?>"
										   name="portfoliotitle[]" value="<?php echo isset($portfolio_image['portfoliotitle']) ? esc_attr(stripslashes($portfolio_image['portfoliotitle'])) : ""; ?>"
										   placeholder=""/></div>
							</div>
							<div class="row next-row">
								<div class="col-lg-12">
									<em class="eltdf-field-description">Image</em>
									<div class="eltdf-media-uploader">
										<div<?php if (stripslashes($portfolio_image['portfolioimg']) == false) { ?> style="display: none"<?php } ?>
											class="eltdf-media-image-holder">
											<img src="<?php if (stripslashes($portfolio_image['portfolioimg']) == true) { echo esc_url(eltdf_moose_get_attachment_thumb_url(stripslashes($portfolio_image['portfolioimg']),get_option( 'thumbnail' . '_size_w' ),get_option( 'thumbnail' . '_size_h' ))); } ?>" alt=""
												 class="eltdf-media-image img-thumbnail"/>
										</div>
										<div style="display: none"
											 class="eltdf-media-meta-fields">
											<input type="hidden" class="eltdf-media-upload-url"
												   name="portfolioimg[]"
												   id="portfolioimg_<?php echo esc_attr($no); ?>"
												   value="<?php echo stripslashes($portfolio_image['portfolioimg']); ?>"/>
											<input type="hidden"
												   class="eltdf-media-upload-height"
												   name="eltd_options_theme[media-upload][height]"
												   value=""/>
											<input type="hidden"
												   class="eltdf-media-upload-width"
												   name="eltd_options_theme[media-upload][width]"
												   value=""/>
										</div>
										<a class="eltdf-media-upload-btn btn btn-sm btn-primary"
										   href="javascript:void(0)"
										   data-frame-title="<?php _e('Select Image', 'eltd'); ?>"
										   data-frame-button-text="<?php _e('Select Image', 'eltd'); ?>"><?php _e('Upload', 'eltd'); ?></a>
										<a style="display: none;" href="javascript: void(0)"
										   class="eltdf-media-remove-btn btn btn-default btn-sm"><?php _e('Remove', 'eltd'); ?></a>
									</div>
								</div>
							</div>
							<div class="row next-row">
								<div class="col-lg-3">
									<em class="eltdf-field-description">Video type</em>
									<select class="form-control eltdf-form-element eltdf-portfoliovideotype"
											name="portfoliovideotype[]" id="portfoliovideotype_<?php echo esc_attr($no); ?>">
										<option value=""></option>
										<option <?php if ($portfolio_image['portfoliovideotype'] == "youtube") { echo "selected='selected'"; } ?>  value="youtube">Youtube</option>
										<option <?php if ($portfolio_image['portfoliovideotype'] == "vimeo") { echo "selected='selected'"; } ?>  value="vimeo">Vimeo</option>
										<option <?php if ($portfolio_image['portfoliovideotype'] == "self") { echo "selected='selected'"; } ?>  value="self">Self hosted</option>
									</select>
								</div>
								<div class="col-lg-3">
									<em class="eltdf-field-description">Video ID</em>
									<input type="text"
										   class="form-control eltdf-input eltdf-form-element"
										   id="portfoliovideoid_<?php echo esc_attr($no); ?>"
										   name="portfoliovideoid[]" value="<?php echo isset($portfolio_image['portfoliovideoid']) ? esc_attr(stripslashes($portfolio_image['portfoliovideoid'])) : ""; ?>"
										   placeholder=""/></div>
							</div>
							<div class="row next-row">
								<div class="col-lg-12">
									<em class="eltdf-field-description">Video image</em>
									<div class="eltdf-media-uploader">
										<div<?php if (stripslashes($portfolio_image['portfoliovideoimage']) == false) { ?> style="display: none"<?php } ?>
											class="eltdf-media-image-holder">
											<img src="<?php if (stripslashes($portfolio_image['portfoliovideoimage']) == true) { echo esc_url(eltdf_moose_get_attachment_thumb_url(stripslashes($portfolio_image['portfoliovideoimage']),get_option( 'thumbnail' . '_size_w' ),get_option( 'thumbnail' . '_size_h' ))); } ?>" alt=""
												 class="eltdf-media-image img-thumbnail"/>
										</div>
										<div style="display: none"
											 class="eltdf-media-meta-fields">
											<input type="hidden" class="eltdf-media-upload-url"
												   name="portfoliovideoimage[]"
												   id="portfoliovideoimage_<?php echo esc_attr($no); ?>"
												   value="<?php echo stripslashes($portfolio_image['portfoliovideoimage']); ?>"/>
											<input type="hidden"
												   class="eltdf-media-upload-height"
												   name="eltd_options_theme[media-upload][height]"
												   value=""/>
											<input type="hidden"
												   class="eltdf-media-upload-width"
												   name="eltd_options_theme[media-upload][width]"
												   value=""/>
										</div>
										<a class="eltdf-media-upload-btn btn btn-sm btn-primary"
										   href="javascript:void(0)"
										   data-frame-title="<?php _e('Select Image', 'eltd'); ?>"
										   data-frame-button-text="<?php _e('Select Image', 'eltd'); ?>"><?php _e('Upload', 'eltd'); ?></a>
										<a style="display: none;" href="javascript: void(0)"
										   class="eltdf-media-remove-btn btn btn-default btn-sm"><?php _e('Remove', 'eltd'); ?></a>
									</div>
								</div>
							</div>
							<div class="row next-row">
								<div class="col-lg-4">
									<em class="eltdf-field-description">Video webm</em>
									<input type="text"
										   class="form-control eltdf-input eltdf-form-element"
										   id="portfoliovideowebm_<?php echo esc_attr($no); ?>"
										   name="portfoliovideowebm[]" value="<?php echo isset($portfolio_image['portfoliovideowebm']) ? esc_attr(stripslashes($portfolio_image['portfoliovideowebm'])) : ""; ?>"
										   placeholder=""/></div>
								<div class="col-lg-4">
									<em class="eltdf-field-description">Video mp4</em>
									<input type="text"
										   class="form-control eltdf-input eltdf-form-element"
										   id="portfoliovideomp4_<?php echo esc_attr($no); ?>"
										   name="portfoliovideomp4[]" value="<?php echo isset($portfolio_image['portfoliovideomp4']) ? esc_attr(stripslashes($portfolio_image['portfoliovideomp4'])) : ""; ?>"
										   placeholder=""/></div>
								<div class="col-lg-4">
									<em class="eltdf-field-description">Video ogv</em>
									<input type="text"
										   class="form-control eltdf-input eltdf-form-element"
										   id="portfoliovideoogv_<?php echo esc_attr($no); ?>"
										   name="portfoliovideoogv[]" value="<?php echo isset($portfolio_image['portfoliovideoogv']) ? esc_attr(stripslashes($portfolio_image['portfoliovideoogv'])):""; ?>"
										   placeholder=""/></div>
							</div>
							<div class="row next-row">
								<div class="col-lg-12">
									<a class="eltdf_remove_image btn btn-sm btn-primary" href="/" onclick="javascript: return false;">Remove portfolio image/video</a>
								</div>
							</div>



						</div>
					</div>
					<!-- close div.eltdf-section-content -->

				</div>
			</div>
			<?php
			$no++;
		}
		?>
		<br />
		<a class="eltdf_add_image btn btn-sm btn-primary" onclick="javascript: return false;" href="/" >Add portfolio image/video</a>
	<?php

	}
}


/*
   Class: ElatedMooseImagesVideos
   A class that initializes Elated Images Videos
*/
class ElatedMooseImagesVideosFramework implements iElatedMooseRender {
	private $label;
	private $description;


	function __construct($label="",$description="") {
		$this->label = $label;
		$this->description = $description;
	}

	public function render($factory) {
		global $post;
		?>

		<!--Image hidden start-->
		<div class="eltdf-hidden-portfolio-images"  style="display: none">
			<div class="eltdf-portfolio-toggle-holder">
				<div class="eltdf-portfolio-toggle eltdf-toggle-desc">
					<span class="number">1</span><span class="eltdf-toggle-inner">Image - <em>(Order Number, Image Title)</em></span>
				</div>
				<div class="eltdf-portfolio-toggle eltdf-portfolio-control">
					<span class="toggle-portfolio-media"><i class="fa fa-caret-up"></i></span>
					<a href="#" class="remove-portfolio-media"><i class="fa fa-times"></i></a>
				</div>
			</div>
			<div class="eltdf-portfolio-toggle-content">
				<div class="eltdf-page-form-section">
					<div class="eltdf-section-content">
						<div class="container-fluid">
							<div class="row">
								<div class="col-lg-2">
									<div class="eltdf-media-uploader">
										<em class="eltdf-field-description">Image </em>
										<div style="display: none" class="eltdf-media-image-holder">
											<img src="" alt="" class="eltdf-media-image img-thumbnail">
										</div>
										<div  class="eltdf-media-meta-fields">
											<input type="hidden" class="eltdf-media-upload-url" name="portfolioimg_x" id="portfolioimg_x">
											<input type="hidden" class="eltdf-media-upload-height" name="eltd_options_theme[media-upload][height]" value="">
											<input type="hidden" class="eltdf-media-upload-width" name="eltd_options_theme[media-upload][width]" value="">
										</div>
										<a class="eltdf-media-upload-btn btn btn-sm btn-primary" href="javascript:void(0)" data-frame-title="Select Image" data-frame-button-text="Select Image">Upload</a>
										<a style="display: none;" href="javascript: void(0)" class="eltdf-media-remove-btn btn btn-default btn-sm">Remove</a>
									</div>
								</div>
								<div class="col-lg-2">
									<em class="eltdf-field-description">Order Number</em>
									<input type="text" class="form-control eltdf-input eltdf-form-element" id="portfolioimgordernumber_x" name="portfolioimgordernumber_x" placeholder="">
								</div>
								<div class="col-lg-8">
									<em class="eltdf-field-description">Image Title (works only for Gallery portfolio type selected) </em>
									<input type="text" class="form-control eltdf-input eltdf-form-element" id="portfoliotitle_x" name="portfoliotitle_x" placeholder="">
								</div>
							</div>
							<input type="hidden" name="portfoliovideoimage_x" id="portfoliovideoimage_x">
							<input type="hidden" name="portfoliovideotype_x" id="portfoliovideotype_x">
							<input type="hidden" name="portfoliovideoid_x" id="portfoliovideoid_x">
							<input type="hidden" name="portfoliovideowebm_x" id="portfoliovideowebm_x">
							<input type="hidden" name="portfoliovideomp4_x" id="portfoliovideomp4_x">
							<input type="hidden" name="portfoliovideoogv_x" id="portfoliovideoogv_x">
							<input type="hidden" name="portfolioimgtype_x" id="portfolioimgtype_x" value="image">

						</div><!-- close div.container-fluid -->
					</div><!-- close div.eltdf-section-content -->
				</div>
			</div>
		</div>
		<!--Image hidden End-->

		<!--Video Hidden Start-->
		<div class="eltdf-hidden-portfolio-videos"  style="display: none">
			<div class="eltdf-portfolio-toggle-holder">
				<div class="eltdf-portfolio-toggle eltdf-toggle-desc">
					<span class="number">2</span><span class="eltdf-toggle-inner">Video - <em>(Order Number, Video Title)</em></span>
				</div>
				<div class="eltdf-portfolio-toggle eltdf-portfolio-control">
					<span class="toggle-portfolio-media"><i class="fa fa-caret-up"></i></span> <a href="#" class="remove-portfolio-media"><i class="fa fa-times"></i></a>
				</div>
			</div>
			<div class="eltdf-portfolio-toggle-content">
				<div class="eltdf-page-form-section">
					<div class="eltdf-section-content">
						<div class="container-fluid">
							<div class="row">
								<div class="col-lg-2">
									<div class="eltdf-media-uploader">
										<em class="eltdf-field-description">Cover Video Image </em>
										<div style="display: none" class="eltdf-media-image-holder">
											<img src="" alt="" class="eltdf-media-image img-thumbnail">
										</div>
										<div style="display: none" class="eltdf-media-meta-fields">
											<input type="hidden" class="eltdf-media-upload-url" name="portfoliovideoimage_x" id="portfoliovideoimage_x">
											<input type="hidden" class="eltdf-media-upload-height" name="eltd_options_theme[media-upload][height]" value="">
											<input type="hidden" class="eltdf-media-upload-width" name="eltd_options_theme[media-upload][width]" value="">
										</div>
										<a class="eltdf-media-upload-btn btn btn-sm btn-primary" href="javascript:void(0)" data-frame-title="Select Image" data-frame-button-text="Select Image">Upload</a>
										<a style="display: none;" href="javascript: void(0)" class="eltdf-media-remove-btn btn btn-default btn-sm">Remove</a>
									</div>
								</div>
								<div class="col-lg-10">
									<div class="row">
										<div class="col-lg-2">
											<em class="eltdf-field-description">Order Number</em>
											<input type="text" class="form-control eltdf-input eltdf-form-element" id="portfolioimgordernumber_x" name="portfolioimgordernumber_x" placeholder="">
										</div>
										<div class="col-lg-10">
											<em class="eltdf-field-description">Video Title (works only for Gallery portfolio type selected)</em>
											<input type="text" class="form-control eltdf-input eltdf-form-element" id="portfoliotitle_x" name="portfoliotitle_x" placeholder="">
										</div>
									</div>
									<div class="row next-row">
										<div class="col-lg-2">
											<em class="eltdf-field-description">Video type</em>
											<select class="form-control eltdf-form-element eltdf-portfoliovideotype" name="portfoliovideotype_x" id="portfoliovideotype_x">
												<option value=""></option>
												<option value="youtube">Youtube</option>
												<option value="vimeo">Vimeo</option>
												<option value="self">Self hosted</option>
											</select>
										</div>
										<div class="col-lg-2 eltdf-video-id-holder">
											<em class="eltdf-field-description" id="videoId">Video ID</em>
											<input type="text" class="form-control eltdf-input eltdf-form-element" id="portfoliovideoid_x" name="portfoliovideoid_x" placeholder="">
										</div>
									</div>

									<div class="row next-row eltdf-video-self-hosted-path-holder">
										<div class="col-lg-4">
											<em class="eltdf-field-description">Video webm</em>
											<input type="text" class="form-control eltdf-input eltdf-form-element" id="portfoliovideowebm_x" name="portfoliovideowebm_x" placeholder="">
										</div>
										<div class="col-lg-4">
											<em class="eltdf-field-description">Video mp4</em>
											<input type="text" class="form-control eltdf-input eltdf-form-element" id="portfoliovideomp4_x" name="portfoliovideomp4_x" placeholder="">
										</div>
										<div class="col-lg-4">
											<em class="eltdf-field-description">Video ogv</em>
											<input type="text" class="form-control eltdf-input eltdf-form-element" id="portfoliovideoogv_x" name="portfoliovideoogv_x" placeholder="">
										</div>
									</div>
								</div>

							</div>
							<input type="hidden" name="portfolioimg_x" id="portfolioimg_x">
							<input type="hidden" name="portfolioimgtype_x" id="portfolioimgtype_x" value="video">
						</div><!-- close div.container-fluid -->
					</div><!-- close div.eltdf-section-content -->
				</div>
			</div>
		</div>
		<!--Video Hidden End-->


		<?php
		$no = 1;
		$portfolio_images = get_post_meta( $post->ID, 'eltd_portfolio_images', true );
		if (count($portfolio_images)>1) {
			usort($portfolio_images, "eltdMooseComparePortfolioImages");
		}
		while (isset($portfolio_images[$no-1])) {
			$portfolio_image = $portfolio_images[$no-1];
			if (isset($portfolio_image['portfolioimgtype']))
				$portfolio_img_type = $portfolio_image['portfolioimgtype'];
			else {
				if (stripslashes($portfolio_image['portfolioimg']) == true)
					$portfolio_img_type = "image";
				else
					$portfolio_img_type = "video";
			}
			if ($portfolio_img_type == "image") {
				?>

				<div class="eltdf-portfolio-images eltdf-portfolio-media" rel="<?php echo esc_attr($no); ?>">
					<div class="eltdf-portfolio-toggle-holder">
						<div class="eltdf-portfolio-toggle eltdf-toggle-desc">
							<span class="number"><?php echo esc_html($no); ?></span><span class="eltdf-toggle-inner">Image - <em>(<?php echo stripslashes($portfolio_image['portfolioimgordernumber']); ?>, <?php echo stripslashes($portfolio_image['portfoliotitle']); ?>)</em></span>
						</div>
						<div class="eltdf-portfolio-toggle eltdf-portfolio-control">
							<a href="#" class="toggle-portfolio-media"><i class="fa fa-caret-down"></i></a>
							<a href="#" class="remove-portfolio-media"><i class="fa fa-times"></i></a>
						</div>
					</div>
					<div class="eltdf-portfolio-toggle-content" style="display: none">
						<div class="eltdf-page-form-section">
							<div class="eltdf-section-content">
								<div class="container-fluid">
									<div class="row">
										<div class="col-lg-2">
											<div class="eltdf-media-uploader">
												<em class="eltdf-field-description">Image </em>
												<div<?php if (stripslashes($portfolio_image['portfolioimg']) == false) { ?> style="display: none"<?php } ?>
													class="eltdf-media-image-holder">
													<img src="<?php if (stripslashes($portfolio_image['portfolioimg']) == true) { echo esc_url(eltdf_moose_get_attachment_thumb_url(stripslashes($portfolio_image['portfolioimg']),get_option( 'thumbnail' . '_size_w' ),get_option( 'thumbnail' . '_size_h' ))); } ?>" alt=""
														 class="eltdf-media-image img-thumbnail"/>
												</div>
												<div style="display: none"
													 class="eltdf-media-meta-fields">
													<input type="hidden" class="eltdf-media-upload-url"
														   name="portfolioimg[]"
														   id="portfolioimg_<?php echo esc_attr($no); ?>"
														   value="<?php echo stripslashes($portfolio_image['portfolioimg']); ?>"/>
													<input type="hidden"
														   class="eltdf-media-upload-height"
														   name="eltd_options_theme[media-upload][height]"
														   value=""/>
													<input type="hidden"
														   class="eltdf-media-upload-width"
														   name="eltd_options_theme[media-upload][width]"
														   value=""/>
												</div>
												<a class="eltdf-media-upload-btn btn btn-sm btn-primary"
												   href="javascript:void(0)"
												   data-frame-title="<?php _e('Select Image', 'eltd'); ?>"
												   data-frame-button-text="<?php _e('Select Image', 'eltd'); ?>"><?php _e('Upload', 'eltd'); ?></a>
												<a style="display: none;" href="javascript: void(0)"
												   class="eltdf-media-remove-btn btn btn-default btn-sm"><?php _e('Remove', 'eltd'); ?></a>
											</div>
										</div>
										<div class="col-lg-2">
											<em class="eltdf-field-description">Order Number</em>
											<input type="text" class="form-control eltdf-input eltdf-form-element" id="portfolioimgordernumber_<?php echo esc_attr($no); ?>" name="portfolioimgordernumber[]" value="<?php echo isset($portfolio_image['portfolioimgordernumber']) ? esc_attr(stripslashes($portfolio_image['portfolioimgordernumber'])) : ""; ?>" placeholder="">
										</div>
										<div class="col-lg-8">
											<em class="eltdf-field-description">Image Title (works only for Gallery portfolio type selected) </em>
											<input type="text" class="form-control eltdf-input eltdf-form-element" id="portfoliotitle_<?php echo esc_attr($no); ?>" name="portfoliotitle[]" value="<?php echo isset($portfolio_image['portfoliotitle']) ? esc_attr(stripslashes($portfolio_image['portfoliotitle'])) : ""; ?>" placeholder="">
										</div>
									</div>
									<input type="hidden" id="portfoliovideoimage_<?php echo esc_attr($no); ?>" name="portfoliovideoimage[]">
									<input type="hidden" id="portfoliovideotype_<?php echo esc_attr($no); ?>" name="portfoliovideotype[]">
									<input type="hidden" id="portfoliovideoid_<?php echo esc_attr($no); ?>" name="portfoliovideoid[]">
									<input type="hidden" id="portfoliovideowebm_<?php echo esc_attr($no); ?>" name="portfoliovideowebm[]">
									<input type="hidden" id="portfoliovideomp4_<?php echo esc_attr($no); ?>" name="portfoliovideomp4[]">
									<input type="hidden" id="portfoliovideoogv_<?php echo esc_attr($no); ?>" name="portfoliovideoogv[]">
									<input type="hidden" id="portfolioimgtype_<?php echo esc_attr($no); ?>" name="portfolioimgtype[]" value="image">
								</div><!-- close div.container-fluid -->
							</div><!-- close div.eltdf-section-content -->
						</div>
					</div>
				</div>

			<?php
			} else {
				?>
				<div class="eltdf-portfolio-videos eltdf-portfolio-media" rel="<?php echo esc_attr($no); ?>">
					<div class="eltdf-portfolio-toggle-holder">
						<div class="eltdf-portfolio-toggle eltdf-toggle-desc">
							<span class="number"><?php echo esc_html($no); ?></span><span class="eltdf-toggle-inner">Video - <em>(<?php echo stripslashes($portfolio_image['portfolioimgordernumber']); ?>, <?php echo stripslashes($portfolio_image['portfoliotitle']); ?></em>) </span>
						</div>
						<div class="eltdf-portfolio-toggle eltdf-portfolio-control">
							<a href="#" class="toggle-portfolio-media"><i class="fa fa-caret-down"></i></a> <a href="#" class="remove-portfolio-media"><i class="fa fa-times"></i></a>
						</div>
					</div>
					<div class="eltdf-portfolio-toggle-content" style="display: none">
						<div class="eltdf-page-form-section">
							<div class="eltdf-section-content">
								<div class="container-fluid">
									<div class="row">
										<div class="col-lg-2">
											<div class="eltdf-media-uploader">
												<em class="eltdf-field-description">Cover Video Image </em>
												<div<?php if (stripslashes($portfolio_image['portfoliovideoimage']) == false) { ?> style="display: none"<?php } ?>
													class="eltdf-media-image-holder">
													<img src="<?php if (stripslashes($portfolio_image['portfoliovideoimage']) == true) { echo esc_url(eltdf_moose_get_attachment_thumb_url(stripslashes($portfolio_image['portfoliovideoimage']),get_option( 'thumbnail' . '_size_w' ),get_option( 'thumbnail' . '_size_h' ))); } ?>" alt=""
														 class="eltdf-media-image img-thumbnail"/>
												</div>
												<div style="display: none"
													 class="eltdf-media-meta-fields">
													<input type="hidden" class="eltdf-media-upload-url"
														   name="portfoliovideoimage[]"
														   id="portfoliovideoimage_<?php echo esc_attr($no); ?>"
														   value="<?php echo stripslashes($portfolio_image['portfoliovideoimage']); ?>"/>
													<input type="hidden"
														   class="eltdf-media-upload-height"
														   name="eltd_options_theme[media-upload][height]"
														   value=""/>
													<input type="hidden"
														   class="eltdf-media-upload-width"
														   name="eltd_options_theme[media-upload][width]"
														   value=""/>
												</div>
												<a class="eltdf-media-upload-btn btn btn-sm btn-primary"
												   href="javascript:void(0)"
												   data-frame-title="<?php _e('Select Image', 'eltd'); ?>"
												   data-frame-button-text="<?php _e('Select Image', 'eltd'); ?>"><?php _e('Upload', 'eltd'); ?></a>
												<a style="display: none;" href="javascript: void(0)"
												   class="eltdf-media-remove-btn btn btn-default btn-sm"><?php _e('Remove', 'eltd'); ?></a>
											</div>
										</div>
										<div class="col-lg-10">
											<div class="row">
												<div class="col-lg-2">
													<em class="eltdf-field-description">Order Number</em>
													<input type="text" class="form-control eltdf-input eltdf-form-element" id="portfolioimgordernumber_<?php echo esc_attr($no); ?>" name="portfolioimgordernumber[]" value="<?php echo isset($portfolio_image['portfolioimgordernumber']) ? esc_attr(stripslashes($portfolio_image['portfolioimgordernumber'])) : ""; ?>" placeholder="">
												</div>
												<div class="col-lg-10">
													<em class="eltdf-field-description">Video Title (works only for Gallery portfolio type selected) </em>
													<input type="text" class="form-control eltdf-input eltdf-form-element" id="portfoliotitle_<?php echo esc_attr($no); ?>" name="portfoliotitle[]" value="<?php echo isset($portfolio_image['portfoliotitle']) ? esc_attr(stripslashes($portfolio_image['portfoliotitle'])) : ""; ?>" placeholder="">
												</div>
											</div>
											<div class="row next-row">
												<div class="col-lg-2">
													<em class="eltdf-field-description">Video Type</em>
													<select class="form-control eltdf-form-element eltdf-portfoliovideotype"
															name="portfoliovideotype[]" id="portfoliovideotype_<?php echo esc_attr($no); ?>">
														<option value=""></option>
														<option <?php if ($portfolio_image['portfoliovideotype'] == "youtube") { echo "selected='selected'"; } ?>  value="youtube">Youtube</option>
														<option <?php if ($portfolio_image['portfoliovideotype'] == "vimeo") { echo "selected='selected'"; } ?>  value="vimeo">Vimeo</option>
														<option <?php if ($portfolio_image['portfoliovideotype'] == "self") { echo "selected='selected'"; } ?>  value="self">Self hosted</option>
													</select>
												</div>
												<div class="col-lg-2 eltdf-video-id-holder">
													<em class="eltdf-field-description">Video ID</em>
													<input type="text"
														   class="form-control eltdf-input eltdf-form-element"
														   id="portfoliovideoid_<?php echo esc_attr($no); ?>"
														   name="portfoliovideoid[]" value="<?php echo isset($portfolio_image['portfoliovideoid']) ? esc_attr(stripslashes($portfolio_image['portfoliovideoid'])) : ""; ?>"
														   placeholder=""/>
												</div>
											</div>

											<div class="row next-row eltdf-video-self-hosted-path-holder">
												<div class="col-lg-4">
													<em class="eltdf-field-description">Video webm</em>
													<input type="text"
														   class="form-control eltdf-input eltdf-form-element"
														   id="portfoliovideowebm_<?php echo esc_attr($no); ?>"
														   name="portfoliovideowebm[]" value="<?php echo isset($portfolio_image['portfoliovideowebm'])? esc_attr(stripslashes($portfolio_image['portfoliovideowebm'])) : ""; ?>"
														   placeholder=""/></div>
												<div class="col-lg-4">
													<em class="eltdf-field-description">Video mp4</em>
													<input type="text"
														   class="form-control eltdf-input eltdf-form-element"
														   id="portfoliovideomp4_<?php echo esc_attr($no); ?>"
														   name="portfoliovideomp4[]" value="<?php echo isset($portfolio_image['portfoliovideomp4']) ? esc_attr(stripslashes($portfolio_image['portfoliovideomp4'])) : ""; ?>"
														   placeholder=""/></div>
												<div class="col-lg-4">
													<em class="eltdf-field-description">Video ogv</em>
													<input type="text"
														   class="form-control eltdf-input eltdf-form-element"
														   id="portfoliovideoogv_<?php echo esc_attr($no); ?>"
														   name="portfoliovideoogv[]" value="<?php echo isset($portfolio_image['portfoliovideoogv']) ? esc_attr(stripslashes($portfolio_image['portfoliovideoogv'])) : ""; ?>"
														   placeholder=""/></div>
											</div>
										</div>

									</div>
									<input type="hidden" id="portfolioimg_<?php echo esc_attr($no); ?>" name="portfolioimg[]">
									<input type="hidden" id="portfolioimgtype_<?php echo esc_attr($no); ?>" name="portfolioimgtype[]" value="video">
								</div><!-- close div.container-fluid -->
							</div><!-- close div.eltdf-section-content -->
						</div>
					</div>
				</div>
			<?php
			}
			$no++;
		}
		?>

		<div class="eltdf-portfolio-add">
			<a class="eltdf-add-image btn btn-sm btn-primary" href="#"><i class="fa fa-camera"></i> Add Image</a>
			<a class="eltdf-add-video btn btn-sm btn-primary" href="#"><i class="fa fa-video-camera"></i> Add Video</a>

			<a class="eltdf-toggle-all-media btn btn-sm btn-default pull-right" href="#"> Expand All</a>
			<?php /* <a class="eltdf-remove-last-row-media btn btn-sm btn-default pull-right" href="#"> Remove last row</a> */ ?>
		</div>


	<?php

	}
}

class ElatedMooseTwitterFramework implements  iElatedMooseRender {
    public function render($factory) {
        $twitterApi = ElatedTwitterApi::getInstance();
        $message = '';

        if(!empty($_GET['oauth_token']) && !empty($_GET['oauth_verifier'])) {
            if(!empty($_GET['oauth_token'])) {
                update_option($twitterApi::AUTHORIZE_TOKEN_FIELD, $_GET['oauth_token']);
            }

            if(!empty($_GET['oauth_verifier'])) {
                update_option($twitterApi::AUTHORIZE_VERIFIER_FIELD, $_GET['oauth_verifier']);
            }

            $responseObj = $twitterApi->obtainAccessToken();
            if($responseObj->status) {
                $message = __('You have successfully connected with your Twitter account. If you have any issues fetching data from Twitter try reconnecting.', 'eltd');
            } else {
                $message = $responseObj->message;
            }
        }

        $buttonText = $twitterApi->hasUserConnected() ? __('Re-connect with Twitter', 'eltd') : __('Connect with Twitter', 'eltd');
    ?>
        <?php if($message !== '') { ?>
            <div class="alert alert-success" style="margin-top: 20px;">
                <span><?php echo esc_html($message); ?></span>
            </div>
        <?php } ?>
        <div class="eltdf-page-form-section" id="eltdf_enable_social_share">

            <div class="eltdf-field-desc">
                <h4><?php _e('Connect with Twitter', 'eltd'); ?></h4>

                <p><?php _e('Connecting with Twitter will enable you to show your latest tweets on your site', 'eltd'); ?></p>
            </div>
            <!-- close div.eltdf-field-desc -->

            <div class="eltdf-section-content">
                <div class="container-fluid">
                    <div class="row">
                        <div class="col-lg-12">
                            <a id="eltdf-tw-request-token-btn" class="btn btn-primary" href="#"><?php echo esc_html($buttonText); ?></a>
                            <input type="hidden" data-name="current-page-url" value="<?php echo esc_url($twitterApi->buildCurrentPageURI()); ?>"/>
                        </div>
                    </div>
                </div>
            </div>
            <!-- close div.eltdf-section-content -->

        </div>
    <?php }

}

/*
   Class: ElatedMooseImagesVideos
   A class that initializes Elated Images Videos
*/
class ElatedMooseOptionsFramework implements iElatedMooseRender {
	private $label;
	private $description;


	function __construct($label="",$description="") {
		$this->label = $label;
		$this->description = $description;
	}

	public function render($factory) {
		global $post;
		?>

		<div class="eltdf-portfolio-additional-item-holder" style="display: none">
			<div class="eltdf-portfolio-toggle-holder">
				<div class="eltdf-portfolio-toggle eltdf-toggle-desc">
					<span class="number">1</span><span class="eltdf-toggle-inner">Additional Sidebar Item <em>(Order Number, Item Title)</em></span>
				</div>
				<div class="eltdf-portfolio-toggle eltdf-portfolio-control">
					<span class="toggle-portfolio-item"><i class="fa fa-caret-up"></i></span>
					<a href="#" class="remove-portfolio-item"><i class="fa fa-times"></i></a>
				</div>
			</div>
			<div class="eltdf-portfolio-toggle-content">
				<div class="eltdf-page-form-section">
					<div class="eltdf-section-content">
						<div class="container-fluid">
							<div class="row">

								<div class="col-lg-2">
									<em class="eltdf-field-description">Order Number</em>
									<input type="text" class="form-control eltdf-input eltdf-form-element" id="optionlabelordernumber_x" name="optionlabelordernumber_x" placeholder="">
								</div>
								<div class="col-lg-10">
									<em class="eltdf-field-description">Item Title </em>
									<input type="text" class="form-control eltdf-input eltdf-form-element" id="optionLabel_x" name="optionLabel_x" placeholder="">
								</div>
							</div>
							<div class="row next-row">
								<div class="col-lg-12">
									<em class="eltdf-field-description">Item Text</em>
									<textarea class="form-control eltdf-input eltdf-form-element" id="optionValue_x" name="optionValue_x" placeholder=""></textarea>
								</div>
							</div>
							<div class="row next-row">
								<div class="col-lg-12">
									<em class="eltdf-field-description">Enter Full URL for Item Text Link</em>
									<input type="text" class="form-control eltdf-input eltdf-form-element" id="optionUrl_x" name="optionUrl_x" placeholder="">
								</div>
							</div>
						</div><!-- close div.eltdf-section-content -->
					</div><!-- close div.container-fluid -->
				</div>
			</div>
		</div>
		<?php
		$no = 1;
		$portfolios = get_post_meta( $post->ID, 'eltd_portfolios', true );
		if (count($portfolios)>1) {
			usort($portfolios, "eltdMooseComparePortfolioOptions");
		}
		while (isset($portfolios[$no-1])) {
			$portfolio = $portfolios[$no-1];
			?>
			<div class="eltdf-portfolio-additional-item" rel="<?php echo esc_attr($no); ?>">
				<div class="eltdf-portfolio-toggle-holder">
					<div class="eltdf-portfolio-toggle eltdf-toggle-desc">
						<span class="number"><?php echo esc_html($no); ?></span><span class="eltdf-toggle-inner">Additional Sidebar Item - <em>(<?php echo stripslashes($portfolio['optionlabelordernumber']); ?>, <?php echo stripslashes($portfolio['optionLabel']); ?>)</em></span>
					</div>
					<div class="eltdf-portfolio-toggle eltdf-portfolio-control">
						<span class="toggle-portfolio-item"><i class="fa fa-caret-down"></i></span>
						<a href="#" class="remove-portfolio-item"><i class="fa fa-times"></i></a>
					</div>
				</div>
				<div class="eltdf-portfolio-toggle-content" style="display: none">
					<div class="eltdf-page-form-section">
						<div class="eltdf-section-content">
							<div class="container-fluid">
								<div class="row">

									<div class="col-lg-2">
										<em class="eltdf-field-description">Order Number</em>
										<input type="text" class="form-control eltdf-input eltdf-form-element" id="optionlabelordernumber_<?php echo esc_attr($no); ?>" name="optionlabelordernumber[]" value="<?php echo isset($portfolio['optionlabelordernumber']) ? esc_attr(stripslashes($portfolio['optionlabelordernumber'])) : ""; ?>" placeholder="">
									</div>
									<div class="col-lg-10">
										<em class="eltdf-field-description">Item Title </em>
										<input type="text" class="form-control eltdf-input eltdf-form-element" id="optionLabel_<?php echo esc_attr($no); ?>" name="optionLabel[]" value="<?php echo esc_attr(stripslashes($portfolio['optionLabel'])); ?>" placeholder="">
									</div>
								</div>
								<div class="row next-row">
									<div class="col-lg-12">
										<em class="eltdf-field-description">Item Text</em>
										<textarea class="form-control eltdf-input eltdf-form-element" id="optionValue_<?php echo esc_attr($no); ?>" name="optionValue[]" placeholder=""><?php echo esc_attr(stripslashes($portfolio['optionValue'])); ?></textarea>
									</div>
								</div>
								<div class="row next-row">
									<div class="col-lg-12">
										<em class="eltdf-field-description">Enter Full URL for Item Text Link</em>
										<input type="text" class="form-control eltdf-input eltdf-form-element" id="optionUrl_<?php echo esc_attr($no); ?>" name="optionUrl[]" value="<?php echo stripslashes($portfolio['optionUrl']); ?>" placeholder="">
									</div>
								</div>
							</div><!-- close div.eltdf-section-content -->
						</div><!-- close div.container-fluid -->
					</div>
				</div>
			</div>
			<?php
			$no++;
		}
		?>

		<div class="eltdf-portfolio-add">
			<a class="eltdf-add-item btn btn-sm btn-primary" href="#"> Add New Item</a>


			<a class="eltdf-toggle-all-item btn btn-sm btn-default pull-right" href="#"> Expand All</a>
			<?php /* <a class="eltdf-remove-last-item-row btn btn-sm btn-default pull-right" href="#"> Remove Last Row</a> */ ?>
		</div>
	<?php

	}
}