#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int numerosCuadrados[100000 + 1];
	int a, b;

	memset(numerosCuadrados, 0, sizeof(numerosCuadrados[0]) * (100000 + 1));

	for(int i = 1;; ++i)
	{
		int calculo = pow(i, 2);
		if(calculo > 100000)
		{
			break;
		}
		numerosCuadrados[calculo] = 1;
	}

	while(cin >> a >> b)
	{
		if(a == 0 && b == 0)
		{
			break;
		}
		int respuesta = 0;
		for(int i = a; i <= b; ++i)
		{
			if(numerosCuadrados[i] == 1)
			{
				respuesta++;
			}
		}
		cout << respuesta << endl;
	}

	return 0;
}