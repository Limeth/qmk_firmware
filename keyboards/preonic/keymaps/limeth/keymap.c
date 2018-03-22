#include "preonic.h"
#include "action_layer.h"
#define XXXXXXX KC_NO

enum preonic_layers {
  _BASE,
  _NUMPAD,
  _GREEK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// TODO: Greek: https://unicode-table.com/en/0370/
#define UC_GK_A 0x391

enum unicode_greek {
    UC_GK_ALPHA = 0x391,
    UC_GK_BETA,
    UC_GK_GAMMA,
    UC_GK_DELTA,
    UC_GK_EPSILON,
    UC_GK_ZETA,
    UC_GK_ETA,
    UC_GK_THETA,
    UC_GK_IOTA,
    UC_GK_KAPPA,
    UC_GK_LAMBDA,
    UC_GK_MU,
    UC_GK_NU,
    UC_GK_XI,
    UC_GK_OMICRON,
    UC_GK_PI,
    UC_GK_RHO,
    // Skip one
    UC_GK_SIGMA = 0x3a3,
    UC_GK_TAU,
    UC_GK_UPSILON,
    UC_GK_PHI,
    UC_GK_CHI,
    UC_GK_PSI,
    UC_GK_OMEGA,

    // Lower-case alternatives
    UC_GK_ALT_THETA = 0x3d1,
    UC_GK_ALT_SIGMA = 0x3c2,
};

// TODO: Add math ops: https://unicode-table.com/en/#mathematical-operators

// Custom keycodes with custom behaviour, starting at SAFE_RANGE
enum preonic_keycodes {
    // Layers
    BASE = SAFE_RANGE,
    NUMPAD,
    GREEK,
    LOWER,
    RAISE,

    // Top row
    TR_1,
    TR_2,
    TR_3,
    TR_4,
    TR_5,
    TR_6,
    TR_7,
    TR_8,
    TR_9,
    TR_0,

    // Other
    LDR_LNG,
    LDR_ACC,
    COMMA,
    RI_SYMB,
    UP_SYMB,
    LE_SYMB,
    DO_SYMB,

