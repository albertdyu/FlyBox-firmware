#include "../../firmware.h"

extern LiquidCrystal_I2C lcd;

void printStartMenu(Time* time){
    int select = 0;
    int IRState = -1;
    long originalPosition = getRotaryInfo();
    bool enterPressed = 0;
    for (;;) {
        writeLCD("Select Test      >", 2, 0);
        if (IRState == -1){
            writeLCD("Toggle IR - off", 2, 1);
            digitalWrite(IR_PIN, LOW);
        } else {
            writeLCD("Toggle IR - on ", 2, 1);
            digitalWrite(IR_PIN, HIGH);
        }
        writeLCD("Adjust Box Time  >", 2, 2);
        long newPosition = getRotaryInfo();
        bool up = (newPosition < originalPosition);
        bool down = (newPosition > originalPosition);
        originalPosition = newPosition;
        int enter = !digitalRead(SW);
    
        if (down){
            clearLCD();
            select ++;
            if (select > 2){
                select = 2;
                }
        }
        if (up){
            clearLCD();
            select --;
            if (select < 0){
                select = 0;
            }
        }
        writeLCD(">", 0, select);

        if (select == 1 && enterPressed == 0 && enter){
            IRState *= -1;
            enterPressed = 1;
        }
        if (!enter && enterPressed){
            enterPressed = 0;
        }
    
        if (select == 2 && enter){
            timeChange(time);
        }


        if (select == 0 && enter) {
            clearLCD();
            digitalWrite(IR_PIN, LOW);
            return;
        }

    }
}