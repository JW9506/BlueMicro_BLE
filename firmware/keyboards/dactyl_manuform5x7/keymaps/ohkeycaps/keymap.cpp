/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"


#if KEYBOARD_SIDE == MASTER
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
	    KC_1,  KC_2,    KC_3,    KC_4,    KC_5,    KC_6, KC_7,
        KC_7,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_8,
        KC_8,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_9,
        KC_9,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        KC_0,  KC_1,    KC_2,    KC_3,
                                          KC_4,    KC_5,
                                          KC_6,    KC_7,
                                          KC_8,    KC_9
    )};

void setupKeymap() {

   // no layers for master keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.

}

void process_user_macros(uint16_t macroid)
{

}

void process_user_layers(uint16_t layermask)
{

}
#endif


#if KEYBOARD_SIDE == LEFT

/* Qwerty
 * ,------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  | HOME |
 * |-----------------------------------------|------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  | END  |
 * |------+------+------+------+------+------|------|
 * | RAISE|   A  |   R  |   S  |   T  |   G  | =    |
 * |------+------+------+------+------+------|------'
 * | Ctrl |   Z  |   X  |   C  |   D  |   V  |
 * `------+------+------+------+------+------'
 * | DOWN | `   |    '  | LEFT  |
 * `------+----------------------------------.
 *                             |BS | LOWER  |
 *                             `-------------------------.
 *                                           |CTRL |SHIFT|
 *                                           ------------|
 *                                           | ATL| WIN  |
 *                                           ------------'
 */

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {
        KEYMAP(
	    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_END,
        L_RAISE, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,   KC_EQUAL,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,
        KC_DOWN, KC_GRAVE, KC_QUOTE, KC_LEFT,
                                            KC_BSPC, L_LOWER,
                                            KC_LSFT, KC_LGUI,
                                            KC_LCTL, KC_LALT
	)
    };


