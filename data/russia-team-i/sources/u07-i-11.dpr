      program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var s,l,sum,n,k,i:integer;
    a:array[1..10000000]of integer;
r,w:text;
begin
   assign(r,'sochi.in'); reset(r);
 assign(w,'sochi.out'); rewrite(w);
  readln(r,n,k);
  for i:= 1 to n do
  begin
  read(r,s);
  if (s)>(2*k) then
  begin
  inc(l);
  a[l]:=s;
  end;
  end;
  for i:=1 to l do
  sum:=sum+a[i];
  writeln(w,sum-k*(2*(l-1)));
close(r);
 close(w);
  end.

