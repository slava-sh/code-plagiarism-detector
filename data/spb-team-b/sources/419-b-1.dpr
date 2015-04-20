program letsgobowling;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n, i, j, k, l: integer;
  a: array [1..1000,1..1000] of integer;

begin
  assign(input, 'chess.in');
  assign(output, 'chess.out');
  readln(n);
  for i := 1 to n do begin
    read(l);
    for j := 1 to l do
      a[i,j] := 1;
  end;
  k := 0;
  for i := 1 to 1000 do
      if a[i,i] = 1 then
        k := k + 1
      else
        break;
  writeln(k);
  for i := 1 to k do
    writeln(i,' ',i);
end.
