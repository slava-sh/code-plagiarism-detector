#include<iostream>
#include<fstream>

using namespace std;

int arr[1000][1000];
int m[1000][2];
int main()
{
	int k, col, row, max_row = 0;
	ifstream in("chess.in");
	ofstream out("chess.out");
	
	in >> col;
	if (col == 1)
		out << 1 << endl << "1 1";
	else{
		for (int i(0); i < col; i++)
		{
			in >> row;
			if (row > max_row) max_row = row;
			for (int j(0); j < row; j++)
				arr[i][j] = 1;
		}
		int i = col - 1;
		int j = 0;
		for (k = 0; i > -1;)
		{
			if (arr[i][j + 1] != 1)
			{
				if ((i == 0) && (j == max_row - 1))
					m[k][0] = 1, m[k][1] = max_row, k++;
				i--;
			}
			else
			{
				m[k][0] = i + 1, m[k][1] = j + 1;
				i--;
				j++;
				k++;
			}
		}
		if (k == 0)
			out << 1 << endl << "1 1";
		else{
			out << k << endl;
			for (i = 0; i < k; i++)
				out << m[i][0] << " " << m[i][1] << endl;
		}
	}
	out.close();
	return 0;
}