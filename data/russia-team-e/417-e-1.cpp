#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

string T;

string magic (int a,int b) {
	int q = 0;
	if (a>9) q++;
	if (a>99) q++;
	if (b>999) q++;
	if (b>9999) q++;
	if (b>99999) q++;
	string O="";
	switch (11-q) {
	case 3:
		O=T[8]+T[9]+T[10];
		break;
	case 4:
		O=T[5+2]+T[6+2]+'-'+T[7+2]+T[8+2];
		break;
	case 5:
		O=T[4+2]+T[5+2]+T[6+2]+'-'+T[7+2]+T[8+2];
		break;
	case 6:
		O=T[3+2]+T[4+2]+T[5+2]+'-'+T[6+2]+T[7+2]+T[8+2];
		break;
	case 7:
		O=T[2+2]+T[3+2]+T[4+2]+'-'+T[5+2]+T[6+2]+'-'+T[7+2]+T[8+2];
		break;
	}
	return O;
}

int main()
{
	int goss;
	ifstream inf ("numbers.in");
	inf>>goss;
	//vector < vector <int> > mass;
	//mass.resize(goss);
	//for (int i=0;i<goss;i++)
	//{
	//	int k,c;
	//	inf>>k>>c;
	//	mass[i].resize(c+1);
	//	inf>>mass[i][0];
	//	for (int j=1;j<=c;j++)
	//		inf>>mass[i][j];
	//}
	map <int, map <int,bool> > mass;
	for (int i=0;i<goss;i++)
	{
		int c,k;
		inf>>k>>c;
		for (int j=0;j<c;j++)
		{
			int t;
			inf>>t;
			mass[k][t]=true;
		}
	}
	int N;
	inf>>N;
	ofstream ouf ("numbers.out");
	for (int i=0;i<N;i++)
	{
		bool flag = false, f2 =false;
		inf>>T;
		int a[3],b[9],j,ans[2];
		a[0] = T[0]-'0';
		a[1] = (T[0]-'0')*10+(T[1]-'0');
		a[2] = (T[0]-'0')*100+(T[1]-'0')*10+(T[2]-'0');
		for (j=0;j<3;j++) {
			b[0+3*j] = ((T[1+j]-'0')*10+T[j+2]-'0')*10+T[3+j]-'0';
			b[1+3*j] = (((T[1+j]-'0')*10+T[2+j]-'0')*10+T[3+j]-'0')*10 + T[4+j] - '0';
			b[2+3*j] = ((((T[1+j]-'0')*10+T[2+j]-'0')*10+T[3+j]-'0')*10 + T[4+j] - '0')*10 + T[5+j] - '0';
		}
		for (j=0;j<9;j++) {
			try
			{
				flag = mass[a[(int)(j/3)]][b[j]];
				if (flag) {
					ans[0] = a[(int)(j/3)];
					ans[1] = b[j];
					f2 = true;
				}
			}
			catch (...) {
			}
		}
		if (f2) {
			ouf<<'+'<<ans[0]<<'('<<ans[1]<<')'<<magic(ans[0],ans[1])<<'\n';
		}
		else {
			ouf<<"Incorrect\n";
		}
	}
	ouf.close();
	return 0;
}