program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var s,l,sum,n,k,i:integer;
r,w:text;
begin
   assign(w,'sochi.in'); reset(w);
  assign(r,'sochi.out'); rewrite(r);
  readln(r,n,k);
  for i:= 1 to n do
  begin
  read(r,s);
  sum:=sum+s;
  end;
  sum:=sum -((n-1)*2*k);
  Write(w,sum);
  close(r);
  close(w);
  end.
