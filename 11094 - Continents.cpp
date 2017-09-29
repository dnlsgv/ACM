/*
    11094 - Continents
    Flood fill
*/
#include <iostream>
#include <stdio.h>

using namespace std;

int M, N, apariciones;
char caracterTierra, caracterAgua;
char tablero[22][22];

void dfs(int fila, int columna){
    tablero[fila][columna] = caracterAgua;
    apariciones++;

    if(columna + 1 >= N){
        if(tablero[fila][0] == caracterTierra){
            dfs(fila, 0);
        }
    }
    else{
        if(columna + 1 < N && tablero[fila][columna + 1] == caracterTierra){
            dfs(fila, columna + 1);
        }
    }

    if(columna - 1 < 0){
        if(tablero[fila][N - 1] == caracterTierra){
            dfs(fila, N - 1);
        }
    }
    else{
        if(columna - 1 >= 0 && tablero[fila][columna - 1] == caracterTierra){
            dfs(fila, columna - 1);
        }
    }

    if(fila + 1 < M){
        if(tablero[fila + 1][columna] == caracterTierra){
            dfs(fila + 1, columna);
        }
    }

    if(fila - 1 >= 0){
        if(tablero[fila - 1][columna] == caracterTierra){
            dfs(fila - 1, columna);
        }
    }
    return;
}

int main(int argc, char const *argv[]){
    int X, Y;

    while(cin >> M >> N){

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cin >> tablero[i][j];
            }
        }

        cin >> X >> Y;

        caracterTierra = tablero[X][Y];
        caracterAgua = caracterTierra;

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(tablero[i][j] != caracterTierra){
                    caracterAgua = tablero[i][j];
                    break;
                }
            }
        }

        if(caracterAgua == caracterTierra){
            printf("0\n");
            continue;
        }
        else{
            apariciones = 0;
            dfs(X, Y);
        }

        int ultimaAparicion = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(tablero[i][j] == caracterTierra){
                    apariciones = 0;
                    dfs(i, j);
                    ultimaAparicion = max(ultimaAparicion, apariciones);
                }
            }
        }
        printf("%d\n", ultimaAparicion );
    }

    return 0;
}