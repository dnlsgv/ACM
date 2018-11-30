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
	//Happy birthday to you! Happy birthday to you! Happy birthday to Rujia! Happy birthday to you!!!
	vs message;
	int N, repeat, j = 0;

	message.push_back("Happy");
	message.push_back("birthday");
	message.push_back("to");
	message.push_back("you");
	message.push_back("Happy");
	message.push_back("birthday");
	message.push_back("to");
	message.push_back("you");
	message.push_back("Happy");
	message.push_back("birthday");
	message.push_back("to");
	message.push_back("Rujia");
	message.push_back("Happy");
	message.push_back("birthday");
	message.push_back("to");
	message.push_back("you");

	cin >> N;

	vs people(N);

	for(int i = 0; i < N; ++i)
	{
		cin >> people[i];
	}

	repeat = (N%16 == 0 ? N/16 : 1 + (N/16));

	for(int i = 0; i < repeat; ++i)
	{
		for(int m = 0; m < 16; ++j, ++m)
		{
			if(j == N)
			{
				j = 0;
			}
			printf("%s: %s\n", people[j].c_str(), message[m].c_str() );
		}
	}
	return 0;
}