#include <Servo.h> 
Servo arm;
Servo spin;
int armpos =10;
int bag =0;
Servo pully;
int bagpull = 0;
int milkpull = 0;
int sugarpull = 0;
int made = 1;
Servo milk;
int milkpos;
Servo spoon;
int spoonpos;
int shake;
int spoonset;
int startbutt;


void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
pinMode(4,INPUT);
digitalWrite(5,HIGH);
pully.attach(9);
pully.write(90);
arm.attach(A1);
spin.attach(12);
arm.write(25);
milk.attach(A2);
milkpos = 0;
milk.write(5);
spoon.attach(A3);
spoonpos=10;
spoon.write(spoonpos);
spoonset = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  startbutt = digitalRead(4); // read input value
  if (startbutt == LOW) {// check if the input is HIGH
    delay(1000);
    made = 0;

}
 while(made<1){
 pour();
 pullone();
 teadunk();
 pulltwo();
 splash();
 pullthree();
 honey();
 reset();
 made = 1;
}

}


void pour()
{
 digitalWrite(5, LOW);
 delay(200000);
 digitalWrite(5,HIGH);
 delay(1000);
}

void pullone(){
    while(bagpull<1){ 
    uint32_t period = 48 * 100L;       // 5 minutes
    for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){
    pully.write(60);
    }
    pully.write(90);
    bagpull = 1;
}
}

void teadunk(){
  while (bag<1){ 
  for (armpos >= 25; armpos <= 90; armpos += 1) {
  arm.write(armpos);
  delay(20);
  }
  spin.write(45);
  delay(90000);
  spin.write(90);
  
  for (armpos <= 90; armpos >= 25; armpos -= 1) {
  arm.write(armpos);
  delay(20);
  bag = 1;
  }
}
}


void pulltwo(){
    while(milkpull<1){ 
    uint32_t period = 42 * 100L;       // 5 minutes
    for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){
    pully.write(60);
    }
    pully.write(90);
    milkpull = 1;
  
}
}

void splash() {
  for (milkpos >= 25; milkpos <= 120; milkpos += 1) {
  milk.write(milkpos);
  delay(5);
}
delay(10000);
}

void pullthree(){
  while(sugarpull<1){ 
    uint32_t period = 43 * 100L;       // 5 minutes
    for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){
    pully.write(60);
    }
    pully.write(90);
    sugarpull = 1;
  
}
}

void honey() {
while (spoonset<1){
    for (spoonpos >= 0; spoonpos <= 140; spoonpos += 1) {
    spoon.write(spoonpos);
    delay(40);
    }
 spoonset = 1;
}  
while (shake<30){ 
  for (spoonpos >= 0; spoonpos <= 140; spoonpos += 1) {
  spoon.write(spoonpos);
  delay(1);
  }
  
  for (spoonpos <= 140; spoonpos >= 95; spoonpos -= 1) {
  spoon.write(spoonpos);
  delay(1);

  }
    shake += 1;
}
spoon.write(0);
}

void reset(){
    spoonpos=10;
    spoon.write(spoonpos);
    spoonset = 0;
    milkpos = 0;
    milk.write(0);
    arm.write(25);
    pully.write(90);
    bagpull = 0;
    milkpull = 0;
    sugarpull = 0;
    armpos =10;
    bag =0;
    shake=0;
}
