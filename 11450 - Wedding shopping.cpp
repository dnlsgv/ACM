#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, M, C;
	int dp[20 + 1][200 + 1];
	int vestimentas[20 + 1][20 + 1];

	cin >> T;

	while(T--)
	{

		for(int i = 0; i <= 20; ++i)
		{
			for(int j = 0; j <= 200; ++j)
			{
				dp[i][j] = 0;
			}
		}

		for(int i = 0; i <= 20; ++i)
		{
			for(int j = 0; j <= 20; ++j)
			{
				vestimentas[i][j] = 0;
			}
		}
		cin >> M >> C;

		for(int i = 1; i <= C; ++i)
		{
			int K;
			cin >> K;
			vestimentas[i][0] = K;
			for(int j = 1; j <= K; ++j)
			{
				int valorPrenda;
				cin >> valorPrenda;
				vestimentas[i][j] = valorPrenda;
			}
		}

/*		
		for(int i = 1; i <= C; ++i)
		{
			for(int j = 1; j <= vestimentas[i][0]; ++j)
			{
				printf("%d ", vestimentas[i][j]);
			}
			printf("\n");
		}
		printf("\n");
*/
		for(int i = 1; i <= C; ++i)
		{
			for(int j = 1; j <= M; ++j)
			{
				for(int prenda = 1; prenda <= vestimentas[i][0]; ++prenda)
				{
					if(vestimentas[i][prenda] <= j)
					{
						if(i - 1 == 0)
						{
							dp[i][j] = max(dp[i][j], vestimentas[i][prenda] + dp[i - 1][j - vestimentas[i][prenda]]);
							continue; 
						}

						if(dp[i - 1][j - vestimentas[i][prenda]] != 0)
						{
							dp[i][j] = max(dp[i][j], vestimentas[i][prenda] + dp[i - 1][j - vestimentas[i][prenda]]);
						}
					}
				}
			}
		}

		if(dp[C][M] == 0)
		{
			printf("no solution\n");
		}
		else
		{
			printf("%d\n", dp[C][M] );
		}
		/*for(int i = 0; i <= M; ++i)
		{
			printf("%d ", dp[3][i] );
		}*/
	}




	return 0;
}