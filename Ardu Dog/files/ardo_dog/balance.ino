
void balance()
{
  /*The code beneath is a rewrite from http://playground.arduino.cc/Main/MPU-6050#short
   titeled: 
   MPU-6050 Short Example Sketch
   By Arduino User JohnChi
   August 17, 2014
   Public Domain
   */
  int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  //Writes the information out on serial connection
  Serial.print("AcX = "); 
  Serial.print(AcX);
  Serial.print(" | AcY = "); 
  Serial.print(AcY);
  Serial.print(" | AcZ = "); 
  Serial.print(AcZ);
  Serial.print(" | Tmp = "); 
  Serial.print(Tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); 
  Serial.print(GyX);
  Serial.print(" | GyY = "); 
  Serial.print(GyY);
  Serial.print(" | GyZ = "); 
  Serial.println(GyZ);
  delay(333);

}


