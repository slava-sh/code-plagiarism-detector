#include <iostream>

using namespace std;

int const Max = 111;
int n, m;
int con[Max], k[Max], reg[Max][Max];

void Pr(char s[15], int l1, int l2)
{
	cout << "+";
	for (int i = 0; i < l1; i++)
		cout << s[i];
	cout << "(";
	for (int i = l1; i < l1 + l2; i++)
		cout << s[i];
	cout << ")";
	int len = 11 - (l1 + l2);
	if (len == 3)
	{
		for (int i = l1 + l2; i < 11; i++)
			cout << s[i];
	}
	if (len == 4)
	{
		cout << s[l1 + l2] << s[l1 + l2 + 1] << '-' << s[l1 + l2 + 2] << s[l1 + l2 + 3]; 
	}
	if (len == 5)
	{
		cout << s[l1 + l2] << s[l1 + l2 + 1] << s[l1 + l2 + 2] << '-' << s[l1 + l2 + 3] << s[l1 + l2 + 4];
	}
	if (len == 6)
	{
		cout << s[l1 + l2] << s[l1 + l2 + 1] << '-' << s[l1 + l2 + 2] << s[l1 + l2 + 3] << '-' << s[l1 + l2 + 4] << s[l1 + l2 + 5]; 
	}
	if (len == 7)
	{
		cout << s[l1 + l2] << s[l1 + l2 + 1] << s[l1 + l2 + 2] << '-' << s[l1 + l2 + 3] << s[l1 + l2 + 4] << '-' << s[l1 + l2 + 5] << s[l1 + l2 + 6];
	}
	cout << endl;
}

int main()
{
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> con[i] >> k[i];
		for (int j = 1; j <= k[i]; j++)
			cin >> reg[i][j];
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		bool OK;
		OK = false;
		char num[15];
		cin >> num;
		if (num[0] == '0')
		{
			cout << "Incorrect" << endl;
			continue;
		}
		int n1, n2, n3;
		n1 = (num[0] - '0') * 100 + (num[1] - '0') * 10 + (num[2] - '0');
		n2 = (num[0] - '0') * 10 + (num[1] - '0');
		n3 = (num[0] - '0');
		for (int j = 1; j <= n; j++)
		{
			int s1, s2, s3;
			if (con[j] == n1)
			{
				s3 = (num[3] - '0') * 100 + (num[4] - '0') * 10 + (num[5] - '0');
				s2 = s3 * 10 + (num[6] - '0');
				s1 = s2 * 10 + (num[7] - '0');
				if (num[3] != '0')
				{
					for (int p = 1; p <= k[j]; p++)
					{
						if (s1 == reg[j][p])
						{
							if (num[8] != '0')
							{
								Pr(num, 3, 5);
								OK = true;
							}
						}
						if (s2 == reg[j][p])
						{
							if (num[7] != '0')
							{
								Pr(num, 3, 4);
								OK = true;
							}
						}
						if (s3 == reg[j][p])
						{
							if (num[6] != '0')
							{
								Pr(num, 3, 3);
								OK = true;
							}
						}
					}
				}
			}
			if (con[j] == n2)
			{
				s3 = (num[2] - '0') * 100 + (num[3] - '0') * 10 + (num[4] - '0');
				s2 = s3 * 10 + (num[5] - '0');
				s1 = s2 * 10 + (num[6] - '0');
				if (num[2] != '0')
				{
					for (int p = 1; p <= k[j]; p++)
					{
						if (s1 == reg[j][p])
						{
							if (num[7] != '0')
							{
								Pr(num, 2, 5);
								OK = true;
							}
						}
						if (s2 == reg[j][p])
						{
							if (num[6] != '0')
							{
								Pr(num, 2, 4);
								OK = true;
							}
						}
						if (s3 == reg[j][p])
						{
							if (num[5] != '0')
							{
								Pr(num, 2, 3);
								OK = true;
							}
						}
					}
				}
			}
			if (con[j] == n3)
			{
				s3 = (num[1] - '0') * 100 + (num[2] - '0') * 10 + (num[3] - '0');
				s2 = s3 * 10 + (num[4] - '0');
				s1 = s2 * 10 + (num[5] - '0');
				if (num[1] != '0')
				{
					for (int p = 1; p <= k[j]; p++)
					{
						if (s1 == reg[j][p])
						{
							if (num[6] != '0')
							{
								Pr(num, 1, 5);
								OK = true;
							}
						}
						if (s2 == reg[j][p])
						{
							if (num[5] != '0')
							{
								Pr(num, 1, 4);
								OK = true;
							}
						}
						if (s3 == reg[j][p])
						{
							if (num[4] != '0')
							{
								Pr(num, 1, 3);
								OK = true;
							}
						}
					}
				}
			}
		}
		if (!OK)
			cout << "Incorrect" << endl;
	}
	return 0;
}