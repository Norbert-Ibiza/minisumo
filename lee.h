

///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 void lee()
///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
{ que_gpd_ant=que_gpd;
  que_cny=que_gpd=0;
   n1=analogRead(niv1);
     
  cny_e=analogRead(CNYe); 
  for(int i=0;i<5;i++)  
  { cny_e=cny_e+analogRead(CNYe);  
    cny_e=cny_e/2;
  }

  cny_d=analogRead(CNYd); 
  for(int i=0;i<5;i++)  
  { cny_d=cny_d+analogRead(CNYd);  
    cny_d=cny_d/2;
  }
  
  gpd_e=analogRead(GPDe);
  for(int i=0;i<5;i++)  
  { gpd_e=gpd_e+analogRead(GPDe);  
    gpd_e=gpd_e/2;
  }
  
  gpd_d=analogRead(GPDd);
  for(int i=0;i<5;i++)  
  { gpd_d=gpd_d+analogRead(GPDd);  
    gpd_d=gpd_d/2;
  }

  gpd_fe=analogRead(GPDfe);
  for(int i=0;i<5;i++)  
  { gpd_fe=gpd_fe+analogRead(GPDfe);  
    gpd_fe=gpd_fe/2;
  }
 
  gpd_fd=analogRead(GPDfd);
  for(int i=0;i<5;i++)  
  { gpd_fd=gpd_fd+analogRead(GPDfd);  
    gpd_fd=gpd_fd/2;
  }

 
  if (gpd_e  >g_e) que_gpd=que_gpd+1;
  if (gpd_fe >g_fe) que_gpd=que_gpd+2;
  if (gpd_fd >g_fd) que_gpd=que_gpd+4;
  if (gpd_d  >g_d) que_gpd=que_gpd+8;
  
 //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
  if (cny_e > c_e) que_cny=que_cny+1;
  if (cny_d > c_d) que_cny=que_cny+2;

  //if (cny_e < 200) que_cny=que_cny+1;
  //if (cny_d < 200) que_cny=que_cny+2;

}
  
