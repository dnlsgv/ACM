#include <iostream>
#include <algorithm>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int montoMaximo, cantidadPrendas;
int precios[100 + 1];
int valores[100 + 1];
int dp[100 + 1][10000 + 200 + 10];

int back(int indiceActual, int sumatoriaActual)
{
	if(sumatoriaActual > 10000 + 200 + 1)
	{
		return -99999;
	}

	if(indiceActual == cantidadPrendas)
	{
		if(sumatoriaActual > montoMaximo && sumatoriaActual < 2000)
		{
			return -99999;
		}
		else
		{
			//Ver si lo puedo alcanzar
			if(sumatoriaActual > 2000 && montoMaximo + 200 >= sumatoriaActual)
			{
				return 0;
			}
			else
			{
				if(sumatoriaActual <= montoMaximo)
				{
					return 0;
				}
				return -99999;
			}
		}
	}

	if(dp[indiceActual][sumatoriaActual] != -1)
	{
		return dp[indiceActual][sumatoriaActual];
	}

	dp[indiceActual][sumatoriaActual] = max(valores[indiceActual] + back(indiceActual + 1, precios[indiceActual] + sumatoriaActual), back(indiceActual + 1, sumatoriaActual));

	return dp[indiceActual][sumatoriaActual];
}

int main(int argc, char const *argv[])
{
	while(cin >> montoMaximo >> cantidadPrendas)
	{
		for(int i = 0; i < cantidadPrendas; ++i)
		{
			cin >> precios[i] >> valores[i];
		}

		//Configuracion DP
		for(int i = 0; i < 100 + 1; ++i)
		{
			for(int j = 0; j < 10000 + 200 + 10; ++j)
			{
				dp[i][j] = -1;
			}
		}

		if(cantidadPrendas == 0)
		{
			cout << "0" << endl;
		}
		else
		{
			cout << back(0, 0) << endl;
		}
	}
	
	return 0;
}