program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  t, x1, x2, i: integer;
  s: string;

begin
  assignfile(input, 'abcd.in');
  assignfile(output, 'abcd.out');
  readln(t);

  for i:= 1 to t do
  begin
    readln(s);
    x1:= strtoint(copy(s, 1, 2));
    x2:= strtoint(copy(s, 3, 4));
    if ((x1*x1 + x2*x2) mod 7 = 1) then
      writeln('YES')
    else
      writeln('NO');
  end;
end.
