#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int a, b;

	while(cin >> a >> b)
	{
		if(a == -1 && b == -1)
		{
			break;
		}

		if(a > b)
		{
			printf("%d\n", min(abs(a - b), 99 - a + b + 1));
		}
		else
		{
			if(b > a)
			{
				printf("%d\n", min(abs(a - b), a + 99 - b + 1));
			}
			else
			{
				printf("0\n");
			}
		}
	}

	return 0;
}