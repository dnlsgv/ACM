/*
	Rotar la matriz mas chica
*/
#include <iostream>
#include <cstdio>

using namespace std;

int N, n;

int main(int argc, char const *argv[])
{

	while(cin >> N >> n)
	{
		if(N == 0 && n == 0)
		{
			break;
		}

		char matrizGrande[N][N], matrizChica[n][n], copiaMatrizChica[n][n];

		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < N; ++j)
			{
				cin >> matrizGrande[i][j];
			}
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				cin >> matrizChica[i][j];
				copiaMatrizChica[i][j] = matrizChica[i][j];
			}
		}

		//Inicio debugger
		// bool laMasGrande = true;
		// for(int i = 0; i < (laMasGrande ? N : n); ++i)
		// {
		// 	for(int j = 0; j < (laMasGrande ? N : n); ++j)
		// 	{
		// 		printf("%c", (laMasGrande ? matrizGrande[i][j] : matrizChica[i][j]));
		// 	}
		// 	printf("\n");
		// }
		//Fin debugger

		int respuestas[4], repeticiones, subRepeticiones;

		for(int rotaciones = 0; rotaciones < 4; ++rotaciones)
		{
			repeticiones = 0;
			if(rotaciones > 0)
			{
				//rotar el cuadrado mas chico
				for(int j = n - 1, k = 0; j >= 0; --j, ++k)
				{
					for(int i = 0; i < n; ++i)
					{
						matrizChica[i][j] = copiaMatrizChica[k][i];
					}
				}

				for(int i = 0; i < n; ++i)
				{
					for(int j = 0; j < n; ++j)
					{
						copiaMatrizChica[i][j] = matrizChica[i][j];
					}
				}
			}

			for(int i = 0; i < N; ++i)
			{
				for(int j = 0; j < N; ++j)
				{
					subRepeticiones = 0;
					for(int k = 0; k < n; ++k)
					{
						for(int m = 0; m < n; ++m)
						{
							if(i + k >= N || j + m >= N)
							{
								break;
							}
							if(matrizChica[k][m] == matrizGrande[i + k][j + m])
							{
								subRepeticiones++;
							}
							else
							{
								break;
							}
						}
					}
					if(subRepeticiones == n * n)
					{
						repeticiones++;
					}
				}
			}
			respuestas[rotaciones] = repeticiones;
		}

		printf("%d", respuestas[0] );
		for(int i = 1; i < 4; ++i)
		{
			printf(" %d", respuestas[i]);
		}
		printf("\n");
	}

	return 0;
}