#include <bits/stdc++.h>

using namespace std;
  
const int MAX = 100;
int almacen[MAX], n;
int grafo[MAX][MAX];
int peso[MAX];
  
bool clique(int b)
{
    for (int i=1;i<b;i++) 
	{
        for (int j=i+1;j<b;j++)
            if (grafo[almacen[i]][almacen[j]] == 0)
            	return false;
    }
    return true;
}

int max_clique(int i, int l)
{
    int maximal = 0;
    for (int j=i+1;j<=n;j++) 
	{
        almacen[l] = j;
        if (clique(l + 1)) 
		{
            maximal = max(maximal, l);
            maximal = max(maximal, max_clique(j, l + 1));
        }
    }
    return maximal;
}
  
int main()
{
    int vertices[][2] = { {1, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 3}, {3, 5}, {3, 6}, {5, 6}, {5, 7} };
    int tam = sizeof(vertices) / sizeof(vertices[0]);
    n = 7;
    for (int i=0;i<tam;i++) 
	{
    	grafo[vertices[i][0]][vertices[i][1]] = 1;
        grafo[vertices[i][1]][vertices[i][0]] = 1;
        peso[vertices[i][0]]++;
        peso[vertices[i][1]]++;
    }
    cout << max_clique(0, 1);
    return 0;
}
