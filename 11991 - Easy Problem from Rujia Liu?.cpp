#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m, k, v;

	while(cin >> n >> m)
	{
		map<int, vector<int> > grafoMapeado;

		int numero;
		for(int i = 0; i < n; ++i)
		{
			cin >> numero;
			grafoMapeado[numero].push_back(i);
		}

		for(int i = 0; i < m; ++i)
		{
			cin >> k >> v;

			if(grafoMapeado[v].size() < k)
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", grafoMapeado[v][k - 1] + 1);
			}
		}
	}

	return 0;
}