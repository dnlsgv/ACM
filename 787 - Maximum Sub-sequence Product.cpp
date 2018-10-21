#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

class NumeroGigante
{
	private:
		string numero;
		bool positivo;

	public:
		NumeroGigante(string numero, bool positivo)
		{
			this->numero = numero;
			this->positivo = positivo;
		}

		string getNumero()
		{
			return this->numero;
		}

		void setNumero(pair<string, bool> resultado)
		{
			this->numero = resultado.first;
			this->positivo = resultado.second;
		}

		string getNumeroConSigno()
		{
			return (positivo ? "" : "-") + this->numero;
		}

		string concatenarNumero(string numero)
		{
			return this->numero + numero;
		}

		bool getSigno()
		{
			return this->positivo;
		}

		pair<string, bool> multiplicar(NumeroGigante numeroObjeto)
		{
			string numero = numeroObjeto.getNumero();
			int N, M;
			N = numero.size();
			M = this->numero.size() + 1 + numero.size();
			int matriz[N][M];
			for(int i = 0; i < N; ++i)
			{
				for(int j = 0; j < M; ++j)
				{
					matriz[i][j] = 0;
				}
			}

			int avance, acarreo, multiplicacion;
			avance = acarreo = 0;
			int fila, columna;
			for(int i = numero.size() - 1, fila = 0; i >= 0; --i, ++fila)
			{
				for(int j = this->numero.size() - 1, columna = M - 1; j >= 0; --j, --columna)
				{
					multiplicacion = int(this->numero[j] - '0') * int(numero[i] - '0') + acarreo;
					matriz[fila][columna + avance] = multiplicacion%10;
					acarreo = multiplicacion/10;
					if(j == 0 && acarreo != 0)
					{
						matriz[fila][columna + avance - 1] = acarreo;
						acarreo = 0;
					}
				}
				avance--;
			}

			string salida = "";
			int sumatoriaVertical, digito;
			acarreo = 0;

			for(int j = M - 1; j >= 0; --j)
			{
				sumatoriaVertical = 0;
				for(int i = 0; i < N; ++i)
				{
					sumatoriaVertical+=matriz[i][j];
				}
				digito = (sumatoriaVertical + acarreo)%10;
				salida+=(digito + '0');
				acarreo = (sumatoriaVertical + acarreo)/10;
			}

			reverse(salida.begin(), salida.end());
			string salidaSinCeros = "";
			bool agregar = false;

			for(int i = 0; i < salida.size(); ++i)
			{
				if(!agregar && salida[i] != '0')
				{
					agregar = true;
				}
				if(agregar)
				{
					salidaSinCeros+=salida[i];
				}
			}

			bool signo = determinarSigno(this->positivo, numeroObjeto.getSigno());
			// cout << signo << endl;
			pair<string, bool> salidaPair;

			salidaPair = make_pair(salidaSinCeros, signo);

			return salidaPair;
			//return salidaSinCeros;
		}

		bool determinarSigno(bool signoUno, bool signoDos)
		{
			// cout << signoUno << signoDos << endl;
			// + * +
			if(signoUno == true && signoDos == true)
			{
				return true;
			}
			//- * -
			if(signoUno == false && signoDos == false)
			{
				return true;
			}
			// - * +
			if(signoUno == false && signoDos == true)
			{
				return false;
			}
			//+ * -
			if(signoUno == true && signoDos == false)
			{
				return false;
			}

			return true;
		}
};

