#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	
	int dp[100 + 1][100 + 1];

	for(int i = 0; i <= 100; ++i)
	{
		dp[0][i] = 0;
		dp[i][0] = 0;
 	}

 	//precalculo de todos los escenarios posibles
 	for(int i = 1; i <= 100; ++i)
 	{
 		dp[1][i] = 1;
 		dp[i][1] = i;
 	}

 	for(int i = 2; i <= 100; ++i)
 	{
 		for(int j = 2; j <= 100; ++j)
 		{
 			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%1000000;
 		}
 	}

 	int N, K;

 	while(cin >> N >> K)
 	{
 		if(N == 0 and K == 0)
 		{
 			break;
 		}
 		/*for(int i = 0; i <= K; ++i)
 		{
 			for(int j = 0; j <= N; ++j)
 			{
 				printf("%d\t", dp[i][j] );
 			}
 			printf("\n");
 		}*/
 		printf("%d\n", dp[K][N] );
 	}


	return 0;
}