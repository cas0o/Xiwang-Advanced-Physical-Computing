#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        6
#define NUMPIXELS1  19
#define NUMPIXELS2  19


Adafruit_NeoPixel pixels1(NUMPIXELS1, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS2, PIN, NEO_GRB + NEO_KHZ800);

const int trigPin = 12;
const int echoPin = 11;
int duration = 0;
int distance = 0;

void NeoBlink(int num, int wait)
{
  if(distance <20)
  {Serial.print("00");
    for (int i = 0; i < num; i++)
    {
      pixels1.setPixelColor(i, 14, 221, 162);
      pixels2.setPixelColor(i, 14, 221, 162);
    }
    pixels1.show();
    pixels2.show();
    }else if(distance>20 && distance<40){
    Serial.print("22");
    for (int j = 0; j < num; j++)
    {
      pixels1.setPixelColor(j, 255, 77, 230);
      pixels2.setPixelColor(j, 255, 77, 230);
    }
    pixels1.show(); 
    pixels2.show(); 
    delay(10);
  }

  else {
    Serial.print("33");
    for (int p = 0; p < num; p++)
    {
      pixels1.setPixelColor(p, 217, 215, 226);
      pixels2.setPixelColor(p, 217, 215, 226);
      delay(10);
       for (int x = 255; x > 0; x=x-2){
        pixels1.setBrightness(x);
         pixels2.setBrightness(x);
       pixels1.show();
        pixels2.show();
      //delay(10);
       }
    }
    pixels1.show(); 
    pixels2.show(); 
  }  
  delay(wait);
}

void setup() 
{
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);
  pixels1.begin();
  pixels2.begin();
pixels1.setBrightness(50);
pixels2.setBrightness(50);
  Serial.begin(9600);
}
void loop()
{
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  NeoBlink(19, 500);
  
 
  delay(100);
}
