#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int cantidadGrupos, longitudSubstring;
	string palabraCompleta;

	while(cin >> cantidadGrupos)
	{
		if(cantidadGrupos == 0)
		{
			break;
		}

		cin >> palabraCompleta;

		longitudSubstring = palabraCompleta.size()/cantidadGrupos;

		for(int i = 0; i < palabraCompleta.size(); i+=longitudSubstring)
		{
			string subCadena = palabraCompleta.substr(i, longitudSubstring);
			reverse(subCadena.begin(), subCadena.end());
			cout << subCadena;
		}
		cout << endl;
	}
	
	return 0;
}