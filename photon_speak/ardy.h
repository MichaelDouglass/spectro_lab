#ifndef ARDY_H
#define ARDY_H

#include "lever.h"
#include "photo.h"

class Ardy
{
  private:
  	// objects
    Lever lever;
    Photo photo;

  public:
    Ardy(){};
    ~Ardy(){};

    Lever get_lever() { return this->lever; }
    void set_lever_ang(int ang) { this->lever.set_ang(ang); }
    int get_lever_ang() { return this->lever.get_ang(); }
    void init_lever() { this->lever.init_attach(); }

    Photo get_photo() { return this->photo; }
    void init_photo() { this->photo.init_meas_pin(); }
    int get_photo_meas() { return this->photo.get_meas(); }

};

#endif
