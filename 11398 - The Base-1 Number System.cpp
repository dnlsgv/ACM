#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	string bloque, flag, numeroBinario;
	vector<string> bloqueCompleto;
	long long salida;
	for(;;)
	{
		cin >> bloque;
		if(bloque == "~")
		{
			break;
		}

		if(bloque == "#")
		{
			//calcular
			numeroBinario = "";
			salida = 0;
			for(string secuencia : bloqueCompleto)
			{
				if(secuencia.size() == 1)
				{
					flag = "1";
				}
				else
				{
					if(secuencia.size() == 2)
					{
						flag = "0";
					}
					else
					{
						for(int i = 0; i < secuencia.size() - 2; ++i)
						{
							numeroBinario+=flag;
						}
					}
				}
			}

			for(int i = 0, j = numeroBinario.size() - 1; j >= 0; ++i, --j)
			{
				if(numeroBinario[j] == '1')
				{
					salida+=(pow(2, i));
				}
			}
			
			cout << salida << endl;
			bloqueCompleto.clear();
		}
		else
		{
			bloqueCompleto.push_back(bloque);
		}
	}

	return 0;
}