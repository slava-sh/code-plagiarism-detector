program Chess;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n,i,j:longint;
  a:array[1..1000] of longint;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  readln(n);
  i:=0;
  repeat
    i:=i+1;
    read(a[i]);
  until (a[i]<i);
  writeln(i-1);
  for j:=1 to i-1 do
    writeln(j,' ',j);
  close(input);
  close(output);
end.
 