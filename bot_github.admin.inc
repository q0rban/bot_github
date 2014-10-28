<?php

/**
 * @file
 * Administrative pages for the Bot Github module.
 */

/**
 * Configures Bot Github settings.
 */
function bot_github_settings($form) {
  $form['bot_github_repo_url'] = array(
    '#default_value' => variable_get('bot_github_repo_url', ''),
    '#title' => t('Bot Github Repo URL'),
    '#type' => 'textfield',
    '#description' => t('The URL of the Github repo, e.g. https://github.com/Lullabot/ircbot_profile.'),
  );

  return system_settings_form($form);
}

/**
 * Validates the Bot Github settings.
 */
function bot_github_settings_validate(&$form, &$form_state) {
  if (empty($form_state['values']['bot_github_repo_url'])) {
    return;
  }
  if (!valid_url($form_state['values']['bot_github_repo_url'], TRUE)) {
    form_set_error('bot_github_repo_url', t('You must enter a valid url.'));
  }
  form_set_value($form['bot_github_repo_url'], rtrim($form_state['values']['bot_github_repo_url'], '/'), $form_state);
}
