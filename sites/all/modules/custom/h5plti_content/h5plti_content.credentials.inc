<?php

/**
 * Get credentials for h5p video.
 */

/**
 * The callback to get lti credentials for h5p video - h5p/%/credentials.
 */
function h5plti_h5p_credentials($nid) {
  global $base_url, $base_path;
  $url = $base_url . $base_path . 'h5p-video/' . $nid . '/lti';
  $credentials = h5plti_get_lti_credentials($nid);
  print theme('h5plti_credentials', $credentials + array('url' => $url));
  drupal_exit();
}
