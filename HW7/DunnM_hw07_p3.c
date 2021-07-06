/****************************************************************************
Marina Dunn
PHYS 305, Fall 2016
Created: 4 October 2016
Last Modified: 5 October 2016

Purpose: Instead of a linear correspondence, the drag force now increases quadratically with velocity. We want to again find t, the time at which the falling body reaches the ground. This approximation gives us the most realistic model for a falling body with air resistance.


Usage:
to compile: $gcc DunnM_hw07_p3.c -o DunnM_hw07_p3.exe -lm
to run: $DunnM_hw07_p3.exe






***************************************************************************/

#include <stdio.h>
#include <math.h>

//For quadratic drag, dv_y(t)/dt = -g(1 + v(t)|v(t)|/(v_term^2))

 double a_quad(double g, double v, double v_term){
   double value;
   value = -g*(1.+(v*abs(v))/(v_term*v_term));
   return (value);

}

int main (){

  double x, y, t, v, vy, vx, v_term = 1000;
  double y0 = 10; //initial vertical position in m
  double h = 0.0001; // step size (in sec)
  double v_y0 = 0; // m/s // initial vertical velocity
  double g = 9.8; // m/s^2 //gravitational constant
  double t_half, t_start = 0, t_end; // in sec
  double y_new, y_half, x_half, y_end = 0;
  double v_new, v_half, a_half, a;
  y = y0;
  v = v_y0;
  a = a_quad(g,v,v_term);

  for (t=t_start; t<=t_end; t+=h){
   y_half = y + (h/2.)* vy;
   v_half = v + (h/2.)* a;
   a_half = a_quad(g, v, v_term);
   
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
  printf(" t (sec) at which object reaches ground with quadratic drag: %f \n", t_end);
  printf(" t (sec) at which object reaches ground with no drag: 1.428521 \n");


}
