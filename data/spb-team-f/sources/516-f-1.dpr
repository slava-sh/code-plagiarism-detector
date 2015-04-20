program Project2;

{$APPTYPE CONSOLE}


{%File 'chess.in'}
{%File 'chess.out'}

uses
  SysUtils;

var i,j,k,n,a:longint;
begin
 assign(input,'chess.in');
 assign(output,'chess.out');
readln(n);
for i:=1 to n do
  begin
  read(a);
  if a<i then break;
  end;
k:=i-1;
writeln(k);
for i:=1 to k do writeln(i,' ',i);
end.
