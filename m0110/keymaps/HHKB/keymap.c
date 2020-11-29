#include QMK_KEYBOARD_H

enum custom_layout {
    _WINKEY,
    _MACKEY,
    _FN,
    _WINALT
};

enum custom_keycodes {
  WINKEY = SAFE_RANGE,
  MACKEY
};

#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_WINKEY] = LAYOUT_hhkb(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSLS, KC_GRV,
		KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_LBRC,   KC_RBRC,  KC_BSPC,
		KC_LCTL,           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,         KC_ENT,
		KC_LSFT,                KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,  KC_SLSH, KC_RSFT,  MO(_FN),
		            KC_LGUI,  KC_LALT,                              KC_SPC,                              KC_RALT,  KC_RGUI
	),

	[_MACKEY] = LAYOUT_hhkb(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSLS, KC_GRV,
		KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_LBRC,   KC_RBRC,  KC_BSPC,
		KC_LCTL,           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,         KC_ENT,
		KC_LSFT,                KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,  KC_SLSH, KC_RSFT,  MO(_FN),
		            KC_LALT,  KC_LGUI,                              KC_SPC,                              KC_RGUI,  KC_RALT
	),

	[_FN] = LAYOUT_hhkb(
		______,  KC_F1,  KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
		KC_CAPS,  WINKEY,   MACKEY,   ______,  ______, ______, ______,  ______,  KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   ______, ______,
		______,    KC_VOLU,  KC_VOLD,  KC_MUTE, ______, ______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,       ______,
		______,      KC_MPRV,  KC_MPLY,  KC_MNXT, ______, ______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN,   KC_DOWN,  ______,   ______,
		          ______,   ______,            ______,                                             ______,   ______
	),

    [_WINALT] = LAYOUT_hhkb(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSLS, KC_GRV,
		KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_LBRC,   KC_RBRC,  KC_BSPC,
		KC_LCTL,           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,         KC_ENT,
		KC_LSFT,                KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,  KC_SLSH, KC_RSFT,  MO(_FN),
		            KC_LGUI,  KC_LALT,                              KC_RALT,                              KC_RALT,  KC_RGUI
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case WINKEY:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_WINKEY);
			}
			return false;
			break;
		case MACKEY:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_MACKEY);
			}
			return false;
			break;
	}

    return true;
};