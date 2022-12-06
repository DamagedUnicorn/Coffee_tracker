/* debounce alternatives: button2.h, Bounce2.h

  SD lib: https://github.com/adafruit/SD - https://learn.adafruit.com/adafruit-data-logger-shield/for-the-mega-and-leonardo
  DS3231 lib: https://github.com/rodan/ds3231

  NOTES:
    - SD card file names are short 8.3, i.e. maximum 8 character name with maximum character extension
    - Screen calibration and setup: https://www.google.com/search?q=ILI9341+shield+example&rlz=1C5CHFA_enDK887DK887&sxsrf=ALiCzsYHRfZrMl6I24SzConzUr_LVYUPig:1670160465435&source=lnms&tbm=vid&sa=X&ved=2ahUKEwiu5onKiOD7AhV4g_0HHUQLAR4Q_AUoAnoECAEQBA&biw=836&bih=666&dpr=2#fpstate=ive&vld=cid:d5ac037e,vid:mGevO10I-pU

*/
//#define CONFIG_UNIXTIME

#include <ezButton.h>
#include <Wire.h>
#include <ds3231.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>   // Hardware-specific library
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include "header.h"

ezButton button0(BUTTON_0);
ezButton button1(BUTTON_1);
ezButton button2(BUTTON_2);
ezButton buttonMode(BUTTON_MODE);

void setup()
{
  // Serial communication
  Serial.begin(baudRate);

  mode = MAINTENANCE; // Set start-up mode

  SDInit();

  String string0 = readData(DESCALE);
  String string1 = readData(BACKFLUSH);
  String string2 = readData(FILTER_CHANGE);

  screenInit(string0, string1, string2);

  //deleteFiles();

  Wire.begin();

  // RESET clock, DO NOT RUN!
  //setCLK(NULL, NULL, NULL, NULL, NULL, NULL);

  // Pin setup for buttons
  pinMode(BUTTON_0, INPUT);
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUTTON_MODE, INPUT);

  // configure buttons
  button0.setDebounceTime(debounceDelay);
  button1.setDebounceTime(debounceDelay);
  button2.setDebounceTime(debounceDelay);
  buttonMode.setDebounceTime(debounceDelay);

}

void loop()
{
  button0.loop(); // MUST call the loop() function first
  button1.loop();
  button2.loop();
  buttonMode.loop();

  updateMode();

  switch (mode)
  {
    case MAINTENANCE:
      modeMaintenanceFunction();

      if (updateScreen)
      {
        string0 = readData(DESCALE);
        string1 = readData(BACKFLUSH);
        string2 = readData(FILTER_CHANGE);

        screenUpdate(string0, string1, string2);
      }
      break;

    case OTHER:
      modeOtherFunction();

      if (updateScreen)
      {
        screenUpdate("", "", "");
      }
      break;

    default:
      break;
  }




  /*
    if (timer == timeout)
    {
      Serial.print("MODE:          ");
      Serial.println(mode);
      dateString = readData(DESCALE);
      Serial.print("DESCALE:       ");
      Serial.println(dateString);
      dateString = readData(BACKFLUSH);
      Serial.print("BACKFLUSH:     ");
      Serial.println(dateString);
      dateString = readData(FILTER_CHANGE);
      Serial.print("FILTER CHANGE: ");
      Serial.println(dateString);
      Serial.println("=====================================");
      timer = timer % timeout;
    }
    timer++;
  */
}
