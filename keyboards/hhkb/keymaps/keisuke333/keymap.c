#include "hhkb.h"

#define BASE 0
#define HHKB 1
#define SPFN 2
#define REST 3
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift     | fn  |
     * +-----------------------------------------------------------------------------------------+
     *         | LGUI|  LAlt  |               Space               | RAlt  | RGUI|
     *         `----------------------------------------------------------------´
     */

  [BASE] = KEYMAP(  //  default layer
  KC_ESC,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,     KC_9,    KC_0,     KC_MINS,  KC_EQL,    KC_BSLS,  KC_GRV, \
  KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_LBRC,  KC_RBRC,   KC_BSPC,          \
  KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,                      \
  KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,  MO(HHKB),                    \
      KC_LGUI,  KC_LALT,               LT(SPFN, KC_SPC),              KC_RALT,  KC_RGUI),



    /* Layer HHKB: HHKB mode (HHKB Fn)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Caps |     |     |     |    |    |    |    | Psc | Slk | Pus | Up  |       | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | VoD | VoU | Mut |    |    | *  | /  | Hom | PgU | Lef | Rig | Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    | +  | -  | End | PgD | Dow |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */


  [HHKB] = KEYMAP(
  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_INS,  KC_DEL, \
  KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_UP,   _______, KC_BSPC,         \
  _______,  KC_VOLD,  KC_VOLU,  KC_MUTE,  _______,  _______,  KC_PAST,  KC_PSLS,  KC_HOME,  KC_PGUP,  KC_LEFT,  KC_RGHT, KC_PENT,                  \
  _______,  _______,  _______,  _______,  _______,  _______,  KC_PPLS,  KC_PMNS,  KC_END,   KC_PGDN,  KC_DOWN,  _______, _______,                  \
                     _______, _______,           _______,                _______, _______),


    /* SpaceFN Layer
     * ref: https://geekhack.org/index.php?topic=51069.0
     * ,-----------------------------------------------------------------------------------------.
     * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |     |     |
     * |-----------------------------------------------------------------------------------------+
     * |        |  !  |  @  |  {  |  }  |  |  |  ^  |  &  |  *  |  -  |  +  |  |  |  \  |        |
     * |-----------------------------------------------------------------------------------------+
     * |         |  #  |  $  |  (  |  )  |  `  |LEFT |DOWN | UP  |RIGHT|     |     |             |
     * |-----------------------------------------------------------------------------------------+
     * |           |  %  |  ^  |  [  |  ]  |  ~  |     |     |     |     |     |           | Fn+ |
     * +-----------------------------------------------------------------------------------------+
     *         |     |        |                                   |       |     |
     *         `----------------------------------------------------------------´
     */

  [SPFN] = KEYMAP(
  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  _______, _______, \
  _______,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_CIRC,  KC_AMPR,  KC_PAST,  KC_PMNS,  KC_PLUS,  _______,  _______, _______,          \
  _______,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,   KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT,  _______,  _______,  _______,                   \
  _______,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,  _______,  _______,  _______,  _______,  _______,  _______,  LT(REST, KC_TRNS),         \
                     _______, _______,           _______,                _______, _______),


    /* RESET Layer
     * ,-----------------------------------------------------------------------------------------.
     * |RESET |     |     |     |     |     |     |     |     |     |     |     |     |     |    |
     * |-----------------------------------------------------------------------------------------+
     * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
     * |-----------------------------------------------------------------------------------------+
     * |         |     |     |     |     |     |     |     |     |     |     |     |             |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |     |     |     |     |     |     |     |     |           |     |
     * +-----------------------------------------------------------------------------------------+
     *         |     |        |                                   |       |     |
     *         `----------------------------------------------------------------´
     */

  [REST] = KEYMAP(
  RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,          \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                    \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                    \
                     _______, _______,          _______,                  _______, _______)


};


const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
