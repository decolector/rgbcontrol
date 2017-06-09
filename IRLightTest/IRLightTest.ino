/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

/*
int ON = 0xF7C03F;
int OFF = 0xF740BF;
int MORE = 0xF700FF;
int LESS = 0xF7807F;

int RED = 0xF720DF;
int GREEN = 0xF7A05F;
int BLUE = 0xF7609F;
int WHITE = 0xF7E01F;

int ORANGE_RED = 0xF7103F;
int LIGHT_GREEN = 0xF7906F;
int DOGGER_BLUE = 0xF750AF;
int FLASH = 0xF7D02F;

int ORANGE = 0xF730CF;
int LIGHT_BLUE = 0xF7B04F;
int PURPLE = 0xF7708F;
int STROBE = 0xF7F00F;

int LIGHT_ORANGE = 0xF708F7;
int CYAN = 0xF78877;
int DARK_RED = 0xF748B7;
int FADE = 0xF7C837;

int YELLOW =0xF728D7;
int DARK_BLUE = 0xF7A857;
int PINK = 0xF76897;
int SMOOTH = 0xF7E817;
*/

unsigned long DIMDOWN = 0x10EF30CF; //8 Steps

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

unsigned long  IR_BPlus  = 0xFF3AC5;
unsigned long IR_BMinus = 0xFFBA45;
unsigned long IR_ON     = 0xFF827D;
unsigned long IR_OFF    = 0xFF02FD;
unsigned long IR_R    = 0xFF1AE5;
unsigned long IR_G    = 0xFF9A65;
unsigned long IR_B      = 0xFFA25D;
unsigned long IR_W    = 0xFF22DD;
unsigned long IR_B1   = 0xFF2AD5;
unsigned long IR_B2   = 0xFFAA55;
unsigned long IR_B3   = 0xFF926D;
unsigned long IR_B4   = 0xFF12ED;
unsigned long IR_B5   = 0xFF0AF5;
unsigned long IR_B6   = 0xFF8A75;
unsigned long IR_B7   = 0xFFB24D;
unsigned long IR_B8   = 0xFF32CD;
unsigned long IR_B9   = 0xFF38C7;
unsigned long IR_B10    = 0xFFB847;
unsigned long IR_B11    = 0xFF7887;
unsigned long IR_B12    = 0xFFF807;
unsigned long IR_B13    = 0xFF18E7;
unsigned long IR_B14    = 0xFF9867;
unsigned long IR_B15    = 0xFF58A7;
unsigned long IR_B16    = 0xFFD827;
unsigned long IR_UPR    = 0xFF28D7;
unsigned long IR_UPG    = 0xFFA857;
unsigned long IR_UPB    = 0xFF6897;
unsigned long IR_QUICK  = 0xFFE817;
unsigned long IR_DOWNR  = 0xFF08F7;
unsigned long IR_DOWNG  = 0xFF8877;
unsigned long IR_DOWNB  = 0xFF48B7;
unsigned long IR_SLOW   = 0xFFC837;
unsigned long IR_DIY1   = 0xFF30CF;
unsigned long IR_DIY2   = 0xFFB04F;
unsigned long IR_DIY3   = 0xFF708F;
unsigned long IR_AUTO   = 0xFFF00F;
unsigned long IR_DIY4   = 0xFF10EF;
unsigned long IR_DIY5   = 0xFF906F;
unsigned long IR_DIY6   = 0xFF50AF;
unsigned long IR_FLASH  = 0xFFD02F;
unsigned long IR_JUMP3  = 0xFF20DF;
unsigned long IR_JUMP7  = 0xFFA05F;
unsigned long IR_FADE3  = 0xFF609F;
unsigned long IR_FADE7  = 0xFFE01F;

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



#include <IRremote.h>

IRsend irsend;
int val = 0;
int led = 13;


void sendCommand(unsigned long command){
  irsend.sendNEC(command, 32);
}

void setup()
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);
    
}

void loop() {
  /*
	irsend.sendNEC(0xF7E01F, 32);
	delay(5000); //5 second delay between each signal burst
  irsend.sendNEC(0xF7609F, 32);
  delay(5000); //5 second delay between each signal burst
    irsend.sendNEC(0xF7A05F, 32);
  delay(5000); //5 second delay between each signal burst
    irsend.sendNEC(0xF720DF, 32);
  delay(5000); //5 second delay between each signal burst
  */
  sendCommand(BLUE);
  delay(1000);
  sendCommand(GREEN);
  delay(1000);
}

