#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define debug(x) cout << (#x) << " tiene el valor " << (x) << endl

int main(int argc, char const *argv[])
{
	long long T, monto, casos = 1;
	long double tax, taxMomentaneo;

	cin >> T;

	while(T--)
	{
		cin >> monto;
		tax = 0.0;

		if(monto <= 180000)
		{
			tax = 0.0;
		}
		else
		{
			monto-=180000;

			if(monto > 0)
			{
				if(monto >= 300000)
				{
					monto-=300000;
					tax+=(300000 * 0.1);
				}
				else
				{
					taxMomentaneo = monto * 0.1;
					if(taxMomentaneo < 2000)
					{
						tax+=2000;
					}
					else
					{
						tax+=taxMomentaneo;
					}
					monto = 0;
				}
				// debug(monto);
			}

			if(monto > 0)
			{
				// debug(monto);
				if(monto >= 400000)
				{
					monto-=400000;
					tax+=(400000 * 0.15);
				}
				else
				{
					taxMomentaneo = monto * 0.15;
					tax+=taxMomentaneo;
					monto = 0;
				}
			}

			if(monto > 0)
			{
				if(monto >= 300000)
				{
					monto-=300000;
					tax+=(300000 * 0.2);
				}
				else
				{
					taxMomentaneo = monto * 0.2;

					tax+=taxMomentaneo;
					monto = 0;
				}
			}

			if(monto > 0)
			{
				taxMomentaneo = monto * 0.25;
				tax+=taxMomentaneo;
			}

		}

		if(tax - int(tax) > 0.0)
		{
			tax++;
		}

		// if(tax < 2000) tax = 2000.0;

		printf("Case %lld: %ld\n", casos, long(tax) );
		casos++;
	}
	
	return 0;
}