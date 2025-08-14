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

#include QMK_KEYBOARD_H

enum layers {
    _BASE,     // base layer
    _FREECAD,  // FreeCAD navigation layer
    _ADMIN     // admin duties
};

// Custom keycodes for FreeCAD navigation
enum custom_keycodes {
    FC_UP = SAFE_RANGE,
    FC_DOWN,
    FC_LEFT,
    FC_RIGHT,
    FC_UP_LEFT,
    FC_UP_RIGHT,
    FC_DOWN_LEFT,
    FC_DOWN_RIGHT,
    FC_FIT,     // Fit all in view
    FC_UNDO,    // Undo
    FC_REDO,    // Redo
    FC_TOGVIS,  // Toggle visibility
    FC_VIEW1,   // Front view (V,1)
    FC_VIEW2,   // Top view (V,2)
    FC_VIEW3    // Right view (V,3)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
    //           │         │         │         │         │         │
    //           │    7    │    8    │    9    │    /    │  ADMIN  │
    //  ROTARY   │         │         │         │         │         │
    //  VOL UP   ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  VOL DOWN │         │         │         │         │         │
    //           │    4    │    5    │    6    │    *    │ FREECAD │
    //  ROTARY   │         │         │         │         │         │
    //  BUTTON:  ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PLAY/PAUSE         │         │         │         │         │
    //           │    1    │    2    │    3    │    -    │         │
    //           │         │         │         │         │         │
    // ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    // │  PLAY/  │         │         │         │         │         │
    // │  PAUSE  │    0    │    .    │    =    │    +    │   ESC   │
    // │         │         │         │         │         │         │
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

    [_BASE] = LAYOUT(
                KC_P7,    KC_P8,   KC_P9,   KC_PSLS, MO(_ADMIN),
                KC_P4,    KC_P5,   KC_P6,   KC_PAST, TG(_FREECAD),
                KC_P1,    KC_P2,   KC_P3,   KC_PMNS, KC_NO,
        KC_MPLY,KC_P0,    KC_PDOT, KC_PEQL, KC_PPLS, KC_ESC
    ),

    // FREECAD LAYER
    //           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
    //           │         │         │         │         │         │
    //           │    ↖    │    ↑    │    ↗    │  UNDO   │         │
    //  ROTARY   │ UP-LEFT │   UP    │UP-RIGHT │ Cmd+Z   │         │
    //  VOL UP   ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  VOL DOWN │         │         │         │         │         │
    //           │    ←    │  FIT    │    →    │  REDO   │  EXIT   │
    //  ROTARY   │  LEFT   │  VIEW   │  RIGHT  │Cmd+Sh+Z │ FREECAD │
    //  BUTTON:  ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PLAY/PAUSE         │         │         │         │         │
    //           │    ↙    │    ↓    │    ↘    │ TOGGLE  │         │
    //           │DOWN-LEFT│  DOWN   │DOWN-RGT │VISIBLE  │         │
    // ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    // │  PLAY/  │         │         │         │         │         │
    // │  PAUSE  │  SPACE  │  FRONT  │   TOP   │  RIGHT  │   ESC   │
    // │         │ CONSTR. │  VIEW   │  VIEW   │  VIEW   │         │
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

    [_FREECAD] = LAYOUT(
                 FC_UP_LEFT,  FC_UP,    FC_UP_RIGHT,  FC_UNDO,    _______,
                 FC_LEFT,     FC_FIT,   FC_RIGHT,     FC_REDO,    TG(_FREECAD),
                 FC_DOWN_LEFT,FC_DOWN,  FC_DOWN_RIGHT,FC_TOGVIS,  _______,
        _______, KC_SPC,      FC_VIEW1, FC_VIEW2,     FC_VIEW3,   KC_ESC
    ),

