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
#include <stdlib.h>
#include <math.h>
#include "animation.h" //prototypes for the animation routines
#define PI = 3.14159265
#define GM = 4*PI*PI //m^3/s^2*kg
#define M = 1.989*pow(10,30) // kg, mass of Sun

double acc(double r_mag, double r) {
  double acceleration;
  double r3 = fabs(r_mag)*fabs(r_mag)*fabs(r_mag);
  acceleration = -GM*r/(r3);
  return acceleration;
}
int main(){

  double p1, p2, impulse; //animation points

  double t, dt = .001, v_init = 1, L, E, T; // dt is step size
  double r0[2]; //initial position - r0[0] is initial x, r0[1] is initial y
  double v0[2]; //initial velocity - v0[0] is initial x-velocity, v0[1] is initial y-velocity
  double r[0] = 1;
  double r[1] = 0;
  double r[2]; //position vector - r[0] is x, r[1] is y
  double v[2]; //velocity vector - v[0] is x-component of v, v[1] is y-component of v
  double a[2]; //acceleration vector - a[0] is x-component of a, a[1] is y-component of a

  double r_mag; //magnitude of position vector
  double v_mag; //magnitude of velocity vector

  double r_half[2];
  double v_half[2];
  double a_half[2];

  int i = 1, i_half, count = 0, p1, p2;
 count = 0;
 // time to update animation is 1/20 sec


 v[0] = 0;
 v[1] = v_init*2*PI;
 a[0] = acc(r_mag, r[0]);
 a[1] = acc(r_mag, r[1]);

 animation_start( -1.1, 1.1, -1.1, 1.1 );
   set_clock_tick( dt );
   p1 = add_particle(r[0],r[1]); //orbiting object
   p2 = add_particle(0.0,0.0); //sun

   for(i==0; i<5; i=i+dt){
     if(i > 1-step/2 && i < 1 + step/2) {
      impulse = v[0] + .1;
      v[0] = v[0] + impulse;}

   i_half = i + (dt/2.)
   r_half[0] = r[0] + v[0]*(dt/2.);
   r_half[1] = r[1] + v[1]*(dt/2.);
   v_half[0] = v[0] + a[0]*(dt/2.);
   v_half[1] = v[1] + a[1]*(dt/2.);

   r[0] += v_half[0]*dt;
   r[1] += v_half[1]*dt;
   v[0] += a_half[0]*dt;
   v[1] += a_half[1]*dt;
   a[0] = acc(r_mag,r[1]);
   a[1] = acc(r_mag,r[1]);

 r_mag=hypot(r[0],r[1]);
 v_mag=hypot(v[0],v[1]);

move_particle_leave_track(p1,r[0], r[1] );

 L = (r[0]*v[1]) - (r[1]*v[0]); //conservation of angular momentum for motion in the x,y plane
 E = (pow(v_mag,2)/2.) + (-GM/r_mag); //conservation of energy

   if(count==0){
     printf("%f  %f\n", r[0], r[1]);
     count=0;}

  count += 1; //reset counter
	}
   }
   }

 
}
