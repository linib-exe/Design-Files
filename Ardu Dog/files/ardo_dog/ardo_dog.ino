/*
Ardo_Dog sketch
 
 An experiment on making AI.
 
 The construction move around based on random numbers and inputs based on its movment and its surroundings.
 The construction are made up of 10, 9g servo's that operate the legs, tail and head. Eatch leg gets operated by 2 servo's.
 On the back side of the construction the tail uses 1 sero that is traying to balance up the robot when it walks.
 To do this the arduino uses a gyroscope(MPU-6050).
 The robot has a head that is connected to a servo so it can turn at least 180 degrees. On the front of the head there is a ultrasound 
 sensor(HC-SR04) that is used to tell the robot what is in front of it and on it sides(90 degrees from center front). 
 The readings from the ultrasonic sensor and the choices the robot makes are all saved on to a SD-card. For this a use a SCA-1709 SD-card module. 
 
 */

#include <Servo.h>
#include <Wire.h>
#include <SD.h>


// #define, constants through out the program

#define trigerPIN 8
#define echoPIN 9


// General global variables

static boolean hasDoneStartUp = true; // Is global so other functions can see if its first time runing
const int MPU = 0x68;  // I2C address of the MPU-6050
const int SD_Pin = 10; // SPI
int distaWalk; //Distance to walk, value from sight, is being used in walkRandom(), and loop()

int infoDistance[5]; // array where the distance and decition on where to move is stored before its taken to the SD card, used in walkRandom() and loop()

// Servo object's

Servo servoFrontRT; //Servo on Front Right Tigh,
Servo servoFrontLT; //and so on.
Servo servoBackRT;
Servo servoBackLT;
Servo servoFrontRL;//Servo on Front Right Leg,
Servo servoFrontLL;//and so on.
Servo servoBackRL;
Servo servoBackLL;
Servo servoTail;
Servo servoHead;

void setup()
{

  //For testing, Serial output, if use balance()
  //Serial.begin(9600);

  //MPU-6050 setup
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);

  // SCA-1709 SD module
  pinMode(SD_Pin, OUTPUT);

  //Connecting servo's to servo object
  servoFrontRT.attach(2,501,2400);
  servoFrontLT.attach(3,501,2400);
  servoBackRT.attach(4,501,2400);
  servoBackLT.attach(5,501,2400);
  servoFrontRL.attach(6,501,2400);
  servoFrontLL.attach(7,501,2400);
  servoBackRL.attach(A2,501,2400);
  servoBackLL.attach(A3,501,2400);
  servoTail.attach(A1,501,2400);
  servoHead.attach(A0,501,2400);

  //Setting up the ultrasonic sensor pin's, HC-SR04
  pinMode(trigerPIN, OUTPUT);
  pinMode(echoPIN, INPUT);

}

void loop()
{

  int startAngle; //The random angle to wich start walking

  int distaAngle; // Distance to a upstical at an spesific angle  
  int numberD; //Number on decition that is taken on random


  /*Startup prosedure for geting the robot ready for the walkRandom function
   -Setting the tail, and head in start position.
   -Find a direction to start walking
   -Find out how long the distance is to an obstical in that direction and if its distance is long enough
   -Walk up to that upstical 
   */

  randomSeed(analogRead(6)); // Starts a random seed for random(), uses port 6 for random analog value

  if (hasDoneStartUp == true) 
  {
    walk("cB",0);

    delay(1000);

noRightDist0:

    // Choose which way it will go at first startup
    startAngle = random(0, 360); // Gives a random angel in witch to start walking
    if (startAngle <= 90)
      walk("fR", 1);
    if (startAngle >= 90 && startAngle < 180)
      walk("fR", 2);
    if (startAngle >= 180 && startAngle < 270)
      walk("fL", 2);
    if (startAngle >= 270 && startAngle < 360)
      walk("fL", 1);
    delay(5000);

    distaAngle = sight(90);
    if (distaAngle >= 40) {
      distaWalk = ((distaAngle - 30) / 10); //Gives the number of stemps the robot needs to walk to get the measured distance(1 step for 10 cm)
      walk("fS", distaWalk);
    }
    else {
      goto noRightDist0; //Try once moore to find a direction to walk that has enough clearence
    }
    hasDoneStartUp = false;
  }  
  delay(4000);
  
  walkRandom();//This is the function that controlles the ArduDog's "random" moving around
  

}










