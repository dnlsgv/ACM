#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, sumaObjetivo, cantidadNumeros;
	int numeros[1000 + 1];
	bool haySolucion;

	cin >> T;

	while(T--)
	{
		cin >> sumaObjetivo >> cantidadNumeros;
		haySolucion = false;
		for(int i = 0; i < cantidadNumeros; ++i)
		{
			cin >> numeros[i];
		}

		int sumatoria;
		for(int i = 0; i < (1 << cantidadNumeros); ++i)
		{
			sumatoria = 0;
			for(int j = 0; j < cantidadNumeros; ++j)
			{
				//Ver si el j bit esta prendido
				if(i & (1 << j))
				{
					sumatoria+=numeros[j];
				}
			}
			if(sumatoria == sumaObjetivo)
			{
				haySolucion = true;
				break;
			}
		}
		cout << (haySolucion ? "YES" : "NO") << endl;
	}

	return 0;
}