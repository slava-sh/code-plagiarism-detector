program Project2;

{$APPTYPE CONSOLE}

{%File 'dunes.in'}
{%File 'dunes.out'}

uses
  SysUtils;

var i,f,j,m,n,k:longint;
 l,r:array [1..1000] of longint;
 x:array [1..1000] of integer;
begin
assign(input,'dunes.in');
assign(output,'dunes.out');
readln(n,m);
for i:=1 to n do
begin
read(l[i]);
read(r[i]);
readln(x[i]);
end;
for i:=1 to m do
  begin
  readln(k);
  f:=0;
  for j:=1 to n do
    begin
    if (k>=l[j]) and (k<=r[j]) then
      if ((k-l[j]) mod 2)=0 then f:=f+x[j] else f:=f-x[j];
    end;
    writeln(f);
  end;
{for i:=1 to n do
  begin
  readln(l,r,x);
  if l mod 2 = 0
    then
    for j:=l to r do if (j mod 2) = 0 then a[j]:=a[j]+x else a[j]:=a[j]-x
    else
    for j:=l to r do if (j mod 2) = 1 then a[j]:=a[j]+x else a[j]:=a[j]-x;
   end;
for i:=1 to m do
  begin
  readln(k);
  writeln(a[k]);
  end;}
end.
