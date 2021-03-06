#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define ARWF 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |GrvEsc|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | FN   |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * | Ctrl | Alt  |   \  | Caps |Numpad|                                  |   [  |   ]  |   '  |  Alt | Ctrl |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      | LGUI |PrntSc|  |Insert| RGUI |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      | Home |  | PgUp |      |      |
 *                               |Space |Delete|------|  |------|BckSpc| Space|
 *                               |      |      | End  |  | PgDn |      |      |
 *                               `--------------------'  `--------------------'
 */
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
          KC_GESC,   KC_1,     KC_2,     KC_3,     KC_4,      KC_5,
          KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,
          MO(ARWF),  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,
          KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,
          KC_LCTL,   KC_LALT,  KC_BSLS,  KC_CLCK,  TG(SYMB),
                                                                        KC_LGUI,  KC_PSCR,
                                                                                  KC_HOME,
                                                              KC_SPC,   KC_DEL,   KC_END,
        // right hand
                               KC_6,     KC_7,     KC_8,      KC_9,     KC_0,     KC_MINS,
                               KC_Y,     KC_U,     KC_I,      KC_O,     KC_P,     KC_PLUS,
                               KC_H,     KC_J,     KC_K,      KC_L,     KC_SCLN,  KC_ENT,
                               KC_N,     KC_M,     KC_COMM,   KC_DOT,   KC_SLSH,  KC_RSFT,
                                         KC_LBRC,  KC_RBRC,   KC_QUOT,  KC_RALT,  KC_RCTRL,
          KC_INS,    KC_RGUI,
          KC_PGUP,
          KC_PGDN,   KC_BSPC,  KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   {  |   }  |   |  |                    |      |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   #  |   $  |   (  |   )  |   `  |                    |      |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   %  |   ^  |   [  |   ]  |   ~  |                    |      |   1  |   2  |   3  |   \  |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      |      |   &  |      |      |                                  |      |   .  |   0  |   =  |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      | RESET|  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |------|  |------|      |      |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
      KC_TRNS,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,
      KC_TRNS,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,
      KC_TRNS,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,
      KC_TRNS,  KC_TRNS,  KC_AMPR,  KC_TRNS,  KC_TRNS,
                                                        KC_TRNS,  RESET,
                                                                  KC_TRNS,
                                              KC_TRNS,  KC_TRNS,  KC_TRNS,
       // right hand
                KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                KC_TRNS,  KC_7,     KC_8,     KC_9,     KC_ASTR,  KC_TRNS,
                KC_TRNS,  KC_4,     KC_5,     KC_6,     KC_PLUS,  KC_TRNS,
                KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_BSLS,  KC_TRNS,
                          KC_TRNS,  KC_DOT,   KC_0,     KC_EQL,   KC_TRNS,
      KC_TRNS,  KC_TRNS,
      KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS
),
/* Keymap 2: Arrow keys and and F keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |  Up  |      |  [   |   ]  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      | Left | Down | Right|      |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      |      |      |      |      |                                  |      |      |      |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |------|  |------|      |Enter |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 *
 */
// Arrow Keys and F keys
[ARWF] = LAYOUT_ergodox(
      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                        KC_TRNS,  KC_TRNS,
                                                                  KC_TRNS,
                                              KC_TRNS,  KC_TRNS,  KC_TRNS,
    // right hand
                KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,  KC_TRNS,
                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,
      KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_ENT
),
};
