/*
	471 - Magic Numbers
	Busqueda exhaustiva y teniendo en cuenta las propiedades:

	s1/s2 = N 
	s1 = N * s2
*/
#include <iostream>

using namespace std;

int digitosRepetidos(long long numero){
	string numeroString = to_string(numero);
	int digitosOcupados[10] = {0};

	for(int i = 0; i < numeroString.size(); i++){
		if(digitosOcupados[numeroString[i] - '0'] == 1){
			return 1;
		}
		else{
			if(digitosOcupados[numeroString[i] - '0'] == 0){
				digitosOcupados[numeroString[i] - '0'] = 1;
			}
		}
	}

	return 0;
}

int main(int argc, char const *argv[]){

	int T;
	long long N, s1, s2;

	long long limite = 9876543210;

	cin >> T;

	while(T--){
		cin >> N;

		s2 = 1;
		for(s1 = N; s1 <= limite; s1 = s1 + N){

			if(digitosRepetidos(s1) == 0 && digitosRepetidos(s2) == 0){
				printf("%lld / %lld = %lld\n", s1, s2, N );
			}
			s2++;
		}
		if(T > 0){
			printf("\n");
		}
	}

	return 0;
}

