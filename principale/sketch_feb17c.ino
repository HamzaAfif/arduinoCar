#include <NewPing.h>
char incomingByte;

//moto 1
int enA = 3;
int in1 = 2;
int in2 = 4;
//moto 2
int enB = 6;
int in3 = 5;
int in4 = 7;

NewPing sonar(A0, A1, 20);

void setup() {
  Serial.begin(9600);
  delay(50);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
}
void f(){
  if (sonar.ping_cm() >= 1 && sonar.ping_cm() <5){
    s();
    digitalWrite(8, HIGH);
    delay(200);
    digitalWrite(8, LOW);
    b();
    delay(500);
    s();
  }
  else {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  }}
void b(){ 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(9, 255);
  digitalWrite(8, HIGH);
  delay(20);
  digitalWrite(9, 0);
  digitalWrite(8, LOW);}
void r(){  
  digitalWrite(in1,HIGH ); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);}
void l(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);}
void s(){ 
  digitalWrite(in1, LOW); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);}

void loop() {
  while(Serial.available()){
    incomingByte = Serial.read();
    if(digitalRead(12) == HIGH){
    digitalWrite(13, HIGH);
    digitalWrite(8, HIGH);
    }
    else if (incomingByte == 'F') { 
    f();
    digitalWrite(8, LOW);
    digitalWrite(13, LOW);
    }
    else if (incomingByte == 'B') {  
    b();
    }
    else if (incomingByte == 'S'){
    s();
    }
    else if (incomingByte == 'L'){ 
    r();
    }
    else if (incomingByte == 'R'){ 
    l(); 
    }
    else if (incomingByte == 'W'){
    digitalWrite(13, HIGH);
    }
    else if(incomingByte == 'w'){
    digitalWrite(13, LOW);
    }
    else if(incomingByte == 'V'){
    digitalWrite(8, HIGH);
    }
    else if(incomingByte == 'v'){
    digitalWrite(8, LOW);
    }
    else if(incomingByte == 'U'){
    digitalWrite(9, 255);
    }
    else if(incomingByte == 'u'){
    digitalWrite(9, 0);
    }
    else if(incomingByte == '0'){
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    }
    else if (incomingByte == '1' || incomingByte == '2'){
    analogWrite(enA, 75);
    analogWrite(enB, 80);
    }
    else if(incomingByte == '3' || incomingByte == '4'){
    analogWrite(enA, 85);
    analogWrite(enB, 110);
    }
    else if (incomingByte == '5' || incomingByte == '6'){
    analogWrite(enA, 155);
    analogWrite(enB, 160);
    }
    else if(incomingByte == '7' || incomingByte == '8'){
    analogWrite(enA, 195);
    analogWrite(enB, 200);
    }
    else if (incomingByte == '9' || incomingByte == 'q'){
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    }
  }
}
