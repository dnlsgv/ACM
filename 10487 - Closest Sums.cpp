/*
	10487 - Closest Sums
	La clave del problema es usar set, ya que no se pueden tener numeros repetidos
	al momento de calcular sumas :-)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]){

	int N, M, contadorCasos;

	set<int>::iterator it;
	set<int> numerosRepetidos;
	vector<int> numeros;
	vector<int> consultas;
	vector<int> sumatorias;

	contadorCasos = 0;

	while(cin >> N){
		if(N == 0){
			break;
		}
		contadorCasos++;
		numeros.clear();
		consultas.clear();
		sumatorias.clear();
		numerosRepetidos.clear();

		for(int i = 0, valor; i < N; i++){
			cin >> valor;
			//numeros.push_back(valor);
			numerosRepetidos.insert(valor);
		}

		for(it = numerosRepetidos.begin(); it != numerosRepetidos.end(); it++){
			numeros.push_back(*it);
		}

		cin >> M;

		for(int i = 0, valor; i < M; i++){
			cin >> valor;
			consultas.push_back(valor);
		}

		//Calcular sumatorias

		for(int i = 0; i < N - 1; i++){
			for(int j = i + 1; j < N; j++){
				if(numeros[i] != numeros[j]){
					sumatorias.push_back(numeros[i] + numeros[j]);
				}
			}
		}

		sort(sumatorias.begin(), sumatorias.end());

		//Probar con las consultas
		int diferenciaActual, diferenciaMenor, respuesta = 0;

		printf("Case %d:\n", contadorCasos );

		for(int i = 0; i < M; i++){
			diferenciaMenor = 9999999;
			for(int j = 0; j < sumatorias.size(); j++){
				diferenciaActual = abs(consultas[i] - sumatorias[j]);

				if(diferenciaActual <= diferenciaMenor){
					diferenciaMenor = diferenciaActual;
					respuesta = sumatorias[j];
				}
				else{
					break;
				}
			}
			printf("Closest sum to %d is %d.\n", consultas[i], respuesta );
		}
	}

	return 0;
}