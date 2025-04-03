/* Copyright 2021 Dane Evans
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
// Kiiro setup

#include <stdio.h>

#include QMK_KEYBOARD_H
#include "keymap_czech.h"


enum sofle_layers {
    _QWERTY   = 0,
    _CHARS,
    _EDIT,
    _NUMS,
    _TETRIS,
};


#define QWERTY PDF(_QWERTY)

#define NUMS LT(_NUMS, KC_ESC)
#define TETR TG(_TETRIS)
#define EDIT MO(_EDIT)
#define CHARS MO(_CHARS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * _QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|  MUTE |    | _TETR |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |Space | /_EDIT  /       \_CHAR \  |Enter | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    
    [_QWERTY] = LAYOUT(
        NUMS,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
      KC_GRV,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
      KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
      KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,       TETR,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LGUI, KC_LALT, KC_LCTL, KC_SPC,EDIT,          CHARS, KC_ENT,  KC_RCTL,    KC_RALT, KC_RGUI
    ),
    
    /* _CHARS
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |Space | /_EDIT  /       \_CHAR \  |Enter | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_CHARS] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
      _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       XXXXXXX, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                        _______, _______, _______, _______, _______,       _______, _______,   _______, _______, _______
    ),
    
    /* _EDIT
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | Esc  |CpsLck|Prtscn|Scrlck|Pause |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |Insert| Home |Pg Up |      |                    |      |      |      |      |      | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      | Del  | End  |Pg Dn |      |-------.    ,-------|      |      |  Up  |      |      |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|      |      |     |       |      |-------|    |-------|      | Left | Down | Right|      |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |Space | /_EDIT  /       \_CHAR \  |Enter | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_EDIT] = LAYOUT(
        _______, KC_CAPS, KC_PSCR, KC_SCRL, KC_PAUS, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_INS , KC_HOME, KC_PGUP, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, KC_DEL , KC_END , KC_PGDN, XXXXXXX,                         XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,       XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______,
                          _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
    ),
    
    /* _NUMS
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | Esc  |      |      |      |      |      |                    |      |NumLck|  /   |  *   |  -   |  =   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |  7   |  8   |  9   |  +   | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |      |      |      |      |-------.    ,-------|      |  4   |  5   |  6   |      |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      |  1   |  2   |  3   |      |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |Space | /_EDIT  /       \_CHAR \  |Enter |  0   |  .   |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_NUMS] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX,  KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, KC_PEQL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX,   KC_P7,   KC_P8,   KC_P9, KC_PPLS, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX,   KC_P4,   KC_P5,   KC_P6, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,       XXXXXXX, XXXXXXX,   KC_P1,   KC_P2,   KC_P3, XXXXXXX, _______,
                          _______, _______, _______, _______, _______,       _______, _______,   KC_P0,  KC_PDOT, XXXXXXX
      ), 
    
    /* _TETRIS
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |   Y  |                    |      |      |      |      |      | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |      |   S  |      |      |-------.    ,-------|      |      |  Up  |      |      |      |
     * |------+------+------+------+------+------|  MUTE |    | _TETR |------+------+------+------+------+------|
     * |LShift|      |   Z  |   X  |   C  |      |-------|    |-------|      |Left  | Down |Right |      |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      | LCTR |Space | /       /       \      \  |Enter | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_TETRIS] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_Y,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_S,    XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_Z,    KC_X,    KC_C,    XXXXXXX, _______,       _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______,
                          XXXXXXX, XXXXXXX, _______, _______, XXXXXXX,       XXXXXXX, _______, _______, _______, _______
    )
    
    // /* _EMPTY
    //  * ,-----------------------------------------.                    ,-----------------------------------------.
    //  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
    //  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    //  * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
    //  * `-----------------------------------------/       /     \      \-----------------------------------------'
    //  *            |      |      |      |      | /       /       \      \  |      |      |      |      |
    //  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    //  *            `----------------------------------'           '------''---------------------------'
    //  */
    // [_EMPTY] = LAYOUT(
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    //                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    //   ) 
    };

#ifdef OLED_ENABLE
#    include "oled.c"
#endif

#ifdef ENCODER_ENABLE
#    include "encoder.c"
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /*switch (keycode) {*/
    /*    case KC_LOWER:*/
    /*        if (record->event.pressed) {*/
    /*            layer_on(_LOWER);*/
    /*            update_tri_layer(_LOWER, _RAISE, _ADJUST);*/
    /*        } else {*/
    /*            layer_off(_LOWER);*/
    /*            update_tri_layer(_LOWER, _RAISE, _ADJUST);*/
    /*        }*/
    /*        return false;*/
    /*}*/
    return true;
}
