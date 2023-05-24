#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x,float y)
{
       return 1-x+4*y;
}

int main (){
	int n=1000,i,j=-1,z=0;
	float x0,x,k1,y,y0,h,k2,k3,k4,a=0;
	printf ("\n Metodo de Euler Aprimorado: ");
	printf("\n");
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
	y=y0;
	for (i=0;i<n;i++){
	printf ("----------------------------------");
	printf("\n");
	
		k1 = f(x0,y);
		j++;
		printf ("\n k%d_1: %.4f\n",j,k1);
		
		    x0 = x0+h;
		
		        k2 = f(x0,(y+h*k1));
		        printf ("\n k%d_2: %.4f\n",j,k2);
	                
					z++;
		            y = y+h*(k1+k2)/2;
		            
	printf ("\n y%d = %.4f\n",z,y);
	printf("\n");
	}
	printf ("\n A solucao de y(%.2f) = %.4f",x,y);
	printf("\n");
	system("pause");
	return 0;
}
