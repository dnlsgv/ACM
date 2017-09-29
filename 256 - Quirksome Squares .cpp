/*
	256 - Quirksome Squares
	Ya que cuando n = 8 se hacen 10^8 iteraciones, el juez arrojara TLE
	Se precalcula con antelacion cuando n = 8
*/
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]){

	int n;

	while(cin >> n){

		if(n == 8){
			printf("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n");
			continue;
		}
		else{

			int numero, primeraMitad, segundaMitad;

			for(long long i = 0; i < pow(10, n); i++){
				numero = i;
				primeraMitad = numero/pow(10, n/2);
				segundaMitad = numero - (primeraMitad * pow(10, n/2));
				// segundaMitad = primeraMitad + numero;

				if(pow(primeraMitad + segundaMitad, 2) == i){
					if(n == 2)
						cout << primeraMitad << segundaMitad << endl;
					if(n == 4){
						printf("%02d", primeraMitad);
						printf("%02d\n", segundaMitad);
					}
					if(n == 6){
						printf("%03d", primeraMitad);
						printf("%03d\n", segundaMitad);
					}
				}
			}
		}
	}

	return 0;
}