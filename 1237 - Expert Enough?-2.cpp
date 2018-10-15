#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int T, Q, cantidadDatos, menorPrecio, mayorPrecio, precioBuscado, encontrados;
	string nombre, respuesta;
	vector<pair<string, vector<int> > > datos;

	cin >> T;

	while(T--)
	{
		datos.clear();
		cin >> cantidadDatos;
		vector<int> vectorAux;

		for(int i = 0; i < cantidadDatos; ++i)
		{
			vectorAux.clear();
			cin >> nombre >> menorPrecio >> mayorPrecio;
			vectorAux.push_back(menorPrecio);
			vectorAux.push_back(mayorPrecio);
			datos.push_back(make_pair(nombre, vectorAux));
		}

		cin >> Q;

		for(int i = 0; i < Q; ++i)
		{
			cin >> precioBuscado;
			// debug(precioBuscado);
			
			encontrados = 0;
			for(int i = 0; i < cantidadDatos; ++i)
			{
				// debug(datos[i].second[0]);
				if(precioBuscado >= datos[i].second[0] && precioBuscado <= datos[i].second[1])
				{
					encontrados++;
					respuesta = datos[i].first;
				}
			}
			cout << (encontrados == 1 ? respuesta : "UNDETERMINED") << endl;
		}

		if(T != 0)
		{
			cout << endl;
		}
	}

	return 0;
}