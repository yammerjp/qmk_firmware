/* Copyright 2015-2017 Jack Humbert
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
 // sudo make planck/rev6:basd4g:dfu-util

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------.
 * | Tab    |   Q  |   W  |   E  |   R  |   T   |   Y   |   U  |   I  |   O  |   P  |  \     |
 * |--------+------+------+------+------+-------+-------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G   |   H   |   J  |   K  |   L  |   ;  |  '     |
 * |--------+------+------+------+------+-------+-------+------+------+------+------+--------|
 * |CMD/Eisu|   Z  |   X  |   C  |   V  |   B   |   N   |   M  |   ,  |   .  |   /  |OPT/Kana|
 * |--------+------+------+------+------+-------+-------+------+------+------+------+--------|
 * |        |      |      | GUI  |Lower |SFT/SPC|CTL/ENT|Raise | BSPS |      |      |        |
 * `-----------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,          KC_Y,          KC_U,       KC_I,    KC_O,   KC_P,    KC_BSLS,
    CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,       KC_G,          KC_H,          KC_J,       KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    CMD_T(KC_LANG2), KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,          KC_N,          KC_M,       KC_COMM, KC_DOT, KC_SLSH, OPT_T(KC_LANG1),
    XXXXXXX,       XXXXXXX, XXXXXXX, KC_LGUI, MO(_LOWER), SFT_T(KC_SPC), CTL_T(KC_ENT), MO(_RAISE), KC_BSPC, XXXXXXX,XXXXXXX, XXXXXXX
),

/* Lower
 * ,-------------------------------------------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   ~   |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------|
 * |        |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   `   |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------|
 * |        |   _  |   +  |   -  |   =  |      |   [  |   ]  |   {  |   }  |      |SFT+SPC|
 * |--------+------+------+------+------+------+------+------+------+------+------+-------|
 * |CTL+LEFT|      |      |      |      |      |      |      |  DEL |      |      |CTL+UP |
 * `--------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TILD,
    _______,       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
    _______,       KC_UNDS, KC_PLUS, KC_MINS, KC_EQL,  XXXXXXX, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX, LSFT(KC_SPC),
    LCTL(KC_LEFT), _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, LCTL(KC_UP)
),

/* Raise
 * ,-----------------------------------------------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   F7   |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+------+------+--------+------+------+------+--------|
 * |        | F11  | F12  |      |      |      | LEFT |  DOWN  |  UP  | RIGHT|      |        |
 * |--------+------+------+------+------+------+------+--------+------+------+------+--------|
 * |        |      |      |      |      |      |      |PAGEDOWN|PAGEUP|      |      |        |
 * |--------+------+------+------+------+------+------+--------+------+------+------+--------|
 * |CTL+DOWN|      |      |      |      |      |      |        |      |      |      |CTL+LGHT|
 * `-----------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______,       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______,       KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, _______,
    LCTL(KC_DOWN), _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, LCTL(KC_RGHT)
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
