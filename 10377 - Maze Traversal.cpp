#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

int cantidadFilas, cantidadColumnas;
int filaFinal, columnaFinal;
char grid[60 + 1][60 + 1];
map<string, char> mapaDeCombinaciones;
vector<char> comandos;
string apuntando;
string apuntadoFinal;
								//primera llamada = -1
void dfs(int fila, int columna, int indiceInstruccionActual)
{
	indiceInstruccionActual++;

	if(comandos[indiceInstruccionActual] == 'Q')
	{
		filaFinal = fila;
		columnaFinal = columna;
		return;
	}
	else
	{
		if(comandos[indiceInstruccionActual] == 'F') //&& fila - 1 >= 0 && fila + 1 < cantidadFilas && columna - 1 >= 0 && columna + 1 < cantidadColumnas)
		{
			if(apuntando == "N" && grid[fila - 1][columna] != '*')
			{
				dfs(fila - 1, columna, indiceInstruccionActual);

			}
			else if(apuntando == "E" && grid[fila][columna + 1] != '*')
			{
				dfs(fila, columna + 1, indiceInstruccionActual);

			}
			else if(apuntando == "S" && grid[fila + 1][columna] != '*')
			{
				dfs(fila + 1, columna, indiceInstruccionActual);

			}
			else if(apuntando == "W" && grid[fila][columna - 1] != '*')
			{
				dfs(fila, columna - 1, indiceInstruccionActual);
			}
			else
			{
				dfs(fila, columna, indiceInstruccionActual);
			}
		}
		else
		{
			//apuntando+=comandos[indiceInstruccionActual];
			apuntando = mapaDeCombinaciones[apuntando+comandos[indiceInstruccionActual]];
			dfs(fila, columna, indiceInstruccionActual);
		}
	}



}

void mostrarGrid()
{
	for(int i = 0; i < cantidadFilas; ++i)
	{
		//printf("%d: ", i + 1 );
		for(int j = 0; j < cantidadColumnas; ++j)
		{
			printf("%c ", grid[i][j] );
		}
		printf("\n");
	}
}

void mostrarComandos()
{
	for(int i = 0; i < comandos.size(); ++i)
	{
		printf("%c ", comandos[i] );
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
		
	int T, filaInicial, columnaInicial;

	cin >> T;

	mapaDeCombinaciones["NR"] = 'E';
	mapaDeCombinaciones["NL"] = 'W';

	mapaDeCombinaciones["ER"] = 'S';
	mapaDeCombinaciones["EL"] = 'N';

	mapaDeCombinaciones["SR"] = 'W';
	mapaDeCombinaciones["SL"] =  'E';

	mapaDeCombinaciones["WR"] = 'N';
	mapaDeCombinaciones["WL"] = 'S';

	while(T--)
	{
		comandos.clear();
		apuntando = "N";

		scanf("%d %d", &cantidadFilas, &cantidadColumnas);
		string lineaCompleta;
		getline(cin, lineaCompleta);
		for(int i = 0; i < cantidadFilas; ++i)
		{
			getline(cin, lineaCompleta);
			for(int j = 0; j < cantidadColumnas; ++j)
			{
				grid[i][j] = lineaCompleta[j];
			}
		}

		scanf("%d %d", &filaInicial, &columnaInicial);

		char comando;

		while(cin >> comando)
		{
			comandos.push_back(comando);
			if(comando == 'Q')
			{
				break;
			}
		}

		dfs(filaInicial - 1, columnaInicial - 1, -1);

		printf("%d %d %s\n", filaFinal + 1, columnaFinal + 1, apuntando.c_str() );

		if(T != 0)
		{
			printf("\n");
		}
	}

	return 0;
}