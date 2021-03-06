/************************************************************************
Marina Dunn
PHYS 305, Fall 2016
Created: 13 September 2016
Last Modified: 14 September 2016

Purpose:


Usage:

to compile: $gc DunnM_hw04_p2.c -o DunnM_hw04_p2.exe -lm
to run: $DunnM_hw04_p2.exe





***********************************************************************/

#include <stdio.h>
#include <math.h>



int main(){

  double i, N = 1000, x, f_x, xLo = 0.5, xHi = 1.5, h, total_area;

  for(i=1; i<=N; i++){
    h = (xHi - xLo)/N; //h is step size
    total_area = 0;
    for(x=xLo + (1/2*N); x<=xHi; x+= h){
      f_x = sqrt(x);
      total_area += h*f_x;
      printf("%d\t%d\n", N, fabs(total_area - 0));
    }
  }


  return 0;
}
