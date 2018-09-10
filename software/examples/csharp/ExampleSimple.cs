using System;
using System.Threading;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change XYZ to the UID of your Industrial Digital Out 4 Bricklet 2.0

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletIndustrialDigitalOut4V2 ido4 =
		  new BrickletIndustrialDigitalOut4V2(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Set channels alternating high/low 10 times with 100 ms delay
		for(int i = 0; i < 10; i++)
		{
			Thread.Sleep(100);
			ido4.SetValue(new bool[]{true, false, false, false});
			Thread.Sleep(100);
			ido4.SetValue(new bool[]{false, true, false, false});
			Thread.Sleep(100);
			ido4.SetValue(new bool[]{false, false, true, false});
			Thread.Sleep(100);
			ido4.SetValue(new bool[]{false, false, false, true});
		}

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}
