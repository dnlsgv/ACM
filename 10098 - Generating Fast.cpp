#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int T;

	cin >> T;

	while(T--)
	{
		string palabra;

		cin >> palabra;

		sort(palabra.begin(),palabra.end());

		do
		{
			cout << palabra << endl;
		}while(next_permutation(palabra.begin(), palabra.end()));

		// debug(palabra);
		cout << endl;
	}


	return 0;
}