#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

class NumeroGigante
{
	private:
		string numero;

	public:
		NumeroGigante(string numero)
		{
			this->numero = numero;
		}

		string getNumero()
		{
			return this->numero;
		}

		string concatenarNumero(string numero)
		{
			return this->numero + numero;
		}

		string multiplicar(string numero)
		{
			int N, M;
			N = numero.size();
			M = this->numero.size() + 1 + numero.size();
			int matriz[N][M];
			for(int i = 0; i < N; ++i)
			{
				for(int j = 0; j < M; ++j)
				{
					matriz[i][j] = 0;
				}
			}

			int avance, acarreo, multiplicacion;
			avance = acarreo = 0;
			int fila, columna;
			for(int i = numero.size() - 1, fila = 0; i >= 0; --i, ++fila)
			{
				for(int j = this->numero.size() - 1, columna = M - 1; j >= 0; --j, --columna)
				{
					multiplicacion = int(this->numero[j] - '0') * int(numero[i] - '0') + acarreo;
					matriz[fila][columna + avance] = multiplicacion%10;
					acarreo = multiplicacion/10;
					if(j == 0 && acarreo != 0)
					{
						matriz[fila][columna + avance - 1] = acarreo;
						acarreo = 0;
					}
				}
				avance--;
			}

			string salida = "";
			int sumatoriaVertical, digito;
			acarreo = 0;

			for(int j = M - 1; j >= 0; --j)
			{
				sumatoriaVertical = 0;
				for(int i = 0; i < N; ++i)
				{
					sumatoriaVertical+=matriz[i][j];
				}
				digito = (sumatoriaVertical + acarreo)%10;
				salida+=(digito + '0');
				acarreo = (sumatoriaVertical + acarreo)/10;
			}

			reverse(salida.begin(), salida.end());
			string salidaSinCeros = "";
			bool agregar = false;

			for(int i = 0; i < salida.size(); ++i)
			{
				if(!agregar && salida[i] != '0')
				{
					agregar = true;
				}
				if(agregar)
				{
					salidaSinCeros+=salida[i];
				}
			}
			return salidaSinCeros;
		}
};

int main(int argc, char const *argv[])
{
	vector<NumeroGigante *> factoriales(366 + 1);

	factoriales[0] = new NumeroGigante("1");
	factoriales[1] = new NumeroGigante("1");
	factoriales[2] = new NumeroGigante("2");

	for(int i = 3; i < 366 + 1; ++i)
	{
		factoriales[i] = new NumeroGigante(factoriales[i - 1]->multiplicar(to_string(i)));
	}

	int numero;

	while(cin >> numero)
	{
		if(numero == 0)
		{
			break;
		}

		string factorialCalculado;

		factorialCalculado = factoriales[numero]->getNumero();
		int digitosCalculados[10];

		for(int i = 0; i < 10; ++i)
		{
			digitosCalculados[i] = 0;
		}

		for(int i = 0; i < factorialCalculado.size(); ++i)
		{
			digitosCalculados[int(factorialCalculado[i] - '0')]++;
		}

		printf("%d! --\n", numero);
		printf("   (0)    %d    (1)    %d    (2)    %d    (3)    %d    (4)    %d\n", digitosCalculados[0], digitosCalculados[1], digitosCalculados[2], digitosCalculados[3], digitosCalculados[4] );
		printf("   (5)    %d    (6)    %d    (7)    %d    (8)    %d    (9)    %d\n", digitosCalculados[5], digitosCalculados[6], digitosCalculados[7], digitosCalculados[8], digitosCalculados[9] );

	}

	return 0;
}