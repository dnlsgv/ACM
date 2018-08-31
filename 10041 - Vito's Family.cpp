#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcular(vector<int> parientes, int calleElegida)
{
	int respuesta = 0;
	for(int valor : parientes)
	{
		if(valor == calleElegida)
		{
			continue;
		}
		else
		{
			respuesta+=(abs(calleElegida - valor));
		}
	}
	return respuesta;
}

int main(int argc, char const *argv[])
{
	int T;

	cin >> T;

	while(T--)
	{
		int cantidadParientes;
		vector<int> parientes;

		cin >> cantidadParientes;

		for(int i = 0; i < cantidadParientes; ++i)
		{
			int calle;
			cin >> calle;
			parientes.push_back(calle);
		}

		sort(parientes.begin(), parientes.end());

		int setSize = parientes.size();
		int respuesta = 0;

		if(setSize%2 != 0)
		{
			int calleElegida = parientes[setSize/2];
			respuesta = calcular(parientes, calleElegida);
		}
		else
		{
			//Hay 2 mitades por probar
			int calleElegida1 = parientes[setSize/2];
			int calleElegida2 = parientes[(setSize/2) - 1];

			respuesta = min(calcular(parientes, calleElegida1), calcular(parientes, calleElegida2));
		}

		cout << respuesta << endl;
	}
	
	return 0;
}