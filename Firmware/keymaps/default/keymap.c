#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_3x3( 
        KC_1, KC_2, KC_3, 
        KC_4, KC_5, KC_6, 
        KC_7, KC_8, KC_9  
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

// Handle encoder switch manually
void matrix_scan_user(void) {
    // Read encoder switch pin (GP3)
    static bool encoder_switch_pressed_last = false;
    bool encoder_switch_pressed = !readPin(GP3); // Assuming active low
    
    if (encoder_switch_pressed && !encoder_switch_pressed_last) {
        // Switch pressed
        tap_code(KC_MUTE);
    }
    
    encoder_switch_pressed_last = encoder_switch_pressed;
}

void keyboard_post_init_user(void) {
    // Initialize encoder switch pin
    setPinInputHigh(GP3); // Set as input with pullup
}

// OLED Boilerplate Code
// This function is called periodically to update the OLED display.
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // Rotate for slave half 
    }
    return rotation;
}

bool oled_task_user(void) {
    oled_clear();

    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default"), false);
            break;
        // case 1:
        //     oled_write_P(PSTR("Layer 1"), false);
        //     break;
        default:
            oled_write_P(PSTR("Unknown"), false);
            break;
    }
    oled_write_P(PSTR("\n"), false); // New line

    // Print encoder status (example)
    // oled_write_P(PSTR("Encoder: "), false);
    // if (encoder_is_active(0)) { // Check if encoder 0 is active
    //     oled_write_P(PSTR("Active"), false);
    // } else {
    //     oled_write_P(PSTR("Idle"), false);
    // }
    // oled_write_P(PSTR("\n"), false);

    // Print key press count (example)
    // You would need to implement a counter in your keymap or process_record_user
    // static uint32_t key_press_count = 0;
    // oled_write_P(PSTR("Presses: "), false);
    // oled_write_uint(key_press_count);
    // oled_write_P(PSTR("\n"), false);

    // You can add more information here like:
    // - Current mode (e.g., Gaming mode, Typing mode)
    // - Custom text/logos
    // - WPM (Words Per Minute) if you implement it
    // - Battery status (if applicable)
    
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Add custom logic here if needed
    return true;
}
