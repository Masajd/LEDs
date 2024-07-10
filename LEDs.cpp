/*
  LED.CPP - Library for creating and controlling LEDs
  Created by Sam Dicker on 10.7.2024
*/

#include "Arduino.h"
#include "LEDs.h"

/**
** Default Constructor that creates an LED on Pin 1, with a timing of 0 and an old timing of 0,
** with the LED set to OFF and a time delay between blinks of 1 second. The LED is unnamed.
**/
LEDs::LEDs(){
    this->Pin = 1;
    this->ms = 0;
    this->msOld = 0;
    this->LEDState = 0;
    this->tDelay = 1000;
    this->Name = "Unnamed LED";
}

/**
** Constructor that takes 6 arguments. It assigns the LED to a pin, sets an LEDState, the time delay between blinks, and gives it a name.
** @param int Pin, Pin that LED is assigned to on the Arduino.
** @param long tDelay, Time delay between blinks of LED states.
** @param String Name, Name of the LED, usually its colour and assigned pin.
**/
LEDs::LEDs(int Pin, long tDelay, String Name){
    this->Pin = Pin;
    this->ms = 0;
    this->msOld = 0;
    this->LEDState = 0;
    this->tDelay = tDelay;
    this->Name = Name;

    initLED();
    LEDOff();
}

//LEDs::rgbLEDs(int RedPin, int Green)

/** Initialises pin that LED is assigned to OUTPUT.
**/
void LEDs::initLED(){
    pinMode(this->Pin,OUTPUT);
}

/** Set Pin value of Pin object.
** @param int Pin, Pin that LED is assigned to on the Arduino.
**/
void LEDs::setPin(int Pin){
    this->Pin = Pin;
}

/** Set the state of the LED to 0 or 1 to show the LED as being on or off.
**  @param int LEDState, State of the LED, 0 = OFF, 1 = ON.
**/
void LEDs::setLEDState(int LEDState){
    this->LEDState = LEDState;
}

/** Set the length between blinks of the LED object
**  @param long tDelay, Time delay between blinks of LED states.
**/
void LEDs::settDelay(long tDelay){
    this->tDelay = tDelay;
}

/** Set the Name of the LED object.
**  @param String Name, Name of the LED, usually its colour and assigned pin.
**/
void LEDs::setName(String Name){
    this->Name = Name;
}

/** Set the current clock timer to a value
**  @param int ms, the current clock timer value
**/
void LEDs::setms(long ms){
    this->ms = ms;
}

/** Set a value for the old clock timer
**  @param long msOld, the old clock timer value
**/
void LEDs::setmsOld(long msOld){
    this->msOld = msOld;
}

/** Get the LEDs Pin Number.
**  @return int Pin, the LEDs assgined Pin on the Arduino
**/
int LEDs::getPin(){
    return this->Pin;
}

/** Gets the LED state of the LED.
**  @return int LEDState, the LED state of the LED.
**/
int LEDs::getLEDState(){
    return this->LEDState;
}

/** Gets the time interval between blinks of the LED.
**  @return long tDelay, the time interval between blinks value of the LED.
**/
long LEDs::gettDelay(){
    return this->tDelay;
}

/** Gets the Name of the LED.
**  @return String Name, the name of the LED.
**/
String LEDs::getName(){
    return this->Name;
}

/** Gets the current clock timer value
**  @return long ms, the current clock timer value.
**/
long LEDs::getms(){
    return this->ms;
}

/** Gets the old clock timer value.
**  @return long msOld, the old clock timer value.
**/
long LEDs::getmsOld(){
    return this->msOld;
}

/** Turn the LED on and set the LED state to 1.
**/
void LEDs::LEDOn(){
    digitalWrite(this->Pin,HIGH);
    setLEDState(1);
}

/** Turn the LED off and set the LED state to 0.
**/
void LEDs::LEDOff(){
    digitalWrite(this->Pin,LOW);
    setLEDState(0);
}

/** Blinks the LED with an interval of tDelay.
**/
void LEDs::BlinkLED(){
    setms(millis());
    if((getms() - getmsOld())>gettDelay()){
    setmsOld(getms());
    if(getLEDState() == 0){
        LEDOff();
    }
    else{
        LEDOn();
    }
    }
}