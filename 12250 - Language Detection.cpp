#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	string saludo;
	int casos;
	map<string, string> palabras;

	palabras["HOLA"] = "SPANISH";
	palabras["HELLO"] = "ENGLISH";
	palabras["HALLO"] = "GERMAN";
	palabras["BONJOUR"] = "FRENCH";
	palabras["CIAO"] = "ITALIAN";
	palabras["ZDRAVSTVUJTE"] = "RUSSIAN";

	casos = 1;
	
	while(cin >> saludo)
	{
		if(saludo == "#")
		{
			break;
		}

		cout << "Case " << casos << ": " << ((palabras.count(saludo) == 0) ? "UNKNOWN" : palabras[saludo]) << endl;

		casos++;
	}

	return 0;
}