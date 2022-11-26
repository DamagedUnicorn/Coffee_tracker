/* debounce alternatives: button2.h, Bounce2.h
 * 
 * 
 */

#include "header.h"
#include <ezButton.h>

ezButton button0(BUTTON_0);
ezButton button1(BUTTON_1);
ezButton button2(BUTTON_2);
ezButton button3(BUTTON_3);

ezButton buttons[] = { button0, button1, button2, button3 };

void setup()
{
  // Serial communication
  Serial.begin(baudRate);

  // Pin setup for buttons
  pinMode(BUTTON_0, INPUT);
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUTTON_3, INPUT);

  // Pin setup for ModeSwitch
  pinMode(MODE_SWITCH_0, INPUT);
  pinMode(MODE_SWITCH_1, INPUT);

  // configure buttons
  for (uint8_t i = 0; i < NUMBER_OF_BUTTONS; i++)
  {
    buttons[i].setDebounceTime(debounceDelay);
  }

  // Detect and save mode
  modeSwitchVal = getModeSwitchVal();
}

void loop()
{
  for (uint8_t i = 0; i < NUMBER_OF_BUTTONS; i++)
  {
    buttons[i].loop(); // MUST call the loop() function first
  }

  if (buttons[0].isPressed())
  {
    Serial.println("The button 0 is pressed");
  }

  switch (modeSwitchVal)
  {
    case MODE_MAINTENANCE:
      modeMaintenanceFunction();
      break;

    case MODE_OTHER:
      modeOtherFunction();
      break;

    case MODE_INVALID:
      modeInvalidFunction();
      break;

    default:
      break;
  }
}
