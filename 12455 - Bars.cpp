#include <iostream>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int sumaBuscada, cantidadBarras;
int barras[20 + 1];
int dp[20 + 1][1000 + 1];
bool haySolucion;

bool back(int indiceActual, int sumatoriaActual)
{
	if(indiceActual == cantidadBarras)
	{
		if(sumatoriaActual == sumaBuscada)
		{
			haySolucion = 1;
			return true;
		}
		else
		{
			return false;
		}
	}

	if(sumatoriaActual == sumaBuscada)
	{
		return 1;
	}

	if(sumatoriaActual > 1000 + 1)
	{
		return 0;
	}

	if(dp[indiceActual][sumatoriaActual] != -1)
	{
		return dp[indiceActual][sumatoriaActual];
	}

	dp[indiceActual][sumatoriaActual] = (back(indiceActual + 1, sumatoriaActual + barras[indiceActual]) || back(indiceActual + 1, sumatoriaActual));

	return dp[indiceActual][sumatoriaActual];
}

int main(int argc, char const *argv[])
{
	int T;

	cin >> T;

	while(T--)
	{
		cin >> sumaBuscada;
		cin >> cantidadBarras;

		for(int i = 0; i < cantidadBarras; ++i)
		{
			cin >> barras[i];
		}

		haySolucion = false;
		for(int i = 0; i < 20 + 1; ++i)
		{
			for(int j = 0; j < 1000 + 1; ++j)
			{
				dp[i][j] = -1;
			}
		}

		if(sumaBuscada == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << (back(0, 0) == 1 ? "YES" : "NO") << endl;
		}
	}

	return 0;
}