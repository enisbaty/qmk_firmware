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

#include QMK_KEYBOARD_H

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
};

enum my_keycodes {
    RLI_TOG = SAFE_RANGE,
};

bool raiseLowerToggle = true;

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |XXXXXX|   1  |   2  |   3  |   4  |   5  |   6  |   7  |  8   |   9  |  0   |XXXXXX|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   -  |  =   |  [   |  ]   | PRSC | PGUP | HOME | INS  |XXXXXX|XXXXXX|  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol+ | Play |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    XXXXXXX, XXXXXXX, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX,
    _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PSCR, KC_PGUP, KC_HOME, KC_INS , XXXXXXX, XXXXXXX, KC_PIPE,
    _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, KC_MNXT, KC_VOLU, KC_MPLY, _______
),



/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   '  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | F13  |Raise |    Space    |Lower | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, KC_SLSH,
    KC_LCTL, KC_LGUI, KC_LALT, KC_F13,  RAISE,   KC_SPC,  KC_SPC,  LOWER,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  `   |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |RGBTOG|RLITOG|RGBVAD|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CAPSLK|  !   |  @   |  #   |  $   |  %   |  ^   |   &  |   *  |  (   |   )  | Ent  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  _   |  +   |  {   |  }   |PAUSE | PGDN | END  |XXXXXX|XXXXXX|XXXXXX|  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Vol- | Stop |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
    KC_GRV , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_TOG, RLI_TOG, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_CAPS, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_ENT ,
    _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PAUS, KC_PGDN, KC_END , XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,
    _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, KC_MPRV, KC_VOLD, KC_MSTP, _______
)

};

// Called post keyboard init on boot
void keyboard_post_init_user(void) {
    // Set RGB to full white
    //rgblight_sethsv(0,0,255);

    // Read RGB from EEPROM
    rgblight_reload_from_eeprom();
}

// Called for custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case RLI_TOG:
            if (record->event.pressed) {
                // Toggle raise/lower indicator bool
                raiseLowerToggle = !raiseLowerToggle;
                
                // Load LED state from eeprom
                rgblight_reload_from_eeprom();
            }
            return false; // Skip further processing
        default:
            return true; // Process all other keycodes normally
    }
}

// Called upon a layer change
layer_state_t layer_state_set_user(layer_state_t state) {
    // Load LED state from eeprom
    rgblight_reload_from_eeprom();

    // Switch on layers if raiseLowerToggle is true
    if(raiseLowerToggle) {
        switch (get_highest_layer(state)) {
            case _RAISE:
                // Set LED in front of RAISE to dim orange
                rgblight_setrgb_at(23,11,0,8);
                break;
            case _LOWER:
                // Set LED in front of LOWER to dim blue
                rgblight_setrgb_at(12,18,16,1);
                break;
       }
    }

    // Handle caps lock state
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        // Set LED in middle of board to green for caps lock
        rgblight_setrgb_at(0,255,0,6);
    }

    return state;
}

