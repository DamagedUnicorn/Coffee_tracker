#include "header.h"

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

  // Detect and save mode
  modeSwitchVal = getModeSwitchVal();
}

void loop()
{
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
