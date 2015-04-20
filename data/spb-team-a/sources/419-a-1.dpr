program letsgobowling;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  t, i, s: integer;
begin
  assign(input, 'abcd.in');
  assign(output, 'abcd.out');
  readln(t);
  for i := 1 to t do begin
    readln(s);
    if ((s div 100)*(s div 100) + (s mod 100)*(s mod 100)) mod 7 = 1 then
      writeln('YES')
    else
      writeln('NO');
  end;
end.
