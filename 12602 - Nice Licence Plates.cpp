#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int T;
	string lineaCompleta;

	cin >> T;

	while(T--)
	{
		string patente;
		string numero;

		patente = numero = "";

		cin >> lineaCompleta;

		char letra;
		for(int i = 0; i < 8; ++i)
		{
			letra = lineaCompleta[i];
			if(i < 3)
			{
				patente+=letra;
			}
			else
			{
				if(i > 3)
				{
					numero+=letra;
				}
			}
		}

		int parteIzquierda, parteDerecha;

		parteIzquierda = 0;
		for(int i = 2, j = 0; i >= 0; --i, ++j)
		{
			int calculo = (int(patente[j] - '0') - 17) * pow(26, i);
			// debug(calculo);
			parteIzquierda+=calculo;
		}

		parteDerecha = stoi(numero);

		if(abs(parteIzquierda - parteDerecha) <= 100)
		{
			printf("nice\n");
		}
		else
		{
			printf("not nice\n");
		}
	}
	
	return 0;
}