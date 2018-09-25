#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int cantidadMonedas, sumatoriaMonedas;
int monedas[100 + 1];
int dp[100 + 1][50000 + 1];

int back(int indiceActual, int sumatoriaActual)
{
	if(dp[indiceActual][sumatoriaActual] != -1)
	{
		return dp[indiceActual][sumatoriaActual];
	}
	
	if(indiceActual == cantidadMonedas)
	{
		return abs(sumatoriaActual - (sumatoriaMonedas - sumatoriaActual));
	}

	dp[indiceActual][sumatoriaActual] = min(back(indiceActual + 1, sumatoriaActual + monedas[indiceActual]), back(indiceActual + 1, sumatoriaActual));

	return dp[indiceActual][sumatoriaActual];
}

int main(int argc, char const *argv[])
{
	int T;

	cin >> T;

	while(T--)
	{
		cin >> cantidadMonedas;

		sumatoriaMonedas = 0;

		for(int i = 0; i < cantidadMonedas; ++i)
		{
			cin >> monedas[i];
			sumatoriaMonedas+=monedas[i];
		}

		//Configuracion de DP
		for(int i = 0; i < 100 + 1; ++i)
		{
			for(int j = 0; j < 50000 + 1; ++j)
			{
				dp[i][j] = -1;
			}
		}

		cout << back(0, 0) << endl;
	}
	
	return 0;
}