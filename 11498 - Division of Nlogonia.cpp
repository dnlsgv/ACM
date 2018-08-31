#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, puntoDeDivisionX, puntoDeDivisionY, residenciaX, residenciaY;

	while(cin >> T)
	{
		if(T == 0)
		{
			break;
		}

		cin >> puntoDeDivisionX >> puntoDeDivisionY;

		for(int i = 0; i < T; ++i)
		{
			cin >> residenciaX >> residenciaY;

			if(puntoDeDivisionX == residenciaX || puntoDeDivisionY == residenciaY)
			{
				cout << "divisa" << endl;
			}
			else
			{
				if(residenciaX > puntoDeDivisionX)
				{
					if(residenciaY > puntoDeDivisionY)
					{
						cout << "NE" << endl;
					}
					else
					{
						cout << "SE" << endl;	
					}
				}
				else
				{
					if(residenciaY > puntoDeDivisionY)
					{
						cout << "NO" << endl;
					}
					else
					{
						cout << "SO" << endl;
					}
				}
			}
		}
	}

	return 0;
}