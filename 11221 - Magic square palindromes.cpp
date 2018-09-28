#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int T, casos = 1;
	string lineaCompleta;
	string caracteresProhibidos = " ,.?¿¡!()";
	int secuenciasPermitidas[100];

	for(int i = 0; i < 100; ++i)
	{
		secuenciasPermitidas[i] = (i + 1) * (i + 1);
	}

	cin >> T;
	getline(cin, lineaCompleta);

	while(T--)
	{
		string palabraProcesada = "";
		getline(cin, lineaCompleta);

		for(int i = 0; i < lineaCompleta.size(); ++i)
		{
			if(caracteresProhibidos.find(lineaCompleta[i]) == string::npos)
			{
				palabraProcesada+=lineaCompleta[i];
			}
		}

		bool posibleCuadrado = false;
		int tamSecuencia;
		for(int i = 0; i < 100; ++i)
		{
			if((i + 1)*(i + 1) == palabraProcesada.size())
			{
				tamSecuencia = secuenciasPermitidas[i];
				posibleCuadrado = true;
				tamSecuencia = i + 1;
			}
		}

		printf("Case #%d:\n", casos );
		if(!posibleCuadrado)
		{
			printf("No magic :(\n");
		}
		else
		{
			//Hacer una matriz de tamSecuenciaxtamSecuencia y verificar
			char matriz[tamSecuencia][tamSecuencia];
			int posicionPalabra = 0;
			for(int i = 0; i < tamSecuencia; ++i)
			{
				for(int j = 0; j < tamSecuencia; ++j)
				{
					matriz[i][j] = palabraProcesada[posicionPalabra];
					posicionPalabra++;
				}
			}

			string str1, str2, str3, str4;

			str1 = str2 = str3 = str4 = "";

			for(int i = 0; i < tamSecuencia; ++i)
			{
				str1+=matriz[0][i]; str2+=matriz[i][0]; str3+=matriz[tamSecuencia - 1][i]; str4+=matriz[i][tamSecuencia - 1];
			}

			reverse(str3.begin(), str3.end());
			reverse(str4.begin(), str4.end());

			if(str1 == str2 && str1 == str3 && str1 == str4 && str2 == str3 && str3 == str4)
			{
				printf("%d\n", tamSecuencia );
			}
			else
			{
				printf("No magic :(\n");
			}
		}
		casos++;
	}

	return 0;
}