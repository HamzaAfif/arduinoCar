#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include<NewPing.h> 
char incomingByte;
int enA = 2;
int in1 = 3;
int in2 = 4;
int ledPin = 8;
int enB = 7;
int in3 = 5;
int in4 = 6;
NewPing sonar(A0, A1, 30);

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above
LiquidCrystal_I2C lcd(0x3F, 16, 2);
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
byte UID[4] = {0xC7, 0x8D, 0xE2, 0x2B};

void setup() {
  Serial.begin(9600);  // initialize serial communication at 9600 baud
  delay(50);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  lcd.begin();
  lcd.backlight();
  SPI.begin();		// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);
  Serial.println(F("Scan PICC to see UID..."));
  lcd.print("Scan your key ");
 
  } 
  void av(){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW); 
  }
  void ar(){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(30);
      digitalWrite(ledPin, LOW);
  }
  void ga(){
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       digitalWrite(in3, LOW);
       digitalWrite(in4, LOW);
  }
  void dr(){
       digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);
       digitalWrite(in3, HIGH);
       digitalWrite(in4, LOW);
  }
  void sto(){
      digitalWrite(in1, LOW); 
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
  }


void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;}
	if ( ! mfrc522.PICC_ReadCardSerial()) {
	return;}
  if(mfrc522.uid.uidByte[0] == UID[0] && mfrc522.uid.uidByte[1] == UID[1] && mfrc522.uid.uidByte[2] == UID[2] && mfrc522.uid.uidByte[3] == UID[3] ){
    lcd.clear();
    lcd.print("Bienvenue a HEM");
    if(Serial.available()) {
    lcd.print("Test conexion");
    delay(1000);
    lcd.clear();
    incomingByte = Serial.read();  // read the incoming byte from Bluetooth
    if (incomingByte == 'F') {  // if the incoming byte is '1'
      av();
    }
    else if (incomingByte == 'B') {  // if the incoming byte is '0'
      ar();
    }
    else if (incomingByte == 'S'){
      sto();
    }
    else if (incomingByte == 'L'){ 
      ga();
    }
    else if (incomingByte == 'R'){ 
      dr(); 
    }
  }
  }else {
    lcd.clear();
    lcd.print("Pas la bonne cle");
    delay(4000);
  }
  }
