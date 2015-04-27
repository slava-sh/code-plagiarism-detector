#include <cstdio>
#include <algorithm>
using namespace std;
struct ball{
  int amount;
  int r;
};
struct snow{
  int a;
  int b;
  int c;
};
bool operator<(const ball &a, const ball &b){
  if(a.amount<b.amount) return true;
  else return false;
}
int N,n;
int array[100000];
ball all[100000];
snow men[100000];
int ans;
int main(){
  ans=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++) scanf("%d",&array[i]);
  sort(array,array+N);
  n=0;
  int hwm=1;
  for(int i=1;i<N;i++){
    if(array[i]==array[i-1]){
      hwm++;
    }else{
      all[n].amount=hwm;
      all[n].r=array[i-1];
      hwm=1;
      n++;
    }
  }
  all[n].amount=hwm;
  all[n].r=array[N-1];
  n++;
  sort(all,all+n);
  reverse(all,all+n);
  if(n<3){
    printf("0");
    return 0;
  }
  while(1){
    if(all[0].amount<=0 || all[1].amount<=0 || all[2].amount<=0) break;


    if((n>3 && all[2].amount> all[3].amount) || (n==3)){ //jest ok
      all[0].amount--;
      all[1].amount--;
      all[2].amount--;
      men[ans].a=all[0].r;
      men[ans].b=all[1].r;
      men[ans].c=all[2].r;
    }else{
      int war=all[3].amount;
      int chan=0;
      if(all[0].amount==war){
        chan++;
      }else{
        men[ans].a=all[0].r;
        all[0].amount--;
      }
      if(all[1].amount==war){
        chan++;
      }else{
        men[ans].b=all[1].r;
        all[1].amount--;
      }
      if(all[2].amount==war){
        chan++;
      }else{
        men[ans].c=all[2].r;
        all[2].amount--;
      }
      //binsearch
      int left=0;
      int right=n-1;
      while(left<right){
        int midd=(left+right)/2;
        if(all[midd].amount>war) left=midd+1;
        if(all[midd].amount<war) right=midd-1;
        if(all[midd].amount==war){
          if(midd+1<n && all[midd+1].amount==war && all[midd+1].amount>0){
            left=midd+1;
          }else{
            left=midd;
            break;
          }
        }
      }


      for(int i=0;i<chan;i++){
        all[left-i].amount--;
        if(i==0) men[ans].c=all[left-i].r;
        if(i==1) men[ans].b=all[left-i].r;
        if(i==2) men[ans].a=all[left-i].r;
      }

    }
    ans++;
  }
  printf("%d\n",ans);
  for(int i=0;i<ans;i++){
    int ar[3];
    ar[0]=men[i].a;
    ar[1]=men[i].b;
    ar[2]=men[i].c;
    sort(ar,ar+3);
    printf("%d %d %d\n",ar[2],ar[1],ar[0]);
  }


  return 0;
}


