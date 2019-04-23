#ifndef STEP_H
#define STEP_H

class Stepper
{
  private:

    int pin1;
    int pin2;
    int pin3;
    int pin4;

    int step_number;

    bool direction;

  public:
    Stepper()
    {
      this->pin1 = 9;
      this->pin2 = 10;
      this->pin3 = 11;
      this->pin4 = 12;
      this->direction = 1;
    };
    ~Stepper(){};

    void init_step()
    {
      pinMode(this->pin1, OUTPUT);
      pinMode(this->pin2, OUTPUT);
      pinMode(this->pin3, OUTPUT);
      pinMode(this->pin4, OUTPUT);
    }

    bool get_dir()
    {
      return this->direction;
    }

    void set_dir(bool direction)
    {
      this->direction = direction;
    }

    void one_step()
    {
      if(this->direction)
      {
        switch(this->step_number)
        {
          case 0:
          digitalWrite(this->pin1, HIGH);
          digitalWrite(this->pin2, LOW);
          digitalWrite(this->pin3, LOW);
          digitalWrite(this->pin4, LOW);
          break;
          case 1:
          digitalWrite(this->pin1, LOW);
          digitalWrite(this->pin2, HIGH);
          digitalWrite(this->pin3, LOW);
          digitalWrite(this->pin4, LOW);
          break;
          case 2:
          digitalWrite(this->pin1, LOW);
          digitalWrite(this->pin2, LOW);
          digitalWrite(this->pin3, HIGH);
          digitalWrite(this->pin4, LOW);
          break;
          case 3:
          digitalWrite(this->pin1, LOW);
          digitalWrite(this->pin2, LOW);
          digitalWrite(this->pin3, LOW);
          digitalWrite(this->pin4, HIGH);
          break;
        }
      }
      else
      {
        switch(this->step_number)
        {
          case 0:
          digitalWrite(this->pin1, LOW);
          digitalWrite(this->pin2, LOW);
          digitalWrite(this->pin3, LOW);
          digitalWrite(this->pin4, HIGH);
          break;
          case 1:
          digitalWrite(this->pin1, LOW);
          digitalWrite(this->pin2, LOW);
          digitalWrite(this->pin3, HIGH);
          digitalWrite(this->pin4, LOW);
          break;
          case 2:
          digitalWrite(this->pin1, LOW);
          digitalWrite(this->pin2, HIGH);
          digitalWrite(this->pin3, LOW);
          digitalWrite(this->pin4, LOW);
          break;
          case 3:
          digitalWrite(this->pin1, HIGH);
          digitalWrite(this->pin2, LOW);
          digitalWrite(this->pin3, LOW);
          digitalWrite(this->pin4, LOW);
          break;
        }
      }
      this->step_number++;
      if (this->step_number>3)
      {
        this->step_number=0;
      }
    }

    void take_steps(int step_nums)
    {
      for (int i = 1; i < step_nums; i++ )
      {
        one_step();
        delay(2);
      }
    }
};

#endif
