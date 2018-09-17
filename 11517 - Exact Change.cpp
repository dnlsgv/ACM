/*
	DP tipo coin change
	Se usa pair para ir buscando lo menor entre 2 parametros
*/
#include <iostream>
#include <utility>
#include <cstdio>
#include <algorithm>

using namespace std;

const int INFINITO = 1 << 30;
#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int cantidadMonedas, montoObjetivo;
int monedas[100 + 1];
bool monedasOcupadas[100 + 1];
pair<int, int> dp[100 + 1][10000 * 2 + 1];

pair<int, int> back(int montoActual, int monedasUsadas)
{
	if(montoActual >= montoObjetivo)
	{
		return pair<int, int>(monedasUsadas, montoActual);
	}
	if(dp[monedasUsadas][montoActual].first != INFINITO && dp[monedasUsadas][montoActual].second != INFINITO)
	{
		return dp[monedasUsadas][montoActual];
	}

	// dp[monedasUsadas][montoActual] = make_pair(INFINITO, INFINITO);
	for(int i = 0; i < cantidadMonedas; ++i)
	{
		if(!monedasOcupadas[i])
		{
			monedasOcupadas[i] = true;
			pair<int, int> respuesta = back(montoActual + monedas[i], monedasUsadas + 1);
			monedasOcupadas[i] = false;
			if(dp[monedasUsadas][montoActual].second > respuesta.second)
			{
				dp[monedasUsadas][montoActual].second = respuesta.second;
				dp[monedasUsadas][montoActual].first = respuesta.first;
			}
			else
			{
				if(respuesta.second == dp[monedasUsadas][montoActual].second)
				{
					dp[monedasUsadas][montoActual].first = min(respuesta.first, dp[monedasUsadas][montoActual].first);
				}
			}
		}
	}

	return dp[monedasUsadas][montoActual];
}

int main(int argc, char const *argv[])
{
	int T;

	cin >> T;

	while(T--)
	{
		cin >> montoObjetivo >> cantidadMonedas;

		for(int i = 0; i < cantidadMonedas; ++i)
		{
			cin >> monedas[i];
			// debug(monedas[i]);
		}

		//Configurar DP
		for(int i = 0; i < 100 + 1; ++i)
		{
			for(int j = 0; j < 10000 * 2 + 1; ++j)
			{
				dp[i][j] = make_pair(INFINITO, INFINITO);
			}
		}
		//Configurar monedas ocupadas
		for(int i = 0; i < 100 + 1; ++i)
		{
			monedasOcupadas[i] = false;
		}

		pair<int, int> respuesta = back(0, 0);
		printf("%d %d\n", respuesta.second, respuesta.first );
	}
	
	return 0;
}