/////  Multimodal Haptic Armrest for Immersive 4D Experiences - demo code  /////
/////  CAPSTONE project - F2020-W2021 - MECH Project #22                   /////
/////  Arduino code for the actuations of the prototype demonstration      /////
/////  The Incredibles https://www.youtube.com/watch?v=quXf_jvnU4M         /////
/////  From 0:00 to 1:27.                                                  /////
/////  Scenes as described in "Incredibles video timestamps" Google doc    /////
/////  Harcoded demo.                                                      /////

//////// define pin set up & code variables //////// 
/// peltier ///
int E2 = 12;
int M2 = 13;
int numberOfPokes = 0;
///
/// solenoids ///
int RELAY_1_PIN = 11; 
int RELAY_2_PIN = 10; 
///
/// strong vibration motors and fan ///
#include <SparkFun_TB6612.h> // library to control SparkFun motor driver module
#define PWMD 9
#define DIN2 8 
#define DIN1 7
#define CIN1 6
#define CIN2 5
#define PWMC 4
#define STBY 40
#define STB2 41
///
/// weak vibration motors and fan ///
#define AIN1 50
#define BIN1 51
#define AIN2 53
#define BIN2 48
#define PWMA 52
#define PWMB 49
///
const int offsetA = 1;
const int offsetB = 1;
const int offsetC = 1;
const int offsetD = 1;

void setup() {
/// Set ups
  pinMode(E2, OUTPUT);
  pinMode(M2, OUTPUT);
  Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);  // defines channel (2 motors)
  Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);  // defines channel (2 motors)
  Motor motor3 = Motor(CIN1, CIN2, PWMC, offsetC, STB2);

//// Scene 1 -> 2 //// weak vib motors
  motor1.drive(60); // weak vib motors on
  motor2.drive(60); // weak vib motors on

  delay(22000);
  
  digitalWrite(AIN1, LOW);                          //set pin 1 to low
  digitalWrite(AIN2, LOW);                          //set pin 2 to low
  digitalWrite(BIN1, LOW);                          //set pin 1 to low
  digitalWrite(BIN2, LOW);                          //set pin 2 to low
  analogWrite(PWMA, 0);              
  analogWrite(PWMB, 0);              
  
//// Scene 2 -> 3 //// strong vib motors
  motor3.drive(255);
  
  delay(1000);
  
  motor3.brake(); // stop vib

//// Scene 3 -> 4 //// weak vib motors
  motor1.drive(120); // weak vib motors on
  motor2.drive(120); // weak vib motors on
  
  delay(1000);
  
  digitalWrite(AIN1, LOW);                          //set pin 1 to low
  digitalWrite(AIN2, LOW);                          //set pin 2 to low
  digitalWrite(BIN1, LOW);                          //set pin 1 to low
  digitalWrite(BIN2, LOW);                          //set pin 2 to low
  analogWrite(PWMA, 0);               
  analogWrite(PWMB, 0);               

//// Scene 4 -> 5 //// strong vib motors
  motor3.drive(160);
  
  delay(1000);
  
//// Scene 5 -> 6 //// strong vib motors
  motor3.drive(255);
  
  delay(1000);
  
  motor3.brake(); // stop vib

//// Scene 6 -> 9 //// weak & strong vib motors + peltier
  motor1.drive(120); // weak motors on
  motor2.drive(120); // weak motors on
  motor3.drive(160); // strong motors on
  digitalWrite(E2, HIGH);   // Peltier warming
  digitalWrite(M2, LOW);    // Peltier warming
  
  delay(4000);

  digitalWrite(E2, LOW);  // turn peltier off
  digitalWrite(M2, LOW);  // turn peltier off 
  
  // solenoid poking
  // 3 pokes per second for 3 seconds, 9 pokes total
  int numberOfPokes = 0;
  while (numberOfPokes < 9) {
    pinMode(RELAY_1_PIN, OUTPUT);   // connect
    pinMode(RELAY_2_PIN, OUTPUT);   // connect
    digitalWrite(RELAY_1_PIN, HIGH);   // switch Solenoid1 ON
    digitalWrite(RELAY_2_PIN, HIGH);   // switch Solenoid2 ON
    delay(167);
    digitalWrite(RELAY_1_PIN, LOW);    // switch Solenoid1 OFF
    digitalWrite(RELAY_2_PIN, LOW);    // switch Solenoid2 OFF
    delay(167);
    numberOfPokes = numberOfPokes + 1;
  }
  pinMode(RELAY_1_PIN, INPUT);   // to place solenoid down
  pinMode(RELAY_2_PIN, INPUT);   // to place solenoid down
  
  digitalWrite(E2, HIGH);   // Peltier warming
  digitalWrite(M2, LOW);    // Peltier warming
  delay(4000);
  digitalWrite(E2, LOW);  // turn peltier off
  digitalWrite(M2, LOW);  // turn peltier off 
  delay(3000);
  digitalWrite(E2, HIGH);   // Peltier warming
  digitalWrite(M2, LOW);    // Peltier warming
  delay(2000);
  digitalWrite(E2, LOW);  // turn peltier off
  digitalWrite(M2, LOW);  // turn peltier off 
  delay(1000);
  digitalWrite(E2, HIGH);   // Peltier warming
  digitalWrite(M2, LOW);    // Peltier warming
  delay(3000); 

  motor3.brake(); // stop vib
    
