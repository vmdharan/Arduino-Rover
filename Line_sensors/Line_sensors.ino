#include <LiquidCrystal.h>

// Initialise the LCD display - set up pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Line sensor 1
int s1g = 38; // Sensor 1 Ground
int s1v = 40; // Sensor 1 Vcc
int s1 = 42;  // Sensor 1 Output

// Line sensor 2
int s2g = 39; // Sensor 2 Ground
int s2v = 41; // Sensor 2 Vcc
int s2 = 43;  // Sensor 2 Output

// Initial setup
void setup() {
  // Sensor 1 initialisation.
  pinMode(s1, INPUT);
  pinMode(s1g, OUTPUT);
  pinMode(s1v, OUTPUT);

  // Sensor 2 initialisation.
  pinMode(s2, INPUT);
  pinMode(s2g, OUTPUT);
  pinMode(s2v, OUTPUT);

  // Initialise number of characters and lines for LCD.
  lcd.begin(16, 2);

  // Print on first line.
  lcd.print("Line Sensors");
}

// Main execution loop
void loop() {
  // Get the right-side sensor value.
  digitalWrite(s1g, LOW);
  digitalWrite(s1v, HIGH);
  int R_val = digitalRead(s1);

  // Get the left-side sensor value.
  digitalWrite(s2g, LOW);
  digitalWrite(s2v, HIGH);
  int L_val = digitalRead(s2);

  // Display the sensor output on the LCD display.
  // Output '1' when sensor is over a dark surface.
  // Output '0' when sensor is over a light surface.
  lcd.setCursor(0, 2);
  lcd.print("  R:");
  lcd.print(R_val);
  lcd.print("  L:");
  lcd.print(L_val);

  // Delay before running the next loop.
  delay(50);
}
