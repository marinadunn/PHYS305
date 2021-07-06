/**************************************
Marina Dunn
PHYS 305, Fall 2016
Created: 31 August 2016
Last modified: 31 August 2016
Homework 2, Problem 4

Purpose: to input values of x, from -pi to pi, increasing in increments of 0.1, and producing corresponding values of cos(x), and then graphing the results, cos(x) vs. x. In this program, x is the independent variable.

Usage:
The for loop begins at x=-3.141 and increases by 0.1. The cosine function then gives the corresponding ouput value, in between the y boundaries -1 and 1.The program then graphs the result in philsplot.
$gcc DunnM_hw02_p4.c -o DunnM_hw02_p4.exe -lm //to compile
$DunnM_hw02_p4.exe //to run


*********************************************
*/

#include <stdio.h>
#include <math.h>
#include "philsplot.h"

int main(){

  float i,f_x,x; // i is the counting integer
  float xLo=-3.141, xHi= +3.141, yLo = -1, yHi = +1;
  float expand = 1.1;
  int boxcolor=1,linecolor=13, linestyle=1, linewidth=3;
  open_plot("700x700");
  box_plot(xLo,xHi,yLo,yHi,expand,boxcolor,"x", "cos(x)","","HW2 Problem 4 Graph");
  locate_plot(xLo,yLo);

  for(i=-3.141; i<=3.141; i++){ //beginning of loop
    printf(" x value   cos(x) \n");
    x = i + 0.1; //this gives x an initial value of -3.141, or -pi, and increases it by 0.1
    f_x = cos(x); //cos(x) is already a function in the math library, it needs to take in the increasing value of x
    printf(" x: %f   cos(%f): %f \n",x,x,f_x); // cos(x) is given in radians
    drawto_plot(x,f_x, linecolor, linestyle, linewidth);
     }
  flush_plot();
  close_plot();

  return (0);

}


