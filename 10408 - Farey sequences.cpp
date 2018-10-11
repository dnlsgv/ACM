#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cstdio>

using namespace std;

bool ordenarPorElSegundoParametro(const pair<string, double> &a, const pair<string, double> &b)
{
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
	int n, k;

	while(cin >> n >> k)
	{
		vector<pair<string, double> > secuencia;
		string fraccionString;

		for(int i = 1; i < n; ++i)
		{
			for(int j = n; j >= 1; --j)
			{
				if(double(i)/j >= 0 && double(i)/j <= 1 && __gcd(i, j) == 1)
				{
					fraccionString = (to_string(i) + "/" + to_string(j));
					secuencia.push_back(make_pair(fraccionString, double(i)/j));
				}
			}
		}

		sort(secuencia.begin(), secuencia.end(), ordenarPorElSegundoParametro);

		cout << secuencia[k - 1].first << endl;
	}

	return 0;
}