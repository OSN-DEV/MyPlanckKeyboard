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

#include "planck.h"
#include "action_layer.h"
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _DEFAULT,
  _USER1,
  _USER2,
  _USER3,
  _USER4,
  _USER5,
  _ADJUST
};

enum planck_keycodes {
  DEFAULT = SAFE_RANGE,
  USER1,
  USER2,
  USER3,
  USER4,
  USER5
};

#define USER1 MO(_USER1)
#define USER2 MO(_USER2)
#define USER3 MO(_USER3)
#define USER4 MO(_USER4)
#define USER5 MO(_USER5)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Default
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Esc   |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    | User4  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | User5  |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |   ;    |   -    |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | Shift  |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   ,    |   .    |   /    | Enter  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |  Win   |  Alt   | Usre3  | User1  |      Space      | User2  |  Left  |  Down  |   Up   | Right  |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_DEFAULT] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    USER4,
    USER5,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, USER3,   USER1,   KC_SPC,  KC_SPC,  USER2,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* User1
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Esc   |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |  Bksp  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |  Tab   |   ^    |   \|   |   ]    |   \_   |        |        |  Home  |  End   | Enter  |  Esc   | Pg Up  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | Shift  |        |   -    |   :    |        |        |  Del   |  Bksp  |  Ins   |  Tab   |   Up   | Pg Dn  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |  Win   |  Alt   |        | User1  |      Space      |  変換  |  かな  |  Left  |  Down  | Right  |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_USER1] = LAYOUT_planck_grid(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_EQL,  KC_JYEN, KC_NUHS, KC_RO,   XXXXXXX, XXXXXXX, KC_HOME, KC_END,  KC_ENT,  KC_ESC,  KC_PGUP,
    _______, XXXXXXX, KC_MINS, KC_QUOT, XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, KC_INS,  KC_TAB,  KC_UP,   KC_PGDN ,
    _______, _______, _______, XXXXXXX, _______, _______, _______, KC_HENK, KC_KANA, KC_LEFT, KC_DOWN, KC_RGHT
),

/* User2
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Esc   |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |  F10   |  Bksp  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |  Tab   |  F11   |  F12   |        |        |        |        | Print  | Scroll | Pause  |  Caps  |  Tab   |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | Shift  |        |        |        |        |        |        |  Left  |  Down  |   Up   | Right  | Shift  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |  Win   |  Alt   |        | 無変換 |      Space      | User2  |        |  Alt   |  Win   |  Ctrl  |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_USER2] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
    KC_TAB,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, KC_CAPS, KC_TAB,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RSFT,
    _______, _______, _______, XXXXXXX, KC_MHEN, _______, _______, _______, XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL
),

/* User3
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Esc   |        |        | Reset  |        |        |        |        |        | Whl Up |        |  Acc0  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        | Whl Dn |        |  Acc1  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | Shift  |        |        |        |        |        |        |        |  Btn1  |  M Up  |  Btn2  |  Acc2  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |  Win   |  Alt   | User3  |        |      Space      |        | M Left | M Down |M Right |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_USER3] = LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, KC_ACL0,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, KC_ACL1,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, KC_ACL2,
    _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX
),

/* User4
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Esc   |        |        |        |        |        |        |        |        |        |        | User4  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |  Tab   |   ;    |   -    |   :    |   ^    |   \_   |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | Shift  |   [    |   ]    |   |    |   `    |        |        |        |        |        |        | Enter  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |  Win   |  Alt   |        |        |      Space      |        |        |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_USER4] = LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    KC_TAB,  KC_SCLN, KC_MINS, KC_QUOT, KC_EQL,  KC_RO,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_RBRC, KC_NUHS, KC_JYEN, KC_LBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* User5
 * ,-----------------------------------------------------------------------------------------------------------.
 * |  Esc   |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |  F10   |  Bksp  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | User5  |  F11   |  F12   |        |全角半角|        |        |  Home  |  End   | Enter  |  Bksp  |        |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * | Shift  |        |        |        |        |        |  Del   |  Bksp  |        |        |        | Enter  |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |  Ctrl  |  Win   |  Alt   |        |        |      Space      |        |  Alt   |  Win   |  Menu  |  Ctrl  |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_USER5] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
    _______, KC_F11,  KC_F12,  XXXXXXX, KC_GRV,  XXXXXXX, XXXXXXX, KC_HOME, KC_END,  KC_ENT,  KC_BSPC, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_RALT, KC_RGUI, KC_APP,  KC_RCTL
),

/* Adjust (User1 + User2) … なくても良い気がする
 * ,-----------------------------------------------------------------------------------------------------------.
 * |        | Reset  |        |        |        |        |        |        |        |        |        |  Del   |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        |        |        | Aud on | Audoff | AGnorm | AGswap |Default |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        | Voice- | Voice+ | Mus on | Musoff | MIDIon | MIDIof |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |                 |        |        |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DEFAULT, _______, _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF,_______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};


const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case _DEFAULT:
      if (record->event.pressed) {
        layer_on(_DEFAULT);
      } else {
        layer_off(_DEFAULT);
      }
      break;
    case _USER1:
      if (record->event.pressed) {
        layer_on(_USER1);
      } else {
        layer_off(_USER1);
      }
      break;
    case _USER2:
      if (record->event.pressed) {
        layer_on(_USER2);
      } else {
        layer_off(_USER2);
      }
      break;
    case _USER3:
      if (record->event.pressed) {
        layer_on(_USER3);
      } else {
        layer_off(_USER3);
      }
      break;
    case _USER4:
      if (record->event.pressed) {
        layer_on(_USER4);
      } else {
        layer_off(_USER4);
      }
      break;
    case _USER5:
      if (record->event.pressed) {
        layer_on(_USER5);
      } else {
        layer_off(_USER5);
      }
      break;
  }
  return MACRO_NONE;
};



