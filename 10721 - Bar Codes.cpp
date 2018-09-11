/*
	DP con enfoque top-down
*/
#include <iostream>

using namespace std;

int N, K, M;
long long dp[50 + 1][50 + 1];

long long back(int barrasUsadas, int sumaActual)
{
	if(dp[barrasUsadas][sumaActual] != -1)
	{
		return dp[barrasUsadas][sumaActual];
	}

	if(barrasUsadas == K)
	{
		if(sumaActual == N)
		{
			dp[barrasUsadas][sumaActual] = 1;
			return 1;
		}
		else
		{
			dp[barrasUsadas][sumaActual] = 0;
			return 0;
		}
	}
	else
	{
		if(sumaActual > N)
		{
			dp[barrasUsadas][sumaActual] = 0;
			return 0;
		}
	}

	dp[barrasUsadas][sumaActual] = 0;
	for(int i = 1; i <= M; ++i)
	{
		if(sumaActual + i <= N)
			dp[barrasUsadas][sumaActual]+= back(barrasUsadas + 1, sumaActual + i);
	}

	return dp[barrasUsadas][sumaActual];
}


int main(int argc, char const *argv[])
{
	while(cin >> N >> K >> M)
	{
		for(int i = 0; i < 50 + 1; ++i)
		{
			for(int j = 0; j < 50 + 1; ++j)
			{
				dp[i][j] = -1;
			}
		}
		cout << back(0, 0) << endl;
	}

	return 0;
}