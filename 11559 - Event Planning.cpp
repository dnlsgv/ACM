#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, B, H, W;
	int montoHotel;

	while(scanf("%d %d %d %d", &N, &B, &H, &W) != EOF)
	{
		int grid[H][W];
		int montosHoteles[H];

		for(int i = 0; i < H; ++i)
		{
			scanf("%d", &montosHoteles[i]);
			for(int j = 0; j < W; ++j)
			{
				scanf("%d", &grid[i][j]);
			}
		}

		int montoMinimo = 9999999;

		for(int i = 0; i < H; ++i)
		{
			for(int j = 0; j < W; ++j)
			{
				if(grid[i][j] >= N)
				{
					montoMinimo = min(montoMinimo, N * montosHoteles[i]);
				}
			}
		}

		if(montoMinimo > B)
		{
			printf("stay home\n");
		}
		else
		{
			printf("%d\n", montoMinimo );
		}
	}

	return 0;
}