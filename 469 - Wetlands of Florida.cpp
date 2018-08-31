#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>

using namespace std;

int cantidadColumnas, cantidadFilas;
int contadorDeAgua;
char grid[100][100];
int gridNumeros[100][100];

void dfs(int fila, int columna)
{
	contadorDeAgua++;
	grid[fila][columna] = '.';
	if(grid[fila - 1][columna] == 'W' && fila - 1 >= 0)
	{
		dfs(fila - 1, columna);
		gridNumeros[fila - 1][columna] = contadorDeAgua;

	}
	if(grid[fila - 1][columna + 1] == 'W' && fila - 1 >= 0 && columna + 1 < cantidadColumnas )
	{
		dfs(fila - 1, columna + 1);
		//gridNumeros[fila - 1][columna + 1] = contadorDeAgua;
	}
	if(grid[fila][columna + 1] == 'W' && columna + 1 < cantidadColumnas)
	{
		dfs(fila, columna + 1);
		//gridNumeros[fila][columna + 1] = contadorDeAgua;
	}
	if(grid[fila + 1][columna + 1] == 'W' && fila + 1 < cantidadFilas && columna + 1 < cantidadColumnas)
	{
		dfs(fila + 1, columna + 1);
		//gridNumeros[fila + 1][columna + 1] = contadorDeAgua;
	}
	if(grid[fila + 1][columna] == 'W' && fila + 1 < cantidadFilas)
	{
		dfs(fila + 1, columna);
		//gridNumeros[fila + 1][columna] = contadorDeAgua;
	}
	if(grid[fila + 1][columna - 1] == 'W' && fila + 1 < cantidadFilas && columna - 1 >= 0)
	{
		dfs(fila + 1, columna - 1);
		//gridNumeros[fila + 1][columna - 1] = contadorDeAgua;
	}
	if(grid[fila][columna - 1] == 'W' && columna - 1 >= 0)
	{
		dfs(fila, columna - 1);
		//gridNumeros[fila][columna - 1] = contadorDeAgua;
	}
	if(grid[fila - 1][columna - 1] == 'W' && fila - 1 >= 0 && columna - 1 >= 0)
	{
		dfs(fila - 1, columna - 1);
		//gridNumeros[fila - 1][columna - 1] = contadorDeAgua;
	}


}

int main(int argc, char const *argv[])
{
	
	int T, contador, casos;
	string TString, primeraLinea, lineaCompleta;
	vector<string> preGrid;
	vector<int> consultas;

	getline(cin, TString);

	//cout << TString << endl;
	T = stoi(TString);
	casos = 0;

	while(T--)
	{
		preGrid.clear();
		consultas.clear();
		contador = 0;
		cantidadFilas = 0;
		memset(gridNumeros, 0, sizeof(gridNumeros[0][0]) * 100 * 100);

		if(casos == 0)
			getline(cin, lineaCompleta);
		
		while(getline(cin, lineaCompleta))
		{
			if(contador == 0)
			{
				cantidadColumnas = lineaCompleta.size();
				contador = 1;
			}
			if(lineaCompleta.size() == 0){
				break;
			}
			else
			{
				if(lineaCompleta.size() != cantidadColumnas || (lineaCompleta[0] != 'W' && lineaCompleta[0] != 'L'))
				{
					//lei una query
					//aplicar sstream
					stringstream ss(lineaCompleta);
					int numero;

					while(ss >> numero)
					{
						consultas.push_back(numero);
					}

				}
				else{
					//cout << lineaCompleta << endl;
					//Armar grid
					preGrid.push_back(lineaCompleta);
					cantidadFilas++;
				}
			}
		}


		for(int i = 0; i < preGrid.size(); ++i)
		{
			for(int j = 0; j < preGrid[i].size(); ++j)
			{
				grid[i][j] = preGrid[i][j];
			}
		}

		/*for(int i = 0; i < cantidadFilas; ++i)
		{
			for(int j = 0; j < cantidadColumnas; ++j)
			{
				printf("%c ", grid[i][j] );
			}
			printf("\n");
		}*/


		//printf("Consultas: \n");
		for(int i = 0; i < consultas.size(); i+=2)
		{
			//printf("{%d, %d}\n", consultas[i], consultas[i + 1] );
		}


		//printf("Filas: %d\n", cantidadFilas );
		//printf("Columnas: %d\n", cantidadColumnas);

		//Ahora puedo aplicar el algoritmo :'), AL FIN!!!!


		for(int i = 0; i < consultas.size(); i+=2)
		{
			contadorDeAgua = 0;
			dfs(consultas[i] - 1, consultas[i + 1] - 1);
			printf("%d\n", contadorDeAgua );
			//Regenerar grafo
			for(int i = 0; i < preGrid.size(); ++i)
			{
				for(int j = 0; j < preGrid[i].size(); ++j)
				{
					grid[i][j] = preGrid[i][j];
				}
			}
		}

		//printf("\n");

		// for(int i = 0; i < cantidadFilas; ++i)
		// {
		// 	for(int j = 0; j < cantidadColumnas; ++j)
		// 	{
		// 		printf("%d ", gridNumeros[i][j]);
		// 	}
		// 	printf("\n");
		// }
		casos++;
		if(T >= 1)
			printf("\n");
	}


	return 0;
}