#include <SPI.h>        //SPI.h must be included as DMD is written by SPI (the IDE complains otherwise)
#include <DMD.h>        //
#include <TimerOne.h>   //
#include "SystemFont5x7.h"
#include "Arial_Black_16.h"

//Fire up the DMD library as dmd
#define DISPLAYS_ACROSS 2
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);
boolean buka = false;
boolean dataBaru = true;
boolean blink=true;

/// variable timer untuk mengatur blink
unsigned long blinkPrevMillis = 0;
const long blinkInterval = 1000; // 1000= 1 sec

void ScanDMD()
{
  dmd.scanDisplayBySPI();
}


void setup() {
  //initialize TimerOne's interrupt/CPU usage used to scan and refresh the display
  Timer1.initialize( 3000 );           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
  Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()

  //clear/init the DMD pixels held in RAM
  dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)
  Serial.begin(115200);
  dmd.selectFont(Arial_Black_16);
  //buka =1;
}

void loop() {
  if (Serial.available())
  {
    serial_baca();
  }
  bukaTutup();
  //scrollText("Dunia hanya?", 0);
}
