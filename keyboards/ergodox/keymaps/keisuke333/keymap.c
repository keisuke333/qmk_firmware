#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols & cursor

#define _______ KC_TRNS


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |CABrk |           |CADel |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------| F10  |           | F11  |------+------+------+------+------+--------|
 * | LCTRL  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | BASE |           | SYMB |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | Alt  | LGui | Alt  |LANG2+|                                       |LANG1 | Alt  |RCTRL |RCTRL | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Delete| Home |       |Break |Insert|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       |      |        |      |
 *                                 | Space|Back  |------|       |------|        |Enter |
 *                                 |      |space | Esc  |       | Esc  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,   KC_1,    KC_2,    KC_3,    KC_4,               KC_5, LALT(LCTL(KC_BRK)),
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,               KC_T, KC_F10,
        KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,               KC_G,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,               KC_B, TO(BASE),
        KC_NO,    KC_LALT, KC_LGUI, KC_LALT, LT(SYMB, KC_LANG2),
                                                               KC_DEL, KC_HOME,
                                                                        KC_END,
                                                      KC_SPC, KC_BSPC,  KC_ESC,
        // right hand
        LALT(LCTL(KC_DEL)), KC_6,     KC_7,    KC_8,     KC_9,     KC_0,    KC_MINS,
        KC_F11,             KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,    KC_BSLS,
                            KC_H,     KC_J,    KC_K,     KC_L,     KC_SCLN, KC_QUOT,
        TO(SYMB),           KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT,
                            KC_LANG1, KC_RALT, KC_RCTRL, KC_RCTRL, KC_FN1,
        KC_BRK, KC_INS,
        KC_NO,
        KC_ESC, KC_NO, KC_ENT
    ),
/* Keymap 1: Symbol & Cursor Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   ^  |   &  |   *  |   _  |   +  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Left | Down |  Up  |Right |   :  |    "   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |      |      |   <  |   >  |   ?  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
       _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
       _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,
          EPRM, _______, _______, _______, _______,
                                       _______, _______,
                                                _______,
                              _______, _______, _______,
       // right hand
       _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_CIRC, KC_AMPR, KC_PAST, KC_UNDS, KC_PLUS, KC_F12,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQUO,
       _______, _______, _______, KC_LABK, KC_RABK, KC_QUES, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  return MACRO_NONE;
};


uint32_t tmp_layer_state = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;

    // for switch IME
    case KC_LANG1:
      if (!record->event.pressed) {
        register_code(KC_F15);
        unregister_code(KC_F15);
      }
      break;
    case LT(SYMB, KC_LANG2):
      if (record->event.pressed) {
        tmp_layer_state = layer_state;
      } else {
        if (tmp_layer_state == layer_state){
          register_code(KC_F16);
          unregister_code(KC_F16);
	}
      }
    break;
  }
  return true;
}


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};
