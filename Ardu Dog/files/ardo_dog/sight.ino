/* Function that gives back distance based on an angle to a upstical in front of the robot*/

int sight(int angle)
{
  //Varibles
  int lenght; //time it takes for the echo to come back, in microSeconds 
  int distance; //variable that stores the distance to an upstical

  servoHead.write(angle);
  delay(1000);

  digitalWrite(trigerPIN, LOW); //Sends out signal to triger the sensor
  delayMicroseconds(2);
  digitalWrite(trigerPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPIN, LOW);

  lenght = pulseIn(echoPIN, HIGH); //measurse the signal that comes back
  distance = lenght/ 58,2; // uS/ 58=cm or uS/148=inch; distance=high level time*voice velocity(340m/s) / 2, source:http://www.ebay.com/itm/161130848128?_trksid=p2059210.m2749.l2649&ssPageName=STRK%3AMEBIDX%3AIT

  return distance;

} 

