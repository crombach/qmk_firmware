/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

enum layers {
  _MACRO,
  _SYSTEM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Up/Dn |                   | Knob 2: Page Dn/Up |
        | Press: Mute       | Toggle Layer 1 On | Press: Play/Pause  |
        | Previous Track    | Play/Pause        | Next Track         |
        | CTRL + ALT + F22 |  CTRL + ALT + F23  | CTRL + ALT + F24   |
     */
    [0] = LAYOUT(
        KC_MUTE    , TG(_SYSTEM), KC_HOME,
        KC_MPRV    , KC_MPLY    , KC_MNXT,
        LCA(KC_F13), LCA(KC_F14), LCA(KC_F15)
    ),
    /*
        | Knob 1: RGB Hue Up/Dn |                     | Knob 2: RGB Saturation Up/Dn |
        | Press: RGB On/Off     | Toggle Layer 0 On   | Press: System Power Down     |
        | RGB Mode Next         | RGB Brightness Up   | System Sleep                 |
        | RGB Mode Prev         | RGB Brightness Down | System Wake                  |
     */
    [1] = LAYOUT(
        RGB_TOG , _______, KC_PWR ,
        RGB_MOD , RGB_VAI, KC_SLEP,
        RGB_RMOD, RGB_VAD, KC_WAKE
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        switch(biton32(layer_state)) {
            case _SYSTEM:
                if (clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
                }
                break;
            case _MACRO:
            default:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
        }
    }
    else if (index == _MIDDLE) {
        // Not installed right now, but leaving it here for the future.
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    else if (index == _RIGHT) {
        switch(biton32(layer_state)) {
            case _SYSTEM:
                if (clockwise) {
                    rgblight_increase_sat();
                } else {
                    rgblight_decrease_sat();
                }
                break;
            case _MACRO:
            default:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
        }
    }
}
