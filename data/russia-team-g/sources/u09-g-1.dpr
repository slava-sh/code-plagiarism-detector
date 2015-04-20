program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n,m:integer;
begin
  assign(input,'prize.in');
  reset(input);
  assign(output,'prize.out');
  rewrite(output);
  read(n,m);
  writeln(n div m);
  readln;
  readln;
end.
