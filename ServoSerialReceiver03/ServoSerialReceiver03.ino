#include <Servo.h> 
Servo sv, sv2;
int data[5];
int motorData[2];

void setup() {

  sv.attach(A0) ;
  sv2.attach(A1) ;

  Serial.begin( 9600 ) ;
}

void loop() {
 if (Serial.available())
  {
    for (int i = 0; i < 5; i++)
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
  }
  delay(5);


}
