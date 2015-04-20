#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main(){
	ifstream fin("tictactoe.in");
	ofstream fout("tictactoe.out");
	int h, w, quan=0, quan1=0;
	fin >> h >> w;
	vector < vector<char> > chess(h + 6);
	for (int i = 0; i < h + 6; i++){
		chess[i].resize(w + 6,'.');
	}
	for (int i = 2; i < h + 2; i++)
		for (int j = 2; j < w + 2; j++)
			fin >> chess[i][j];
	for (int j = 2; j < w + 2; j++){
		for (int i = 2; i < h + 2; i++){
        //..XXX..
			if (chess[i - 1][j] == 'X' && chess[i][j] == 'X' && chess[i + 1][j] == 'X'){
				if ((chess[i - 2][j] == '.' && chess[i + 2][j] == '.') && (chess[i - 3][j] == '.' || chess[i + 3][j] == '.')){
					quan+=2;
				}
			}
            //
            /*.
            .
            X
            X
            X
            .
            .*/
			if (chess[i][j-1] == 'X' && chess[i][j] == 'X' && chess[i][j+1] == 'X'){
				if ((chess[i][j-2] == '.' && chess[i][j+2] == '.') && (chess[i][j-3] == '.' || chess[i][j+3] == '.')){
					quan+=2;
				}
			}
            //diag
			if (chess[i - 1][j - 1] == 'X' && chess[i][j] == 'X' && chess[i + 1][j + 1] == 'X'){
				if ((chess[i - 2][j - 2] == '.' && chess[i + 2][j + 2] == '.') && (chess[i - 3][j - 3] == '.' || chess[i + 3][j + 3] == '.')){
					quan+=2;
				}
			}
			if (chess[i + 1][j - 1] == 'X' && chess[i][j] == 'X' && chess[i - 1][j + 1] == 'X'){
				if ((chess[i + 2][j - 2] == '.' && chess[i - 2][j + 2] == '.') && (chess[i + 3][j - 3] == '.' || chess[i - 3][j + 3] == '.')){
					quan+=2;
				}
			}
			if ((chess[i - 2][j] == '0' || chess[i + 2][j] == '0') && (chess[i - 1][j] == '0' && chess[i][j] == '0' && chess[i + 1][j] == '0')){
				quan=0;
			}
			if ((chess[i][j - 2] == '0' || chess[i][j + 2] == '0') && (chess[i][j - 1] == '0' && chess[i][j] == '0' && chess[i][j + 1] == '0')){
				quan=0;
			}
			if ((chess[i - 2][j - 2] == '0' || chess[i + 2][j + 2] == '0') && (chess[i - 1][j - 1] == '0' && chess[i][j] == '0' && chess[i + 1][j + 1] == '0')){
				quan=0;
			}
			if ((chess[i + 2][j - 2] == '0' || chess[i - 2][j + 2] == '0') && (chess[i + 1][j - 1] == '0' && chess[i][j] == '0' && chess[i - 1][j + 1] == '0')){
				quan=0;
			}



			if ((chess[i - 2][j] == 'X' || chess[i + 2][j] == 'X') && (chess[i - 1][j] == 'X' && chess[i][j] == 'X' && chess[i + 1][j] == 'X')){
				quan1++;
			}
			if ((chess[i][j - 2] == 'X' || chess[i][j + 2] == 'X') && (chess[i][j - 1] == 'X' && chess[i][j] == 'X' && chess[i][j + 1] == 'X')){
				quan1++;
			}
			if ((chess[i - 2][j - 2] == 'X' || chess[i + 2][j + 2] == 'X') && (chess[i - 1][j - 1] == 'X' && chess[i][j] == 'X' && chess[i + 1][j + 1] == 'X')){
				quan1++;
			}
			if ((chess[i + 2][j - 2] == 'X' || chess[i - 2][j + 2] == 'X') && (chess[i + 1][j - 1] == 'X' && chess[i][j] == 'X' && chess[i - 1][j + 1] == 'X')){
				quan1++;
			}
		}
		quan += (quan1) / 2;
	}
	fout << quan;
	fout.close();
}