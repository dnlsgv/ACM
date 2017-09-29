/*
	10684 - The jackpot
	Programación dinámica
	Suma maxima en un arreglo de una dimension
*/
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]){

	int N;

	while(scanf("%d", &N)){
		if(N == 0){
			break;
		}

		int numeros[N];
		int sumaMaxima, sumaActual;

		for(int i = 0; i < N; i++){
			scanf("%d", &numeros[i]);
		}

		sumaMaxima = 0;
		sumaActual = 0;

		for(int i = 0; i < N; i++){
			sumaActual+=numeros[i];
			if(sumaActual > sumaMaxima){
				sumaMaxima = sumaActual;
			}
			else{
				if(sumaActual < 0){
					sumaActual = 0;
				}
			}
		}

		if(sumaMaxima == 0){
			printf("Losing streak.\n");
		}
		else{
			printf("The maximum winning streak is %d.\n", sumaMaxima );
		}
	}

	return 0;
}