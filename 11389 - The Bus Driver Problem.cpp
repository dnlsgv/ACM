#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int cantidadRutas, valorMaximo, cobroExtra;
	vector<int> primerasRutas, segundasRutas;

	while(cin >> cantidadRutas >> valorMaximo >> cobroExtra)
	{
		if(cantidadRutas == 0 && valorMaximo == 0 && cobroExtra == 0)
		{
			break;
		}
		
		primerasRutas.clear();
		segundasRutas.clear();

		for(int i = 0, aux; i < cantidadRutas; ++i)
		{
			cin >> aux;
			primerasRutas.push_back(aux);
		}
		for(int i = 0, aux; i < cantidadRutas; ++i)
		{
			cin >> aux;
			segundasRutas.push_back(aux);
		}


		sort(primerasRutas.begin(), primerasRutas.end());
		sort(segundasRutas.begin(), segundasRutas.end());
		// reverse(segundasRutas.end(), segundasRutas.begin());

		int respuesta = 0;

		for(int i = 0, j = segundasRutas.size() - 1; i < primerasRutas.size(); ++i, --j)
		{
			if(primerasRutas[i] + segundasRutas[j] > valorMaximo)
			{
				respuesta+=((primerasRutas[i] + segundasRutas[j] - valorMaximo) * cobroExtra);
				// debug(respuesta);
			}
		}
		cout << respuesta << endl;
	}

	return 0;
}