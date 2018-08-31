#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, cantidadClaves, repeticionesCombinacionMasGrande;
	map<string, int> combinaciones;

	//mapa[1] = make_pair(2, vector<int>());

	while(cin >> N)
	{
		if(N == 0)
		{
			break;
		}
		cantidadClaves = 0;
		vector<int> cursosTomados;
		combinaciones.clear();
		repeticionesCombinacionMasGrande = 0;

		for(int i = 0; i < N; ++i)
		{
			cursosTomados.clear();

			for(int j = 0, curso; j < 5; ++j)
			{
				cin >> curso;
				cursosTomados.push_back(curso);
			}

			sort(cursosTomados.begin(), cursosTomados.end());
			
			string clave = "";
			for(int c = 0; c < 5; ++c)
			{
				//printf("%d ", cursosTomados[c] );
				clave+=(to_string(cursosTomados[c]));
			}
			//printf("\n");
			//printf("%s\n", clave.c_str() );

			if(combinaciones.count(clave) == 0)
			{
				//Esta clave no esta
				combinaciones[clave] = 1;
			}
			else
			{
				combinaciones[clave]++;
			}

		}

		if(combinaciones.size() == N)
		{
			printf("%d\n", N );
		}
		else
		{
			//imprimir el mayor
			int mayor = 0;
			for(map<string,int>::iterator it=combinaciones.begin(); it!=combinaciones.end(); ++it)
			{
				mayor = max(mayor, it->second);
			}

			int respuesta = 0;

			for(map<string,int>::iterator it=combinaciones.begin(); it!=combinaciones.end(); ++it)
			{
				if(it->second == mayor)
				{
					respuesta+=it->second;
				}
			}
			printf("%d\n", respuesta );
		}
		//printf("%d\n", combinaciones["100101102103488"] );

		//break;
	}


	return 0;
}