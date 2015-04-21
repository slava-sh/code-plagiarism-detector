#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct edge {
    int fr,to,cs;
};
edge ed[500000];
int p,n,v,m,d,ll[400000],rr[400000];
int mar[500000],q,rrr,parent[500000],st,fn,sm[500000],rn[500000],bg[500000],o1[500000],o2[500000];
vector <pair<int,int> > edd[100001];
void prepare() {
    for (int i=1;i<=v;i++) {
        mar[i]=0;
        parent[i]=0;
        sm[i]=i;
        bg[i]=i;
        rn[i]=0;
    }
}
int findset(int x) {
    if (parent[x]==0) return x;
    parent[x]=findset(parent[x]);
    return parent[x];
}
void findfirst(int x, int y) {
    if (ed[rr[x]].cs<y-d) p=rr[x]+1;
    int l=ll[x];
    int r=rr[x];
    while (r-l>0) {
        int mid=(r+l)/2;
        if (ed[mid].cs<y-d) l=mid+1;
        else r=mid;
    }
    p=l;
}
int aabs(int x) {
    if (x<0) return -x;
    return x;
}
void un(int xx, int yy) {
    if (mar[yy]==0) return;
    yy=findset(yy);
    if (rn[xx]<rn[yy]) swap(xx,yy);
    if (rn[xx]==rn[yy]) rn[xx]++;
    parent[yy]=xx;
    sm[xx]=min(sm[xx],sm[yy]);
    bg[xx]=max(bg[xx],bg[yy]);
}
void del(int x, int y) {
    mar[y]=1;
    if (y+1<=rr[x]) un(y,y+1);
    if (y-1>=ll[x]) un(findset(y),y-1);
}
int main() {
   // freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> d;
    for (int i=1;i<=m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        edd[x].push_back(make_pair(y,z));
        edd[y].push_back(make_pair(x,z));
    }
    for (int i=1;i<=n;i++) {
        ll[i]=v+1;
        for (int j=0;j<edd[i].size();j++) {
            v++;
            ed[v]=(edge){i,edd[i][j].first,edd[i][j].second};
        }
        rr[i]=v;
    }
    cin >> q;
    for (int i=1;i<=q;i++) {
        cin >> st >> fn;
        if (st==fn) {
            cout << 1 << "\n";
            continue;
        }
        prepare();
        int sz=0;
        for (int j=ll[st];j<=rr[st];j++) {
            sz++;
            o1[sz]=j;
            o2[sz]=1;
        }
        int l=1;
        int ans=-1;
        while (l<=sz) {
            int x=o1[l];
            int y=ed[x].to;
            if (ed[x].to==fn) {
                ans=o2[l];
                break;
            }
            findfirst(y,ed[x].cs);
            while (p<=rr[y]) {
                rrr=p;
                if (mar[p]==1) {
                    p=findset(p);
                    rrr=p;
                    p=bg[p]+1;
                }
                if (p>rr[y]) break;
                if (aabs(ed[p].cs-ed[x].cs)>d) break;
                sz++;
                o1[sz]=p;
                o2[sz]=o2[l]+1;
                if (mar[p]==1) {
                    cout << "how\n";
                    exit(0);
                }
                del(y,p);
            }
            l++;
        }
        cout << ans << "\n";
    }
    return 0;
}
