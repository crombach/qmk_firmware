/*
Copyright 2021 Spencer Deven <splitlogicdesign@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _GAMING,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAMING,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(
      GRAVE_ESC, KC_1,    KC_2,    KC_3,      KC_4,     KC_5,                                       KC_6, KC_7,     KC_8,      KC_9,    KC_0,    KC_BSLS,
      KC_TAB,    KC_Q,    KC_W,    KC_E,      KC_R,     KC_T, KC_LBRC,                     KC_RBRC, KC_Y, KC_U,     KC_I,      KC_O,    KC_P,    KC_BSPC,
      KC_CAPS,   KC_A,    KC_S,    KC_D,      KC_F,     KC_G, KC_MINS,                     KC_EQL,  KC_H, KC_J,     KC_K,      KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT,   KC_Z,    KC_X,    KC_C,      KC_V,     KC_B, KC_GRV, KC_MUTE,    RGB_TOG, KC_DEL,  KC_N, KC_M,     KC_COMM,   KC_DOT,  KC_SLSH, KC_RSFT,
      KC_LCTL,   KC_LGUI, KC_LALT, KC_ADJUST, KC_LOWER, /**/  KC_SPC, KC_ENT,     KC_ENT,  KC_SPC,  /**/  KC_RAISE, KC_ADJUST, KC_RALT, KC_RGUI, KC_RCTL
    ),

    [_GAMING] = LAYOUT(
      GRAVE_ESC, KC_1,    KC_2,    KC_3,      KC_4,     KC_5,                                       KC_6, KC_7,     KC_8,      KC_9,    KC_0,    KC_BSLS,
      KC_TAB,    KC_Q,    KC_W,    KC_E,      KC_R,     KC_T, KC_LBRC,                     KC_RBRC, KC_Y, KC_U,     KC_I,      KC_O,    KC_P,    KC_BSPC,
      KC_CAPS,   KC_A,    KC_S,    KC_D,      KC_F,     KC_G, KC_MINS,                     KC_EQL,  KC_H, KC_J,     KC_K,      KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT,   KC_Z,    KC_X,    KC_C,      KC_V,     KC_B, KC_GRV, KC_MUTE,    RGB_TOG, KC_DEL,  KC_N, KC_M,     KC_COMM,   KC_DOT,  KC_UP,   KC_RSFT,
      KC_LCTL,   KC_LGUI, KC_LALT, KC_ADJUST, KC_LOWER, /**/  KC_SPC, KC_ENT,     KC_ENT,  KC_SPC,  /**/  KC_RAISE, KC_ADJUST, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

	[_LOWER] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                                         KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
      _______, _______, _______, KC_UP,   _______, _______, _______,                      _______, _______, _______, KC_UP,   _______,  _______, KC_F12,
      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                      _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, /*   */  _______, _______,    _______, _______, /*   */  _______, _______, _______,  _______, _______
      ),

	[_RAISE] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      _______, _______, _______, KC_UP,   _______, _______, _______,                      _______, _______, KC_UP,   _______, _______, _______, KC_F12,
      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, /*   */  _______, _______,    _______, _______, /*   */  _______, _______, _______, _______, _______
      ),

	[_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      _______, _______, _______, _______, _______, _______, KC_QWERTY,                      _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, KC_F12,
      _______, _______, _______, _______, _______, _______, KC_GAMING,                      _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,   _______,    _______, _______, _______, _______, _______, _______, _______, _______,
      CG_TOGG, _______, _______, _______, _______, /*   */  _______,   _______,    _______, _______, /*   */  _______, _______, _______, _______, CG_TOGG
      )

};
#ifdef OLED_ENABLE

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       60

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           32   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;
/* current row (used for rendering frames) */
uint8_t current_row = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][3][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                                                       { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                                                       { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {
                                                       { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                                                       { 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                                                       { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
                                                   }};

    /* Walk */
    static const char PROGMEM walk[2][3][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00 },
                                                        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00 },
                                                        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00 },
                                                        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00 },
                                                        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
                                                    }};

    /* Run */
    static const char PROGMEM run[2][3][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       { 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00 },
                                                       { 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00 },
                                                       { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00 }
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       { 0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00 },
                                                       { 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00 },
                                                       { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][3][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        { 0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00 },
                                                        { 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00 },
                                                        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        { 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00 },
                                                        { 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10 },
                                                        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][3][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
                                                         { 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00 },
                                                         { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00 }
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00 },
                                                         { 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00 },
                                                         { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00 }
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        uint8_t current_row_offset = 0;
        if (isJumping || !showedJump) {
            /* clear the bottom line of Luna */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write_P(PSTR("     "), false);
            current_row_offset = 1;
            showedJump = true;
        } else {
            /* clear the line above Luna */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write_P(PSTR("     "), false);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;
        current_row = 0;

        /* current status */
        for (current_row = 0; current_row < 3; current_row++) {
            oled_set_cursor(LUNA_X, LUNA_Y + current_row - current_row_offset);
            if (led_usb_state.caps_lock) {
                oled_write_raw_P(bark[abs(1 - current_frame)][current_row], ANIM_SIZE);
            } else if (isSneaking) {
                oled_write_raw_P(sneak[abs(1 - current_frame)][current_row], ANIM_SIZE);
            } else if (current_wpm <= MIN_WALK_SPEED) {
                oled_write_raw_P(sit[abs(1 - current_frame)][current_row], ANIM_SIZE);
            } else if (current_wpm <= MIN_RUN_SPEED) {
                oled_write_raw_P(walk[abs(1 - current_frame)][current_row], ANIM_SIZE);
            } else {
                oled_write_raw_P(run[abs(1 - current_frame)][current_row], ANIM_SIZE);
            }
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }

    /* this fixes the screen on and off bug */
    if (current_wpm > 0) {
        oled_on();
        anim_sleep = timer_read32();
    } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
        oled_off();
    }
}

/* KEYBOARD PET END */

static void print_status(void) {
     /* Print current mode */
    oled_set_cursor(0, 1);
    oled_write_P(PSTR("MODE"), false);
    oled_set_cursor(0, 2);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(PSTR("Mac"), false);
    } else {
        oled_write_P(PSTR("Win"), false);
    }
    oled_set_cursor(0, 3);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:       
            oled_write_P(PSTR("Qwerty"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("Gaming"), false);
            break;
        default:
            oled_write_P(PSTR("Undef "), false);
    }

    /* Print current layer */
    oled_set_cursor(0, 6);
    oled_write("LAYER", false);
    oled_set_cursor(0, 7);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base "), false);
            break;
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj  "), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    /* caps lock */
    oled_set_cursor(0, 10);
    oled_write_P(PSTR("CPSLK"), led_usb_state.caps_lock);

    /* KEYBOARD PET RENDER START */

    render_luna(2, 13);

    /* KEYBOARD PET RENDER END */
}

static void print_wpm(void) {
    /* wpm counter */
    oled_set_cursor(0, 15);
    oled_write_P(PSTR(" WPM: "), false);
    oled_write(get_u8_str(current_wpm, '0'), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_90;
    }
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status();
    } else {
        print_wpm();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        /* KEYBOARD PET STATUS START */
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
        /* KEYBOARD PET STATUS END */
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (clockwise) {
            rgblight_step();
        } else {
            rgblight_step_reverse();
        }
    }
    return true;
}

#endif
