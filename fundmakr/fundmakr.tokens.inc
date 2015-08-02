<?php

/**
 * Implements hook_token_info().
 *
 */
function fundmakr_token_info() {
  // Add two different token types. The first is the generic text format. The
  // second is the user's default text format, which is itself a 'format' token
  // type so it can be used directly.
  $info['types']['fundmakr'] = array(
    'name' => t('Fundmakr Tokens'),
    'description' => t('Tokens related to Fundmakr.'),
  );

  // Tokens for the text format token type.
  $info['tokens']['fundmakr']['godaddy_certificate'] = array(
    'name' => t('Godaddy Security Certificate'),
    'description' => t("A Godaddy snippet for Security Certificate."),
  );

  return $info;
}

/**
 * Implements hook_tokens().
 *
 * @todo
 * Create variables for token contents
 */
function fundmakr_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  // Text format tokens.
  if ($type == 'fundmakr') {
    $format = $data['format'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'godaddy_certificate':

          $replacements[$original] = '<span id="siteseal"><script type="text/javascript" src="https://seal.godaddy.com/getSeal?sealID=LLHllu1QAVpj3ZCzNGmN0HlW8Imx6JorHOw94aFS57tv7qWYnOsvWtL95fJS"></script></span>';
          break;
      }
    }
  }


  return $replacements;
}
