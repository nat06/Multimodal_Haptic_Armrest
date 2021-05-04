#include <SparkFun_TB6612.h>

#define PWMD 9
#define DIN2 8
#define DIN1 7
#define CIN1 6
#define CIN2 5
#define PWMC 4
#define STBY 40
#define STB2 41

#define AIN1 50
#define BIN1 51
#define AIN2 53
#define BIN2 48
#define PWMA 52
#define PWMB 49

const int offsetA = 1;
const int offsetB = 1;
const int offsetC = 1;
const int offsetD = 1;

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);
Motor impact = Motor(CIN1, CIN2, PWMC, offsetC, STB2);
Motor fan = Motor(DIN1, DIN2, PWMD, offsetD, STB2);

int t = 40;
int motorspeed = 0;

void setup() {
}

void loop() {
  
  motor1.drive(t, 200);
  motor1.brake();
  motor1.drive(-t, 200);
  motor1.brake();
  motor2.drive(t, 200);
  motor2.brake();
  motor2.drive(-t, 200);
  motor2.brake();

//  impact.drive(90, 70); 
//  impact.brake();
//  t = t + 20;
//  if (t >= 220) t = 40;

//    digitalWrite(DIN1, LOW);                         
//    digitalWrite(DIN2, HIGH);                       
//    analogWrite(PWMD, 255);              
//    delay(5000);
//
//    //stop motor
//    digitalWrite(DIN1, LOW);                          
//    digitalWrite(DIN2, LOW);                     
//    analogWrite(PWMD, 0);          
//    delay(3000);
  
}
