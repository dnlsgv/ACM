#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> grafo[9999 + 1];
int nodosVisitados[9999 + 1];

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

void bfs(int nodoInicial)
{
	//Marcar todos los nodos como no visitados
	for(int i = 0; i < 9999 + 1; ++i)
	{
		nodosVisitados[i] = -1;
	}

	queue<int> cola;
	cola.push(nodoInicial);

	nodosVisitados[nodoInicial] = 0;

	while(cola.size() != 0)
	{
		int nodoActual;

		nodoActual = cola.front();
		cola.pop();

		//Encolo todos sus vecinos, que no hayan sido visitados
		for(int i = 0; i < grafo[nodoActual].size(); ++i)
		{
			int siguienteNodo = grafo[nodoActual][i];
			if(nodosVisitados[siguienteNodo] == -1)
			{
				//Lo puedo encolar, no ha sido visitado
				nodosVisitados[siguienteNodo] = 1 + nodosVisitados[nodoActual];
				cola.push(siguienteNodo);
			}
		}

	}

}

int sumar(int valorUno, int valorDos)
{
	//Agregar ceros
	string numeroUno(""), numeroDos("");

	int cerosFaltantes;

	cerosFaltantes = 4 - to_string(valorUno).size();

	for(int i = 0; i < cerosFaltantes; ++i)
	{
		numeroUno+="0";
	}
	numeroUno+=to_string(valorUno);
	// debug(numeroUno);

	cerosFaltantes = 4 - to_string(valorDos).size();
	for(int i = 0; i < cerosFaltantes; ++i)
	{
		numeroDos+="0";
	}
	numeroDos+=to_string(valorDos);
	// debug(numeroDos);

	vector<int> digitosMenosSignificativos;
	int resto = 0;

	for(int i = 3; i >= 0; --i)
	{
		int calculo = ((int(numeroUno[i] - '0') + int(numeroDos[i] - '0')) + resto);

		if(calculo > 9)
		{
			digitosMenosSignificativos.push_back(calculo%10);
			resto = 1;
		}
		else
		{
			digitosMenosSignificativos.push_back(calculo);
			resto = 0;
		}
	}

	string salida = "";

	reverse(digitosMenosSignificativos.begin(), digitosMenosSignificativos.end());

	for(int i = 0; i < 4; ++i)
	{
		// debug(digitosMenosSignificativos[i]);
		salida+=char(digitosMenosSignificativos[i] + '0');
	}

	// debug(salida);

	return stoi(salida);
}

int main(int argc, char const *argv[])
{

	int nodoInicial, nodoFinal, cantidadBotones;
	int valorBotones[10 + 1], casos = 1;

	while(cin >> nodoInicial >> nodoFinal >> cantidadBotones)
	{
		if(nodoInicial == 0 && nodoFinal == 0 && cantidadBotones == 0)
		{
			break;
		}

		for(int i = 0; i < 9999 + 1; ++i)
		{
			grafo[i].clear();
		}

		for(int i = 0; i < cantidadBotones; ++i)
		{
			cin >> valorBotones[i];
		}

		//Armar grafo
		for(int i = 0; i < 9999 + 1; ++i)
		{
			for(int j = 0; j < cantidadBotones; ++j)
			{
				int suma = sumar(i, valorBotones[j]);

				grafo[i].push_back(suma);
			}
		}

		bfs(nodoInicial);

		printf("Case %d: ", casos);

		if(nodosVisitados[nodoFinal] == -1)
		{
			printf("Permanently Locked\n");
		}
		else
		{
			printf("%d\n", nodosVisitados[nodoFinal] );
		}
		casos++;
	}

	return 0;
}