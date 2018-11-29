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
	int T;
	string S;

	cin >> T;

	while(T--)
	{
		cin >> S;

		if((S == "1" or S == "4") or S == "78")
		{
			cout << "+";
		}
		else
		{
			if(S[S.size() - 1] == '5' and S[S.size() - 2] == '3')
			{
				cout << "-";
			}
			else
			{
				if(S[S.size() - 1] == '4' and S[0] == '9')
				{
					cout << "*";
				}
				else
				{
					cout << "?";
				}
			}
		}
		cout << endl;
	}
	return 0;
}