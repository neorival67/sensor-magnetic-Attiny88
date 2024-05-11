# Magnetic Sensor Detector with ATTINY88

This program demonstrates how to read an analog magnetic sensor and control an LED indicator using an ATTINY88 microcontroller.

## Pin Connections

- **SENSOR_PIN**: PB0 (Analog pin for the magnetic sensor)
- **LED_PIN**: PB1 (Digital pin for LED indicator)

## Functions

### `ADC_init()`

This function initializes the Analog to Digital Converter (ADC) of the ATTINY88. It sets the reference voltage to AVcc (the same as the supply voltage), configures the ADC clock frequency, and enables the ADC.

### `ADC_read(uint8_t channel)`

This function reads an analog value from the specified ADC channel. It selects the ADC channel, starts the conversion, waits for the conversion to complete, and then returns the ADC result.

## Main Functionality

1. **Initialization**: The ADC is initialized using `ADC_init()`, and the LED pin is set as an output.
2. **Main Loop**:
   - The program continuously reads the analog value from the magnetic sensor using `ADC_read(SENSOR_PIN)`.
   - It compares the sensor value with a threshold to detect the presence of a magnetic field.
   - If the sensor value exceeds the threshold, the LED is turned on; otherwise, it is turned off.
   - There's a delay of 500 milliseconds before the next sensor reading to prevent rapid toggling of the LED.

## Adjustments

- **Threshold**: Adjust the threshold value according to the sensitivity of your sensor and environment.

