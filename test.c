/*************************************************************************

Marina Dunn
PHYS 305, Fall 2016
Created: 12 October 2016
Last Modified: 13 October 2016

Purpose: This program is intended to display the orbital motion for an object


Usage:

To compile: $gcc DunnM_hw08_p1.c -o DunnM_hw08_p1.exe -lm
To run: $DunnM_hw08_p1.exe

*************************************************************************/

#include <stdio.h>
#include <math.h>
#include <animation.h>
#define PI = 3.14159265
#define G = 9.8 //m^3/s^2*kg
#define M = 1.989*pow(10,30) // mass of Sun

double acceleration( double r[2], double a[2]);

int main(){
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

 FILE*fp;
 fp=fopen("orbital.g", "w");


 printf("Please specify an initial velocity as a fraction out of sqrt(GM/r): \n");
 scanf("%f", &v_init);

 printf("Please specify a step size: \n");
 scanf("%f", &dt);

 printf("Please specify the total periods that occur: \n");
 scanf("%f", &T);

 for(t=0; t<T; t+=dt){
   r_half[0] = r[0] + v[0]*(dt/2.);
   r_half[1] = r[1] + v[1]*(dt/2.);
   v_half[0] = v[0] + a[0]*(dt/2.);
   v_half[1] = v[1] + a[1]*(dt/2.);
 
   r[0] += v_half[0]*dt;
   r[1] += v_half[1]*dt;
   v[0] += a_half[0]*dt;

   acceleration(r_half,a_half);


 r[1] += v_half[1]*dt;
 v[1] += a_half[1]*dt;
 r[0] = 1;
 r[1] = 0;
 v[0] = 0;
 v[1] = v_init*(2./PI);

 acceleration(r,a);
 r_mag=hypot(r[0],r[1]);
 v_mag=hypot(v[0],v[1]);

 L=r[0]*v[1] - r[1]*v[0]; //conservation of angular momentum for motion in the x,y plane
 E=(v_mag*v_mag)/2. + (-G*M/r_mag); //conservation of energy
 }

 printf("E = %f \n",E);
 printf("L = %f \n" L);
fclose(fp);

}
