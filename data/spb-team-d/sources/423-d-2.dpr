program Dunes;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
a:array[1..2001] of int64;
b:array[1..1001] of int64;
i, j, m, n:int64;
t,x:int64;
begin
  assign(input,'dunes.in');
  assign(output,'dunes.out');
  reset(input);
  rewrite(output);
  readln(n, m);
  x:=0;
  for i:= 1 to n do
    begin
    read(a[2*i-1]);
    read(a[2*i]);
    readln(b[i]);
    end;
  for i:=1 to m do
    begin
    readln(t);
    for j:=1 to n do
    if (a[2*j-1]<=t) and (t<=a[2*j]) then
    if ((t-2*j+1) mod 2 = 0) then x:=x+b[j] else x:=x-b[j];
    writeln (x);
    x:=0;
    end;
  close(input);
  close(output);
end.
