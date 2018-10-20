#include <iostream>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int n, k, m;
long long dp[50 + 1][50 + 1];

long long back(int anchoActual, int barrasUsadas)
{
	if(anchoActual > n)
	{
		return 0;
	}
	if(barrasUsadas == k)
	{
		if(anchoActual == n)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if(dp[anchoActual][barrasUsadas] != -1)
	{
		return dp[anchoActual][barrasUsadas];
	}

	dp[anchoActual][barrasUsadas] = 0;
	for(int i = 1; i <= m; ++i)
	{
		dp[anchoActual][barrasUsadas]+=(back(anchoActual + i, barrasUsadas + 1));
	}

	return dp[anchoActual][barrasUsadas];
}

int main(int argc, char const *argv[])
{
	
	while(cin >> n >> k >> m)
	{
		for(int i = 0; i < 50 + 1; ++i)
		{
			for(int j = 0; j < 50 + 1; ++j)
			{
				dp[i][j] = -1;
			}
		}
		//debug(m);
		cout << back(0, 0) << endl;
	}	

	return 0;
}