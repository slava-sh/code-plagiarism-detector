program Project2;

{$APPTYPE CONSOLE}

{%File 'abcd.in'}
{%File 'abcd.out'}

uses
  SysUtils;

var
    a:array[1..4] of byte;
    summ:int64;
    i,t,p:longint;
begin
assign(input,'abcd.in');
assign(output,'abcd.out');
summ:=0;
  read(t);
  for i:= 1 to t do begin
  read(p);
  a[4]:=p mod 10;
  a[3]:=p div 10 mod 10;
  a[2]:=p div 100 mod 10;
  a[1]:=p div 1000 mod 10;
  summ:=(a[1]*10+a[2])*(a[1]*10+a[2])+(a[3]*10+a[4])*(a[3]*10+a[4]);
 if (summ mod 7 =1) then writeln('YES') else writeln('NO');
  end;
end.
 