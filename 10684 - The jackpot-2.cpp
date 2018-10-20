#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int N;
	long long sumatoria, maximaApuesta;
	int apuestas[10000 + 1];

	while(cin >> N)
	{
		if(N == 0)
		{
			break;
		}

		for(int i = 0; i < N; ++i)
		{
			cin >> apuestas[i];
		}

		maximaApuesta = sumatoria = 0;

		for(int i = 0; i < N; ++i)
		{
			sumatoria+=apuestas[i];
			maximaApuesta = max(maximaApuesta, sumatoria);

			if(sumatoria < 0)
			{
				sumatoria = 0;
			}
		}

		if(maximaApuesta == 0)
		{
			printf("Losing streak.\n");
		}
		else
		{
			printf("The maximum winning streak is %lld.\n", maximaApuesta );
		}
	}
	
	return 0;
}