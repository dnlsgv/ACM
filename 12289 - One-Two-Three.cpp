/*
	12289 - One-Two-Three
*/
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]){
		
	int T, errores;
	string numero;

	cin >> T;

	while(T--){
		cin >> numero;
		errores = 0;
		if(numero.size() == 5){
			printf("3\n");
		}
		else{
			if(numero[0] != 'o'){
				errores++;
			}		
			if(numero[1] != 'n'){
				errores++;
			}
			if(numero[2] != 'e'){
				errores++;
			}

			if(errores == 1 || errores == 0){
				printf("1\n");
			}
			else{
				printf("2\n");
			}
		}
	}

	return 0;
}