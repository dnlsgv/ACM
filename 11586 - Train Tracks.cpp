#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long ll;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(void)
{
	int T, male, female;
	string l;

	cin >> T;
	getline(cin, l);

	while(T--)
	{
		getline(cin, l);
		male = female = 0;
		for(int i = 0; i < l.size(); ++i)
		{
			if(l[i] == 'M')
			{
				male++;
			}
			if(l[i] == 'F')
			{
				female++;
			}
		}
		if(male == 1 and female == 1)
		{
			male = 1;
			female = 2;
		}
		cout << (male == female ? "LOOP" : "NO LOOP") << endl;
	}
	
	return 0;
}