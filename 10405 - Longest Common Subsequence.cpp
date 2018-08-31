#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string stringUno, stringDos;

	while(getline(cin, stringUno))
	{
		
		getline(cin, stringDos);
		if(stringDos.size() == 0 || stringUno.size() == 0)
		{
			printf("0\n");
			continue;
		}

		int dp[stringUno.size() + 1][stringDos.size() + 1];

		for(int i = 0; i <= stringUno.size(); ++i) dp[i][0] = 0;
		for(int i = 0; i <= stringDos.size(); ++i) dp[0][i] = 0;

		for(int i = 1; i <= stringUno.size(); ++i)
		{
			for(int j = 1; j <= stringDos.size(); ++j)
			{
				if(stringUno[i - 1] == stringDos[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
		printf("%d\n", dp[stringUno.size()][stringDos.size()] );
	}

	return 0;
}