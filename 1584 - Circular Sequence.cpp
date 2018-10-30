#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	string secuencia;

	cin >> T;

	while(T--)
	{
		vector<string> secuencias;
		cin >> secuencia;

		secuencias.push_back(secuencia);
		for(int i = 1; i < secuencia.size(); ++i)
		{
			string secuenciaParcial = "";
			int posicionActual = i;
			bool volver = false;
			while(!volver)
			{
				if(posicionActual >= secuencia.size())
				{
					posicionActual = 0;
				}
				secuenciaParcial+=secuencia[posicionActual];
				if(posicionActual == i - 1)
				{
					volver = true;
				}
				posicionActual++;
			}
			// cout << secuenciaParcial << endl;
			secuencias.push_back(secuenciaParcial);
		}
		sort(secuencias.begin(), secuencias.end());

		cout << secuencias[0] << endl;
	}
	return 0;
}