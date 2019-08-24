//L293D
//Motor A
const int motorPin1 = 9;
const int motorPin2 = 10;

void setup() {
  //Set pins as output
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);  
    //This code  will turn Motor A clockwise for 2 sec.
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(2000);
    digitalWrite(motorPin1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
