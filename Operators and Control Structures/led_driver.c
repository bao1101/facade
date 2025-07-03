#include "led_driver.h"
#include <stdlib.h>
#include <string.h> // for memset

static uint32_t* g_led_buffer = NULL;
static uint32_t g_num_pixels = 0;

int led_init(size_t num_pixels) {
    if (num_pixels == 0) {
        return -1; // Cannot initialize with 0 pixels
    }

    // Free any existing buffer before re-initializing
    if (g_led_buffer != NULL) {
        free(g_led_buffer);
        g_led_buffer = NULL;
        g_num_pixels = 0;
    }

    g_led_buffer = (uint32_t*)calloc(num_pixels, sizeof(uint32_t));
    if (g_led_buffer == NULL) {
        return -1; // Memory allocation failed
    }

    g_num_pixels = num_pixels;
    // calloc already initializes memory to zero, so no need for explicit memset for black.
    return 0;
}

void led_shutdown() {
    if (g_led_buffer != NULL) {
        free(g_led_buffer);
        g_led_buffer = NULL;
        g_num_pixels = 0;
    }
}

void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b) {
    if (g_led_buffer == NULL || index >= g_num_pixels) {
        return; // Silently ignore invalid index or uninitialized buffer
    }

    // Format: 0x00_GG_RR_BB
    g_led_buffer[index] = ((uint32_t)g << 16) | ((uint32_t)r << 8) | (uint32_t)b;
}

void led_fill(uint8_t r, uint8_t g, uint8_t b) {
    if (g_led_buffer == NULL) {
        return; // Do nothing if buffer is not initialized
    }

    uint32_t color_value = ((uint32_t)g << 16) | ((uint32_t)r << 8) | (uint32_t)b;

    for (size_t i = 0; i < g_num_pixels; ++i) {
        g_led_buffer[i] = color_value;
    }
}

void led_clear() {
    led_fill(0, 0, 0); // Fill with black (0,0,0)
}

const uint32_t* led_get_buffer() {
    return g_led_buffer;
}

size_t led_get_pixel_count() {
    return g_num_pixels;
}