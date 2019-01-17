/*******************************************************************************
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTY AND SUPPORT
 * IS APPLICABLE TO THIS SOFTWARE IN ANY FORM. CYTRON TECHNOLOGIES SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL
 * DAMAGES, FOR ANY REASON WHATSOEVER.
 ********************************************************************************
 * DESCRIPTION:
 *
 * This example shows how to drive a motor using the PWM and DIR pins.
 * This example only shows how to drive a single motor for simplicity.
 * For dual channel motor driver, both channel work the same way.
 * 
 * Open the Serial Monitor and select 9600 baud.
 * Send the corresponding number to control the motor.
 * 
 * 
 * CONNECTIONS:
 * 
 * Arduino D3  - Motor Driver PWM Input
 * Arduino D4  - Motor Driver DIR Input
 * Arduino GND - Motor Driver GND
 *
 *
 * AUTHOR   : Kong Wai Weng
 * COMPANY  : Cytron Technologies Sdn Bhd
 * WEBSITE  : www.cytron.io
 * EMAIL    : support@cytron.io
 *
 *******************************************************************************/


// Define the pin number.
const int pwmPin = 3;   // PWM is connected to pin 3.
const int dirPin = 4;   // DIR is connected to pin 4.



// The setup routine runs once when you press reset.
void setup() {
  // Set the PWM and DIR pins as outputs.
  pinMode(pwmPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // Set the PWM and DIR pins to 0.
  analogWrite(pwmPin, 0);
  digitalWrite(dirPin, LOW);

  // Initialize the serial port.
  Serial.begin(9600);

  // Draw a menu on the serial port.
  // We only do it once.
  Serial.println( "-----------------------------" );
  Serial.println( "MENU:"              );
  Serial.println( "1) Forward (Fast)"  );
  Serial.println( "2) Forward (Slow)"  );
  Serial.println( "3) Brake"           );
  Serial.println( "4) Backward (Slow)" );
  Serial.println( "5) Backward (Fast)" );
  Serial.println( "-----------------------------" );
}



// The loop routine runs over and over again forever.
void loop() {
  
  // Wait until a character is received from the serial port.
  while( !Serial.available() );

  // Read the received character.
  byte c = Serial.read();
  
  // Drive the motor based on the character received.
  switch( c ) {
    case '1':
      Serial.println( "Forward (Fast)" );
      digitalWrite( dirPin, LOW );    // Set the direction to forward.
      analogWrite( pwmPin, 255 );     // Set the motor speed to 100%.
      break;
      
    case '2':
      Serial.println( "Forward (Slow)" );
      digitalWrite( dirPin, LOW );    // Set the direction to forward.
      analogWrite( pwmPin, 128 );     // Set the motor speed to 50%.
      break;

    case '3':
      Serial.println( "Brake" );
      analogWrite( pwmPin, 0 );       // Set the motor speed to 0. Direction doesn't matter here.
      break;

    case '4':
      Serial.println( "Backward (Slow)" );
      digitalWrite( dirPin, HIGH );   // Set the direction to backward.
      analogWrite( pwmPin, 128 );     // Set the motor speed to 50%.
      break;

    case '5':
      Serial.println( "Backward (Fast)" );
      digitalWrite( dirPin, HIGH );   // Set the direction to backward.
      analogWrite( pwmPin, 255 );     // Set the motor speed to 100%.
      break;

    case '\r':
      // Ignore the carriage return character.
      break;

    case '\n':
      // Ignore the line feed character.
      break;

    default:
      Serial.println( "Invalid Input" );
      break;
  }
  
}
