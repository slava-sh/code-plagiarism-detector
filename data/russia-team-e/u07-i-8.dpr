program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var s,l,sum,n,k,i:integer;
r,w:text;
begin
   assign(r,'sochi.in'); reset(r);
  assign(w,'sochi.out'); rewrite(w);
  readln(r,n,k);
  sum:=0;
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
