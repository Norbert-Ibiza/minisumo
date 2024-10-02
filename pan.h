
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void muestra()
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
{ // Serial.print("-------MUESTRA--------: "); 
  Serial.print("BAT..........: ");  Serial.println(n1);
   Serial.print("CNY  e,d.----: ");  Serial.print(cny_e);    Serial.print(","); Serial.print(cny_d); Serial.print(" -> ");  Serial.println(que_cny);

   Serial.print("GPD e,fe,fe,d: ");  
          Serial.print(gpd_fe); Serial.print(",");
          Serial.print(gpd_e);    Serial.print(","); 
          Serial.print(gpd_d); Serial.print(","); 
          Serial.print(gpd_fd);   Serial.print(","); 
         
          Serial.print(" -> ");   Serial.println(que_gpd); 
   
    Serial.println(" ");  
   //Serial.print("PER...: ");   Serial.println(perdido);   

   //Serial.print("CRONO.: ");   Serial.println(cr);  
   //Serial.println("  ");  
}







//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void luces(int n)
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
{ digitalWrite(led1, LOW);  
  digitalWrite(led2, LOW);  
  digitalWrite(led3, LOW);
  if       (n==1) {digitalWrite(led1, HIGH);}
  else if  (n==2) {digitalWrite(led2, HIGH);}
  else if  (n==3) {digitalWrite(led2, HIGH); digitalWrite(led1, HIGH);}
  else if  (n==4) {digitalWrite(led3, HIGH);}
  else if  (n==5) {digitalWrite(led3, HIGH);digitalWrite(led1, HIGH);}
  else if  (n==6) {digitalWrite(led3, HIGH);digitalWrite(led2, HIGH);}
  else if  (n==7) {digitalWrite(led3, HIGH);digitalWrite(led2, HIGH);digitalWrite(led1, HIGH);}
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
void paradita()
{
  
    bool ss=false;
      while (!ss) 
      {  if (Serial.available())  
         {	char kk='x';
           kk = Serial.read();  
           while (Serial.available()) Serial.read();
           if   (kk ='c') {ss=true;}
		     }
      }
      //salir=true;
}




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lucecitas()
{  luces(0); delay(100);
   luces(7); delay(100);
   luces(0); delay(100);
   luces(7); delay(100);
   luces(0); delay(100);
 }

