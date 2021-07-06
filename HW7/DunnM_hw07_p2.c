/***********************************************************************

Marina Dunn
PHYS 305, Fall 2016
Created: September 29, 2016
Last Modified: October 5, 2016

Purpose: We are again finding the time at which a falling body reaches the ground, but with an added linear drag component, meaning drag corresponds to the velocity linearly. Velocity increases, negatively, until it reaches its terminal velocity.


Usage:

to compile: $gcc DunnM_hw07_p2.c -o DunnM_hw07_p2.exe -lm
to run: $DunnM_hw07_p2.exe


**********************************************************************/

#include <stdio.h>
#include <math.h>

double x, y, vy, vx, g = -9.8, v, v_term = 10;

 double a_linear(double g, double v, double v_term){
   double value;
   value = -g*(1+(v/v_term)) ;
   return (value);
 }

//For linear drag, dv_y(t)/dt = -g(1 + (v_y(t)/v_term))

int main (){

  double x, y, t, v, vy, vx, v_term = 10;
  double y0 = 10; //initial vertical position 
  double h = 0.0001; // step size (in sec)
  double v_y0 = 0; // m/s // initial vertical velocity
  double g = 9.8; // m/s^2 //gravitational constant
  double t_half, t_start = 0, t_end; // in sec
  double y_new, y_half, x_half, y_end = 0;
  double v_new, v_half, a_half, a;
  y = y0;
  v = v_y0;
  a= a_linear(g,v,v_term);

  for (t=t_start; t<=t_end; t+=h){
   y_half = y + (h/2.)* vy;
   v_half = v + (h/2.)* a;
   a_half = a_linear(g, v, v_term);
   
   y += v_half * h;
   v += a_half * h;
   
   if(y==y_end){
     t = t_end;
   }
   if(y> y_end){
     t_half = t - (h/2.);
     t_end = t_half - (y_half - y_end)/v_half;
   }
     
}
  printf(" t (sec) at which object reaches ground with linear drag: %f \n", t_end);


}
