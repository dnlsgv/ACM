#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

string numeroLimite;
ll dp[200][2][200];
bool primeraVez = true;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

string aBinario(ll numero)
{
	if(numero == 0)
	{
		return "0";
	}
	
	if(numero == 1)
	{
		return "1";
	}

	string respuesta = "";

	do
	{
		respuesta+=char((numero%2) + '0');
		numero/=2;
	}while(numero != 1);

	respuesta+="1";

	reverse(respuesta.begin(), respuesta.end());

	return respuesta;

}

ll aDecimal(string numero)
{
	ll respuesta = 0;

	for(int i = numero.size() - 1, exponente = 0; i >= 0; --i, ++exponente)
	{
		respuesta+=(pow(2, exponente) * int(numero[i] - '0'));
	}

	return respuesta;
}

ll back(int indiceActual, int restriccion, ll cantidadUnos)
{
	if(indiceActual == numeroLimite.size())
	{
		return cantidadUnos;
	}

	if(dp[indiceActual][restriccion][cantidadUnos] != -1)
	{
		return dp[indiceActual][restriccion][cantidadUnos];
	}

	ll respuesta = 0;
	// string aux = cadenaActual;

	if(restriccion)
	{
		respuesta+=back(indiceActual + 1, restriccion, cantidadUnos + 1) + back(indiceActual + 1, restriccion, cantidadUnos);
	}
	else
	{
		if(numeroLimite[indiceActual] == '0')
		{
			respuesta+=back(indiceActual + 1, restriccion, cantidadUnos);
		}
		else
		{
			respuesta+=back(indiceActual + 1, 1, cantidadUnos) + back(indiceActual + 1, 0, cantidadUnos + 1);
		}
	}
	dp[indiceActual][restriccion][cantidadUnos] = respuesta;

	return dp[indiceActual][restriccion][cantidadUnos];
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll A, B;

	while(cin >> A >> B)
	{
		primeraVez = true;
		for(int i = 0; i < 200; ++i)
		{
			for(int j = 0; j < 2; ++j)
			{
				for(int k = 0; k < 200; ++k)
				{
					dp[i][j][k] = -1;
				}
			}
		}

		numeroLimite = aBinario(B);
		string numeroAuxiliarUno(numeroLimite.size(), '0');

		ll primeraRespuesta = back(0, 0, 0);
		// debug(numeroLimite);
		// debug(primeraRespuesta);

		for(int i = 0; i < 200; ++i)
		{
			for(int j = 0; j < 2; ++j)
			{
				for(int k = 0; k < 200; ++k)
				{
					dp[i][j][k] = -1;
				}
			}
		}

		numeroLimite = aBinario(A - 1);
		string numeroAuxiliarDos(numeroLimite.size(), '0');

		ll segundaRespuesta = back(0, 0, 0);

		cout << primeraRespuesta - segundaRespuesta << endl;
	}

	return 0;
}