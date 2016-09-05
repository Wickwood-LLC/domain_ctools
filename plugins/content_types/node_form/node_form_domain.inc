<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'icon' => 'icon_node_form.png',
  'title' => t('Node form domain access options'),
  'description' => t('The domain access selection form.'),
  'required context' => new ctools_context_required(t('Form'), 'node_form'),
  'category' => t('Form'),
);

function domain_ctools_node_form_domain_content_type_render($subtype, $conf, $panel_args, &$context) {
  $block = new stdClass();
  $block->module = t('node_form');

  $block->title = t('Domain Access Options');
  $block->module = t('node_form');
  $block->delta = 'domain-options';

  if (isset($context->form)) {
    if (isset($context->form['domain'])) {
      $block->content['domain'] = $context->form['domain'];
      unset($block->content['domain']['#pre_render']);
      unset($block->content['domain']['#theme_wrappers']);
      $block->content['domain']['#type'] = '';

      // Set access to false on the original rather than removing so that
      // vertical tabs doesn't clone it. I think this is due to references.
      $context->form['domain']['#access'] = FALSE;
    }
  }
  else {
    $block->content = t('Domain Access Options.');
  }
  return $block;
}

function domain_ctools_node_form_domain_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" node form domain field', array('@s' => $context->identifier));
}

function domain_ctools_node_form_domain_content_type_edit_form($form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
  return $form;
}
