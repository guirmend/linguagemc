#include <stdio.h>
#include <stdlib.h>

float f(float x,float y)
{
	return 1-x+4*y;
}
int main(int argc, char *argv[])
{
	test:;
	float x,y,h,xn,k1,k2,k3,k4,n,g=0;
	int i,j=-1,z=0;
	printf ("Entre com o valor de 'x0' inicial: ");
	scanf("%f",&x);
	printf ("\nEntro com o valor de 'y0' inicial (eh o 'y' do 'x' inicial): ");
	scanf("%f",&y);
	printf ("\nEntre com o valor de x ('xn') para encontrar y: ");
	scanf("%f",&xn);
	printf ("\nEntre com o valor de h (incremento): ");
	scanf("%f",&h);
	n=(xn-x)/h;
	printf("\nA quantidade de passos sao: %d",n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf ("----------------------------------");
		printf("\n");
		
		    k1 = f(x,y);
		    j++;
		    printf ("\n k%d_1: %.4f\n",j,k1);
		
		        k2 = f((x+h/2),y+((h/2)*k1));
		        printf ("\n k%d_2: %.4f\n",j,k2);
		        
		            k3 = f((x+h/2),y+((h/2)*k2));
		            printf ("\n k%d_3: %.4f\n",j,k3);
		
		                k4 = f(x+h,y+(h*k3));
		                printf ("\n k%d_4: %.4f\n",j,k4);
		
		                    z++;                
		                    y = y+h*(k1+2*k2+2*k3+k4)/6;
		                    printf ("\n y%d = %.4f\n",z,y);
		                    printf("\n");
		
		x = x+h;
		g=g+h;
	}
	printf("O valor de solucao de y(%.1f) eh: %.4f",g,y);
	printf("\n");
	goto test;
	return 0;
}
