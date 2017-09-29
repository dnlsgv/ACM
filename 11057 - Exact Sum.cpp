/*
    11057 - Exact Sum
    Divide y venceras(?)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){

    int N, M, libroUno, libroDos;
    vector<int> precios;
    vector<int>::iterator esta;

    while(cin >> N){
        int librosEncontrados[2] = {0};
        int diferencia;

        precios.clear();

        for(int i = 0, valor; i < N; i++){
            cin >> valor;
            precios.push_back(valor);
        }

        cin >> M;

        sort(precios.begin(), precios.end());

        for(int i = 0; i < N; i++){
            libroUno = precios[i];
            libroDos = M - libroUno;

            esta = find(precios.begin() + i + 1, precios.end(), libroDos);

            if(esta == precios.end()){
                continue;
            }
            else{
                librosEncontrados[0] = libroUno;
                librosEncontrados[1] = libroDos;
            }

        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", librosEncontrados[0], librosEncontrados[1] );
    }
    
    return 0;
}