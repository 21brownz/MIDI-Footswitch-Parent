#include <Arduino.h>
#include <Wire.h>
#include <MIDI.h>
#include <ArduinoTapTempo.h>

//create MIDI instance
MIDI_CREATE_DEFAULT_INSTANCE();

// DEBUG mode flag. set this to 1 if you want state printouts
bool DEBUG_MODE = 0;

// sets all pin numbers;
const int exp1pin = A0;
const int exp1detpin = A0;
const int exp2pin = A1;
const int exp2detpin = A1;
const int exp3pin = A2;
const int exp3detpin = A2;
const int toe1pin = 12;
const int toe1detpin = 12;
const int toe2pin = 6;
const int toe2detpin = 6;

//pin states
bool exp1det;
bool exp2det;
bool exp3det;
bool toe1;
bool toe2;
int exp1 = 0;
int exp2 = 0;
int exp3 = 0;

//sets the color of the integrated LED in a footswitch module at addr to the rgb value specified.
void setButtonColor(int addr, int r, int g, int b){
  Wire.beginTransmission(addr);
  Wire.write(r);
  Wire.write(g);
  Wire.write(b);
  Wire.endTransmission();
  //TODO: IMPLEMENT DEBUG MODE
}

//gets the state of the button. if debug mode is on, it prints out the state
bool getButtonState(byte addr){
  Wire.requestFrom(addr,1);
  while(Wire.available()){    // slave may send less than requested
    bool ret = Wire.read() == 1;
    if(DEBUG_MODE){
      //TODO: GET THIS FORMATTED RIGHT
      Serial.println(ret);
    }
    return ret;
  }
}

//updates expression pedal positions
void updateExp(){
  
}

//setup code
void setup() {
  MIDI.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
}
