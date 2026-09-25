// Copyright 2024 Lee Haugen (@internetlee)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "transactions.h"

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
 *          | NO | Cmd | NO |Lower|Hypr/ Enter /       \Raise \ RAlt |Space| NO |
 *          |    |     |    |     |    /       /         \      \     |     |    |
 *          `------------------------------'           '------------------------'
 *   Encoder push:  L = Mute,   R = Play/Pause.
 *   Encoder twist: L = Volume, R = Zoom.  Raise+L = Undo/Redo, Lower+R = Scroll.
 *   Big left thumb = Hyper (hold).  Adjust = hold Lower + Raise (tri-layer).
 */
[_QWERTY] = LAYOUT(
  KC_GRV,          KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,          KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  LCTL_T(KC_ESC),  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SC_LSPO,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, KC_MUTE,        KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,
                   KC_NO, KC_LGUI, KC_NO, TL_LOWR, ALL_T(KC_NO),  KC_ENT, TL_UPPR, KC_RALT, KC_SPC, KC_NO
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
 * | Caps |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CapWd|      |      |      |      |      |-------.    ,-------| Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|      |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 */
[_RAISE] = LAYOUT(
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  CW_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
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

#ifdef ENCODER_ENABLE
// Encoders are layer-aware. A held layer occupies the thumb on the *same* side
// as one knob, so only the two comfortable cross-hand combos get a special
// role; every other layer/knob combination falls back to the base behavior.
//
//   Base :  L = Volume        R = Zoom (Cmd -/+)
//   Raise:  L = Undo / Redo   (right knob falls back to Zoom)
//   Lower:                    R = Scroll  (left knob falls back to Volume)
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            if (index == 0) { // left knob: undo / redo
                tap_code16(clockwise ? SGUI(KC_Z) : LGUI(KC_Z));
                return false;
            }
            break;
        case _LOWER:
            if (index == 1) { // right knob: scroll wheel
                tap_code(clockwise ? MS_WHLD : MS_WHLU);
                return false;
            }
            break;
        default:
            break;
    }

    // Base / fallback for every other layer and knob.
    if (index == 0) { // left knob: volume
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
    } else {          // right knob: zoom
        tap_code16(clockwise ? LGUI(KC_EQL) : LGUI(KC_MINS));
    }
    return false;
}
#endif

// --- Split sync + init -----------------------------------------------------
// Caps Lock and layer state are synced to the slave automatically (see
// config.h). Caps Word is master-only, so mirror it to the slave over a small
// RPC transaction; that lets the caret indicator match on both halves.
static bool caps_word_synced = false;

#ifdef CAPS_WORD_ENABLE
static void sync_caps_word_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
    caps_word_synced = *(const bool *)in_data;
}
#endif

void keyboard_post_init_user(void) {
#ifdef CAPS_WORD_ENABLE
    transaction_register_rpc(RPC_ID_SYNC_CAPS_WORD, sync_caps_word_handler);
#endif
#ifdef OLED_ENABLE
    // Force *both* halves to the tall orientation (sofle.c only rotates master).
    oled_init(OLED_ROTATION_270);
#endif
}

void housekeeping_task_user(void) {
#ifdef CAPS_WORD_ENABLE
    if (is_keyboard_master()) {
        static bool prev = false;
        bool now = is_caps_word_on();
        caps_word_synced = now;
        if (now != prev) {
            if (transaction_rpc_send(RPC_ID_SYNC_CAPS_WORD, sizeof(now), &now)) {
                prev = now; // only latch once the slave has the update
            }
        }
    }
#endif
}

#ifdef OLED_ENABLE
// Both halves show a tall HUD: the active layer in caps, this half's own knob
// action, and (only while caps is active) a row of carets across the bottom.
// The display is 5 glyphs wide, so labels are padded to 5 to overwrite cleanly.
static const char *hud_layer_name(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY: return "BASE ";
        case _LOWER:  return "LOWER";
        case _RAISE:  return "RAISE";
        case _ADJUST: return "ADJST";
        default:      return "?    ";
    }
}

// Left knob: undo/redo scrub on Raise, else volume.
static const char *hud_left_knob(void) {
    return (get_highest_layer(layer_state) == _RAISE) ? "SCRUB" : "VOL  ";
}

// Right knob: scroll on Lower, else zoom.
static const char *hud_right_knob(void) {
    return (get_highest_layer(layer_state) == _LOWER) ? "SCRL " : "ZOOM ";
}

static bool hud_caps_active(void) {
    if (host_keyboard_led_state().caps_lock) {
        return true;
    }
#ifdef CAPS_WORD_ENABLE
    if (caps_word_synced) {
        return true;
    }
#endif
    return false;
}

bool oled_task_user(void) {
    // Layer name, top.
    oled_set_cursor(0, 1);
    oled_write(hud_layer_name(), false);

    // This half's own knob action.
    oled_set_cursor(0, 3);
    oled_write(is_keyboard_left() ? hud_left_knob() : hud_right_knob(), false);

    // Caps active -> carets across the bottom; blank the row when off.
    oled_set_cursor(0, 15);
    oled_write(hud_caps_active() ? "^^^^^" : "     ", false);

    return false; // we own both screens
}
#endif
