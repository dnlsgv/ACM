#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	
	int T, amplitud, frecuencia;

	cin >> T;

	while(T--)
	{
		cin >> amplitud >> frecuencia;

		for(int f = 0; f < frecuencia; ++f)
		{
			for(int i = 1; i <= amplitud; ++i)
			{
				for(int j = 1; j <= i; ++j)
				{
					printf("%d", i);
				}
				printf("\n");
			}
			for(int i = amplitud - 1; i >= 1; --i)
			{
				for(int j = 1; j <= i; ++j)
				{
					printf("%d", i );
				}
				printf("\n");
			}

			if(f != frecuencia - 1)
			{
				printf("\n");
			}
		}
		if(T != 0) printf("\n");
	}

	return 0;
}