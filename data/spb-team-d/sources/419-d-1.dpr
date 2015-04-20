program letsgobowling;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n, m, x, i, j: integer;
  q, l, r: int64;
  a: array [1..1000000000] of integer;
begin
  assign(input, 'abcd.in');
  assign(output, 'abcd.out');
  readln(n, m);
  for i := 1 to n do begin
    readln(l, r, x);
    for j := l to r do
      if j mod 2 = l mod 2 then
        a[j] := a[j] + x
      else
        a[j] := a[j] - x;
  end;
  for i := 1 to m do begin
    read(q);
    writeln(a[q]);
  end;  
end.
