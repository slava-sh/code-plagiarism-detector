program Gcm;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
a,b,s: longint;
x:real;
begin
  assign(input,'gcm.in');
  assign(output,'gcm.out');
  reset(input);
  rewrite(output);
  readln(a,b);
  s:=a*b;
  x:=trunc(sqrt(s));
  while (s/x<>trunc(s/x)) do
  x:=x-1;
  writeln (x:0:0,' ',s/x:0:0);
  close(input);
  close(output);
end.
