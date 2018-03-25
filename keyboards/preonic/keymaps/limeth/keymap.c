#include "preonic.h"
#include "action_layer.h"
#include "wait.h"

#define XXXXXXX KC_NO

enum preonic_layers {
  _BASE,
  _GAME,
  _NUMPAD,
  _NUMPAD_LOWER,
  _NUMPAD_RAISE,
  _GREEK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SYSTEM,
};

// Custom keycodes with custom behaviour, starting at SAFE_RANGE
enum preonic_keycodes {
    // Layers
    BASE = SAFE_RANGE,
    GAME,
    NUMPAD,
    KP_LOWR,
    KP_RAIS,
    GREEK,
    LOWER,
    RAISE,
    SYSTEM,

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

    // Numpad
    KP_FORA,
    KP_EXST,
    KP_ELEM,
    KP_SUBS,
    KP_SUMM,
    KP_PROD,
    KP_SSUB,
    KP_ESBS,
    KP_CONJ,
    KP_DISJ,
    KP_NEGA,
    KP_SISC,
    KP_SUNI,
    KP_ELL1,
    KP_ELL2,

    KP_0,
    KP_1,
    KP_DIV,
    KP_MUL,
    KP_MINS,
    KP_PLUS,
    KP_EQLS,
    KP_DOT,

    KP_SNAT,
    KP_SINT,
    KP_SRAT,
    KP_SREA,
    KP_SCLX,
    KP_SQTN,

    // Numpad Lower
    KPL_0,
    KPL_1,
    KPL_2,
    KPL_3,
    KPL_4,
    KPL_5,
    KPL_6,
    KPL_7,
    KPL_8,
    KPL_9,
    KPL_ADD,
    KPL_SUB,
    KPL_EQS,
    KPL_LPA,
    KPL_RPA,
    KPL_VAR,

    // Numpad Raise
    KPR_0,
    KPR_1,
    KPR_2,
    KPR_3,
    KPR_4,
    KPR_5,
    KPR_6,
    KPR_7,
    KPR_8,
    KPR_9,
    KPR_ADD,
    KPR_SUB,
    KPR_EQS,
    KPR_LPA,
    KPR_RPA,
    KPR_VAR,

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

    // Lower
    LKC_CBE,
    LKC_ULC,
    LKC_LBU,
    LKC_LBM,
    LKC_LBL,
    LKC_RBU,
    LKC_RBM,
    LKC_RBL,

    LKC_LSB,
    LKC_RSB,
    LKC_LAB,
    LKC_RAB,

    LKC_END,
    LKC_EMD,
    LKC_DUN,
    LKC_UND,
    LKC_BTK,
    LKC_TLD,
    LKC_QOT,

    LKC_SEP,
    LKC_SCN,
    LKC_CLN,
    LKC_FSP,
    LKC_EXC,
    LKC_QSM,

    // Raise
    RKC_EUR,
    RKC_RTM,
    RKC_TDM,
    RKC_YEN,
    RKC_CPR,

    RKC_FQL,
    RKC_FQR,
    RKC_DQL,
    RKC_DQR,
    RKC_SQL,
    RKC_SQR,

    RKC_LRB,
    RKC_RRB,
    RKC_LCB,
    RKC_RCB,

    // System
    REISUB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty (Czech layout)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | 1  ! | 2  @ | 3  # | 4  $ | 5  % | 6  ^ | 7  & | 8  * | 9  / | 0  \ | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  | q  Q | w  W | e  E | r  R | t  T | y  Y | u  U | i  I | o  O | p  P | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | a  A | s  S | d  D | f  F | g  G | h  H | j  J | k  K | l  L | ,    |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift| z  Z | x  X | c  C | v  V | b  B | n  N | m  M | ´  ° | ˇ  ¨ |  Up  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |NumPad|Greek | LGUI | LAlt |Lower |    Space    |Raise | RAlt | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = {
  {KC_ESC,  TR_1,  TR_2,    TR_3,    TR_4,    TR_5,    TR_6,    TR_7,    TR_8,    TR_9,    TR_0,    KC_BSPC},
  {KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL},
  {KC_LCTL, KC_A,  KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    /*COMMA*/KC_COMM,   KC_ENT},
  {KC_LSFT, KC_Y,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    LDR_LNG, LDR_ACC, KC_UP,   KC_RSFT},
  {NUMPAD,  GREEK, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT}
},

