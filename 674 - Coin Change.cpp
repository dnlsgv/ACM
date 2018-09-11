/*
	Coin change con el enfoque bottom-up
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int monedas[6] = {0, 1, 5, 10, 25, 50};
	int dp[6][7489 + 1];
	int numero;

	for(int i = 0; i < 6; ++i)
	{
		for(int j = 0; j < 7489 + 1; ++j)
		{
			dp[i][j] = (i == 1 || j == 0 ? 1 : 0);
		}
	}

	dp[0][0] = 1;

	for(int i = 2; i < 6; ++i)
	{
		for(int j = 1; j < 7489 + 1; ++j)
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
		cout << dp[5][numero] << endl;
	}

	return 0;
}