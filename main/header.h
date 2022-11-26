// Defines
#define NUMBER_OF_BUTTONS 4
#define BUTTON_0 1
#define BUTTON_1 2
#define BUTTON_2 3
#define BUTTON_3 4

#define MODE_SWITCH_0 5
#define MODE_SWITCH_1 6

#define MODE_MAINTENANCE 0
#define MODE_OTHER 1
#define MODE_INVALID 2

// Constants
const uint16_t baudRate = 9600;
const uint16_t debounceDelay = 50;    // the debounce time; increase if the output flickers

// Variables
uint8_t modeSwitchVal;
