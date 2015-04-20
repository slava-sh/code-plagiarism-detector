program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  a : array[1..1393] of integer;
  n, k, i : integer;
begin
  Assign(input, 'chess.in');
  reset(output, 'chess.out');
  readln(n);
  for i := 1 to n do
    read(a[i]);
  i := 1;
  k := 0;
  while i <= a[i] do begin
    inc(k);
    inc(i);
  end;
  writeln(k);
  i := 1;
  while i <= a[i] do begin
    writeln(i, ' ', i);
    inc(i);
  end;
  close(output);
end.
