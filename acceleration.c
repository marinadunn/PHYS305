#include <stdio.h>
#include <math.h>

int main(){

  double x, y, vy, vx, v_term, t, g = 9.8;


 double a_linear(double g, double v, double v_term){
   double value;
   value = -g*(1+(v/10.)) ;
   return = (value);
 }
 double a_quad(double g, double v, double v_term){
   double value;
   value = -g*(1+(v*abs(v))/(v_term*v_term))

}
