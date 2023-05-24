#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
		setlocale(LC_ALL, "Portuguese");
    int n=10000,i,j,d;
    float x[n],y[n],a,s,k;
    printf("\t Interpolação de Lagrange \n\n");
    
    printf("Entre com o numero de termos da tabela: ");
    scanf("%d",&n);
    printf("\n Entre com os respectivos valores das variaveis de x: \n");
    for(i=0;i<n;i++){
        printf("Insira o valor de x%d:\t",i);
        scanf("%f",&x[i]);
    }
    printf("\n Entre com os respectivos valores das variaveis de y: \n");
    for(i=0;i<n;i++){
        printf("Insira o valor de y%d :\t",i);
        scanf("%f",&y[i]);
    }
    printf("\nA tabela de entradas é : \n\n");
    for(i=0;i<n;i++){
        printf("%0.4f\t%0.4f",x[i],y[i]);
        printf("\n");
    }
    do{
        k=0;
        printf("\n\n Entre com o valor de x para  a aproximação de y\n\n");
        scanf("%f",&a);
        for(i=0;i<n;i++){
            s=1;
            for(j=0;j<n;j++){
                if(j!=i){
                    s*=(a-x[j])/(x[i]-x[j]);
                }
            }
        printf("\n");
        printf("L_%d=%0.5f\n",i,s);
        k+=(s*y[i]);
    }
    printf("\n O valor de f(x) é aproximadamente: %.5f\n)",k);
    printf("\n Quer fazer para um novo valor de f(x)?\n\n Aperte 1 para continuar ou qualquer tecla para sair");
    scanf("%d",&d);
}while(d==1);   
}
