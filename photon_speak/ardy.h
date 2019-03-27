#ifndef ARDY_H
#define ARDY_H

#include "lever.h"

class Ardy
{
  private:
  	// objects
    Lever lever;

  public:
    Ardy(){};
    ~Ardy(){};

    Lever get_lever() { return this->lever; }
    void set_lever_ang(int ang) { this->lever.set_ang(ang); }
    int get_lever_ang() { return this->lever.get_ang(); }
    void init_lever() { this->lever.init_attach(); }

};

#endif
