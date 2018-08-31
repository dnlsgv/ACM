#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, n, m, porColumna, porFila, primeraColumna, restoDeColumnas;

	cin >> T;

	while(T--)
	{
		cin >> n >> m;

		n-=2;
		m-=2;

		primeraColumna = n/3;

		if(n%3 > 0)
		{
			primeraColumna++;
		}

		restoDeColumnas = m/3;

		if(m%3 > 0)
		{
			restoDeColumnas++;
		}

		cout << primeraColumna*restoDeColumnas << endl;

	}
	
	return 0;
}