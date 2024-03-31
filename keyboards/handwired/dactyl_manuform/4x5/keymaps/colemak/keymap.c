// This is the c configuration file for the keymap

#include QMK_KEYBOARD_H

enum layers{
    _ALPHAS,
    _RAISE,
    _LOWER,
    _BLANK
};

// Fillers to make layering more clear
#define ____ KC_TRNS

#define SFT_ESC SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC ALT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define SFT_DEL  SFT_T(KC_DEL)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* base (colemak dhm)
     * +----------------------------------+                             +----------------------------------+
     * |   q  |   w  |   f  |   p  |   b  |                             |   j  |   l  |   u  |   y  |   '  |
     * |------+------+------+------+------|                             |------+------+------+------+------|
     * |   a  |   r  |   s  |   t  |   g  |                             |   m  |   n  |   e  |   i  |   o  |
     * |------+------+------+------+------|                             |------+------+------+------+------|
     * |   z  |   x  |   c  |   d  |   v  |                             |   k  |   h  |   ,  |   .  |   /  |
     * +------+------+------+-------------+                             +-------------+------+------+------+
     *        |  [   |   ]  |                                                         |   -  |   ;  |
     *        +-------------+-------------+                             +-------------+-------------+
     *                      |Lshift|Space |                             |Bkspc |Rshift|
     *                      +-------------+                             +-------------+
     *                                    +-------------+ +-------------+
     *                                    | LCTL | Esc  | | Enter| RCTL |
     *                                    |------+------| |------+------|
     *                                    | LWin | LAlt | | RAlt | RWin |
     *                                    +-------------+ +-------------+
     */
    [_ALPHAS] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                 KC_LBRC, KC_RBRC,                                                                       KC_MINUS, KC_SCLN,
                                                  KC_TAB,  ALT_SPC,   CTL_BSPC, SFT_DEL,
                                                  SFT_ESC, KC_HOME,   KC_END,  KC_ENT,
                                                  RAISE,   KC_GRV,    KC_LGUI, LOWER
    ),

    /* Raise
     * ,----------------------------------,                             ,----------------------------------,
     * |      |      |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |      |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |      |      |                                                         | mbtn |mbtn2 |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */

    [_RAISE] = LAYOUT(
      ____, ____,  KC_MU, ____,  ____,                          KC_VOLU, ____,    KC_UP,   ____,     KC_PGUP,
      ____, KC_ML, KC_MD, KC_MR, ____,                          KC_MUTE, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,
      ____, ____,  ____,  ____,  ____,                          KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES,  KC_PIPE,
            ____,  ____,                                                          KC_MB1,  KC_MB2,
                                       ____, ____,  ____, ____,
                                       ____, ____,  ____, ____,
                                       ____, ____,  ____, ____
    ),

    /* Lower
     * ,----------------------------------,                             ,----------------------------------,
     * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  10  |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        | F11  | F12  |                                                         |  -   |  =   |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */

    [_LOWER] = LAYOUT(
      KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                            KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,
      KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                             KC_6,    KC_7,     KC_8,    KC_9,    KC_0,
      KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,
               KC_F11, KC_F12,                                                               ____,    ____,
                                                 ____, ____,  ____, ____,
                                                 ____, ____,  ____, ____,
                                                 ____, ____,  ____, ____
    )

};
//clang-format on
