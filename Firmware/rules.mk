# MCU and architecture
MCU = RP2040
ARCH = ARM

# Bootloader
BOOTLOADER = rp2040

# Build Options
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output support

# Encoder support
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

# Keyboard features
# Enable matrix and encoder support
# SRC += matrix.c
# SRC += encoder.c

# Enable OLED support
OLED_ENABLE = yes
OLED_DRIVER = ssd1306

# Enable console and debug output 
CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes
# DEBUG_ENABLE = yes # Uncomment for more verbose debugging

# Optional: Enable extra features if needed
# LTO_ENABLE = yes # Link Time Optimization for smaller firmware size
