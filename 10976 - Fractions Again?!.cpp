#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char const *argv[])
{
	int k, x, y, repeticiones;

	while(cin >> k)
	{
		vector<pair<long long, long long> > salida;
		repeticiones = 0;
		for(y = k + 1; y <= 2 * k; ++y)
		{
			// float x = float(k * y)/(y - k);
			if((k * y)%(y - k) == 0)
			{
				int x = (k * y)/(y - k);
				repeticiones++;
				salida.push_back(make_pair(long(x), y));
			}
		}
		printf("%d\n", repeticiones );
		for(int i = 0; i < repeticiones; ++i)
		{
			printf("1/%d = 1/%lld + 1/%lld\n", k, salida[i].first, salida[i].second );	
		}
	}

	return 0;
}