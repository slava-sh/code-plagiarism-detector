program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n,m:integer;
begin
  assign(input,'prizes.in');
  reset(input);
  assign(output,'prizes.out');
  rewrite(output);
  read(n,m);
  writeln(n div m);
  readln;
  readln;
end.
