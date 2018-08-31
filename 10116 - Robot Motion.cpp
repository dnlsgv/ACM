#include <iostream>
#include <string.h>

using namespace std;

char grid[10][10];
int gridVisitados[10][10];
int pasos, pasosLoop;
int cantidadFilas, cantidadColumnas, columnaDeInicio;
int filaLoop, columnaLoop;
bool huboLoop;

void dfs(int fila, int columna)
{
	if(gridVisitados[fila][columna] == 1)
	{
		huboLoop = true;
		filaLoop = fila;
		columnaLoop = columna;
		return;
	}

	gridVisitados[fila][columna] = 1;
	pasos++;

	if(grid[fila][columna] == 'N')
	{
		if(fila - 1 < 0)
		{
			return;
		}
		else
		{
			dfs(fila - 1, columna);
		}
	}
	if(grid[fila][columna] == 'E')
	{
		if(columna + 1 > cantidadColumnas - 1)
		{
			return;
		}
		else
		{
			dfs(fila, columna +1);
		}
	}
	if(grid[fila][columna] == 'S')
	{
		if(fila + 1 > cantidadFilas - 1)
		{
			return;
		}
		else
		{
			dfs(fila + 1, columna);
		}
	}
	if(grid[fila][columna] == 'W')
	{
		if(columna - 1 < 0)
		{
			return;
		}
		else
		{
			dfs(fila, columna - 1);
		}
	}

	if(huboLoop)
	{
		pasosLoop++;
	}
	if(filaLoop == fila && columnaLoop == columna)
	{
		huboLoop = false;
	}
}


int main(int argc, char const *argv[])
{
	
	while(cin >> cantidadFilas >> cantidadColumnas >> columnaDeInicio)
	{
		if(cantidadFilas == 0 && cantidadColumnas == 0 && columnaDeInicio == 0)
		{
			break;
		}

		pasos = 0;
		char caracter;

		for(int i = 0; i < cantidadFilas; ++i)
		{
			for(int j = 0; j < cantidadColumnas; ++j)
			{
				cin >> caracter;
				grid[i][j] = caracter;
			}
		}

		huboLoop = false;
		filaLoop = columnaLoop = -1;
		pasosLoop = 0;
		//memset(gridVisitados, 0, sizeof(gridVisitados[0][0]) * cantidadFilas * cantidadColumnas);

		for(int i = 0; i < cantidadFilas; ++i)
		{
			for(int j = 0; j < cantidadColumnas; ++j)
			{
				gridVisitados[i][j] = 0;
			}
		}

		dfs(0, columnaDeInicio - 1);

		if(pasosLoop == 0)
		{
			printf("%d step(s) to exit\n", pasos);
		}
		else
		{
			printf("%d step(s) before a loop of %d step(s)\n", pasos - pasosLoop, pasosLoop );
		}
	}

	return 0;
}