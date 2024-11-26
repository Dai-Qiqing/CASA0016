#include <Metro.h>
#include <math.h>
#include <Adafruit_NeoPixel.h>

#define PIN1 6 
#define PIN2 9 
#define NUMPIXELS 12
#define PIR_PIN 5

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);

Metro ledlightup = Metro(60, true);
Metro processdata = Metro(50, true);
Metro TcsTrigger = Metro(10, true);

int s0 = 8, s1 = 9, s2 = 10, s3 = 11;
int out = 2;
int flag = 0;
int counter = 0;
int countR = 0, countG = 0, countB = 0;

bool humanDetected = false;

void setup() {
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(PIR_PIN, INPUT);

  strip1.begin();
  strip1.show();
  strip2.begin();
  strip2.show();
}

void TCS() {
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  attachInterrupt(0, ISR_INTO, CHANGE);
}

void ISR_INTO() {
  counter++;
}

int Raverage = 0;
int Baverage = 0;
int Gaverage = 0;

void loop() {
  TCS();
  humanDetected = digitalRead(PIR_PIN);

  if (TcsTrigger.check()) {
    Tcstrigger();
  }
  if (processdata.check()) {
    procedata();
  }
  if (ledlightup.check()) {
    ledup();
  }
}

void Tcstrigger() {
  flag++;
  if (flag == 1) {
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    countR = counter;
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
  } else if (flag == 2) {
    countG = counter;
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
  } else if (flag == 3) {
    countB = counter;
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    flag = 0;
  }
  counter = 0;
}

void procedata() {
  static int Rinput[5] = {0, 0, 0, 0, 0}, Binput[5] = {0, 0, 0, 0, 0}, Ginput[5] = {0, 0, 0, 0, 0};

  for (int i = 4; i > 0; i--) {
    Rinput[i] = Rinput[i - 1];
    Binput[i] = Binput[i - 1];
    Ginput[i] = Ginput[i - 1];
  }

  if (countR < 2500)
    Rinput[0] = countR;
  else
    Rinput[0] = Rinput[1];

  if (countB < 2500)
    Binput[0] = countB;
  else
    Binput[0] = Binput[1];

  if (countG < 2500)
    Ginput[0] = countG;
  else
    Ginput[0] = Ginput[1];

  Raverage = 0;
  Baverage = 0;
  Gaverage = 0;

  for (int i = 0; i <= 4; i++) {
    Raverage += Rinput[i];
    Baverage += Binput[i];
    Gaverage += Ginput[i];
  }
  Raverage /= 5;
  Baverage /= 5;
  Gaverage /= 5;
}

void ledup() {
  if (humanDetected) {
    int ledvalueR = Raverage;
    int ledvalueG = Gaverage;
    int ledvalueB = Baverage;

    ledvalueR = constrain(ledvalueR, 350, 1700);
    ledvalueB = constrain(ledvalueB, 350, 1500);
    ledvalueG = constrain(ledvalueG, 350, 1650);
    ledvalueR = map(ledvalueR, 350, 1700, 0, 255);
    ledvalueB = map(ledvalueB, 350, 1500, 0, 255);
    ledvalueG = map(ledvalueG, 350, 1650, 0, 255);


    int brightness = 150; 
    for (int i = 0; i < NUMPIXELS; i++) {
      strip1.setPixelColor(i, strip1.Color((ledvalueR * brightness) / 255, 
                                           (ledvalueG * brightness) / 255, 
                                           (ledvalueB * brightness) / 255));
    }
    for (int i = 0; i < NUMPIXELS; i++) {
      int reverseR = 255 - ledvalueR;
      int reverseG = 255 - ledvalueG;
      int reverseB = 255 - ledvalueB;

      strip2.setPixelColor(i, strip2.Color((reverseR * brightness) / 255, 
                                           (reverseG * brightness) / 255, 
                                           (reverseB * brightness) / 255));
    }

    strip1.show();
    strip2.show();
  } else {
    for (int i = 0; i < NUMPIXELS; i++) {
      strip1.setPixelColor(i, 0);
      strip2.setPixelColor(i, 0);
    }
    strip1.show();
    strip2.show();
  }
}