//https://bit.ly/2rfGnYg
#include <iostream>
#include <string.h>

using namespace std;

long long memorizacion[50 + 1];

long long fibonacci(int n)
{
	if(memorizacion[n] != -1)
	{
		return memorizacion[n];
	}
	else
	{
		memorizacion[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return memorizacion[n];
	}
}

int main(int argc, char const *argv[])
{

	for(int i = 0; i <= 50; ++i) memorizacion[i] = -1;
	
	memorizacion[0] = 0;
	memorizacion[1] = 1;

	fibonacci(50);

	int longitud;

	while(cin >> longitud)
	{
		if(longitud == 0)
		{
			break;
		}
		else
		{
			cout << memorizacion[longitud + 1] << endl;
		}
	}

	return 0;
}