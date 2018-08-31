#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{

	int N, balance, casos;

	casos = 1;
	while(cin >> N)
	{
		if(N == 0)
		{
			break;
		}

		balance = 0;

		for(int i = 0, valor; i < N; ++i)
		{
			cin >> valor;
			balance+=((valor > 0) ? 1 : -1 );
		} 

		printf("Case %d: %d\n", casos, balance );
		casos++;
	}

	return 0;
}