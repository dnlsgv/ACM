/*
	483 - Word Scramble
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
	
	string lineaDeTexto;
	string trozoTexto;
	vector<string> palabras;

	while(getline(cin, lineaDeTexto)){
		stringstream parte(lineaDeTexto);

		palabras.clear();

		while(parte >> trozoTexto){
			palabras.push_back(trozoTexto);
		}

		for(int i = 0; i < palabras.size(); i++){
			for(int j = palabras[i].size() - 1; j >= 0; j--){
				printf("%c", palabras[i][j]);
			}
			if(i != palabras.size() - 1){
				printf(" ");
			}
		}
		printf("\n");
	}


	return 0;
}