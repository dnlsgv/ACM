#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    clock_t tStart = clock();

	for(int i = 1; i <= 2000; ++i)
	{
		for(int j = i; j <= 2000; ++j)
		{
			for(int k = j; k <= 2000; ++k)
			{
				//Calcular el precio_4 con la ecuacion
				int denominador = (i * j * k) - 1000000;
				int numerador = 1000000 * (i + j + k);

				if(i * j * pow(k, 2) > 2 * 1000000000)
				{
					break;
				}
				if(denominador <= 0)
				{
					continue;
				}

				if(numerador%denominador != 0)
				{
					// printf("BUU\n");
					continue;
				}
				else
				{
					int ultimoNumero = numerador/denominador;
					if(k > ultimoNumero)
					{
						continue;
					}
					if(i + j + k + ultimoNumero > 2000)
					{
						continue;
					}
					else
					{
						if(i * j * k * ultimoNumero > 2 * 1000000000)
						{
							continue;
						}
						printf("%.2f %.2f %.2f %.2f\n", i/100.00, j/100.00, k/100.00, (numerador/denominador)/100.00 );
					}
				}
			}
		}
	}

    //printf("Tiempo de ejecucion: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

	return 0;
}