#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int NODOS = 200;
vector<int> listaDeAdyacencia[200];
vector<int> colores(200, -1);

string bfs(int nodoInicial){
    int nodoActual, nodoVecino, colorActual, colorNegro, colorRojo;
    queue<int> cola;

    colorNegro = 1;
    colorRojo = 0;

    cola.push(nodoInicial);
    colores[nodoInicial] = colorNegro;

    while(cola.size() != 0){
        nodoActual = cola.front();
        cola.pop();
        colorActual = colores[nodoActual];

        for(int i = 0; i < listaDeAdyacencia[nodoActual].size(); i++){
            nodoVecino = listaDeAdyacencia[nodoActual][i];

            if(colores[nodoVecino] == -1){
                //no ha sido coloreado aun, debo colorearlo
                if(colores[nodoActual] == colorNegro){
                    colores[nodoVecino] = colorRojo;
                }
                else{
                    colores[nodoVecino] = colorNegro;
                }
                cola.push(nodoVecino);
            }
            else{
                //El nodo ya fue visitado, comparar con el color del nodo actual
                if(colores[nodoVecino] == colores[nodoActual]){
                    return "NOT BICOLORABLE.";
                }
            }
        }

    }

    return "BICOLORABLE.";

}

int main(int argc, char const *argv[]){

    int n, m, u, v;
    
    while(cin >> n >> m){
        if(n == 0) break;

        //limpiar los contenedores
        for(int i = 0; i < colores.size(); i++){
            colores[i] = -1;
        }

        for(int i = 0; i < NODOS; i++){
            listaDeAdyacencia[i].clear();
        }

        for(int i = 0; i < m; i++){
            cin >> u >> v;
            // u--;
            // v--;
            listaDeAdyacencia[u].push_back(v);
            listaDeAdyacencia[v].push_back(u);
        }

        if(n == 2){
            cout << "NOT BICOLORABLE." << endl;
            continue;
        }
        //imprimir lista de adyacencia

        // for(int i = 0; i < n; i++){
        //     cout << i << " -> "; 
        //     for(int j = 0; j < listaDeAdyacencia[i].size(); j++){
        //         cout << listaDeAdyacencia[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        cout << bfs(u) << endl;
        // for(int i = 0; i < n; i++) cout << colores[i] << " ";
        // cout << endl;

    }





    return 0;
}