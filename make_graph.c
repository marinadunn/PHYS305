
#include <math.h>
#include <stdio.h>

double myfunc(double x);
main(){
  double x,y;
  double x1, x2, dx;

  fprintf(stderr,"enter range to be plotted and step size: x1 x2 dx \n");
  scanf("%lf %lf %lf",&x1,&x2,&dx);
  for(x=x1; x<=x2; x+=dx){
    y=myfunc(x);
    printf("%le %le\n", x, y);
  }
}
