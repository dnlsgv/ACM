/*
	10334 - Ray Through Glasses
	Fibonacci + Trabajar con numeros gigantes
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> numerosFibonacci(1001);

string sumarNumerosGrandes(string numeroUno, string numeroDos){
	vector<string> numerosPorSumar;

	int mayorLongitud;

	numerosPorSumar.push_back(numeroUno);
	numerosPorSumar.push_back(numeroDos);

	if(numeroUno.size() > numeroDos.size()){
		mayorLongitud = numeroUno.size();
	}
	else{
		if(numeroUno.size() < numeroDos.size()){
			mayorLongitud = numeroDos.size();
		}
		else{
			mayorLongitud = numeroUno.size();
		}
	}

	string numeroFormateado;
	int cerosPorAgregar;
	for(int i = 0; i < numerosPorSumar.size(); i++){
		numeroFormateado = "";
		cerosPorAgregar = mayorLongitud - numerosPorSumar[i].size();

		if(cerosPorAgregar > 0){
			for(int j = 0; j < cerosPorAgregar; j++){
				numeroFormateado+="0";
			}
			numeroFormateado+=numerosPorSumar[i];
			numerosPorSumar[i] = numeroFormateado;
		}
	}

	int primeraColumna = mayorLongitud - 1;
	int carreo;
	string numeroFinal = "";

	carreo = 0;

	for(int i = numerosPorSumar[0].size()-1; i >= 0; i--){
		int sumatoria = 0;
		for(int j = 0; j < 2 ; j++){
			sumatoria+=(numerosPorSumar[j][i] - '0');
		}

		sumatoria+=carreo;
		carreo = 0;
		if(sumatoria > 9){
			carreo = sumatoria/10;
		}
		numeroFinal+=to_string(sumatoria%10);
		//printf("%d\n", sumatoria );
	}

	if(carreo > 0){
		while(carreo > 0){
			int mod = carreo%10;
			carreo/=10;
			numeroFinal+=(mod + '0');
		}
	}
	
	reverse(numeroFinal.begin(), numeroFinal.end());

	return numeroFinal;
}

int main(int argc, char const *argv[]){

	int numero;

	numerosFibonacci[0] = "1";
	numerosFibonacci[1] = "2";		
	numerosFibonacci[2] = "3";		

	for(int i = 3; i <= 1000; i++){
		numerosFibonacci[i] = sumarNumerosGrandes(numerosFibonacci[i - 1], numerosFibonacci[i - 2]);
	}

	while(scanf("%d", &numero) != EOF){
		printf("%s\n", numerosFibonacci[numero].c_str() );
	}

	return 0;
}