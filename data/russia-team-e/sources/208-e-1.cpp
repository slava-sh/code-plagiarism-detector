#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

long n,m,k;
string s,c,t,country="",reg="",numb="",temp;
map<string, bool> op, co;

ifstream cinn("numbers.in");
ofstream coutn("numbers.out");

int main()
{
	
	cinn >> n;

	for (long i = 0; i < n; i++) {
		cinn >> c >> k;
		co[c]=true;
	
	for (long j=0; j<k;j++) {
		cinn >> t;
		op[c+t] = true;
	}

	}

	cinn >> m;

	short work;

	for (int i = 0; i<m; i++) {

		work = 0;
		temp = "";
		country="",reg="",numb="";

		cinn >> s;

		for (int j = 0; j<11; j++) {

			temp+=s[j];

			if (temp.length() == 1 && temp == "0") {coutn << "Incorrect" << endl; break;}

			if (work == 0) {
				if (temp.length()>3) {coutn << "Incorrect" << endl; break;}
				if (co[temp]) {work++; country=temp; temp="";continue;} else {continue;}
			}
			if (work == 1) {
				if (temp.length()>5) {coutn << "Incorrect" << endl; break;}
				if (op[country+temp]) {work++; reg=temp; temp="";continue;} else {continue;}
			}

			

			if (work == 2 && j == 10) {
				coutn << "+" << country << "(" << reg << ")";
				if (temp.length() == 7) {
					temp = temp.substr(0,3) + "-" + temp.substr(3,2) + "-" + temp.substr(5,2);
				}
				if (temp.length() == 6) {
					temp = temp.substr(0,2) + "-" + temp.substr(2,2) + "-" + temp.substr(4,2);
				}
				if (temp.length() == 5) {
					temp = temp.substr(0,3) + "-" + temp.substr(3,2);
				}
				if (temp.length() == 4) {
					temp = temp.substr(0,2) + "-" + temp.substr(2,2);
				}
				coutn << temp << endl;
		}
	}
	}
	
	return 0;
}