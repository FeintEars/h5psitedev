<?php

/**
 * Check OAuth credentials from LTI request.
 */
function h5plti_embed_authorization() {
  module_load_include('inc', 'lti_tool_provider', 'lti_tool_provider.operations');

  global $user;
  // If not an LTI launch request, then ignore.
  if (!lti_tool_provider_is_basic_lti_request()) {
    return t('Error: Not a LTI request.');
  }
  // Insure we have a valid context.
  if (empty($_REQUEST['oauth_consumer_key'])) {
    unset($_SESSION['lti_tool_provider_context_info']);
    return t('Error: Invalid context. Missing oauth_consumer_key in request.');
  }
  // Begin a new session based on this LTI launch request.
  drupal_session_start();
  $oauth_consumer_key = $_REQUEST['oauth_consumer_key'];
  // Verify the message signature.
  $store = new LTIToolProviderOAuthDataStore();
  $server = new OAuthServer($store);
  $method = new OAuthSignatureMethod_HMAC_SHA1();
  $server->add_signature_method($method);
  $request = OAuthRequest::from_request();
  try {
    $server->verify_request($request);
    // This is a LTI launch request.
  } catch (Exception $e) {
    return t('Check the key and secret.');
  }
  $consumer = lti_tool_provider_get_consumer_by_key($oauth_consumer_key);
  return $consumer;
}

/**
 * Get (or generate if needed) lti key and secret for h5p video.
 */
function h5plti_get_lti_credentials($nid) {
  $node = node_load($nid);
  $node->menu = FALSE;
  $node->revision = FALSE;
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $allowed_keys = $node_wrapper->field_lti_allowed_keys->value();
  if (empty($allowed_keys)) {
    // Generate a new pair key/secret.
    $ret = h5plti_generate_lti_credentials($nid);
    return $ret;
  }
  else {
    foreach ($allowed_keys as $index => $key) {
      if ($secret = h5plti_load_secret_by_key($key)) {
        // Return both key and secret.
        $ret = array(
          'key' => $key,
          'secret' => $secret
        );
        return $ret;
      }
      else {
        // Remove wrong key.
        unset($allowed_keys[$index]);
        $node_wrapper->field_lti_allowed_keys->set($allowed_keys);
        $node_wrapper->save();
      }
    }
  }

  // Generate a new key/secret again.
  $ret = h5plti_generate_lti_credentials($nid);
  return $ret;
}

/**
 * Generate lti credentials.
 */
function h5plti_generate_lti_credentials($nid) {
  $node = node_load($nid);
  $node->menu = FALSE;
  $node->revision = FALSE;
  $node_wrapper = entity_metadata_wrapper('node', $node);

  // Generate a new key/secret pair.
  $key = substr(md5($nid . 'key'), 0, 7);
  $secret = substr(md5($nid . 'secret'), 0, 5);

  // Save the node.
  $allowed_keys = $node_wrapper->field_lti_allowed_keys->value();
  $allowed_keys[] = $key;
  $node_wrapper->field_lti_allowed_keys->set($allowed_keys);
  $node_wrapper->save();

  // Save the lti consumer.
  $entity = entity_get_controller('lti_tool_provider_consumer')->create();
  $entity->lti_tool_provider_consumer_key = $key;
  $entity->lti_tool_provider_consumer_secret = $secret;
  $entity->lti_tool_provider_consumer_consumer = 'H5PLTI Embed';
  $entity->lti_tool_provider_consumer_domain = '';
  $entity->lti_tool_provider_consumer_dummy_pref = 0;
  lti_tool_provider_consumer_save($entity);

  // Return both key and secret.
  $ret = array(
    'key' => $key,
    'secret' => $secret
  );
  return $ret;
}

/**
 * Load lti secret by key.
 */
function h5plti_load_secret_by_key($key) {
  $consumer = lti_tool_provider_get_consumer_by_key($key);
  if (isset($consumer->lti_tool_provider_consumer_secret)) {
    return $consumer->lti_tool_provider_consumer_secret;
  }
  return FALSE;
}
