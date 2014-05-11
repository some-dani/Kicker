#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 exp1;

int LightSensorPin_A = A3;    // select the input pin for the light sensor (on the side A)
int LightSensorPin_B = A4;    // select the input pin for the light sensor (on the side B)
int sensorValue_A = 0;        // variable to store the value coming from the ligth sensor (side A)
int sensorValue_B = 0;        // variable to store the value coming from the ligth sensor (side B)
int maxSensorValueInit_A = 0;      // Init Value of the light sensor without beeing something between
int maxSensorValueInit_B = 0;

int goalA = 0; // holds the current number of goals
int goalB = 0; // holds the current number of goals
char serialBuf[64];


void setup() {
  // init light sensor
  int currentValue;
  for (int i = 0; i < 50; i++) {
    currentValue = analogRead(LightSensorPin_A);
    if (currentValue > maxSensorValueInit_A) {
      maxSensorValueInit_A = currentValue;
    }
    delay(10);
  }

  for (int i = 0; i < 50; i++) {
    currentValue = analogRead(LightSensorPin_B);
    if (currentValue > maxSensorValueInit_B) {
      maxSensorValueInit_B = currentValue;
    }
    delay(10);
  }

  exp1.begin(0);

  for (int i = 0; i < 16; i++) {
    exp1.pinMode(i, OUTPUT);
  }

  setZero(0);
  setZero(1);
  
  delay(3000);
  
  Serial.begin(9600);
  Serial.print("test");

}

void loop() {
  // refresh the sensor value
  sensorValue_A = analogRead(LightSensorPin_A);
  sensorValue_B = analogRead(LightSensorPin_B);

  //Serial.println(sensorValue_A);
  
  // checks if there is something between the light sensor...
  // ... for goalA
  if (sensorValue_A > maxSensorValueInit_A + 15) {
    Serial.println("goal!");
    goalA++;
    setGoalA();
    delay(1000);
  }

  //... and goalB
  if ( sensorValue_B > maxSensorValueInit_B + 15) {
    Serial.println("goal!");
    goalB++;
    setGoalB();
    delay(1000);
  }
  delay(1);
}

/*
Set the goals on the seven segment display on both side A (If you want to set it for the other side use the function setGoalB())
*/
void setGoalA() {
  Serial.print(goalA);
  //reset goals if 10 or higher is reached
  if (goalA >= 10 ) {
    goalA = 0;
  }
  switch (goalA) {
    case 0: setZero(0);
      break;
    case 1: setOne(0);
      break;
    case 2: setTwo(0);
      break;
    case 3: setTree(0);
      break;
    case 4: setFour(0);
      break;
    case 5: setFive(0);
      break;
    case 6: setSix(0);
      break;
    case 7: setSeven(0);
      break;
    case 8: setEight(0);
      break;
    case 9: setNine(0);
      break;
  }
}

/*
Set the goals on the seven segment display on both side B (If you want to set it for the other side use the function setGoalA())
*/
void setGoalB() {
  //reset goals if 10 or higher is reached
  if (goalB >= 10) {
    goalB = 0;
  }
  switch (goalB) {
    case 0: setZero(1);
      break;
    case 1: setOne(1);
      break;
    case 2: setTwo(1);
      break;
    case 3: setTree(1);
      break;
    case 4: setFour(1);
      break;
    case 5: setFive(1);
      break;
    case 6: setSix(1);
      break;
    case 7: setSeven(1);
      break;
    case 8: setEight(1);
      break;
    case 9: setNine(1);
      break;
  }
}

/* ############################### NUMBER DISPLAY SEVEN SEGMENT DISPLAY ############################################ */
//display on the seven segment display to the value zero (the point and the horizontal middle line will set off and get no current)
void setZero(int t) {
  if (t == 0){
  exp1.digitalWrite(0, LOW);
  exp1.digitalWrite(1, LOW);
  exp1.digitalWrite(2, LOW);
  exp1.digitalWrite(3, HIGH);
  exp1.digitalWrite(4, LOW);
  exp1.digitalWrite(5, LOW);
  exp1.digitalWrite(6, LOW);
  exp1.digitalWrite(7, HIGH);
  }
  if (t == 1){
  exp1.digitalWrite(8, HIGH);
  exp1.digitalWrite(9, LOW);
  exp1.digitalWrite(10, LOW);
  exp1.digitalWrite(11, HIGH);
  exp1.digitalWrite(12, LOW);
  exp1.digitalWrite(13, LOW);
  exp1.digitalWrite(14, LOW);
  exp1.digitalWrite(15, LOW);
  }
}

