#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

int distancias[100 + 1];
vector<int> grafo[100 + 1];

void bfs(int nodoInicial)
{
	for(int i = 0; i <= 100; ++i)
	{
		distancias[i] = -1;
	}

	queue<int> cola;

	cola.push(nodoInicial);

	//distancias[nodoInicial] = 0;

	while(!cola.empty())
	{
		int nodoActual;

		nodoActual = cola.front();
		cola.pop();

		for(int i = 0; i < grafo[nodoActual].size(); ++i)
		{
			int nodoVecino;

			nodoVecino = grafo[nodoActual][i];

			if(distancias[nodoVecino] == -1)
			{
				//Lo puedo visitar
				distancias[nodoVecino] = 1 + distancias[nodoActual];
				cola.push(nodoVecino);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	
	int n, nodoInicial, nodoConector, cantidadConsultas, verticeInicial;

	while(cin >> n)
	{
		if(n == 0)
		{
			break;
		}

		for(int i = 0; i <= 100; ++i)
		{
			grafo[i].clear();
		}

		while(true)
		{
			cin >> nodoInicial;
			if(nodoInicial == 0)
			{
				break;
			}
			for(;;)
			{
				cin >> nodoConector;
				if(nodoConector == 0)
				{
					break;
				}
				grafo[nodoInicial].push_back(nodoConector);
			}

		}

		cin >> cantidadConsultas;

		for(int i = 0; i < cantidadConsultas; ++i)
		{
			cin >> verticeInicial;
			bfs(verticeInicial);
			//Mostrar como quedo el arreglo distancias
			bool ASiMismo = false;
			for(int i = 0; i < grafo[verticeInicial].size(); ++i)
			{
				if(grafo[verticeInicial][i] == verticeInicial)
				{
					ASiMismo = true;
				}
			}

			// if(ASiMismo == false)
			// {
			// 	distancias[verticeInicial] = 0;
			// }

			vector<int> salida;
			for(int j = 1; j <= n; ++j)
			{
				if(distancias[j] == -1)
				{
					salida.push_back(j);
				}
			}

			if(salida.size() > 0)
			{
				printf("%lu ", salida.size() );
				for(int i = 0; i < salida.size() - 1; ++i)
				{
					printf("%d ", salida[i] );
				}
				printf("%d", salida[salida.size() - 1] );
				printf("\n");
			}
			else
			{
				printf("0\n");
			}
		}

	}

	return 0;
}