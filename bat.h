

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void control_bateria()
{ n1=analogRead(niv1); //posible lentitud de eacio ESTUDIAR////////////
      if ((long)n1 < 400) //600
      {  Serial.print("ERROR- Bat Baixa- esta a ");
         Serial.print(n1);
         digitalWrite(mot_drt1,0);  digitalWrite(mot_drt2,0); analogWrite(pwmd,0);  
         digitalWrite(mot_esq1,0);  digitalWrite(mot_esq2,0); analogWrite(pwme,0);
         lucecitas();
       }
}


