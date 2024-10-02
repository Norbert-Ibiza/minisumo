/*Progra realizado por Norberto Moreno, 2024
Programa básico de minisumo con 4 gpd analogicos delante y dos cny80 delante.
De libre distribución.*/


#include <EEPROM.h>
#include <Arduino.h>
#include "var.h"  
#include "pan.h"
#include "lee.h"
#include "bat.h"
#include "cal.h"
#include "man.h"

//-----------------------------------------------------------------------
void setup() 
//-----------------------------------------------------------------------
{  pinMode(P1, INPUT);  //definicion del pulsador como entrada  
   pinMode(led1, OUTPUT);      
   pinMode(led2, OUTPUT);   
   pinMode(led3, OUTPUT); //definicion de los leds como salida
   pinMode(mot_drt1, OUTPUT);  
   pinMode(mot_drt2, OUTPUT); 
   pinMode(pwmd,  OUTPUT); 
   pinMode(pwme,  OUTPUT); // motores declarados para PWM 
   pinMode(mot_esq1, OUTPUT);  
   pinMode(mot_esq2, OUTPUT);   
   
   digitalWrite(mot_drt1,0);  
   digitalWrite(mot_drt2,1); 

   analogWrite(pwmd,0); 
   analogWrite(pwme,0);
   digitalWrite(mot_esq1,0);  
   digitalWrite(mot_esq2,1); 
   
   Serial.begin(9600); 
   //Serial.begin(115200); 
}


//----------------------------------------------------------------------
void loop() 
//----------------------------------------------------------------------
{  //calibra(); davant();
   
   //while(1)gira_esq();
  lee();
  muestra();
  lucecitas();   luces(7);
  control_bateria();
  
  uint8_t programa= que_programa();

  lucecitas();
  espera_pulsador();
  
  switch (programa)
      { case 1: ataca();    
                break;
        case 2: //rota_esq();
                digitalWrite(mot_drt1,0);  digitalWrite(mot_drt2,1); analogWrite(pwmd,vel_max);  
                digitalWrite(mot_esq1,1);  digitalWrite(mot_esq2,0); analogWrite(pwme,vel_max);
                delay(200);
                break;
        case 3: //rota_drt(); 
                digitalWrite(mot_drt1,1);  digitalWrite(mot_drt2,0); analogWrite(pwmd,vel_max);  
                digitalWrite(mot_esq1,0);  digitalWrite(mot_esq2,1); analogWrite(pwme,vel_max);
                delay(200);
                break;
      }
 
     
 



  bool salir=false;   
   
   while (!salir)
   {  //cr=crono(0);
      //lee();
      //muestra();
      accion();
      //salir = digitalRead(P1); 
      //if (salir==1) { while(1) atura();  }   
     
      //cr=crono(1);
      //Serial.print(cr); 
      //Serial.print(que_gpd); Serial.print(",");Serial.println(que_cny);
      //muestra();
      //paradita();  
        var_pul=0;
        var_pul = digitalRead(P1);   
        if(var_pul==1) while (1)  atura();
        
       
   }
   
 }//loop
 


      
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void accion()

{   
     lee();  
         
      if      (que_gpd== 1)  gira_esq();  
      else if (que_gpd== 2)  gira_esq();  
      else if (que_gpd== 3)  gira_esq();        
      else if (que_gpd== 4)  gira_drt();  
      //else if (que_gpd== 5)  davant();    
      //else if (que_gpd== 6)  davant();   
      else if (que_gpd== 7)  ataca();    
      else if (que_gpd== 8)  gira_drt();  
      else if (que_gpd== 9)  ataca();     
      //else if (que_gpd== 10)  davant();  
      else if (que_gpd== 11)  ataca();    
      else if (que_gpd== 12)  gira_drt(); 
      else if (que_gpd== 13)  ataca();    
      else if (que_gpd== 14)  ataca();    
      else if (que_gpd== 15)  ataca();    
      else davant();
    
      if      (que_cny==1)  {darrere(); rota_drt();atura(); } 
      else if (que_cny==2)  {darrere(); rota_esq();atura(); } 
      else if (que_cny==3)  {darrere(); volta();   atura(); }    
      
} //void





//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int que_programa()
{ luces(0);
  int var_programa=0; //initzializa la varible del programa 
  int var_pulsador= 0; //llegim si està pulsat
 
  while (var_pul==LOW )  {   var_pul = digitalRead(P1);  }
  
  cr=crono(0); // distancia inicial del temps
  while(cr < 20000 && var_pul==1)// contrl dels 20 segons
  { var_programa ++;
    if (var_programa > 3) var_programa = 1; //control de overflow
    
    if      (var_programa==1)  luces(1);
    else if (var_programa==2)  luces(2);
    else if (var_programa==3)  luces(4);
    
    delay(500); // retras per controlar que ho canvii massa depresa.  
    cr=crono(1); //actualitza el temps passat, per controlar els 10 segons
    var_pul = digitalRead(P1); 
    
  }//while

  if (var_programa <1) var_programa=1;
  lucecitas();
  if      (var_programa==1)  luces(1);
  else if (var_programa==2)  luces(2);
  else if (var_programa==3)  luces(4);
  delay(2000);
  luces(0);
  return var_programa;
}




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
unsigned long crono(bool i)
{ unsigned long ii=999999999;
  if (i==0) 
  { temps1=millis(); 
    return 0;
  }
else if (i==1) 
  { temps2=millis();  
    ii= temps2 - temps1; 
    return ii;
  }
}




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void espera_pulsador()
{  luces(7); 
   crono(0);
   while (var_pul==LOW )  
   {   var_pul = digitalRead(P1);                    // espera hasta que acionas pusador
       //lee();  perdidos(); muestra();  delay(300);
       
   }
   luces(0);
   while (var_pul==HIGH )  var_pul = digitalRead(P1); // espera que lo sueltes
   delay(5000);
} 


