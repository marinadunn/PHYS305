
#include <math.h>
#include <stdio.h>
double myfunc(double x);

int main(){
  double x, y;

  //enter value for x
  fprintf(stderr,"enter value for x: \n");
  scanf("%lf",&x);
  fprintf(stderr, "x:%lf\n",x);

  //calculate f(x)
  y=myfunc(x);
  fprintf(stderr, "%e %e\n",x,y);

}
