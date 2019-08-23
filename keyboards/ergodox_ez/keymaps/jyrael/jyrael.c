// Keyboard keymap:
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ergodox(
        // left hand
        TD(TD_EQ_TILDE), KC_1, KC_2, KC_3, KC_4, KC_5, SH_ON,
        KC_DELT, KC_Q, KC_W, KC_E, KC_R, KC_T, OSL(ACENTOS),
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, CTL_T(KC_Z), KC_X, KC_C, KC_V, KC_B, LCTL(KC_C),
        TD(TD_CTL_DITTO), KC_QUOT, KC_LEFT, KC_RGHT, KC_LALT,
        ALT_T(KC_APP), KC_LGUI,
        KC_HOME,
        KC_SPC, KC_BSPC, KC_END,
        // right hand
        SH_OFF, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        TG(SYMB), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_H, KC_J, KC_K, KC_L, TD(CT_CLN), GUI_T(KC_QUOT),
        LCTL(KC_V), KC_N, KC_M, KC_COMM, KC_DOT, CTL_T(KC_SLSH), KC_RSFT,
        KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, TG(STEN),
        KC_LALT, CTL_T(KC_ESC),
        KC_PGUP,
        KC_PGDN, KC_TAB, KC_ENT),
    [SYMB] = LAYOUT_ergodox(
        // left hand
        VRSN, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
        KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
        KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV,
        KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
        EPRM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        RGB_MOD, KC_TRNS,
        KC_TRNS,
        RGB_VAD, RGB_VAI, KC_TRNS,
        // right hand
        DYN_REC_STOP, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TRNS, KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12,
        KC_DOWN, KC_4, KC_5, KC_6, KC_PLUS, KC_TRNS,
        KC_TRNS, KC_AMPR, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS,
        KC_TRNS, KC_DOT, KC_0, KC_EQL, KC_TRNS,
        RGB_TOG, RGB_SLD,
        KC_TRNS,
        KC_TRNS, RGB_HUD, RGB_HUI),
    [ACENTOS] = LAYOUT_ergodox(
        // left hand
        CRASE_A, TIO_A, TIO_O, CIRC_O, AGUDO_O, KC_TRNS, KC_TRNS,
        CRASE_E, AGUDO_A, AGUDO_E, AGUDO_I, KC_TRNS, KC_TRNS, KC_TRNS,
        AGUDO_U, CIRC_E, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, CEDILHA_C, KC_TRNS, KC_TRNS, KC_MY_COMPUTER,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LPRN, KC_RPRN,
        KC_LCBR,
        KC_PIPE, KC_PSCR, KC_RCBR,
        // right hand
        DYN_REC_START1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS,
        DYN_MACRO_PLAY1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LABK, KC_RABK,
        KC_LBRC,
        KC_RBRC, KC_TRNS, KC_TRNS),
    [STEN] = LAYOUT_ergodox(  // Stenography
       KC_BSPC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  KC_NO,
       KC_NO,   STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,
       KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  STN_A,   STN_O,   KC_NO,
    // right hand
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
                 STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
       KC_NO,    STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   STN_E,   STN_U
),
};