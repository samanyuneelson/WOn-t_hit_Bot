const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
//L293D
//Motor A
const int motorPin1 = 9;
const int motorPin2 = 10;
//Motor B
const int motorPin3 = 11;
const int motorPin4 = 12;

void setup() {
    Serial.begin(9600); // Starting Serial Terminal  

}

void loop() {
  long duration, inches, cm;
   pinMode(motorPin1, OUTPUT);
   pinMode(motorPin2, OUTPUT); 
   pinMode(motorPin3, OUTPUT);
   pinMode(motorPin4, OUTPUT);   
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);

   if (cm >= 10){
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);     //forward
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
    }
   else {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);     //stop
      digitalWrite(motorPin4, LOW);
      delay(500);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);    //backward
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
      delay(2000);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);     //righturn
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
      delay(1000);
    }
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
