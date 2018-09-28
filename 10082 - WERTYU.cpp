#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	string lineaCompleta;
	vector<string> teclado;

	teclado.push_back("`1234567890-=");
	teclado.push_back("QWERTYUIOP[]");
	teclado.push_back("ASDFGHJKL;'");
	teclado.push_back("ZXCVBNM,./");

	// cout << '\\' << endl;

	while(getline(cin, lineaCompleta))
	{
		for(int i = 0; i < lineaCompleta.size(); ++i)
		{
			if(lineaCompleta[i] == ' ')
			{
				cout << " ";
				continue;
			}

			if(lineaCompleta[i] == '\\')
			{
				cout << "]" << endl;
				continue;
			}

			for(int j = 0; j < 4; ++j)
			{
				for(int k = 0; k < teclado[j].size(); ++k)
				{
					if(teclado[j][k] == lineaCompleta[i])
					{
						cout << teclado[j][k - 1];
						break;
					}
				}
			}
		}
		cout << endl;
	}

	return 0;
}