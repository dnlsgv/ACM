#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int secuencia[7 + 1];
string reglaActual, palabraActual;

void back(int indiceActual, int largo)
{
	if(indiceActual >= largo)
	{
		int contadorSecuencia = 0;
		for(int i = 0; i < reglaActual.size(); ++i)
		{
			if(reglaActual[i] != '0')
			{
				printf("%s", palabraActual.c_str() );
			}
			else
			{
				printf("%d", secuencia[contadorSecuencia] );
				contadorSecuencia++;
			}
		}
		printf("\n");
		return;
	}
	for(int i = 0; i <= 9; ++i)
	{
		secuencia[indiceActual] = i;
		back(indiceActual + 1, largo);
	}
	return;
}

int main(int argc, char const *argv[])
{
	int cantidadPalabras, cantidadReglas;

	while(cin >> cantidadPalabras)
	{
		vector<string> palabras(cantidadPalabras);

		for(int i = 0; i < cantidadPalabras; ++i)
		{
			cin >> palabras[i];
		}
		cin >> cantidadReglas;
		vector<string> reglas(cantidadReglas);

		for(int i = 0; i < cantidadReglas; ++i)
		{
			cin >> reglas[i];
		}

		int largo;
		for(int i = 0; i < reglas.size(); ++i)
		{
			printf("--\n");
			reglaActual = reglas[i];
			largo = 0;
			for(int j = 0; j < reglaActual.size(); ++j)
			{
				if(reglaActual[j] == '0')
				{
					largo++;
				}
			}

			for(int k = 0; k < palabras.size(); ++k)
			{
				palabraActual = palabras[k];
				back(0, largo);
			}
		}

	}

	return 0;
}