#include <stdio.h>
#define LINEAS 2
#define ESTACIONES 6

int min(int a, int b) 
{ 
	return a < b ? a : b; 
}

int produccion(int a[][ESTACIONES], int t[][ESTACIONES], int *e, int *x)
{
	int f1[ESTACIONES], f2[ESTACIONES], i;

	f1[0] = e[0] + a[0][0]; 
	f2[0] = e[1] + a[1][0]; 
	for(i=1;i<ESTACIONES;i++)
	{
		f1[i] = min(f1[i-1] + a[0][i], f2[i-1] + t[1][i] + a[0][i]);
		f2[i] = min(f2[i-1] + a[1][i], f1[i-1] + t[0][i] + a[1][i]);
	}
	return min(f1[ESTACIONES-1] + x[0], f2[ESTACIONES-1] + x[1]);
}

int main()
{
	int a[][ESTACIONES] = {{7, 9, 3, 4, 8, 4},	{8, 5, 6, 4, 5, 7}};
	int t[][ESTACIONES] = {{0, 2, 3, 1, 3, 4},	{0, 2, 1, 2, 2, 1}};
	int e[] = {2, 4}, x[] = {3, 7};
	printf("%d", produccion(a, t, e, x));
	return 0;
}

