/*
	DP - Top-down
*/
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int M, C;
int preciosPrendas[20 + 1][20 + 1]; //La primera posicion contiene la cantidad de prendas
int dp[200 + 1][20 + 1];

int back(int montoActual, int prendaActual)
{
	if(prendaActual >= C)
	{
		return (montoActual < 0 ? -1 * (1 << 30) : M - montoActual);
	}

	if(montoActual < 0)
	{
		return -1;
	}

	if(dp[montoActual][prendaActual] != -1)
	{
		return dp[montoActual][prendaActual];
	}

	for(int i = 1; i <= preciosPrendas[prendaActual][0]; ++i)
	{
		dp[montoActual][prendaActual] = max(dp[montoActual][prendaActual], back(montoActual - preciosPrendas[prendaActual][i], prendaActual + 1));
	}

	return dp[montoActual][prendaActual];
}

int main(int argc, char const *argv[])
{
	int T;

	cin >> T;

	while(T--)
	{
		cin >> M >> C;

		for(int i = 0; i < 200 + 1; ++i)
		{
			for(int j = 0; j < 20 + 1; ++j)
			{
				dp[i][j] = -1;
			}
		}

		for(int i = 0; i < C; ++i)
		{
			cin >> preciosPrendas[i][0];
			for(int j = 1; j <= preciosPrendas[i][0]; ++j)
			{
				cin >> preciosPrendas[i][j];
			}
		}

		int respuesta = back(M, 0);
		if(respuesta == -1)
		{
			printf("no solution\n");
		}
		else
		{
			printf("%d\n", respuesta);
		}
	}

	return 0;
}