//// Scene 9 -> 10 //// weak vib motors + peltier
  digitalWrite(E2, LOW);  // turn peltier off
  digitalWrite(M2, LOW);  // turn peltier off
  delay(1000);

  digitalWrite(AIN1, LOW);                          //set pin 1 to low
  digitalWrite(AIN2, LOW);                          //set pin 2 to low
  digitalWrite(BIN1, LOW);                          //set pin 1 to low
  digitalWrite(BIN2, LOW);                          //set pin 2 to low
  analogWrite(PWMA, 0);               
  analogWrite(PWMB, 0);               

//// Scene 10 -> 11 //// weak & strong vib motors + peltier  
  motor1.drive(230); // weak motors on
  motor2.drive(230); // weak motors on
  motor3.drive(200); // strong motors on

  delay(1000);

  motor3.brake(); // stop vib
  digitalWrite(AIN1, LOW);                          //set pin 1 to low
  digitalWrite(AIN2, LOW);                          //set pin 2 to low
  digitalWrite(BIN1, LOW);                          //set pin 1 to low
  digitalWrite(BIN2, LOW);                          //set pin 2 to low
  analogWrite(PWMA, 0);               
  analogWrite(PWMB, 0);               

//// Scene 11 -> 12 //// no actuation
  delay(1000);

//// Scene 12 -> 13 //// solenoids + strong vib motors
  motor3.drive(200); // strong motors on
  
  // solenoid poking
  // 1 poke per second for 1 second, 1 poke total
  numberOfPokes = 0;
  while (numberOfPokes < 1) {
    pinMode(RELAY_1_PIN, OUTPUT);   // connect
    pinMode(RELAY_2_PIN, OUTPUT);   // connect
    digitalWrite(RELAY_1_PIN, HIGH);   // switch Solenoid1 ON
    digitalWrite(RELAY_2_PIN, HIGH);   // switch Solenoid2 ON
    delay(500);
    digitalWrite(RELAY_1_PIN, LOW);    // switch Solenoid1 OFF
    digitalWrite(RELAY_2_PIN, LOW);    // switch Solenoid2 OFF
    delay(450);
    numberOfPokes = numberOfPokes + 1;
  }
  pinMode(RELAY_1_PIN, INPUT);   // to place solenoid down
  pinMode(RELAY_2_PIN, INPUT);   // to place solenoid down

  motor3.brake(); // stop strong vib

//// Scene 13 -> 14 //// weak vib motors
  motor1.drive(120); // weak motors on
  motor2.drive(120); // weak motors on

  delay(1000);

  digitalWrite(AIN1, LOW);                          //set pin 1 to low
  digitalWrite(AIN2, LOW);                          //set pin 2 to low
  digitalWrite(BIN1, LOW);                          //set pin 1 to low
  digitalWrite(BIN2, LOW);                          //set pin 2 to low
  analogWrite(PWMA, 0);               
  analogWrite(PWMB, 0);

//// Scene 14 -> 15 //// fan + peltier 
  digitalWrite(DIN1, LOW);   // fan on
  digitalWrite(DIN2, HIGH);  // fan on 
  analogWrite(PWMD, 255);    // fan on - full speed           
  digitalWrite(E2, HIGH);    // Peltier warming
  digitalWrite(M2, LOW);     // Peltier warming
  
  delay(4000);
    
  digitalWrite(E2, LOW);   // turn peltier off
  digitalWrite(M2, LOW);   // turn peltier off 

