#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

int M, N;
vector<vector<int> >  matrizValores;
int dpMatriz[100000 + 10][1000 + 10];
int dp[100000 + 10];
int dp2[100000 + 10];

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int back(int indiceActual, vector<int>& filaEstadoActual, int filaActual)
{
	if(indiceActual >= N)
	{
		return 0;
	}

	if(dpMatriz[filaActual][indiceActual] != -1)
	{
		return dpMatriz[filaActual][indiceActual];
	}

	int tomar = filaEstadoActual[indiceActual] + back(indiceActual + 2, filaEstadoActual, filaActual);
	int noTomar = back(indiceActual + 1, filaEstadoActual, filaActual);

	return dpMatriz[filaActual][indiceActual] = max(tomar, noTomar);
}

int back2(int filaActual1)
{
	//Elegir esa fila o no
	if(filaActual1 >= M)
	{
		return 0;
	}

	if(dp2[filaActual1] != -1)
	{
		return dp2[filaActual1];
	}

	int tomar = back(0, matrizValores[filaActual1], filaActual1) + back2(filaActual1 + 2);
	int noTomar = 0 + back2(filaActual1 + 1);

	return dp2[filaActual1] = max(tomar, noTomar);
}

int main(int argc, char const *argv[])
{

	while(cin >> M >> N)
	{
		if(M == 0 && N == 0)
		{
			break;
		}

		for(int i = 0; i <= M; ++i)
		{
			for(int j = 0; j <= N; ++j)
			{
				dpMatriz[i][j] = -1;
			}
		}

		for(int i = 0; i < 100000 + 10; ++i)
		{
			dp[i] = -1;
			dp2[i] = -1;
		}

		matrizValores.clear();

		for(int i = 0; i < M; ++i)
		{
			vector<int> vectorAuxiliar;
			for(int j = 0; j < N; ++j)
			{
				int aux;
				cin >> aux;
				vectorAuxiliar.push_back(aux);
			}
			matrizValores.push_back(vectorAuxiliar);
		}
		cout << back2(0) << endl;
	}

	return 0;
}