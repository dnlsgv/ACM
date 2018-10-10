#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	long long numero, auxNumero;

	while(cin >> numero)
	{
		if(numero == 0)
		{
			break;
		}
		bool porMasDeUnPrimo = false;
		vector<long long> factoresPrimos;
		set<long long> distintosFactores;
		auxNumero = numero;

		numero = abs(numero);
		if(numero == 1)
		{
			cout << "-1" << endl;
			continue;
		}

		while(numero%2 == 0)
		{
			numero/=2;
			factoresPrimos.push_back(2);
			distintosFactores.insert(2);
		}

		for(int i = 3; i <= sqrt(numero); i+=2)
		{
			while(numero%i == 0)
			{
				numero/=i;
				factoresPrimos.push_back(i);
				porMasDeUnPrimo = true;
				distintosFactores.insert(i);
			}
		}
		//Numero restante es primo
		if(numero > 2)
		{
			porMasDeUnPrimo = true;
			distintosFactores.insert(numero);
			factoresPrimos.push_back(numero);
		}

		if(factoresPrimos[factoresPrimos.size() - 1] == auxNumero)
		{
			cout << "-1" << endl;
		}
		else
		{
			if(porMasDeUnPrimo == false)
			{
				cout << "-1" << endl;
			}
			else
			{
				if(distintosFactores.size() > 1)
				{
					cout << factoresPrimos[factoresPrimos.size() - 1] << endl;
				}
				else
				{
					cout << "-1" << endl;
				}
			}
		}

	}

	return 0;
}