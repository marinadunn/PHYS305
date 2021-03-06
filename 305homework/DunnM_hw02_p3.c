/****************************************************************************
*Marina Dunn
*Physics 305, Fall 2016
*Created: 26 August  2016
*Last Modification: 31 August 2016
*Homework 2, Problem 3
*
*The purpose of this program is to raise a base number to a certain amount of 
*powers without using the general power function, but in this case a for loop.
*
*Usage:
*The'for loop' begins at an exponential power of 1 and grows by increments of 1
*until it reaches 20. The output (integer) will be 2 raised to that power n.
*$gcc DunnM_hw02_p3.c -o DunnM_hw02_p3.exe -lm  //to compile
*$DunnM_hw02_p3.exe //to run
*
*****************************************************************************/


#include <stdio.h>
#include <math.h>
int main(){


  int n, power;
  power = 1;
  // We want our base number to always be 2, and raise it to powers between 1 and 20
  //beginning of loop
  for(n=1; n<=20; n++){  //operator checks that value is less than the number that follows
    power *= 2;  //equivalent to power = power * 2, our base
  printf("result = 2^%i = %i \n",n,power);
  } //end of loop

  return 0;



}
