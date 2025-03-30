#include "luna.c"

static void print_status_narrow(void) {
    bool invert = false;
    oled_write_P(PSTR("\n\n"), invert);
    oled_write_ln_P(PSTR("Kiiro\n"), invert);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Base"), invert);
            break;
        case _CHARS:
            oled_write_ln_P(PSTR("Chars"), invert);
            break;
        case _EDIT:
            oled_write_ln_P(PSTR("Edit"), invert);
            break;
        case _TETRIS:
            oled_write_ln_P(PSTR("Tetr"), invert);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), invert);
    }

    oled_write_ln_P(led_usb_state.caps_lock ? PSTR("CpsLk") : PSTR(""), invert);

    render_luna(0, 13);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        // render_logo();
    }
    return false;
}
