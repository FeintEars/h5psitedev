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
