#ifndef ARDY_H
#define ARDY_H

#include "lever.h"
#include "photo.h"
#include "stepper.h"

class Ardy
{
  private:
  	// objects
    Lever lever;
    Photo photo;
    Stepper stepper;

  public:
    Ardy(){};
    ~Ardy(){};

    Lever get_lever() { return this->lever; }
    void set_lever_ang(int ang) { this->lever.set_ang(ang); }
    int get_lever_ang() { return this->lever.get_ang(); }
    void init_lever() { this->lever.init_attach(); }

    Photo get_photo() { return this->photo; }
    int get_photo_meas() { return this->photo.get_meas(); }

    Stepper get_stepper() { return this->stepper; }
    void init_stepper() {this->stepper.init_step(); }
    bool get_step_direction() {return this->stepper.get_dir(); }
    void set_step_direction(bool direction) {this->stepper.set_dir(direction); }
    void take_more_steps(int step_nums) {this->stepper.take_steps(step_nums); }

};

#endif
