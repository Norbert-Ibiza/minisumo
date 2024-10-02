#include <stdint.h>
   const int pwmd    =3; //6; // Control de potencia del Mt1 de 0 a 255
   const int mot_drt1=4; //5; // Direcio normal -Connectat a la Digital D5
   const int mot_drt2=8; //7; // Direcio negada -Connectat a la Digital D'
   
   const int pwme     = 6;// 3; // 
   const int mot_esq1 = 5;// 4; // Direcio normal puerta D4
   const int mot_esq2 = 7;// 8; // Direcio negada puerta D8
   
   const int led1 =9; // Idem motor1
   const int led2 =10;
   const int led3 =11; 
   const int P1  =2; // Conectado a puera D2
   
   const int CNYd =A5; 
   const int CNYe =A6;

   const int GPDfe =A3;
   const int GPDe =A0;
   const int GPDd =A1;
   const int GPDfd =A2;
   const int niv1 =7; //Nivell de la bateria A1
   
   int cny_e,cny_d=0;
   int gpd_e,gpd_fe,gpd_fd,gpd_d=0;

  long num_acc=0;
   //*****************************************************
   int c_e=200; // vista de blanco a partir de 200 marca que esta fuera
   int c_d=200;
   int g_e= 80;   // lectura minima que se entiende que ve al eneimodo centro izquierda
   int g_d= 90;   // centro derecha
   int g_fe=80;   // lateral izquierda
   int g_fd=80;   // lateral dercha
   //******************************************************



   float n1=0;
   //int cny_e,cny_d=0;
 
   unsigned int var_pul=0;
   
   int vel_med=125;
   int vel_max=250;
   
   uint_fast8_t que_cny; //IMPORTANTISIMA nos indica si esta sobre 
                //linea exterior 0=no, 1=toco cny izquierdo, 2=derecho,3=los dos.
   uint_fast8_t que_gpd;  //IMPORTANTISIMA indica si vemos al enemigo 0=no, 
                 //1= lo veo por la izquierda, 2=derecha,3=los dos.
   
   int que_gpd_ant,perdido=0;
   unsigned long temps1,temps2,cr;
   uint8_t blanco=50;