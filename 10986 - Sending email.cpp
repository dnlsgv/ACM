#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

typedef pair<int, int> arista; //peso, nodo
vector<arista> grafo[20000 + 1];
const int INFINITO = 1 << 30; // pow(2, 30)
int distanciasMinimas[20000 + 1];
int padre[20000 + 1];

void dijkstra(int nodoInicial, int cantidadNodos)
{
	for(int i = 0; i < cantidadNodos; ++i)
	{
		distanciasMinimas[i] = INFINITO;
		padre[i] = -1;
	}

	priority_queue<arista, vector<arista>, greater<arista> > colaDePrioridad;

	distanciasMinimas[nodoInicial] = 0;
	colaDePrioridad.push(arista(0, nodoInicial));

	while(!colaDePrioridad.empty())
	{
		int distancia = colaDePrioridad.top().first;
		int nodoActual = colaDePrioridad.top().second;
		colaDePrioridad.pop();

		if(distancia > distanciasMinimas[nodoActual])
		{
			continue;
		}
		for(int i = 0; i < grafo[nodoActual].size(); ++i)
		{
			int siguienteNodo = grafo[nodoActual][i].second;
			int pesoExtra = grafo[nodoActual][i].first;

			if(distanciasMinimas[nodoActual] + pesoExtra < distanciasMinimas[siguienteNodo])
			{
				distanciasMinimas[siguienteNodo] = distanciasMinimas[nodoActual] + pesoExtra;
				padre[siguienteNodo] = nodoActual;
				colaDePrioridad.push(arista(distanciasMinimas[siguienteNodo], siguienteNodo));
			}
		}
	}
}


int main(int argc, char const *argv[])
{

	int casosDePrueba, n, m, nodoInicial, nodoFinal, casos;

	cin >> casosDePrueba;
	casos = 1;
	while(casosDePrueba--)
	{
		//Limpiar grafo
		for(int i = 0; i < 20000 + 1; ++i)
		{
			grafo[i].clear();
		}

		cin >> n >> m >> nodoInicial >> nodoFinal;

		for(int i = 0; i < m; ++i)
		{
			int u, v, w;

			cin >> u >> v >> w;

			grafo[u].push_back(make_pair(w, v));
			grafo[v].push_back(make_pair(w, u));
		}

		dijkstra(nodoInicial, n + 1);

		if(distanciasMinimas[nodoFinal] == 1 << 30)
		{
			printf("Case #%d: unreachable\n", casos);
		}
		else
		{
			printf("Case #%d: %d\n", casos, distanciasMinimas[nodoFinal] );
		}

		casos++;
		//break;
	}
	
	return 0;
}