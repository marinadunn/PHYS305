/**************************************
Marina Dunn
PHYS 305, Fall 2016
Created: 31 August 2016
Last modified: 31 August 2016
Homework 2, Problem 5

Purpose:to create a Maclaurin series expansion, or Taylor series expansion about the point x=0, for f(x) = e^x, to the fourth order.

Usage:
e^(x)= 1 +(x/1!) + (x^2/2!)+(x^3/3!)+...
The goal is to make separate files for each order and sum them together

$gcc DunnM_hw02_p5.c -o DunnM_hw02_p5.exe -lm //to compile
$DunnM_hw02_p5.exe //to run


*********************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "philsplot.h"

int main(){
  FILE*f1=fopen("DunnM_taylorseries.",
  int i, x, f_x;
  float xLo=-1, xHi= +1, yLo = -1, yHi = +2;
  float expand = 1.1;
  int boxcolor=1,linecolor=13, linestyle=1, linewidth=3;
  open_plot("700x700");
  box_plot(xLo,xHi,yLo,yHi,expand,boxcolor,"x", "exp(x)","","HW2 Problem 5 Graph");
  locate_plot(xLo,yLo);

  for(i=0; i<=N; i++){
    x= i + 0.01;
    f_x = exp(x);
    printf(" x: %f    e^(%f):  %f  \n",x,x,f_x); //outputs exponential value for given x values 
  
    return (0);
}
