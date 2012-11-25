<?php

/**
 * @file
 * Configuration forms
 */

/**
 * Form for the general settings
 */
function highslide2_options_form() {
  $options = variable_get('highslide2_options', _highslide2_default_options());

  //control if the higslide script is downladed  
  $path = _highslide2_js_path();
  if (!$path) {
    drupal_set_message(t('The Highslide JS file was not found.  Please review the INSTALL.txt file included with the Highslide module for installation instructions.'), 'error'); 
  }
  
  $form = array();

  $form['highslide2_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Highslide options'),
    '#tree' => TRUE,
  );

  $form['highslide2_options']['graphicsDir'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Highslide Graphics Directory'),
    '#default_value'  => $options['graphicsDir'],
    '#description'    => t('Leading and trailing slashes must be placed.'),
  );

  $form['highslide2_options']['autoEnableAllImages'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Enable for all image links'),
    '#description'    => t('Enable this option to automatically add the <code>class="highslide"</code> attribute to all links pointing to an image file.'),
    '#default_value'  => $options['autoEnableAllImages'],
  );

  $form['highslide2_options']['enableAllImages'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Text origin'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#states'      => array(
      'visible'     => array(
        ':input[name="highslide2_options[autoEnableAllImages]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['highslide2_options']['enableAllImages']['heading'] = array(
    '#title'         => t('Heading'),
    '#type'          => 'select',
    '#default_value' => $options['enableAllImages']['heading'],
    '#options'       => _highslide2_enum_sourceText('global'),
    '#description'   => t('Select the source of the heading text, if the option "show heading" is enabled in the default formatter.'),
  );

  $form['highslide2_options']['enableAllImages']['caption'] = array(
    '#title'         => t('Caption'),
    '#type'          => 'select',
    '#default_value' => $options['enableAllImages']['caption'],
    '#options'       => _highslide2_enum_sourceText('global'),
    '#description'   => t('What is the source of the caption text, if the option "show caption" is enabled in the default formatter.'),
  );

  $form['highslide2_options']['allowMultipleInstances'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Allow multiple instances'),
    '#description'    => t('Allow more than one popup expander to be open at the same time. If this options is not enables, the opened expanders will close when you click to open another.'),
    '#default_value'  => $options['allowMultipleInstances'],
  );

  $form['highslide2_options']['language'] = array(
    '#type'           => 'select',
    '#title'          => t('Language'),
    '#description'    => t('Default language used by Highslide to dsiplay messages. The module will first try to use the language of the site and, if the file language is not available, it will use the default language.'),
    '#default_value'  => $options['language'],
    '#options'        => _highslide2_get_languages_available(),
  );


  $form['highslide2_options']['align'] = array(
    '#type'          => 'radios',
    '#title'         => t('Align'),
    '#default_value' => $options['align'],
    '#options'       => array(
      'auto'            => t('Auto'),
      'center'          => t('Center'),
    ),
    '#description'   => t('Position of the full image in the client.  <a href="@href" target="_blank">Click here</a> for more details.', array('@href' => 'http://highslide.com/ref/hs.align')),
  );

 $form['highslide2_options']['outlineType'] = array(
    '#type'          => 'select',
    '#title'         => t('Outline'),
    '#default_value' => $options['outlineType'],
    '#options'       => _highslide2_enum_outlineType(),
    '#description'   => t('The graphic outline to display around the expanded content.  <a href="@href" target="_blank">Click here</a> for more details.', array('@href' => 'http://highslide.com/ref/hs.outlineType')),
  );

  // Credits informations : Begin
  $form['highslide2_options']['showCredits'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Enable the credit text'),
    '#description'    => t('Enable this option to display the credit information in the image (i.e. copyright).'),
    '#default_value'  => $options['showCredits'],
  );

  $form['highslide2_options']['credits'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Credits Information'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#states'      => array(
      'visible'     => array(
        ':input[name="highslide2_options[showCredits]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['highslide2_options']['credits']['creditsText'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Credit label'),
    '#default_value'  => $options['credits']['creditsText'],
    '#description'    => t('Highslide credits text will be displayed in the image.'),
  );

  $form['highslide2_options']['credits']['creditsHref'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Credit Hyperlink reference'),
    '#default_value'  => $options['credits']['creditsHref'],
    '#description'    => t('Hyperlink reference for the credits label.  <a href="@href" target="_blank">Click here</a> for more details.', array('@href' => 'http://highslide.com/ref/hs.creditsHref')),
  );

  $form['highslide2_options']['credits']['creditsPosition'] = array(
    '#type'           => 'select',
    '#title'          => t('Credit position'),
    '#default_value'  => $options['credits']['creditsPosition'],
    '#options'        => _highslide2_enum_position('image'),
    '#description'    => t('Specifies where the credits label will appear related to the full-size image. <a href="@href" target="_blank">Click here</a> for more details.', array('@href' => 'http://highslide.com/ref/hs.creditsPosition')),
  );

  $form['highslide2_options']['credits']['creditsTarget'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Credit target'),
    '#default_value'  => $options['credits']['creditsTarget'],
    '#description'    => t('The target controls where the page defined in Credit Hyperlink reference will be displayed. Typical values are <code>_self</code> or <code>_blank</code> open the linked document in the same frame as it was clicked, <code>_blank</code> open the linked document in a new window or tab and <code>_top</code> open the linked document in the full body of the window. <a href="@href" target="_blank">Click here</a> for more details.', array('@href' => 'http://highslide.com/ref/hs.creditsTarget')),
  );

  $form['highslide2_options']['credits']['creditsTitle'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Credit Title'),
    '#default_value'  => $options['credits']['creditsTitle'],
    '#description'    => t('Text displayed when the mouse is placed on the credits label.  <a href="@href" target="_blank">Click here</a> for more details.', array('@href' => 'http://highslide.com/ref/hs.creditsTitle')),
  );
  // Credits informations : End

  $form['highslide2_options']['customizeHighslide'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Customize Highslide settings'),
    '#description'    => t('Enable this option to add your own CSS and/or JS to customize the layout (i.e. if you have used the highslide editor)'),
    '#default_value'  => $options['customizeHighslide'],
  );

  $form['highslide2_options']['custom'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Custom settings'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#states'      => array(
      'visible'     => array(
        ':input[name="highslide2_options[customizeHighslide]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['highslide2_options']['custom']['JS'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Custom JS'),
    '#default_value' => $options['custom']['JS'],
    '#description'   => t('Place JS strings here to apply special formating for highslide (i.e. should you have used the highslide configurator)'),
  );

  $form['highslide2_options']['custom']['CSS'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Custom CSS'),
    '#default_value' => $options['custom']['CSS'],
    '#description'   => t('Place CSS strings here to apply special behavior for highslide'),
  );

  $form = system_settings_form($form);

  return $form;
}

/**
 * Validate admin settings form inputs.
 */
function highslide2_options_form_validate($form, &$form_state) {
 //nothing
}

/**
 * Display a list of all formatters
 */
function highslide2_formatter_list() {

  $output =  '<ul class="action-links"><li>' . l(t('Add a formatter'), 'admin/config/media/highslide/formatters/add') . '</li></ul>' ;
  $output .= '<br><br>';

  $header = array(t('Name'), t('Actions'));
  $rows = array();
  foreach (highslide2_formatters() as $formatter) {
    $row = array();
    $row[] = l($formatter['name'], 'admin/config/media/highslide/formatters/'. $formatter['name'] . '/edit');
    $links = array();
    $links[] = l(t('Edit'), 'admin/config/media/highslide/formatters/'. $formatter['name'] . '/edit');
    // The default formatter may not be deleted
    if ($formatter['name']!= 'default') {
      $links[] = l(t('Delete'), 'admin/config/media/highslide/formatters/'. $formatter['name'] .'/delete');
    }
    $row[] = implode('&nbsp;|&nbsp;', $links);
    $rows[] = $row;
  }

  $output .= theme_table(array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array(),
    'caption' => '',
    'colgroups' => array(),
    'sticky' => '',
    'empty' => t('The list is empty.') . ' ' . l(t('Add a formatter'), 'admin/config/media/highslide/formatters/add'),
    )
  );

  return $output;
}

/**
 * Form for editing or adding a custom Highslide formatter.
 */
function highslide2_formatter_form($form, &$form_state, $op = 'add', $formatter = array()) {

  if ($op == 'edit' && empty($formatter)) {
    drupal_set_message(t('The specified formatter was not found.'), 'error');
    drupal_goto('admin/config/media/highslide/formatters');
  }

   if ($op == 'edit') {
    $form['old_name'] = array(
      '#type'  => 'value',
      '#value' => $formatter['name'],
    );
  }
  elseif ($op == 'add') {
    $formatter += _highslide2_default_formater();
  }

  $form['highslide2_formatter'] = array(
    '#tree' => TRUE
  );

  $form['highslide2_formatter']['name'] = array(
    '#type'          => 'textfield',
    '#size'          => '64',
    '#title'         => t('Formatter Name'),
    '#default_value' => $formatter['name'],
    '#description'   => t('Please only use lowercase alphanumeric characters, and underscores (_) for names.'),
    '#required'      => TRUE,
  );

  $form['highslide2_formatter']['numberPosition'] = array(
    '#type'           => 'select',
    '#title'          => t('Number position'),
    '#default_value'  => $formatter['numberPosition'],
    '#options'        => _highslide2_enum_numberPosition(),
    '#description'    => t('Show an image count like "Image 1 of 5" in the given position.'),
  );

  // Heading Begin
  $form['highslide2_formatter']['showHeading'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Show heading'),
    '#default_value' => $formatter['showHeading'],
    '#description'   => t('Enable this option to display a heading .'),
  );

  $form['highslide2_formatter']['heading'] = array(
      '#type'        => 'fieldset',
      '#title'       => t('Heading'),
      '#collapsible' => TRUE,
      '#collapsed'   => FALSE,
      '#states'      => array(
        'visible'     => array(
          ':input[name="highslide2_formatter[showHeading]"]' => array('checked' => TRUE),
        ),
      ),
    );
  _highslide2_generate_position_form($form['highslide2_formatter']['heading'], $formatter['heading'], 'heading', 'highslide2_formatter[heading]');
  //Heading End

  // Caption Begin
  $form['highslide2_formatter']['showCaption'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Show caption'),
    '#default_value'  => $formatter['showCaption'],
    '#description'    => t('Enable this option to display a caption .'),
  );

  $form['highslide2_formatter']['caption'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Caption'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#states'      => array(
      'visible'     => array(
        ':input[name="highslide2_formatter[showCaption]"]' => array('checked' => TRUE),
      ),
    ),
  );

  _highslide2_generate_position_form($form['highslide2_formatter']['caption'], $formatter['caption'], 'caption', 'highslide2_formatter[caption]');
  //Caption End


  //dimming overlay begin
  $form['highslide2_formatter']['showDimming'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Show dimming'),
    '#default_value' => $formatter['showDimming'],
    '#description'   => t('Add a semitransparent mask above the page behind the Highslide popup.'),
  );

  $form['highslide2_formatter']['dimming'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Dimming'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#states'      => array(
      'visible'      => array(
        ':input[name="highslide2_formatter[showDimming]"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  $form['highslide2_formatter']['dimming']['dimmingOpacity'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Dimming Opacity'),
    '#default_value'  => $formatter['dimming']['dimmingOpacity'],
    '#description'    => t('Opacity of background dimming (from 0 to 1) 0 is transparent and 1 is opaque.'),
  );

  $form['highslide2_formatter']['dimming']['dimmingDuration'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Dimming Duration'),
    '#default_value'  => $formatter['dimming']['dimmingDuration'],
    '#description'    => t('Duration to apply the dimming in ms.'),
  );
  //dimming overlay end

  // Slideshow informations : Begin
  $form['highslide2_formatter']['activateSlideshow'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Enable gallery'),
    '#default_value'  => $formatter['activateSlideshow'],
    '#description'    => t('Enable this option activate the gallery functionalities.'),
  );

  $form['highslide2_formatter']['slideshow'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Gallery Information'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#states'      => array(
      'visible'      => array(
        ':input[name="highslide2_formatter[activateSlideshow]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['highslide2_formatter']['slideshow']['interval'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Interval'),
    '#default_value'  => $formatter['slideshow']['interval'],
    '#description'    => t('The amount of millisecond that each slide will be displayed.'),
  );


  $form['highslide2_formatter']['slideshow']['autoPlay'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Auto play slideshow'),
    '#default_value'  => $formatter['slideshow']['autoPlay'],
    '#description'    => t('Enable this option to start the slideshow automatically.'),
  );

  $form['highslide2_formatter']['slideshow']['repeat'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Repeat slideshow'),
    '#default_value'  => $formatter['slideshow']['repeat'],
    '#description'    => t('Enable this option to start over from the first slide when going to the next from the last slide.'),
  );

  $form['highslide2_formatter']['slideshow']['fixedControls'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Fixes the control position'),
    '#default_value'  => $formatter['slideshow']['fixedControls'],
    '#description'    => t('When enabled, Highslide aligns subsequent slides so that the controls are in the same position for the next image. This means the user can browse through the images using the "Next" button without moving the mouse.'),
  );

  $form['highslide2_formatter']['slideshow']['useControls'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Navigation controls'),
    '#default_value'  => $formatter['slideshow']['useControls'],
    '#description'    => t('Enable this option to create a controls overlay for the gallery.'),
  );

  $form['highslide2_formatter']['slideshow']['controls'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Navigation controls'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
    '#states'      => array(
      'visible'      => array(
        ':input[name="highslide2_formatter[slideshow][useControls]"]' => array('checked' => TRUE),
      ),
    ),
  );


  $form['highslide2_formatter']['slideshow']['controls']['hideOnMouseOut'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Hide controls on mouse out'),
    '#default_value'  => $formatter['slideshow']['controls']['hideOnMouseOut'],
    '#description'    => t('When enabled, the contorls will be hidden when the mouse leaves the full-size image.'),
  );

  $form['highslide2_formatter']['slideshow']['controls']['controlsClass'] = array(
    '#type'           => 'select',
    '#title'          => t('Style'),
    '#default_value'  => $formatter['slideshow']['controls']['controlsClass'],
    '#options'        => _highslide2_enum_slideshow_controls(),
    '#description'    => t('Specifies the style of the navigation controls'),
  );

  _highslide2_generate_position_form($form['highslide2_formatter']['slideshow']['controls'], $formatter['slideshow']['controls'], 'controls', 'highslide2_formatter[slideshow][controls]');


  $form['highslide2_formatter']['slideshow']['showThumbstrip'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Enable thumbstrip'),
    '#default_value'  => $formatter['slideshow']['showThumbstrip'],
    '#description'    => t('Enable this option to display the thumbnails in the overlay'),
  );

  $form['highslide2_formatter']['slideshow']['thumbstrip'] = array(
      '#type'        => 'fieldset',
      '#title'       => t('Thumbstrip'),
      '#collapsible' => TRUE,
      '#collapsed'   => FALSE,
      '#states'      => array(
        'visible'      => array(
          ':input[name="highslide2_formatter[slideshow][showThumbstrip]"]' => array('checked' => TRUE),
        ),
      ),
    );

  $form['highslide2_formatter']['slideshow']['thumbstrip']['mode'] = array(
    '#type'           => 'select',
    '#title'          => t('Mode'),
    '#default_value'  => $formatter['slideshow']['thumbstrip']['mode'],
    '#options'        => _highslide2_enum_thumbstrip_mode(),
    '#description'    => t('Specifies the orientation of the thumbstrip'),
  );

  _highslide2_generate_position_form($form['highslide2_formatter']['slideshow']['thumbstrip'], $formatter['slideshow']['thumbstrip'], 'thumbstrip', 'highslide2_formatter[slideshow][thumbstrip]');
  // Slideshow informations : End

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => ($op == 'edit') ? t('Update Formatter') : t('Create New Formatter'),
  );

   $form['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
  );
  
  return $form;
}

/**
 * Validation handler for highslide2_formatter_form().
 *
 * Errors should be signaled with form_set_error().
 */
function highslide2_formatter_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  $name = $values['highslide2_formatter']['name'];

  if ($values['op'] == t('Cancel')) {
   return;
  }
  
  if ($values['op'] == t('Update Formatter')) {
    //control that the default formatter name is not changed
    if ($values['old_name'] == 'default' && $name!='default') {
      drupal_set_message(t('The name of the default formatter may not be modified.'), 'error');
      drupal_goto('admin/config/media/highslide/formatters');
    }
  }
  else {
    // Check for duplicates
    foreach(highslide2_formatters() as $formatter) {
      if (in_array($name, $formatter)) {
        form_set_error('name', t('The name you have chosen is already in use.'));
        break;
      }
    }
  }

  // Check for illegal characters in preset names
  if (!preg_match('/^[a-z0-9_.]+$/', $name)) {
    form_set_error('name', t('Please only use lowercase alphanumeric characters and underscores (_) for names.'));
  }

    //control the values
     $dimmingOpacity = $form_state['values']['highslide2_formatter']['dimming']['dimmingOpacity'];
  if (!is_numeric($dimmingOpacity) || $dimmingOpacity < 0 || $dimmingOpacity > 1) {
    form_set_error('highslide2_formatter][dimming][dimmingOpacity', t('dimmingOpacity : You must enter a number between 0 and 1.'));
  }

  $dimmingDuration = $form_state['values']['highslide2_formatter']['dimming']['dimmingDuration'];
  if (!((string)(int)$dimmingDuration === (string)$dimmingDuration) || $dimmingDuration < 0) {
    form_set_error('highslide2_options][dimmingDuration', t('Dimming duration') . ' : '. t('You must enter an integer greater than 0.'));
  }

  if ($form_state['values']['highslide2_formatter']['activateSlideshow']) {
    $slideshow_interval = $form_state['values']['highslide2_formatter']['slideshow']['interval'];
    if (!((string)(int)$slideshow_interval === (string)$slideshow_interval) || $slideshow_interval < 9) {
      form_set_error('highslide2_formatter][slideshow][interval', t('Slideshow interval : You must enter an integer greater than 9.'));
    }
  }
}

/**
 * Submit handler for highslide2_formatter_form().
 */
function highslide2_formatter_form_submit($form, &$form_state) {

  $values = $form_state['values'];
  //At the end we go back to the formatters list
  $form_state['redirect'] = 'admin/config/media/highslide/formatters';

  if ($values['op'] == t('Cancel')) {
    return;
  }

  $formatter = $values['highslide2_formatter'];
  $formatters = highslide2_formatters();

  // Unset the formatter (in case of edit of the name)
  if (!empty($values['old_name'])) {
    unset($formatters[$values['old_name']]);
  }

  $formatters[$formatter['name']] = $formatter;

  variable_set('highslide2_formatters', $formatters);

  if ($values['op'] = t('Update Formatter')) {
    drupal_set_message(t('Highslide formatter %name was updated....', array('%name' => $formatter['name'])));
  }
  else {
    drupal_set_message(t('Highslide formatter %name was created.', array('%name' => $formatter['name'])));
  }
}

/**
 * Page callback confirm form for deleting a Custom formatter.
 */
function highslide2_formatter_delete_form($form, &$form_state, $formatter = array()) {


 if (empty($formatter)) {
    drupal_set_message(t('The specified formatter was not found.'), 'error');
    drupal_goto('admin/config/media/highslide/formatters');
  }

  //prevent path manipulation
 if ($formatter['name'] == 'default') {
    drupal_set_message(t('The default formatter may not be deleted.'), 'error');
    drupal_goto('admin/config/media/highslide/formatters');
  }
  $form = array();
  $form['name'] = array(
    '#type' => 'value',
    '#value' => $formatter['name']
  );

  $question = t('Are you sure you want to delete the formatter %name?', array('%name' => $formatter['name']));
  $path = 'admin/config/media/highslide/formatters';
  $descr = t('This action cannot be undone.');
  $yes = t('Delete');
  $no = t('Cancel');

  return confirm_form($form, $question, $path, $descr, $yes, $no);
}

/**
 * Submit handler for the delete confirm form.
 */
function highslide2_formatter_delete_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $formatters = highslide2_formatters();
  $formatter = $formatters[$values['name']];

  unset($formatters[$values['name']]);
  variable_set('highslide2_formatters', $formatters);
  drupal_set_message(t('Formatter %name was deleted.', array('%name' => $formatter['name'])));

  $form_state['redirect'] = 'admin/config/media/highslide/formatters';
}


/**
 * Generates the form  parts for positioning the elements (heading, controls,...)
 */
function _highslide2_generate_position_form(&$form, &$options, $target, $name) {

    $form['relativeTo'] = array(
      '#type'           => 'select',
      '#title'          => t('Position reference'),
      '#default_value'  => $options['relativeTo'],
      '#options'         => _highslide2_enum_relativeTo(),
      '#description'    => t('Specifies the element taken as reference for the position'),
    );


    $form['positionViewport'] = array(
      '#type'           => 'select',
      '#title'          => t('Position'),
      '#default_value'  => $options['positionViewport'],
      '#options'         => _highslide2_enum_position('viewport'),
      '#description'    => t('Specifies where the ' . $target . ' will appear related to the full-size image.'),
      '#states' => array(
        'visible' => array(
          ':input[name="'. $name .'[relativeTo]"]' => array('value' => t('viewport')),
        ),
      ),
    );

    $form['positionImage'] = array(
      '#type'           => 'select',
      '#title'          => t('Position.'),
      '#default_value'  => $options['positionImage'],
      '#options'         => _highslide2_enum_position('image'),
      '#description'    => t('Specifies where the '. $target .' will appear related to the full-size image.'),
      '#states' => array(
        'invisible' => array(
          ':input[name="'. $name .'[relativeTo]"]' => array('value' => t('viewport')),
        ),
      ),
    );
}