void setupKeymap() {


/* Lower
 * ,------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
 * |-----------------------------------------|------|
 * |      |      | PRINT| ESC  |      |      |      |
 * |------+------+------+------+------+------|------|
 * |      | GUI  | Alt  | Shift| Ctrl |      |      |
 * |------+------+------+------+------+------|------'
 * |      | Undo | Cut  | Copy | Paste|      |
 * `-----------------------------------------'
 * | UP   |      |      | DOWN |
 * `------+----------------------------------.
 *                             |      |      |
 *                             `---------------------------.
 *                                           |      |      |
 *                                           --------------|
 *                                           |      |      |
 *                                           --------------'
 */
    uint32_t lower[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,   KC_F6,   \
  _______,_______,KC_PSCR,KC_ESC ,_______,_______, _______, \
  _______,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______, _______, \
  KC_LSFT,KC_UND, KC_CUT, KC_CPY, KC_PST, _______, \
  KC_UP,_______,_______,KC_DOWN,                 \
                                  _______,_______, \
                                  _______,_______, \
                                  _______,_______  \
);

/* Raise
 * ,------------------------------------------------.
 * |   ~  |  F1   |  F2 |  F3  |  F4  |  F5  |  F6  |
 * |-----------------------------------------|------|
 * | Mute | Home | PgDn | ESC | End  |       |  (   |
 * |------+------+------+------+------+------|------|
 * | Vol+ | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|------'
 * | Vol- |      |      |      |      |      |
 * `-----------------------------------------'
 * |      |      |      |      |
 * `------+----------------------------------.
 *                             |      |      |
 *                             `---------------------------.
 *                                           |      |      |
 *                                           --------------|
 *                                           |      |      |
 *                                           --------------'
 */
    uint32_t raise[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  KC_TILD,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,   KC_F6,   \
  KC_MUTE,KC_HOME,KC_PGDN,KC_ESC, KC_END, _______, KC_LPRN, \
  KC_VOLU,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,_______, _______, \
  KC_VOLD,_______,_______,_______,_______,_______, \
  _______,_______,_______,_______,                 \
                                  _______,_______, \
                                  _______,_______, \
                                  _______,_______  \
);

/* Adjust
 * ,------------------------------------------------.
 * |Batt  |  M1  |  M2  |  M3  |  M4  |      |      |
 * |------+------+------+------+------+------|------|
 * |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------|
 * |      |      |Dvorak|Colmak|Qwerty|      |      |
 * |------+------+------+------+------+------|------'
 * |Board |      |      |      |      |      |
 * `-----------------------------------------'
 * |      |      |      |      |
 * `------+----------------------------------.
 *                             |      |      |
 *                             `---------------------------.
 *                                           |      |      |
 *                                           --------------|
 *                                           |      |      |
 *                                           --------------'
 */
    uint32_t adjust[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  PRINT_BATTERY,HOME_ADD,WORK_ADD,EMAIL_1,EMAIL_2,_______, _______, \
  _______, _______,_______,_______, _______, _______,      _______, \
  _______,_______,KM_DVORAK,KM_COLEMAK,KM_QWERTY,_______,  _______, \
  PRINT_INFO, _______,_______,_______, _______, _______, \
  _______,_______,_______,_______,                 \
                                    _______,_______, \
                                    _______,_______, \
                                    _______,_______  \
);

    /*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_LOWER, Method::PRESS, lower[row][col]);
            matrix[row][col].addActivation(_RAISE, Method::PRESS, raise[row][col]);
            matrix[row][col].addActivation(_ADJUST, Method::PRESS, adjust[row][col]);
        }
    }

}

void process_user_macros(uint16_t macroid)
{
uint32_t qwerty[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
	    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_LBRC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_LCBR,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        KC_CAPS, KC_LGUI, TAB_L,   TAB_R,
                                            L_LOWER, KC_SPC,
                                            KC_TAB,  KC_HOME,
                                            KC_BSPC, KC_GRAVE
	);

uint32_t colemak[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
	    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_END,
        KC_EQUAL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,   XXXXXXX,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,
        KC_LEFT, KC_GRAVE, KC_QUOTE, KC_RIGHT,
                                            KC_BSPC, KC_LSFT,
                                            KC_LCTL, KC_LALT,
                                            L_LOWER, KC_LGUI
	);

uint32_t dvorak[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
	    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,
        KC_TAB,  KC_QUOTE,KC_COMMA,KC_DOT,  KC_P,    KC_Y,   KC_LBRC,
        KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   KC_LCBR,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,
        KC_CAPS, KC_LGUI, TAB_L,   TAB_R,
                                            L_LOWER, KC_SPC,
                                            KC_TAB,  KC_HOME,
                                            KC_BSPC, KC_GRAVE
	);

 switch ((macroid))
 {
      case (KM_QWERTY):
        for (int row = 0; row < MATRIX_ROWS; ++row)
        {
            for (int col = 0; col < MATRIX_COLS; ++col)
            {
                matrix[row][col].addActivation(_QWERTY, Method::PRESS, qwerty[row][col]);
            }
        }
     break;
     case (KM_COLEMAK):
        for (int row = 0; row < MATRIX_ROWS; ++row)
        {
            for (int col = 0; col < MATRIX_COLS; ++col)
            {
                matrix[row][col].addActivation(_COLEMAK, Method::PRESS, colemak[row][col]);
            }
        }
     break;
     case (KM_DVORAK):
        for (int row = 0; row < MATRIX_ROWS; ++row)
        {
            for (int col = 0; col < MATRIX_COLS; ++col)
            {
                matrix[row][col].addActivation(_DVORAK, Method::PRESS, dvorak[row][col]);
            }
        }
     break;
     case HOME_ADD:
     addStringToQueue("123 Quiet Crescent");
     break;
     case WORK_ADD:
     addStringToQueue("123 Work Place");
      break;
     case EMAIL_1:
     addStringToQueue("Primary@Email");
      break;
     case EMAIL_2:
     addStringToQueue("Other@Email");
      break;
 }
}

void process_user_layers(uint16_t layermask)
{
    KeyScanner::process_for_tri_layers(_LOWER, _RAISE, _ADJUST);
}

#endif  // left



#if KEYBOARD_SIDE == RIGHT

/* Qwerty
 *         ,------------------------------------------------.
 *         | pgUp |   6  |   7  |   8  |   9  |   0  |      |
 *         |------------------------------------------------|
 *         |pgDown|   J  |   L  |   U  |   Y  |   ;  |  \   |
 *         |------+------+------+------+------+-------------|
 *         |  -   |   M  |   N  |   E  |   I  |   O  | LOWER|
 *         `------+------+------+------+------+------|------|
 *                |   K  |   H  |   ,  |   .  |   /  |SHIFT |
 *                `-----------------------------------------'
 *                              | RIGHT|  [ |   ]   | UP    |
 *                ,-----------------------------------------'
 *                | Enter| SPACE|
 *    ,-------------------------'
 *    |RAISE| CTRL|
 *    |-----------|
 *    | WIN |ALT  |
 *    `-----------'
 */

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {
    KEYMAP(
    KC_PGUP, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      _______,
    KC_PGDN, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCOLON, KC_BSLASH,
    KC_MINUS,KC_M,    KC_N,    KC_E,    KC_I,    KC_O,      L_LOWER,
             KC_K,    KC_H,    KC_COMMA,KC_DOT,  KC_SLSH,   KC_RSFT,
                               KC_RIGHT, KC_LBRC, KC_RBRC,  KC_UP,
            KC_ENT,  KC_SPC,
            KC_LGUI, KC_MINUS,
            KC_RALT, KC_RCTL
        )
    };



void setupKeymap() {


/* Lower
 *         ,------------------------------------------------.
 *         |  F7  |  F8  | F9   | F10  | F11 | F12  |  Del  |
 *         |------------------------------------------------|
 *         |      | PgUp | 7    | 8    | 9  | Del  |      |
 *         |------+------+------+------+------+-------------|
 *         |      | PgDn | 4    | 5    | 6   | BkSp |      |
 *         `------+------+------+------+------+------|------|
 *                |  Ins | 1    | 2    | 3    | 0     |      |
 *                `-----------------------------------------'
 *                              |      |      |      |      |
 *                ,-----------------------------------------'
 *                |      |      |
 *  ,---------------------------'
 *  |      |      |
 *  |-------------|
 *  |      |      |
 *  `-------------'
 */
    uint32_t lower[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
   KC_F7,   KC_F8,  KC_F9,KC_F10,KC_F11,KC_F12,  KC_DEL, \
   _______,KC_PGUP, KC_7, KC_8, KC_9,  KC_DEL,  _______,  \
   _______,KC_PGDN, KC_4, KC_5, KC_6, KC_BSPC, _______,  \
           KC_INS , KC_1, KC_2, KC_3,  KC_0, KC_RSFT,  \
                             _______, _______, _______, _______,  \
           _______, _______,                                      \
           _______, _______,                                      \
           _______, _______                                       \
);

/* Raise
 *         ,------------------------------------------------.
 *         |      |   ^  |   &  |  *   |   (  |   )  |  Del |
 *         |------------------------------------------------|
 *         |   )  | HOME |      |      | END  |   -  |   _  |
 *         |------+------+------+------+------+-------------|
 *         |      | LEFT | DOWN | UP   | RIGHT|   +  |   |  |
 *         `------+------+------+------+------+------|------|
 *                |     | =    | -    |      |      | SHIFT|
 *                `-----------------------------------------'
 *                              |      |  (   |  )   |      |
 *                ,-----------------------------------------'
 *                |      | SHIFT|
 *  ,---------------------------'
 *  |      |      |
 *  |-------------|
 *  |      |      |
 *  `-------------'
 */
    uint32_t raise[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  _______,KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,   \
  KC_RPRN,KC_HOME, _______,  _______,  KC_END,  KC_MINS, KC_UNDS,  \
  _______,KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT,  KC_PLUS, KC_PIPE,  \
          _______,KC_EQUAL, KC_MINUS, _______ , _______, KC_RSFT,  \
                            _______ , KC_LPRN,  KC_RPRN, _______,  \
          _______, KC_RSFT,                                      \
          _______, _______,                                      \
          _______, _______                                       \
);

/* Adjust
 *         ,------------------------------------------------.
 *         |      |      |      |      |      |      |Batt  |
 *         |------------------------------------------------|
 *         |      |      |      |      |      |      |      |
 *         |------+------+------+------+------+-------------|
 *         |      |      |Qwerty|Colmak|Dvorak|      |      |
 *         `------+------+------+------+------+------|------|
 *                |      |      |      |      |      |Board |
 *                `-----------------------------------------'
 *                              |      |      |      |      |
 *                ,-----------------------------------------'
 *                |      |      |
 *  ,---------------------------'
 *  |      |      |
 *  |-------------|
 *  |      |      |
 *  `-------------'
 */
    uint32_t adjust[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
    _______,_______, _______, _______, _______, _______,PRINT_BATTERY,  \
    _______,_______, _______, _______, _______, _______, _______,  \
    _______,_______,KM_QWERTY,KM_COLEMAK,KM_DVORAK,_______,_______,  \
            _______, _______, _______, _______, _______, PRINT_INFO,  \
                              _______, _______, _______, _______,     \
            _______, _______,                                      \
            _______, _______,                                      \
            _______, _______                                       \
);

    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_LOWER, Method::PRESS, lower[row][col]);
            matrix[row][col].addActivation(_RAISE, Method::PRESS, raise[row][col]);
            matrix[row][col].addActivation(_ADJUST, Method::PRESS, adjust[row][col]);
        }
    }

}

