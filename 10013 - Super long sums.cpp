/*
	10013 - Super long sums
	
	Sumar 2 numeros gigantes, tratarlos como un string.
	Al ser solo 2 numeros por sumar y me dan la longitud máxima de uno de ellos,
	se evitan problemas de rellenar con ceros y solo se suma columna por columna
	teniendo cuidado con el acarreo de la suma.
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){

	int T, mayorLongitud, sumaColumna, acarreo;
	string numeroUno, numeroDos, numeroSumado;
	char digitoNumeroUno, digitoNumeroDos;

	scanf("%d", &T);

	while(T--){
		numeroUno = "";
		numeroDos = "";
		numeroSumado = "";

		scanf("%d", &mayorLongitud);
		for(int i = 0; i < mayorLongitud; i++){
			cin >> digitoNumeroUno;
			cin >> digitoNumeroDos;

			numeroUno.push_back(digitoNumeroUno);
			numeroDos.push_back(digitoNumeroDos);
		}

		acarreo = 0;

		for(int i = mayorLongitud - 1; i >= 0; i--){
			sumaColumna = (numeroUno[i] - '0') + (numeroDos[i] - '0');
			sumaColumna += acarreo;

			acarreo = 0;

			if(sumaColumna > 9){
				acarreo = sumaColumna/10;
			}
			numeroSumado+=(to_string(sumaColumna%10));
		}

		if(acarreo > 0){
			while(acarreo > 0){
				int mod = acarreo%10;
				acarreo/=10;
				numeroSumado+=to_string(mod);
			}
		}	
		reverse(numeroSumado.begin(), numeroSumado.end());
		printf("%s\n", numeroSumado.c_str() );
		if(T >= 1){
			printf("\n");
		}
	}


	return 0;
}