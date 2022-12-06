// Defines
#define BUTTON_0 23
#define BUTTON_1 24
#define BUTTON_2 25
#define BUTTON_MODE 22

#define SD_CS 10
#define SD_CLK 13
#define SD_MOSI 11
#define SD_MISO 12

#define BLACK 0x0000
#define WHITE 0xFFFF

// Enums
enum modes
{
  MAINTENANCE,
  OTHER,
  NUMBER_OF_MODES
};

enum SDCardCodes
{
  DESCALE,
  BACKFLUSH,
  FILTER_CHANGE
};

// Structs
struct ts t;

// Constants
const uint16_t baudRate = 9600;
const uint16_t debounceDelay = 50;    // the debounce time; increase if the output flickers
const uint32_t timeout = 100000;

// Variables
modes mode;
File myFile;
uint32_t timer = 0;
String dateString;
MCUFRIEND_kbv tft;
bool updateScreen = false;
String string0;
String string1;
String string2;
