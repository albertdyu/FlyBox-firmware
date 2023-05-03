#include "../../firmware.h"

extern Time* currentFlyTime;

/**
 * @brief Display the current time on the box and update time if time adjustment buttons are pressed
 * 
 * @param time A Time* object containing day, hour, and minute
 */
void printIntro(){
    writeLCD("FLYBOX",0,0);
    writeLCD("Click knob to start", 0, 2);
    for(;;){
      updateCurrentTime();
      dispTime(currentFlyTime, 15, 0);
      if (knobIsPressed()){
        clearLCD();
        updateCurrentTime();
        break;
      }
    }
}