/* Qwertz Game (Czech layout)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | +  1 | ě  2 | š  3 | č  4 | ř  5 | ž  6 | ý  7 | á  8 | í  9 | é  0 | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  | q  Q | w  W | e  E | r  R | t  T | y  Y | u  U | i  I | o  O | p  P | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | a  A | s  S | d  D | f  F | g  G | h  H | j  J | k  K | l  L | ,    |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift| z  Z | x  X | c  C | v  V | b  B | n  N | m  M | ´  ° | ˇ  ¨ |  Up  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |NumPad|Greek | LGUI | LAlt |Lower |    Space    |Raise | RAlt | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = {
  {KC_ESC,  KC_1,  KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL},
  {KC_LCTL, KC_A,  KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    COMMA,   KC_ENT},
  {KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    LDR_LNG, LDR_ACC, KC_UP,   KC_RSFT},
  {NUMPAD,  GREEK, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT}
},

/* NumPad
 * ,-----------------------------------------------------------------------------------.
 * |      | ∀  ⎲ | ∃  ∄ | ∈  ∉ | ⊂  ⊄ | NLCK | /  ÷ | *  × | -  ∓ | ℕ    | ℤ    |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | ∑  ⎳ | ∏  ∐ | ∖    | ⊆  ⊈ | 7    | 8    | 9    | +  ± | ℚ    | ℝ    |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | ∧    | ∨    | ¬    |      | 4    | 5    | 6    | =  ≠ | ℂ    | ℍ    |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | ∩    | ∪    | ⋯  ⋮ | ⋱  ⋰ | 1  ∞ | 2    | 3    | .  , |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |NPLowr| 0      ∅    |NPRais|Enter |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = {
  {_______, KP_FORA, KP_EXST, KP_ELEM, KP_SUBS, KC_NLCK, KP_DIV,  KP_MUL,  KP_MINS, KP_SNAT, KP_SINT, _______},
  {_______, KP_SUMM, KP_PROD, KP_SSUB, KP_ESBS, KC_KP_7, KC_KP_8, KC_KP_9, KP_PLUS, KP_SRAT, KP_SREA, _______},
  {_______, KP_CONJ, KP_DISJ, KP_NEGA, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KP_EQLS, KP_SCLX, KP_SQTN, _______},
  {_______, KP_SISC, KP_SUNI, KP_ELL1, KP_ELL2, KP_1,    KC_KP_2, KC_KP_3, KP_DOT,  XXXXXXX, XXXXXXX, _______},
  {_______, _______, _______, _______, KP_LOWR, KP_0,    KP_0,    KP_RAIS, KC_PENT, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* NumPad Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      | ₍    | ₎    | ₙ  ᵢ | ₋    |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | ₇    | ₈    | ₉    | ₊    |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | ₄    | ₅    | ₆    | ₌    |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | ₁    | ₂    | ₃    |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |NPLowr|    ₀        |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD_LOWER] = {
  {_______, _______, _______, _______, _______, KPL_LPA, KPL_RPA, KPL_VAR, KPL_SUB, _______, _______, _______},
  {_______, _______, _______, _______, _______, KPL_7,   KPL_8,   KPL_9,   KPL_ADD, _______, _______, _______},
  {_______, _______, _______, _______, _______, KPL_4,   KPL_5,   KPL_6,   KPL_EQS, _______, _______, _______},
  {_______, _______, _______, _______, _______, KPL_1,   KPL_2,   KPL_3,   _______, _______, _______, _______},
  {_______, _______, _______, _______, KP_LOWR, KPL_0,   KPL_0,   XXXXXXX, _______, _______, _______, _______}
},

/* NumPad Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      | ⁽    | ⁾    | ⁿ  ⁱ | ⁻    |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | ⁷    | ⁸    | ⁹    | ⁺    |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | ⁴    | ⁵    | ⁶    | ⁼    |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | ¹    | ²    | ³    |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    ⁰        |NPRais|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD_RAISE] = {
  {_______, _______, _______, _______, _______, KPR_LPA, KPR_RPA, KPR_VAR, KPR_SUB, _______, _______, _______},
  {_______, _______, _______, _______, _______, KPR_7,   KPR_8,   KPR_9,   KPR_ADD, _______, _______, _______},
  {_______, _______, _______, _______, _______, KPR_4,   KPR_5,   KPR_6,   KPR_EQS, _______, _______, _______},
  {_______, _______, _______, _______, _______, KPR_1,   KPR_2,   KPR_3,   _______, _______, _______, _______},
  {_______, _______, _______, _______, XXXXXXX, KPR_0,   KPR_0,   KP_RAIS, _______, _______, _______, _______}
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
 * |      |      |      |      |      | ⎪    | ⎰  ⎱ | en–  | em—  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | ⎧  ⎡ | ⎫  ⎤ | ‗    | _  ‾ | |  ‖ | ;    |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | [  ⟦ | ]  ⟧ | ⎨  ⎢ | ⎬  ⎥ | `    | ~  ≈ | :    | .  … |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | <  ⟨ | >  ⟩ | ⎩  ⎣ | ⎭  ⎦ |      | '  " | !  ‼ | ?  ⁇ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LKC_CBE, LKC_ULC, LKC_END, LKC_EMD, XXXXXXX, XXXXXXX, _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LKC_LBU, LKC_RBU, LKC_DUN, LKC_UND, LKC_SEP, LKC_SCN, _______},
  {_______, XXXXXXX, XXXXXXX, LKC_LSB, LKC_RSB, LKC_LBM, LKC_RBM, LKC_BTK, LKC_TLD, LKC_CLN, LKC_FSP, _______},
  {_______, XXXXXXX, XXXXXXX, LKC_LAB, LKC_RAB, LKC_LBL, LKC_RBL, XXXXXXX, LKC_QOT, LKC_EXC, LKC_QSM, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      | «  ‹ | »  › |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | €    | ®    | ™    | ¥    |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | „  ” | “    | (  ⟬ | )  ⟭ | £    |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | ©  ¢ |      | ‚  ’ | ‘    | {  ⟪ | }  ⟫ | Prev | Next | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Vol- | Vol+ | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RKC_FQL, RKC_FQR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {_______, XXXXXXX, XXXXXXX, RKC_EUR, RKC_RTM, RKC_TDM, RKC_YEN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RKC_DQL, RKC_DQR, RKC_LRB, RKC_RRB, XXXXXXX, XXXXXXX, _______},
  {_______, XXXXXXX, XXXXXXX, RKC_CPR, XXXXXXX, RKC_SQL, RKC_SQR, RKC_LCB, RKC_RCB, KC_MPRV, KC_MNXT, KC_MPLY},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      | Base |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Scale|Aud on|AudOff|AGnorm|AGswap|      |      |      |      | Game |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   System    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {XXXXXXX, RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TERM_ON, TERM_OFF,XXXXXXX, XXXXXXX, BASE},
  {XXXXXXX, XXXXXXX, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAME},
  {XXXXXXX, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, SYSTEM,  SYSTEM,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* System (Adjust + Spacebar)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |      |      |      |      |      |REISUB|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYSTEM] = {
  {RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  REISUB},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
}


};

/*
 * Thanks to fredizzimo for sharing:
 * https://github.com/fredizzimo/qmk_firmware/blob/18d83e5c98dd3a9dbf5a5e0f1579e86bee2d924f/layouts/community/ergodox/fredizzimo/keymap.c#L171-L198
 */
