<?php

/**
 * @file
 * Definition of fundmakr_handler_progress_bar.
 */

/**
 * Provide the first name only from the name field.
 *
 * @ingroup views_filter_handlers
 */
class fundmakr_handler_progress_bar extends views_handler_field {
  /**
  * Render the name field.
  */
  public function render($values) {
    $value = $this->get_value($values);
    $return = explode(' ', $value);
    return 'First name: ' . $return['0'];
  }
}


