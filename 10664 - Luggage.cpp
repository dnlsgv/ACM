#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

int cantidadMaletas, pesoMaximo;
int pesos[20 + 1];
int dp[20 + 1][20 * 200 + 1];

int back(int indiceActual, int sumatoriaActual)
{
	if(indiceActual == cantidadMaletas)
	{
		return abs(sumatoriaActual - (pesoMaximo - sumatoriaActual));
	}

	dp[indiceActual][sumatoriaActual] = min(back(indiceActual + 1, sumatoriaActual + pesos[indiceActual]), back(indiceActual + 1, sumatoriaActual));

	return dp[indiceActual][sumatoriaActual];
}

int main(int argc, char const *argv[])
{
	int T;
	string lineaCompleta;

	cin >> T;

	getline(cin, lineaCompleta);//Para dejar apuntado hacia las nuevas lineas

	while(T--)
	{
		getline(cin, lineaCompleta);

		string pesoMaletaString;
		stringstream ss(lineaCompleta);
		cantidadMaletas = 0;
		pesoMaximo = 0;

		while(ss >> pesoMaletaString)
		{
			pesos[cantidadMaletas] = stoi(pesoMaletaString);
			pesoMaximo+=pesos[cantidadMaletas];
			cantidadMaletas++;
		}

		if(back(0, 0) == 0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	
	return 0;
}