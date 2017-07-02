<?php

/**
 * H5PLTI theme.
 */

/**
 * Preprocess page.
 */
function h5plti_preprocess_page(&$vars) {
  $vars['footer_menu'] = menu_tree_output(menu_tree_all_data('menu-footer-menu'));
  $vars['footer_menu2'] = menu_tree_output(menu_tree_all_data('menu-footer-menu-2'));
}

/**
 * Preprocess block.
 */
function h5plti_preprocess_block(&$vars) {
  if ($vars['block']->module == 'user' && $vars['block']->delta == 'login') {
    if (module_exists('go1auth')) {
      $content2 = drupal_get_form('go1auth_register_form');
      $vars['content2'] = drupal_render($content2);
    }
  }
}
