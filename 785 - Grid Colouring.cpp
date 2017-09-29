/*
	785 - Grid Colouring
	DFS
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> tablero;
char contorno;

void dfs(int i, int j, char color){
	//Pintar todo los espacios vacios que no hayan sido pintados antes
	if(tablero[i][j + 1] == ' ' && tablero[i][j + 1] != color && tablero[i][j + 1] != contorno){
		tablero[i][j + 1] = color;
		dfs(i, j + 1, color);
	}

	if(tablero[i + 1][j] == ' ' && tablero[i + 1][j] != color && tablero[i + 1][j] != contorno){
		tablero[i + 1][j] = color;
		dfs(i + 1, j, color);
	}

	if(tablero[i][j - 1] == ' ' && tablero[i][j - 1] != color && tablero[i][j - 1] != contorno){
		tablero[i][j - 1] = color;
		dfs(i, j - 1, color);
	}

	if(tablero[i - 1][j] == ' ' && tablero[i - 1][j] != color && tablero[i - 1][j] != contorno){
		tablero[i - 1][j] = color;
		dfs(i - 1, j, color);
	}
	return;
}

int main(int argc, char const *argv[]){

	int columna;
	string lineaCompleta;

	while(getline(cin, lineaCompleta)){

		if(lineaCompleta[0] != '_'){
			tablero.push_back(lineaCompleta);

			if(tablero.size() == 1){
				for(int i = 0; i < lineaCompleta.size(); i++){
					if(lineaCompleta[i] != '_' && lineaCompleta[i] != ' '){
						contorno = lineaCompleta[i];
					}
				}
			}
		}
		else{
			for(int i = 0; i < tablero.size(); i++){
				for(int j = 0; j < tablero[i].size(); j++){
					if(tablero[i][j] != '_' && tablero[i][j] != ' ' && tablero[i][j] != contorno){
						dfs(i, j, tablero[i][j]);
					}
				}
			}

			for(int i = 0; i < tablero.size(); i++){
				for(int j = 0; j < tablero[i].size(); j++){
					printf("%c", tablero[i][j] );
				}
				printf("\n");
			}
			printf("%s\n", lineaCompleta.c_str() );
			tablero.clear();
		}
	}
	
	return 0;
}