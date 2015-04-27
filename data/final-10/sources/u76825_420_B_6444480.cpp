#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int id[100009],ans[100009];
char s[100009];
bool vis[100009],vib[100009];

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int i,j,k;
        set<int> st,sb;
        st.clear();
        sb.clear();
        memset(vis,false,sizeof(vis));
        memset(vib,false,sizeof(vib));
        for(i=1;i<=n;i++) st.insert(i);
        for(i=0;i<m;i++)
        {
            cin>>s[i]>>id[i];
            if(s[i]=='+')
            {
                vib[id[i]]=true;
                if(!vis[id[i]]) st.erase(id[i]);
            }
            if(s[i]=='-')
            {
                vis[id[i]]=true;
                if(!vib[id[i]] && sb.count(id[i])==0) sb.insert(id[i]);
            }
        }
        int all=st.size();
        int ab=sb.size();
        bool fst=1,fsb=1;
        k=0;
        if(ab==0)
        {
            //ab++;
            sb.insert(id[0]);
        }
        for(i=0;i<m;i++)
        {
            if(s[i]=='-')
            {
                all--;
                ab--;
                if(all>0 && st.count(id[i])) st.erase(id[i]);
                if(ab>0 && sb.count(id[i])) sb.erase(id[i]);
            }
            if(s[i]=='+')
            {
                if(all==0)
                {
                    if(st.count(id[i]))
                    {
                        st.clear();
                        st.insert(id[i]);
                    }
                    else fst=0;
                }
                if(ab==0)
                {
                    if(sb.count(id[i]))
                    {
                        sb.clear();
                        sb.insert(id[i]);
                    }
                    else fsb=0;
                }
                all++;
                ab++;
            }
        }

        if(!fst) st.clear();
        if(!fsb) sb.clear();

        for(std::set<int>::iterator it = st.begin(); it != st.end(); ++it)
        {
            if(sb.count(*it)==0) sb.insert(*it);
        }
        for(std::set<int>::iterator it = sb.begin(); it != sb.end(); ++it)
        {
            ans[k++]=*it;
        }
        cout<<k<<endl;
        if(k>0){for(i=0;i<k-1;i++) cout<<ans[i]<<" ";cout<<ans[i]<<endl;}
        /*********************************************************************************************************/


    }
    return 0;
}


/*
5 4
+ 1
+ 2
- 2
- 1

3 2
+ 1
- 2

2 4
+ 1
- 1
+ 2
- 2

5 6
+ 1
- 1
- 3
+ 3
+ 4
- 4

2 4
+ 1
- 2
+ 2
- 1


*/
