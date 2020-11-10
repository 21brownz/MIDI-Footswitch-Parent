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
        void setColor(uint32_t rgb);{
            Wire.beginTransmission(address);
            Wire.write("r");
            Wire.write(rgb);
            Wire.endTransmission();
        }
        uint16_t getTempo(){
            byte recieved[] = {00000000,00000000};
            Wire.beginTransmission(address);
            Wire.write("t");
            Wire.requestFrom(address, 2);
            int i = 0;
            while(Wire.available()){
                recieved[i] = Wire.read();
            }
            return (recieved[0] << 8) | recieved[1];
        }
        uint32_t getColor();
        bool getSwitchState();
};