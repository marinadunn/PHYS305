/***************************************************************************
Marina Dunn
PHYS 305, Fall 2016
Created: 13 September
Last modified: 14 September 2016

Purpose: The bounds of 0 and positive infinity make this integral improper. We want to find a way to evaluate the function even though this is so. The function is also a problem; Normally, by hand, we could use integration by parts and realize that the integral turns into the error function, erf(x). I found that this function actually is included in the math.h library.


Usage:

to compile: $gc DunnM_hw04_p2.c -o DunnM_hw04_p2.exe -lm
to run: $DunnM_hw04_p2.exe







***************************************************************************/

#include <stdio.h>
#include <math.h>
#include <limits.h> //this is a library I researched that makes it so a variable type cannot have a value beyond the maximum or minimum; in this case, I will want to use long_max for the positive infinity bound, which corresponds to a value of 2147483647

double f(double x);

int main(){

  double  i, N=1000, x, f_x, xLo = 0,  h, total_area, erfx = erf(x);
  long double xHi;
   
  for(i=1; i<N; i++){
     h = (xHi-xLo)/N; // This is the step size/interval, (upper-lower)/nbins
     total_area = 0;
     for(x=xLo + (1/2*N); x<=xHi; x+= h){
       f_x = (-3.1415926/4)*erf(x);
       total_area += h*f_x;
     
      // For midpoint method, I would use the x value in the middle of the bin, instead of the x value on the boundaries of the bin, then divide the area by the number of bins, N, then find the total area

        printf("%d\t%d\n",N,fabs(total_area - 0.98904261));
    }
  }

  return 0;
}
