#include <SPI.h>
#include <DMD2.h>
#include <fonts/Arial_Black_16.h>

int i=0;
const int WIDTH = 2;
const int HEIGHT = 1;
const int buttonPin = 2; 
const int out_status = 4;

SoftDMD dmd(WIDTH,HEIGHT);
DMD_TextBox box(dmd); 


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(out_status, OUTPUT);
  dmd.setBrightness(30); // Set kecerahan 0 - 255 
  dmd.selectFont(Arial_Black_16); // Font yang digunakan
  dmd.begin();     // memulai DMD 
   dmd.clearScreen(); 
 dmd.drawString(4,1,F("TUTUP"));
}

void loop() {
delay (2000);
scroolMSG("halo Gan");
delay (2000);
scroolMSG("Tulisan ke 2");
 Serial.println (i);
  
}

