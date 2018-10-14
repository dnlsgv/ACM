#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	string secuencia;
	int cantidadConsultas;

	cin >> secuencia >> cantidadConsultas;

	map<char, vector<int> > mapaDeLetras;

	for(int i = 0; i < secuencia.size(); ++i)
	{
		mapaDeLetras[secuencia[i]].push_back(i);
	}

	vector<string> consultas(cantidadConsultas);

	for(int i = 0; i < cantidadConsultas; ++i)
	{
		cin >> consultas[i];
	}

	for(int i = 0; i < cantidadConsultas; ++i)
	{
		int indiceInicial, indiceFinal, indiceActual, serialNumber;
		for(int j = 0; j < consultas[i].size(); ++j)
		{
			if(j == 0)
			{
				//Primera ocurrencia > a -1
				if(mapaDeLetras.count(consultas[i][j]) == 0)
				{
					indiceInicial = indiceFinal = -1;
					break;
				}
				auto busqueda = upper_bound(mapaDeLetras[consultas[i][j]].begin(), mapaDeLetras[consultas[i][j]].end(), -1);
				// debug(busqueda - mapaDeLetras[consultas[i][j]].begin());
				indiceInicial = mapaDeLetras[consultas[i][j]][busqueda - mapaDeLetras[consultas[i][j]].begin()];
				serialNumber = indiceInicial;
				// debug(serialNumber);
			}
			else
			{
				if(mapaDeLetras.count(consultas[i][j]) == 0)
				{
					indiceInicial = indiceFinal = -1;
					break;
				}

				auto busqueda = upper_bound(mapaDeLetras[consultas[i][j]].begin(), mapaDeLetras[consultas[i][j]].end(), serialNumber);
				serialNumber = mapaDeLetras[consultas[i][j]][busqueda - mapaDeLetras[consultas[i][j]].begin()];
				if(busqueda - mapaDeLetras[consultas[i][j]].begin() == mapaDeLetras[consultas[i][j]].size())
				{
					indiceInicial = indiceFinal = -1;
					break;
				}
			}
			if(j == consultas[i].size() - 1)
			{
				indiceFinal = serialNumber;
			}
		}
		if(indiceInicial == -1 && indiceFinal == -1)
		{
			cout << "Not matched" << endl;
		}
		else
		{
			cout << "Matched " << indiceInicial << " " << indiceFinal << endl; 
		}
	}
	
	return 0;
}