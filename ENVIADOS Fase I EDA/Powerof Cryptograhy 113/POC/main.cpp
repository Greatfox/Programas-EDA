#include<stdio.h>
#include<math.h>
int main(){
    double n, p;
      while( scanf("%lf %lf",&n,&p) == 2)
            printf("%.0lf\n",pow(10.0L, log10(p)/n));
 return 0;}
