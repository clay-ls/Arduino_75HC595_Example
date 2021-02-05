/*
  74HC595
  L.Swarnajith January 04, 2020.
  Local time 1325, Sri Lanka.
*/

#define latchPin 5
#define clockPin 6
#define dataPin 4

byte leds = 0;
int outArr[]={1,3,5,0,0,0,0,0};

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop()
{
 leds = 0;
 updateShiftRegister();
 delay(500);
 for(int i = 0; i < 8; i++)
 {
  bitSet(leds, outArr[i]);
  updateShiftRegister();
  delay(500);
 }
}

void updateShiftRegister()
{
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}
