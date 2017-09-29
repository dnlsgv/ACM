/*
	167 - The Sultan's Successors
*/
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int N;
int reinasEnTablero = 0;
int tablero[8][8];
int valores[8][8];
int sumatoria = 0;
int sumatoriaMaxima = 0;

void imprimirTablero(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%d ", tablero[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
bool posicionar(int fila, int columna){

	//consultar por la fila
	for(int i = 0; i < N; i++){
		if(tablero[fila][i] == 1 && i != columna){
			return false;
		}
	}

	//consultar por columna
	for(int i = 0; i < N; i++){
		if(tablero[i][columna] == 1 && i != fila){
			return false;
		}
	}

	//probar diagonal izquierda superior
	for(int i = fila - 1, j = columna - 1; i >= 0 && j >= 0; i--, j--){
		if(tablero[i][j] == 1){
			return false;
		}
	}

	//probar diagonal derecha superior
	for(int i = fila - 1, j = columna + 1; i >= 0 && j < N; i--, j++){
		if(tablero[i][j] == 1){
			return false;
		}
	}

	//probar diagonal derecha inferior
	for(int i = fila + 1, j = columna + 1; i < N && j < N; i++, j++){
		if(tablero[i][j] == 1){
			return false;
		}
	}

	//diagonal izquierda inferior
	for(int i = fila + 1, j = columna - 1; i < N && j >= 0; i++, j--){
		if(tablero[i][j] == 1){
			return false;
		}
	}

	return true;
}

void backtracking(int fila, int columna){
	for(int i = fila; i < N; i++){
		if(posicionar(i, columna) == true){
			tablero[i][columna] = 1;
			reinasEnTablero++;
			
			if(reinasEnTablero == N){
				//imprimirTablero();
				sumatoria = 0;
				for(int m = 0; m < N; m++){
					for(int n = 0; n < N; n++){
						if(tablero[n][m] == 1){
							sumatoria+=valores[n][m];
						}
					}
				}
				if(sumatoria > sumatoriaMaxima){
					sumatoriaMaxima = sumatoria;
				}
				//printf("%d\n", sumatoria );
				sumatoria = 0;
			}
			backtracking(0, columna + 1);
			tablero[i][columna] = 0;
			reinasEnTablero--;
		}
	}
	return;
}


int main(int argc, char const *argv[]){

	N = 8;
	int casos;
	memset(tablero, 0, sizeof(tablero[0][0]) * N * N);

	scanf("%d", &casos);

	for(int i = 0; i < casos; i++){

		//leer tablero
		for(int j = 0; j < 8; j++){
			for(int k = 0; k < 8; k++){
				scanf("%d", &valores[j][k]);
			}
		}

		backtracking(0, 0);
		printf("%5d\n", sumatoriaMaxima );
		sumatoriaMaxima = 0;
		sumatoria = 0;
	}

	return 0;
}
