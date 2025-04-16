#include <SoftwareSerial.h>
int M2PWM = 5;
int M2DIR = 4;
int M1PWM = 3;
int M1DIR = 2;
SoftwareSerial bt(0,1);

void move_dung(){
  digitalWrite (M1DIR, 1);
  analogWrite (M1PWM, 0);
  digitalWrite (M2DIR, 1);
  analogWrite (M2PWM, 0);
}
void move_tien(){
  digitalWrite (M1DIR, 1);
  analogWrite (M1PWM, 255);
  digitalWrite (M2DIR, 1);
  analogWrite (M2PWM, 255);
}
void move_phai(){
  digitalWrite (M1DIR, 1);
  analogWrite (M1PWM, 255);
  digitalWrite (M2DIR, 0);
  analogWrite (M2PWM, 255);
}
void move_lui(){
  digitalWrite (M1DIR, 0);
  analogWrite (M1PWM, 255);
  digitalWrite (M2DIR, 0);
  analogWrite (M2PWM, 255);
}
void move_trai(){
  digitalWrite (M1DIR, 0);
  analogWrite (M1PWM, 255);
  digitalWrite (M2DIR, 1);
  analogWrite (M2PWM, 255);
}
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  bt.begin(9600);
  Serial.begin(9600);
  }

void loop() {
  if (bt.available())
  {
    int a = bt.read();
    Serial.println(a);
    switch(a){
      case 0:
        move_dung();
        break;
      case 1:
        move_tien();
        break;
      case 2:
        move_phai();
        break;
      case 3:
        move_lui();
        break;
      case 4:
        move_trai();
        break;
      
      }
    
}}
