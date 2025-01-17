/*
Copyright 2020-2021 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H
#include "hardware_variants.h"

/* HARDWARE DEFINITION*/
/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 8
#define MATRIX_ROW_PINS { 10, 9, 24, 20 } // B4, E6, D7, D4 
#define MATRIX_COL_PINS { 43, 28, 3, 45, 2, 29, 26, 30 } // B6, B2, B3, B1, F7, F6, F5, F4

// NOTE ONLY A SINGLE ENCODER IS POSSIBLE.
#define ENCODER_PAD_A  13 // C6 
#define ENCODER_PAD_B  38 // B5
#define ENCODER_RESOLUTION 2 // This doesn't do anything.

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define BATTERY_TYPE BATT_LIPO
        #define VBAT_PIN  4
        #define VCC_PIN 12
#define VCC_POLARITY_ON 1

#define BACKLIGHT_PWM_ON 0
#define WS2812B_LED_PIN 6
	
#define WS2812B_LED_COUNT 10
#define WS2812B_LED_ON 1 

#define  STATUS_BLE_LED_PIN  19  //blue = 0.19
#define  STATUS_KB_LED_PIN 17  //red = 0.17

//  OLED DEFINITION
    #define I2C_SDA_PIN 15
    #define I2C_SCK_PIN 17
    #define DISPLAY_U8G2_CONSTRUCTOR U8G2_SSD1306_128X64_NONAME_F_HW_I2C // see https://github.com/olikraus/u8g2/wiki/u8g2setupcpp for reference

#endif /* HARDWARE_CONFIG_H */