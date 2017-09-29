#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longitudDeCiclo(int n){
	int numerosGenerados;

	numerosGenerados = 1;

	while(n != 1){
		if(n%2 == 0){
			n = n/2;
		}
		else{
			n = (n * 3) + 1;
		}
		numerosGenerados++;
	}

	return numerosGenerados;
}

int main(int argc, char const *argv[]){

	int i, j, aux, cambio;
	vector<int> longitudes;

	while(cin >> i >> j){
		cambio = 0;
		longitudes.clear();
		if(i > j){
			aux = i;
			i = j;
			j = aux;
			cambio = 1;
		}

		for(int n = i; n <= j; n++){
			longitudes.push_back(longitudDeCiclo(n));
		}

		if(cambio == 1){
			//imprimir primero j y despues i
			cout << j << " " << i << " " << *max_element(longitudes.begin(), longitudes.end()) << endl;
		}
		else{
			cout << i << " " << j << " " << *max_element(longitudes.begin(), longitudes.end()) << endl;
		}
	}

	return 0;
}







































