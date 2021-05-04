int RELAY_1_PIN = 5; 
int RELAY_2_PIN = 3; 
 
void setup() {
  pinMode(RELAY_1_PIN, OUTPUT);  
  pinMode(RELAY_2_PIN, OUTPUT);         
}

// initial tests
void loop() {
  digitalWrite(RELAY_1_PIN, HIGH);    //Switch Solenoid1 ON
  digitalWrite(RELAY_2_PIN, HIGH);    //Switch Solenoid2 ON
  delay(150);                      //Wait 
  digitalWrite(RELAY_1_PIN, LOW);    //Switch Solenoid1 OFF
  digitalWrite(RELAY_2_PIN, LOW);    //Switch Solenoid2 ON
  delay(150);                      //Wait 1 Second
}
