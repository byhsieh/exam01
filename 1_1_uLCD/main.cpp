// uLCD-144-G2 basic text demo program for uLCD-4GL LCD driver library

//

#include "mbed.h"

#include "uLCD_4DGL.h"


uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;


int main()

{

    // basic printf demo = 16 by 18 characters on screen

    uLCD.background_color(0xFFFFFF);

    uLCD.textbackground_color(0xFFFFFF);

    uLCD.color(RED);

    uLCD.printf("\n Hello uLCD World\n"); //Default Green on black text

    uLCD.printf("\n  Starting Demo...\n");

    uLCD.color(BLUE);

    uLCD.printf("\nStudent ID Number:\n");

    uLCD.printf("\n    105070039\n");

    uLCD.text_width(4); //4X size text

    uLCD.text_height(4);

    uLCD.color(GREEN);

    for (int i=30; i>=0; --i) {

        uLCD.locate(1,3);

        uLCD.printf("%2D",i);

        wait(1);

    }

}
