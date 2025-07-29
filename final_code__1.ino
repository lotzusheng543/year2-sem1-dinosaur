#include <Stepper.h>
#include <Servo.h>
   Servo mouth_servo;
   Servo neck_servo;

// Pin definitions
#define photor_resistor1 A1
#define photor_resistor2 A2
#define mouth_LDR A0
#define echoPin 2
#define trigPin 3
#define redLED 11
#define C41 262  //1 Do
#define D41 294  //2 Re
#define E41 330  //3 Mi
#define F41 349  //4 Fa
#define G41 392  //5 Sol
#define G42 415  //#5 #Sol
#define A41 440  //6 La
#define B41 494  //7 Si
#define C51 523  //1 Do_h
#define D51 587  //2 Re_h
#define D52 622  //#2 #Re_h
#define E51 659  //3 Mi_h
#define F51 698  //4 Fa_h
#define G51 784  //5 Sol_h
#define A51 880  //6 La_h
#define B51 988  //7 Si_h
#define O1 000  //休止符

int angle_mouth = 90;
int angle_neck = 90;
int LDR_left;
int LDR_right;
int mouth_R;
int n_red = 255;
int counter_mouth = 0;
int buzzer=4;
int scale[]={E51,D52,E51,D52,E51,B41,D51,C51,A41,O1,E41,A41,B41}; //input
int time[]={1,1,1,1,1,1,1,1,3,0,1,1,3};
int length;

// Motor setup
const int stepsPerRevolution = 2048;
Stepper myStepper = Stepper(stepsPerRevolution, 7, 12, 8, 13);

// Variables
long duration;  
float distance;   

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  //Set initial angle for mouth and neck
  neck_servo.attach(9);
  neck_servo.write(angle_neck);
  mouth_servo.attach(10);
  mouth_servo.write(angle_mouth);

  //Serial.println("Ultrasonic Sensor HC-SR04 Test");
  //Serial.println("with Arduino UNO R3");
  Serial.println("Setup completed");
  length=sizeof(scale)/sizeof(scale[0]);  //Obtain length of array of music
}

void loop() {
  myStepper.setSpeed(15);
  ultrasonic();
  LDR_left = analogRead(A1);
  LDR_right = analogRead(A2);
  mouth_R = analogRead(A0);
  //Serial.println(LDR_left);
  Serial.println(mouth_R);
  //Serial.println(counter_mouth);

  //biting action
  if (mouth_R < 60){

    mouth_servo.write(65);
    counter_mouth += 2 ; //an increasing variable over time
    if (counter_mouth > 60){
      
      for(int i=0;i<length;i++){
        tone(buzzer,scale[i]);
 
        if(time[i]>0)                        //Determine the situation(got music)
          delay(time[i]*250);
        else{                                 //Determine the situation(without music)
          noTone(buzzer);
          delay(250);
        }
      noTone(buzzer);
      delay(0);
      }
    delay(100);
    mouth_servo.write(90);
    counter_mouth = 0;
    }    
  }
  else{
    counter_mouth = 0;
    mouth_servo.write(90);
  }

  //curiosity (move forward)
  if (distance <= 50 && distance > 32.5) {
    blinkDistance();
    myStepper.step(25);
  } 
  //curiosity (move backward)
  else if (distance >= 20 && distance < 30) {
    blinkDistance();
    myStepper.step(-25);
  } 
  //fear (move backward)
  else if (distance <10){
    blinkDistance();
    myStepper.step(-25);
  }
  else {
    blinkDistance();
    //noTone(buzzerPin);
    myStepper.step(0);

    //neck turn right
    if(LDR_left > 115 + LDR_right && angle_neck < 115){
    angle_neck++;
    neck_servo.write(angle_neck);
    delay(20);
    } 

    //neck turn left
    if(LDR_right > 115 + LDR_left  && angle_neck > 70){
    angle_neck--;
    neck_servo.write(angle_neck);
    delay(20);
    }
    //Serial.println(angle_neck);
  }
}

// Ultrasonic sensor function
void ultrasonic() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sends the ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin and calculates distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2;

  // Displays the distance on Serial Monitor
  //Serial.print("Distance: ");
  //Serial.print(distance);
  //Serial.println(" cm");
}

//LED dim according to different state
void blinkDistance() 
{
  if (n_red > 5)
  {
    analogWrite(redLED, max(n_red, 0));
    if (distance < 10) {
      n_red /= 2.5; //dim faster
    }
    else if (distance >= 20 && distance <= 30) {
      n_red /= 1.5; //dim slower
    }
    else if (distance >= 32 && distance <= 40) {
      n_red /= 1.5;
    }    
    else {
      n_red = 255; //always on
    }
  } 
  else
  {
    analogWrite(redLED, 0); // Turn off
    delay(50);
    n_red = 255;
  }
}