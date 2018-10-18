#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int k;
	bool saltoDeLinea = false;

	while(cin >> k)
	{
		if(k == 0)
		{
			break;
		}

		if(saltoDeLinea)
		{
			printf("\n");
		}
		vector<int> numeros(k);


		for(int i = 0; i < k; ++i)
		{
			cin >> numeros[i];
		}

		for(int i = 0; i < numeros.size(); ++i)
		{
			for(int j = i + 1; j < numeros.size(); ++j)
			{
				for(int m = j + 1; m < numeros.size(); ++m)
				{
					for(int n = m + 1; n < numeros.size(); ++n)
					{
						for(int x = n + 1; x < numeros.size(); ++x)
						{
							for(int y = x + 1; y < numeros.size(); ++y)
							{
								printf("%d %d %d %d %d %d\n", numeros[i], numeros[j], numeros[m], numeros[n], numeros[x], numeros[y] );
							}
						}
					}
				}
			}
		}
		saltoDeLinea = true;
	}

	return 0;
}