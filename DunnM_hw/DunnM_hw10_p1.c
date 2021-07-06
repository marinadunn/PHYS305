/***********************************************************************

Marina Dunn
PHYS 305, Fall 2016
Created: 27 October 2016
Last Modified: 14 December 2016

Purpose: to understand the logistic map, which estimates the population growth model based on parameters X_n (where 0<= X_n <=1), the nth population, based on r, the growth parameter (where 0<= r >=1).

Usage: to compile: $gcc DunnM_hw10_p1.c -o DunnM_hw10_p1.exe -lm
to run: $DunnM_hw10_p1.exe

***********************************************************************/

#include <stdio.h>
#include <math.h>



int main(){

  double r =/* 0.2, 0.3,0.74,0.76,0.863,0.88,0.89,0.8915,*/ 0.910, X_n=0.5, X_n1;
  int i;

  for(i==0; i<1000; i++){ //1000 iterations
    X_n1 = 4* X_n* r* (1-X_n); //Logistic map equation
 printf("X_n+1 = %lf \n", X_n1);
  }


  return(0);

}
