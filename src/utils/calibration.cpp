#include "calibration.h"
#include "../../firmware.h"

// Global variable to store the calibrated intensity
int calibratedIntensity = 0;

int calibrateWhiteLight() {
    sensors_event_t event;
    int intensity = 0;  // Start with the lowest intensity
    int gainIndex = 0;  // Variable to store the gain setting index

    // Set the gain based on the desired lux value
    if (desiredLux <= 10) {
        tsl.setGain(TSL2591_GAIN_HIGH);
        gainIndex = 3;
    } else if (desiredLux <= 100) {
        tsl.setGain(TSL2591_GAIN_MED);
        gainIndex = 1;
    } else {
        tsl.setGain(TSL2591_GAIN_LOW);
        gainIndex = 0;
    }

    // Print the set gain for debugging
    Serial.print(F("Gain set to: "));
    Serial.println(gainIndex);

    delay(100);  // Wait for the gain to take effect

    // Increase intensity from 0 to 100 in steps of 1
    for (int i = 0; i <= 400; i++) {
        ledcWrite(WHITE_PIN, (i * MAX_DUTY_CYCLE) / 400);
        delay(500);  // Additional delay for the light to stabilize

        // Get the sensor event
        tsl.getEvent(&event);

        // Print the current intensity and lux value
        Serial.print(F("Intensity: "));
        Serial.print(i);
        Serial.print(F(" -> Lux: "));
        Serial.println(event.light);

        if (event.light >= desiredLux) {  // Use the desired lux value from the JSON file
            calibratedIntensity = i;
            Serial.print(F("Calibrated intensity found: "));
            Serial.println(i);
            return i;
        }
    }
    return -1;  // Return -1 if calibration fails
}
