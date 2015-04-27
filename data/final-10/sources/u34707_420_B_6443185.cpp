#include <iostream>
using namespace std;
int n, m, om[100100], sol, nrexista, lastiesit;
char op[100100];
bool posibil[100100], anterior[100100], intrat[100100], exista[100100];

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, poz = 0;
	cin >> n >> m;
	for(i = 1; i <= m; ++i)
		cin >> op[i] >> om[i];
	for(i = 1; i <= n; ++i)
		posibil[i] = true;
	for(i = 1; i <= m; ++i)
	{
		if(op[i] == '-' && !intrat[om[i]])
		{
			anterior[om[i]] = true;
			poz = i;
		}
		if(op[i] == '+')
			intrat[om[i]] = true;
	}
	for(i = 1; i < poz; ++i)
	{
		if(op[i] == '+' && !anterior[om[i]])
			posibil[om[i]] = false;
	}
	for(i = 1; i <= n; ++i)
	{
		exista[i] = anterior[i];
		if(exista[i])
			nrexista++;
	}
	if(nrexista > 0)
	{
		for(i = 1; i <= n; ++i)
			if(!anterior[i] && intrat[i])
				posibil[i] = false;
	}
	else
	{
		i = 1;
		while(i <= m && op[i] != '+')
			i++;
		poz = i;
		for(i = 1; i <= n; ++i)
			if(i != om[poz] && intrat[i])
				posibil[i] = false;
	}
	for(i = 1; i <= m; ++i)
	{
		if(op[i] == '+')
		{
			exista[om[i]] = true;
			nrexista++;
			if(nrexista == 1)
			{
				if(lastiesit == om[i])
					lastiesit = 0;
				posibil[lastiesit] = false;
			}
		}
		else
		{
			exista[om[i]] = false;
			nrexista--;
			if(nrexista == 0)
				lastiesit = om[i];
			else
				posibil[om[i]] = false;
		}
	}
	for(i = 1; i <= n; ++i)
		if(posibil[i])
			sol++;
	cout << sol << "\n";
	for(i = 1; i <= n; ++i)
		if(posibil[i])
			cout << i << ' ';
	cout << "\n";
	return 0;
}
