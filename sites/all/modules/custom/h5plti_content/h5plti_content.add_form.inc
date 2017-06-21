<?php

/**
 * Add h5p video form.
 */

/**
 * Form callback for h5p/add.
 */
function h5plti_h5p_add_form($form, &$form_state) {
  // Copy the h5p-node from template to save.
  if (!isset($form_state['node'])) {
    $already_exists = hp5lti_h5p_check_video_template();
    $form_state['node'] = hp5lti_h5p_get_video_template();
  }

  // Customize the usual node-edit form.
  $form_state['build_info']['args'] = array($form_state['node']);
  form_load_include($form_state, 'inc', 'node', 'node.pages');
  $form = drupal_build_form('h5p_content_node_form', $form_state);
  unset($form['title']['#value']);
  if (!$already_exists) {
    // $form['title']['#default_value'] = '';
  }
  unset($form['json_content']['#value']);
  $form['additional_settings']['#access'] = FALSE;
  $form['revision_information']['#access'] = FALSE;
  $form['author']['#access'] = FALSE;
  $form['options']['#access'] = FALSE;
  $form['field_h5p_video_only']['#access'] = FALSE;
  $form['field_lti_allowed_keys']['#access'] = FALSE;
  $form['actions']['submit']['#value'] = t('Add');
  unset($form['actions']['preview']);
  unset($form['actions']['delete']);
  $form['actions']['submit']['#submit'][] = '_h5p_form_submit';
  $form['actions']['submit']['#submit'][] = 'h5peditor_h5p_content_node_form_submit';
  $form['actions']['submit']['#submit'][] = 'h5plti_h5p_add_form_submit';

  return $form;
}

/**
 * Additional submit for h5p/add form.
 */
function h5plti_h5p_add_form_submit($form, &$form_state) {
  hp5lti_h5p_free_video_template();
  $messages = drupal_get_messages();
  drupal_goto('<front>');
}

/**
 * Get a new h5p-video template for this user.
 */
function hp5lti_h5p_get_video_template() {
  // Get the current user wrapper.
  global $user;
  $user_wrapper = entity_metadata_wrapper('user', $user);

  // Check if the template already exists for this user.
  if ($nid = $user_wrapper->field_h5p_video_template_nid->value()) {
    $node = node_load($nid);
    if ($node) {
      $node->revision = FALSE;
      $node->menu = FALSE;
      return $node;
    }
  }

  // Duplicate a new template for this user.
  $node = node_load(H5P_VIDEO_TEMPLATE_NID);
  $node->is_new = TRUE;
  $node->title = t('New H5P video');
  unset($node->nid);
  unset($node->vid);
  $node->uid = $user->uid;
  node_save($node);
  $node->revision = FALSE;
  $node->menu = FALSE;
  $user_wrapper->field_h5p_video_template_nid->set($node->nid);
  $user_wrapper->save();

  return $node;
}

/**
 * Check if the tempate already exists for the user.
 */
function hp5lti_h5p_check_video_template() {
  // Get the current user wrapper.
  global $user;
  $user_wrapper = entity_metadata_wrapper('user', $user);

  // Check if the template already exists for this user.
  if ($nid = $user_wrapper->field_h5p_video_template_nid->value()) {
    $node = node_load($nid);
    if ($node) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Free the user from the template.
 */
function hp5lti_h5p_free_video_template() {
  global $user;
  $user_wrapper = entity_metadata_wrapper('user', $user);
  $user_wrapper->field_h5p_video_template_nid->set(NULL);
  $user_wrapper->save();
}
