// This is the c configuration file for the keymap

#include QMK_KEYBOARD_H

enum layers{
    _BASE,
    _RAISE,
    _LOWER,
    _BLANK
};

#define SFT_ESC SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC ALT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)

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
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,               KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,               KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                 KC_LBRC, KC_RBRC,                                                KC_MINUS, KC_SCLN,
                                   KC_LSFT, KC_SPC,             KC_BSPC, KC_RSFT,
                                   KC_LCTL, KC_ESC,             KC_ENT,  KC_RCTL,
                                   KC_LGUI, KC_LALT,            KC_LALT, KC_RGUI
    ),

    [_LOWER] = LAYOUT(
        _______, _______, _______, _______, KC_LBRC,             KC_RBRC, KC_P7,   KC_P8,   KC_P9,   QK_BOOT,
        KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_LPRN,             KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_MINS,
        _______, _______, _______, _______, _______,             _______, KC_P1,   KC_P2,   KC_P3,   KC_EQL,
                 _______, KC_PSCR,                                                 _______, KC_P0,
                                   _______, _______,             _______, _______,
                                   _______, _______,             _______, _______,
                                   _______, _______,             _______, _______
    ),

    [_RAISE] = LAYOUT(
        QK_BOOT, _______, _______, _______, KC_LBRC,             KC_RBRC, _______, KC_NUM, KC_INS, KC_SCRL,
        KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_LPRN,             KC_RPRN, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,
        _______, _______, _______, _______, _______,             _______, _______, _______, _______, KC_VOLD,
                 _______, _______,                                                 KC_EQL,  KC_MUTE,
                                   _______, _______,             _______, _______,
                                   _______, _______,             _______, _______,
                                   _______, _______,             _______, _______
    ),

    [_BLANK] = LAYOUT(
        _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______,
                 _______, _______,                                                 _______, _______,
                                   _______, _______,             _______, _______,
                                   _______, _______,             _______, _______,
                                   _______, _______,             _______, _______
    )
};
//clang-format on
