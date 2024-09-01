#include QMK_KEYBOARD_H
#include "version.h"

#define ____ KC_TRANSPARENT
#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

bool sh_togg_enabled = false;
int sh_mon_held = 0;

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    SWAP_HANDS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    ____,           KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,                                ____,      KC_6,       KC_7,       KC_8,       KC_9,       KC_0,        ____,
    KC_TAB,         KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,       TG(3),                               TG(4),     KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,     ____,
    KC_LSFT,        KC_A,       KC_R,       KC_S,       KC_T,       KC_D,                                                       KC_H,       KC_N,       KC_E,       KC_I,       KC_O,        ____,
    KC_LCTL,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       ____,                                ____,      KC_K,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,    ____,
    KC_LALT,        SH_MON,     ____,   LGUI_T(KC_TAB), LALT_T(KC_DEL),                                                         LGUI_T(KC_TAB), LALT_T(KC_DEL),     ____,       SH_MON,      ____,
                                                                                  SH_MON, SH_TOGG, SH_TOGG, SH_MON,
                                                                                             ____, ____,
                                                           LT(2,KC_SPACE), LCTL_T(KC_ESCAPE),____, ____, LSFT_T(KC_ENTER),LT(1,KC_BSPC)
  ),
  [1] = LAYOUT_ergodox_pretty(
    ____,      KC_F1,      KC_F2,      KC_F3,     KC_F4,     KC_F5,     KC_F6,                                KC_F7,     KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,       ____,
    ____,      KC_6,       KC_4,       KC_2,      KC_0,      KC_8,      ____,                                 ____,      KC_9,           KC_1,           KC_3,           KC_5,           KC_7,         ____,
    ____,      KC_EXLM,    KC_HASH,    KC_QUOTE,  KC_PERC,   KC_PIPE,                                                    KC_PLUS,        KC_MINUS,       KC_DQUO,        KC_AMPR,        KC_EQUAL,     ____,
    ____,      KC_UNDS,    KC_AT,      KC_CIRC,   KC_TILD,   KC_NO,     ____,                                 ____,      KC_NO,          KC_ASTR,        KC_DLR,         KC_GRAVE,       KC_BSLS,      ____,
    ____,      ____,       ____,       ____,      ____,                                                                                 ____,            ____,           ____,           ____,         ____,
                                                                                             ____, ____, ____, ____,
                                                                                                   ____, ____,
                                                                            KC_LPRN,    KC_RPRN,   ____, ____, ____, ____
  ),
  [2] = LAYOUT_ergodox_pretty(
    ____,      ____,        ____,         ____,           ____,                ____,                 ____,                                 ____,              ____,         ____,           ____,          ____,           ____,           ____,
    ____,      ____,        KC_LCBR,      KC_LBRC,        KC_LABK,             ____,                 ____,                                 ____,              ____,         KC_RABK,        KC_RBRC,       KC_RCBR,        ____,           ____,
    ____,      KC_MS_LEFT,  KC_MS_DOWN,   KC_MS_UP,       KC_MS_RIGHT,          KC_WWW_BACK,                                                               KC_WWW_FORWARD,  KC_LEFT,       KC_DOWN,        KC_UP,          KC_RIGHT,       ____,
    ____,      LCTL_T       (KC_HOME),    LSFT_T(KC_END), LCTL_T(KC_PGDN),     LSFT_T(KC_PGUP),      ____, ____,                           ____,              ____,         KC_MS_WH_DOWN,  KC_MS_WH_UP,   KC_MS_ACCEL2,   KC_MS_ACCEL0,   ____,
    ____,      ____,        ____,         ____,           ____,                                                                                               KC_MS_BTN3,   ____,           ____,          ____,           ____,
                                                                                            ____, ____, ____, ____,
                                                                                                  ____, ____,
                                                                                      ____, ____, ____, ____, KC_MS_BTN2,     KC_MS_BTN1
  ),
  [3] = LAYOUT_ergodox_pretty(
    ____,      ____,           ____,           ____,           ____,           ____,           ____,                                 ____,       ____,       ____,       ____,          ____,            ____,           ____,
    ____,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           ____,                                 ____,       KC_Y,       KC_U,       KC_I,           KC_O,           KC_P,           ____,
    ____,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                             KC_H,       KC_J,       KC_K,           KC_L,           KC_SCLN,        ____,
    ____,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_Y,                                 ____,       KC_N,       KC_M,       KC_COMMA,       KC_DOT,         KC_SLASH,       ____,
    ____,      KC_H,           KC_J,           KC_K,           KC_ESCAPE,                                                                                    ____,       ____,           ____,           ____,           ____,
                                                                                  KC_U,        KC_I,     ____, ____,
                                                                                               KC_O,     ____,
                                                                     KC_SPACE,    KC_ENTER,    KC_P,     ____, ____, ____
  ),
  [4] = LAYOUT_ergodox_pretty(
    ____, ____, ____, ____, ____, ____, ____,                                                 ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, KC_D, KC_V, ____,                                                 ____, ____, KC_H, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, KC_P,                                                             KC_M, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, KC_G, ____, ____,                                                 ____, ____, KC_L, ____, ____, ____, ____,
    ____, ____, ____, ____, ____,                                                                         ____, ____, ____, ____, ____,
                                                        ____, ____, ____, ____,
                                                              ____, ____,
                                                  ____, ____, ____, ____, ____, ____
  ),
};

void handle_swap_hands(bool sh_togg_enabled, int sh_mon_held) {
    if ((sh_mon_held > 0) != sh_togg_enabled){
        swap_hands_on();
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
    } else {
        swap_hands_off();
        ergodox_right_led_1_off();
        ergodox_right_led_3_off();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            }
            break;
        case SH_MON:
            if (record->event.pressed) {
                sh_mon_held++;
            } else {
                sh_mon_held--;
            }

            handle_swap_hands(sh_togg_enabled, sh_mon_held);

            return false;
        case SH_TOGG:
            if (record->event.pressed) {
                sh_togg_enabled = !sh_togg_enabled;
                handle_swap_hands(sh_togg_enabled, sh_mon_held);
            }
            return false;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_led_all_set(LED_BRIGHTNESS_LO);

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            handle_swap_hands(sh_togg_enabled, sh_mon_held);
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
