program abcd;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  i,t,a,b:longint;
  f:string;
begin
  assign(input,'abcd.in');
  assign(output,'abcd.out');
  reset(input);
  rewrite(output);
  readln(t);
  for i :=1 to t do
    begin
    readln(f);
    a:=(ord(f[1])-ord('0'))*10+(ord(f[2])-ord('0'));
    b:=(ord(f[3])-ord('0'))*10+(ord(f[4])-ord('0'));
    if((sqr(a)+sqr(b)) mod 7=1) then
      writeln('YES') else
      writeln('NO');
    end;
  close(input);
  close(output);
end.
