#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

vector<pair<int, string> > suffixArray;

bool ordenarPorElSegundoParametro(const pair<int, string> &a, const pair<int, string> &b)
{
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
	string secuencia;
	int T;

	cin >> T;
	getline(cin, secuencia);

	while(T--)
	{
		getline(cin, secuencia);
		//debug(secuencia);
		suffixArray.clear();
	
		for(int i = 0, j = secuencia.size() - 1; i < secuencia.size(); ++i, --j)
		{
			suffixArray.push_back(make_pair(i, secuencia.substr(i, secuencia.size() - i)));
		}
	
		sort(suffixArray.begin(), suffixArray.end(), ordenarPorElSegundoParametro);

		int LCP[secuencia.size()];
		int indiceDelSubStringMasLargo;

		LCP[0] = 0;

		//Ir comparando la posicion i contra la i - 1
		for(int i = 1; i < secuencia.size(); ++i)
		{
			string prefijo1, prefijo2;
			prefijo1 = suffixArray[i - 1].second;
			prefijo2 = suffixArray[i].second;

			int bordeMinimo = min(prefijo1.size(), prefijo2.size());
			int repeticiones = 0;

			for(int j = 0; j < bordeMinimo; ++j)
			{
				if(prefijo1[j] == prefijo2[j])
				{
					repeticiones++;
				}
				else
				{
					break;
				}
			}

			LCP[i] = repeticiones;
		}

		//Buscar el substring mas largo O(n)
		int maximo = -1;
		string subStringMaximo;
		for(int i = 0; i < secuencia.size(); ++i)
		{
			if(LCP[i] > maximo)
			{
				maximo = LCP[i];
				subStringMaximo = suffixArray[i].second.substr(0, LCP[i]);
			}
		}

		// subStringMaximo = "A";
		// printf("subStringMaximo: %s\n", subStringMaximo.c_str() );

		vector<int> posicionesEncontradas;
		int posicioneDondeFueEncontrado = secuencia.find(subStringMaximo, 0);
		while(posicioneDondeFueEncontrado != string::npos)
		{
		    posicionesEncontradas.push_back(posicioneDondeFueEncontrado);
		    posicioneDondeFueEncontrado = secuencia.find(subStringMaximo, posicioneDondeFueEncontrado + 1);
		}

		// printf("Ocurrencias de %s en %s: %lu\n", subStringMaximo.c_str() , secuencia.c_str(), positions.size());

		if(subStringMaximo == "")
		{
			printf("No repetitions found!\n");
		}
		else
		{
			printf("%s %lu\n", subStringMaximo.c_str(), posicionesEncontradas.size() );
		}

		//break;
	}

	return 0;
}