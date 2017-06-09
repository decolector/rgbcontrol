/*
SharpDistSensorBasic.ino
Source: https://github.com/DrGFreeman/SharpDistSensor

MIT License

Copyright (c) 2017 Julien de la Bruere-Terreault <drgfreeman@tuta.io>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
This example shows how to use the SharpDistSensor library to continuously
read the sensor and display the analog value and the corrseponding distance
in mm.

The library default values corresponding to the Sharp GP2Y0A60SZLF 5V sensor
are used.

See the library README for how to use pre-defined sensor models or custom
fit functions.
*/

#include <SharpDistSensor.h>
#include <IRremote.h>




unsigned long ON = 0xF7C03F;
unsigned long OFF = 0xF740BF;
unsigned long MORE = 0xF700FF;
unsigned long LESS = 0xF7807F;
unsigned long RED = 0xF720DF;
unsigned long GREEN = 0xF7A05F;
unsigned long BLUE = 0xF7609F;
unsigned long WHITE = 0xF7E01F;
unsigned long ORANGE_RED = 0xF7103F;
unsigned long LIGHT_GREEN = 0xF7906F;
unsigned long DOGGER_BLUE = 0xF750AF;
unsigned long FLASH = 0xF7D02F;
unsigned long ORANGE = 0xF730CF;
unsigned long LIGHT_BLUE = 0xF7B04F;
unsigned long PURPLE = 0xF7708F;
unsigned long STROBE = 0xF7F00F;
unsigned long LIGHT_ORANGE = 0xF708F7;
unsigned long CYAN = 0xF78877;
unsigned long DARK_RED = 0xF748B7;
unsigned long FADE = 0xF7C837;
unsigned long YELLOW =0xF728D7;
unsigned long DARK_BLUE = 0xF7A857;
unsigned long PINK = 0xF76897;
unsigned long SMOOTH = 0xF7E817;

unsigned long commands[] = {
  OFF,
  ON,
  MORE,
  LESS,
  RED,
  GREEN,
  BLUE,
  WHITE,
  ORANGE_RED,
  LIGHT_GREEN,
  DOGGER_BLUE,
  FLASH,
  ORANGE,
  LIGHT_BLUE,
  PURPLE,
  STROBE,
  LIGHT_ORANGE,
  CYAN,
  DARK_RED,
  FADE,
  YELLOW,
  DARK_BLUE,
  PINK,
  SMOOTH
  
  };

unsigned long red_gamma[] = {
  RED,
  ORANGE,
  ORANGE_RED,
  LIGHT_ORANGE,
  YELLOW,
  };

unsigned long green_gamma[] = {
  GREEN,
  LIGHT_GREEN,
  LIGHT_BLUE,
  CYAN,
  DARK_BLUE
  };

unsigned long blue_gamma[] = {
  BLUE,
  DOGGER_BLUE,
  PURPLE,
  DARK_RED,
  PINK
  };

unsigned long gammas[][5] = {
    {
  RED,
  ORANGE,
  ORANGE_RED,
  LIGHT_ORANGE,
  YELLOW,
  },
    {
  GREEN,
  LIGHT_GREEN,
  LIGHT_BLUE,
  CYAN,
  DARK_BLUE
  },
{
  BLUE,
  DOGGER_BLUE,
  PURPLE,
  DARK_RED,
  PINK
  }
  };

unsigned long last_command = WHITE;

int dist, pdist = 0;

const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

// Analog pin to which the sensor is connected
const byte sensorPin0 = A0;
const byte sensorPin1 = A1;
const byte sensorPin2 = A2;

// Window size of the median filter (odd number, 1 = no filtering)
const byte mediumFilterWindowSize = 5;

// Create an object instance of the SharpDistSensor class
SharpDistSensor sensor0(sensorPin0, mediumFilterWindowSize);
//SharpDistSensor sensor1(sensorPin1, mediumFilterWindowSize);
//SharpDistSensor sensor2(sensorPin2, mediumFilterWindowSize);

IRsend irsend;

int led = 13;
int threshold = 5;

void sendCommand(unsigned long command){
  irsend.sendNEC(command, 32);
}

int processData(int val){
  //int cv = constrain(val, 120, 1450);
  int v = map(val, 120, 1450, 0, 5);
  return v;
  }


void setup() {
  Serial.begin(9600);
  //Serial.begin(115200);
  pinMode(led, OUTPUT);
}

void loop() {
  // Get distance from sensor
  
  
  int val = sensor0.getDist();




  int cv = constrain(val, 120, 1450);
  
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = cv;
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  dist = average;

    // Print distance to Serial
  Serial.print("dist: ");
  Serial.println(dist);
  
  int movement = abs(dist - pdist);
  Serial.print("mov:");
  Serial.println(movement);
  if(movement > threshold){
      Serial.println("detected movement");
      int c = processData(dist);
      sendCommand(red_gamma[c]);
      last_command = red_gamma[c];
      delay(10);
    }else{
      sendCommand(last_command);       
      delay(10);
    }
  pdist = dist;
  delay(100);

  
}
