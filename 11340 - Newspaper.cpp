#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, cantidadClaves, cantidadLineas;

	cin >> T;

	while(T--)
	{
		double resultado = 0;
		vector<string> texto;
		map<char, int> mapaDeClaves;
		cin >> cantidadClaves;

		for(int i = 0; i < cantidadClaves; ++i)
		{
			char auxClave;
			int auxValor;

			cin >> auxClave >> auxValor;
			mapaDeClaves[auxClave] = auxValor;
		}

		cin >> cantidadLineas;

		string lineaCompleta;
		getline(cin, lineaCompleta);

		for(int i = 0; i < cantidadLineas; ++i)
		{
			getline(cin, lineaCompleta);
			texto.push_back(lineaCompleta);
			// cout << lineaCompleta << endl;
		}

		for(int i = 0; i < cantidadLineas; ++i)
		{
			for(int j = 0; j < texto[i].size(); ++j)
			{
				// cout << texto[i][j] << endl;
				if(mapaDeClaves.count(texto[i][j]) > 0)
				{
					resultado+=mapaDeClaves[texto[i][j]];
				}
			}
		}
		printf("%.2f$\n", resultado/100 );
	}
	
	return 0;
}