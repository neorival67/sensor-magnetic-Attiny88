#include <avr/io.h>
#include <util/delay.h>

#define SENSOR_PIN PB0 // Analog pin for the magnetic sensor
#define LED_PIN PB1    // Digital pin for LED indicator

// Function to initialize ADC
void ADC_init() {
    // Set ADC reference voltage to AVcc
    ADMUX |= (1 << REFS0);
    // Set ADC prescaler to 128 (ADC clock frequency = F_CPU / 128)
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    // Enable ADC
    ADCSRA |= (1 << ADEN);
}

// Function to read ADC value from specified channel
uint16_t ADC_read(uint8_t channel) {
    // Set ADC channel
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
    // Start ADC conversion
    ADCSRA |= (1 << ADSC);
    // Wait for conversion to complete
    while (ADCSRA & (1 << ADSC));
    // Return ADC result
    return ADC;
}

int main(void) {
    // Initialize ADC
    ADC_init();

    // Set LED pin as output
    DDRB |= (1 << LED_PIN);

    // Main loop
    while (1) {
        // Read analog value from magnetic sensor
        uint16_t sensorValue = ADC_read(SENSOR_PIN);

        // Your threshold for detecting magnetic field
        uint16_t threshold = 512; // Example threshold

        // Compare sensor value with threshold
        if (sensorValue > threshold) {
            // Magnetic field detected, turn on LED
            PORTB |= (1 << LED_PIN);
        } else {
            // No magnetic field detected, turn off LED
            PORTB &= ~(1 << LED_PIN);
        }

        // Delay before next sensor reading
        _delay_ms(500); // Example delay: 500 milliseconds
    }

    return 0;
}
