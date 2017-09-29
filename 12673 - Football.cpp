/*
	12673 - Football
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){

	vector<int> diferenciaDeGoles;
	int partidosJugados, golesComprados;
	int s, r;
	int puntosObtenidos;

	while(cin >> partidosJugados >> golesComprados){

		diferenciaDeGoles.clear();
		puntosObtenidos = 0;

		for(int i = 0; i < partidosJugados; i++){
			cin >> s >> r;
			// cout << s << " - " << r << endl;
			if(s <= r){
				diferenciaDeGoles.push_back(abs(s - r));			
			}
			else{
				puntosObtenidos+=3;
			}
		}
		sort(diferenciaDeGoles.begin(), diferenciaDeGoles.end());
		for(int i = 0; i < diferenciaDeGoles.size(); i++){
			if(golesComprados == 0){
				if(diferenciaDeGoles[i] == 0){
					puntosObtenidos+=1;
				}
				else{
					break;
				}
			}
			else{
				if(diferenciaDeGoles[i] == 0){
					golesComprados--;
					puntosObtenidos+=3;
				}
				else{
					if(diferenciaDeGoles[i] == golesComprados){
						golesComprados = 0;
						puntosObtenidos+=1;
					}
					else{
						if(diferenciaDeGoles[i] < golesComprados){
							golesComprados-=(diferenciaDeGoles[i] + 1);
							puntosObtenidos+=3;
						}
					}
				}
			}

		}
		cout << puntosObtenidos << endl;

	}


	
	return 0;
}