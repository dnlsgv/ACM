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
	int T, N, instructions[100 + 1], answer;
	string instruction;

	cin >> T;

	while(T--)
	{
		memset(instructions, 0, sizeof(instructions));
		cin >> N;

		for(int i = 0; i < N; ++i)
		{
			cin >> instruction;

			if(instruction == "RIGHT")
			{
				instructions[i] = 1;
			}
			else
			{
				if(instruction == "LEFT")
				{
					instructions[i] = -1;
				}
				else
				{
					int value;
					cin >> instruction >> value;
					instructions[i] = instructions[value - 1];
				}
			}
		}
		
		answer = 0;
		
		for(int i = 0; i < N; ++i)
		{
			answer+=instructions[i];
		}
		cout << answer << endl;
	}
	return 0;
}