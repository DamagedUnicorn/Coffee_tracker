void modeMaintenanceFunction(void)
{
  if (button0.isPressed())
  {
    readCLK();
    writeData(DESCALE);
  }

  if (button1.isPressed())
  {
    readCLK();
    writeData(BACKFLUSH);
  }

  if (button2.isPressed())
  {
    readCLK();
    writeData(FILTER_CHANGE);
  }
}
