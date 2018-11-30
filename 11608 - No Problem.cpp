#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(void)
{
	int S, createdProblems[12], requiredProblems[12], c = 1;
	bool solution;

	while(scanf("%d", &S), (S >= 0))
	{
		solution = true;
		for(int i = 0; i < 12; ++i)
		{
			cin >> createdProblems[i];
		}
		for(int i = 0; i < 12; ++i)
		{
			cin >> requiredProblems[i];
		}

		int acc = S;
		printf("Case %d:\n", c++ );
		for(int i = 0; i < 12; ++i)
		{
			if(i > 0)
			{
				acc+=createdProblems[i - 1];
			}

			if(requiredProblems[i] > acc)
			{
				printf("No problem. :(\n");
			}
			else
			{
				acc-=requiredProblems[i];
				printf("No problem! :D\n");
			}
		}
	}
	return 0;
}