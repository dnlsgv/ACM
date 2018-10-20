#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int montoInicial, cantidadMonedas = 5;
int monedas[] = {1, 5, 10, 25, 50};
long long dp[30000 + 1][5];

long long back(int montoActual, int indiceActual)
{
	//debug(montoActual);
	if(indiceActual >= cantidadMonedas)
	{
		if(montoActual == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if(montoActual < 0)
	{
		return 0;
	}

	if(montoActual == 0)
	{
		return 1;
	}

	if(dp[montoActual][indiceActual] != -1)
	{
		return dp[montoActual][indiceActual];
	}

	dp[montoActual][indiceActual] = (back(montoActual - monedas[indiceActual], indiceActual) + back(montoActual, indiceActual + 1));

	return dp[montoActual][indiceActual];
}

int main(int argc, char const *argv[])
{
    clock_t tStart = clock();
	for(int i = 0; i < 30000 + 1; ++i)
	{
		for(int j = 0; j < 5; ++j)
		{
			dp[i][j] = -1;
		}
	}

	for(int i = 30000; i >= 0; --i)
	{
		back(i, 0);
	}


	while(cin >> montoInicial)
	{

		long long respuesta = dp[montoInicial][0];

		if(montoInicial == 0)
		{
			respuesta = 1;
		}
		if(respuesta != 1)
		{
			printf("There are %lld ways to produce %d cents change.\n", respuesta, montoInicial );
		}
		else
		{
			printf("There is only 1 way to produce %d cents change.\n", montoInicial );
		}

	}
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

	return 0;
}