    // Greek
    GK_ALPHA,
    GK_BETA,
    GK_GAMMA,
    GK_DELTA,
    GK_EPSILON,
    GK_ZETA,
    GK_ETA,
    // lowercase variants
    GK_THETA1,
    GK_THETA2,
    GK_IOTA,
    GK_KAPPA,
    GK_LAMBDA,
    GK_MU,
    GK_NU,
    GK_XI,
    GK_OMICRON,
    GK_PI,
    GK_RHO,
    // lowercase variants
    GK_SIGMA1,
    GK_SIGMA2,
    GK_TAU,
    GK_UPSILON,
    GK_PHI,
    GK_CHI,
    GK_PSI,
    GK_OMEGA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty (Czech layout)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | 1  ! | 2  @ | 3  # | 4  $ | 5  % | 6  ^ | 7  & | 8  * | 9  / | 0  \ | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  | q  Q | w  W | e  E | r  R | t  T | y  Y | u  U | i  I | o  O | p  P | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | a  A | s  S | d  D | f  F | g  G | h  H | j  J | k  K | l  L | ,    |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift| z  Z | x  X | c  C | v  V | b  B | n  N | m  M | ´  ° | ˇ  ¨ |  Up  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |NumPad|Greek | LGUI | LAlt |Lower |    Space    |Raise | RAlt | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = {
  {KC_ESC,  TR_1,  TR_2,    TR_3,    TR_4,    TR_5,    TR_6,    TR_7,    TR_8,    TR_9,    TR_0,    KC_BSPC},
  {KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL},
  {KC_LCTL, KC_A,  KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    COMMA,   KC_ENT},
  {KC_LSFT, KC_Y,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    LDR_LNG, LDR_ACC, KC_UP,   KC_RSFT},
  {NUMPAD,  GREEK, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT}
},

/* NumPad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      | NLCK | /    | *    | -    |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | 7    | 8    | 9    | +    |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | 4    | 5    | 6    | =    |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | 1    | 2    | 3    | ,    |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    0        | .    |Enter |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = {
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, XXXXXXX, _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, XXXXXXX, XXXXXXX, _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PEQL, XXXXXXX, XXXXXXX, _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PCMM, XXXXXXX, XXXXXXX, _______},
  {_______, _______, _______, _______, XXXXXXX, KC_KP_0, KC_KP_0, KC_PDOT, KC_PENT, _______, _______, _______}
},

/* Greek
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Theta1|Omega |Epsiln| Rho  | Tau  | Psi  |Upsiln| Iota |Omicrn|  Pi  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Alpha |Sigma1|Delta | Phi  |Gamma | Eta  |Theta2|Kappa |Lambda|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Zeta |  Xi  | Chi  |Sigma2| Beta |  Nu  |  Mu  |      |      | ↑    |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | ←    | ↓    | →    |
 * `-----------------------------------------------------------------------------------'
 */
[_GREEK] = {
  {_______, XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,    XXXXXXX, _______},
  {_______, GK_THETA1, GK_OMEGA,  GK_EPSILON, GK_RHO,    GK_TAU,   GK_PSI,  GK_UPSILON, GK_IOTA,  GK_OMICRON, XXXXXXX, _______},
  {_______, GK_ALPHA,  GK_SIGMA1, GK_DELTA,   GK_PHI,    GK_GAMMA, GK_ETA,  GK_THETA2,  GK_KAPPA, GK_LAMBDA,  XXXXXXX, _______},
  {_______, GK_ZETA,   GK_XI,     GK_CHI,     GK_SIGMA2, GK_BETA,  GK_NU,   GK_MU,      XXXXXXX,  XXXXXXX,    UP_SYMB, _______},
  {_______, _______,   _______,   _______,    XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,    _______,  LE_SYMB,    DO_SYMB, RI_SYMB}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      | (    | )    |      |      |      |      |      |
 * |------+------+------+------+------+------+------+-------------+------+------+------|
 * |      |      |      |      |      | {    | }    |      |      | |    | ;    |      |
 * |------+------+------+------+------+------+------+-------------+------+------+------|
 * |      |      |      |      |      | [    | ]    |      |      | :    | .    |      |
 * |------+------+------+------+------+------+------+------|------+------+------+------|
 * |      |      |      |      |      | <    | >    |      |      | !    | ?    |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Vol- | Stop | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN,       KC_RPRN,      _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR,       KC_RCBR,      _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC,       KC_RBRC,      _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RALT(KC_COMM), RALT(KC_DOT), _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD,       KC_VOLU,      KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | ÷    | ×    |      |      |      |      |
 * |------+------+------+------+------+------+------+-------------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+-------------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------|------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol+ | Play | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Scale|Aud on|AudOff|AGnorm|AGswap| Base |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {XXXXXXX, RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TERM_ON, TERM_OFF,XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, BASE,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
}


};

/*
 * Thanks to fredizzimo for sharing:
 * https://github.com/fredizzimo/qmk_firmware/blob/18d83e5c98dd3a9dbf5a5e0f1579e86bee2d924f/layouts/community/ergodox/fredizzimo/keymap.c#L171-L198
 */
void press_key_with_level_mods(uint16_t key) {
    const uint8_t interesting_mods = MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT) | MOD_BIT(KC_RALT);

    // Save the state
    const uint8_t real_mods = get_mods();
    const uint8_t weak_mods = get_weak_mods();
    const uint8_t macro_mods = get_macro_mods();

    uint8_t target_mods = (key >> 8) & (QK_MODS_MAX >> 8);
    // The 5th bit indicates that it's a right hand mod,
    // which needs some fixup
    if (target_mods & 0x10) {
        target_mods &= 0xF;
        target_mods <<= 4;
    }

    // Clear the mods that we are potentially going to modify,
    del_mods(interesting_mods);
    del_weak_mods(interesting_mods);
    del_macro_mods(interesting_mods);

    // Enable the mods that we need
    add_mods(target_mods & interesting_mods);

    // Press and release the key
    register_code(key & 0xFF);
    unregister_code(key & 0xFF);

    // Restore the previous state
    set_mods(real_mods);
    set_weak_mods(weak_mods);
    set_macro_mods(macro_mods);
    send_keyboard_report();
}

bool override_key(keyrecord_t *record, uint16_t normal, uint16_t shifted) {
    const uint8_t shift = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT);
    // Todo, should maybe also check at least the weak mods
    uint8_t current_mods = get_mods();
    if (record->event.pressed) {
        // Todo share this code with send keyboard report
#ifndef NO_ACTION_ONESHOT
        if (get_oneshot_mods()) {
#if (defined(ONESHOT_TIMEOUT) && (ONESHOT_TIMEOUT > 0))
            if (has_oneshot_mods_timed_out()) {
                dprintf("Oneshot: timeout\n");
                clear_oneshot_mods();
            }
#endif
            current_mods |= get_oneshot_mods();
            clear_oneshot_mods();
        }
#endif
        bool shift_pressed = current_mods & shift;
        const uint16_t target = shift_pressed ? shifted : normal;

        if (target > QK_UNICODE) {
            if (target == KC_NO) {
                return false;
            }
            process_unicode(target, record);
        } else {
            uint8_t keycode = target & 0xFF;
            if (keycode == KC_NO) {
                return false;
            }
            press_key_with_level_mods(target);
        }
    }
    return false;
}

