/*        KONTROL  BIEGONKORRA (Sakatzaile 1)

  Debounce metodoa aplikatu zaio zarata elektrikoa ekiditeko.
  created 21 Nov 2006 by David A. Mellis
  modified 20 sep 2018 by Axpi
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Debounce
*/
// Aldagaiak definitu
const int buttonPinA = 2;
const int buttonPinB = 3;
const int buttonPinC = 5;

const int ledPin = 13;
const int ledPinA = 12;
const int ledPinB = 11;
const int ledPinC = 10;



int ledStateA = HIGH; // LED-aren hasierako balioa
int ledStateB = HIGH; // LED-aren hasierako balioa
int ledStateC = HIGH; // LED-aren hasierako balioa
int ledState = LOW; //LED-aren hasierako balioa
int buttonStateA; // Sakatzailearen oraingo egoera
int buttonStateB; // Sakatzailearen oraingo egoera
int buttonStateC; // Sakatzailearen oraingo egoera

int lastButtonStateA = HIGH; // Sakatzailearen aurreko egoera
int lastButtonStateB = HIGH; // Sakatzailearen aurreko egoera
int lastButtonStateC = HIGH; // Sakatzailearen aurreko egoera


// DEBOUNCE denborak.
unsigned long lastDebounceTime = 0; // Lehen aldiz sakatua
unsigned long debounceDelay = 50; // Debounce denbora.

void setup() {
  Serial.begin(9600); // Serie komunikazioa martxan jarri.
  pinMode(buttonPinA, INPUT);
  pinMode(buttonPinB, INPUT);
  pinMode(buttonPinC, INPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinC, OUTPUT);

  digitalWrite(ledPin, ledState);
  digitalWrite(ledPinA, ledStateA);
  digitalWrite(ledPinB, ledStateB);
  digitalWrite(ledPinC, ledStateC);

  Serial.print("Sakatzailea sakatu zain...........");
}

void loop() {
  int readingA = digitalRead(buttonPinA);
  int readingB = digitalRead(buttonPinB);
  int readingC = digitalRead(buttonPinC);

  if (readingA != lastButtonStateA) { //Sakatzailea sakatu
    lastDebounceTime = millis();   //Timerra inizializatu
  }
  if (readingB != lastButtonStateB) { //Sakatzailea sakatu
    lastDebounceTime = millis();   //Timerra inizializatu
  }
  if (readingC != lastButtonStateC) { //Sakatzailea sakatu
    lastDebounceTime = millis();   //Timerra inizializatu
  }


  // Botoiaren egoera aldatu baldin bada:
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (readingA != buttonStateA) {  // Botoia aldatu bada
      buttonStateA = readingA; // Balioak eguneratu
      if (buttonStateA == HIGH) {//LED-a HIGH bada soilik
        ledStateA = !ledStateA;
        Serial.print("A BOTOIA: ");
        Serial.println(ledStateA);
      }
    }
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (readingB != buttonStateB) {  // Botoia aldatu bada
      buttonStateB = readingB; // Balioak eguneratu
      if (buttonStateB == HIGH) {//LED-a HIGH bada soilik
        ledStateB = !ledStateB;
        Serial.print("B BOTOIA-a: ");
        Serial.println(ledStateB);
      }
    }
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (readingC != buttonStateC) {  // Botoia aldatu bada
      buttonStateC = readingC; // Balioak eguneratu
      if (buttonStateC == HIGH) {//LED-a HIGH bada soilik
        ledStateC = !ledStateC;
        Serial.print("C BOTOIA-a: ");
        Serial.println(ledStateC);
      }
    }
  }

  digitalWrite(ledPinA, ledStateA); // LED-a freskatu
  digitalWrite(ledPinB, ledStateB); // LED-a
  digitalWrite(ledPinC, ledStateC); // LED-a

  if (ledStateA == 1 && ledStateB == 1 && ledStateC == 1) { //A-B-C Botoiak aktibatuta badaude Led-a piztutzen da
    Serial.println("ITZALI");
    digitalWrite(ledPin, HIGH);
  }
  else {
    Serial.println("PIZTU"); // A-B-C Botoiak desaktibatuta badaude Led-a itzali egiten da
    digitalWrite(ledPin, LOW);
  }

  lastButtonStateA = readingA; // Balioak eguneratu
  lastButtonStateB = readingB; // Balioak eguneratu
  lastButtonStateC = readingC; // Balioak eguneratu
}
