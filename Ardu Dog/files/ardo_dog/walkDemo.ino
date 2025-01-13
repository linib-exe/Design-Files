void walkDemo() {

  walk("cB", 1);
  //Showing of head movement
  delay(1000);
  servoHead.write(0);
  delay(1000);
  servoHead.write(180);
  delay(1000);
  servoHead.write(90);
  delay(1000);

  //Showing of general leg movement
  walk("fS", 5);
  walk("fR", 5);
  walk("fL", 5);
  walk("bS", 5);
  walk("bR", 5);
  walk("bL", 5);

}

