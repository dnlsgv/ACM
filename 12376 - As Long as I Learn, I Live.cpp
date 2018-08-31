#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;

vector<int> grafo[100 + 1];
int conocimiento[100 + 1];
int sumaMaxima, ultimoNodo;

void dfs(int nodoActual)
{
	int montoMaximoConocimiento, indiceMaximoConocimiento, proximoNodo;

	montoMaximoConocimiento = 0;

	if(grafo[nodoActual].size() > 0)
	{
		for(int i = 0; i < grafo[nodoActual].size(); ++i)
		{
			if(conocimiento[grafo[nodoActual][i]] > montoMaximoConocimiento)
			{
				montoMaximoConocimiento = conocimiento[grafo[nodoActual][i]];
				indiceMaximoConocimiento = i;
				proximoNodo = grafo[nodoActual][i];
			}
		}
		sumaMaxima+=montoMaximoConocimiento;
		//printf("Maximo conocimiento desde %d: %d\n", nodoActual, montoMaximoConocimiento);
		ultimoNodo = proximoNodo;
		dfs(proximoNodo);
	}
}


int main(int argc, char const *argv[])
{
	int T, N, M, casos;

	cin >> T;

	casos = 1;

	while(T--)
	{
		sumaMaxima = 0;
		ultimoNodo = 0;

		cin >> N >> M;

		memset(conocimiento, 0, sizeof(conocimiento[0]) * (N + 1));

		for(int i = 0; i < 100 + 1; ++i) grafo[i].clear();

		for(int i = 0, valor; i < N; ++i)
		{
			cin >> valor;
			conocimiento[i] = valor; 
		}

		for(int i = 0; i < M; ++i)
		{
			int u, v;
			cin >> u >> v;
			grafo[u].push_back(v);
		}

		dfs(0);

		printf("Case %d: %d %d\n", casos, sumaMaxima, ultimoNodo );
		casos++;
	}


	return 0;
}