/***********************************************************************

Marina Dunn
PHYS 305, Fall 2016
Created: September 29, 2016
Last Modified: October 5, 2016

Purpose: The goal of this program is to resemble the motion of a falling body from a particular height with no drag/air resistance, and eventually find the time where it hits the ground, using second-order RK method.


Usage: This program takes the functions a(y,v,t) and v_y(y,v,t) defined in a separate function, and then uses a 'for loop' to find y_new, v_new, y_half, and v_half, up until the object reaches the ground at a time t.

to compile: $gcc DunnM_hw07_p1.c -o DunnM_hw07_p1.exe -lm
to run: $DunnM_hw07_p1.exe


**********************************************************************/

#include <stdio.h>
#include <math.h>



// For the case of no drag, dy(t)/dt = v(t), dv(t)/dt = -g

int main (){

  double x, y, t, v, vy, vx;
  double y0 = 10; //initial vertical position 
  double h = 0.0001; // step size (in sec)
  double v_y0 = 0; // m/s // initial vertical velocity
  double g = 9.8; // m/s^2 //gravitational constant
  double t_half, t_start = 0, t_end; // in sec
  double y_new, y_half, x_half, y_end = 0;
  double v_new, v_half, a_half, a = -g;
  y = y0;
  v = v_y0;

  //RK second order method
  for (t=t_start; t<=t_end; t+=h){
   y_half = y + (h/2.)* vy;
   v_half = v + (h/2.)* a;
   a_half = a;
   
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
  printf(" t (sec) at which object reaches ground with no drag: %f \n", t_end);
}
