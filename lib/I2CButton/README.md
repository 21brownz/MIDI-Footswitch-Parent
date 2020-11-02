Library for controlling Zach Brown's I2C Pedalboard Buttons
In this library, color is represented as a 32 bit integer. the bits are mapped in hex as nothing-R-G-B 

low level stuff you shouldn't worry about:

opcodes:
0x24 - set the button's led color.
0x25 - set the button as a tap tempo. Just send a single bool after this.  
0x26 - ask for the tempo. Expect to recieve a 16 bit integer after this that is the tempo.
0x27 - get the color from the button.
0x28 - get the state of the button.