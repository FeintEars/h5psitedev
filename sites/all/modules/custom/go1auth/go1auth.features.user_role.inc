<?php
/**
 * @file
 * go1auth.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function go1auth_user_default_roles() {
  $roles = array();

  // Exported role: Go1 authenticated user.
  $roles['Go1 authenticated user'] = array(
    'name' => 'Go1 authenticated user',
    'weight' => 3,
  );

  return $roles;
}
