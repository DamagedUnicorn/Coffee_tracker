void updateMode(void)
{
  if (buttonMode.isPressed())
  {
    mode = (mode + 1) % NUMBER_OF_MODES;
  }
}
