program Project2;

{$APPTYPE CONSOLE}

{%File 'dunes.in'}
{%File 'dunes.out'}

uses
  SysUtils;

var i,l,r,x,m,n,j,k:longint;
  a:array[1..1000000000] of longint;
begin
assign(input,'dunes.in');
assign(output,'dunes.out');
readln(n,m);
for i:=1 to n do
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
  end;
end.
