#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Board{
    int s,a,b;
    Board (int x, int y, int z) {s = x; a = y; b = z;}
    Board() {}
};

double EPS = 1e-9;
const int MAX = 105, L = 100000, H = 100, INF = 1e9;
int H1, H2, N, best = 0;
double m,b;
bool tvis[MAX], bvis[MAX];
Board top[MAX]; int tsize;
Board bot[MAX]; int bsize;
vector<int> Eloc;

int checkbot (double a){
    for(int i=0; i<bsize; i++){
	if (!bvis[i] and bot[i].a <= a and a <= bot[i].b){
	    bvis[i] = true;
	    return bot[i].s;
	}
    }
    return -1;
}

int checktop (double a){
    for(int i=0; i<tsize; i++){
	if (!tvis[i] and top[i].a <= a and a <= top[i].b){
	    tvis[i] = true;
	    return top[i].s;
	}
    }
    return -1;
}

int go (int eh){
    m =(double)(eh - H1) / L, b = H1;
    int res = 0;
    memset (bvis, 0, sizeof (bvis));
    memset (tvis, 0, sizeof (tvis));
    vector<int> deb;
    if (abs (m) < EPS) return 0;
    for (int y=-10000; y<=10000; y += 100){
	double xint = (double)(y - b) / m;
	if (xint < 0 or xint > L) continue;

	int cur;
	if ( (y/100 + 100000) % 2 == 0){
	    //bot
	    cur = checkbot(xint);
	}else{
	    //top
	    cur = checktop (xint);
	}
	if (cur == -1){
	    return -INF;
	}
	res += cur;

	deb.push_back(cur);
    }
    /*
    for(int i=0; i<deb.size(); i++){
	cout << deb[i] << " ";
    }
    cout << endl << "\t" <<  res << endl;*/
    return res;
}

int main(){
    cin >> H1 >> H2 >>  N;
    tsize = 0, bsize = 0;
    for(int i=0; i<N; i++){
	int s,a,b; string c;
	cin >> s >> c >> a >> b;
	if (c[0] == 'T'){
	    top[tsize] = Board (s,a,b);
	    tsize ++;
	}else{
	    bot[bsize] = Board (s,a,b);
	    bsize ++;
	}
    }

    int half = (N + 1) / 2;
    for(int i=-half; i<=half; i++){
	Eloc.push_back (H2 + i * 200);
	Eloc.push_back(200 - H2 + i * 200);
    }
    sort (Eloc.begin(), Eloc.end());
    for(int i=0; i<Eloc.size(); i++){
	int cur = go (Eloc[i]);
	best = max (best, cur);
    }
    cout << best << endl;
}	
