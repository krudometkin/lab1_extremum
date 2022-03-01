#include <stdio.h>
#include <math.h>


double f(double x){
  return 2*sqrt(4*x+3);
}

double method3(int a, int b){
  const double step = 0.1; // why not
  const int cnt = (b-a)/step;
  double xex, yex, y, x=a;

  for (int i=0;i<=cnt;i++){
    y = f(x);
    if (y > yex) {
      xex = x;
      yex = y;
    }
    x += step;
  }

  return xex;
}



double dichotomy(double a, double b){
  const double eps = 0.0001; // why not
  const double delta = eps/2; // why not
  double x1 = (a+b-delta)/2, x2 = (a+b+delta)/2;

  if ((b-a)/2 >= eps){
    if (f(x1) > f(x2)){
      return dichotomy (a, x2);
    } else {
      return dichotomy (x1, b);
    }
  }

   return (a+b)/2;
}
double method4(int a, int b){
  return dichotomy(a, b);
}



double goldenRatio(double a, double b, double x1, double x2, double fx1, double fx2){
  const double eps = 0.0001; // why not
  const double k = (sqrt(5)-1)/2;

  if ((b-a)/2 >= eps){
    if (fx1 < fx2){
      return goldenRatio (x1, b, x2, x1+k*(b-x1), fx2, f(x1+k*(b-x1)));
    } else {
      return goldenRatio (a, x2, a+(1-k)*(x2-a), x1, f(a+(1-k)*(x2-a)), fx1);
    }
  }

   return (a+b)/2;
}

double method5(int a, int b){
  const double k = (sqrt(5)-1)/2;
  return goldenRatio(a, b, a+(1-k)*(b-a), a+k*(b-a), f(a+(1-k)*(b-a)), f(a+k*(b-a)));
}


int main(int argc, char *argv[]){
  const int a=-7, b=12;
  double Xm3 = method3(a, b);
  double Xm4 = method4(a, b);
  double Xm5 = method5(a, b);
  printf("method3: Xmax=%f, f(Xmax)=%f\n", Xm3, f(Xm3));
  printf("method4: Xmax=%f, f(Xmax)=%f\n", Xm4, f(Xm4));
  printf("method5: Xmax=%f, f(Xmax)=%f\n", Xm5, f(Xm5));
}
