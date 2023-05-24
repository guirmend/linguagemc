#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main()
{
	int i, j, n=10;
	float y0[n], x0[4], xf, x, y, h, k1, k2, k3, k4, e, ec, f[n], fy, ya;
	printf("\t Previsor-Corretor  \n\n");
	printf("Informe o valor inicial x0:\t");
	scanf("%f", &x0[0]);
	printf("Informe o valor inicial y0:\t");
	scanf("%f", &y0[0]);
	printf("Informe o valor final x:\t");
	scanf("%f", &xf);
	printf("Informe o incremento:\t");
	scanf("%f", &h);
	printf("Informe o erro:\t");
	scanf("%f", &e);
	n=(xf-x)/h;
	x=x0[0];
	y=y0[0];
	for(i=1; i<=3; i++)
	{
		k1=1+4*y-x;
		k2=1-x-h/2+4*(y+h*k1/2);
		k3=1-x-h/2+4*(y+h*k2/2);
		k4=1-x-h+4*(y+h*k3);
		y=y+(k1+2*k2+2*k3+k4)*h/6;
		x+=h;
		x0[i]=x;
		y0[i]=y;
	}
	for(i=0; i<4; i++)
	{
		f[i]=1-x0[i]+4*y0[i];
	}
	i=4;
	do{
		j=0;
		y=y0[i-1]+h*(55*f[i-1]-59*f[i-2]+37*f[i-3]-9*f[i-4])/24;
		printf("O valor de y%d^%d = %.4f\n", i, j, y);
		x+=h;
		do{
			j++;
			ya=y;
			fy=1-x+4*y;
			y=y0[i-1]+h*(9*fy+19*f[i-1]-5*f[i-2]+f[i-3])/24;
			ec=(y-ya)/y;
			printf("O valor de y%d^%d = %.4f com erro de %.4f\n", i, j, y, ec);
		}while(ec>e);
		y0[i]=y;
		fy=1-x+4*y;
		f[i]=fy;
		i++;
	}while(xf!=x);
	printf("Logo y(%.4f)=%.4f\n", x,y);
}