    // ADMIN LAYER
    //           ┌─────────┬─────────┬─────────┬─────────┬─────────┐
    //           │         │         │         │         │         │
    //           │  BOOT   │         │         │  DEBUG  │         │
    //  ROTARY   │         │         │         │         │         │
    //  VOL UP   ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  VOL DOWN │         │         │         │         │         │
    //           │         │         │         │         │         │
    //  ROTARY   │         │         │         │         │         │
    //  BUTTON:  ├─────────┼─────────┼─────────┼─────────┼─────────┤
    //  PLAY/PAUSE         │         │         │         │         │
    //           │         │         │         │         │         │
    //           │         │         │         │         │         │
    // ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    // │         │         │         │         │         │         │
    // │         │         │         │         │         │         │
    // │         │         │         │         │         │         │
    // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘

    [_ADMIN] = LAYOUT(
                 QK_BOOT, _______, _______, DB_TOGG, TG(_ADMIN),
                 _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______
    ),
};

// Process custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // FreeCAD Navigation Keys with Ctrl+Shift+MouseClick+Direction
        case FC_UP:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_BTN1);
                register_code(KC_MS_U);
            } else {
                unregister_code(KC_MS_U);
                unregister_code(KC_BTN1);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
            
        case FC_DOWN:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_BTN1);
                register_code(KC_MS_D);
            } else {
                unregister_code(KC_MS_D);
                unregister_code(KC_BTN1);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
            
        case FC_LEFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_BTN1);
                register_code(KC_MS_L);
            } else {
                unregister_code(KC_MS_L);
                unregister_code(KC_BTN1);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
            
        case FC_RIGHT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_BTN1);
                register_code(KC_MS_R);
            } else {
                unregister_code(KC_MS_R);
                unregister_code(KC_BTN1);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
            
        // Diagonal movements
        case FC_UP_LEFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_BTN1);
                register_code(KC_MS_U);
                register_code(KC_MS_L);
            } else {
                unregister_code(KC_MS_L);
                unregister_code(KC_MS_U);
                unregister_code(KC_BTN1);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
            
        case FC_UP_RIGHT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_BTN1);
                register_code(KC_MS_U);
                register_code(KC_MS_R);
            } else {
                unregister_code(KC_MS_R);
                unregister_code(KC_MS_U);
                unregister_code(KC_BTN1);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
            
        case FC_DOWN_LEFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_BTN1);
                register_code(KC_MS_D);
                register_code(KC_MS_L);
            } else {
                unregister_code(KC_MS_L);
                unregister_code(KC_MS_D);
                unregister_code(KC_BTN1);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
            
        case FC_DOWN_RIGHT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_BTN1);
                register_code(KC_MS_D);
                register_code(KC_MS_R);
            } else {
                unregister_code(KC_MS_R);
                unregister_code(KC_MS_D);
                unregister_code(KC_BTN1);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
            
        // FreeCAD specific shortcuts
        case FC_FIT:  // Fit all in view (V, 0)
            if (record->event.pressed) {
                tap_code(KC_V);
                wait_ms(50);
                tap_code(KC_0);
            }
            return false;
            
        case FC_UNDO:  // Cmd+Z
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_Z);
                unregister_code(KC_LGUI);
            }
            return false;
            
        case FC_REDO:  // Cmd+Shift+Z
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                tap_code(KC_Z);
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
            }
            return false;
            
        case FC_TOGVIS:  // Toggle visibility (Cmd+D)
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_D);
                unregister_code(KC_LGUI);
            }
            return false;
            
        case FC_VIEW1:  // Front view (V,1)
            if (record->event.pressed) {
                tap_code(KC_V);
                wait_ms(50);
                tap_code(KC_1);
            }
            return false;
            
        case FC_VIEW2:  // Top view (V,2)
            if (record->event.pressed) {
                tap_code(KC_V);
                wait_ms(50);
                tap_code(KC_2);
            }
            return false;
            
        case FC_VIEW3:  // Right view (V,3)
            if (record->event.pressed) {
                tap_code(KC_V);
                wait_ms(50);
                tap_code(KC_3);
            }
            return false;
    }
    return true;
}

// Encoder handling for volume control
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);  // Volume up
        } else {
            tap_code(KC_VOLD);  // Volume down
        }
    }
    return true;
}
