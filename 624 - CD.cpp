/*
	uVa 624 - CD
	Resuelto usando backtracking
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M, sumaMaxima;
vector<int> tracks;
vector<int> rutaFinal;

void backtracking(int i, int sumaActual, vector<int> probadorRutas){
	sumaActual += tracks[i];

	probadorRutas.push_back(tracks[i]);

	if(sumaActual > sumaMaxima){
		sumaMaxima = sumaActual;
		rutaFinal = probadorRutas;
	}

	for(int j = i + 1; j < M; j++){
		if(sumaActual + tracks[j] <= N){
			backtracking(j, sumaActual, probadorRutas);
		}
		else{
			continue;
		}
	}
	return;
}


int main(int argc, char const *argv[]){
	int valor;

	while(cin >> N >> M){
		tracks.clear();
		rutaFinal.clear();
		sumaMaxima = 0;
		vector<int> cualquierVector;

		for(int i = 0; i < M; i++){
			cin >> valor;
			tracks.push_back(valor);
		}

		for(int i = 0; i < M; i++){
			backtracking(i, 0, cualquierVector);
		}

		for(int i = 0; i < rutaFinal.size(); i++){
			cout << rutaFinal[i] << " ";
		}
		cout << "sum:" << sumaMaxima << endl;
	}

	return 0;
}
