void scrollText(char *text, unsigned int speed)
{

  if (speed <= 0) speed = 30;
  dmd.drawMarquee(text, strlen(text), (32 * DISPLAYS_ACROSS) - 1, 0);
  long start = millis();
  long timer = start;
  boolean ret = false;
  while (!ret) {
    if ((timer + speed) < millis()) {
      ret = dmd.stepMarquee(-1, 0);
      timer = millis();
    }
  }
}

void bukaTutup()
{
  unsigned long blinkCurrMillis = millis();
  if (blinkCurrMillis - blinkPrevMillis >= blinkInterval) 
  {
    blinkPrevMillis = blinkCurrMillis;
    blink=!blink;
    
  //Serial.print("blink");
  //Serial.println(blink);
  }
  if (blink)
  {
    if (dataBaru)
    {
      dmd.clearScreen( true );
      if (buka)
      {
        dmd.drawString(  9,  0, "BUKA", 5, GRAPHICS_NORMAL );
      }
      else
      {
        dmd.drawString( 4,  0, "TUTUP", 5, GRAPHICS_NORMAL );
      }
    }
    dataBaru = false;
  } else // tidak blink maka hapus semua
  {
    dmd.clearScreen( true );
    dataBaru = true;
  }

}

