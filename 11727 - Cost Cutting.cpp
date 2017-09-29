/*
    11727 - Cost Cutting
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){

    int T, casos;
    vector<int> salarios;

    casos = 1;

    cin >> T;

    while(T--){
        salarios.clear();

        for(int i = 0, valor; i < 3; i++){
            cin >> valor;
            salarios.push_back(valor);
        }

        sort(salarios.begin(), salarios.end());

        printf("Case %d: %d\n", casos, salarios[1]);
        casos++;
    }
    
    return 0;
}