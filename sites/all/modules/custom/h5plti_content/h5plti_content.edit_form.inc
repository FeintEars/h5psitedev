<?php

/**
 * Edit h5p video form.
 */

/**
 * Form callback for h5p/%/edit.
 */
function h5plti_h5p_edit_form($form, &$form_state, $nid) {
  // Prepare the current node.
  if (!isset($form_state['node'])) {
    $form_state['node'] = node_load($nid);
    if ($form_state['node']) {
      $form_state['node']->revision = FALSE;
      $form_state['node']->menu = FALSE;
    }
    else {
      drupal_not_found();
    }
  }

  // Customize the usual node-edit form.
  $form_state['build_info']['args'] = array($form_state['node']);
  form_load_include($form_state, 'inc', 'node', 'node.pages');
  $form = drupal_build_form('h5p_content_node_form', $form_state);
  unset($form['title']['#value']);
  unset($form['json_content']['#value']);
  $form['additional_settings']['#access'] = FALSE;
  $form['revision_information']['#access'] = FALSE;
  $form['author']['#access'] = FALSE;
  $form['options']['#access'] = FALSE;
  $form['field_h5p_video_only']['#access'] = FALSE;
  unset($form['actions']['preview']);
  unset($form['actions']['delete']);
  $form['actions']['submit']['#submit'][] = '_h5p_form_submit';
  $form['actions']['submit']['#submit'][] = 'h5peditor_h5p_content_node_form_submit';
  $form['actions']['submit']['#submit'][] = 'h5plti_h5p_edit_form_submit';

  return $form;
}

/**
 * Additional submit for h5p/edit form.
 */
function h5plti_h5p_edit_form_submit($form, &$form_state) {
  $messages = drupal_get_messages();
  drupal_goto('<front>');
}
