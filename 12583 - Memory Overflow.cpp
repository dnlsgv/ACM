#include <iostream>
#include <cstdio>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	int T, n, k, reconocimientos, casos = 1;
	char nombres[500 + 1];

	cin >> T;

	while(T--)
	{
		cin >> n >> k;
		for(int i = 0; i < n; ++i)
		{
			cin >> nombres[i];
		}

		reconocimientos = 0;
		for(int i = 0; i < n; ++i)
		{
			char personaActual = nombres[i];
			for(int j = i - 1, diasTranscurridos = 0; j >= 0 && diasTranscurridos < k; --j, ++diasTranscurridos)
			{
				if(personaActual == nombres[j])
				{
					reconocimientos++;
					break;
				}
			}
		}
		
		printf("Case %d: %d\n", casos, reconocimientos);
		casos++;
	}
	
	return 0;
}