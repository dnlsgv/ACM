/*
	DP usando el enfoque TOP-DOWN
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, t;
int sobras[10000 + 1];
int hamburguesas[10000 + 1];

int back(int tiempoActual)
{
	//Condicion DP
	if(hamburguesas[tiempoActual] != -1)
	{
		return hamburguesas[tiempoActual];
	}

	if(tiempoActual == 0)
	{
		sobras[tiempoActual] = 0;
		hamburguesas[tiempoActual] = 0;
		return 0;
	}

	if(tiempoActual < n && tiempoActual < m)
	{
		sobras[tiempoActual] = tiempoActual;
		hamburguesas[tiempoActual] = 0;
		return 0;
	}

	int izquierda, derecha, sobrasIzquierda, sobrasDerecha;

	izquierda = (tiempoActual < n ? 0 : 1 + back(tiempoActual - n));
	derecha = (tiempoActual < m ? 0 : 1 + back(tiempoActual - m));

	sobrasIzquierda = (tiempoActual < n ? t : sobras[tiempoActual - n]); 
	sobrasDerecha = (tiempoActual < m ? t : sobras[tiempoActual - m]);

	if(sobrasIzquierda < sobrasDerecha)
	{
		//printf("aqui\n");
		sobras[tiempoActual] = sobrasIzquierda;
		return hamburguesas[tiempoActual] = izquierda;
	}
	else
	{
		if(sobrasIzquierda == sobrasDerecha)
		{
			sobras[tiempoActual] = sobrasIzquierda;
			return hamburguesas[tiempoActual] = max(izquierda, derecha);
		}
		else
		{
			//printf("hamburguesas[%d] = %d\n", tiempoActual, derecha);
			sobras[tiempoActual] = sobrasDerecha;
			return hamburguesas[tiempoActual] = derecha;
		}
	}

}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> n >> m >> t)
	{
		for(int i = 0; i < 10000 + 1; ++i)
		{
			sobras[i] = hamburguesas[i] = -1;
			//hamburguesas[i] = -1;
		}

		// printf("%d %d %d\n", n, m, t );

		int resultado = back(t);
		if(sobras[t] != 0)
		{
			printf("%d %d\n", resultado, sobras[t]);
		}
		else
		{
			printf("%d\n", resultado);
		}
		// printf("%d\n", back(t) );
		// printf("%d\n", sobras[t] );
	}
	
	return 0;
}