//// Scene 15 -> 16 //// weak vib motors + fan + peltier
  motor1.drive(120); // weak motors on
  motor2.drive(120); // weak motors on
  
  delay(1000);
  digitalWrite(E2, HIGH);   // Peltier warming
  digitalWrite(M2, LOW);    // Peltier warming
  delay(3000);
  digitalWrite(E2, LOW);   // turn peltier off
  digitalWrite(M2, LOW);   // turn peltier off 
  delay(1000);
  digitalWrite(E2, HIGH);   // Peltier warming
  digitalWrite(M2, LOW);    // Peltier warming

//// Scene 16 -> 17 //// weak vib motors + fan + peltier
  delay(2000);

//// Scene 17 -> 18 //// weak vib motors + fan + peltier
  digitalWrite(E2, LOW);   // turn peltier off
  digitalWrite(M2, LOW);   // turn peltier off 
  delay(3000);
//  // solenoid poking
//  // 3 pokes per second for 3 seconds, 9 pokes total
//  numberOfPokes = 0;
//  while (numberOfPokes < 9) {
//    pinMode(RELAY_1_PIN, OUTPUT);   // connect
//    pinMode(RELAY_2_PIN, OUTPUT);   // connect
//    digitalWrite(RELAY_1_PIN, HIGH);   //Switch Solenoid1 ON
//    digitalWrite(RELAY_2_PIN, HIGH);   //Switch Solenoid2 ON
//    delay(167);
//    digitalWrite(RELAY_1_PIN, LOW);    //Switch Solenoid1 OFF
//    digitalWrite(RELAY_2_PIN, LOW);    //Switch Solenoid2 OFF
//    delay(167);
//    numberOfPokes = numberOfPokes + 1;
//  }
//  pinMode(RELAY_1_PIN, INPUT);   // to place solenoid down
//  pinMode(RELAY_2_PIN, INPUT);   // to place solenoid down

  digitalWrite(E2, HIGH);   // Peltier warming
  digitalWrite(M2, LOW);    // Peltier warming
  delay(2000);
//  // solenoid poking
//  // 1 pokes per second for 2 seconds
//  numberOfPokes = 0;
//  while (numberOfPokes < 2) {
//    pinMode(RELAY_1_PIN, OUTPUT);   // connect
//    pinMode(RELAY_2_PIN, OUTPUT);   // connect
//    digitalWrite(RELAY_1_PIN, HIGH);   //Switch Solenoid1 ON
//    digitalWrite(RELAY_2_PIN, HIGH);   //Switch Solenoid2 ON
//    delay(100);
//    digitalWrite(RELAY_1_PIN, LOW);    //Switch Solenoid1 OFF
//    digitalWrite(RELAY_2_PIN, LOW);    //Switch Solenoid2 OFF
//    delay(900);
//    numberOfPokes = numberOfPokes + 1;
//  }
//  pinMode(RELAY_1_PIN, INPUT);   // to place solenoid down
//  pinMode(RELAY_2_PIN, INPUT);   // to place solenoid down

  digitalWrite(E2, LOW);   // turn peltier off
  digitalWrite(M2, LOW);   // turn peltier off 
  
  digitalWrite(AIN1, LOW);                          //set pin 1 to low
  digitalWrite(AIN2, LOW);                          //set pin 2 to low
  digitalWrite(BIN1, LOW);                          //set pin 1 to low
  digitalWrite(BIN2, LOW);                          //set pin 2 to low
  analogWrite(PWMA, 0);               
  analogWrite(PWMB, 0); 
  
//// Scene 18 -> 19 //// strong vib motors + fan
  motor3.drive(120);
  delay(4000);
  
//// Scene 19 -> 20 //// strong vib motors + fan + peltier
  digitalWrite(E2, HIGH);   // Peltier warming
  digitalWrite(M2, LOW);    // Peltier warming
  delay(1000);
  motor3.brake();
  delay(2000);
  digitalWrite(E2, LOW);   // turn peltier off
  digitalWrite(M2, LOW);   // turn peltier off
  motor3.drive(120);
  delay(1000);
  motor3.brake();
  motor1.drive(120); // weak motors on
  motor2.drive(120); // weak motors on
  digitalWrite(E2, HIGH);   // Peltier warming
  digitalWrite(M2, LOW);    // Peltier warming
  delay(3000);
  digitalWrite(E2, LOW);   // turn peltier off
  digitalWrite(M2, LOW);   // turn peltier off
  delay(1000);

