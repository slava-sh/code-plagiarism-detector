program ProjectA;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var t, i, n, a, b, c, d : integer;
BEGIN
  assign (input, 'abcd.in');
  assign (output, 'abcd.out');
  reset(input);
  rewrite(output);
  read(t);
  for i:= 1 to t do
    begin
    readln(n);
    a:= n div 100;
    b:= n mod 100;
    c:= a*a + b*b;
    d:= c mod 7;
    if d=1 then writeln('YES')
    else writeln('NO');
    end;
  close(input);
  close(output);
END.
 