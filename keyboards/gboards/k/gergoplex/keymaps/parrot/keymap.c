/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion
#define GAME 3 // gaming

/* Combomap
 *
 * ,-----------------------------.       ,--------------------------------.
 * |      |    ESC    |     |     |      |     |    ESC    |    BSLH      |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |      |   BSPC   ENT    |     |      |    LES   COLN  GRT    |        | 
 * |-----+-----+-----+--RMB+-LMB--+		   |--------------------------------|
 * |      |   MINS    |     |     |      |    QUO   UNDR   |     |        |
 * `------+-----+-----+------+----'		   `--------------------------------'
 *  .-------------------------.           .-----------------.   
 *  |        |       |        |           |        |    |   |
 *  '-------------------------'           '-----------------' 
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------.       ,--------------------------------.
 * |    Q |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |    P   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |CTRL/A|  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  | CTRL/; | 
 * |-----+-----+-----+-----+------+		   |--------------------------------|
 * |SHFT/Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  <  |  >  | SHFT/? |
 * `------+-----+-----+------+----'		   `--------------------------------'
 *  .-------------------------.           .-----------------.   
 *  |ESC/META|ENT/ALT|SPC(SYM)|           |SPC(NUM)|BSPC|TAB|
 *  '-------------------------'           '-----------------' 
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q, 		            KC_W, KC_E, KC_R,     KC_T,  KC_Y, KC_U, KC_I,    KC_O,    KC_P, 
    MT(MOD_LCTL,    KC_A),  KC_S, KC_D, KC_F,     KC_G,  KC_H, KC_J, KC_K,    KC_L,    MT(MOD_LCTL, KC_SCLN),
    MT(MOD_RSFT,    KC_Z),  KC_X, KC_C, KC_V,     KC_B,  KC_N, KC_M, KC_COMM, KC_DOT,  MT(MOD_RSFT, KC_SLSH),

 		MT(MOD_LALT, KC_DEL), KC_TAB, LT(SYMB, KC_BSPC),									// Left
		LT(NUMB, KC_SPC), KC_ENT, MT(MOD_RALT, KC_TAB)																// Right
    ),
/* Keymap 1: Symbols layer
 * ,-----------------------------.       ,--------------------------------.
 * |  !   |  @  |  {  |  }  |       |  `  |  ~  |     |     |    \   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |  #   |  $  |  (  |  )  | LMB |      |  +  |  -  |  /  |  *  |    '   | 
 * |-----+-----+-----+-----+------+		   |--------------------------------|
 * |  %   |  ^  |  [  |  ]  | RMB |      |  &  |  =  |  ,  |  .  |   -    |
 * `------+-----+-----+------+----'		   `--------------------------------'
 *  				.-----------------.           .------------------.   
 *  				|MMB |  ;  	|	 = 	|						|  =  |  ;  |  DEL |
 *  				'-----------------'           '------------------' 
 */
[SYMB] = LAYOUT_gergoplex(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC,  KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,     KC_7,    KC_8,     KC_9,    KC_0,
    KC_LSFT, KC_TILD, KC_LBRC, KC_LPRN, KC_GRV,    KC_PPLS,  KC_RPRN, KC_RBRC,  KC_EQL,  KC_RSFT,
                      KC_LGUI, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, CMB_TOG
    ),
/* Keymap 2: Pad/Function layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
 * |-----+-----+-----+-----+------|      |-------------------------------|
 * |  F1  | F2  | F3  | F4  |  F5 |      | LFT | DWN | UP  | RGT | VOLUP | 
 * |-----+-----+-----+-----+------+		   |-------------------------------|
 * |  F6  | F7  | F8  | F9  | F10 |      |MLFT | MDWN| MUP | MRGT| VOLDN |
 * `------+-----+-----+------+----'		   `-------------------------------'
 *  				.-----------------.           .-----------------.   
 *  				| F11 | F12|	  	|						|     | PLY | SKP |
 *  				'-----------------'           '-----------------' 
 */
[NUMB] = LAYOUT_gergoplex(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  		KC_F6,   KC_F7,   KC_F8,   KC_F9, 	KC_F10,
    KC_WH_L,  KC_WH_D,  KC_MS_U,  KC_WH_U,  KC_WH_R,   		KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
    KC_BTN2,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN3,  		KC_ACL2, KC_PGDN, KC_PGUP, KC_TAB,  KC_VOLD,
     						KC_F11, KC_F12, KC_BTN1,  	    KC_TRNS, KC_MPLY, TO(GAME)
    ),

[GAME] = LAYOUT_gergoplex(
    KC_ESC,  KC_Q, KC_W, KC_E, KC_R,       KC_T, KC_U, KC_I,    KC_O,    KC_P, 
    KC_TAB,  KC_A, KC_S, KC_D, KC_F,       KC_G, KC_J, KC_K,    KC_L,    MT(MOD_LCTL, KC_SCLN),
    KC_RSFT, KC_Z, KC_X, KC_C, KC_V,       KC_B, KC_M, KC_COMM, KC_DOT,  MT(MOD_RSFT, KC_SLSH),
 		KC_LALT, KC_SPC, KC_LCTL,            KC_SPACE, KC_ENT, TO(BASE)
    )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LCTL, KC_A):
            return 210;
        case MT(MOD_LCTL, KC_SCLN):
            return 210;
        default:
            return TAPPING_TERM;
    }
}
