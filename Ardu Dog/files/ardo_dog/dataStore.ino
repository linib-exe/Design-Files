
int dataStore(int left,int left2 ,int straightF,int right2,int right, int choice, int choiceDis) {

  if (SD.begin(SD_Pin)){ // If Sd card i avalible the then save string in file 
    File choicesFile = SD.open("choices.txt", FILE_WRITE);
    String writeText; 
    writeText += String(left) += ":"; //Takes the values from int to String
    writeText += String(left2) += ":";
    writeText += String(straightF) += ":";
    writeText += String(right2) += ":";
    writeText += String(right) += ":";
    writeText += String(choice) += ":";
    writeText += String(choiceDis);
 
    choicesFile.println(writeText); // Saves the String to the file
    delay(1000); 
    choicesFile.close();

  }  

}

