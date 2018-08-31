#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int numerosOcupados[16 + 1];
int numerosPrimos[31 + 1];
vector<int> numerosImpares;
vector<int> numerosPares;
vector<int> secuenciaDeSalida;
vector<vector<int>> salida;
int n;

void backtrack(int numeroActual)
{
	secuenciaDeSalida.push_back(numeroActual);
	numerosOcupados[numeroActual] = 1;

	if(secuenciaDeSalida.size() == n)
	{
		if(numerosPrimos[secuenciaDeSalida[n - 1] + 1] == 1)
		{
			salida.push_back(secuenciaDeSalida);
			return;
		}
	}

	if(numeroActual%2 != 0)//Impar
	{
		for(int numero : numerosPares)
		{
			if(numerosOcupados[numero] == 0 && numerosPrimos[numero + numeroActual] == 1)
			{
				backtrack(numero);
				numerosOcupados[numero] = 0;
				secuenciaDeSalida.pop_back();
			}
		}
	}
	else
	{
		for(int numero : numerosImpares)
		{
			if(numerosOcupados[numero] == 0 && numerosPrimos[numero + numeroActual] == 1)
			{
				backtrack(numero);
				numerosOcupados[numero] = 0;
				secuenciaDeSalida.pop_back();
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int casos;

	for(int i = 0; i < 31 + 1; ++i)
	{
		numerosPrimos[i] = 0;
	}

	numerosPrimos[2] = numerosPrimos[3] = numerosPrimos[5] = numerosPrimos[7] = numerosPrimos[11] = numerosPrimos[13] = numerosPrimos[17] = numerosPrimos[19] = numerosPrimos[23] = numerosPrimos[29] = numerosPrimos[31] = 1;

	casos = 1;

	while(cin >> n)
	{
		if(casos > 1)
		{
			printf("\n");
		}
		numerosPares.clear();
		numerosImpares.clear();
		secuenciaDeSalida.clear();
		salida.clear();

		for(int i = 0; i < 16 + 1; ++i)
		{
			numerosOcupados[i] = 0;
		}

		for(int i = 2; i <= n; ++i)
		{
			if(i%2 == 0)
			{
				numerosPares.push_back(i);
			}
			else{
				numerosImpares.push_back(i);
			}
		}

		backtrack(1);

		printf("Case %d:\n", casos);
		for(vector<int> secuencia : salida)
		{
			for(int i = 0; i < secuencia.size() - 1; ++i)
			{
				printf("%d ", secuencia[i] );
			}
			printf("%d", secuencia[secuencia.size() - 1] );
			cout << endl;
		}
		casos++;
	}
	return 0;
}