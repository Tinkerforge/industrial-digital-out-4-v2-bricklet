#!/usr/bin/env python3
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "Hkp"

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_industrial_digital_out_4_v2 import BrickletIndustrialDigitalOut4V2

import time

def wiegand_string_to_bool_list(string):
    return [bit == '1' for bit in string]

def cb_wiegand_done():
    print('Done')

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    ido = BrickletIndustrialDigitalOut4V2(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    ido.register_callback(ido.CALLBACK_WIEGAND_DONE, cb_wiegand_done)

    data = wiegand_string_to_bool_list('11010101110010010010101100')

    ido.write_wiegand_data(data)

    while True:
        time.sleep(0.02)
        state = ido.get_wiegand_state()

        print('State {0}'.format(state))

        if state == BrickletIndustrialDigitalOut4V2.WIEGAND_STATE_IDLE:
            break

    ipcon.disconnect()
