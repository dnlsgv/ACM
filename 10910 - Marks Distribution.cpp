/*
	Dynamic programming con enfoque bottom up =D
*/
#include <iostream>
#include <cstdio>

using namespace std;

int dp[70 + 1][70 + 1];

void setearMemorizacion()
{
	for(int i = 0; i < 70 + 1; ++i)
	{
		for(int j = 0; j < 70 + 1; ++j)
		{
			dp[i][j] = 0;
		}
	}

}

int main(int argc, char const *argv[])
{
	
	int K, N, T, P;

	cin >> K;

	while(K--)
	{
		cin >> N >> T >> P;

		if(N == 1)
		{
			cout << 1 << endl;
			continue;
		}

		setearMemorizacion();
		//Generacion de los casos bases
		for(int i = P; i < 70 + 1; ++i)
		{
			dp[1][i] = 1;
		}

		for(int i = 2; i <= N; ++i)
		{
			for(int j = 1; j <= T; ++j)
			{
				for(int k = P; ; ++k)
				{
					int resto = j - k;

					if(resto < P)
					{
						break;
					}
					else
					{
						dp[i][j]+=dp[i - 1][resto];
					}
				}
			}
		}
		cout << dp[N][T] << endl;
	}

	return 0;
}