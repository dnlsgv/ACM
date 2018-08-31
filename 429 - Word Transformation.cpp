#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	string Tstring;	
	int T;

	getline(cin, Tstring);
	T = stoi(Tstring);
	
	while(T--)
	{

		string palabra;
		map<int, vector<string> > diccionario;
		vector<string> consultas;

		while(cin >> palabra)
		{
			if(palabra == "*")
			{
				break;
			}
			else
			{
				diccionario[palabra.size()].push_back(palabra);
			}
		}

		//Ahora vienen las consultas
		string lineaCompleta;
		getline(cin, lineaCompleta);
		while(getline(cin, lineaCompleta))
		{
			if(lineaCompleta.size() == 0)
			{
				break;
			}
			stringstream ss(lineaCompleta);
			string palabra;
			while(ss >> palabra)
			{
				consultas.push_back(palabra);
			}
		}

		for(int i = 0; i < consultas.size(); i+=2)
		{

			string stringInicial, stringFinal;

			stringInicial = consultas[i]; 
			stringFinal = consultas[i + 1];


			int cantidadNodos = diccionario[stringInicial.size()].size();
			int posicionNodoInicial, posicionNodoFinal;

			for(int n = 0; n < cantidadNodos; ++n)
			{
				if(diccionario[stringInicial.size()][n] == stringInicial)
				{
					posicionNodoInicial = n;
				}
			}

			int nodosVisitados[cantidadNodos];
			for(int v = 0; v < cantidadNodos; ++v) nodosVisitados[v] = -1;

			queue<int> colaDeNodos;

			colaDeNodos.push(posicionNodoInicial);
			nodosVisitados[posicionNodoInicial] = 0;

			while(colaDeNodos.size() != 0)
			{
				int nodoActual = colaDeNodos.front();
				colaDeNodos.pop();

				string palabraActual = diccionario[stringInicial.size()][nodoActual];

				//Buscar todos quienes se diferencien en 1 caracter
				int diferencias = 0;
				for(int i = 0; i < cantidadNodos; ++i)
				{
					diferencias = 0;
					if(nodosVisitados[i] == -1)
					{
						string palabraComparar = diccionario[stringInicial.size()][i];
						for(int j = 0; j < palabraComparar.size(); ++j)
						{
							if(palabraActual[j] != palabraComparar[j])
							{
								diferencias++;
							}
						}
						if(palabraComparar == stringFinal)
						{
							posicionNodoFinal = i;
						}
					}
					if(diferencias == 1)
					{
						nodosVisitados[i] = 1 + nodosVisitados[nodoActual];
						colaDeNodos.push(i);
					}
				}

			}

			if(stringInicial == stringFinal)
			{
				printf("%s %s %d\n", stringInicial.c_str(), stringFinal.c_str(), 0 );
			}
			else
			{
				printf("%s %s %d\n", stringInicial.c_str(), stringFinal.c_str(), nodosVisitados[posicionNodoFinal] );
			}
		}

		if(T != 0)
		{
			printf("\n");
		}

	}
	return 0;
}