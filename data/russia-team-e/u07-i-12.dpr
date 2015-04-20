      program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var s,l,sum1,sum2,n,k,i:integer;
    b,a:array[1..10000000]of integer;
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
  if a[i]>3*k then
  sum1:=sum1+a[i]else
  sum2:=sum2+a[i];
  writeln(w,sum1+sum2-2*(l-1)*k);



close(r);
 close(w);
  end.

