#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long ll;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(void)
{
	int T, farmers, x, y, z;
	ll answer;

	cin >> T;

	while(T--)
	{
		cin >> farmers;
		answer = 0;

		for(int i = 0; i < farmers; ++i)
		{
			cin >> x >> y >> z;
			answer+=(x * z);
		}
		cout << answer << endl;
	}
	return 0;
}