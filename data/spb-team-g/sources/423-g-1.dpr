program Merlin;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var i,j,s,k,n,t:longint;a:array[1..100001]of int64;
begin
  assign(input,'merlin.in');
  assign(output,'merlin.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:= 1 to n-1 do
    for j:=1 to n-i do
      if(a[j]>a[j+1]) then
        begin
        t:=a[j];
        a[j]:=a[j+1];
        a[j+1]:=t;
        end;
  for i:= 1 to n do s:=s+a[i];
  a[n+1]:=0;
  i:=n+1;
  while(a[i]<(a[i-1]-(s-a[i-1])/(i-2))*(i-2)) do
    begin
    i:=i-1;
    s:=s-a[i];
    end;
 writeln(n-i+1);

  close(input);
  close(output);
end.
 