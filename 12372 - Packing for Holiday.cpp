#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{

	int T, l, w, h;
	string respuesta;

	cin >> T;

	for(int i = 1; i <= T; ++i)
	{
		cin >> l >> w >> h;

		if(l > 20 || w > 20 || h > 20)
		{
			respuesta = "bad";
		}
		else
		{
			respuesta = "good";
		}

		printf("Case %d: %s\n", i, respuesta.c_str() );
	}


	return 0;
}