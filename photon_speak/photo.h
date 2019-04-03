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
      this->V_val = 0;
    };
    ~Photo(){};


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
