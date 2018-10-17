#include <iostream>
#include <cmath>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int T, gradoPolinomio, d, k;
	long long coeficientes[20];

	cin >> T;

	while(T--)
	{
		cin >> gradoPolinomio;

		for(int i = 0; i <= gradoPolinomio; ++i)
		{
			cin >> coeficientes[i];
		}

		cin >> d >> k;

		bool alcanzarK = false;
		long long respuesta;

		while(!alcanzarK)
		{
			//bn
			long long terminosAlcanzados = 0, bi;
			for(long long i = 1; ; ++i)
			{
				//bi = coeficientes[0];
				bi = 0;
				for(long long j = 0; j <= gradoPolinomio; ++j)
				{
					bi+=(coeficientes[j] * pow(i, j));
				}
				// debug(bi);
				terminosAlcanzados+=( i * d );

				if(terminosAlcanzados >= k)
				{
					respuesta = bi;
					alcanzarK = true;
					break;
				}
			}
			//debug(respuesta);
			cout << respuesta <<  endl;
		}
	}

	return 0;
}