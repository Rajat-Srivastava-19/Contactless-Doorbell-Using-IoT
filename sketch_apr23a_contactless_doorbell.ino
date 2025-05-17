#include <NewPing.h>

const int TRIG_PIN = 9;    
const int ECHO_PIN = 10;   
const int BUZZER_PIN = 8; 
const int MAX_DISTANCE = 200; 
const int THRESHOLD_DISTANCE = 15; 

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(500);
  unsigned int distance = sonar.ping_cm(); 


  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance > 0 && distance <= THRESHOLD_DISTANCE) {
    digitalWrite(BUZZER_PIN, HIGH);
  }
  else{
    digitalWrite(BUZZER_PIN, LOW);
     }}