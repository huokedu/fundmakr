<?php

/**
 * @file
 * Fundmakr Settings UI.
 */

/**
 * Menu callback: configure Fundmakr settings
 */

function fundmakr_admin_settings() {

  $form['fundmakr_settings_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fundmakr Settings'),
    '#collapsible' => TRUE,
  );

  $form['fundmakr_settings_fieldset']['fundmakr_settings_currency_code'] = array(
    '#default_value' => variable_get('fundmakr_settings_currency_code', ''),
    '#options' => currency_options(),
    '#required' => TRUE,
    '#title' => t('Currency'),
    '#type' => 'select',
  );

  $form['fundmakr_settings_fieldset']['fundmakr_settings_payment_method'] = array(
    '#default_value' => variable_get('fundmakr_settings_payment_method', 0),
    '#options' => payment_method_options(),
    '#required' => TRUE,
    '#title' => t('Payment method'),
    '#type' => 'select',
  );

  $form['fundmakr_settings_fieldset']['fundmakr_settings_payment_method_description'] = array(
    '#default_value' => variable_get('fundmakr_settings_payment_method_description', ''),
    '#required' => TRUE,
    '#title' => t('Payment description'),
    '#type' => 'textfield',
  );

  $form['fundmakr_settings_fieldset']['fundmakr_settings_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Stripe Application/Client ID'),
    '#required' => TRUE,
    '#description' => 'Used for Stripe Connect integration.',
    '#default_value' => variable_get('fundmakr_settings_client_id', ''),
  );

  $form['fundmakr_settings_fieldset']['fundmakr_settings_application_fee'] = array(
    '#type' => 'textfield',
    '#title' => t('Stripe Application Fee'),
    '#element_validate' => array('element_validate_integer_positive'),
    '#required' => TRUE,
    '#description' => 'Stripe application fee in percentage.',
    '#default_value' => variable_get('fundmakr_settings_application_fee', 0),
  );

  $form['fundmakr_settings_fieldset']['fundmakr_settings_recommended_amounts'] = array(
    '#default_value' => variable_get('fundmakr_settings_recommended_amounts', ''),
    '#required' => TRUE,
    '#title' => t('List down recommended amounts'),
    '#type' => 'textarea',
    '#description' => 'Format: key|value',
  );



  return system_settings_form($form);
}
