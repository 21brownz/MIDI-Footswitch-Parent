# MIDI-Footswitch-Parent

Firmware written in Arduino C++ to communicate with MIDI footswitch child modules over I2C. Features some cool abstraction of each module that I spent a lot of time on. 

TODO:
  get MIDI class to talk to actual button modules, and have parent code automatically detect the number of buttons on the bus.
  get parent to talk though MIDI jack, not just USB port. (this should be really easy)
  write MIDI-sysex configuration class to allow functionality changes without having to edit code. (this is going to be a lot trickier but well worth)
  Add class to turn the whole board into an LED matrix. (I want to be able to play tetris on my pedalboard.)
