/*************************************************************************

Marina Dunn
PHYS 305, Fall 2016
Created: 18 October 2016
Last Modified: 14 December 2016

Purpose: This program models the orbital motion of a satellite when given a tangential kick, which is an impulse/increase in momentum in the tangential direction at a particular point in time.

Usage:
To compile: $gcc DunnM_hw09_p1.c -o DunnM_hw09_p1.exe -lm
To run: $DunnM_hw09_p1.exe

*************************************************************************/

#include <stdio.h>
#include <math.h>
#include "animation.h" //prototypes for the animation routines
#define PI = 3.14159265
#define GM = 4*PI*PI //m^3/s^2*kg
#define M = 1.989*pow(10,30) // kg, mass of Sun

int main(){

  double t_kick;

  double t, dt, v_init, L, E, T; // dt is step size
  double r0[2]; //initial position - r0[0] is initial x, r0[1] is initial y
  double v0[2]; //initial velocity - v0[0] is initial x-velocity, v0[1] is initial y-velocity

  double r[2]; //position vector - r[0] is x, r[1] is y
  double v[2]; //velocity vector - v[0] is x-component of v, v[1] is y-component of v
  double a[2]; //acceleration vector - a[0] is x-component of a, a[1] is y-component of a

  double r_mag; //magnitude of position vector
  double v_mag; //magnitude of velocity vector

  double r_half[2];
  double v_half[2];
  double a_half[2];

 int i = 1, count, p1, resample, clock_time;
 count = 0;
 // time to update animation is 1/20 sec
 clock_time = 0.05;
 resample=clock_time/dt;

 FILE*fp;
 fp=fopen("orbital.g", "w");

 printf("Please specify an initial velocity as a fraction of sqrt(GM/r): \n");
 scanf("%lf",&v_init);

 printf("Please specify a step size, in AU: \n");
 scanf("%lf", &dt);
 
 printf("Please specify the total periods that occur: \n");
 scanf("%lf", &T);

 r[0] = 1;
 r[1] = 0;
 v[0] = 0;
 v[1] = 1.1*v_init*2*PI;

 animation_start( -1.1, 1.1, -1.1, 1.1 );
   set_clock_tick( 0.05 );ls

   p1 = add_particle(0.0,0.0);

 while(i==1){
 for(t=0; t<T; t+=dt){
   count+=1;

   r_half[0] = r[0] + v[0]*(dt/2.);
   r_half[1] = r[1] + v[1]*(dt/2.);
   v_half[0] = v[0] + a[0]*(dt/2.);
   v_half[1] = v[1] + a[1]*(dt/2.);

   r[0] += v_half[0]*dt;
   r[1] += v_half[1]*dt;
   v[0] += a_half[0]*dt;
   v[1] += a_half[1]*dt;

 acceleration(r,a);
 r_mag=hypot(r[0],r[1]);
 v_mag=hypot(v[0],v[1]);

 L = (r[0]*v[1]) - (r[1]*v[0]); //conservation of angular momentum for motion in the x,y plane
 E = (pow(v_mag,2)/2.) + (-GM/r_mag); //conservation of energy

   if((count==resample)||(t<dt/2.)){
	move_particle_leave_track(p1, cos(t), sin(t) );
	count=0; //reset counter
	}
   }
   }

 fclose(fp); 
 

}
