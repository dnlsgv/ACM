#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, sumaBuscada;
	vector<pair<int, int> > soluciones;

	while(cin >> N)
	{
		soluciones.clear();
		vector<int> precios(N);
		for(int i = 0; i < N; ++i)
		{
			cin >> precios[i];
		}

		cin >> sumaBuscada;

		sort(precios.begin(), precios.end());
		int complemento;
		for(int i = 0; i < N - 1; ++i)
		{
			complemento = sumaBuscada - precios[i];

			if(binary_search(precios.begin() + i + 1, precios.end(), complemento))
			{
				if(precios[i] > complemento)
				{
					soluciones.push_back(make_pair(complemento ,precios[i]));
				}
				else
				{
					soluciones.push_back(make_pair(precios[i], complemento));
				}
			}
		}

		int menorDiferencia = 1 << 30;
		int respuesta;

		for(int i = 0; i < soluciones.size(); ++i)
		{
			if(abs(soluciones[i].first - soluciones[i].second) < menorDiferencia)
			{
				respuesta = i;
				menorDiferencia = abs(soluciones[i].first - soluciones[i].second);
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n", soluciones[respuesta].first, soluciones[respuesta].second);
		printf("\n");
	}

	return 0;
}