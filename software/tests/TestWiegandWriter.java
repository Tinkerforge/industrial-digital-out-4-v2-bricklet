import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletIndustrialDigitalOut4V2;

public class TestWiegandWriter {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;
	private static final String UID = "Hkp";

	private static boolean[] wiegandStringToBooleanArray(String string) {
		boolean[] data = new boolean[string.length()];

		for (int i = 0; i < string.length(); ++i) {
			data[i] = string.charAt(i) == '1';
		}

		return data;
	}

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletIndustrialDigitalOut4V2 ido4 =
		  new BrickletIndustrialDigitalOut4V2(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		ido4.addWiegandDoneListener(new BrickletIndustrialDigitalOut4V2.WiegandDoneListener() {
			public void wiegandDone() {
				System.out.println("Done");
			}
		});

		boolean[] data = wiegandStringToBooleanArray("11010101110010010010101100");

		ido4.writeWiegandData(data);

		while (true) {
			Thread.sleep(20);

			int state = ido4.getWiegandState();

			System.out.println("State " + state);

			if (state == BrickletIndustrialDigitalOut4V2.WIEGAND_STATE_IDLE) {
				break;
			}
		}

		ipcon.disconnect();
	}
}
