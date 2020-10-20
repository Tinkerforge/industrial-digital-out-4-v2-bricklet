#!/usr/bin/env python3
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "Hkp"

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_industrial_digital_out_4_v2 import BrickletIndustrialDigitalOut4V2

import time

def wiegand_string_to_bool_list(s):
    l = []
    for x in s:
        l.append(x == '1')
    
    return l

def cb_wiegand_done():
    print('CB DONE!')

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    ido = BrickletIndustrialDigitalOut4V2(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

#    ido.write_wiegand_data(wiegand_string_to_bool_list('11010101110010010010101100'))

    data = (True, True, False, True, False, True, False, True, True, True, False, False, True, False, False, True, False, False, True, False, True, False, True, True, False, False)

    ido.write_wiegand_data(data)
    ido.register_callback(ido.CALLBACK_WIEGAND_DONE, cb_wiegand_done)
    while True:
        time.sleep(0.01)
        state = ido.get_wiegand_state()
        print('Wiegand State: {0}'.format(state))
        if state == 0:
            break

    ipcon.disconnect()
