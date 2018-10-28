#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int sumaDigitos(string numero)
{
	int sumatoria = 0;
	for(int i = 0; i < numero.size(); ++i)
	{
		sumatoria+=(int(numero[i] - '0'));
	}
	return sumatoria;
}

int main(int argc, char const *argv[])
{
	int T, numero, respuesta;
	int preCalculos[100000 + 1];

	for(int k = 1; k < 100000 + 1; ++k)
	{
		int respuesta = 0;
		
		//Reducción del espacio de busqueda, para evitar TLE
		for(int i = (k - 100 >= 0 ? k - 50 : 0); i < k; ++i)
		{
			if(sumaDigitos(to_string(i)) + i == k)
			{
				respuesta = i;
				break;
			}
		}
		//printf("%d : %d, hace: %d\n", k, respuesta, k - respuesta );
		preCalculos[k] = respuesta;
	}

	cin >> T;

	while(T--)
	{
		cin >> numero;

		respuesta = 0;

		cout << preCalculos[numero] << endl;
	}

	return 0;
}