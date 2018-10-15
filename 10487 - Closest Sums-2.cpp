#include <iostream>
#include <cmath>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int cantidadNumeros, cantidadConsultas, casos = 1, respuesta;
	int numeros[1000 + 1];
	int consultas[25];

	while(cin >> cantidadNumeros)
	{
		if(cantidadNumeros == 0)
		{
			break;
		}

		for(int i = 0; i < cantidadNumeros; ++i)
		{
			cin >> numeros[i];
		}

		cin >> cantidadConsultas;

		for(int i = 0; i < cantidadConsultas; ++i)
		{
			cin >> consultas[i];
		}

		int menorValorAbsoluto = 1 << 30, valorCalculado;
		bool valorAbsolutoCero = false;

		printf("Case %d:\n", casos );
		for(int i = 0; i < cantidadConsultas; ++i)
		{
			int sumaBuscada = consultas[i];
			menorValorAbsoluto = 1 << 30;
			valorAbsolutoCero = false;
			for(int j = 0; j < cantidadNumeros; ++j)
			{
				if(valorAbsolutoCero)
				{
					break;
				}
				for(int k = 0; k < cantidadNumeros; ++k)
				{
					if(j == k)
					{
						continue;
					}

					valorCalculado = abs(numeros[j] + numeros[k] - sumaBuscada);
					// debug(valorCalculado);
					if(valorCalculado == 0)
					{
						respuesta = numeros[j] + numeros[k];
						valorAbsolutoCero = true;
						break;
					}

					if(valorCalculado < menorValorAbsoluto)
					{
						respuesta = numeros[j] + numeros[k];
						menorValorAbsoluto = valorCalculado;
					}
				}
			}
			printf("Closest sum to %d is %d.\n", sumaBuscada, respuesta );
		}
		casos++;
	}

	return 0;
}