pair<string, bool> determinarMayor(NumeroGigante* maximoEncontrado, NumeroGigante* multiplicaciones)
{
	// printf("Comparando %s%s con %s%s.\n", (maximoEncontrado->getSigno() ? "" : "-"), maximoEncontrado->getNumero().c_str(), (multiplicaciones->getSigno() ? "" : "-"), multiplicaciones->getNumero().c_str() );

	if(maximoEncontrado->getNumero() == multiplicaciones->getNumero() && maximoEncontrado->getSigno() == multiplicaciones->getSigno())
	{
		return make_pair(maximoEncontrado->getNumero(), maximoEncontrado->getSigno());
	}

	if(maximoEncontrado->getSigno() == true && multiplicaciones->getSigno() == false)
	{
		return make_pair(maximoEncontrado->getNumero(), maximoEncontrado->getSigno());
	}

	if(maximoEncontrado->getSigno() == false && multiplicaciones->getSigno() == true)
	{
		return make_pair(multiplicaciones->getNumero(), multiplicaciones->getSigno());
	}

	if(maximoEncontrado->getSigno() == multiplicaciones->getSigno())
	{
		bool mayorA, mayorB;
		mayorA = mayorB = false;
		if(maximoEncontrado->getNumero().size() > multiplicaciones->getNumero().size())
		{
			mayorA = true;
		}
		else
		{
			// cout << maximoEncontrado->getNumero() << " " << multiplicaciones->getNumero() << endl;
			if(multiplicaciones->getNumero().size() > maximoEncontrado->getNumero().size())
			{
				mayorB = true;
			}
			else
			{
				//Son del mismo tam
				string numeroUno, numeroDos;
				numeroUno = maximoEncontrado->getNumero();
				numeroDos = multiplicaciones->getNumero();
				for(int i = 0; i < maximoEncontrado->getNumero().size(); ++i)
				{
					int a = int(numeroUno[i] - '0');
					int b = int(numeroDos[i] - '0');
					if(a > b)
					{
						mayorA = true;
						break;
					}
					else
					{
						if(b > a)
						{
							mayorB = true;
							break;
						}
					}
				}
			}
		}

		if(maximoEncontrado->getSigno() == true)
		{
			if(mayorA)
			{
				return make_pair(maximoEncontrado->getNumero(), maximoEncontrado->getSigno());
			}
			if(mayorB)
			{
				return make_pair(multiplicaciones->getNumero(), multiplicaciones->getSigno());				
			}
		}
		else
		{
			if(mayorA)
			{
				return make_pair(multiplicaciones->getNumero(), multiplicaciones->getSigno());								
			}
			else
			{
				return make_pair(maximoEncontrado->getNumero(), maximoEncontrado->getSigno());				
			}
		}

	}


	return make_pair("1", true);
}

int main(int argc, char const *argv[])
{
	string lineaCompleta;

	while(getline(cin, lineaCompleta))
	{
		stringstream ss(lineaCompleta);
		string numero;
		vector<NumeroGigante *> secuencia;

		while(ss >> numero)
		{
			if(numero != "-999999")
			{
				if(numero[0] == '-')
				{
					string numeroSinSigno = "";
					for(int i = 1; i < numero.size(); ++i)
					{
						numeroSinSigno+=numero[i];
					}
					secuencia.push_back(new NumeroGigante(numeroSinSigno, false));
				}
				else
				{
					secuencia.push_back(new NumeroGigante(numero, true));
				}
			}
		}

		NumeroGigante* maximoEncontrado = new NumeroGigante("1000000000000000000000", false); // Simulacion de -infinito
		NumeroGigante* multiplicaciones = new NumeroGigante("1", true);

		for(int i = 0; i < secuencia.size(); ++i)
		{
			NumeroGigante* multiplicaciones = new NumeroGigante("1", true);

			for(int j = i; j < secuencia.size(); ++j)
			{

				if(multiplicaciones->getNumero() == "0")
				{
					multiplicaciones->setNumero(make_pair("1", true));
				}
				multiplicaciones->setNumero(multiplicaciones->multiplicar(*secuencia[j]));

				if(secuencia[j]->getNumero() == "0")
				{
					if(j == 0)
					{
						//El mayor es cero
						maximoEncontrado->setNumero(make_pair("0", true));
					}
				}

				if(multiplicaciones->getNumero() == "")
				{
					multiplicaciones->setNumero(make_pair("0", true));
				}

				maximoEncontrado->setNumero(determinarMayor(maximoEncontrado, multiplicaciones));
			}
		}
		cout << (maximoEncontrado->getSigno() ? "" : "-") << maximoEncontrado->getNumero() << endl;
	}

	return 0;
}