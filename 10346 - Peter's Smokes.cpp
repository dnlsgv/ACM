#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, k, cigarros, restos, nuevosCigarros;

	while(cin >> n >> k)
	{
		restos = n;
		cigarros = n;

		while(restos >= k)
		{
			nuevosCigarros = restos/k;
			restos = restos - (nuevosCigarros * k) + nuevosCigarros;
			cigarros+=nuevosCigarros;
		}

		cout << cigarros << endl;
	}

	return 0;
}