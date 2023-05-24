#include <stdio.h>
#include <stdlib.h>

float f(float x,float y)
{
	return 1-x+4*y;
}

int main (){
	
	int n=1001,i,j=0;
	float x0,x,y0,h,y,k;
	printf ("\n Metodo de Euler\n");
	printf ("\nEntre com o valor de 'x0' inicial: ");
	scanf ("%f",&x0);
	printf ("\nEntro com o valor de 'y0' inicial (eh o 'y' do 'x' inicial): ");
	scanf ("%f",&y0);
	printf ("\nEntre com o valor de x ('xn') para encontrar y: ");
	scanf ("%f",&x);
	printf ("\nEntre com o valor de h (incremento): ");
	scanf ("%f",&h);
	n = (x-x0)/h;
	printf("\nA quantidade de passos sao: %d",n);
	printf("\n");
     for (i=0;i<n;i++){
     	k = f (x0,y0);
     	y = y0 + h*k;
     	
     	     j++;
     	     printf ("----------------------------------");
			 printf ("\n \ty%d\tk%d_1\ty%d\n",i,i,j);
     	     printf ("----------------------------------");
		     printf ("\n \t%.4f\t%.4f\t%.4f",y0,k,y);
     	     printf("\n");
     	    
     	y0 = y;
     	x0 = x0 + h;
	 }
	 printf ("\nO valor da solucao de y(%.2f) = %.4f",x,y);
}
