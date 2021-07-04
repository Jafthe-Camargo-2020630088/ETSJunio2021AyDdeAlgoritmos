#include<stdio.h>
#include<stdlib.h>

int main()
{
	int q, w, e, r, i, j, k;
	
	printf("Filas de la Matriz 1: ");
	scanf("%d", &q);
	printf("Columnas de la Matriz 1: ");
	scanf("%d", &w);
	printf("\n");
	
	printf("Filas de la Matriz 2: ");
	scanf("%d", &e);
	printf("Columnas de la Matriz 2: ");
	scanf("%d", &r);
	printf("\n");
	
	int a[q][w], b[e][r], c[q][r];
	
	if(w==e)
	{
		printf("Primer Matriz [%dx%d]\n", q,w);
		for(i=1;i<=q;i++) //Filas
		{
			for(j=1;j<=w;j++) //Columnas
			{ 
				printf("Valor de [%d][%d]: ",i,j);
				scanf("%d", &a[i][j]);
			}
		}
	
		printf("\nSegunda Matriz [%dx%d]\n", e,r);
		for(i=1;i<=e;i++) //Filas
		{
			for(j=1;j<=r;j++) //Columnas
			{ 
				printf("Valor de [%d][%d]: ",i,j);
				scanf("%d", &b[i][j]);
			}
		}
	
		for(i=1;i<=q;i++) //Filas
		{
			for(j=1;j<=r;j++) //Columnas
			{ 
				c[i][j] = 0;
				for(k=1;k<=w;k++)
				{
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		printf("\nResultado\n");
		for(i=1;i<=q;i++) //Filas
		{
			for(j=1;j<=r;j++) //Columnas
			{ 
				printf(" %d ", c[i][j]);
			}
			printf("\n");
		}
	} else
	printf("El Numero de Columnas de la Matriz 1 Debe ser el Mismo que el Numero de Filas" 
	"de la Matriz 2\n");
}
