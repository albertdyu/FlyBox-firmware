#include "../../firmware.h"


/**
 * @brief Display the current time on the box and update time if time adjustment buttons are pressed
 * 
 * @param time A Time* object containing day, hour, and minute
 */
void printIntro(Time* time){
    writeLCD("FLYBOX",0,0);
    writeLCD("Click knob to start", 0, 2);
    for(;;){
      updateCurrentTime(time);
      dispTime(time, 15, 0);
      if (knobIsPressed()){
        clearLCD();
        updateCurrentTime(time);
        break;
      }
    }
}