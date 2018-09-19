/*
	Load balancing - Greedy
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int cantidadCamaras, cantidadEspecimenes, casos;

	casos = 1;

	while(cin >> cantidadCamaras >> cantidadEspecimenes)
	{
		vector<int> camaras[cantidadCamaras]; // 0 -> cantidadCamaras
		int especimenes[cantidadEspecimenes];
		vector<int> especimenesArreglados;
		double masaPromedio;
		int sumatoria;

		sumatoria = 0;

		for(int i = 0; i < cantidadEspecimenes; ++i)
		{
			cin >> especimenes[i];
			especimenesArreglados.push_back(especimenes[i]);
			sumatoria+=especimenes[i];
		}

		masaPromedio = double(sumatoria)/cantidadCamaras;

		if(cantidadEspecimenes < 2 * cantidadCamaras)
		{
			//agregar 2*cantidadCamaras - S especimenes nuevos
			for(int i = 0; i < 2*cantidadCamaras - cantidadEspecimenes; ++i)
			{
				especimenesArreglados.push_back(0);
			}
		}

		sort(especimenesArreglados.begin(), especimenesArreglados.end());

		for(int i = 0, j = especimenesArreglados.size() - 1; i < especimenesArreglados.size()/2; ++i, j--)
		{
			camaras[i].push_back(especimenesArreglados[i]);
			camaras[i].push_back(especimenesArreglados[j]);
		}

		double respuesta = 0.0;
		int sumatoriaDeCamaraAcumulada;

		printf("Set #%d\n", casos );
		for(int i = 0; i < cantidadCamaras; ++i)
		{
			sumatoriaDeCamaraAcumulada = 0;
			printf(" %d:", i );
			// cout << "camara " << i + 1 << " => ";
			for(int j = 0; j < camaras[i].size(); ++j)
			{
				sumatoriaDeCamaraAcumulada+=camaras[i][j];
				if(camaras[i][j] != 0)
					printf(" %d", camaras[i][j]);
			}
			respuesta += (fabs(sumatoriaDeCamaraAcumulada - masaPromedio));
			cout << endl;
		}
		printf("IMBALANCE = %.5f\n\n", respuesta );

		casos++;
	}

	return 0;
}