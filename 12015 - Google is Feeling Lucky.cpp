#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, casos;
	vector<string> paginas;
	int valoraciones[10];

	cin >> T;

	casos = 1;

	while(T--)
	{
		for(int i = 0, valoracion; i < 10; ++i)
		{
			string nombrePagina;
			cin >> nombrePagina >> valoracion;
			
			paginas.push_back(nombrePagina);
			valoraciones[i] = valoracion;
		}

		//Encontrar la mayor puntuacion
		int mayorPuntuacion = 0;

		for(int i = 0; i < 10; ++i)
		{
			if(valoraciones[i] > mayorPuntuacion)
			{
				mayorPuntuacion = valoraciones[i];
			}
		}

		printf("Case #%d:\n", casos );
		for(int i = 0; i < 10; ++i)
		{
			if(valoraciones[i] == mayorPuntuacion)
			{
				printf("%s\n", paginas[i].c_str() );
			}
		}
		casos++;
	}


	return 0;
}