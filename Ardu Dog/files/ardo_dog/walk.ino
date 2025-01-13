/*
The function walk uses the atributes
 dction:
 
 cB: setting legs to standardpostion
 
 fR: forward right
 fS: forward straight
 fL: forward left
 bR: backwards right
 bS: backwards straight
 bL: backwards left
 
 step:
 int : number of steps
 
 */

void walk(String dction, int step)
{

  int dMotionSide = 500; //delay between legs motion
  int dMotionLeg = 500;


  if (dction == "cB" ) {
    servoFrontRT.write(90);
    servoFrontLT.write(90);
    servoBackLT.write(90);
    servoBackRT.write(90);

    delay(1000);

    servoFrontRL.write(90);
    servoFrontLL.write(90);
    servoBackLL.write(90);
    servoBackRL.write(90);

    delay(1000);

    servoTail.write(90);
    servoHead.write(90);

    delay(5000); //Gives time to calibrating
  }

  if (dction == "fS" ) {  
    for( ; step > 0; step--)
    {

      servoFrontRT.write(135);
      servoFrontRL.write(135);
      delay(dMotionLeg);
      servoBackLT.write(45);
      servoBackLL.write(45);
      servoTail.write(45); //Moves the tail for more stability
      delay(dMotionSide);

      servoFrontLT.write(135);
      servoFrontLL.write(135);
      delay(dMotionLeg);
      servoBackRT.write(45);
      servoBackRL.write(45);

      delay(dMotionSide);

      servoFrontRT.write(90);
      servoFrontRL.write(90);
      delay(dMotionLeg);
      servoBackLT.write(90);
      servoBackLL.write(90);
      servoTail.write(90); //Moves the tail back in general mode
      delay(250);

      servoFrontLT.write(45);
      servoFrontLL.write(45);
      delay(dMotionLeg);
      servoBackRT.write(135);
      servoBackRL.write(135);
      servoTail.write(135);
      delay(dMotionSide);

      servoFrontRT.write(45);
      servoFrontRL.write(45);
      delay(dMotionLeg);
      servoBackLT.write(135);
      servoBackLL.write(135);

      delay(dMotionSide);

      servoFrontLT.write(90);
      servoFrontLL.write(90);
      delay(dMotionLeg);
      servoBackRT.write(90);
      servoBackRL.write(90);
      servoTail.write(90);
      delay(250);

    }
  }

  if (dction == "fR") {  
    for( ; step > 0; step--)
    {
      servoTail.write(50);
      servoFrontLT.write(50);
      servoFrontLL.write(50);

      delay(dMotionLeg);

      servoBackLT.write(50);
      servoBackLL.write(50);
      servoFrontLT.write(130);
      servoFrontLL.write(130);

      delay(dMotionLeg);

      servoBackLT.write(90);
      servoBackLL.write(90);
      servoFrontLT.write(90);
      servoFrontLL.write(90);
      servoTail.write(90); 

      delay(dMotionLeg);

    }
  }

  if (dction == "fL") {
    for( ; step > 0; step--)
    {

      servoTail.write(140);
      servoFrontRT.write(130);
      servoFrontRL.write(130);

      delay(dMotionLeg);

      servoBackRT.write(130);
      servoBackRL.write(130);
      servoFrontRT.write(50);
      servoFrontRL.write(50);

      delay(dMotionLeg);

      servoBackRT.write(90);
      servoBackRL.write(90);
      servoFrontRT.write(90);
      servoFrontRL.write(90);
      servoTail.write(90);

      delay(dMotionLeg);
    }
  }

  if (dction == "bS") {  
    for( ; step > 0; step--)
    {
      
      
      
      servoBackLT.write(135);
      servoBackLL.write(135);
      delay(dMotionLeg);
      servoFrontRT.write(45);
      servoFrontRL.write(45);

      delay(dMotionSide);

      servoBackRT.write(135);
      servoBackRL.write(135);
      delay(dMotionLeg);
      servoFrontLT.write(45);
      servoFrontLL.write(45);

      delay(dMotionSide);

      servoBackLT.write(90);
      servoBackLL.write(90);
      delay(dMotionLeg);
      servoFrontRT.write(90);
      servoFrontRL.write(90);

      delay(250);

      servoBackRT.write(45);
      servoBackRL.write(45);
      delay(dMotionLeg);
      servoFrontLT.write(135);
      servoFrontLL.write(135);

      delay(dMotionSide);

      servoBackLT.write(45);
      servoBackLL.write(45);
      delay(dMotionLeg);
      servoFrontRT.write(135);
      servoFrontRL.write(135);

      delay(dMotionSide);

      servoBackRT.write(90);
      servoBackRL.write(90);
      delay(dMotionLeg);
      servoFrontLT.write(90);
      servoFrontLL.write(90);

      delay(250);
    } 
  }

  if (dction == "bR") {  
    for( ; step > 0; step--)
    {
      servoBackRT.write(50);
      servoBackRL.write(50);

      delay(dMotionLeg);

      servoFrontRT.write(50);
      servoFrontRL.write(50);
      servoBackRT.write(130);
      servoBackRL.write(130);

      delay(dMotionLeg);

      servoFrontRT.write(90);
      servoFrontRL.write(90);
      servoBackRT.write(90);
      servoBackRL.write(90);

      delay(dMotionLeg);
    }
  }

  if (dction == "bL") {
    for( ; step > 0; step--)
    {

      servoBackLT.write(50);
      servoBackLL.write(50);

      delay(dMotionLeg);

      servoFrontLT.write(50);
      servoFrontLL.write(50);
      servoBackLT.write(130);
      servoBackLL.write(130);

      delay(dMotionLeg);

      servoFrontLT.write(90);
      servoFrontLL.write(90);
      servoBackLT.write(90);
      servoBackLL.write(90);

      delay(dMotionLeg);

    }
  }

  //Places all the legs in an standard postions after being done with walk function
  servoFrontLT.write(90);
  servoFrontLL.write(90);
  delay(dMotionLeg);
  servoBackRT.write(90);
  servoBackRL.write(90);
  delay(dMotionLeg);
  servoFrontRT.write(90);
  servoFrontRL.write(90);
  delay(dMotionLeg);
  servoBackLT.write(90);
  servoBackLL.write(90);
}











