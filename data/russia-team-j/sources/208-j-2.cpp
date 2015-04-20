#include <string>
#include <queue>
#include <fstream>
using namespace std;

string maps[500][500], temp="", res="", temp2 = "";
char map[500][500];
bool mapb[500][500];
int mapp[500][500][2];
int w, h, n, c = 0, xnn, ynn, xxx, yyy;
queue<int> ox, oy, ln, emp2;
queue<string> ms, emp1;
char t;
ifstream cin("numbers.in");
ofstream cout("numbers.out");

int main()
{
	

	cin >> w >> h >> n;
	
	for (int j = 0; j < h; j++) 
		for (int i = 0; i < w; i++) {
			cin >> t;
			map[i][j] = t;
			if (t == 'V') {
				map[i][j]='A';xnn = i; ynn = j;
			}
		}



			if (xnn - 1 >= 0) {
				mapb[xnn-1][ynn] = true;
				ox.push(xnn - 1);
				oy.push(ynn);
				ms.push("W");
			}
			if (ynn - 1 >= 0) {
				mapb[xnn][ynn-1] = true;
				ox.push(xnn);
				oy.push(ynn - 1);
				ms.push("N");
			}
			if (xnn + 1 < w) {
				mapb[xnn+1][ynn] = true;
				ox.push(xnn + 1);
				oy.push(ynn);
				ms.push("E");
			}
			if (ynn + 1 < h) {
				mapb[xnn][ynn+1] = true;
				ox.push(xnn);
				oy.push(ynn + 1);
				ms.push("S");
			}

			//searching first

		while (!ox.empty()) {

			temp = ms.front();
			ms.pop();
			xnn = ox.front();
			ox.pop();
			ynn = oy.front();
			oy.pop();

			if (map[xnn][ynn] == 'T') {
				res+=temp;
				n--; break;
			}

		
			if (xnn - 1 >= 0 && !mapb[xnn-1][ynn]) {
				mapb[xnn-1][ynn] = true;
				ox.push(xnn - 1);
				oy.push(ynn);
				ms.push(temp + "W");
			}
			if (ynn - 1 >= 0 && !mapb[xnn][ynn-1]) {
				mapb[xnn][ynn-1] = true;
				ox.push(xnn);
				oy.push(ynn - 1);
				ms.push(temp + "N");
			}
			if (xnn + 1 < w && !mapb[xnn+1][ynn]) {
				mapb[xnn+1][ynn] = true;
				ox.push(xnn + 1);
				oy.push(ynn);
				ms.push(temp + "E");
			}
			if (ynn + 1 < h && !mapb[xnn][ynn+1]) {
				mapb[xnn][ynn+1] = true;
				ox.push(xnn);
				oy.push(ynn + 1);
				ms.push(temp + "S");
			}
		}

		int xx = xnn, yy = ynn;
		xxx = xnn;
		yyy = ynn;

		while (maps[xx][yy]=="") {

		ox = emp2;
		oy = emp2;
		ms = emp1;
			

		if (xnn - 1 >= 0) {
				ox.push(xnn - 1);
				oy.push(ynn);
				ms.push("W");
			}
			if (ynn - 1 >= 0) {
				ox.push(xnn);
				oy.push(ynn - 1);
				ms.push("N");
			}
			if (xnn + 1 < w) {
				ox.push(xnn + 1);
				oy.push(ynn);
				ms.push("E");
			}
			if (ynn + 1 < h) {
				ox.push(xnn);
				oy.push(ynn + 1);
				ms.push("S");
			}

			//searching second and other

			temp = "";

		while (!ox.empty()) {

			temp = ms.front();
			ms.pop();
			xnn = ox.front();
			ox.pop();
			ynn = oy.front();
			oy.pop();

			if (map[xnn][ynn] == 'T') {
				maps[xx][yy] = temp;
				mapp[xx][yy][0] = xnn;
				mapp[xx][yy][1] = ynn;
				xx=xnn;
				yy=ynn;
				break;
			}


			if (xnn - 1 >= 0) {
				ox.push(xnn - 1);
				oy.push(ynn);
				ms.push(temp + "W");
			}
			if (ynn - 1 >= 0) {
				ox.push(xnn);
				oy.push(ynn - 1);
				ms.push(temp + "N");
			}
			if (xnn + 1 < w) {
				ox.push(xnn + 1);
				oy.push(ynn);
				ms.push(temp + "E");
			}
			if (ynn + 1 < h) {
				ox.push(xnn);
				oy.push(ynn + 1);
				ms.push(temp + "S");
			}
			

		}

		}

		cout << res;

		for (int i = n; i>0; i--) {
			cout << maps[xxx][yyy];
			xnn = xxx;
			ynn = yyy;
			xxx = mapp[xnn][ynn][0];
			yyy = mapp[xnn][ynn][1];
			}
	

	return 0;
}