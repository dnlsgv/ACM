#include <iostream>
#include <cstring>

using namespace std;

int campo[100][100];
int resultado[100][100];

void imprimirMatriz(int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(campo[i][j] == -1){
				cout << '*';
			}
			else{
				cout << '.';
			}
		}
		cout << endl;
	}
	cout << endl << endl;
}

void imprimirMatrizResultado(int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(campo[i][j] == -1){
				cout << "*";
				continue;
			}
			cout << resultado[i][j];
		}
		cout << endl;
	}
}

void minasAdyacentes(int n, int m){
	int cantidadDeBombas;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cantidadDeBombas = 0;
			if(campo[i][j] == -1){
				continue;
			}

			if(j - 1 >= 0 && campo[i][j - 1] == -1){
				cantidadDeBombas++;
			}
			if(i - 1 >= 0 && campo[i - 1][j] == -1){
				cantidadDeBombas++;
			}
			if(j + 1 < m && campo[i][j + 1] == -1){
				cantidadDeBombas++;
			}
			if(i + 1 < n && campo[i + 1][j] == -1){
				cantidadDeBombas++;
			}

			//detectar las diagonales
			//diagonal izquierda
			if(i - 1 >= 0 && j - 1 >= 0 && campo[i - 1][j - 1] == -1){
				cantidadDeBombas++;
			}

			//diagonal derecha
			if(i - 1 < m && j + 1 < m && campo[i - 1][j + 1] == -1){
				cantidadDeBombas++;
			}

			//diagonal derecha inferior
			if(i + 1 < n && j + 1 < m && campo[i + 1][j + 1] == -1){
				cantidadDeBombas++;
			}

			//diagonal abajo izquierda
			if(i + 1 < n && j - 1 >= 0 && campo[i + 1][j - 1] == -1){
				cantidadDeBombas++;
			}

			resultado[i][j] = cantidadDeBombas;
		}
	}

}

int main(int argc, char const *argv[]){

	int n, m, field;
	char valor;

	field = 1;
	while(cin >> n >> m){
		if(n == 0 && m == 0){
			break;
		}
		if(field > 1){
			cout << endl;
		}
		memset(campo, 0, sizeof(campo[0][0]) * n * m);
		memset(resultado, 0, sizeof(resultado[0][0]) * n * m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> valor;
				if(valor == '*'){
					campo[i][j] = -1;
				}
				else{
					if(valor == '.'){
						campo[i][j] = 0;
					}
				}
				
			}
		}

		cout << "Field #" << field << ":" << endl;
		minasAdyacentes(n, m);
		imprimirMatrizResultado(n, m);
		field++;

	}	
	
	return 0;
}
























