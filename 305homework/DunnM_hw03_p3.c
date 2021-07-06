/************************************************************

Marina Dunn
Physics 305, Fall 2016
Created: 7 September 2016
Last Modified: 7 September 2016
Homework 3, Problem 1

The purpose of this program is to find the integral of a function using the midpoint method, where the actual value is not known, and must be calculated.

Usage: The boundaries are now from x = 0.5 to x = 1.5. I approximated the integral by hand using a Taylor series approzimation and then integrated to get a value of 0.3367. The calculated area is compared with this to find the error.

to compile: $gcc DunnM_hw03_p1.c -o DunnM_hw03_p3.exe -lm
to run: $DunnM_hw03_p3.exe




************************************************************/

#include <stdio.h>
#include <math.h>

int main(){

  //I want to declare the bounds of integration first
  double xLo = 0.5, xHi = 1.5;
  //I now want to declare all  temporary variables and final variables
  double  x, f_x;
  //I wante to declare the variable for the final answer
  double sum = 0;

  double i, N = 1; // i is my count variable, and N is the number of bins
  double h;

  //I now need to loop over all the bins
  x = (xLo+h)/2; //This uses the midpoint method
  for(i=1; i<=22; i++){// beginning of first loop
    N *= 2;
    h = (xHi-xLo)/N; // This is the step size/interval, (upper-lower)/nbins
    sum = 0;

    for(x=xLo + 1/(2*N); x< xHi; x+= h){//beginning of second loop
      f_x = x*exp(-(x*x));

      //this calculates the area of the rectangle and then adds it to the total
    sum += f_x * h;
 
    }//end of second loop
    printf("%f\t%f\n",N,fabs(sum - 0.33670077925)); //prints N and error
   
  } //end of first loop

  //Print out the calculated and true answers
	   // printf("Integrated area = %f\n", sum);
	   // printf("Correct answer = %f\n",0.33670077925);

   return 0;






}
