// C++ code
//
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  if (digitalRead(13) == 1) {
    if (0.01723 * readUltrasonicDistance(11, 11) < 100 && 0.01723 * readUltrasonicDistance(11, 11) > 20) {
      digitalWrite(12, HIGH);
    } else {
      digitalWrite(12, LOW);
    }
  } else {
    digitalWrite(12, LOW);
  }

  if (digitalRead(13) == 1) {
    if (0.01723 * readUltrasonicDistance(11, 11) < 100 && 0.01723 * readUltrasonicDistance(11, 11) > 20) {
      digitalWrite(7, HIGH);
      delay(200); // Wait for 200 millisecond(s)
      digitalWrite(7, HIGH);
      delay(200); // Wait for 200 millisecond(s)
    } else {
      digitalWrite(7, LOW);
    }
  } else {
    digitalWrite(7, LOW);
  }

  if (digitalRead(13) == 1) {
    if (0.01723 * readUltrasonicDistance(11, 11) < 100 && 0.01723 * readUltrasonicDistance(11, 11) > 20) {
      digitalWrite(8, LOW);
    } else {
      digitalWrite(8, HIGH);
    }
  } else {
    digitalWrite(8, LOW);
  }
}
