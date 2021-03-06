/****************************************************************************
Marina Dunn
PHYS 305, Fall 2016
Created: 4 October 2016
Last Modified: 5 October 2016

Purpose: This program aims to model the motion of a skydiver as he jumps from a certain height above the Earth, and falls back to the ground. He will eventually reach a terminal velocity. We will approximate the time at which he opens his parachute at a height of 1000 m from the ground. This model will use quadratic drag force, which most closely resembles real atmospheric air resistance.


Usage:
to compile: $gcc DunnM_hw07_p5.c -o DunnM_hw07_p5.exe -lm
to run: $DunnM_hw07_p5.exe

***************************************************************************/

#include <stdio.h>
#include <math.h>


double a_real(double g, double y, double v, double v_term){
   double value;
   value = -g*(1.- ((v*v)/(v_term*v_term))*exp(-(y/8000)));
   return (value);

}

int main (){

  double x, y, t, v, vy, vx, v_term = 65;
  double y0 = 40000; //initial vertical position in m
  double h = 0.0001; // step size (in sec)
  double v_y0 = 0; // m/s // initial vertical velocity
  double g = 9.8; // m/s^2 //gravitational constant
  double t_half, t_start = 0, t_end; // in sec
  double y_new, y_half, x_half, y_end = 1000; //Want ending height to be height at which skydiver opens chute, not when he reaches the ground
  double v_new, v_half, a_half, a;
  y = y0;
  v = v_y0;
  a = a_real(g,y, v,v_term);

  for (t=t_start; t<=t_end; t+=h){
   y_half = y + (h/2.)* vy;
   v_half = v + (h/2.)* a;
   a_half = a_real(g, y, v, v_term);
   
   y += v_half * h;
   v += a_half * h;
   
   if(y==y_end){
     t = t_end;
   }
   if(y> y_end){
     t_half = t - (h/2.);
     t_end = t_half - (y_half - y_end)/v_half;
   }
   printf(" %f\t%f \n", v, t);
}
  // printf(" t (sec) at which skydiver opens chute: %f \n", t_end);



}