//// Scene 20 -> 21 //// weak vib motors + fan + peltier + solenoids
  delay(1000);
  digitalWrite(E2, HIGH);   // Peltier warming
  digitalWrite(M2, LOW);    // Peltier warming

  // solenoid poking
  // 2 pokes per second for 3 seconds, 6 pokes total
  numberOfPokes = 0;
  while (numberOfPokes < 6) {
    pinMode(RELAY_1_PIN, OUTPUT);   // connect
    pinMode(RELAY_2_PIN, OUTPUT);   // connect
    digitalWrite(RELAY_1_PIN, HIGH);   //Switch Solenoid1 ON
    digitalWrite(RELAY_2_PIN, HIGH);   //Switch Solenoid2 ON
    delay(100);
    digitalWrite(RELAY_1_PIN, LOW);    //Switch Solenoid1 OFF
    digitalWrite(RELAY_2_PIN, LOW);    //Switch Solenoid2 OFF
    delay(400);
    numberOfPokes = numberOfPokes + 1;
  }
  pinMode(RELAY_1_PIN, INPUT);   // to place solenoid down
  pinMode(RELAY_2_PIN, INPUT);   // to place solenoid down

  digitalWrite(E2, LOW);   // turn peltier off
  digitalWrite(M2, LOW);   // turn peltier off
  
//// Scene 21 -> 22 //// weak vib motors + fan + peltier
  delay(1000);
  digitalWrite(E2, HIGH);   // Peltier warming
  digitalWrite(M2, LOW);    // Peltier warming
  delay(1000);

//// Scene 22 -> 23 //// weak vib motors + fan + peltier + solenoid
  // solenoid poking
  // 1 poke per second for 1 second, 1 poke total
  numberOfPokes = 0;
  while (numberOfPokes < 1) {
    pinMode(RELAY_1_PIN, OUTPUT);   // connect
    pinMode(RELAY_2_PIN, OUTPUT);   // connect
    digitalWrite(RELAY_1_PIN, HIGH);   //Switch Solenoid1 ON
    digitalWrite(RELAY_2_PIN, HIGH);   //Switch Solenoid2 ON
    delay(100);
    digitalWrite(RELAY_1_PIN, LOW);    //Switch Solenoid1 OFF
    digitalWrite(RELAY_2_PIN, LOW);    //Switch Solenoid2 OFF
    delay(900);
    numberOfPokes = numberOfPokes + 1;
  }
  pinMode(RELAY_1_PIN, INPUT);   // to place solenoid down
  pinMode(RELAY_2_PIN, INPUT);   // to place solenoid down

  digitalWrite(AIN1, LOW);                          //set pin 1 to low
  digitalWrite(AIN2, LOW);                          //set pin 2 to low
  digitalWrite(BIN1, LOW);                          //set pin 1 to low
  digitalWrite(BIN2, LOW);                          //set pin 2 to low
  analogWrite(PWMA, 0);               
  analogWrite(PWMB, 0); 

  digitalWrite(DIN1, LOW); // fan off
  digitalWrite(DIN2, LOW); // fan off
  analogWrite(PWMD, 0);    // fan off - 0 speed
  
  digitalWrite(E2, LOW);   // turn peltier off
  digitalWrite(M2, LOW);   // turn peltier off
 
//// Scene 23 -> 24 //// no actuation
  delay(1000);

//// Scene 24 -> 25 //// solenoid, last actuation
  // solenoid poking
  // 1 poke per second for 1 second, 1 poke total
  numberOfPokes = 0;
  while (numberOfPokes < 1) {
    pinMode(RELAY_1_PIN, OUTPUT);   // connect
    pinMode(RELAY_2_PIN, OUTPUT);   // connect
    digitalWrite(RELAY_1_PIN, HIGH);   //Switch Solenoid1 ON
    digitalWrite(RELAY_2_PIN, HIGH);   //Switch Solenoid2 ON
    delay(100);
    digitalWrite(RELAY_1_PIN, LOW);    //Switch Solenoid1 OFF
    digitalWrite(RELAY_2_PIN, LOW);    //Switch Solenoid2 OFF
    delay(900);
    numberOfPokes = numberOfPokes + 1;
  }
  pinMode(RELAY_1_PIN, INPUT);   // to place solenoid down
  pinMode(RELAY_2_PIN, INPUT);   // to place solenoid down
}
void loop() {
  exit; // terminate loop execution
}

//// DONE :-) !!! We hope you enjoy or provide a fun, immersive 4D experience. 
