#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	
	string lineaCompleta, todasLasLineas;

	while(getline(cin, lineaCompleta))
	{
		todasLasLineas+=(" " + lineaCompleta);
	}

	stringstream ss(todasLasLineas);
	string palabraDelTexto;
	vector<string> diccionario;
	set<string> diccionarioSet;

	while(ss >> palabraDelTexto)
	{
		string palabraFormateada;
		vector<string> palabrasDetectadas;
		for(int i = 0; i < palabraDelTexto.size(); ++i)
		{
			if(isalpha(palabraDelTexto[i]))
			{
				palabraFormateada+=((tolower(palabraDelTexto[i])));
			}
			else
			{
				palabrasDetectadas.push_back(palabraFormateada);
				palabraFormateada = "";
				//continue;
			}
		}
		if(palabraFormateada.size() > 0)
		{
			diccionarioSet.insert(palabraFormateada);
		}
		for(int i = 0; i < palabrasDetectadas.size(); ++i)
		{
			if(palabrasDetectadas.size() > 0)
				diccionarioSet.insert(palabrasDetectadas[i]);
		}		
	}

	for(string palabra : diccionarioSet)
	{
		diccionario.push_back(palabra);
	}

	sort(diccionario.begin(), diccionario.end());

	for(int i = 0; i < diccionario.size(); ++i)
	{
		if(diccionario[i].size() > 0)
		{
			cout << diccionario[i] << endl;
		}
	}

	return 0;
}