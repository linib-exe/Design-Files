void turnAround() // Takes two steps back and turns around 180 degrees
{
  walk("bS", 4);
  walk("fR", 6);
}

boolean scanRoom() //scans the room for distances and safes that distances in an array
{
  int index=0;
  boolean gotAllowedDistance = false;
  
  for (int i=0; i <= 180; i += 45) { // Lookes around, in all 45 degrees, measurse distance, saves in infoDistance
    int sightInCm = sight(i);
    if (sightInCm >= 40)
      gotAllowedDistance = true;
    
    infoDistance[index++] = sightInCm; 
    delay(2000);
  }
  sight(90); // Moves its head back in initial position
  
  return gotAllowedDistance;
}

void performWalk(int choice)
{
  if (choice == 3)
    walk("fR", 1);
  if (choice == 4)
    walk("fR", 2);
  if (choice == 0)
    walk("fL", 2);
  if (choice == 1)
    walk("fL", 1);
  delay(2000);

  distaWalk = ((sight(90) - 30) / 10); //Gives the number of steps the robot needs to walk to get the measured distance(1 step for 10 cm)
  walk("fS", distaWalk);
}

void walkRandom() {
  int infoDistance[5]; // array where the distances are temporarily held until saved to the SD card 
  boolean gotADistance = scanRoom();
  
  if (gotADistance) {
    int choice;
    selectNewChoice:
    choice = random(0,5);
    // Chooses a random way to walk if angles distance to upstical is greater then 40cm. Then it saves distances in all angles and the choice it made
    if (infoDistance[choice] >= 40) {
        dataStore(infoDistance[0] ,infoDistance[1],infoDistance[2],infoDistance[3], infoDistance[4], choice, infoDistance[choice]);
        performWalk(choice);
    }
    else
      goto selectNewChoice;
  }
  else {
    turnAround();
  }
}


