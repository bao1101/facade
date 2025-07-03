#include <stdio.h>
#include "led_driver.h"

#define NUM_LEDS 10

int main() {
    printf("--- Starting LED Driver Test ---\n");

    // Scenario 1: Initialize and verify that buffer is set to zero
    printf("\nScenario 1: Initialize LED strip with %d pixels.\n", NUM_LEDS);
    if (led_init(NUM_LEDS) == 0) {
        printf("Initialization successful.\n");
        const uint32_t* buffer = led_get_buffer();
        size_t pixel_count = led_get_pixel_count();

        // Check if buffer was initialized to all zeros
        int all_zero = 1;
        for (size_t i = 0; i < pixel_count; ++i) {
            if (buffer[i] != 0x00000000) {
                all_zero = 0;
                break;
            }
        }
        if (all_zero) {
            printf("Buffer initialized to zero (black): PASSED\n");
        } else {
            printf("Buffer NOT initialized to zero: FAILED\n");
        }

        // Scenario 2: Set specific pixel colors
        printf("\nScenario 2: Set specific pixel colors.\n");
        led_set_pixel_color(0, 255, 0, 0);   // Pixel 0: Red
        led_set_pixel_color(9, 0, 0, 255);   // Pixel 9: Blue
        led_set_pixel_color(4, 255, 255, 255); // Pixel 4: White
        led_set_pixel_color(NUM_LEDS + 1, 100, 100, 100); // Test out-of-bounds index (should be ignored)

        // Print hex values of selected pixels to verify
        printf("Hex value of pixel 0: 0x%08X (Expected: 0x0000FF00 for Red)\n", buffer[0]);
        printf("Hex value of pixel 4: 0x%08X (Expected: 0x00FFFFFF for White)\n", buffer[4]);
        printf("Hex value of pixel 9: 0x%08X (Expected: 0x000000FF for Blue)\n", buffer[9]);

        // Check expected results
        if (buffer[0] == 0x0000FF00) printf("Pixel 0 (Red) test: PASSED\n"); else printf("Pixel 0 (Red) test: FAILED\n");
        if (buffer[9] == 0x000000FF) printf("Pixel 9 (Blue) test: PASSED\n"); else printf("Pixel 9 (Blue) test: FAILED\n");
        if (buffer[4] == 0x00FFFFFF) printf("Pixel 4 (White) test: PASSED\n"); else printf("Pixel 4 (White) test: FAILED\n");

        // Scenario 3: Use led_fill()
        printf("\nScenario 3: Use led_fill() to set all pixels to Green.\n");
        led_fill(0, 255, 0); // Fill with Green (0, 255, 0)

        // Verify all pixels are green
        int all_green = 1;
        for (size_t i = 0; i < pixel_count; ++i) {
            if (buffer[i] != 0x00FF0000) {
                all_green = 0;
                break;
            }
        }
        if (all_green) {
            printf("All pixels are Green (0x00FF0000): PASSED\n");
        } else {
            printf("Some pixels are not Green: FAILED\n");
            for (size_t i = 0; i < pixel_count; ++i) {
                printf("  Pixel %zu: 0x%08X\n", i, buffer[i]);
            }
        }

        // Scenario 4: Use led_clear()
        printf("\nScenario 4: Use led_clear() to turn off all pixels.\n");
        led_clear();

        // Verify buffer is reset to black
        int all_black_after_clear = 1;
        for (size_t i = 0; i < pixel_count; ++i) {
            if (buffer[i] != 0x00000000) {
                all_black_after_clear = 0;
                break;
            }
        }
        if (all_black_after_clear) {
            printf("All pixels are black after clear: PASSED\n");
        } else {
            printf("Some pixels are not black after clear: FAILED\n");
        }

        // Scenario 5: Release memory
        printf("\nScenario 5: Release memory.\n");
        led_shutdown();
        if (led_get_buffer() == NULL && led_get_pixel_count() == 0) {
            printf("Memory release successful: PASSED\n");
        } else {
            printf("Memory release FAILED\n");
        }

    } else {
        printf("Initialization failed. Check memory allocation.\n");
    }

    printf("\n--- LED Driver Test Completed ---\n");
    return 0;
}