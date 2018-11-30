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

string s;

string answer(int startPosition, int endPosition)
{
	int ones, zeros;

	ones = zeros = 0;
	for(int i = startPosition; i <= endPosition; ++i)
	{
		if(s[i] == '1')
		{
			ones++;
		}
		else
		{
			zeros++;
		}
	}

	if(ones == 0 || zeros == 0)
	{
		return "Yes";
	}
	else
	{
		return "No";
	}
}

int main(void)
{
	int Q, i, j, c = 1;

	while(cin >> s)
	{
		printf("Case %d:\n", c );
		cin >> Q;
		for(int q = 0; q < Q; ++q)
		{
			cin >> i >> j;

			printf("%s\n", answer(min(i, j), max(i, j)).c_str() );
		}
		c++;
	}

	return 0;
}