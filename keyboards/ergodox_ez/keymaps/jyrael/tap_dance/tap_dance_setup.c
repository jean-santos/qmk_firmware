
void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 1)
  {
    register_code(KC_SCLN);
  }
  else
  {
    register_code(KC_RSFT);
    register_code(KC_SCLN);
  }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 1)
  {
    unregister_code(KC_SCLN);
  }
  else
  {
    unregister_code(KC_RSFT);
    unregister_code(KC_SCLN);
  }
}