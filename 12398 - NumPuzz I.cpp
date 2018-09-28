#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	vector<string> tableroConLetras;
	int tableroConNumeros[5][5], casos = 1;
	string configuracionFinal;

	tableroConLetras.push_back("////");
	tableroConLetras.push_back("/abc/");
	tableroConLetras.push_back("/def/");
	tableroConLetras.push_back("/ghi/");
	tableroConLetras.push_back("////");

	while(getline(cin, configuracionFinal))
	{
		for(int i = 0; i < 5; ++i)
		{
			for(int j = 0; j < 5; ++j)
			{
				tableroConNumeros[i][j] = 0;
			}
		}


		for(int i = 0; i < configuracionFinal.size(); ++i)
		{
			char letraBuscada = configuracionFinal[i];

			for(int i = 1; i < 4; ++i)
			{
				for(int j = 1; j < 4; ++j)
				{
					if(tableroConLetras[i][j] == letraBuscada)
					{
						tableroConNumeros[i][j] = (tableroConNumeros[i][j] + 1 > 9 ? 0 : tableroConNumeros[i][j] + 1);
						tableroConNumeros[i - 1][j]= (tableroConNumeros[i - 1][j] + 1 > 9 ?  0 : tableroConNumeros[i - 1][j] + 1);
						tableroConNumeros[i][j - 1] = (tableroConNumeros[i][j - 1] + 1 > 9 ? 0 : tableroConNumeros[i][j - 1] + 1);
						tableroConNumeros[i + 1][j] = (tableroConNumeros[i + 1][j] + 1 > 9 ? 0 : tableroConNumeros[i + 1][j] + 1);
						tableroConNumeros[i][j + 1] = (tableroConNumeros[i][j + 1] + 1 > 9 ? 0 : tableroConNumeros[i][j + 1] + 1);

						// tableroConNumeros[i][j]++;//Misma posicion
						// tableroConNumeros[i - 1][j]++;//Izquierda
						// tableroConNumeros[i][j - 1]++;//Arriba
						// tableroConNumeros[i + 1][j]++ ;//Abajo
						// tableroConNumeros[i][j + 1]++;//Derecha
					}
				}
			}
		}

		printf("Case #%d:\n", casos );
		for(int i = 1; i < 4; ++i)
		{
			printf("%d", tableroConNumeros[i][1] );
			for(int j = 2; j < 4; ++j)
			{
				printf(" %d", tableroConNumeros[i][j] );
			}
			printf("\n");
		}
		casos++;
	}

	return 0;
}