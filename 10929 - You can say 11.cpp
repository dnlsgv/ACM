#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string numero;

	while(cin >> numero)
	{
		if(numero == "0")
		{
			break;
		}
		int sumaPosicionesPares, sumaPosicionesImpares;

		sumaPosicionesPares = sumaPosicionesImpares = 0;

		for(int i = numero.size() - 1, contador = 1; i >= 0; --i, ++contador)
		{
			if(contador%2 == 0)
			{
				sumaPosicionesPares+=(int(numero[i] - '0'));
			}
			else
			{
				sumaPosicionesImpares+=(int(numero[i] - '0'));
			}
		}
		
		if((sumaPosicionesPares - sumaPosicionesImpares)%11 == 0)
		{
			printf("%s is a multiple of 11.\n", numero.c_str() );
		}
		else
		{
			printf("%s is not a multiple of 11.\n", numero.c_str());
		}
	}

	return 0;
}