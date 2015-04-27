#include <bits/stdc++.h>

using
namespace
std;


int
main(){




map<int,int>
cnts;




int
n;




cin>>n;




for
(int
i=0;i<n;i++){








int
a;








cin>>a;








++cnts[a];




}




priority_queue<pair<int,int>
>
qu;




for(map<int,int>::iterator
it=cnts.begin();it!=cnts.end();++it){








qu.push(make_pair(it->second,
it->first));




}




vector<pair<pair<int,int>,int>
>
res;




while(qu.size()>=3)
{








pair<int,int>
a
=
qu.top();








qu.pop();








pair<int,int>
b
=
qu.top();








qu.pop();








pair<int,int>
c
=
qu.top();








qu.pop();








res.push_back(make_pair(make_pair(a.second,b.second),c.second));








--a.first;








--b.first;








--c.first;








if(a.first)












qu.push(a);








if(b.first)












qu.push(b);








if(c.first)












qu.push(c);




}




cout<<res.size()<<endl;




for(int
i
=
0;
i
<res.size();
i++){








int
a=res[i].first.first;








int
b=res[i].first.second;








int
c=res[i].second;








if(a<b)












swap(a,b);








if(b<c)












swap(b,c);








if(a<b)












swap(a,b);








cout<<a<<' '<<b<<' '<<c<<'\n';




}









return
0;
}