//display on the seven segment display to the value zero (the point and the horizontal middle line will set off and get no current)
void setOne(int t) {
  if (t == 0){
  exp1.digitalWrite(0, HIGH);
  exp1.digitalWrite(1, HIGH);
  exp1.digitalWrite(2, LOW);
  exp1.digitalWrite(3, HIGH);
  exp1.digitalWrite(4, LOW);
  exp1.digitalWrite(5, HIGH);
  exp1.digitalWrite(6, HIGH);
  exp1.digitalWrite(7, HIGH);
  }
  if (t == 1){
  exp1.digitalWrite(8, HIGH);
  exp1.digitalWrite(9, HIGH);
  exp1.digitalWrite(10, LOW);
  exp1.digitalWrite(11, HIGH);
  exp1.digitalWrite(12, HIGH);
  exp1.digitalWrite(13, LOW);
  exp1.digitalWrite(14, HIGH);
  exp1.digitalWrite(15, HIGH);
  }
}

void setTwo(int t) {
  if (t == 0){
  exp1.digitalWrite(0, LOW);
  exp1.digitalWrite(1, HIGH);
  exp1.digitalWrite(2, LOW);
  exp1.digitalWrite(3, LOW);
  exp1.digitalWrite(4, HIGH);
  exp1.digitalWrite(5, LOW);
  exp1.digitalWrite(6, LOW);
  exp1.digitalWrite(7, HIGH);
  }
  if (t == 1){
  exp1.digitalWrite(8, HIGH);
  exp1.digitalWrite(9, LOW);
  exp1.digitalWrite(10, HIGH);
  exp1.digitalWrite(11, LOW);
  exp1.digitalWrite(12, LOW);
  exp1.digitalWrite(13, LOW);
  exp1.digitalWrite(14, HIGH);
  exp1.digitalWrite(15, LOW);
  }
}

void setTree(int t) {
  if (t == 0){
  exp1.digitalWrite(0, LOW);
  exp1.digitalWrite(1, HIGH);
  exp1.digitalWrite(2, LOW);
  exp1.digitalWrite(3, LOW);
  exp1.digitalWrite(4, LOW);
  exp1.digitalWrite(5, HIGH);
  exp1.digitalWrite(6, LOW);
  exp1.digitalWrite(7, HIGH);
  }
  if (t == 1){
  exp1.digitalWrite(8, HIGH);
  exp1.digitalWrite(9, LOW);
  exp1.digitalWrite(10, LOW);
  exp1.digitalWrite(11, LOW);
  exp1.digitalWrite(12, HIGH);
  exp1.digitalWrite(13, LOW);
  exp1.digitalWrite(14, HIGH);
  exp1.digitalWrite(15, LOW);
  }
}

void setFour(int t) {
  if (t == 0){
  exp1.digitalWrite(0, HIGH);
  exp1.digitalWrite(1, LOW);
  exp1.digitalWrite(2, LOW);
  exp1.digitalWrite(3, LOW);
  exp1.digitalWrite(4, LOW);
  exp1.digitalWrite(5, HIGH);
  exp1.digitalWrite(6, HIGH);
  exp1.digitalWrite(7, HIGH);
  }
  if (t == 1){
  exp1.digitalWrite(8, HIGH);
  exp1.digitalWrite(9, HIGH);
  exp1.digitalWrite(10, LOW);
  exp1.digitalWrite(11, LOW);
  exp1.digitalWrite(12, HIGH);
  exp1.digitalWrite(13, LOW);
  exp1.digitalWrite(14, LOW);
  exp1.digitalWrite(15, HIGH);
  }
}

