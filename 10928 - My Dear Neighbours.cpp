#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	
	int T, P, menor;

	cin >> T;

	while(T--)
	{
		cin >> P;
		menor = 10001;
		int grafo[P + 1];
		string lineaCompleta;
		int cantidadEspacios;

		getline(cin, lineaCompleta);
		for(int i = 1; i <= P; ++i)
		{
			cantidadEspacios = 0;
			getline(cin, lineaCompleta);
			for(int i = 0; i < lineaCompleta.size(); ++i)
			{
				if(lineaCompleta[i] == ' ')
				{
					cantidadEspacios++;
				}
			}
			grafo[i] = cantidadEspacios + 1;
			menor = min(menor, grafo[i]);
		}

		vector<int> salida;

		for(int i = 1; i <= P; ++i)
		{
			if(grafo[i] == menor)
			{
				salida.push_back(i);
			}
		}

		if(salida.size() == 1)
		{
			printf("%d", salida[0] );
		}
		else
		{
			for(int i = 0; i < salida.size() - 1; ++i)
			{
				printf("%d ", salida[i] );
			}
			printf("%d", salida[salida.size() - 1] );
		}
		printf("\n");
	}

	return 0;
}