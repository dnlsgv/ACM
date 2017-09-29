/*
    11849 - CD
    Estructura de datos
*/
#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]){
        
    int N, M, repeticiones;
    set<int> cds;
    bool existe;

    while(cin >> N >> M){

        if(N == 0 && M == 0){
            break;
        }

        cds.clear();
        repeticiones = 0;

        for(int i = 0, valor; i < N; i++){
            cin >> valor;
            cds.insert(valor);
        }

        for(int i = 0, valor; i < M; i++){
            int tamActual = cds.size();
            cin >> valor;
            cds.insert(valor);

            //Si al momento de insertar, el .size() no aumento
            //Quiere decir que ya existia en el set el valor (repeticion de CD)
            if(tamActual == cds.size()){
                repeticiones++;
            }
        }
        printf("%d\n", repeticiones );
    }

    return 0;
}