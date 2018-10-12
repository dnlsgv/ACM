#include <iostream>

using namespace std;

int sumaObjetivo, cantidadBarras;
int barras[20 + 1];

bool back(int indiceActual, int sumaActual)
{
	if(indiceActual == cantidadBarras)
	{
		if(sumaActual == sumaObjetivo)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(sumaActual == sumaObjetivo)
	{
		return true;
	}
	else
	{
		if(sumaActual > sumaObjetivo)
		{
			return false;
		}
		else
		{
			return (back(indiceActual + 1, sumaActual + barras[indiceActual]) || back(indiceActual + 1, sumaActual));
		}
	}
}

int main(int argc, char const *argv[])
{
	int T;

	cin >> T;

	while(T--)
	{
		cin >> sumaObjetivo >> cantidadBarras;
		for(int i = 0; i < cantidadBarras; ++i)
		{
			cin >> barras[i];
		}
		cout << (back(0, 0) ? "YES" : "NO") << endl;
	}

	return 0;
}