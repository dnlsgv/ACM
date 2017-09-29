/*
    10107 - What is the Median?
    En udebug hay que usar tipo long(?) pero en uva no
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]){

    long long n, tamActual;
    vector<long long> numeros;

    tamActual = 0;

    while(cin >> n){

        numeros.push_back(n);
        tamActual++;

        sort(numeros.begin(), numeros.end());
        
        if(tamActual%2 == 0){
            int posicionMitad;

            posicionMitad = tamActual/2; 

            printf("%lld\n", (numeros[posicionMitad] + numeros[posicionMitad - 1])/2 );
        }
        else{
            printf("%lld\n", numeros[tamActual/2] );
        }
    }

    return 0;
}

