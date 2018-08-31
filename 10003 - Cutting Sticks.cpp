/*
	DP con el enfoque TOP-DOWN
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int l, n;
int dp[1000][1000];
int cortes[50];

int back(int inicio, int fin)
{
	//Condicion DP, para no volver a calcular algo ya realizado
	if(dp[inicio][fin] != 100*l)
	{
		return dp[inicio][fin];
	}

	// if(inicio == fin)
	// {
	// 	dp[inicio][fin] = 0;
	// 	return 0;
	// }

	int seLeHizoUnCorte = false;
	for(int i = 0; i < n; ++i)
	{
		int corte = cortes[i];
		if(corte >= fin || corte < inicio)
		{
			continue;
		}
		else
		{
			seLeHizoUnCorte = true;
			// printf("%d + back(%d, %d) + back(%d, %d)\n", fin-inicio, inicio, corte, corte + 1, fin);
			dp[inicio][fin] = min(1+(fin - inicio) + back(inicio, corte) + back(corte + 1, fin), dp[inicio][fin]);
		}
	}
	if(!seLeHizoUnCorte)
	{
		dp[inicio][fin] = 0;
	}
	return dp[inicio][fin];
}

int main(int argc, char const *argv[])
{
	while(cin >> l)
	{
		if(l == 0)
		{
			break;
		}

		cin >> n;

		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &cortes[i]);
		}

		//inicializacion de la tabla de memorizacion
		for(int i = 0; i < 1000; ++i)
		{
			for(int j = 0; j < 1000; ++j)
			{
				dp[i][j] = 100*l;
			}
		}
		printf("The minimum cutting is %d.\n", back(1, l));
	}

	return 0;
}