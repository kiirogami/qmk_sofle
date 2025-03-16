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

#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _CHARS,
    _VIM,
    _NUMPAD,
};

/*enum custom_keycodes {*/
/*};*/

#define KC_QWERTY PDF(_QWERTY)

#define ESC_CHAR LT(_CHARS, KC_ESC)
#define BCS_VIM LT(_VIM, KC_BSPC)
#define CTL_RET MT(MOD_LCTL, KC_ENT)
#define MOD_SPC MT(MOD_LGUI, KC_SPC)
#define MO_NP MO(_NUMPAD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Caps |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------| +- vol      scroll |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  | E+Ctl|      |
 * |------+------+------+------+------+------| MUTE  |    | PrtSc |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |NumPad| Alt  | Space | /LShift/      \ Bspc \  | Esc   |  Cz  |      |      |
 *            |      |      |      |  Win  |/      /        \ Nav  \ | Char  |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------.                    ,---------------------------------------------------.
  KC_CAPS, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    _______,
  //|-------------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    _______,
  //|-------------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TAB,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    CTL_RET, _______,
  //|-------------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,   KC_PSCR, KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, _______,
  //|-------------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                _______,   MO_NP,  KC_LALT, MOD_SPC, KC_LSFT,   BCS_VIM,  ESC_CHAR,  KC_RALT,  _______,  _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* CHARS
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |   &  |                    |   |  |   _  |   "  |   '  |   `  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   #  |   ;  |   (  |   )  |   ?  |-------.    ,-------|   !  |   =  |   -  |   +  |   %  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   ~  |  [   |  ]   |   ^  |   $  |-------|    |-------|   :  |   *  |   <  |   >  |   @  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_CHARS] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, _______ , _______ , _______ , _______ , _______,               _______,  _______  , _______,  _______ ,  _______ ,_______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______,  KC_BSLS,KC_SLSH, KC_LCBR, KC_RCBR,KC_AMPR,                    KC_PIPE,  KC_UNDS, KC_DQT,  KC_QUOT,  KC_GRV, _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______,  KC_HASH, KC_SCLN, KC_LPRN, KC_RPRN, KC_QUES,                  KC_EXLM,  KC_EQL,  KC_MINS, KC_PLUS, KC_PERC, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______,  KC_TILD, KC_LBRC, KC_RBRC, KC_CIRC, KC_DLR,_______,    _______,KC_COLN,  KC_ASTR,  KC_LT, KC_GT,   KC_AT,   _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

#define MED_PP KC_MEDIA_PLAY_PAUSE

/* VIM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | prev |      |      |Ctl+R |      |      |                    |      | PgUp |      |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | play |      |      |PgDown|      |      |-------.    ,-------| Left | Down |  Up  | Rigth|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | next |      |      |      |      |Ctl+L |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_VIM] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_MPRV,  XXXXXXX,XXXXXXX,LCTL(KC_RIGHT),XXXXXXX,XXXXXXX,               XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  MED_PP,   XXXXXXX,XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,   XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_MNXT,  XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,LCTL(KC_LEFT),_______, _______,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|      |      |      |      |      |                    |      |NumLck|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |      |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMPAD] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NUM,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_7,  KC_8,   KC_9,   KC_ASTR, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+------+-------+-------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_4,  KC_5,   KC_6,   KC_EQL,  KC_PIPE,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+------+-------+-------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,KC_PLUS, KC_1,  KC_2,   KC_3,   KC_SLSH, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
              _______, OSM(MOD_MEH), _______, _______, _______,   _______, _______,  KC_P0,   KC_PDOT, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
)

};


#ifdef OLED_ENABLE
    #include "oled.c"
#endif

#ifdef ENCODER_ENABLE
    #include "encoder.c"
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
