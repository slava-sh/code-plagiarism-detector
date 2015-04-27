#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    char a[1005][1005],b[3][3];
    int i,j,k,m,n,t;
    bool f;
    b[0][0]='1',b[0][1]='2',b[0][2]='3';
    b[1][0]='4',b[1][1]='5',b[1][2]='6';
    b[2][0]='7',b[2][1]='8',b[2][2]='9';
    while(cin>>n>>m){
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>a[i][j];
                //scanf("%c",&a[i][j]);
        for(i=0;i<n;i++){
            k=i%3;
            t=0;
            for(j=0;j<m;j++){
                if(a[i][j]=='.'){
                    if(j+1<m&&a[i][j+1]=='.'){
                        a[i][j+1]=a[i][j]=b[k][t];
                        t=(t+1)%3;
                    }
                    else if(i+1<n&&a[i+1][j]=='.'){
                        a[i][j]=a[i+1][j]=b[k][t];
                        t=(t+1)%3;
                    }
                }
            }
        }
        f=true;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(a[i][j]=='.'){
                    if(j-1>=0&&a[i][j-1]!='#')
                        a[i][j]=a[i][j-1];
                    else if(j+1<m&&a[i][j+1]!='#')
                        a[i][j]=a[i][j+1];
                    else if(i-1>=0&&a[i-1][j]!='#')
                        a[i][j]=a[i-1][j];
                    else{
                        f=false;
                        break;
                    }
                }
            }
            if(!f)
                break;
        }
        if(!f)
            cout<<-1<<endl;
        else{
            for(i=0;i<n;i++){
                for(j=0;j<m;j++)
                    printf("%c",a[i][j]);
                printf("\n");
            }
        }
    }
}