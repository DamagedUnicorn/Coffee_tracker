/*

  Calibration output:

  SerSerial took 0ms to start
  ID = 0x9341
  TouchScreen.h GFX Calibration
  Making all control and bus pins INPUT_PULLUP
  Typical 30k Analog pullup with corresponding pin
  would read low when digital is written LOW
  e.g. reads ~25 for 300R X direction
  e.g. reads ~30 for 500R Y direction

  Testing : (A2, D8) = 25
  Testing : (A3, D9) = 31
  ID = 0x9341

  cx=893 cy=95 cz=618  X, Y, Pressure
  cx=900 cy=486 cz=546  X, Y, Pressure
  cx=893 cy=880 cz=483  X, Y, Pressure
  cx=515 cy=104 cz=570  X, Y, Pressure
  cx=514 cy=878 cz=338  X, Y, Pressure
  cx=139 cy=103 cz=544  X, Y, Pressure
  cx=141 cy=484 cz=407  X, Y, Pressure
  cx=145 cy=879 cz=228  X, Y, Pressure

*** COPY-PASTE from Serial Terminal:
  const int XP=8,XM=A2,YP=A3,YM=9; //240x320 ID=0x9341
  const int TS_LEFT=929,TS_RT=106,TS_TOP=74,TS_BOT=904;

  PORTRAIT  CALIBRATION     240 x 320
  x = map(p.x, LEFT=929, RT=106, 0, 240)
  y = map(p.y, TOP=74, BOT=904, 0, 320)

  LANDSCAPE CALIBRATION     320 x 240
  x = map(p.y, LEFT=74, RT=904, 0, 320)
  y = map(p.x, TOP=106, BOT=929, 0, 240)


*/

void screenInit(String string0, String string1, String string2)
{
  uint16_t ID = tft.readID();
  if (ID == 0xD3D3) ID = 0x9481; //force ID if write-only display
  tft.begin(ID);
  tft.setRotation(3);

  screenUpdate(string0, string1, string2);
}

void screenUpdate(String string0, String string1, String string2)
{

  uint8_t xStart = 20;
  uint8_t sizeHeadline = 1;
  uint8_t sizeTimestamp = 1;

  if (mode == MAINTENANCE)
  {
    tft.fillScreen(BLACK);

    // MODE
    tft.setCursor(xStart, 20);
    tft.setTextColor(WHITE);
    tft.setTextSize(sizeHeadline);
    tft.setFont(&FreeSans9pt7b);
    tft.print("MODE: MAINTENANCE");

    // DESCALE
    tft.setCursor(xStart, 60);
    tft.setTextColor(WHITE);
    tft.setTextSize(sizeHeadline);
    tft.setFont(&FreeSans9pt7b);
    tft.print("DESCALE");
    tft.drawFastHLine(xStart, 68, 83, WHITE);

    tft.setCursor(xStart, 90);
    tft.setTextColor(WHITE);
    tft.setTextSize(sizeTimestamp);
    tft.setFont(&FreeSans12pt7b);
    tft.print(string0);

    // BACKFLUSH
    tft.setCursor(xStart, 130);
    tft.setTextColor(WHITE);
    tft.setTextSize(sizeHeadline);
    tft.setFont(&FreeSans9pt7b);
    tft.print("BACKFLUSH");
    tft.drawFastHLine(xStart, 132, 108, WHITE);

    tft.setCursor(xStart, 155);
    tft.setTextColor(WHITE);
    tft.setTextSize(sizeTimestamp);
    tft.setFont(&FreeSans12pt7b);
    tft.print(string1);

    // FILTER CHANGE
    tft.setCursor(xStart, 190);
    tft.setTextColor(WHITE);
    tft.setTextSize(sizeHeadline);
    tft.setFont(&FreeSans9pt7b);
    tft.print("FILTER CHANGE");
    tft.drawFastHLine(xStart, 192, 143, WHITE);

    tft.setCursor(xStart, 215);
    tft.setTextColor(WHITE);
    tft.setTextSize(sizeTimestamp);
    tft.setFont(&FreeSans12pt7b);
    tft.print(string2);
  }
  else if (mode == OTHER)
  {
    tft.fillScreen(BLACK);

    // MODE
    tft.setCursor(xStart, 20);
    tft.setTextColor(WHITE);
    tft.setTextSize(sizeHeadline);
    tft.setFont(&FreeSans9pt7b);
    tft.print("MODE: OTHER");
  }

  updateScreen = false;

}
