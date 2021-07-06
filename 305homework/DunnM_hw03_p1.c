/************************************************************

Marina Dunn
Physics 305, Fall 2016
Created: 7 September 2016
Last Modified: 7 September 2016
Homework 3, Problem 1

The purpose of this program is to calculate the area under a function of one variable,
over a finite range. This particular function is smooth over the integration interval,
so we can compare the calculated and correct value of the area. We will use the Left-Hand
Rule of numerical integration, which starts at the lowest x limit but does not take into account the highest x limit. Therefore, it is an underestimation of the area. The number of bins increases by powers of 2, from 1 to 22.

Usage:
The integration starts at the lowest x limit, xLo, then sums the area under the curve as the number of bins goes from 2^1 to 2^22. It continues until just before it reaches xHi, adding the areas of the rectangular slices together. The error is then calculated from the difference between the actual value, 0.8333, and the value that was found numerically, which is plotted with both single and double precision.

to compile: $gcc DunnM_hw03_p1.c -o DunnM_hw03_p1.exe -lm
to run: $DunnM_hw03_p1.exe




************************************************************/

#include <stdio.h>
#include <math.h>

int main(){

  //I want to declare the bounds of integration first
  double xLo = 0, xHi = 1;
  //I now want to declare all  temporary variables and final variables
  double rect_area, x, f_x;
  //I wante to declare the variable for the final answer
  double ILH_area = 0;

  double i, N = 1; // i is my count variable, and N is the number of rectangles
  double h;

  //I now need to loop over all the rectangles
  x = xLo; //This starts at the left limit
  for(i=1; i<=22; i++){// beginning of first loop
    N *= 2;
    h = (xHi-xLo)/N; // This is the step size/interval, (upper-lower)/nbins
    ILH_area = 0;

    for(x=xLo; x< xHi; x+= h){//beginning of second loop
      f_x = 0.5 + x*x;

      //this calculates the area of the rectangle and then adds it to the total
    rect_area = f_x * h;
    ILH_area += rect_area;
    }//end of second loop
    
    // printf("%f\t%f\n",N,ILH_area);         //data for DunnM_hw03_p1.ps
    // printf("%f\t%f\n",N,0.8333333);
    // printf("%f\t%f\n",N,fabs(0.83333-ILH_area));  //data for DunnM_hw03_p1_graph2.ps
    printf("%f\t%f\n",N,fabs(0.83333-ILH_area)); 
  } //end of first loop

  //Print out the calculated and true answers
  //printf("Integrated area = %f\n", ILH_area);
  //printf("Correct answer = %f\n", 0.833333333);

   return 0;






}
