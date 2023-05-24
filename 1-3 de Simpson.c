#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
float f(float x)
{
    return(1/sqrt(1+x*x));
}

int main (){
  int i,n;
  float x0,xn,h,y[1000],somapar,somaimpar,integral,x[1000];
  somapar=0;
  somaimpar=0;
    printf("\nColoque os valores dos intervalos X0,Xn: ");
    scanf("%f%f",&x0,&xn);
    printf("\nColoque o valor do sub-intervalos n: ");
    scanf("%d",&n);
    if(n%2==1){
        n=n+1;
        printf("Como o n e impar vamos transforma-lo em par");
    }
    h=(xn-x0)/n;
    for(i=0; i<=n; i++){
        x[i]=x0+i*h;
        
        y[i]=f(x[i]);
    }
    for(i=1; i<n; i++){
        if(i%2==1){
            somaimpar=somaimpar+y[i];
        }
        else{
            somapar=somapar+y[i];
        }
    }
    integral=h/3*(y[0]+y[n]+4*somaimpar+2*somapar);
    printf("\nO valor da integral por 1/3 de Simpson eh: %0.4f",integral);
 		return 0;
}
