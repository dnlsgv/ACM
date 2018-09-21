#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, cantidadCaracteres, espantapajaros, casos = 1;

	cin >> T;

	while(T--)
	{
		cin >> cantidadCaracteres;
		char campo[cantidadCaracteres];

		for(int i = 0; i < cantidadCaracteres; ++i)
		{
			cin >> campo[i];
		}

		espantapajaros = 0;

		for(int i = 0; i < cantidadCaracteres; ++i)
		{
			if(campo[i] == '.')
			{
				if(i + 1 < cantidadCaracteres)
				{
					campo[i] = '#';
					campo[i + 1] = '#';
					campo[i + 2] = '#';
					espantapajaros++;
				}
				else
				{
					campo[i] = '#';
					espantapajaros++;
				}
			}
		}
		
		printf("Case %d: %d\n", casos, espantapajaros );
		casos++;
	}

	return 0;
}