void setFive(int t) {
  if (t == 0){
  exp1.digitalWrite(0, LOW);
  exp1.digitalWrite(1, LOW);
  exp1.digitalWrite(2, HIGH);
  exp1.digitalWrite(3, LOW);
  exp1.digitalWrite(4, LOW);
  exp1.digitalWrite(5, HIGH);
  exp1.digitalWrite(6, LOW);
  exp1.digitalWrite(7, HIGH);
  }
  if (t == 1){
  exp1.digitalWrite(8, HIGH);
  exp1.digitalWrite(9, LOW);
  exp1.digitalWrite(10, LOW);
  exp1.digitalWrite(11, LOW);
  exp1.digitalWrite(12, HIGH);
  exp1.digitalWrite(13, HIGH);
  exp1.digitalWrite(14, LOW);
  exp1.digitalWrite(15, LOW);
  }
}

void setSix(int t) {
  if (t == 0){
  exp1.digitalWrite(0, LOW);
  exp1.digitalWrite(1, LOW);
  exp1.digitalWrite(2, HIGH);
  exp1.digitalWrite(3, LOW);
  exp1.digitalWrite(4, LOW);
  exp1.digitalWrite(5, LOW);
  exp1.digitalWrite(6, LOW);
  exp1.digitalWrite(7, LOW);
  }
  if (t == 1){
  exp1.digitalWrite(8, LOW);
  exp1.digitalWrite(9, LOW);
  exp1.digitalWrite(10, LOW);
  exp1.digitalWrite(11, LOW);
  exp1.digitalWrite(12, LOW);
  exp1.digitalWrite(13, HIGH);
  exp1.digitalWrite(14, LOW);
  exp1.digitalWrite(15, LOW);
  }
}

void setSeven(int t) {
  if (t == 0){
  exp1.digitalWrite(0, LOW);
  exp1.digitalWrite(1, HIGH);
  exp1.digitalWrite(2, LOW);
  exp1.digitalWrite(3, HIGH);
  exp1.digitalWrite(4, LOW);
  exp1.digitalWrite(5, HIGH);
  exp1.digitalWrite(6, HIGH);
  exp1.digitalWrite(7, HIGH);
  }
  if (t == 1){
  exp1.digitalWrite(8, HIGH);
  exp1.digitalWrite(9, HIGH);
  exp1.digitalWrite(10, LOW);
  exp1.digitalWrite(11, HIGH);
  exp1.digitalWrite(12, HIGH);
  exp1.digitalWrite(13, LOW);
  exp1.digitalWrite(14, HIGH);
  exp1.digitalWrite(15, LOW);
  }
}

void setEight(int t) {
  if (t == 0){
  exp1.digitalWrite(0, LOW);
  exp1.digitalWrite(1, LOW);
  exp1.digitalWrite(2, LOW);
  exp1.digitalWrite(3, LOW);
  exp1.digitalWrite(4, LOW);
  exp1.digitalWrite(5, LOW);
  exp1.digitalWrite(6, LOW);
  exp1.digitalWrite(7, HIGH);
  }
  if (t == 1){
  exp1.digitalWrite(8, HIGH);
  exp1.digitalWrite(9, LOW);
  exp1.digitalWrite(10, LOW);
  exp1.digitalWrite(11, LOW);
  exp1.digitalWrite(12, LOW);
  exp1.digitalWrite(13, LOW);
  exp1.digitalWrite(14, LOW);
  exp1.digitalWrite(15, LOW);
  }
}

void setNine(int t) {
  if (t == 0){
  exp1.digitalWrite(0, LOW);
  exp1.digitalWrite(1, LOW);
  exp1.digitalWrite(2, LOW);
  exp1.digitalWrite(3, LOW);
  exp1.digitalWrite(4, LOW);
  exp1.digitalWrite(5, HIGH);
  exp1.digitalWrite(6, LOW);
  exp1.digitalWrite(7, LOW);
  }
  if (t == 1){
  exp1.digitalWrite(8, LOW);
  exp1.digitalWrite(9, LOW);
  exp1.digitalWrite(10, LOW);
  exp1.digitalWrite(11, LOW);
  exp1.digitalWrite(12, HIGH);
  exp1.digitalWrite(13, LOW);
  exp1.digitalWrite(14, LOW);
  exp1.digitalWrite(15, LOW);
  }
}
