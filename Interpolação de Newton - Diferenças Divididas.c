#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
 
int main(){
	setlocale (LC_ALL, "Portuguese");
  float x[10],y[10][10],sum,p,u,temp;
  int i,n,j,k=0,f,m;
  float fact(int);
  printf("Quantos números serão de entrada: ");
  scanf("%d",&n);
  for(i=0; i<n; i++)
  {
   printf("\n\nColoque os valores de x%d: ",i);
   scanf("%f",&x[i]);
   printf("\n\nColoque os valores de f(x%d): ",i);
   scanf("%f",&y[k][i]);
  }
  printf("\n\nNa entrada X o seu f(x) é: ");
  scanf("%f",&p);
 
  for(i=1;i<n;i++)
  {
    k=i;
    for(j=0;j<n-i;j++)
    {
     y[i][j]=(y[i-1][j+1]-y[i-1][j])/(x[k]-x[j]);
     k++;
    }
  }
  printf("\n_____________________________________________________\n");
  printf("\n  x(i)\t   y(i)\t    y1(i)    y2(i)    y3(i)    y4(i)");
  printf("\n_____________________________________________________\n");
  for(i=0;i<n;i++)
  {
    printf("\n %.3f",x[i]);
    for(j=0;j<n-i;j++)
    {
     printf("   ");
     printf(" %.3f",y[j][i]);
    }
   printf("\n");
  }
 
  i=0;
  do
  {
   if(x[i]<p && p<x[i+1])
    k=1;
   else
    i++;
  }while(k != 1);
  f=i;
 
  sum=0;
  for(i=0;i<n-1;i++)
  {
   k=f;
   temp=1;
   for(j=0;j<i;j++)
   {
    temp = temp * (p - x[k]);
    k++;
   }
    sum = sum + temp*(y[i][f]);
  }
  printf("\n\n f(%.2f) = %f ",p,sum);
}
