#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int visitados[90 + 1];
int grados[90 + 1];
vector<int> caracteresUnicos;
int indiceGlobal;
int LARGO;
string secuencia;

void dfsRevertido(char caracterActual)
{
	caracteresUnicos.push_back(caracterActual);
	visitados[caracterActual] = 1;

	if(indiceGlobal < secuencia.size())
		for(int i = indiceGlobal; i < secuencia.size(); ++i)
		{
			if(visitados[secuencia[i]] == 0)
			{
				indiceGlobal++;
				grados[caracterActual]++;
				grados[secuencia[i]]++;
				dfsRevertido(secuencia[i]);
				i = indiceGlobal - 1;
			}
			else
			{
				indiceGlobal++;
				return;
			}
		}
}

int main(int argc, char const *argv[])
{
	int T, casos;

	cin >> T;

	casos = 1;

	while(T--)
	{
		cin >> secuencia;
		memset(visitados, 0, sizeof(visitados[0]) * (90 + 1));
		memset(grados, 0, sizeof(grados[0]) * (90 + 1));
		caracteresUnicos.clear();
		indiceGlobal = 1;
		LARGO = secuencia.size();

		dfsRevertido(secuencia[0]);

		sort(caracteresUnicos.begin(), caracteresUnicos.end());

		printf("Case %d\n", casos);
		for(int i = 0; i < caracteresUnicos.size(); ++i)
		{
			printf("%c = %d\n", caracteresUnicos[i], grados[caracteresUnicos[i]] );
		}

		casos++;
	}

	return 0;
}