#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define mp make_pair
#define ll long long
#define mod 1000000007

static vector <char> vc;

int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "-w", stdout);
	vc.push_back('U');
	vc.push_back('L');
	vc.push_back('D');
	vc.push_back('R');
	int cu = 0, a = 1, b = 1, c = 0, x = 0, y = 0, ti = 0;
	char ch = 'N';
	while (ch == 'N'){
            ++ti;
        if (b == 0){
            ++c;
            if (c == 3 && ti > 50 * 50)
                break;
            if (c == 4){
                ++a;
                c = 0;
            }
            else if (c == 2)
                ++a;
            b = a;
        }
        --b;
        cout << vc[c] << endl;
        if (c == 0)
            ++y;
        else if (c == 1)
            --x;
        else if (c == 2)
            --y;
        else
            --x;
        cin >> ch;
	}
	x = y = 0;
        while (x > 0){
            --x;
            cout << "L" << endl;
            cin >> ch;
            if (ch != 'N')
                return 0;
        }
        while (y > 0){
            --y;
            cout << "D" << endl;
            cin >> ch;
            if (ch != 'N')
                return 0;
        }
        while (x < 0){
            ++x;
            cout << "R" << endl;
            cin >> ch;
            if (ch != 'N')
                return 0;
        }
        while (y < 0){
            ++y;
            cout << "U" << endl;
            cin >> ch;
            if (ch != 'N')
                return 0;
        }
	for (int i = 1; ch == 'N'; ++i){
        while (x < i * 45){
            ++x;
            cout << "R" << endl;
            cin >> ch;
            if (ch != 'N')
                return 0;
        }
        for (int j = 0; j < 47; ++j){
            for (int k = 0; k < 47; ++k)
                if ((j & 1) == 0){
                    cout << "R" << endl;
                    ++x;
                    cin >> ch;
                    if (ch != 'N')
                        return 0;
                }
                else{
                    cout << "L" << endl;
                    --x;
                    cin >> ch;
                    if (ch != 'N')
                        return 0;
                }
            ++y;
            cout << 'U' << endl;
            cin >> ch;
            if (ch != 'N')
                return 0;
        }
        while (x > 0){
            --x;
            cout << "L" << endl;
            cin >> ch;
            if (ch != 'N')
                return 0;
        }
        while (y > 0){
            --y;
            cout << "D" << endl;
            cin >> ch;
            if (ch != 'N')
                return 0;
        }
        while (y < i * 45){
            ++y;
            cout << "U" << endl;
            cin >> ch;
            if (ch != 'N')
                return 0;
        }
        for (int j = 0; j < 47; ++j){
            for (int k = 0; k < 47; ++k)
                if ((j & 1) == 0){
                    cout << "R" << endl;
                    ++x;
                    cin >> ch;
                    if (ch != 'N')
                        return 0;
                }
                else{
                    cout << "L" << endl;
                    --x;
                    cin >> ch;
                    if (ch != 'N')
                        return 0;
                }
            ++y;
            cout << 'U' << endl;
            cin >> ch;
            if (ch != 'N')
                return 0;
        }
        while (x > 0){
            --x;
            cout << "L" << endl;
            cin >> ch;
            if (ch != 'N')
                return 0;
        }
        while (y > 0){
            --y;
            cout << "D" << endl;
            cin >> ch;
            if (ch != 'N')
                return 0;
        }
	}
	//system("pause");
	return 0;
}
