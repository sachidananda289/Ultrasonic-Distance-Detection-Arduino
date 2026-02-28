#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int echo = 13;
const int trig = 12;

const int LED1 = 8;
const int LED2 = 7;
const int LED3 = 6;
const int LED4 = 5;
const int LED5 = 4;
const int LED6 = 3;
const int LED7 = 2;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  delay(100);//Small delay to ensure LCD is ready

  lcd.setCursor(0, 0);
  lcd.print("WELCOME TO");
  lcd.setCursor(0, 1);
  lcd.print("SSSINVENTIONS");
  delay(2000);
  lcd.clear();

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 28.5;
  Serial.println(distance);

  lcd.clear();//Clear the LCD screen
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(10, 0);
  lcd.print(distance);
  lcd.print("cm");

  if ( distance <= 7 )
  {
    digitalWrite(LED1, HIGH);
  } 
  else
  {
    digitalWrite(LED1, LOW);
  }
  if ( distance <= 14 )
  {
    digitalWrite(LED2, HIGH);
  } 
  else
  {
    digitalWrite(LED2, LOW);
  }
  if ( distance <= 21 )
  {
    digitalWrite(LED3, HIGH);
  } 
  else
  {
    digitalWrite(LED3, LOW);
  }
  if ( distance <= 28 )
  {
    digitalWrite(LED4, HIGH);
  } 
  else
  {
    digitalWrite(LED4, LOW);
  }
  if ( distance <= 35 )
  {
    digitalWrite(LED5, HIGH);
  } 
  else
  {
    digitalWrite(LED5, LOW);
  }
  if ( distance <= 42 )
  {
    digitalWrite(LED6, HIGH);
  } 
  else
  {
    digitalWrite(LED6, LOW);
  }
  if ( distance <= 49 )
  {
    digitalWrite(LED7, HIGH);
  } 
  else
  {
    digitalWrite(LED7, LOW);
  }
  delay(500);
}
