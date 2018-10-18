#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int puntajeActual, contadorPermutaciones, contadorCombinaciones;
	vector<int> posiblesPuntos;

	for(int i = 0; i <= 20; ++i)
	{
		posiblesPuntos.push_back(i);
		posiblesPuntos.push_back(2 * i);
		posiblesPuntos.push_back(3 * i);
	}
	posiblesPuntos.push_back(50);

	int tamPosiblesPuntos = posiblesPuntos.size();

	while(cin >> puntajeActual)
	{
		set<string> combinaciones;
		contadorPermutaciones = contadorCombinaciones = 0;

		if(puntajeActual <= 0)
		{
			break;
		}

		for(int i = 0; i < tamPosiblesPuntos; ++i)
		{
			for(int j = 0; j < tamPosiblesPuntos; ++j)
			{
				for(int k = 0; k < tamPosiblesPuntos; ++k)
				{

					if(abs(posiblesPuntos[i] + posiblesPuntos[j] + posiblesPuntos[k] - puntajeActual) == 0)
					{
						//generar string para el set
						int tamActual = combinaciones.size();
						string combinacionString("");
						vector<int> puntajes;

						puntajes.push_back(posiblesPuntos[i]);
						puntajes.push_back(posiblesPuntos[j]);
						puntajes.push_back(posiblesPuntos[k]);

						sort(puntajes.begin(), puntajes.end());
						for(int i = 0; i < 3; ++i)
						{
							combinacionString+=(to_string(puntajes[i]));
						}

						combinaciones.insert(combinacionString);

						if(combinaciones.size() > tamActual)
						{
							//guardar combinacion
							contadorCombinaciones++;
							//Guardar permutaciones
							do
							{
								contadorPermutaciones++;
							}while(next_permutation(puntajes.begin(), puntajes.end()));
						}
					}

				}
			}
		}
		if(contadorCombinaciones == 0)
		{
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", puntajeActual );
		}
		else
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", puntajeActual, contadorCombinaciones);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", puntajeActual, contadorPermutaciones);
		}
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");

	return 0;
}