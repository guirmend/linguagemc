#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
main(){
	setlocale(LC_ALL, "Portuguese");
	int n=10,i,j,g=10,count;
	float x[n],y[n],coef[g+1],somax[2*g],somaf[g+1],A[g+1][g+1],b[g+1],ratio,temp;
	printf("\t Método dos mínimos quadrados geral  \n\n");
	printf("Entre com o número de termos da tabela: ");
	scanf("%d", &n);
	printf("\n Entre com os respectivos valores das variaveis de x: \n");
	for(i=0; i<n; i++)
	{
		printf("Insira o valor de x%d: \t", i);
		scanf("%f", &x[i]);
	}
	printf("\n Entre com os respectivos valores das variaveis de y: \n");
	for(i=0; i<n; i++)
	{
		printf("Insira o valor de y%d: \t", i);
		scanf("%f", &y[i]);
	}
	printf("\nA tabela de entradas é: \n\n");
	for(i=0; i<n; i++)
	{
		printf("%.4f\t%.4f", x[i], y[i]);
		printf("\n");
	}
	printf("Informe o grau do polinômio: \n");
	scanf("%d", &g);
	for(i=0;i<2*g;i++)
	{
		somax[i]=0;
		for(j=0;j<n;j++)
		{
			somax[i]+=pow(x[j],i+1);
		}
	}
	for(i=0;i<=g;i++)
	{
		somaf[i]=0;
		for(j=0;j<n;j++)
		{
			somaf[i]+=pow(x[j],i)*y[j];
		}
	}
	for(i=0;i<=g;i++)
	{
		for(j=0;j<=g;j++)
		{
			if(i==g && j==g)
			{
				A[i][j]=n;
			}else{
				A[i][j]=somax[2*g-1-j-i];
			}
		}
	}
	for(i=0;i<=g;i++)
	{
		b[i]=somaf[g-i];
	}
	for (i = 0; i <g; i++) {
        for (j = (i + 1); j < g+1; j++) {
            ratio = A[j][i] / A[i][i];
            for (count = i; count < n; count++) {
                A[j][count] -= (ratio * A[i][count]);
            }
            b[j] -= (ratio * b[i]);
        }
    }
    coef[g] = b[g] / A[g][g];
    for (i = (g - 1); i >= 0; i--) {
        temp = b[i];
        for (j = (i + 1); j < g+1; j++) {
            temp -= (A[i][j] * coef[j]);
        }
        coef[i] = temp / A[i][i];
    }
    printf("A funcao sera:\n");
    for(i=0;i<=g;i++)
    {
    	printf("%.4f*x^%d\t", coef[i], g-i);
	}
}
