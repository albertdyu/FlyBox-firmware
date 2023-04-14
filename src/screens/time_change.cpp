#include "../../firmware.h"

void timeChange(Time* time){
    clearLCD();
    delayMicroseconds(750);
    bool minuteButtonActivlyPressed = minuteButtonIsPressed();
    bool hourButtonActivlyPressed = hourButtonIsPressed();
    writeLCD("Adjust hour and min", 0, 1);
    writeLCD("using buttons on top", 0, 2);
    writeLCD("Press knob to save", 0, 3);
    for(;;){
        int enter = !digitalRead(SW);
        updateCurrentTime(time);
        dispTime(time, 8, 0);
        if (minuteButtonIsPressed() && (minuteButtonActivlyPressed == false)){
            addGlobalMinuteOffset();
            minuteButtonActivlyPressed = true;
        }
        if (!minuteButtonIsPressed() && (minuteButtonActivlyPressed == true)){
            minuteButtonActivlyPressed = false;
        }
        if (hourButtonIsPressed() && (hourButtonActivlyPressed == false)){
            addGlobalHourOffset();
            hourButtonActivlyPressed = true;
        }
        if (!hourButtonIsPressed() && (hourButtonActivlyPressed == true)){
            hourButtonActivlyPressed = false;
        }
        if (enter){
            clearLCD();
            delayMicroseconds(750);
            return;
        }
    }
}