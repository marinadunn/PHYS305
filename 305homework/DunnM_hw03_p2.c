/************************************************************

Marina Dunn
Physics 305, Fall 2016
Created: 7 September 2016
Last Modified: 7 September 2016
Homework 3, Problem 1

The purpose of this program is to show how error of integration is directly related to the methods used for integration; some methods produce better error than others.

Usage:This program calculates the area using midpoint, trapezoid, and Simpson's methods individually , then their errors are plotted against each other.

to compile: $gcc DunnM_hw03_p1.c -o DunnM_hw03_p2.exe -lm
to run: $DunnM_hw03_p2.exe




************************************************************/

#include <stdio.h>
#include <math.h>

int main(){

  
  double x1, x2, x3, y1, y2, y3;
  
  double  x, f_x;
  //I wante to declare the variable for the final answer
  double total_area;

  double i, N = 1; // i is my count variable, and N is the number of rectangles
  double h;

  //I now need to loop over all the rectangles
 
  for(i=1; i<=22; i++){// beginning of first loop
    N *= 2;
    h = (x3-x1)/N; // This is the step size/interval, (upper-lower)/nbins
    total_area = 0;

    // For midpoint method, I would use the x value in the middle of the bin, instead of the x value on the boundaries of the bin, then divide the area by the number of bins, N, then find the total area
 
   
    /*   for(x1=0 + (1/2N); x1< 1; x1+= h){//beginning of second loop
	 y1 = x1*exp(x1);
	 total_area+=h*y1;
	 }
    //For Trapezoidal method, I average the y values of the boundaries of the bins, then add them ;

     for(x1=0; x< 1; x+= h){//beginning of second loop
      y1 = x1*exp(x1);
      x2 = x1 + h;
      y2 = x2*exp(x2);

	total_area = h*(1./2.)*(y1 + y2);

    }//end of second loop
    
    //For Simpson's Rule, the y values at the boundaries and midpoints of the bins are used */
     for(x1=0; x< 1; x+= h){//beginning of second loop
       y1 = x1*exp(x1);
       x2 = x1 + 0.5*h;
       y2 = x2*exp(x2);
       x3 = x1 + h;
       y3 = x3*exp(x3);
       total_area += h*((1./6.)*y1 + (2./3.)*y2+ (1./6.)*y3);		   

    // prints N and error
    printf("%f\t%f\n",N,fabs(total_area - 0.351971)); 
     }

  }
}
