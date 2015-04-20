#include<iostream>
#include<fstream>

using namespace std;

int arr[1000][1000];
int m[1000][2];
int main()
{
	int k, col, row, next_row = 0;
	ifstream in("chess.in");
	ofstream out("chess.out");
	
	in >> col;
	if (col == 1)
		out << 1 << endl << "1 1";
	else{
		for (int i(0); i < col; i++)
		{
			in >> row;
			for (int j(0); j < row; j++)
				arr[i][j] = 1;
		}
		int i = 0;
		int j = 0;
		for (k = 0; arr[i][j] == 1;)
		{
			m[k][0] = i, m[k][1] = j;
			k++;
			i++;
			j++;
		}
		out << k << endl;
		for (int i = 0; i < k; i++)
			out << m[i][0] << " " << m[i][1] << endl;
		
	}
		
	
	out.close();
	return 0;
}