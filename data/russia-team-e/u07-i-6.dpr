program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var l,sum,n,k,i:integer; 
    a,s:array[1..100000]of integer; 
    w,r:text; 
begin
  assign(w,'sochi.in'); reset(w); 
  assign(r,'sochi.out'); rewrite(r); 
  readln(w,n,k); 
  for i:= 1 to n do
  read(w,s[i]); 
  for i:= 1 to n do
  if s[i]>=k then
  begin
  inc(l); 
  a[l]:=s[i]; 
  end; 
  sum:=a[1]+a[2]-2*k; 
  for i:= 3 to l do
  begin
  sum:=(sum+a[i])-2*k; 
  end; 
  writeln(r,sum); 
  close(r); 
  close(w); 
end.


