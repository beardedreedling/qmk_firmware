/* Copyright 2019 Branden Byers (@brandenbyers)
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

    // ┌─────────┬─────────┬─────────┬─────────┐
    // │         │         │         │         │
    // │    ?    │    ?    │    ?    │    ?    │
    // │         │         │         │         │
    // ├─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │
    // │    ?    │    ?    │    ?    │    ?    │ 
    // │         │         │         │         │
    // ├─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │
    // │    ?    │    ?    │    ?    │    ?    │
    // │         │         │         │         │
    // ├─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │
    // │    ?    │    ?    │    ?    │    ?    │ 
    // │         │         │         │         │
    // ├─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │
    // │    ?    │    ?    │    ?    │    ?    │ 
    // │         │         │         │         │
    // └─────────┴─────────┴─────────┴─────────┘

#include QMK_KEYBOARD_H

enum layers {
    _BASE,   // base layer
    _BLENDER,
    _FUSION,
    _FREECADPRIMARY,
    _FREECADSECONDARY,
    _GOOGLE 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // ┌─────────┬─────────┬─────────┬─────────┐
    // │         │         │         │         │
    // │    ?    │    ?    │    ?    │    ?    │
    // │         │         │         │         │
    // ├─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │
    // │    ?    │    ?    │    ?    │    ?    │ 
    // │         │         │         │         │
    // ├─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │
    // │    ?    │    ?    │    ?    │    ?    │
    // │         │         │         │         │
    // ├─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │
    // │    ?    │    ?    │    ?    │    ?    │ 
    // │         │         │         │         │
    // ├─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │
    // │    ?    │    ?    │    ?    │    ?    │ 
    // │         │         │         │         │
    // └─────────┴─────────┴─────────┴─────────┘


    //           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
    //           │         │         │         │         │         │
    //           │    7    │    8    │    9    │    /    │  ADMIN  │
    //  ROTARY   │         │         │         │         │         │
    //  RIGHT:   ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PAGE DOWN│         │         │         │         │         │
    //           │    4    │    5    │    6    │    *    │  MOUSE  │
    //  ROTARY   │         │         │         │         │         │
    //  LEFT:    ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PAGE UP  │         │         │         │         │         │
    //           │    1    │    2    │    3    │    -    │  MIDI   │
    //           │         │         │         │         │         │
    // ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    // │  TOGGLE │         │         │         │         │         │
    // │  MUSIC  │    0    │    .    │    =    │    +    │  MUSIC  │
    // │         │         │         │         │         │         │
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

    [_BASE] = LAYOUT(
                TG(_GOOGLE), KC_NO, KC_NO, KC_NO, KC_NO,
                TG(_FREECADPRIMARY), KC_NO, KC_NO, KC_NO, KC_NO,
                TG(_FUSION), KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO ,TG(_BLENDER), KC_NO, KC_NO, KC_NO, KC_NO
    ),

    // MUSIC LAYER
    //           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
    //           │         │         │         │         │         │
    //           │         │         │         │         │         │
    //  ROTARY   │         │         │         │         │         │
    //  RIGHT:   ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PAGE DOWN│         │         │         │         │         │
    //           │         │         │         │         │         │
    //  ROTARY   │         │         │         │         │         │
    //  LEFT:    ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PAGE UP  │         │         │         │         │         │
    //           │         │         │         │  MODE   │         │
    //           │         │         │         │         │         │
    // ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │         │         │
    // │         │ RECORD  │  STOP   │         │  PLAY   │         │
    // │         │         │         │         │         │         │
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

    [_BLENDER] = LAYOUT(
                 TG(_GOOGLE), QK_MOUSE_ACCELERATION_1, QK_MOUSE_ACCELERATION_2, KC_NO, KC_NO,
                TG(_FREECADPRIMARY), LSFT(KC_KP_4), LCTL(KC_KP_6), KC_NO, KC_NO,
                TG(_FUSION), LCTL(KC_KP_8), LCTL(KC_KP_2), KC_NO, KC_NO,
        KC_NO ,TG(_BLENDER), LSFT(KC_KP_6), LCTL(KC_KP_4), KC_NO, KC_NO
    ),

    // MIDI LAYER
    //           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
    //           │         │         │         │         │         │
    //           │   D♯    │    E    │    F    │   F♯    │    G    │
    //  ROTARY   │         │         │         │         │         │
    //  RIGHT:   ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PAGE DOWN│         │         │         │         │         │
    //           │   A♯    │    B    │    C    │   C♯    │    D    │
    //  ROTARY   │         │         │         │         │         │
    //  LEFT:    ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PAGE UP  │         │         │         │         │         │
    //           │    F    │   F♯    │    G    │   G♯    │    A    │
    //           │         │         │         │         │         │
    // ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │         │         │
    // │         │    C    │   C♯    │    D    │   D♯    │    E    │
    // │         │         │         │         │         │         │
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

    [_FUSION] = LAYOUT(
                TG(_GOOGLE), KC_NO, KC_NO, KC_NO, KC_NO,
                TG(_FREECADPRIMARY), KC_NO, KC_NO, KC_NO, KC_NO,
                TG(_FUSION), KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO ,TG(_BLENDER), KC_NO, KC_NO, KC_NO, KC_NO
    ),

    // MOUSE LAYER
    //           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
    //           │         │         │         │         │         │
    //           │  BTN 5  │         │  WHEEL  │         │         │
    //  ROTARY   │         │         │   UP    │         │         │
    //  RIGHT:   ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PAGE DOWN│         │         │         │         │         │
    //           │         │  LEFT   │  MOUSE  │  RIGHT  │         │
    //  ROTARY   │         │  CLICK  │   UP    │  CLICK  │         │
    //  LEFT:    ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PAGE UP  │         │         │         │         │         │
    //           │  BTN 4  │  MOUSE  │  MOUSE  │  MOUSE  │         │
    //           │         │  LEFT   │  DOWN   │  RIGHT  │         │
    // ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │         │         │
    // │         │  BTN 3  │  WHEEL  │  WHEEL  │  WHEEL  │         │
    // │         │         │  LEFT   │  DOWN   │  RIGHT  │         │
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

    [_FREECADPRIMARY] = LAYOUT(
                 TG(_GOOGLE), KC_NO, KC_NO, KC_NO, KC_NO,
                TG(_FREECADPRIMARY), LCS(KC_RIGHT), KC_NO, KC_NO, KC_NO,
                TG(_FUSION), LCS(KC_UP), LCTL(KC_EQUAL), LCS(KC_DOWN), KC_NO,
        KC_NO ,TG(_BLENDER), KC_NO, LCS(KC_LEFT), KC_NO, MO(_FREECADSECONDARY)
    ),
    [_FREECADSECONDARY] = LAYOUT(
                 TG(_GOOGLE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                TG(_FREECADPRIMARY), KC_TRNS, KC_RIGHT, KC_TRNS, KC_TRNS,
                TG(_FUSION), KC_UP, LCTL(KC_MINUS), KC_DOWN, KC_TRNS,
        KC_NO ,TG(_BLENDER), KC_TRNS, KC_LEFT, KC_TRNS, KC_TRNS
    ),

    // ADMIN LAYER
    //           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
    //           │         │         │         │         │         │
    //           │ QK_BOOT │         │         │         │         │
    //  ROTARY   │         │         │         │         │         │
    //  RIGHT:   ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PAGE DOWN│         │         │         │         │         │
    //           │    4    │    5    │    6    │    *    │         │
    //  ROTARY   │         │         │         │         │         │
    //  LEFT:    ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PAGE UP  │         │         │         │         │         │
    //           │    1    │    2    │    3    │         │         │
    //           │         │         │         │         │         │
    // ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │         │         │
    // │         │    0    │    .    │    =    │         │         │
    // │         │         │         │         │         │         │
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

    [_GOOGLE] = LAYOUT(
                 TG(_GOOGLE), LCTL(KC_TAB), KC_NO, KC_NO, KC_NO,
                TG(_FREECADPRIMARY), LGUI(KC_RIGHT_BRACKET), KC_NO, KC_NO, KC_NO,
                TG(_FUSION), LGUI(KC_LEFT_BRACKET), KC_NO, KC_NO, KC_NO,
        KC_NO ,TG(_BLENDER), LCS(KC_TAB), KC_NO, KC_NO, KC_NO
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
