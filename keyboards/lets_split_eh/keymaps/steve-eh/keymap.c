#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0

#define _LOWER 3
#define _RAISE 4
#define _FUNCTION 15
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Func |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  `   | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_TAB,        KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, \
  MO(_FUNCTION), KC_A,   KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,  \
  OSM(MOD_LSFT), KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
  KC_LCTL,       KC_GRV, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      | Mute |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower | Bksp | Bksp |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_ESC,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_MUTE, _______, _______, \
  _______, _______,  _______, _______, _______, KC_BSPC, KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   +  |  F5  |  F6  |   -  |   =  |   [  |   ]  |   \  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Enter |   7  |   8  |   9  |   -  |  F11 |  F12 |ISO # |ISO / | Mute |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ,  |   0  |  .   |Lower | Bksp | Bksp |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,  KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  _______, KC_4,    KC_5,  KC_6,   KC_PLUS, KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_ENT,  KC_7,    KC_8,  KC_9,   KC_MINS, KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_MUTE, _______, _______, \
  _______, KC_COMM, KC_0,  KC_DOT, _______, KC_BSPC, KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Taskmg|      |      |      |      |      |      |      |RGBVAI|RGBSAI|RGBHUI|caltde|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|RGBVAD|RGBSAD|RGBHUD|RGBTOG|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |BLSTEP|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | RESET|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT( \
  TSKMGR,  _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, CALTDEL, \
  _______, _______, _______, _______, _______, _______, _______, QWERTY,  RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_STEP, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET    \
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

// This is run every time layers are changed.
uint32_t layer_state_set_user(uint32_t state) {
  // typically the LOWER and RAISE keycodes just layer_on() and update_tri_layer(),
  // which causes two layer state changes in quick succession.
  // since there is some issue with updating the rgblight underglow LEDs so rapidly,
  // we compute the third layer's state here once during a single layer_state_set()
  // instead.
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

  // get existing value to avoid changing the EEPROM-configured brightness
  // hue and saturation need to be controlled here to fully control colour
  uint8_t cur_val = rgblight_get_val();

  // state is bitmask of active layers, of the max 32 layers
  // biton32() is most significant on-bit, i.e. highest enabled layer
  switch (biton32(state)) {
    /*case _SDV1:*/
    /*case _SDV2:*/
      /*rgblight_sethsv_noeeprom(90, 255, cur_val); // chartreuse green*/
      /*break;*/
    /*case _OVCK:*/
      /*rgblight_sethsv_noeeprom(30, 255, cur_val); // orange*/
      /*break;*/
    case _LOWER:
      rgblight_sethsv_noeeprom(210, 255, cur_val); // azure
      break;
    case _RAISE:
      rgblight_sethsv_noeeprom(150, 255, cur_val); // spring green
      break;
    case _ADJUST:
      rgblight_sethsv_noeeprom(180, 255, cur_val); // cyan (blue + green)
      break;
    default:
      rgblight_sethsv_noeeprom(0, 0, cur_val); // white
      break;
  }

  // transmit the rgblight change to slave
  RGB_DIRTY = true;

  return state;
}
