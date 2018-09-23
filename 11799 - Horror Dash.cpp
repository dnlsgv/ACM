#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, N, casos = 1;

	cin >> T;
	
	while(T--)
	{
		cin >> N;

		int minimo = -1;

		for(int i = 0, aux; i < N; ++i)
		{
			cin >> aux;
			minimo = max(minimo, aux);
		}
		printf("Case %d: %d\n", casos, minimo );
		casos++;
	}

	return 0;
}