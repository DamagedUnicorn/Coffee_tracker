/* debounce alternatives: button2.h, Bounce2.h
 * 
 * 
 */
#define CONFIG_UNIXTIME




#include <ezButton.h>
#include <Wire.h>
#include <ds3231.h>
#include "header.h"

ezButton button0(BUTTON_0);
ezButton button1(BUTTON_1);
ezButton button2(BUTTON_2);
ezButton buttonMode(BUTTON_MODE);

ezButton buttons[] = { button0, button1, button2, buttonMode };

void setup()
{
  // Serial communication
  Serial.begin(baudRate);
  Wire.begin();

  // Pin setup for buttons
  pinMode(BUTTON_0, INPUT);
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUTTON_MODE, INPUT);

  // configure buttons
  for (uint8_t i = 0; i < NUMBER_OF_BUTTONS; i++)
  {
    buttons[i].setDebounceTime(debounceDelay);
  }
}

void loop()
{
  for (uint8_t i = 0; i < NUMBER_OF_BUTTONS; i++)
  {
    buttons[i].loop(); // MUST call the loop() function first
  }

  updateMode();

  switch (mode)
  {
    case MAINTENANCE:
      modeMaintenanceFunction();
      break;

    case OTHER:
      modeOtherFunction();
      break;

    default:
      break;
  }
}
