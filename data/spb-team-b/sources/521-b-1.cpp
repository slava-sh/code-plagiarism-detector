#include<iostream>
#include<fstream>

using namespace std;

int arr[1000][1000];
int m[1000][2];
int main()
{
	int k, col, row;
	ifstream in("chess.in");
	ofstream out("chess.out");
	
	in >> col;
	for (int i(0); i < col; i++)
	{
		in >> row;
		for (int j(0); j < row; j++)
			arr[i][j] = 1;
	}
	int i = col - 1;
	int j = 0;
	for (k = 0;i > -1;)
	{
		if (arr[i][j + 1] != 1)
			i--;
		else 
		{
			m[k][0] = i+1, m[k][1] = j+1;
			i--;
			j++;
			k++;
		}
	}

	out << k << endl;
	for (i = 0; i < k; i++)
		out << m[i][0] << " " << m[i][1] << endl;
	out.close();
	return 0;
}