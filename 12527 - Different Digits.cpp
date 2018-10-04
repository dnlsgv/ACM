#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	int digitosOcupados[10];

	while(cin >> N >> M)
	{
		string numeroEnString;
		bool tieneDigitosUnicos;
		int respuesta = 0;

		for(int i = N; i <= M; ++i)
		{
			for(int i = 0; i < 10; ++i)
			{
				digitosOcupados[i] = 0;
			}

			numeroEnString = to_string(i);
			tieneDigitosUnicos = true;

			for(int j = 0; j < numeroEnString.size(); ++j)
			{
				int digito = int(numeroEnString[j] - '0');
				digitosOcupados[digito]++;
				if(digitosOcupados[digito] > 1)
				{
					tieneDigitosUnicos = false;
					break;
				}
			}
			if(tieneDigitosUnicos)
			{
				respuesta++;
			}
		}
		cout << respuesta << endl;
	}

	return 0;
}