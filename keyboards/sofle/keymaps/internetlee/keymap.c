// Copyright 2024 Lee Haugen (@internetlee)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

// Ported from the keebio/iris "leegenes" keymap so the transition
// between the Iris and the Sofle is as close as possible.
//
// The alpha grid maps 1:1 with the Iris. The Sofle has more thumb keys
// than the Iris, so the Iris thumb roles are placed on the analogous
// *inner* Sofle thumb keys and the two outermost thumb keys per side
// are left unused (KC_NO).

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Ctl/Es|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| ADJ  |    | MUTE  |------+------+------+------+------+------|
 * |Sft/( |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Sft/) |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *          | NO | Cmd | NO |Lower| NO / Enter /       \Raise \ RAlt |Space| NO |
 *          |    |     |    |     |   /       /         \      \     |     |    |
 *          `------------------------------'           '------------------------'
 *   Encoder clicks: left = Mute, right = Play/Pause.
 *   Adjust layer = hold Lower + Raise together (tri-layer).
 */
[_QWERTY] = LAYOUT(
  KC_GRV,          KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,          KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  LCTL_T(KC_ESC),  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SC_LSPO,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, KC_MUTE,        KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,
                   KC_NO, KC_LGUI, KC_NO, TL_LOWR, KC_NO,        KC_ENT, TL_UPPR, KC_RALT, KC_SPC, KC_NO
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |   +  |                    |   =  | Prev | Play | Next | Vol- | Vol+ |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |   -  |                    |   _  |      |      |      |      | Mute |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |   [  |-------.    ,-------|   ]  |      |      |      |      |      |
 * |------+------+------+------+------+------|      |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |   {  |-------|    |-------|   }  |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 */
[_LOWER] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS,                        KC_EQL,  KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS,                        KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC,                        KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, _______,      _______, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|      |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 */
[_RAISE] = LAYOUT(
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | DbTgl|      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|      |    |       |------+------+------+------+------+------|
 * | Boot |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  DB_TOGG, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                     _______,  _______, _______, _______, _______,   _______,  _______, _______, _______, _______
)

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_LOWER]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_RAISE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
};
#else
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // left encoder: volume
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { // right encoder: page up/down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
