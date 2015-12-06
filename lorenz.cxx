#include <iostream>
#include <cmath>

using namespace std;

void f(double* yt, double* y, const double a, const double b, const double c);

int main(){
  
 const double a=10.0;
 const double b=28.0;
 const double c=8.0/3.0;
 double k1[3];
 double k2[3]; 
 double k3[3]; 
 double k4[3];
 double y[3];
 double ytemp[3]; 
 const double dt = 0.01; 
 const double N = 100.0/dt; 
 
 y[0]=1;
 y[1]=1;
 y[2]=1;
  
 for(int i=0; i<N; i++){
   
  f(k1, y, a, b, c);
  
  const int M = 3;
  for(int j=0; j<M; j++){
  ytemp[j] = y[j] + 0.5*dt*k1[j]; 
  }
   
  f(k2, ytemp, a, b, c);
  
  for(int j=0; j<M; j++){
  ytemp[j] = y[j] + 0.5*dt*k2[j]; 
  }
   
  f(k3, ytemp, a, b, c);  
  
  for(int j=0; j<M; j++){
  ytemp[j] = y[j] + dt*k3[j]; 
  }
   
  f(k4, ytemp, a, b, c);
  
  
  y[0]=y[0]+(dt/6.0)*(k1[0]+2.0*k2[0]+2.0*k3[0]+k4[0]);
  y[1]=y[1]+(dt/6.0)*(k1[1]+2.0*k2[1]+2.0*k3[1]+k4[1]);
  y[2]=y[2]+(dt/6.0)*(k1[2]+2.0*k2[2]+2.0*k3[2]+k4[2]);
  
  cout << i*dt+dt << "\t" << y[0] << "\t" << y[1] << "\t" << y[2] << endl;
 }
  
  
  
  
 return 0; 
}


void f(double* yt, double* y, const double a, const double b, const double c){
  yt[0]=a*(y[1]-y[0]);
  yt[1]=y[0]*(b-y[2])-y[1];
  yt[2]=y[0]*y[1]-c*y[2];  
}