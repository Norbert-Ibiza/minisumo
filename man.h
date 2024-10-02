#include "Arduino.h"
void atura()     
{ digitalWrite(mot_drt1,0);  digitalWrite(mot_drt2,0); analogWrite(pwmd,0);  
  digitalWrite(mot_esq1,0);  digitalWrite(mot_esq2,0); analogWrite(pwme,0);
}



void davant()   
 { digitalWrite(mot_drt1,0);  digitalWrite(mot_drt2,1); analogWrite(pwmd,vel_med);  
   digitalWrite(mot_esq1,0);  digitalWrite(mot_esq2,1); analogWrite(pwme,vel_med);
 }
 
void ataca()   
 { digitalWrite(mot_drt1,0);  digitalWrite(mot_drt2,1); analogWrite(pwmd,vel_max);  
   digitalWrite(mot_esq1,0);  digitalWrite(mot_esq2,1); analogWrite(pwme,vel_max);
  }
void darrere()   
 { atura(); delay(50);
   digitalWrite(mot_drt1,1);  digitalWrite(mot_drt2,0); analogWrite(pwmd,vel_med);  
   digitalWrite(mot_esq1,1);  digitalWrite(mot_esq2,0); analogWrite(pwme,vel_med);
   delay(200); 
 }


void gira_esq()  
{ digitalWrite(mot_drt1,0);  digitalWrite(mot_drt2,1); analogWrite(pwmd,vel_max);  
  digitalWrite(mot_esq1,0);  digitalWrite(mot_esq2,1); analogWrite(pwme,0);
   delay(10); 
}
void gira_drt()   
{ digitalWrite(mot_drt1,0);  digitalWrite(mot_drt2,1); analogWrite(pwmd, 0);  
  digitalWrite(mot_esq1,0);  digitalWrite(mot_esq2,1); analogWrite(pwme,vel_max);
   delay(10); 
}



void rota_esq()  
{ digitalWrite(mot_drt1,0);  digitalWrite(mot_drt2,1); analogWrite(pwmd,vel_med);  
  digitalWrite(mot_esq1,1);  digitalWrite(mot_esq2,0); analogWrite(pwme,vel_med);
  delay(250);
 }
void rota_drt()   
{ digitalWrite(mot_drt1,1);  digitalWrite(mot_drt2,0); analogWrite(pwmd,vel_med);  
  digitalWrite(mot_esq1,0);  digitalWrite(mot_esq2,1); analogWrite(pwme,vel_med);
  delay(250);
}

void volta()
{ rota_esq();  
  rota_esq();  
  atura();
}
