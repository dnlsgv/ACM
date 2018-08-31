/*
	DP Bottom-up
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void mostrarDatos(const vector<pair<int, float> > &datos)
{
	printf("%lu\n", datos.size() );
}

void mostrarDatosVector(const vector<int> &datos)
{
	for(int dato : datos)
	{
		printf("%d ", dato );
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	float precioUnitario, auxPrecio;
	int  M, N, P, auxCantidad, casos;

	casos = 1;

	while(cin >> precioUnitario >> M)
	{
		vector<pair<int, float> > datos;
		vector<int> consultas;

		datos.push_back(make_pair(1, precioUnitario));
		
		for(int i = 0; i < M; ++i)
		{
			cin >> auxCantidad >> auxPrecio;
			datos.push_back(make_pair(auxCantidad, auxPrecio));
		}

		string lineaDeConsultas;

		getline(cin, lineaDeConsultas);
		getline(cin, lineaDeConsultas);

		stringstream numerosComoString(lineaDeConsultas);
		string palabra;

		while(numerosComoString >> palabra)
		{
			consultas.push_back(stoi(palabra));
		}

		int K_MAX = *max_element(consultas.begin(), consultas.end());

		float dp[M + 1][K_MAX + 1];

		for(int i = 0; i <= M; ++i)
		{
			for(int j = 0; j <= K_MAX; ++j)
			{
				dp[i][j] = 0;
			}
		}

		for(int i = 0; i <= K_MAX; ++i)
		{
			dp[0][i] = precioUnitario * i;
		}

		for(int i = 1; i <= M; ++i)
		{
			for(int j = 1; j <= K_MAX; ++j)
			{
				if(datos[i].first <= j)
				{
					dp[i][j] = min(dp[i - 1][j], datos[i].second + dp[i][j - datos[i].first]);
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j], datos[i].second);
				}
			}
		}
		printf("Case %d:\n", casos);
		for(int i = 0; i < consultas.size(); ++i)
		{
			printf("Buy %d for $%.2f\n", consultas[i], dp[M][consultas[i]] );
		}

		casos++;
	}

	return 0;
}