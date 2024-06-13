/*
    Project name : Color Sensor
    Modified Date: 13-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-color-sensor
*/

// Define pins connected to the color sensor
const int S0 = 3;
const int S1 = 4;
const int sensorOut = 2;

// Variables to store color readings
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set control pins as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);

  // Set OUT pin as input
  pinMode(sensorOut, INPUT);

  // Set frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Initialize color sensor
  delay(100); // Allow sensor to stabilize
}

void loop() {
  // Select red color filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // Read red component
  redValue = pulseIn(sensorOut, LOW);

  // Select green color filter
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  // Read green component
  greenValue = pulseIn(sensorOut, LOW);

  // Select blue color filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  // Read blue component
  blueValue = pulseIn(sensorOut, LOW);

  // Print RGB values to Serial Monitor
  Serial.print("Red: ");
  Serial.print(redValue);
  Serial.print(" - Green: ");
  Serial.print(greenValue);
  Serial.print(" - Blue: ");
  Serial.println(blueValue);

  delay(1000); // Delay before next reading
}
