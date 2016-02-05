#include <LiquidCrystal.h>

// Initialise the LCD display - set up pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Accelerometer pins
int xpin = 28;
int ypin = 26;
int zpin = 24;
int GND_pin = 22;
int VCC_pin = 30;

// Calibration variables
int xCal = 512;
int yCal = 512;
int zCal = 512;

// Initial setup
void setup() {
  // Accelerometer initialisation.
  pinMode(GND_pin, OUTPUT);
  pinMode(VCC_pin, OUTPUT);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(zpin, INPUT);

  // Power on the accelerometer.
  digitalWrite(GND_pin, LOW);
  digitalWrite(VCC_pin, HIGH);

  // Initialise number of characters and lines for LCD.
  lcd.begin(16, 2);

  // Print on first line.
  lcd.print("Accelerometer");

  // Calibrate accelerometer.
  // To do.
}

// Main execution loop
void loop() {
  // Print on first line.
  lcd.print("Accelerometer");
  
  // Get the sensor values.
  int Xval = analogRead(xpin);
  int Yval = analogRead(ypin);
  int Zval = analogRead(zpin);

  // Display the sensor output on the LCD display.
  lcd.setCursor(0, 2);
  lcd.print(Xval);
  lcd.print("  ");
  lcd.print(Yval);
  lcd.print("  ");
  lcd.print(Zval);

  // Delay before running the next loop.
  delay(1000);

  lcd.clear();
}