// TODO: Doesn't repeat held keys
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

bool no_shift(keyrecord_t *record, uint16_t code) {
    return override_key(record, code, KC_NO);
}

bool us_key(keyrecord_t *record, uint16_t code) {
    return override_key(record, S(code), RALT(code));
}

bool greek(keyrecord_t *record, uint16_t code) {
    return override_key(record, UC((code + 0x20)), UC(code));
}

void reisub_arming_act_upon(bool);

void system_layer_change_state(bool active) {
    if (active) {
        layer_on(_SYSTEM);
    } else {
        reisub_arming_act_upon(false);
        layer_off(_SYSTEM);
    }
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
            system_layer_change_state(false);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
    }
    return false;
}

#ifdef AUDIO_ENABLE
float default_layer_songs_local[][16][2] = DEFAULT_LAYER_SONGS;
#endif

bool set_default_layer_sound(keyrecord_t *record, uint8_t default_layer) {
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
        PLAY_SONG(default_layer_songs_local[default_layer]);
#endif
        default_layer_set(1U<<default_layer);
    }

    return false;
}

#define REP0(...)
#define REP1(...) __VA_ARGS__
#define REP2(...) REP1(__VA_ARGS__) __VA_ARGS__
#define REP3(...) REP2(__VA_ARGS__) __VA_ARGS__
#define REP4(...) REP3(__VA_ARGS__) __VA_ARGS__

