/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.fundmakr = {
  attach: function(context, settings) {

    // Place your code here.

    $('input[type=radio][name=x_amount]').change(function() {
      if ($(this).val() != 'other') {
        $yourdonation = $(this).val();
        $fhf = $(this).val() * (parseFloat($("#app-fee").html()) / 100);
        $stripefee = $(this).val() * (2.9 / 100) + 0.3;
        $("#your-donation").html($('#user_currency').val() + $yourdonation);
        $("#fundmakr-handling-fee").html($('#user_currency').val() + $fhf);
        $("#stripe-fee").html($('#user_currency').val() + $stripefee);
        $total = parseFloat($yourdonation) - parseFloat($fhf) - parseFloat($stripefee);
        $("#donation-total").html($('#user_currency').val() + $total.toFixed(2) );
      }
      else {
        reset();
      }
    });

    $('#edit-x-other-amount').on('input', function() {
      if ($(this).val() != '' && $(this).val() != 0) {
        $yourdonation = $(this).val();
        $fhf = $(this).val() * (parseFloat($("#app-fee").html()) / 100);
        $stripefee = $(this).val() * (2.9 / 100) + 0.3;
        $("#your-donation").html($('#user_currency').val() + $yourdonation);
        $("#fundmakr-handling-fee").html($('#user_currency').val() + $fhf.toFixed(2));
        $("#stripe-fee").html($('#user_currency').val() + $stripefee.toFixed(2));
        $total = parseFloat($yourdonation) - parseFloat($fhf) - parseFloat($stripefee);
        $("#donation-total").html($('#user_currency').val() + $total.toFixed(2) );
      }
      else {
        reset();
      }

    });

    $("#edit-x-other-amount").keydown(function (e) {

        // Allow: backspace, delete, tab, escape, enter and .
        if ($.inArray(e.keyCode, [46, 8, 9, 27, 13, 110]) !== -1 ||
             // Allow: Ctrl+A
            (e.keyCode == 65 && e.ctrlKey === true) ||
             // Allow: home, end, left, right
            (e.keyCode >= 35 && e.keyCode <= 39)) {
                 // let it happen, don't do anything
                 return;
        }
        // Ensure that it is a number and stop the keypress
        if ((e.shiftKey || (e.keyCode < 48 || e.keyCode > 57)) && (e.keyCode < 96 || e.keyCode > 105)) {
            e.preventDefault();
        }
    });

    function reset() {
      $("#your-donation").html($('#user_currency').val()+'0');
      $("#fundmakr-handling-fee").html($('#user_currency').val()+'0');
      $("#stripe-fee").html($('#user_currency').val()+'0');
      $("#donation-total").html($('#user_currency').val()+'0');
    }

  }
};


})(jQuery, Drupal, this, this.document);
