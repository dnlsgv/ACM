#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, N, sumatoria, promedio, menor, mayor;

	cin >> T;

	while(T--)
	{
		cin >> N;
		sumatoria = 0;
		vector<int> valores;

		for(int i = 0, aux; i < N; ++i)
		{
			cin >> aux;
			valores.push_back(aux);
			sumatoria+=aux;
		}

		promedio = sumatoria/N;
		sort(valores.begin(), valores.end());
		menor = valores[0];
		mayor = valores[N - 1];

		cout << 2*(mayor - promedio) + 2*(promedio - menor) << endl;

	}

	return 0;
}