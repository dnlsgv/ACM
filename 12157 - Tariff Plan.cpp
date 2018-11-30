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

int main(void)
{
	int T, N, answerM, answerJ, c = 1;

	cin >> T;

	while(T--)
	{
		cin >> N;
		int durations[N];
		answerM = answerJ = 0;

		for(int i = 0; i < N; ++i)
		{
			cin >> durations[i];
		}

		for(int i = 0; i < N; ++i)
		{
			int aux = durations[i];

			while(aux >= 0)
			{
				answerM+=10;
				aux-=30;
			}
			
			aux = durations[i];

			while(aux >= 0)
			{
				answerJ+=15;
				aux-=60;
			}
		}
		
		string output;

		if(answerM < answerJ)
		{
			output = "Mile " + to_string(answerM);
		}
		else
		{
			if(answerJ < answerM)
			{
				output = "Juice " + to_string(answerJ);
			}
			else
			{
				output = "Mile Juice " + to_string(answerM);
			}
		}

		// printf("%d %d\n", answerM, answerJ );
		printf("Case %d: %s\n", c, output.c_str());
		c++;
	}

	return 0;
}