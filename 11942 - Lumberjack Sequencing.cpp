#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	int medidas[10];
	bool menorMayor, mayorMenor;

	cin >> N;

	printf("Lumberjacks:\n");
	while(N--)
	{
		menorMayor = mayorMenor = true;
		for(int i = 0; i < 10; ++i)
		{
			scanf("%d", &medidas[i]);
		}
		//ver si es de menor a mayor
		for(int i = 1; i < 10; ++i)
		{
			if(medidas[i] < medidas[i - 1])
			{
				menorMayor = false;
			}
		}

		for(int i = 1; i < 10; ++i)
		{
			if(medidas[i] > medidas[i - 1])
			{
				mayorMenor = false;
			}
		}

		if(menorMayor == mayorMenor)
		{
			printf("Unordered\n");
		}
		else
		{
			printf("Ordered\n");
		}

	}
	
	return 0;
}