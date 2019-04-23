#include "ardy.h"
#include "lever.h"
#include "commands.h"

// pointer for commands
char* options;

// chars read from serial line
int charsRead;

// serial message stored here
char msg[50];

// main interface with our various functions
Ardy ardy;

// setup
void setup() {
  init_commands(&cmds);
  Serial.begin(115200);
  ardy.init_lever();
  ardy.init_stepper();
  delay(500);
  Serial.println("Ready!");
}


void loop() {
  // check that we have things to read
  if (Serial.available())
  {
    // read from serial port
    charsRead = Serial.readBytesUntil('\n', msg, sizeof(msg) - 1);

    // make c string
    msg[charsRead] = '\0';

    // parse and set commands up
    set_commands(&cmds, msg);
  }

}
