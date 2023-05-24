#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
 
int main(){
	setlocale(LC_ALL, "Portuguese");
    int n=10,i;
    float x[n], y[n], a, b, sx=0, sf=0, sx2=0, sxf=0;
    printf("Entre com os números de termos na tabela: ");
    scanf("%d", &n);
    printf("\n Entre com os valores das variaveis de x: \n");
    for(i=0; i<n; i++){
    	printf("\n Coloque o valor de x%d: \t", i);
    	scanf("%f", &x[i]);
	}
	printf("\n Entre com os valores das variaveis de y: \n ");
	for(i=0; i<n; i++){
		printf("\n Coloque o valor de y%d: \t", i);
		scanf("%f", &y[i]);
	}
	printf("\n A tabela de entrada será: \n");
	for(i=0; i<n; i++){
		printf("%.4f\t%.4f\n", x[i], y[i]);
	}
	for(i=0; i<n; i++){
		sx+=x[i];
		sf+=y[i];
		sx2+=pow(x[i],2);
		sxf+=x[i]*y[i];
	}
	b=(sf-sx*sxf/sx2)/(n-sx*sx/sx2);
	a=(sxf-sx*b)/sx2;
	printf("A equação ficará g(x)=%.4fx+%.4f\n",a,b);
	system("pause");
	return 0;
}
