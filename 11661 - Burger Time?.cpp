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
	int L, answer;
	bool solution;

	while(scanf("%d", &L))
	{
		answer = -1;
		solution = false;
		vi drugstores, restaurants;
		if(L == 0)
		{
			break;
		}

		char aux;
		for(int i = 0; i < L; ++i)
		{
			cin >> aux;
			if(aux == 'R')
			{
				restaurants.push_back(i);
			}
			else
			{
				if(aux == 'D')
				{
					drugstores.push_back(i);
				}
				else
				{
					if(aux != '.')
					{
						answer = 0;
						solution = true;
					}
				}
			}
		}

		if(solution)
		{
			cout << 0 << endl;
		}
		else
		{
			//la proxima minima distancia puede ser 1
			answer = 1 << 30;
			for(int i = 0; i < restaurants.size(); ++i)
			{
				for(int j = 0; j < drugstores.size(); ++j)
				{
					answer = min(answer, abs(restaurants[i] - drugstores[j]));
				}
			}
			cout << answer << endl;
		}
	}

	return 0;
}