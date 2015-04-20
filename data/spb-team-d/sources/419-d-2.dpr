program letsgobowling;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n, m, x, i, j: integer;
  l, r: int64;
  a: array [1..1000, 1..3] of int64;
  b: array [1..1000, 1..2] of int64;
begin
  assign(input, 'dunes.in');
  assign(output, 'dunes.out');
  readln(n ,m);
  for i := 1 to n do
    readln(a[i,1], a[i,2], a[i,3]);
  for i := 1 to m do
    readln(b[i,1]);
  for i := 1 to n do
    for j := 1 to m do
      if ((b[j,1] > a[i,1]) and (b[j,1] < a[i,2])) or (b[j,1] = a[i,1]) or (b[j,1] = a[i,2]) then begin
        if b[j,1] mod 2 = a[i,1] mod 2 then
          b[j,2] := b[j,2] + a[i,3]
        else
          b[j,2] := b[j,2] - a[i,3];
      end;
  for i := 1 to m do
    writeln(b[i,2]);
end.

