void SDInit(void)
{
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  pinMode(SS, OUTPUT);

  if (!SD.begin(SD_CS, SD_MOSI, SD_MISO, SD_CLK)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

void writeData(SDCardCodes code)
{

  updateScreen = true;

  switch (code)
  {
    case DESCALE:
      myFile = SD.open("descale.txt", FILE_WRITE);
      break;
    case BACKFLUSH:
      myFile = SD.open("flush.txt", FILE_WRITE);
      break;
    case FILTER_CHANGE:
      myFile = SD.open("filter.txt", FILE_WRITE);
      break;
    default:
      return;
      break;
  }

  if (myFile)
  {
    if (t.mday < 10) myFile.print("0");
    myFile.print(t.mday);
    myFile.print("/");
    if (t.mon < 10) myFile.print("0");
    myFile.print(t.mon);
    myFile.print("-");
    myFile.print(t.year);
    myFile.print(" ");
    if (t.hour < 10) myFile.print("0");
    myFile.print(t.hour);
    myFile.print(":");
    if (t.min < 10) myFile.print("0");
    myFile.print(t.min);
    myFile.print(":");
    if (t.sec < 10) myFile.print("0");
    myFile.println(t.sec);
  }
  myFile.close();
}

String readData(SDCardCodes code)
{
  String dateString = "";
  bool newLine = false;
  char ch;

  switch (code)
  {
    case DESCALE:
      myFile = SD.open("descale.txt");
      break;
    case BACKFLUSH:
      myFile = SD.open("flush.txt");
      break;
    case FILTER_CHANGE:
      myFile = SD.open("filter.txt");
      break;
    default:
      return;
      break;
  }

  if (myFile)
  {
    while (myFile.available())
    {
      ch = myFile.read();
      if (ch == '\n')
      {
        newLine = true;
        continue;
      }
      else
      {
        if (newLine) dateString = "";
        dateString += ch;
        newLine = false;
      }
    }
  }
  myFile.close();

  return dateString;
}

void deleteFiles()
{
  if (SD.exists("descale.txt"))
  {
    SD.remove("descale.txt");
  }

  if (SD.exists("flush.txt"))
  {
    SD.remove("flush.txt");
  }

  if (SD.exists("filter.txt"))
  {
    SD.remove("filter.txt");
  }

}
