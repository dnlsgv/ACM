#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <utility>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	double inicioDouble, finDouble;
	int inicio, fin;

	while(cin >> inicioDouble >> finDouble)
	{
		inicio = inicioDouble * 100;
		fin = finDouble * 100;

		vector<pair<bool, vector<int> > > salida(256000 + 1);

		for(int i = 0; i < 256000 + 1; ++i)
		{
			salida[i] = make_pair(false, vector<int>());
		}

		int numerosBuscados[256 * 100 + 2];

		for(int i = 0; i < 256 * 100 + 2; ++i)
		{
			numerosBuscados[i] = 0;
		}

		for(int i = inicio; i <= fin; ++i)
		{
			numerosBuscados[i] = 1;
		}

		for(int a = 1; a <= fin/2; ++a)
		{
			for(int b = a; b <= fin - a ; ++b)
			{
				int numerador, denominador;

				numerador = 10000 * (a + b);
				denominador = (a * b) - 10000;

				if(denominador <= 0)
				{
					continue;
				}

				if(numerador%denominador != 0)
				{
					continue;
				}

				int c = numerador/denominador;
				if(b > c)
				{
					continue;
				}

				if(a + b + c > fin)
				{
					continue;
				}
				if(a + b + c == a * b * c/10000 && numerosBuscados[a + b + c] == 1)
				{
					salida[a + b + c].first = true;
					salida[a + b + c].second.push_back(a);
					salida[a + b + c].second.push_back(b);
					salida[a + b + c].second.push_back(c);
				}
			}
		}

		for(int i = 0; i < 256000 + 1; ++i)
		{
			if(salida[i].first)
			{
				printf("%.2f = %.2f + %.2f + %.2f = %.2f * %.2f * %.2f\n", i/100.00, salida[i].second[0]/100.00, salida[i].second[1]/100.00, salida[i].second[2]/100.00, salida[i].second[0]/100.00, salida[i].second[1]/100.00, salida[i].second[2]/100.00  );

				if(salida[i].second.size() > 3)
				{
					printf("%.2f = %.2f + %.2f + %.2f = %.2f * %.2f * %.2f\n", i/100.00, salida[i].second[3]/100.00, salida[i].second[4]/100.00, salida[i].second[5]/100.00, salida[i].second[3]/100.00, salida[i].second[4]/100.00, salida[i].second[5]/100.00  );
				}
				if(salida[i].second.size() > 6)
				{
					printf("%.2f = %.2f + %.2f + %.2f = %.2f * %.2f * %.2f\n", i/100.00, salida[i].second[6]/100.00, salida[i].second[7]/100.00, salida[i].second[8]/100.00, salida[i].second[6]/100.00, salida[i].second[7]/100.00, salida[i].second[8]/100.00  );
				}
			}
		}
	}

	return 0;
}