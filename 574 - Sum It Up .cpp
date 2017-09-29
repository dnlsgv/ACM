/*
    574 - Sum It Up
    Backtracking + el uso de set para eliminar las repeticiones de las sumas que ya existian anteriormente  
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

int t, n;
int caminosEncontrados = 0;
int numeros[12];
vector<int> caminoFinal;
set<vector<int> > setDeCaminos;

void backtracking(int indice, int sumatoria, vector<int> caminoParcial){
    sumatoria+=numeros[indice];

    caminoParcial.push_back(numeros[indice]);

    if(sumatoria == t){
        caminosEncontrados++;
        caminoFinal = caminoParcial;
        setDeCaminos.insert(caminoParcial);
        
        return;
    }
    if(sumatoria > t){
        return;
    }
    for(int i = indice + 1; i < n; i++){
        if(sumatoria + numeros[i] <= t){
            backtracking(i, sumatoria, caminoParcial);
        }
    }
    return;
}

int main(int argc, char const *argv[]){


    while(scanf("%d %d", &t, &n)){
        vector<int> cualquierVector;
        if(n == 0){
            break;
        }  
        for(int i = 0; i < n; i++){
            scanf("%d", &numeros[i]);
        }

        caminosEncontrados = 0;
        vector<int> caminoParcial;
        setDeCaminos.clear();

        printf("Sums of %d:\n", t );
        for(int i = 0; i < n; i++){
            backtracking(i, 0, caminoParcial);
        }

        //Para iterar desde el final del set, reverse_iterator
        set<vector<int> >::reverse_iterator it;

        for(it = setDeCaminos.rbegin(); it != setDeCaminos.rend(); it++){
            vector<int> otroVector = *it;
            for(int i = 0; i < otroVector.size(); i++){
                if(i == otroVector.size() - 1){
                    printf("%d", otroVector[i]  );
                }
                else{
                    printf("%d+", otroVector[i] );
                }
            }
            printf("\n");
        }

        if(caminosEncontrados == 0){
            printf("NONE\n");
        }
    }
    
    return 0;
}