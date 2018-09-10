<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletIndustrialDigitalOut4V2.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletIndustrialDigitalOut4V2;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Industrial Digital Out 4 Bricklet 2.0

$ipcon = new IPConnection(); // Create IP connection
$ido4 = new BrickletIndustrialDigitalOut4V2(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Set channels alternating high/low 10 times with 100 ms delay
for($i = 0; $i < 10; $i++) {
    usleep(100*1000);
    $ido4->setValue(array(TRUE, FALSE, FALSE, FALSE));
    usleep(100*1000);
    $ido4->setValue(array(FALSE, TRUE, FALSE, FALSE));
    usleep(100*1000);
    $ido4->setValue(array(FALSE, FALSE, TRUE, FALSE));
    usleep(100*1000);
    $ido4->setValue(array(FALSE, FALSE, FALSE, TRUE));
}

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
