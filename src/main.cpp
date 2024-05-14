#include <Arduino.h>

ISR (TCA0_HUNF_vect) {
  
}

void setup() {

  PORTB_DIR |= 1 << 5;
  PORTB_OUT |= 1 << 5;

  PORTB_DIR |= 1 << 4;
  // PORTB_OUT |= 1 << 4;

  // PORTA_DIR = 1 << 2;

  PORTC_DIR = 1 << 3;
  // PORTC_OUT = 1 << 3;

  //put your setup code here, to run once:
  // TCA0_SPLIT_CTRLB = 0b00001010; //Connect timer to output pins
  TCA0_SPLIT_CTRLB |= 1 << 1; //Connect low channel 1 to output
  // TCA0_SPLIT_CTRLB |= 1 << 4; //Connect High channel 0 to output
  PORTMUX_CTRLC |= 1 << 1; //Set Low Channel 1 outputting on alternative pin (B4)
  // PORTMUX_CTRLC |= 1 << 3; //Set High Channel 0 outputting on alternative pin (C3)

  TCA0_SPLIT_CTRLD = (TCA_SPLIT_SPLITM_bm<<TCA_SPLIT_SPLITM_bp); //Enable Split
  
  TCA0_SPLIT_LPER = 19; //Period of 1 MHz
  TCA0_SPLIT_HPER = 79; //Period of 0.25 MHz

  TCA0_SPLIT_LCMP1 = 10; //Duty cycle 0.5
  TCA0_SPLIT_HCMP0 = 40; //Duty cycle 0.5

  TCA0_SPLIT_INTCTRL = 1 << 1; //High byte underflow interrupt enable

  TCA0_SPLIT_CTRLA = 1; //Enabled with no prescale



}

void loop() {
  // put your main code here, to run repeatedly:

  PORTB_OUT |= 1 << 5;

  delay(10);
  PORTB_OUT = 0;

  delay(10);
}