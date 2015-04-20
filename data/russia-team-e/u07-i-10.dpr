program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var j,l,sum,n,k,i:integer;
s,a:array[1..1000000] of integer;
r,w:text;
begin
  assign(r,'sochi.in'); reset(r);
  assign(w,'sochi.out'); rewrite(w);
  readln(r,n,k);
  sum:=0;
  for i:= 1 to n do
  begin
  read(r,s[i]);
  if s[i]>=k then
  begin
  inc(l);
  a[l]:=s[i]
  end;
  for j:=1 to l do
  sum:=sum+a[j];
  end;
  sum:=sum -((n-1)*2*k);
  Write(w,sum);
  close(r);
  close(w);
  end.
