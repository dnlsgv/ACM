//Programación dinámica - Coin change problem
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{

	int monedas[] = {0, 1, 5, 10, 25, 50};
	long long grid[5 + 1][30000 + 1];

	grid[0][0] = 1;

	for(int i = 1; i <= 5; ++i) grid[0][i] = 0;

	for(int i = 1; i <= 5; ++i)
	{
		for(int j = 0; j <= 30000; ++j)
		{
			if(monedas[i] > j)
			{
				grid[i][j] = grid[i - 1][j];
			}
			else
			{
				grid[i][j] = grid[i - 1][j] + grid[i][j - monedas[i]];
			}
		}
	}

	int consulta;

	while(cin >> consulta)
	{
		if(grid[5][consulta] > 1)
		{
			printf("There are %lld ways to produce %d cents change.\n", grid[5][consulta], consulta);
		}
		else
		{
			printf("There is only 1 way to produce %d cents change.\n", consulta);
		}
	}

	return 0;
}