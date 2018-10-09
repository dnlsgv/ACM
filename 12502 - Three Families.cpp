#include <iostream>
#include <cmath>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int T, x, y, z, totalEnMinutos, minutosDelMayor, minutosDelMenor, mitadMinutos, sumaXY;
	bool usandoX;
	double respuesta;

	cin >> T;

	while(T--)
	{
		cin >> x >> y >> z;

		sumaXY = x + y;
		totalEnMinutos = (x + y) * 60;
		x = x * 60;
		y = y * 60;
		mitadMinutos = totalEnMinutos/2;
		usandoX = false;

		//Determinar quien es mayor
		if(x == y)
		{
			respuesta = z/2;
		}
		else
		{
			if(x > y)
			{	
				//x mayor
				minutosDelMayor = x;
				minutosDelMenor = y;
				usandoX = true;
			}
			else
			{
				//y mayor
				minutosDelMayor = y;
				minutosDelMenor = x;
				usandoX = false;
			}

			respuesta = z * double(minutosDelMayor + (minutosDelMayor - mitadMinutos) + (abs(mitadMinutos - minutosDelMenor)))/totalEnMinutos;
			//debug(respuesta);
			//cout << respuesta << endl;
			if(!usandoX)
			{
				respuesta = z - respuesta;
			}
		}

		cout << (respuesta < 0.0 ? 0 : int(respuesta)) << endl;
	}
	
	return 0;
}