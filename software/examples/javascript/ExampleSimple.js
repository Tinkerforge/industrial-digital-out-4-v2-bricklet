var Tinkerforge = require('tinkerforge');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'XYZ'; // Change XYZ to the UID of your Industrial Digital Out 4 Bricklet 2.0

var ipcon = new Tinkerforge.IPConnection(); // Create IP connection
var ido4 = new Tinkerforge.BrickletIndustrialDigitalOut4V2(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function (error) {
        console.log('Error: ' + error);
    }
); // Connect to brickd
// Don't use device before ipcon is connected

ipcon.on(Tinkerforge.IPConnection.CALLBACK_CONNECTED,
    function (connectReason) {
        // Set channels alternating high/low 10 times with 100 ms delay
        for(var i = 0; i < 10; ++i) {
            setTimeout(function () {
                ido4.setValue([true, false, false, false]);
            }, 400 * i + 100);
            setTimeout(function () {
                ido4.setValue([false, true, false, false]);
            }, 400 * i + 200);
            setTimeout(function () {
                ido4.setValue([false, false, true, false]);
            }, 400 * i + 300);
            setTimeout(function () {
                ido4.setValue([false, false, false, true]);
            }, 400 * i + 400);
        }
    }
);

console.log('Press key to exit');
process.stdin.on('data',
    function (data) {
        ipcon.disconnect();
        process.exit(0);
    }
);
