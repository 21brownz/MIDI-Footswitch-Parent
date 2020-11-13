#include <Arduino.h>
#include <Wire.h>
class Button {
    private:
        int address;
        uint32_t rgb;
        bool isTapTempo;
        uint16_t tempo;
    public:
        Button(int address, bool isTapTempo, uint32_t rgb){
            this->address = address;
            this->isTapTempo = isTapTempo;
            this->rgb = rgb;
            Wire.beginTransmission(address);
            Wire.write("c");
            Wire.write(isTapTempo);
            Wire.write(rgb);
            Wire.endTransmission();
        }
        void setColor(uint32_t rgb){
            Wire.beginTransmission(address);
            Wire.write("r");
            Wire.write(rgb);
            Wire.endTransmission();
        }
        float getTempo(){
            byte recieved[] = {0x0,0x0};
            Wire.beginTransmission(address);
            Wire.write("t");
            Wire.endTransmission();
            Wire.requestFrom(address, 2);
            int i = 0;
            while(Wire.available()){
                recieved[i] = Wire.read();
            }
            uint16_t returner = (recieved[0] << 8) | (recieved[1]);
            return returner;
        }
        uint32_t getColor(){
            byte recieved[] = {0x0, 0x0, 0x0, 0x0};
            Wire.beginTransmission(address);
            Wire.write("g");
            Wire.endTransmission();
            Wire.requestFrom(address,4);
            int i = 0;
            while(Wire.available()){
                recieved[i] = Wire.read();
                i++;
            }
            uint32_t value = (recieved[0] << 24) | (recieved[1] << 16) | (recieved[2] << 8) | (recieved[3]);
            return value;
        }
        bool getSwitchState(){
            byte recieved = 0x0;
            Wire.beginTransmission(address);
            Wire.write("b");
            Wire.endTransmission();
            Wire.requestFrom(address, 1);
            while(Wire.available()){
                recieved = Wire.read();
            }
            return recieved;
        }
};