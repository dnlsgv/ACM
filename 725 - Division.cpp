/*
	UVA - 725
    Algoritmo de busqueda completa
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int arregloDigitos[10];//0,1,2,3,4,5,6,7,8,9

bool numeroApto(int numero){
    int digito, elevacion;
    int cantDigitos;

    cantDigitos = 0;

    for(int i = 4; i >= 0; i--){
        elevacion = pow(10, i);
        digito = numero/elevacion;

        if(arregloDigitos[digito] == 0){
            arregloDigitos[digito] = 1;
            cantDigitos++;
        }
        else{
            return false;
        }
        numero = numero - (digito * elevacion);
    }

/*    if(cantDigitos == 4){
        arregloDigitos[0] = 1;
    }
*/
    return true;
}

int main(int argc, char const *argv[]){

    int N, numerador;
    bool haySolucion;

    int a = 79546;
    int b = 1283;
    int primerCaso = 0;
    while(cin >> N){
        if(N == 0){
            break;
        }
        if(primerCaso != 0){
            printf("\n");
        }
        primerCaso = 1;
        haySolucion = false;

        for(int i = 1234; i < 98765; i++){
            for(int k = 0; k < 10; k++){
                arregloDigitos[k] = 0;
            }

            if(numeroApto(i)){
                numerador = N * i;
                if(numerador > 98765){
                    break;
                }
                else{
                    if(numeroApto(numerador)){
                        haySolucion = true;
                        if(i <= 9999){
                            cout << numerador << " / 0" << i << " = " << N << endl;
                        }
                        else{
                            cout << numerador << " / " << i << " = " << N << endl;
                        }
                    }
                }
            }
        }

        if(haySolucion == false){
            cout << "There are no solutions for " << N << ".\n";
        }
    }
        
    return 0;
}