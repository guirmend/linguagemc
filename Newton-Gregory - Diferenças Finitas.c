#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int n=100,i,j,d,f;
	float x[n],y[n],a,s,k,v[n-1],m[n][n];
	printf("\t Interpolacao de Newton Gregory  \n\n");
	printf("Entre com o numero de termos da tabela: ");
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
	printf("\nA tabela de entradas eh: \n\n");
	for(i=0; i<n; i++)
	{
		printf("%.4f\t%.4f", x[i], y[i]);
		printf("\n");
	}
	for(i=0; i<n-1; i++)
	{
		v[i]=x[i+1]-x[i];
	}
	for(i=0; i<n-2; i++)
	{
		if(v[i]!=v[i+1])
		{
			printf("O metodo nao pode ser utlizado para esta situacao\n");
			system("pause");
			return 0;
		}
	}
	do
	{
		printf("\n\n Entre com o valor de x para encontrar a aproximacao de y: \n");
		scanf("%f", &a);
		for(j=0; j<n; j++)
		{
			for(i=0; i<n; i++)
			{
				if(j==0)
				{
					m[i][j]=y[i];
				}else{
					if(i<n-j)
					{
						m[i][j]=m[i+1][j-1]-m[i][j-1];
					}else{
						m[i][j]=0;
					}
				}
			}
		}
		printf("A tabela das diferencas sera:\n");
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				printf("%.4f\t", m[i][j]);
			}
			printf("\n");
		}
		for(j=0; j<n; j++)
		{
			if(j==0)
			{
				k=m[j][j];
			}else{
				f=1;
				for(i=j;i>0;i--)
				{
					f*=i;
				}
				s=1;
				for(i=0; i<j; i++)
				{
					s*=(a-x[i]);
				}
				k+=s*m[0][j]/(f*pow(v[0],j));
			}
		}
		printf("O valor da aproximacao de x=%.4f eh %.4f\n", a, k);
		printf("\n Quer fazer para um novo valor de f(x)?\n Aperte 1 para continuar ou outra tecla para sair.\n");
		scanf("%d", &d);
	}while(d==1);
	system("pause");
	return 0;
}
