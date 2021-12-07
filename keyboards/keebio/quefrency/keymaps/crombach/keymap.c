#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_with_macro(
    KC_MUTE, MO(_FN2), /**/ KC_GESC, KC_1,    KC_2,    KC_3,   KC_4, KC_5, KC_6,     /**/ KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRAVE, \
    KC_F1,   KC_F2,    /**/ KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R, KC_T,           /**/ KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
    KC_F3,   KC_F4,    /**/ KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F, KC_G,           /**/ KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT, \
    KC_F5,   KC_F6,    /**/ KC_LSFT,          KC_Z,    KC_X,   KC_C, KC_V, KC_B,     /**/ KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, MO(_FN2), \
    KC_F7,   KC_F8,    /**/ KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,             MO(_FN1), /**/         XXXXXXX, KC_SPC,  KC_RALT, KC_RGUI, XXXXXXX, KC_APP,  KC_RCTL
  ),
  [_FN1] = LAYOUT_60_with_macro(
    _______, _______, /**/ _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   /**/ KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
    _______, _______, /**/ _______, _______, KC_UP,   _______, _______, _______,          /**/ _______, _______, KC_UP,   _______, _______, _______, _______, KC_DEL,\
    _______, _______, /**/ _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          /**/ _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,\
    _______, _______, /**/ _______,          _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______,          _______, _______,\
    _______, _______, /**/ _______, _______, _______, _______,                   _______, /**/          _______, _______, _______, _______, _______, _______, _______
  ),
  [_FN2] = LAYOUT_60_with_macro(
    RGB_TOG, _______, /**/ _______, _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, _______, _______, \
    RGB_VAD, RGB_VAI, /**/ _______, _______, _______, _______, _______, _______,          /**/ _______, _______, _______, _______, _______, _______, _______, _______,\
    RGB_HUD, RGB_HUI, /**/ _______, _______, _______, _______, _______, _______,          /**/ _______, _______, _______, _______, _______, _______,          _______,\
    RGB_SAD, RGB_SAI, /**/ _______,          _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______,          _______, _______,\
    RGB_SPD, RGB_SPI, /**/ _______, _______, _______, _______,                   _______, /**/          _______, _______, _______, _______, _______, _______, _______
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
  // First encoder
  if (index == 0) {
    switch (biton32(layer_state)) {
      case _FN2: // Layer 2
        if (clockwise) {
            rgblight_step_reverse();
        } else {
            rgblight_step();
        }
        break;
      case _FN1: // Layer 1
      default: // Base Layer
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
        break;
    }
  }
}
