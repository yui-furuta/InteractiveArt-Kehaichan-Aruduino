#include <Servo.h> 
Servo sv, sv2;
int data[6];
int motorData[2];

#include <Adafruit_NeoPixel.h>
#define PIN       6 // 信号用のピンを指定
#define NUMPIXELS 5// LEDの数を指定
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 5
int step_num = 0;
int color[] = {255, 255, 0};
int delta = -1;

int face = 0;


void setup() {
  sv.attach(A0) ;
  sv2.attach(A1) ;
  Serial.begin( 9600 ) ;
  
  pixels.begin();
}

void loop() {
 if (Serial.available())
  {
    for (int i = 0; i < 6; i++)
    {
      data[i] = Serial.read();
    }
    if (data[0] == 253)
    {
      motorData[0] = data[1];
    }

    if (data[2] == 254)
    {
      motorData[1] = data[3];
    }

    if (data[4] == 255)
    {
      sv.write(motorData[0]);
      sv2.write(motorData[1]);
    }

    if (data[5] == 0)
    {
      delta = -1;
    }
    if (data[5] == 1)
    {
      delta = 1;
    } 



  

  float ratio = step_num / 255.0;
  for(int i = 0; i < NUMPIXELS; i++ ) 
  {
    pixels.setPixelColor(i, pixels.Color(color[0] * ratio, color[1] * ratio, color[2] * ratio));
  }
  if(step_num >= 254)
  {
    step_num = 254;
  }
  if(step_num < 1)
  {
    step_num = 1;
  }

  step_num += delta;

     
//  pixels.show();

  
 }
  delay(10);
}
