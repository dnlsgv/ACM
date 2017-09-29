/*
	108 - Maximum Sum
	Suma maxima en un arreglo de 2 dimensiones
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){

	int N;

	scanf("%d", &N);

	int matriz[N + 1][N + 1];
	int sumatoria[N + 1][N + 1];


	for(int i = 0; i < N + 1; i++){
		matriz[0][i] = 0;
		sumatoria[0][i] = 0;
	} 
	for(int j = 0; j < N + 1; j++){
		matriz[j][0] = 0;
		sumatoria[j][0] = 0;
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			int sum;
			sum = sumatoria[i-1][j] + sumatoria[i][j-1] - sumatoria[i-1][j-1] + matriz[i][j];
			sumatoria[i][j] = sum;
		}
	}

	int sumaMaxima = 0;
	int sumaSubRectangulo;

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			for(int k = i; k <= N; k++){
				for(int l = j; l <= N; l++){

					sumaSubRectangulo = sumatoria[k][l] - sumatoria[i-1][l] - sumatoria[k][j-1] + sumatoria[i-1][j-1];
					if(sumaSubRectangulo > sumaMaxima){
						sumaMaxima = sumaSubRectangulo;
					}
				}
			}
		}
	}

	cout << sumaMaxima << endl;

	return 0;
}