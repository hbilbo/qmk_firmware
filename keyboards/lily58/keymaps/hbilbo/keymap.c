#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_number {
  _QWERTY = 0,
  _LOWER = 1,
  _RAISE = 2,
  _ADJUST = 3,
  _GAME = 4,
  _GAMEADJUST = 5,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Del  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | / Space /       \Enter \  |RAISE | ESC  |RCTRL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_DEL,
                        KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_ESC, KC_RCTL
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      | F11  | F12  |   -  |   _  |   /  |-------|    |-------|   |  |   [  |   ]  |   {  |   }  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | / Space /       \Enter \  |RAISE | ESC  |RCTRL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, ______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
   KC_GRV, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  _______, KC_F11,  KC_F12, KC_PMNS, KC_UNDS, KC_SLSH, _______, _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______,
                            _______, _______, _______, _______, _______,  _______, _______, _______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |Pl/Stp| Prev | Next |Vol - |Vol + | Mute |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   +  |   -  |   *  |   /  |   .  |-------.    ,-------| Left | Down |  Up  | Right| Home | End  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |   =  |-------|    |-------|  Ins |PrtScn| CAPS |PageDn|PageUp|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | / Space /       \Enter \  |RAISE | ESC  |RCTRL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  _______,  _______, _______, _______, _______, _______,                    KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE,
  _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______,  KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_PDOT,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,
  _______,  _______, _______, _______, _______, KC_EQL,  _______, _______,  KC_INS,  KC_PSCR, KC_CAPS, KC_PGDN, KC_PGUP, _______,
                              _______, _______, _______, _______, _______,  _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |Sleep | Wake |      |      |      |                    |      | Play |Vol - |Vol + | Mute |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|GTogg |BL Tog|BLStep|BL DN |BL UP |Breath|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | / Space /       \Enter \  |RAISE | ESC  |RCTRL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_SLEP, KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,   KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   TG(_GAME), BL_TOGG, BL_STEP, BL_DOWN, BL_UP, BL_BRTG,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),

/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   T  |   Q  |   W  |   E  |   R  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   G  |   A  |   S  |   D  |   F  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   B  |   Z  |   X  |   C  |   V  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Del  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt | GAdj | / Space /       \Enter \  |RAISE | ESC  |RCTRL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_GAME] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LSFT,  KC_G,   KC_A,    KC_S,    KC_D,    KC_F,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_B,   KC_Z,    KC_X,    KC_C,    KC_V,   KC_LBRC,  KC_RBRC,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_DEL,
                     KC_LGUI, KC_LALT, MO(_GAMEADJUST), KC_SPC, KC_ENT, MO(_RAISE), KC_ESC, KC_RCTL
),

/* GAMEADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |-------.    ,-------|GTogg |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   6  |   7  |   8  |   9  |   0  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | / Space /       \Enter \  |RAISE | ESC  |RCTRL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_GAMEADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                 TG(_GAME), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
