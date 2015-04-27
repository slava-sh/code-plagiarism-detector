#include<stdio.h>

#define MAXN 500

long long tables[MAXN+10][MAXN+10];

void printtables(maxi, maxj)
{
  int i,j;

  for(i=0; i<maxi; i++){
    for(j=0; j<maxj; j++){
      printf("%3d", (int)tables[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main()
{
  int n, m, mod, i, j;
  int col[MAXN];
  int ones, zeros, o, z, o2, z2;

  scanf("%d %d %d\n", &n, &m, &mod);

  for(i=0; i<n; i++) col[i] = 0;
  for(; m>0; m--){
    for(i=0; i<n; i++)
      if(fgetc(stdin) == '1') col[i]++;
    scanf("\n");
  }

  ones = zeros = 0;
  for(i=0; i<n; i++){
    if(col[i] == 0) zeros++;
    else if(col[i] == 1) ones++;
    else if(col[i] > 2){
      printf("0\n");
      return 0;
    }
  }
  for(i=0; i<n+5; i++)
    for(j=0; j<n+5; j++){
      tables[i][j] = 0;
      tables[i][j] = 0;
    }
  tables[zeros][ones] = 1;

  //printtables(n+5, n+5);
  //printf("%d zeros, %d ones\n", zeros, ones);

  o = ones-1;
  for(z = zeros; z>=0; z--){
    for(; o>=0; o--){
      tables[z][o] = 0;

      z2 = z; o2 = o+2; // 1-1
      tables[z][o] += (o2*(o2-1)/2)*tables[z2][o2];
      tables[z][o] %= mod;

      z2 = z+1; o2 = o; // 0-1
      tables[z][o] += o2*z2*tables[z2][o2];
      tables[z][o] %= mod;

      z2 = z+2; o2 = o-2; // 0-0
      if(o2 >= 0){
	tables[z][o] += (z2*(z2-1)/2)*tables[z2][o2];
	tables[z][o] %= mod;
      }
      //printtables(n+5, n+5);
    }
    o = n;
  }
  printf("%d\n", (int)tables[0][0]);

  return 0;
}
