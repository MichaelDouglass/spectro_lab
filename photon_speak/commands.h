#ifndef COMMANDS_H
#define COMMANDS_H

#include "ardy.h"

extern Ardy ardy;

struct commands
{
  // mode optional
  char* mode;

  // non-optional
  char* func;
  char* cmd;
  char* opt;

} cmds;

void init_commands(struct commands *cmds)
{
  cmds->mode = NULL;
  cmds->func = NULL;
  cmds->cmd  = NULL;
  cmds->opt  = NULL;
}

void set_commands(struct commands *cmds, char *msg)
{
  // bytes to check in strncmp
  int b2chk = 3;
  int qByte = 1;

  char* option = strtok(msg, ": ");

  // just check out info
  if (strcmp(option, "*IDN?") == 0)
  {
    // we can update this with whatever we want?
    // would probably be better to move the info we actually want
    // to return to the ardy.h file
    Serial.write("You've just been hacked by EBME360 Project Photon. Nice!\n");
    cmds->func = "*IDN?";
  }
  // servo
  else if (strncmp(option, "ANG", b2chk) == 0)
  {
      if (option[3] == '?')
      {
        // Print the current angle
        Serial.println(ardy.get_lever_ang());
        return;
      }

      option = strtok(NULL, " ");

      // SET N for setting the servo angle
      if (strncmp(option, "SET", b2chk) == 0)
      {
        // get angle value
        option = strtok(NULL, " ");

        // make sure we have an integer
        int angle = atoi(option);

        // check angle appropriate
        if (angle < 0)
        {
          angle = 0;
          Serial.write("Provided angle was below 0... way to go. Angle set to 0.");
        }
        else if (angle > 180)
        {
          angle = 180;
          Serial.print("Provided angle was above 180. This limit exists. Angle set to 180.");
        }

        // actually set options
        ardy.set_lever_ang(angle);
        cmds->cmd = "SET";
        cmds->opt = option;

        Serial.println("Moving...");
        return;
      }
  }
  else if (strncmp(option, "MEA", b2chk) == 0)
  {
    if (option[3] == '?')
    {
      Serial.println(ardy.get_photo_meas());
      return;
    }
  }
  else if (strncmp(option, "STP", b2chk) == 0)
  {
    if (option[3] == '?')
    {
      Serial.println("Yet to code");
      return;
    }

    option = strtok(NULL, " ");
    cmds->func = "STP";

    if (strncmp(option, "MOV", b2chk) == 0)
    {
      option = strtok(NULL, " ");

      int steps = atoi(option);
      if (steps < 1)
      {
        Serial.print("Steps was below acceptable value of 1. Steps set to 1.");
        steps = 1;
      }
      else if (steps > 1000)
      {
        Serial.print("Steps was above acceptable value of 1000. Steps set to 1000.");
        steps = 1000;
      }

      ardy.take_more_steps(steps);
      Serial.println("Moving...");
    }
    else if (strncmp(option, "SET", b2chk) == 0)
    {
      option = strtok(NULL, " ");

      int direction = atoi(option);
      if (direction == 1)
      {
        ardy.set_step_direction(1);
        Serial.println("Direction CCW");
      }
      else if (direction == 0)
      {
        ardy.set_step_direction(0);
        Serial.println("Direction CW");
      }
      else
      {
        Serial.println("Invalid Argument");
      }
    }
    else if (strncmp(option, "BYE", b2chk) == 0)
    {
      Serial.println("Congratulations, you just reached the LIGHT at the end of the tunnel.");
    }
  }
  // default
  else
  {
    Serial.write("Please provide a valid command.\n");
  }
}

#endif
