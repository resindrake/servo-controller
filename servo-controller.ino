// Pin definitions (Temporary exmaple values)
const int Dout_servo_pin = 0;
const int Ain_controller_pin = 1;
const int Dout_USB_TX = 2;
const int Din_USB_RX = 3;
const int Dout_LED_pin = 4;

// Constants
const int agl_max = 0; //Deg
const int agl_min = 0; //Deg
const int agl_start = 0; //Deg
const int tickrate = 10; //ms
const int baud_rate = 9600;

// Variables
int controller_in;
int agl;
int new_agl;

void setup() {
	pinMode(Dout_servo_pin, OUTPUT);
	pinMode(Ain_controller_pin, INPUT);
	Serial.begin(baud_rate);
	agl = agl_start;
}

void loop() {
	// Get the controller input
	controller_in = analogRead(Ain_controller_pin);
	
	// Determine the current action (rotate left, right, or do nothing)
	if (controller_in > 350) { // High voltage
		new_agl = 1;
	} else if (controller_in > 150) { // Medium voltage
		new_agl = -1;
	} else { // Low voltage
		new_agl = 0;
	}

	// Set the new angle, with an upper/lower constraints
	agl = min(max(agl_min, agl+new_agl), agl_max);

	// Check if either constraint has been hit
	if (agl == agl_min || agl == agl_max) {
		// Turn on LED
		
	} else {
		// Turn off LED
		
	}

	delay(tickrate);
}
