/*
  LED.h - Library for creating and controlling LEDs
  Created by Sam Dicker on 10.7.2024
*/

#ifndef LEDs_h
#define LEDs_h

#include "Arduino.h"

class LEDs{
    private:
      int Pin;
      long ms;
      long msOld;
      int LEDState;
      long tDelay;
      String Name;

      void initLED();
      void setms(long);
      void setmsOld(long);
      long getms();
      long getmsOld();

    public:
      LEDs();
      LEDs(int,long,String);
      void setPin(int);
      void setLEDState(int);
      void settDelay(long);
      void setName(String);
      int getPin();
      int getLEDState();
      long gettDelay();
      String getName();
      void LEDOn();
      void LEDOff();
      void BlinkLED();
};

#endif