#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string n;
	int respuesta;

	while(cin >> n)
	{
		if(n == "0")
		{
			break;
		}

		respuesta = 0;

		while(n.size() != 1)
		{
			respuesta = 0;
			for(int i = 0; i < n.size(); ++i)
			{
				respuesta+=(int(n[i] - '0'));
			}
			n = to_string(respuesta);
		}		

		cout << n << endl;
	}

	return 0;
}