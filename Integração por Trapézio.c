#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/* Defina a função de integração aqui: */
 
double f( double x){
  return (1/sqrt( 1 + x*x ));
}
 
main(){
  int n,i;
  double a,b,h,x,sum=0,integral;
  printf("\nColoque os valores dos sub-intervalos 'n': ");
  scanf("%d",&n);
  printf("\nEntre com o valor de limite inicial 'a': ");
  scanf("%lf",&a);
  printf("\nEntre com o valor de limite final 'b': ");
  scanf("%lf",&b);
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
  }
  integral=(h/2)*(f(a)+f(b)+2*sum);
  printf("\nO valor do intervalo eh: %.2f\n",h);
  printf("\nO valor da integracao eh: %lf\n",integral);
}
 

