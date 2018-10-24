#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int dp[9 + 1][1000 + 1][10000 + 1];
int fuerzas[9 + 1][1000 + 1];
int distancia;

int back(int filaActual, int columnaActual, int combustibleActual)
{
	if(filaActual > 9 || filaActual < 0)
	{
		return 1 << 30;
	}

	if(columnaActual == distancia/100)
	{
		if(filaActual == 9)
		{
			return combustibleActual;
		}
		else
		{
			return 1 << 30;
		}
	}


	if(dp[filaActual][columnaActual][combustibleActual] != -1)
	{
		return dp[filaActual][columnaActual][combustibleActual];
	}

	int subir, bajar, mantenerse;

	subir = back(filaActual - 1, columnaActual + 1, combustibleActual + 60 + (-1 * fuerzas[filaActual][columnaActual]));
	bajar = back(filaActual + 1, columnaActual + 1, combustibleActual + 20 + (-1 * fuerzas[filaActual][columnaActual]));
 	mantenerse = back(filaActual, columnaActual + 1, combustibleActual + 30 + (-1 * fuerzas[filaActual][columnaActual]));

	dp[filaActual][columnaActual][combustibleActual] = min(min(subir, bajar), mantenerse);

	return dp[filaActual][columnaActual][combustibleActual];
}

int main(int argc, char const *argv[])
{
	int T;

	cin >> T;

	while(T--)
	{
		cin >> distancia;

		for(int i = 0; i < 9 + 1; ++i)
		{
			for(int j = 0; j < (distancia/100); ++j)
			{
				cin >> fuerzas[i][j];
			}
		}

		// memset(dp, -1, sizeof(dp[0][0][0]) * (9 + 1) * (1000 + 1) * (10000 + 1));
		for(int i = 0; i < 9 + 1; ++i)
		{
			for(int j = 0; j < (distancia/100); ++j)
			{
				for(int k = 0; k < 10000 + 1; ++k)
				{
					dp[i][j][k] = -1;
				}
			}
		}
		cout << back(9, 0, 0) << endl << endl;
	}
	
	return 0;
}