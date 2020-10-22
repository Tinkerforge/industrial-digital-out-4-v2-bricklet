#define IPCON_EXPOSE_MILLISLEEP

#include <stdio.h>

#include "tinkerforge/ip_connection.h"
#include "tinkerforge/bricklet_industrial_digital_out_4_v2.h"

#define HOST "localhost"
#define PORT 4223
#define UID "Hkp"

void cb_wiegand_done(void *user_data) {
    (void)user_data; // avoid unused parameter warning

    printf("Done\n");
}

int main(void) {
    // Create IP connection
    IPConnection ipcon;
    ipcon_create(&ipcon);

    // Create device object
    IndustrialDigitalOut4V2 ido4;
    industrial_digital_out_4_v2_create(&ido4, UID, &ipcon);

    // Connect to brickd
    if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
        fprintf(stderr, "Could not connect\n");
        return 1;
    }
    // Don't use device before ipcon is connected

    industrial_digital_out_4_v2_register_callback(&ido4,
                                                  INDUSTRIAL_DIGITAL_OUT_4_V2_CALLBACK_WIEGAND_DONE,
                                                  (void (*)(void))cb_wiegand_done,
                                                  NULL);

    bool data[26] = {true, true, false, true, false, true, false, true, true, true, false, false, true, false, false, true, false, false, true, false, true, false, true, true, false, false };

    industrial_digital_out_4_v2_write_wiegand_data(&ido4, data, 26);

    while (true) {
        millisleep(20);

        uint8_t state;
        industrial_digital_out_4_v2_get_wiegand_state(&ido4, &state);
        
        printf("State %u\n", state);

        if (state == INDUSTRIAL_DIGITAL_OUT_4_V2_WIEGAND_STATE_IDLE) {
            break;
        }
    }

    industrial_digital_out_4_v2_destroy(&ido4);
    ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
    return 0;
}
