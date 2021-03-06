/**************************************************************************

Marina Dunn
PHYS 305, Fall 2016
Created: 8 November 2016
Last Modified:

Purpose: In this problem, we will observe the convergence results when modifying the grid size, starting at 20 x 20, then 40 x 40, and 80 x 80. In theory, as the gris becomes infinitely closely-spaced, the temperature should converge to a certain value faster at a singular point. We compare the graphs of each grid size to see if that is true.

**************************************************************************/

#include <stdio.h>
#include <math.h>
#define NGRID 20 //20 x 20 grid size (+ 1 at boundary)
#define NGRID 40 //40 x 40 grid size (+ 1 at boundary)
#define NGRID 80 //80 x 80 grid size (+ 1 at boundary)









int main(){

  double i, j;
