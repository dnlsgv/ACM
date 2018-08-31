#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int grid[1000 + 1][1000 + 1];
int gridCopia[1000 + 1][1000 + 1];
int R, C;
pair<int, int> posicionInicial;
pair<int, int> posicionFinal;

void setearGrid()
{
	for(int i = 0; i < 1000 + 1; ++i)
	{
		for(int j = 0; j < 1000 + 1; ++j)
		{
			grid[i][j] = 0;
			gridCopia[i][j] = 0;
		}
	}
}

void mostrarGrid()
{
	for(int i = 0; i < R; ++i)
	{
		for(int j = 0; j < C; ++j)
		{
			printf("%d\t", gridCopia[i][j] );
		}
		printf("\n");
	}
}

void bfs()
{

	queue<pair<int, int> > colaDePosiciones;

	colaDePosiciones.push(posicionInicial);

	gridCopia[posicionInicial.first][posicionInicial.second] = 0;

	while(colaDePosiciones.size() != 0)
	{
		pair<int, int> casillaActual = colaDePosiciones.front();
		colaDePosiciones.pop();

		//.first = row
		//.second = column
		if(casillaActual.first - 1 >= 0 && gridCopia[casillaActual.first - 1][casillaActual.second] == 0 && grid[casillaActual.first - 1][casillaActual.second] != -1)
		{
			gridCopia[casillaActual.first - 1][casillaActual.second] = 1 + gridCopia[casillaActual.first][casillaActual.second];
			colaDePosiciones.push(make_pair(casillaActual.first - 1, casillaActual.second));
		}

		if(casillaActual.second + 1 < C && gridCopia[casillaActual.first][casillaActual.second + 1] == 0 && grid[casillaActual.first][casillaActual.second + 1] != -1)
		{
			gridCopia[casillaActual.first][casillaActual.second + 1] = 1 + gridCopia[casillaActual.first][casillaActual.second];
			colaDePosiciones.push(make_pair(casillaActual.first, casillaActual.second + 1));
		}

		if(casillaActual.first + 1 < R && gridCopia[casillaActual.first + 1][casillaActual.second] == 0 && grid[casillaActual.first + 1][casillaActual.second] != -1)
		{
			gridCopia[casillaActual.first + 1][casillaActual.second] = 1 + gridCopia[casillaActual.first][casillaActual.second];
			colaDePosiciones.push(make_pair(casillaActual.first + 1, casillaActual.second));
		}

		if(casillaActual.second - 1 >= 0 && gridCopia[casillaActual.first][casillaActual.second - 1] == 0 && grid[casillaActual.first][casillaActual.second - 1] != -1)
		{
			gridCopia[casillaActual.first][casillaActual.second - 1] = 1 + gridCopia[casillaActual.first][casillaActual.second];
			colaDePosiciones.push(make_pair(casillaActual.first, casillaActual.second - 1));
		}
	}
}

int main(int argc, char const *argv[])
{
	
	int filasConBombas;

	while(cin >> R >> C)
	{
		if(R == 0 && C == 0)
		{
			break;
		}

		setearGrid();

		cin >> filasConBombas;

		for(int i = 0; i < filasConBombas; ++i)
		{
			int filaQueContieneBomba, cantidadBombas;

			cin >> filaQueContieneBomba >> cantidadBombas;

			for(int j = 0, columnaBomba; j < cantidadBombas; ++j)
			{
				cin >> columnaBomba;
				grid[filaQueContieneBomba][columnaBomba] = -1;
			}
		}

		int filaInicial, columnaInicial, filaFinal, columnaFinal;

		cin >> filaInicial >> columnaInicial;
		posicionInicial = make_pair(filaInicial, columnaInicial);

		cin >> filaFinal >> columnaFinal;
		posicionFinal = make_pair(filaFinal, columnaFinal);

		//printf("%d %d\n", posicionInicial.first, posicionInicial.second );
		//printf("%d %d\n", posicionFinal.first, posicionFinal.second);

		//mostrarGrid();
		bfs();
		//mostrarGrid();
		printf("%d\n", gridCopia[posicionFinal.first][posicionFinal.second] );		
	}

	return 0;
}