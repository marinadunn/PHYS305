/****************************************************************************
Marina Dunn
PHYS 305, Fall 2016
Created: 4 October 2016
Last Modified: 5 October 2016

Purpose: This problem aims to solve the case where two falling bodies are dropping from the same initial height but with different initial velocities, and we want to find what happens for the cases where there is no drag, linear drag, and quadratic drag.


Usage:
to compile: $gcc DunnM_hw07_p4.c -o DunnM_hw07_p4.exe -lm
to run: $DunnM_hw07_p4.exe


***************************************************************************/

#include <stdio.h>
#include <math.h>

double x, y, v, vy, vx, v_term, g = 9.8; // m/s^2

//For all 3 cases, dx/dt = v_x(t), and dy/dt = v_y(t), but dv_x(t)/dt and dv_y(t)/dt vary.

//Acceleration for no drag case
double acc_x(double x, double y, double vx, double vy, double v_term){
  double value;
  value = 0;
  return (value);
    }

double acc_y(double x, double y, double vx, double vy, double v_term){
  double value;
  value = -g;
  return (value);
    }

//Accelerations for the Linear Drag case
double acc_x_lin(double x, double y, double vx, double vy, double v_term){
   double value;
   value = -g*(vx/v_term) ;
   return (value);
    }

double acc_y_lin(double x, double y, double vx, double vy, double v_term){
   double value;
   value = -g*(1. +(vy/v_term));
   return (value);
    }

//Accelerations for Quadratic Drag Case
double acc_x_quad(double x, double y, double vx, double vy, double v_term){
   double value;
   value = -g*((vx*abs(v))/(v_term*v_term)) ;
   return (value);
    }

double acc_y_quad(double x, double y, double vx, double vy, double v_term){
   double value;
   value = -g*(1.+((vy*abs(v))/(v_term*v_term)));
   return (value);
     }
 
int main (){

  double x, y, t, v, vy, vx, ax, ay, v_term = 10;
  double x0 = 0; //initial horizontal position in m for object 1
  double y0 = 10; //initial vertical position in m for objects
  double h = 0.0001; // step size (in sec)
  double v_x0 = 30; //initial horizontal velocity in m/s for object 1
  double v_y0 = 0; // m/s // initial vertical velocity for object 2
  double g = 9.8; // m/s^2 //gravitational constant
  double t_half, t_start = 0, t_end; // in sec
  double y_new, y_half, x_half, y_end = 0;
  double v_new, vx_half, ax_half, vy_half, ay_half, a;
  x = x0;
  y = y0;
  vx = v_x0;
  vy = v_y0;
  //For No Drag
  ax = acc_x(x,y,vx,vy,v_term);
  ay = acc_y(x,y,vx,vy,v_term);

  //For Linear Drag
  // ax = acc_x_lin(x,y,vx,vy,v_term);
  // ay = acc_y_lin(x,y,vx,vy,v_term);

  //For Quadratic Drag
  // ax = acc_x_quad(x,y,vx,vy,v_term);
  // ay = acc_y_quad(x,y,vx,vy,v_term);

  for(t=t_start; t<=t_end; t+=h){
    x_half = x + (h/2.)*vx;
    y_half = y + (h/2.)*vy;
    vx_half = vx + (h/2.)*ax;
    vy_half = vy + (h/2.)*ay;
    //Case for no drag
    ax_half = acc_x(x_half,y_half,vx_half,vy_half,v_term);
    ay_half = acc_y(x_half,y_half,vx_half,vy_half,v_term);
    
    x+=vx_half * h; //order matters
    y+=vy_half * h; //order matters
    vx+=ax_half * h;
    vy+=ay_half * h;
    ax = acc_x(x,y,vx,vy,v_term);
    ay = acc_y(x,y,vx,vy,v_term);

    if(y==y_end){
      t = t_end;
    }
    if(y <= y_end){
      if(v_x0==30{
      t_half = t + (h/2.);
      t_end = t_half - (x_half/vx_half);
	 }
	 if(v_y0 = 0){
	   t_half = t + (h/2.);
	   t_end = t_half - (y_half/vy_half);
	 }
      break;
    }
    printf("t (sec) at which object 1  reaches ground with no drag: %f\n"  t_end);
  }
 
}

