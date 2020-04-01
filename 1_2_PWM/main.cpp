#include "mbed.h"

Serial pc( USBTX, USBRX );
PwmOut PWM1(D6);
DigitalIn Din(D7);


int sample = 128;
int k;

float ADCdata[128];



int main() {

  float i,j;

  PWM1.period(0.001);
  PWM1 = 0.5;

  while(true){
    for (i=0;i<=1;i+=0.1){

      PWM1.write(i);
      wait(0.1);
    }

    if (i=1) {
      for (j=1;j>=0;j-=0.1) {

        PWM1.write(j);
        wait(0.1);
      }
    }
  }

  for (k = 0; k < sample; k++){

    PWM1 = Din;

    ADCdata[k] = Din;

    wait(1./sample);

  }

  for (k = 0; k < sample; k++){

    pc.printf("%1.3f\r\n", ADCdata[k]);

    wait(0.1);

  }

 
}