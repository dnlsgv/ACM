#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

int main(void)
{
	int T, N, highJumps, lowJumps, c = 1;

	cin >> T;

	while(T--)
	{
		cin >> N;
		int walls[N];

		for(int i = 0; i < N; ++i)
		{
			cin >> walls[i];
		}
		
		highJumps = lowJumps = 0;

		for(int i = 0; i < N - 1; ++i)
		{
			if(walls[i + 1] > walls[i])
			{
				highJumps++;
			}
			else
			{
				if(walls[i + 1] < walls[i])
				{
					lowJumps++;
				}
			}
		}

		printf("Case %d: %d %d\n", c, highJumps, lowJumps);
		
		c++;
	}


	return 0;
}