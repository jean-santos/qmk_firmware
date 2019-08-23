bool CAPS_LOCK   = false;
bool NUM_LOCK    = false;
bool SCROLL_LOCK = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  uint16_t index;
  uint8_t shift;
  if (!process_record_dynamic_macro(keycode, record))
  {
    return false;
  }
  if (record->event.pressed)
  {
    shift = get_mods() & MODS_SHIFT_MASK;
    if (keycode >= TIO_A && keycode <= AGUDO_U)
    {
      index = keycode - TIO_A;
      unregister_code(KC_LSFT);
      unregister_code(KC_RSFT);
      // Choose Alt code based on which key was pressed and whether Shift was held.
      send_string(alt_codes[index][(bool)shift]);
      // Restore Shift keys to their previous state.
      if (shift & MOD_BIT(KC_LSFT))
        register_code(KC_LSFT);
      if (shift & MOD_BIT(KC_RSFT))
        register_code(KC_RSFT);
    }
    else if (keycode == SH_ON)
    {
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
    }
    else if (keycode == SH_OFF)
    {
      ergodox_right_led_1_off();
      ergodox_right_led_2_off();
      ergodox_right_led_3_off();
    }
    switch (keycode)
    {
    case EPRM:
      eeconfig_init();
      return false;
    case VRSN:
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      return false;
    default:
      break;
    }
  }
  return true;
}