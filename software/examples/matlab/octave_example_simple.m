function octave_example_simple()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Industrial Digital Out 4 Bricklet 2.0

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    ido4 = javaObject("com.tinkerforge.BrickletIndustrialDigitalOut4V2", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Set channels alternating high/low 10 times with 100 ms delay
    for i = 0:9
        pause(0.1);
        ido4.setValue([true false false false]);
        pause(0.1);
        ido4.setValue([false true false false]);
        pause(0.1);
        ido4.setValue([false false true false]);
        pause(0.1);
        ido4.setValue([false false false true]);
    end

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end
