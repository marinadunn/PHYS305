/********************** demo.c *************************************/
/*
Demonstrate use of simple animation routines.
This one just moves a dot around a circle.

to compile:  cc -o demo demo.c libanimation.a -lX11 -lm
*/
#include <stdio.h>
#include <math.h>
#include "animation.h"
        /* prototypes for the animation routines */
#define PI 3.14159265

main(){
    int p1,p2,p3;	/* tags for particles 1 and 2 */
    double time,dt;  /* time and time step */
    double clock_time;  /* animation timing */
    int resample,count;      /* resample to match clock time */
    int i=1; 		//prompt to continue
    count=0;
    /* time to update animation is 1/20 sec */
    clock_time = 0.05;
    dt=0.01;
    resample=clock_time/dt;	
    if(resample==0)resample++;
    /* arguments are x_min, x_max, y_min, y_max .
       These are the region of (x,y) to be displayed in the window */
    animation_start( -1.1, 1.1, -1.1, 1.1 );
    set_clock_tick( dt );
    p1 = add_particle(0.0,0.0);	  /* a dot at the center */
    p2 = add_particle(1.0,0.0);	  /* a dot at (1,0) */
    p3 = add_particle(0.,0.5);	  /* a dot at (1,0) */
    
    while(i==1){	
    for( time=0.0; time < 4.*PI; time += dt ){
	    count++;
	//resample
	if((count==resample)||(time<dt/2.)){
	/* move the dots around in a circle */
	move_particle_leave_track(p2, cos(time), sin(time) );
	move_particle_leave_track(p3, .5*sin(time), .5*cos(time) );
	count=0; //reset counter
	}
    }
    fprintf(stderr,"to continue enter (1), to end enter (0)\n");
    scanf("%d" ,&i);
    animation_end();  /* kill the window */
  }
}
