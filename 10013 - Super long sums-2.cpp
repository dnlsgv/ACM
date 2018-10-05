#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int T, cantidadDigitos;
	string primerNumero, segundoNumero;

	cin >> T;

	while(T--)
	{
		vector<int> respuesta;
		char digito;
		primerNumero = segundoNumero = "";

		cin >> cantidadDigitos;

		for(int i = 0; i < cantidadDigitos; ++i)
		{
			cin >> digito;
			primerNumero+=digito;
			cin >> digito;
			segundoNumero+=digito;
		}

		int acarreo = 0;
		for(int i = cantidadDigitos - 1; i >= 0; --i)
		{
			int digitoUno, digitoDos, suma;
			digitoUno = int(primerNumero[i] - '0');
			digitoDos = int(segundoNumero[i] - '0');

			// debug(digitoUno + digitoDos);
			suma = digitoUno + digitoDos + acarreo;

			if(suma < 9)
			{
				respuesta.push_back(suma);
				acarreo = 0;
			}
			else
			{
				//sacar el segundo digito
				if(suma == 10)
				{
					respuesta.push_back(0);
					acarreo = 1;
				}
				else
				{
					acarreo = suma/10;
					respuesta.push_back(suma%10);
				}
			}
		}
		if(acarreo != 0)
		{
			respuesta.push_back(acarreo);
		}
		reverse(respuesta.begin(), respuesta.end());
		for(int numero : respuesta)
		{
			cout << numero << "";
		}
		cout << endl;

		if(T != 0)
		{
			cout << endl;
		}
	}
	
	return 0;
}