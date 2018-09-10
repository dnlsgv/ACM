#include <iostream>
#include <string.h> //memset
#include <string>

#define imp(x) cout << x << endl;
#define impTexto(texto, variable) cout << texto << " " << variable << endl;

using namespace std;

int main(int argc, char const *argv[])
{
	int T, N, G;

	cin >> T;

	while(T--)
	{
		cin >> N;

		int prices[N + 1], weights[N + 1], acumulador;

		prices[0] = weights[0] = 0;

		for(int i = 1; i <= N; ++i)
		{
			int precio, valor;
			cin >> precio >> valor;
			prices[i] = precio;
			weights[i] = valor;
		}

		cin >> G;

		acumulador = 0;
		for(int i = 0; i < G; ++i)
		{
			int pesoMaximo;
			cin >> pesoMaximo;

			int grid[N + 1][pesoMaximo + 1];

			//impTexto("Imprimiendo para ", pesoMaximo);

			//poner en cero la matriz
			for(int i = 0; i <= N; ++i)
			{
				for(int j = 0; j <= pesoMaximo; ++j)
				{
					grid[i][j] = 0;
				}
			}
			//fin poner en cero la matriz

		    for(int i = 1; i <= N; ++i)
		    {
		        for(int j = 1; j <= pesoMaximo; ++j)
		        {
		            if(weights[i] <= j)
		            {
		                if(j - weights[i] > 0){
		                    grid[i][j] = max(grid[i - 1][j], prices[i] + grid[i - 1][j - weights[i]]);
		                }
		                else
		                {
		                    grid[i][j] = max(grid[i - 1][j], prices[i]);
		                }
		            }
		            else
		            {
		                grid[i][j] = grid[i-1][j];
		            }
		            //cout << grid[i][j] << " ";
		        }
		        //cout << endl;
		    }
    		acumulador+=grid[N][pesoMaximo];
		}
		cout << acumulador << endl;
	}
	//cout << acumulador << endl;

	return 0;
}
