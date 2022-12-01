// Defines
#define NUMBER_OF_BUTTONS 4
#define NUMBER_OF_MODES 2

#define BUTTON_0 1
#define BUTTON_1 2
#define BUTTON_2 3
#define BUTTON_MODE 4

// Enums
enum modes
{
  MAINTENANCE,
  OTHER
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

// Variables
modes mode = MAINTENANCE; // Initialize in MAINTENANCE mode
