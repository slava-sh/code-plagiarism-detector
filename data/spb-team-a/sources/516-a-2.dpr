program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var i,a,n,b,x,k:longint;

begin
assign(input,'abcd.in');
assign(output,'abcd.out');
readln(n);
for i:=1 to n do
  begin
  readln(x);
  a:=x div 100;
  b:=x mod 100;
  k:=a*a+b*b;
  if k mod 7 = 1 then writeln('YES') else writeln('NO');
  end;
end.
 