/**************************************************************************

Marina Dunn
PHYS 305, Fall 2016
Created: 8 November 2016
Last Modified: 14 December 2016

Purpose: The goal of this program is to use the over-relaxation method to find the temperature distribution inside an insulated rectangular region with a circular cavity in the center. This means an additional correction term must be placed

************************************************************************************/

#include <stdio.h>
#include <math.h>

#define NGRID 80 // 80 by 80 grid size (plus one at the boundary)

int main(){
  FILE *NEWFILE;
  NEWFILE= fopen("KvsTEMP.g","w");
  double mygrid[NGRID + 1][NGRID + 1];
  int x,y,k,w=1.939;
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
      else{mygrid[x][y] = ((1-w)*mygrid[x][y]+(mygrid[x][y+1]+mygrid[x][y-1]+mygrid[x+1][y]+mygrid[x-1][y])*(w/4.));}
      if(x==5 && y==5){
	fprintf(NEWFILE," %ld    %lf\n", k, mygrid[x][y]);}
    }
   }
 }

}










