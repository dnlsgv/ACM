#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <vector>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	string palabra;
	map<string, string> codigoMorse;

    codigoMorse[".-"] = "A";
    codigoMorse["-..."] = "B";
    codigoMorse["-.-."] = "C";
    codigoMorse["-.."] = "D";
    codigoMorse["."] = "E";
    codigoMorse["..-."] = "F";
    codigoMorse["--."] = "G";
    codigoMorse["...."] = "H";
    codigoMorse[".."] = "I";
    codigoMorse[".---"] = "J";
    codigoMorse["-.-"] = "K";
    codigoMorse[".-.."] = "L";
    codigoMorse["--"] = "M";
    codigoMorse["-."] = "N"; 
    codigoMorse["---"] = "O";
    codigoMorse[".--."] = "P";
    codigoMorse["--.-"] = "Q";
    codigoMorse[".-."] = "R";
    codigoMorse["..."] = "S";
    codigoMorse["-"] = "T";
    codigoMorse["..-"] = "U";
    codigoMorse["...-"] = "V";
    codigoMorse[".--"] = "W";
    codigoMorse["-..-"] = "X";
    codigoMorse["-.--"] = "Y";
    codigoMorse["--.."] = "Z";
    codigoMorse["-----"] = "0";
    codigoMorse[".----"] = "1";
    codigoMorse["..---"] = "2";
    codigoMorse["...--"] = "3";
    codigoMorse["....-"] = "4";
    codigoMorse["....."] = "5";
    codigoMorse["-...."] = "6";
    codigoMorse["--..."] = "7";
    codigoMorse["---.."] = "8";
    codigoMorse["----."] = "9";

    codigoMorse[".-.-.-"] = ".";
    codigoMorse["--..--"] = ",";
    codigoMorse["..--.."] = "?";
    codigoMorse[".----."] = "\'";
    codigoMorse["-.-.--"] = "!";
    codigoMorse["-..-."] = "/";
    //codigoMorse["-.--."] = "(";
    codigoMorse["-.--."] = "(";
    codigoMorse["-.--.-"] = ")";
	codigoMorse[".-..."] = "&";
    codigoMorse["---..."] = ":";
    codigoMorse["-.-.-."] = ";";
    codigoMorse["-...-"] = "=";
    codigoMorse[".-.-."] = "+";
    codigoMorse["-....-"] = "-";
    codigoMorse["..--.-"] = "_";
    codigoMorse[".-..-."] = "\"";
    codigoMorse[".--.-."] = "@";

	// codigoMorse["1"] = '';
	// codigoMorse["22"] = ' ';

	int T, casos = 1;
	string lineaCompleta;

	cin >> T;

	getline(cin, lineaCompleta); //Dejar apuntando hacia la nueva linea

	while(T--)
	{

		getline(cin, lineaCompleta);

		//Preprocesar linea completa
		for(int i = 0; i < lineaCompleta.size(); ++i)
		{
			if(lineaCompleta[i] == ' ')
			{
				if(lineaCompleta[i + 1] == ' ')
				{
					lineaCompleta[i] = '2';
					lineaCompleta[i + 1] = '2';
					++i;
				}
				else
				{
					lineaCompleta[i] = '1';
				}
			}
		}

		vector<string> palabrasConsultadas;
		string consulta;
		for(int i = 0; i < lineaCompleta.size(); ++i)
		{
			if(lineaCompleta[i] != '.' && lineaCompleta[i] != '-')
			{
				palabrasConsultadas.push_back(consulta);
				consulta = "";
				if(lineaCompleta[i] == '1')
				{
					palabrasConsultadas.push_back("0");
				}
				else
				{
					palabrasConsultadas.push_back("1");
					i+=1;
				}
			}
			else
			{
				consulta+=lineaCompleta[i];
			}
		}

		if(consulta.size() > 0)
		{
			palabrasConsultadas.push_back(consulta);
		}

		printf("Message #%d\n", casos);
		for(string cadenaConsultada : palabrasConsultadas)
		{
			if(cadenaConsultada == "1")
			{
				cout << " ";
			}
			else
			{
				if(cadenaConsultada == "0")
				{
					cout << "";
				}
				else
				{
					cout << codigoMorse[cadenaConsultada];
				}
			}
		}

		cout << endl;
		if(T != 0)
		{
			cout << endl;
		}

		casos++;
	}

	return 0;
}