#define REISUB_ARMING_MILLIS 3000
#define REISUB_ARMING_SOUND_PERIOD 250
#define REISUB_INITIATION_COMMAND_PERIOD 2000

#ifdef AUDIO_ENABLE
#define REISUB_TAP(k) \
    SEND_STRING(SS_TAP(k)); \
    PLAY_SONG(initiation_beep); \
    wait_ms(REISUB_INITIATION_COMMAND_PERIOD);
#define REISUB_TAP_FINAL(k) \
    SEND_STRING(SS_TAP(k)); \
    PLAY_SONG(initiation_beep_final);
#else
#define REISUB_TAP(k) \
    SEND_STRING(SS_TAP(k)); \
    wait_ms(REISUB_INITIATION_COMMAND_PERIOD);
#define REISUB_TAP_FINAL(k) \
    SEND_STRING(SS_TAP(k));
#endif

#ifdef AUDIO_ENABLE
static float arming_start[][2] = SONG(M__NOTE(_A3, 2), M__NOTE(_A4, 2), M__NOTE(_A5, 2), M__NOTE(_A6, 2));
static float arming_beep[][2] = SONG(M__NOTE(_A6, 4));
static float arming_cancel[][2] = SONG(M__NOTE(_A7, 8));
static float initiation_beep[][2] = SONG(REP4(M__NOTE(_A6, 2), M__NOTE(_A5, 2), M__NOTE(_A4, 2), M__NOTE(_A3, 2), ));
static float initiation_beep_final[][2] = SONG(REP4(M__NOTE(_A6, 2), M__NOTE(_A5, 2), M__NOTE(_A4, 2), M__NOTE(_A3, 2), )M__NOTE(_A3, 30));
#endif
static bool reisub_arming = false;
static uint16_t reisub_press_timer = 0;
static uint16_t reisub_arming_sounds_played;
static bool reisub_initiated = false;

void reisub_arming_act_upon(bool arming) {
    if (reisub_arming != arming) {
        if (arming) {
#ifdef AUDIO_ENABLE
            PLAY_SONG(arming_start);
#endif
            reisub_press_timer = timer_read();
            reisub_arming_sounds_played = 0;
        } else {
#ifdef AUDIO_ENABLE
            PLAY_SONG(arming_cancel);
#endif
        }

        reisub_arming = arming;
    }
}

