/* Copyright 2019 e3w2q
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  CUSTOM_KEYCODES = SAFE_RANGE,
};


enum layer_number {
  _QWERTY = 0,
  _SIGN,
  _VIM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default Layer
   *  Master Side (USB Cable Connected Side)
   *  ,-----------------------------------------
   *  |   A1   B1   C1   D1   E1   F1   G1   H1 
   *  |   A2   B2   C2   D2   E2   F2   G2   H2 
   *  |   A3   B3   C3   D3   E3   F3   G3   H3 
   *  |   A4   B4   C4   D4   E4   F4   G4   H4 
   *  |   A5   B5   C5   D5   E5   F5   G5   H5 
   *  |   A6   B6   C6   D6   E6   F6   G6   H6 
   *  `-----------------------------------------
   *  Slave Side (USB Cable Not Connected Side)
   *  ,-----------------------------------------
   *  |  SA1  SB1  SC1  SD1  SE1  SF1  SG1  SH1 
   *  |  SA2  SB2  SC2  SD2  SE2  SF2  SG2  SH2 
   *  |  SA3  SB3  SC3  SD3  SE3  SF3  SG3  SH3 
   *  |  SA4  SB4  SC4  SD4  SE4  SF4  SG4  SH4 
   *  |  SA5  SB5  SC5  SD5  SE5  SF5  SG5  SH5 
   *  |  SA6  SB6  SC6  SD6  SE6  SF6  SG6  SH6 
   *  `-----------------------------------------
   */

   [_QWERTY] = LAYOUT( /* Base */ 
    KC_BSLS,  KC_QUOT,  OPT_T(KC_LANG1),  CTL_T(KC_ENT),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_P,     KC_SCLN,  KC_SLSH,          MO(_VIM),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_O,     KC_L,     KC_DOT,           KC_BSPC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_I,     KC_K,     KC_COMM,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_U,     KC_J,     KC_M,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_Y,     KC_H,     KC_N,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  

    KC_T,     KC_G,     KC_B,             SFT_T(KC_SPC), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_R,     KC_F,     KC_V,             MO(_SIGN), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_E,     KC_D,     KC_C,             KC_LGUI, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_W,     KC_S,     KC_X,             XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_Q,     KC_A,     KC_Z,             XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_TAB,   CTL_T(KC_ESC), CMD_T(KC_LANG2) , XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [_SIGN] = LAYOUT(
    KC_TILD,  KC_GRV,   _______,  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_0,     KC_RPRN,  XXXXXXX,  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_9,     KC_LPRN,  KC_RCBR,  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_8,     KC_ASTR,  KC_LCBR,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_7,     KC_AMPR,  KC_RBRC,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_6,     KC_CIRC,  KC_LBRC,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

    KC_5,     KC_PERC,  LCTL(LGUI(KC_SPACE)), _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_4,     KC_DLR,   KC_EQL,   _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_3,     KC_HASH,  KC_MINS,  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_2,     KC_AT,    KC_PLUS,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_1,     KC_EXLM,  KC_UNDS,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______,  _______,  _______,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_VIM] = LAYOUT(
    _______,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F10,   XXXXXXX,  XXXXXXX,  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F9,    KC_RGHT,  XXXXXXX,  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F8,    KC_UP,    KC_PGUP,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F7,    KC_DOWN,  KC_PGDN,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F6,    KC_LEFT,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

    KC_F5,    XXXXXXX,  XXXXXXX,  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F4,    XXXXXXX,  XXXXXXX,  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F3,    XXXXXXX,  XXXXXXX,  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F2,    KC_F12,   XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F1,    KC_F11,   XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______,  _______,  _______,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
