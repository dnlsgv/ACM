#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

vector<int> grafo[2500];
int nodosVisitados[2500];
int contactadosElDia[2500];
vector<int> casosDePrueba;

void bfs(int nodoInicial)
{
	for(int i = 0; i < 2500; ++i)
	{
		nodosVisitados[i] = -1;
		contactadosElDia[i] = 0;
	}

	queue<int> cola;

	nodosVisitados[nodoInicial] = 0;
	cola.push(nodoInicial);

	while(cola.size() != 0)
	{
		int nodoActual;

		nodoActual = cola.front();
		cola.pop();

		for(int i = 0; i < grafo[nodoActual].size(); ++i)
		{
			if(nodosVisitados[grafo[nodoActual][i]] == -1)
			{
				//No ha sido visitado
				//Lo encolo
				nodosVisitados[grafo[nodoActual][i]] = 1 + nodosVisitados[nodoActual];
				contactadosElDia[nodosVisitados[nodoActual] + 1]++;
				cola.push(grafo[nodoActual][i]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	
	int E, T;

	while(cin >> E)
	{
		casosDePrueba.clear();
		int cantidadVecinos;
	
		for(int i = 0; i < E; ++i)
		{
			cin >> cantidadVecinos;
			for(int j = 0; j < cantidadVecinos; ++j)
			{
				int nodoVecino;
				cin >> nodoVecino;
				grafo[i].push_back(nodoVecino);
			}
		}

		cin >> T;

		for(int i = 0, nodoInicial; i < T; ++i)
		{
			cin >> nodoInicial;
			casosDePrueba.push_back(nodoInicial);
		}

		for(int i = 0; i < T; ++i)
		{
			bfs(casosDePrueba[i]);

			int valorMayor, dia;

			valorMayor = -1;

			for(int j = 0; j < E; ++j)
			{
				if(contactadosElDia[j] > valorMayor)
				{
					valorMayor = contactadosElDia[j];
					dia = j;
				}
			}
			if(valorMayor == 0 && dia == 0)
			{
				printf("0\n");
			}
			else
			{
				printf("%d %d\n", valorMayor, dia );
			}
		}
	}

	return 0;
}