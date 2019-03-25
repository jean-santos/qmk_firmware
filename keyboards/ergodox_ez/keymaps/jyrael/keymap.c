#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_steno.h"

#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))
#define BASE 0    // default layer
#define SYMB 1    // symbols
#define MDIA 2    // media keys
#define ACENTOS 3 // acentos keys
#define STEN 4 // acentos keys

#define _x_ KC_NO
#define ___ KC_TRNS

enum custom_keycodes{
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD,
  TIO_A,
  CEDILHA_C,
  AGUDO_A,
  AGUDO_E,
  AGUDO_O,
  TIO_O,
  CIRC_E,
  CIRC_O,
  CRASE_A,
  AGUDO_I,
  CRASE_E,
  AGUDO_U,
  DYNAMIC_MACRO_RANGE,
};

enum
{
  TD_ESC_CAPS = 0,
  TD_EQ_TILDE,
  TD_CTL_DITTO,
  CT_CLN
};

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

qk_tap_dance_action_t tap_dance_actions[] = {
    //Tap once for Esc, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_EQ_TILDE] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, LSFT(KC_GRAVE)),
    [TD_CTL_DITTO] = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, LCTL(KC_GRAVE)),
    [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset)
    // Other declarations would go here, separated by commas, if you have them
};

#include "dynamic_macro.h"
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0, 13}, {1, 13}, {2, 13}, {3, 13}, {4, 13}, {5, 13}},
    {{0, 12}, {1, 12}, {2, 12}, {3, 12}, {4, 12}, {5, 12}},
    {{0, 11}, {1, 11}, {2, 11}, {3, 11}, {4, 11}, {5, 11}},
    {{0, 10}, {1, 10}, {2, 10}, {3, 10}, {4, 10}, {5, 10}},
    {{0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}},
    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}},
    {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}},
    /* Right hand, matrix positions */
    {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}},
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}},
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}},
    {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}},
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}},
};

char *alt_codes[][2] = {
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_7)), //ã
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_5)), //Ã
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_1)), //ç
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_9)), //Ç
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_5)), //á
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_3)), //Á
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_3)), //é
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_1)), //É
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_3)), //ó
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_1)), //Ó
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_5)), //õ
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_3)), //Õ
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_4)), //ê
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_2)), //Ê
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_4)), //ô
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_2)), //Ô
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_4)), //à
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_2)), //À
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_7)), //í
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_5)), //Í
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_2)), //è
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_0)), //È
    },
    {
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_0)), //ú
        SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_8)), //Ú
    }};
/*
(\w )(\d)(\d)(\d)(\d)
\1 SS_LALT\(SS_TAP\(X_KP_\2\)SS_TAP\(X_KP_\3\)SS_TAP\(X_KP_\4\)SS_TAP\(X_KP_\5\)\),
	á  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_5)),
	Á  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_3)),
	à  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_4)),
	À  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_2)),
	é  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_3)),
	É  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_0)SS_TAP(X_KP_1)),
	è  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_2)),
	È  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_0)SS_TAP(X_KP_0)),
	í  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_7)),
	Í  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_0)SS_TAP(X_KP_5)),
	ú  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_0)),
	Ú  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_8)),
	ù  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_9)),
	Ù  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_7)),
	ã  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_7)),
	Ã  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_5)),
	ç  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_3)SS_TAP(X_KP_1)),
	Ç  SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_9)),
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   = ~  |   1  |   2  |   3  |   4  |   5  | SON  |           | SOFF |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L3  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | TAB    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| copy |           | paste|------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTL  |  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
    [BASE] = LAYOUT_ergodox(
        // left hand
        TD(TD_EQ_TILDE), KC_1, KC_2, KC_3, KC_4, KC_5, SH_ON,
        KC_DELT, KC_Q, KC_W, KC_E, KC_R, KC_T, OSL(ACENTOS),
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, CTL_T(KC_Z), KC_X, KC_C, KC_V, KC_B, LCTL(KC_C),
        TD(TD_CTL_DITTO), KC_QUOT, KC_LALT, KC_LEFT, KC_RGHT,
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
    /* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | Mstop|  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
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
    /* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [MDIA] = LAYOUT_ergodox(
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
        KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_WBAK),
    /* Keymap 3: Acentos
 *é
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    à   |   ã  |   õ  |   ô  |   ó  |      |      |           |MStart|      |      |      |      |  RES |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    è   |   á  |   é  |   í  |      |      |explo |           |  M1  |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|  rer |           |      |------+------+------+------+------+--------|
 * |    ú   |   ê  |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   ç  |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  (   |   )  |       |  <   |   >  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |   {  |       |  [   |      |      |
 *                                 |   |  | prnt |------|       |------|      |      |
 *                                 |      |      |   }  |       |  ]   |      |      |
 *                                 `--------------------'       `--------------------'
 */
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
    [STEN] = LAYOUT_ergodox(  // layer 3 : Stenography
    // left hand
    _x_, _x_,    _x_,    _x_,    _x_,    _x_,     ___,
    _x_, STN_N1, STN_N2, STN_N3, STN_N4, STN_N5,  _x_,
    _x_, STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1,
    _x_, STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2, _x_,
    _x_, _x_,    _x_,    _x_,    _x_,
                                         _x_,     _x_,
                                                  _x_,
                                 STN_A,  STN_O,   _x_,
  // right hand
  _x_, _x_,     _x_,    _x_,    _x_,    _x_,    _x_,
  _x_, STN_N6,  STN_N7, STN_N8, STN_N9, STN_NA, STN_NB,
  _x_, STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,
       STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
                _x_,    _x_,    _x_,    _x_,    ___,
  _x_, _x_,
  _x_,
  _x_, STN_E,   STN_U
),
};



const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB) // FN1 - Momentary Layer 1 (Symbols)
};

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
      print("string");
      dprintf("dstring");
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
      //SEND_STRING ("shigeo");
      return false;
    default:
      break;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void)
{
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
  steno_set_mode(STENO_MODE_GEMINI);
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state)
{
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer)
  {
  case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#else
#ifdef RGBLIGHT_ENABLE
    rgblight_init();
#endif
#endif
    break;
  case 1:
    ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
    break;
  case 2:
    ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
    break;
  case 3:
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
    break;
  case 4:
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
    break;
  case 5:
    ergodox_right_led_1_on();
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
    break;
  case 6:
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
    break;
  case 7:
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
    break;
  default:
    break;
  }

  return state;
};
