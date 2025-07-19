#pragma once

// Matrix configuration
// Columns: GPIO27, GPIO28, GPIO29
// Rows:    GPIO1, GPIO2, GPIO4

// Rotary Encoder configuration
// A: GPIO26
// B: GPIO0
// Switch (S1): GPIO3

// OLED configuration 
// SCL: GPIO7
// SDA: GPIO6

#define MATRIX_ROWS 3 
#define MATRIX_COLS 3 

#define MATRIX_ROW_PINS { GP1, GP2, GP4 }
#define MATRIX_COL_PINS { GP27, GP28, GP29 }


#define DIODE_DIRECTION COL2ROW


#define ENCODER_A_PINS { GP26 }
#define ENCODER_B_PINS { GP0 }
#define ENCODER_RESOLUTION 2 // hope it's correct, if not, change it to 4

#define ENCODER_HAS_SWITCH
#define ENCODER_SWITCH_PIN GP3 

#define OLED_DISPLAY_128X32 
#define OLED_DRIVER_SSD1306 // Common driver for many OLEDs

#define OLED_I2C_ADDR 0x3C // Or 0x3D

#define OLED_SDA_PIN GP6
#define OLED_SCL_PIN GP7

// Optional: OLED timeout to turn off the display after inactivity
// #define OLED_TIMEOUT 30000 // 30 seconds

// Optional: OLED brightness (0-255)
// #define OLED_BRIGHTNESS 128

// Optional: Enable debug features (useful for troubleshooting)
// #define DEBUG_MATRIX_SCAN
// #define DEBUG_ENCODERS
// #define DEBUG_OLED