#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
main()
{ 
int i,a [n],t,ok;
for(i=0;i<n;i++)
{
a[i] =random(20)-10;
printf("%i,",a[i]);
}
m1:ok=0;
for(i=0; i<n-1;i++)
{
if(a[i]>a[i+1])
{
    t=a[i+1]
    a[i+1]=a[i];
    a[i]=t;

    ok=1;
  }
}
if(ok==1) goto m1;
printf("n.suriptalgan");
for(i=0;i<n;i++);
printf("%i,",a[i]);
getch();
}