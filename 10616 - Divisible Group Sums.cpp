#include <iostream>
#include <cstdio>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

//Elegir M numeros
//Si su sumatoria%D == 0
int N, Q, M, D;
int setDeNumeros[200 + 1];
long long dp[200 + 1][20 + 1][20 + 1];

long long back(int indiceActual, int numerosOcupados, int sumatoriaActual)
{
	// debug(indiceActual);
	// debug(sumatoriaActual);
	// debug(numerosOcupados);
	if(indiceActual == N + 1)
	{
		return 0;
	}
	if(dp[indiceActual][numerosOcupados][sumatoriaActual] != -1)
	{
		return dp[indiceActual][numerosOcupados][sumatoriaActual];
	}
	if(numerosOcupados == M)
	{
		if(sumatoriaActual%D == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(numerosOcupados < M)
		{
			long long modulo = sumatoriaActual + setDeNumeros[indiceActual];
			modulo = modulo%D;
			if(modulo < 0)
			{
				modulo = modulo + D;
			}
			return dp[indiceActual][numerosOcupados][sumatoriaActual] = back(indiceActual + 1, numerosOcupados + 1, modulo) + back(indiceActual + 1, numerosOcupados, sumatoriaActual);
		}
		else
		{
			return 0;
		}
	}
}

int main(int argc, char const *argv[])
{
	int casos = 1;

	while(cin >> N >> Q)
	{
		if(N == 0 && Q == 0)
		{
			break;
		}

		for(int i = 0; i < N; ++i)
		{
			cin >> setDeNumeros[i];
		}

		printf("SET %d:\n", casos );
		for(int i = 0; i < Q; ++i)
		{
			cin >> D >> M;
			for(int a = 0; a < 200 + 1; ++a)
			{
				for(int b = 0; b < 20 + 1; ++b)
				{
					for(int c = 0; c < 20 + 1; ++c)
					{
						dp[a][b][c] = -1;
					}
				}
			}
			printf("QUERY %d: %lld\n", i + 1 , back(0, 0, 0) );
		}
		casos++;
	}
	
	return 0;
}