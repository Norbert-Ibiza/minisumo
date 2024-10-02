
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void calibra() 
{ Serial.println("++++++++++ CALIBRACION  ++++++++++++++++");
  lucecitas();
  

  lee();
  c_e = cny_e;
  c_d = cny_d; 
  g_e = gpd_e;
  g_d = gpd_d;
  g_fe = gpd_fe;
  g_fd = gpd_fd;

  for (uint8_t j=0; j<=100; j++) //haremos promedio de 100 lecturas
  {  
      lee();

      //if (cny_e  > c_e)  c_e  = cny_e;
      //if (cny_d  > c_d)  c_d  = cny_d;
      if (gpd_e  > g_e)  g_e  = gpd_e;
      if (gpd_fe > g_fe) g_fe = gpd_fe;
      if (gpd_fd > g_fd) g_fd = gpd_fd;
      if (gpd_d  > g_d)  g_d  = gpd_d;
      
  }
  
  /*EEPROM.write( 0,c_e);
  EEPROM.write( 1,c_d);
  c_e=c_d=0;
  c_e=EEPROM.read(0); 
  c_d=EEPROM.read(1); 
  Serial.print("Cny IZQ y DRC: ");  Serial.print(c_e);  Serial.print(" - ");Serial.println(c_d); 
  Serial.println("+++++++++++++++++++++++++++  "); 
  Serial.println(""); 
  */  
  Serial.print("gpd : ");   Serial.print(g_e);  Serial.print(" - ");
                            Serial.print(g_fe);  Serial.print(" - ");
                            Serial.print(g_fd);  Serial.print(" - ");
                            Serial.print(g_d);  Serial.println(" - ");
}