/*
	272 - TEX Quotes
*/
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){

	string linea, textoCompleto;
	int aparicion;

	textoCompleto = "";

	while(getline(cin, linea)){
		textoCompleto+=(linea + "\n");
	}
	
	aparicion = 0;

	for(int i = 0; i < textoCompleto.size(); i++){
		if(textoCompleto[i] == '"'){
			if(aparicion == 0){
				printf("``");
				aparicion = 1;
			}
			else{
				if(aparicion == 1){
					printf("''");
					aparicion = 0;
				}
			}
		}
		else{
			printf("%c", textoCompleto[i] );
		}
	}

	return 0;
}