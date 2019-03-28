#ifndef PHOTO_H
#define PHOTO_H

class Photo
{
  private:
    int pin;
    int V_val;
  public:
    Photo()
    {
      // this->pin = A0;
      this->V_val = 0;
    };
    ~Photo(){};

    void init_meas_pin()
    {
      pinMode(this->pin, INPUT);
    }

    int get_meas()
    {
      return analogRead(A0);
    }

    void info()
    {
      Serial.println(get_meas());
    }

};

#endif