bool us_key(keyrecord_t *record, uint16_t code) {
    return override_key(record, S(code), RALT(code));
}

bool greek(keyrecord_t *record, uint16_t code) {
    return override_key(record, UC((code + 0x20)), UC(code));
}

bool toggle_layer(keyrecord_t *record, uint8_t layer) {
    if (record->event.pressed) {
        layer_on(layer);

        if (layer == _LOWER || layer == _RAISE) {
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
    } else {
        layer_off(layer);

        if (layer == _LOWER || layer == _RAISE) {
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;

        case NUMPAD: return toggle_layer(record, _NUMPAD);
        case GREEK: return toggle_layer(record, _GREEK);
        case LOWER: return toggle_layer(record, _LOWER);
        case RAISE: return toggle_layer(record, _RAISE);

        case TR_1: return us_key(record, KC_1);
        case TR_2: return us_key(record, KC_2);
        case TR_3: return us_key(record, KC_3);
        case TR_4: return us_key(record, KC_4);
        case TR_5: return us_key(record, KC_5);
        case TR_6: return us_key(record, KC_6);
        case TR_7: return us_key(record, KC_7);
        case TR_8: return us_key(record, KC_8);
        case TR_9: return override_key(record, S(KC_9), KC_NO);
        case TR_0: return override_key(record, S(KC_0), KC_NO);

        case LDR_LNG: return override_key(record, KC_EQL, S(KC_GRV));
        case LDR_ACC: return override_key(record, S(KC_EQL), KC_BSLS);
        case COMMA:   return override_key(record, KC_COMM, KC_NO);
        case RI_SYMB: return override_key(record, RALT(KC_I), KC_NO);
        case UP_SYMB: return override_key(record, S(RALT(KC_U)), KC_NO);
        case LE_SYMB: return override_key(record, RALT(KC_Y), KC_NO);
        case DO_SYMB: return override_key(record, RALT(KC_U), KC_NO);

        case GK_ALPHA: return greek(record, UC_GK_ALPHA);
        case GK_BETA: return greek(record, UC_GK_BETA);
        case GK_GAMMA: return greek(record, UC_GK_GAMMA);
        case GK_DELTA: return greek(record, UC_GK_DELTA);
        case GK_EPSILON: return greek(record, UC_GK_EPSILON);
        case GK_ZETA: return greek(record, UC_GK_ZETA);
        case GK_ETA: return greek(record, UC_GK_ETA);
        case GK_THETA1: return greek(record, UC_GK_THETA);
        case GK_THETA2: return override_key(record, UC(UC_GK_ALT_THETA), UC(UC_GK_THETA));
        case GK_IOTA: return greek(record, UC_GK_IOTA);
        case GK_KAPPA: return greek(record, UC_GK_KAPPA);
        case GK_LAMBDA: return greek(record, UC_GK_LAMBDA);
        case GK_MU: return greek(record, UC_GK_MU);
        case GK_NU: return greek(record, UC_GK_NU);
        case GK_XI: return greek(record, UC_GK_XI);
        case GK_OMICRON: return greek(record, UC_GK_OMICRON);
        case GK_PI: return greek(record, UC_GK_PI);
        case GK_RHO: return greek(record, UC_GK_RHO);
        case GK_SIGMA1: return greek(record, UC_GK_SIGMA);
        case GK_SIGMA2: return override_key(record, UC(UC_GK_ALT_SIGMA), UC(UC_GK_SIGMA));
        case GK_TAU: return greek(record, UC_GK_TAU);
        case GK_UPSILON: return greek(record, UC_GK_UPSILON);
        case GK_PHI: return greek(record, UC_GK_PHI);
        case GK_CHI: return greek(record, UC_GK_CHI);
        case GK_PSI: return greek(record, UC_GK_PSI);
        case GK_OMEGA: return greek(record, UC_GK_OMEGA);
    }
    return true;
};

void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
}
