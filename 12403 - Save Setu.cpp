#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	
	int T, montoTotal, monto;
	string operacion;

	montoTotal = 0;
	
	cin >> T;

	while(T--)
	{
		cin >> operacion;

		if(operacion == "donate")
		{
			cin >> monto;
			montoTotal+=monto;
		}
		else
		{
			cout << montoTotal << endl;
		}
	}

	return 0;
}