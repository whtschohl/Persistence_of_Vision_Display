///* Code from 
//https://www.youtube.com/watch?v=NykONuPWycc&t=309s */
//
//
int serialData1 = 3;            // Arduino pin 2 connected to Pin 14, SER(serial input) of SR
int shiftClock = 4;             // Arduino pin 4 connected to Pin 11, SRCLK(shift clock) of SR
int latchClock = 5;             // Arduino pin 5 connected to Pin 12, RCLK(storage/latch clock) of SR
int serialData2 = 2;            // Arduino pin 3 connected to Pin 14, SER(serial input) of SR

void setup()
{                 // runs onece at stratup
  //pinMode(clearPin, OUTPUT);
  pinMode(serialData1, OUTPUT);
  pinMode(shiftClock, OUTPUT);
  pinMode(latchClock, OUTPUT);
  pinMode(serialData2, OUTPUT);

  //digitalWrite(clearPin, Low);          // Pin is active-low, this clears the shift register
  //digitalWrite(clearPin, High);         // Clear pin is inactive
}
//
void loop ()
{                 // runs and loops continuously
  for (int shiftCount = 0; shiftCount < 250; shiftCount++)
  {               // count from 0 to 255 and display the number on the LEDs in binary
    
    digitalWrite(latchClock, LOW);        // take the latchClock low so the LEDs don't change while you're sending in bits.
    
    shiftOut(serialData1, shiftClock, MSBFIRST, shiftCount); // shift out the bits
    digitalWrite(latchClock, HIGH);       // take the latch pin so the LEDs will light up
    delay(500);           // pause before the next value
  }
}
//
//// latch clock  on HIGH activates LEDs with parallel out (LEDs light up in binary order of shiftCount)
//
//void loop ()
//{
//  int shiftCount = 1;
//  
//  digitalWrite(latchClock, LOW);        // take the latchClock low so the LEDs don't change while you're sending in bits.
//  shiftOut(serialData1, shiftClock, MSBFIRST, shiftCount); // shift out the bits
//  digitalWrite(latchClock, HIGH);       // take the latch pin so the LEDs will light up
//  
//}
