/*
	DP con enfoque Bottom-Up
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int preCalculo[100 + 1];
	int dp[10000 + 1];
	int M, N;

	preCalculo[0] = 0;

	for(int i = 1; i < 100 + 1; ++i)
	{
		preCalculo[i] = i * i;
	}

	for(int i = 0; i < 10000 + 1; ++i)
	{
		dp[i] = 1 << 30;
	}

	//Casos bases
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 1;

	for(int i = 5; i < 10000 + 1; ++i)
	{
		for(int j = 1; ; ++j)
		{
			if(preCalculo[j] > i)
			{
				break;
			}
			dp[i] = min(dp[i], 1 + dp[i - preCalculo[j]]);
			// printf("dp[%d] = %d\n", i, dp[i]);

		}
		// break;
	}

	cin >> M;

	while(M--)
	{
		cin >> N;
		cout << dp[N] << endl;
	}

	return 0;
}