bool reisub_press(keyrecord_t *record) {
    reisub_arming_act_upon(record->event.pressed);
    return false;
}

void reisub_initiate(void) {
    reisub_initiated = true;
    reisub_arming = false;

    SEND_STRING(SS_DOWN(X_LALT));
    SEND_STRING(SS_DOWN(X_PSCREEN));
    REISUB_TAP(X_R);
    REISUB_TAP(X_E);
    REISUB_TAP(X_I);
    REISUB_TAP(X_S);
    REISUB_TAP(X_U);
    REISUB_TAP_FINAL(X_B);
    SEND_STRING(SS_UP(X_PSCREEN));
    SEND_STRING(SS_UP(X_LALT));

    reisub_initiated = false;
}

void matrix_init_user() {
    set_unicode_input_mode(UC_LNX);
}

void matrix_scan_user() {
    if (reisub_arming) {
        uint16_t arming_duration = timer_elapsed(reisub_press_timer);

        if (arming_duration > REISUB_ARMING_MILLIS) {
            reisub_initiate();
            return;
        }

        uint16_t arming_sound_index = arming_duration / REISUB_ARMING_SOUND_PERIOD;

        if (arming_sound_index > reisub_arming_sounds_played) {
#ifdef AUDIO_ENABLE
            PLAY_SONG(arming_beep);
#endif
            reisub_arming_sounds_played = arming_sound_index;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (reisub_initiated) {
        return false;
    }

    switch (keycode) {
        case BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;

        case GAME: return set_default_layer_sound(record, _GAME);
        case NUMPAD: return toggle_layer(record, _NUMPAD);
        case KP_LOWR: return toggle_layer(record, _NUMPAD_LOWER);
        case KP_RAIS: return toggle_layer(record, _NUMPAD_RAISE);
        case GREEK: return toggle_layer(record, _GREEK);
        case LOWER: return toggle_layer(record, _LOWER);
        case RAISE: return toggle_layer(record, _RAISE);

        case SYSTEM:
            system_layer_change_state(record->event.pressed);
            return false;

        case TR_1: return us_key(record, KC_1);
        case TR_2: return us_key(record, KC_2);
        case TR_3: return us_key(record, KC_3);
        case TR_4: return us_key(record, KC_4);
        case TR_5: return us_key(record, KC_5);
        case TR_6: return us_key(record, KC_6);
        case TR_7: return us_key(record, KC_7);
        case TR_8: return us_key(record, KC_8);
        case TR_9: return override_key(record, S(KC_9), S(KC_LBRC));
        case TR_0: return override_key(record, S(KC_0), RALT(KC_BSLS));

        case LDR_LNG: return override_key(record, KC_EQL, S(KC_GRV));
        case LDR_ACC: return override_key(record, S(KC_EQL), KC_BSLS);
        case COMMA:   return override_key(record, KC_COMM, KC_NO);
        case RI_SYMB: return override_key(record, RALT(KC_I), KC_NO);
        case UP_SYMB: return override_key(record, S(RALT(KC_U)), KC_NO);
        case LE_SYMB: return override_key(record, RALT(KC_Y), KC_NO);
        case DO_SYMB: return override_key(record, RALT(KC_U), KC_NO);

        // Numpad
        case KP_FORA: return override_key(record, UC(0x2200), UC(0x23B2));
        case KP_EXST: return override_key(record, UC(0x2203), UC(0x2204));
        case KP_ELEM: return override_key(record, UC(0x2208), UC(0x2209));
        case KP_SUBS: return override_key(record, UC(0x2282), UC(0x2284));
        case KP_SUMM: return override_key(record, UC(0x2211), UC(0x23B3));
        case KP_PROD: return override_key(record, UC(0x220F), UC(0x2210));
        case KP_SSUB: return no_shift(record, UC(0x2216));
        case KP_ESBS: return override_key(record, UC(0x2286), UC(0x2288));
        case KP_CONJ: return no_shift(record, UC(0x2227));
        case KP_DISJ: return no_shift(record, UC(0x2228));
        case KP_NEGA: return no_shift(record, UC(0x00AC));
        case KP_SISC: return no_shift(record, UC(0x2229));
        case KP_SUNI: return no_shift(record, UC(0x222A));
        case KP_ELL1: return override_key(record, UC(0x22EF), UC(0x22EE));
        case KP_ELL2: return override_key(record, UC(0x22F1), UC(0x22F0));

        case KP_0: return override_key(record, KC_KP_0, UC(0x2205));
        case KP_1: return override_key(record, KC_KP_1, UC(0x221E));
        case KP_DIV: return override_key(record, KC_PSLS, S(RALT(KC_LBRC)));
        case KP_MUL: return override_key(record, KC_PAST, S(RALT(KC_RBRC)));
        case KP_MINS: return override_key(record, KC_PMNS, UC(0x2213));
        case KP_PLUS: return override_key(record, KC_PPLS, UC(0x00B1));
        case KP_EQLS: return override_key(record, KC_PEQL, UC(0x2260));
        case KP_DOT: return override_key(record, KC_PDOT, KC_COMM);

        case KP_SNAT: return no_shift(record, UC(0x2115));
        case KP_SINT: return no_shift(record, UC(0x2124));
        case KP_SRAT: return no_shift(record, UC(0x211A));
        case KP_SREA: return no_shift(record, UC(0x211D));
        case KP_SCLX: return no_shift(record, UC(0x2102));
        case KP_SQTN: return no_shift(record, UC(0x210D));

        case GK_ALPHA: return greek(record, 0x0391);
        case GK_BETA: return greek(record, 0x0392);
        case GK_GAMMA: return greek(record, 0x0393);
        case GK_DELTA: return greek(record, 0x0394);
        case GK_EPSILON: return greek(record, 0x0395);
        case GK_ZETA: return greek(record, 0x0396);
        case GK_ETA: return greek(record, 0x0397);
        case GK_THETA1: return greek(record, 0x0398);
        case GK_THETA2: return override_key(record, UC(0x03D1), UC(0x0398));
        case GK_IOTA: return greek(record, 0x0399);
        case GK_KAPPA: return greek(record, 0x039A);
        case GK_LAMBDA: return greek(record, 0x039B);
        case GK_MU: return greek(record, 0x039C);
        case GK_NU: return greek(record, 0x039D);
        case GK_XI: return greek(record, 0x039E);
        case GK_OMICRON: return greek(record, 0x039F);
        case GK_PI: return greek(record, 0x03A0);
        case GK_RHO: return greek(record, 0x03A1);
        case GK_SIGMA1: return greek(record, 0x03A3);
        case GK_SIGMA2: return override_key(record, UC(0x03C2), UC(0x03A3));
        case GK_TAU: return greek(record, 0x03A4);
        case GK_UPSILON: return greek(record, 0x03A5);
        case GK_PHI: return greek(record, 0x03A6);
        case GK_CHI: return greek(record, 0x03A7);
        case GK_PSI: return greek(record, 0x03A8);
        case GK_OMEGA: return greek(record, 0x03A9);

        // Numpad Lower
        case KPL_0: 
        case KPL_1:
        case KPL_2:
        case KPL_3:
        case KPL_4:
        case KPL_5:
        case KPL_6:
        case KPL_7:
        case KPL_8:
        case KPL_9:
        case KPL_ADD:
        case KPL_SUB:
        case KPL_EQS:
        case KPL_LPA:
        case KPL_RPA:
            return no_shift(record, UC((0x2080 + keycode - KPL_0)));
        case KPL_VAR: return override_key(record, UC(0x2099), UC(0x1D62));

        // Numpad Raise
        case KPR_0:
        case KPR_4:
        case KPR_5:
        case KPR_6:
        case KPR_7:
        case KPR_8:
        case KPR_9:
        case KPR_ADD:
        case KPR_SUB:
        case KPR_EQS:
        case KPR_LPA:
        case KPR_RPA:
            return no_shift(record, UC((0x2070 + keycode - KPR_0)));
        case KPR_1: return no_shift(record, UC(0x00B9));
        case KPR_2: return no_shift(record, UC(0x00B2));
        case KPR_3: return no_shift(record, UC(0x00B3));
        case KPR_VAR: return override_key(record, UC(0x207F), UC(0x2071));

        // Lower
        case LKC_CBE: return no_shift(record, UC(0x23AA));
        case LKC_ULC: return override_key(record, UC(0x23B0), UC(0x23B1));
        case LKC_LBU: return override_key(record, UC(0x23A7), UC(0x23A1));
        case LKC_LBM: return override_key(record, UC(0x23A8), UC(0x23A2));
        case LKC_LBL: return override_key(record, UC(0x23A9), UC(0x23A3));
        case LKC_RBU: return override_key(record, UC(0x23AB), UC(0x23A4));
        case LKC_RBM: return override_key(record, UC(0x23AC), UC(0x23A5));
        case LKC_RBL: return override_key(record, UC(0x23AD), UC(0x23A6));

        case LKC_LSB: return override_key(record, RALT(KC_LBRC), UC(0x27E6));
        case LKC_RSB: return override_key(record, RALT(KC_RBRC), UC(0x27E7));
        case LKC_LAB: return override_key(record, RALT(KC_COMM), UC(0x27E8));
        case LKC_RAB: return override_key(record, RALT(KC_DOT), UC(0x27E9));

        case LKC_END: return no_shift(record, UC(0x2013));
        case LKC_EMD: return no_shift(record, UC(0x2014));
        case LKC_DUN: return no_shift(record, UC(0x2017));
        case LKC_UND: return override_key(record, S(KC_SLSH), UC(0x203E));
        case LKC_BTK: return no_shift(record, RALT(KC_GRV));
        case LKC_TLD: return override_key(record, S(RALT(KC_GRV)), UC(0x2248));
        case LKC_QOT: return override_key(record, RALT(KC_QUOT), S(KC_SCLN));

        case LKC_SEP: return override_key(record, S(RALT(KC_BSLS)), UC(0x2016));
        case LKC_SCN: return no_shift(record, KC_GRV);
        case LKC_CLN: return no_shift(record, S(KC_DOT));
        case LKC_FSP: return override_key(record, KC_DOT, UC(0x2026));
        case LKC_EXC: return override_key(record, S(KC_QUOT), UC(0x203C));
        case LKC_QSM: return override_key(record, S(KC_COMM), UC(0x2047));

        // Raise
        case RKC_EUR: return no_shift(record, RALT(KC_E));
        case RKC_RTM: return no_shift(record, S(RALT(KC_R)));
        case RKC_TDM: return no_shift(record, UC(0x2122));
        case RKC_YEN: return no_shift(record, S(RALT(KC_Y)));
        case RKC_CPR: return no_shift(record, S(RALT(KC_C)));

        case RKC_FQL: return override_key(record, UC(0x00AB), UC(0x2039));
        case RKC_FQR: return override_key(record, UC(0x00BB), UC(0x203A));
        case RKC_DQL: return override_key(record, UC(0x201E), UC(0x201D));
        case RKC_DQR: return no_shift(record, UC(0x201C));
        case RKC_SQL: return override_key(record, UC(0x201A), UC(0x2019));
        case RKC_SQR: return no_shift(record, UC(0x2018));

        case RKC_LRB: return override_key(record, S(KC_RBRC), UC(0x27EC));
        case RKC_RRB: return override_key(record, KC_RBRC, UC(0x27ED));
        case RKC_LCB: return override_key(record, RALT(KC_9), UC(0x27EA));
        case RKC_RCB: return override_key(record, RALT(KC_0), UC(0x27EB));

        // System
        case REISUB: return reisub_press(record);
    }
    return true;
};
