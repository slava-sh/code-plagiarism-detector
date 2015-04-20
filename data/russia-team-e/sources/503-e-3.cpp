#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct city {
    string pre;
    string cod[101];
    int ncod;
};

city arr[101];
string s,ss,sss,now,now1,now2;
int n,m;
bool flag,superflag;

void Format(string sss) {
    if (sss.length() == 3) cout << sss;
    if (sss.length() == 4) {
        for (int i=0; i<=1; i++) cout << sss[i];
        cout << "-";
        for (int i=2; i<=3; i++) cout << sss[i];
    }
    if (sss.length() == 5) {
        for (int i=0; i<=2; i++) cout << sss[i];
        cout << "-";
        for (int i=3; i<=4; i++) cout << sss[i];
    }
    if (sss.length() == 6) {
        for (int i=0; i<=1; i++) cout << sss[i];
        cout << "-";
        for (int i=2; i<=3; i++) cout << sss[i];
        cout << "-";
        for (int i=4; i<=5; i++) cout << sss[i];
    }
    if (sss.length() == 7) {
        for (int i=0; i<=2; i++) cout << sss[i];
        cout << "-";
        for (int i=3; i<=4; i++) cout << sss[i];
        cout << "-";
        for (int i=5; i<=6; i++) cout << sss[i];
    }
}

bool Obrab() {
    superflag = false;
    for (int i=0; i<n; i++) {
        s = ss;
        flag = false;
        now="+";
        for (int j=0; j<arr[i].pre.length(); j++) if (arr[i].pre[j] != ss[j]) flag=true;
        if ((!flag) && (s[0]!='0')) {
            now1 = now;
            for (int g=0; g<arr[i].pre.length(); g++) now1+=s[g];
            s.erase(0,arr[i].pre.length());
            for (int j=0; j<arr[i].ncod; j++) {
                flag = false;
                sss = s;
                for (int z=0; z<arr[i].cod[j].length(); z++) if (arr[i].cod[j][z] != sss[z]) flag=true;
                if ((!flag) && (sss[0]!='0')) {
                    now2 = now1;
                    now2+="(";
                    for (int g=0; g<arr[i].cod[j].length(); g++) now2+=arr[i].cod[j][g];
                    sss.erase(0,arr[i].cod[j].length());
                    now2+=")";
                    if ((sss[0] != '0') && (sss.length()>=3) && (sss.length()<=7))  {
                        cout << now2;
                        Format(sss);
                        cout << endl;
                        superflag = true;
                    }
                }
            }
        }
    }
    return superflag;
}

int main()
{
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w",stdout);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i].pre >> arr[i].ncod;
        for (int j=0; j<arr[i].ncod; j++) cin >> arr[i].cod[j];
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> ss;
        if (!Obrab()) cout << "Incorrect" << endl;
    }
    return 0;
}
