import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletIndustrialDigitalOut4V2;

public class ExampleSimple {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;

	// Change XYZ to the UID of your Industrial Digital Out 4 Bricklet 2.0
	private static final String UID = "XYZ";

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletIndustrialDigitalOut4V2 ido4 =
		  new BrickletIndustrialDigitalOut4V2(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Set channels alternating high/low 10 times with 100 ms delay
		for(int i = 0; i < 10; i++) {
			Thread.sleep(100);
			ido4.setValue(new boolean[]{true, false, false, false});
			Thread.sleep(100);
			ido4.setValue(new boolean[]{false, true, false, false});
			Thread.sleep(100);
			ido4.setValue(new boolean[]{false, false, true, false});
			Thread.sleep(100);
			ido4.setValue(new boolean[]{false, false, false, true});
		}

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
