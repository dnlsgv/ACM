#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{

	int caso = 1;
	string nombre;

	while(cin >> nombre)
	{
		if(nombre == "*")
		{
			break;
		}

		cout << "Case " << caso << ": Hajj-e-" << (nombre == "Hajj" ? "Akbar" : "Asghar") << endl;
		caso++;
	}

	return 0;
}