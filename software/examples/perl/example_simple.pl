#!/usr/bin/perl

use strict;
use Tinkerforge::IPConnection;
use Tinkerforge::BrickletIndustrialDigitalOut4V2;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Industrial Digital Out 4 Bricklet 2.0

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $ido4 = Tinkerforge::BrickletIndustrialDigitalOut4V2->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Set channels alternating high/low 10 times with 100 ms delay
for (my $i = 0; $i < 10; $i++)
{
    select(undef, undef, undef, 0.1);
    $ido4->set_value([1, 0, 0, 0]);
    select(undef, undef, undef, 0.1);
    $ido4->set_value([0, 1, 0, 0]);
    select(undef, undef, undef, 0.1);
    $ido4->set_value([0, 0, 1, 0]);
    select(undef, undef, undef, 0.1);
    $ido4->set_value([0, 0, 0, 1]);
}

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
