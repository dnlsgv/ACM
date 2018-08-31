#include <iostream>
#include <cstdio>

using namespace std;

unsigned long long dp[60 + 1][61 + 1];

unsigned long long trib(int n, int back)
{
	unsigned long long sumatoria = 1;

	if(n <= 1)
	{
		return 1;
	}

	if(dp[n][back] != -1)
	{
		return dp[n][back];
	}

	for(int i = 1; i <= back; ++i)
	{
		sumatoria+=trib(n - i, back);
	}

	dp[n][back] = sumatoria;
	return sumatoria;
}

int main(int argc, char const *argv[])
{
	int n, back, caso;

	caso = 1;
	for(int i = 0; i <= 61; ++i)
	{
		for(int j = 0; j <= 61; ++j)
		{
			dp[i][j] = -1;
		}
	}

	while(cin >> n >> back)
	{
		if(n > 60)
		{
			break;
		}

		if(n <= 1)
		{
			printf("Case %d: %d\n", caso, 1);
		}
		else
		{
			//usar %llu
			//no usar %lld 
			printf("Case %d: %llu\n", caso, trib(n, back));
		}
		
		caso++;
	}

	return 0;
}