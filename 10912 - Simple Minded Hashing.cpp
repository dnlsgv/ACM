/*	
	26 letras, casi 27 :( (rip letra ñ)
	Sumatoria maxima de a->z: 351
	DP con enfoque top-down
*/
#include <iostream>
#include <cstdio>

using namespace std;

int L, S;
int dp[26 + 1][26 + 1][351 + 1];

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int back(int lActual, int letraActual, int sumatoriaActual)
{
	if(sumatoriaActual == S)
	{
		if(lActual == L)
		{
			// debug(lActual);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(sumatoriaActual > S)
	{
		return 0;
	}

	if(dp[lActual][letraActual][sumatoriaActual] != -1)
	{
		return dp[lActual][letraActual][sumatoriaActual];
	}

	dp[lActual][letraActual][sumatoriaActual] = 0;

	for(int i = letraActual + 1; i <= 26; ++i)
	{
		dp[lActual][letraActual][sumatoriaActual]+=back(lActual + 1, i, sumatoriaActual + i);
	}

	return dp[lActual][letraActual][sumatoriaActual];
}

int main(int argc, char const *argv[])
{
	int casos = 1;

	while(cin >> L >> S)
	{
		if(L == 0 && S == 0)
		{
			break;
		}

		int respuesta;

		if(L > 26 || S > 351)
		{
			respuesta = 0;
		}
		else
		{
			for(int i = 0; i < 26 + 1; ++i)
			{
				for(int j = 0; j < 26 + 1; ++j)
				{
					for(int k = 0; k < 351 + 1; ++k)
					{
						dp[i][j][k] = -1;
					}
				}
			}
			respuesta = back(0, 0, 0);
		}
		printf("Case %d: %d\n", casos, respuesta );
		casos++;
	}

	return 0;
}