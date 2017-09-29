/*
	1237 - Expert Enough?
*/
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]){

	int T, D, Q, precioConsulta, apariciones, respuesta;

	cin >> T;

	while(T--){
		cin >> D;

		int precios[D][2];
		string marcas[D];
		apariciones = 0;

		for(int i = 0; i < D; i++){
			cin >> marcas[i];
			cin >> precios[i][0];
			cin >> precios[i][1];
		}

		cin >> Q;

		for(int consultas = 0; consultas < Q; consultas++){
			cin >> precioConsulta;
			apariciones = 0;

			for(int i = 0; i < D; i++){
				if(precioConsulta >= precios[i][0] && precioConsulta <= precios[i][1]){
					apariciones++;
					respuesta = i;
				}
			}

			if(apariciones == 1){
				printf("%s\n", marcas[respuesta].c_str() );
			}
			else{
				printf("UNDETERMINED\n");
			}
		}
		if(T != 0){
			printf("\n");
		}
	}
	
	return 0;
}