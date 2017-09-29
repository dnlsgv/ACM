/*
	543 - Goldbach's Conjecture
	
	La clave esta en usar la criba de Eratostenes
*/
#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 1000000 + 1

int main(int argc, char const *argv[]){

	int n;
	bool criba[MAX];

	for(int i = 0; i < MAX; i++){
		criba[i] = true;
	}

	criba[0] = false;
	criba[1] = false;

	for(int i = 2; i < MAX; i++){
		if(criba[i]){
			for(int j = 2; i * j < MAX; j++){
				criba[i * j] = false;
			}
		}
	}

	while(cin >> n){
		if(n == 0){
			break;
		}
		/*
			n = aMin + aMax
			aMax = n - aMin
		*/
		bool encontrado = false;
		for(int i = 2; i <= n; i++){
			if(criba[i] && criba[n - i]){

				printf("%d = %d + %d\n", n, i, n - i);
				encontrado = true;
				break;
			}
		}
		if(!encontrado){
			printf("Goldbach's conjecture is wrong.\n");
		}
	}
	
	return 0;
}