void process_user_macros(uint16_t macroid)
{

uint32_t qwerty[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,
    KC_RBRC,KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,
    KC_RCBR,KC_H,    KC_J,    KC_K,    KC_L,    KC_SCOLON,KC_QUOTE,
            KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_SLSH,  KC_LSFT,
                              KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT,
            KC_ENT,  L_RAISE,
            KC_END,  KC_DEL,
            KC_LCTL, KC_LALT
        );

uint32_t colemak[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_PGUP, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_DEL,
    KC_PGDN, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCOLON, KC_BSLASH,
    XXXXXXX, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,      KC_MINUS,
             KC_K,    KC_H,    KC_COMMA,KC_DOT,  KC_SLSH,   KC_RSFT,
                               KC_DOWN, KC_LBRC, KC_RBRC, KC_UP,
            KC_ENT,  KC_SPC,
            KC_RALT, KC_RCTL,
            KC_LGUI, L_RAISE
        );

uint32_t dvorak[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,
    KC_RBRC,KC_F,    KC_G,    KC_C,    KC_R,    KC_L,      KC_MINS,
    KC_RCBR,KC_D,    KC_H,    KC_T,    KC_N,    KC_S,      KC_RSFT,
            KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,      KC_BSLS,
                              KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT,
            KC_ENT,  L_RAISE,
            KC_END,  KC_DEL,
            KC_LCTL, KC_LALT
        );

 switch ((macroid))
 {
      case (KM_QWERTY):
        for (int row = 0; row < MATRIX_ROWS; ++row)
        {
            for (int col = 0; col < MATRIX_COLS; ++col)
            {
                matrix[row][col].addActivation(_QWERTY, Method::PRESS, qwerty[row][col]);
            }
        }
     break;
     case (KM_COLEMAK):
        for (int row = 0; row < MATRIX_ROWS; ++row)
        {
            for (int col = 0; col < MATRIX_COLS; ++col)
            {
                matrix[row][col].addActivation(_COLEMAK, Method::PRESS, colemak[row][col]);
            }
        }
     break;
     case (KM_DVORAK):
        for (int row = 0; row < MATRIX_ROWS; ++row)
        {
            for (int col = 0; col < MATRIX_COLS; ++col)
            {
                matrix[row][col].addActivation(_DVORAK, Method::PRESS, dvorak[row][col]);
            }
        }
     break;
 }
}


void process_user_layers(uint16_t layermask)
{
    KeyScanner::process_for_tri_layers(_LOWER, _RAISE, _ADJUST);
}

#endif
