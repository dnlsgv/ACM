/*
	10327 - Flip Sort
	Ordenar el arreglo y contador los cambios
	(ordenamiento mediante burbuja/insercion)
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){

	int N, cantidadCambios, contador;
	bool cambio;

	while(cin >> N){
		contador = 0;

		int arreglo[N];
		cantidadCambios = 0;

		for(int i = 0;  i < N; i++){
			cin >> arreglo[i];
		}

		while(true){
			cambio = false;
			for(int i = 0; i < N - 1 - contador; i++){
				if(arreglo[i] > arreglo[i + 1]){
					int aux;
					aux = arreglo[i];
					arreglo[i] = arreglo[i + 1];
					arreglo[i + 1] = aux;
					cambio = true;
					cantidadCambios++;
				}
			}

			if(cambio == false){
				break;
			}
			contador++;
		}

		printf("Minimum exchange operations : %d\n", cantidadCambios );
	}

	return 0;
}