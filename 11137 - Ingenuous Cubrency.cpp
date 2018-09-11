/*
	Coin change - cuantas formas - con el enfoque bottom-up
*/
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int monedas[21 + 1];
	long long dp[21 + 1][10000];
	int numero;

	monedas[0] = 0;
	for(int i = 1; i < 21 + 1; ++i)
	{
		monedas[i] = pow(i, 3);
	}

	for(int i = 0; i < 21 + 1; ++i)
	{
		for(int j = 0; j < 10000 + 1; ++j)
		{
			dp[i][j] = (i == 1 || j == 0 ? 1 : 0);
		}
	}

	dp[0][0] = 1;

	for(int i = 2; i < 21 + 1; ++i)
	{
		for(int j = 1; j < 10000; ++j)
		{
			if(monedas[i] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - monedas[i]];
			}
		}
	}

	while(cin >> numero)
	{
		cout << dp[21][numero] << endl;
	}

	return 0;
}