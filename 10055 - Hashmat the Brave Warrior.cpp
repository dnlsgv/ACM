#include <iostream>
#include <stdint.h>

using namespace std;

int main(void){

    long long soldadosNuestros, soldadosEnemigos;

    while(cin >> soldadosNuestros >> soldadosEnemigos){

        if(soldadosNuestros <= soldadosEnemigos){
            cout << (soldadosNuestros - soldadosEnemigos)*-1 << endl;
        }
        else{
            cout << soldadosNuestros - soldadosEnemigos << endl;
        }

    }

    return 0;
}