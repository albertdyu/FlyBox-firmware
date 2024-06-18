#include "../../firmware.h"

/**
 * @brief Initialzie the PWM registers and connect them to their respective output pins
 */
void initLights(){
// Setup pins
  //ledcSetup(PWM_RED, PWM_FREQ, PWM_RESOLUTION);
  //ledcSetup(PWM_GREEN, PWM_FREQ, PWM_RESOLUTION);
  //ledcSetup(PWM_WHITE, PWM_FREQ, PWM_RESOLUTION);
  pinMode(IR_PIN, OUTPUT);

  ledcAttach(RED_PIN, PWM_FREQ, PWM_RESOLUTION);
  ledcAttach(GREEN_PIN, PWM_FREQ, PWM_RESOLUTION);
  ledcAttach(WHITE_PIN, PWM_FREQ, PWM_RESOLUTION);

  sleep(1);
  ledcWrite(PWM_RED, 0);
  ledcWrite(PWM_GREEN, 0);
  ledcWrite(PWM_WHITE, 0);
  digitalWrite(IR_PIN, LOW);
}