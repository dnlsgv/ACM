#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, n, respuesta;

	cin >> T;

	while(T--)
	{
		cin >> n;

		respuesta = (((((((n*567)/9) + 7492) * 235)/47) - 498)%100)/10;
		respuesta = (respuesta >= 0) ? respuesta : respuesta*-1;

		cout << respuesta  << endl;
	}

	return 0;
}