/**************************************************************************

Marina Dunn
PHYS 305, Fall 2016
Created: 8 November 2016
Last Modified: 14 December 2016

Purpose: The goal of this program is to use the relaxation method to find the temperature distribution inside an insulated rectangular region with a circular cavity in the center. The temperature of the rectangular region obeys Laplace's equation.We use a fixed grid size of 20 x 20, which was eventually modified to 40x40, and 80x80 for problem 2. For all points interior to the rectangular region, we assume the intial temperature to be 0 when starting each iteration, unless they are inside the circular region, in which case, the initial T is 80 degrees. In this case, we start at a particular point: r=(1.0,1.0).

Usage: [Temperature units are in Celcius, distance units are in Centimeters] 
Laplace's equation, gradient^2 V(r) = 0, in a region where no charge exists, or p=0, where V is the electrostatic potential on the boundary of the region. If you know this, then you can find the unique solution to Laplace's equation. 
To compile: $gcc DunnM_hw11_p1.c -o DunnM_hw11_p1.exe -lm
To run: $DunnM_hw11_p1.exe


************************************************************************************/

#include <stdio.h>
#include <math.h>

#define NGRID 20 // 20 by 20 grid size (plus one at the boundary)

int main(){
  FILE *NEWFILE;
  NEWFILE= fopen("KvsTEMP.g","w");
  double mygrid[NGRID + 1][NGRID + 1];
  int x,y,k;
  double distance;
 
 for(x=0; x<=NGRID; x++){ 
    for(y=0; y<=NGRID; y++){
      distance = sqrt((pow((x-10),2)+(pow((y-10),2))));
      if(distance <= 5){
	mygrid[x][y] = 80;
      }else{mygrid[x][y] = 0;}
    }
   }

 printf("  %f \n", mygrid[2][2]);

 for(k=1; k<=1000; k++){   //Loop over iterations
 for(x=1; x<NGRID; x++){  //Loop over all interior points
    for(y=1; y<NGRID; y++){
      distance = sqrt((pow((x-10),2)+(pow((y-10),2))));
      if(distance <= 5){
	mygrid[x][y] = 80;}
      else{mygrid[x][y] = (mygrid[x][y+1]+mygrid[x][y-1]+mygrid[x+1][y]+mygrid[x-1][y])/4.;}
      if(x==5 && y==5){
	fprintf(NEWFILE," %ld    %lf\n", k, mygrid[x][y]);}
    }
   }
 }

}












