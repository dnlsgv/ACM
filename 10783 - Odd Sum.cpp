#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, a, b, respuesta;

	cin >> T;

	for(int i = 1; i <= T; ++i)
	{
		cin >> a >> b;
		respuesta = 0;
		
		for(int j = a; j <= b; ++j)
		{
			if(j%2 != 0)
			{
				respuesta+=j;
			}
		}
		printf("Case %d: %d\n", i,  respuesta);
	}

	return 0;
}