/*
	Algoritmo DFS
		Ir guardando las distancias(nodosAlcanzados) para evitar hacer muchas llamadas recursivas
*/
#include <iostream>
#include <cstdio>

using namespace std;

int T, N;
bool ciclo;
int ultimoNodo;
int grafo[50000 + 1][1];
bool nodosVisitados[50000 + 1];
int apuntadores[50000 + 1];
int nodosAlcanzados[50000 + 1];

int dfs(int nodoActual)
{
	nodosVisitados[nodoActual] = true;
	int proximoNodo = grafo[nodoActual][0];

	if(apuntadores[proximoNodo] != 0)
	{
		apuntadores[nodoActual] = nodoActual;
		nodosAlcanzados[nodoActual] = 1 + nodosAlcanzados[apuntadores[proximoNodo]];
		return 1 + nodosAlcanzados[apuntadores[proximoNodo]];
	}
	if(nodosVisitados[proximoNodo])
	{
		ciclo = true;
		ultimoNodo = proximoNodo;
		apuntadores[nodoActual] = ultimoNodo;
		return 0;
	}

	int calculo = 1 + dfs(proximoNodo);

	if(nodoActual == ultimoNodo)
	{
		ciclo = false;
		apuntadores[nodoActual] = ultimoNodo; // a si mismo
	}

	if(ciclo)
	{
		apuntadores[nodoActual] = ultimoNodo;
	}
	else
	{
		nodosAlcanzados[nodoActual] = calculo;
		apuntadores[nodoActual] = nodoActual;
	}

	return calculo;
}

int main(int argc, char const *argv[])
{
	int casos = 1;
	cin >> T;

	while(T--)
	{
		cin >> N;
		for(int i = 1; i <= N; ++i)
		{
			int u, v;
			cin >> u >> v;
			grafo[u][0] = v;
		}

		//Configuraciones
		for(int i = 0; i <= N; ++i)
		{
			nodosVisitados[i] = false;
			apuntadores[i] = 0;
			nodosAlcanzados[i] = 0;
		}

		for(int i = 1; i <= N; ++i)
		{
			if(nodosVisitados[i] == 0)
			{
				ciclo = false;
				dfs(i);
			}
		}

		int respuesta = 1;
		int maximosNodos = nodosAlcanzados[apuntadores[1]];
		for(int i = 2; i <= N; ++i)
		{
			if(nodosAlcanzados[apuntadores[i]] > maximosNodos)
			{
				respuesta = i;
				maximosNodos = nodosAlcanzados[apuntadores[i]];
			}
		}

		printf("Case %d: %d\n", casos, respuesta );
		casos++;
	}
	
	return 0;
}