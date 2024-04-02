// This is the c configuration file for the keymap

#include QMK_KEYBOARD_H

enum layers{
    _ALPHAS,
    _UPPER,
    _LOWER,
    _NAV
};

// Fillers to make layering more clear
#define ____ KC_TRNS

// #define RAISE MO(_RAISE)
// #define LOWER MO(_LOWER)
#define UP_SPC LT(_UPPER, KC_SPC)
#define LOW_BSP LT(_LOWER, KC_BSPC)
#define UP_ENT LT(_UPPER, KC_ENT)
#define SFT_ESC SFT_T(KC_ESC)
#define SFT_DEL SFT_T(KC_DEL)

#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC ALT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define NAV_TAB LT(_NAV, KC_TAB)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2
#define KC_MB3 KC_MS_BTN3
#define KC_MWD KC_MS_WH_DOWN
#define KC_MWU KC_MS_WH_UP
#define KC_MWL KC_MS_WH_LEFT
#define KC_MWR KC_MS_WH_RIGHT

// TODO: update layers comments

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* alphas (colemak dhm)
     * +----------------------------------+                             +----------------------------------+
     * |   q  |   w  |   f  |   p  |   b  |                             |   j  |   l  |   u  |   y  |   '  |
     * |------+------+------+------+------|                             |------+------+------+------+------|
     * |   a  |   r  |   s  |   t  |   g  |                             |   m  |   n  |   e  |   i  |   o  |
     * |------+------+------+------+------|                             |------+------+------+------+------|
     * |   z  |   x  |   c  |   d  |   v  |                             |   k  |   h  |   ,  |   .  |   /  |
     * +------+------+------+-------------+                             +-------------+------+------+------+
     *        |  [   |   ]  |                                                         |   -  |   ;  |
     *        +-------------+-------------+                             +-------------+-------------+
     *                      |Lshift|Upper |                             |Lower |Rshift|
     *                      |   +  |  +   |                             |  +   |  +   |
     *                      |  ESC |Space |                             |Bkspc |Delete|
     *                      +-------------+                             +-------------+
     *                                    +-------------+ +-------------+
     *                                    |      | Nav  | |Upper |      |
     *                                    | LCTL |  +   | |  +   | RCTL |
     *                                    |      | TAB  | |Enter |      |
     *                                    |------+------| |------+------|
     *                                    | LAlt | LWin | | LWin | LAlt |
     *                                    +-------------+ +-------------+
     */
    [_ALPHAS] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                      KC_J,    KC_L,    KC_U,     KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                      KC_M,    KC_N,    KC_E,     KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                      KC_K,    KC_H,    KC_COMM,  KC_DOT,  KC_SLSH,
                 KC_LBRC, KC_RBRC,                                                                       KC_MINUS, KC_EQL,
                                                  SFT_ESC, UP_SPC,     LOW_BSP, SFT_DEL,
                                                  KC_LCTL, NAV_TAB,    UP_ENT,  KC_RCTL,
                                                  KC_LALT, KC_LGUI,    KC_LGUI, KC_LALT
    ),

    /* Upper
     * ,----------------------------------,                             ,----------------------------------,
     * |   {  |  &   |  *   |  (   |  }   |                             |      |      | PgDn | PgUp |      |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   :  |  $   |  %   |  ^   |  +   |                             |   :  |      |      |      |      |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   ~  |  !   |  @   |  #   |  |   |                             |   ~  |  \   |  ?   |  |   |      |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |   (  |   )  |                                                         |  :   |      |
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

    [_UPPER] = LAYOUT(
      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                   ____,    ____,    KC_PGDN, KC_PGUP, ____,
      KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                   KC_COLN, ____,    ____,    ____,    ____,
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                   KC_TILD, KC_BSLS, KC_QUES, KC_PIPE, ____,
               KC_LPRN, KC_RPRN,                                                       ____,    ____,
                                              ____, ____,  ____, ____,
                                              ____, ____,  ____, ____,
                                              ____, ____,  ____, ____
    ),

    /* Lower
     * ,----------------------------------,                             ,----------------------------------,
     * |   [  |   7  |   8  |   9  |   ]  |                             |      |  F7  |  F8  |  F9  |  F10 |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   ;  |   4  |   5  |   6  |   =  |                             |  :   |  F4  |  F5  |  F6  |  F11 |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   `  |   1  |   2  |   3  |   \  |                             |  ~   |  F1  |  F2  |  F3  |  F12 |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |      |  0   |                                                         |      |      |
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
      KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                            ____,    KC_F7, KC_F8, KC_F9, KC_F10,
      KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                             KC_COLN, KC_F4, KC_F5, KC_F6, KC_F11,
      KC_GRV,  KC_1, KC_2, KC_3, KC_BSLS,                            KC_TILD, KC_F1, KC_F2, KC_F3, KC_F12,
               ____, KC_0,                                                           ____,  ____,
                                                 ____, ____,  ____, ____,
                                                 ____, ____,  ____, ____,
                                                 ____, ____,  ____, ____
    ),

    /* Navigation
     * ,----------------------------------,                             ,----------------------------------,
     * |      |      |  mup |      | VOL+ |                             | VOL+ |      | PgDn | PgUp |      |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |      | mleft| mdown|mright| MUTE |                             | left | down |  up  |right |      |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |      |      |      |      | VOL- |                             |mwleft| mbtn1| mbtn3| mbtn2|mwrigt|
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |      |      |                                                         | mwup |mwdown|
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
    [_NAV] = LAYOUT(
      ____, ____,    KC_MU,  ____,  KC_VOLU,                       ____,    ____,    KC_PGDN, KC_PGUP,  ____,
      ____, KC_ML,   KC_MD,  KC_MR, KC_MUTE,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, ____,
      ____, KC_HOME, KC_END, ____,  KC_VOLD,                       KC_MWL,  KC_MB1,  KC_MB3,  KC_MB2,   KC_MWR,
            ____,  ____,                                                          KC_MWD,  KC_MWU,
                                       ____, ____,  ____, ____,
                                       ____, ____,  ____, ____,
                                       ____, ____,  ____, ____
    )

};
//clang-format on
