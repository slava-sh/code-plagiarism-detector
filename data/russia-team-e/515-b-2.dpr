program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type mas=array[1..1000000]of longint;
var a:mas;i,j,n,k:longint;ans:int64;
begin
  assign(input,'che.in');
  assign(output,'che.out');//}
  read(n,k);
  ans:=0;
  for i:=1 to n do read(a[i]);
  i:=1;
  j:=1;
  a[n+1]:=2000000000+2;
  while i<n do
  begin
    while a[j]-a[i]<=k do inc(j);
    inc(ans,n-j+1);
//    writeln(a[i],' ',a[j],' ',i,' ',j);
    inc(i);
  end;
  writeln(ans);
  readln;readln;
end.
