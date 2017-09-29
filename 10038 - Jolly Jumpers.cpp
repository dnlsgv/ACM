#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){

    int n, numeroDeSecuencia;
    vector<int> secuencia;
    vector<int> diferencias;
    bool saltarina;

    while(cin >> n){
        saltarina = true;
        secuencia.clear();
        diferencias.clear();

        if(n == 1){
            cout << "Jolly" << endl;
            cin >> numeroDeSecuencia;
        }
        else{
            for(int i = 0; i < n; i++){
                cin >> numeroDeSecuencia;
                secuencia.push_back(numeroDeSecuencia);
            }
            //Calcular diferencias

            for(int i = 0; i < secuencia.size() - 1; i++){
                diferencias.push_back(abs(secuencia[i] - secuencia[i + 1]));
            }

            sort(diferencias.begin(),  diferencias.end());
            
            for(int i = 0; i < diferencias.size(); i++){
                if(diferencias[i] == i + 1){
                    continue;
                }
                else{
                    saltarina = false;
                    break;
                }
            }
            if(saltarina){
                cout << "Jolly" << endl;
            }
            else{
                cout << "Not jolly" << endl;
            }
        }
    }
    
    return 0;
}