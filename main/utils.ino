uint8_t getModeSwitchVal()
{
  if ((digitalRead(MODE_SWITCH_0) == HIGH) && (digitalRead(MODE_SWITCH_1) == LOW))
  {
    return MODE_MAINTENANCE;
  }
  else if ((digitalRead(MODE_SWITCH_0) == LOW) && (digitalRead(MODE_SWITCH_1) == HIGH))
  {
    return MODE_OTHER;
  }
  else
  {
    return MODE_INVALID;
  }
}
