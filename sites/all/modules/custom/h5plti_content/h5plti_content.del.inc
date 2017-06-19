<?php

/**
 * Del h5p video.
 */

/**
 * The callback to delete h5p video - h5p/%/del.
 */
function h5plti_h5p_del($nid) {
  node_delete($nid);
  drupal_goto('<front>');
}
