// Register the double tap dances:
qk_tap_dance_action_t tap_dance_actions[] = {
    //Tap once for Esc, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_EQ_TILDE] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, LSFT(KC_GRAVE)),
    [TD_CTL_DITTO] = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, LCTL(KC_GRAVE)),
    [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset)
    // Other declarations would go here, separated by commas, if you have them
};