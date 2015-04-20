program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  m, n: Integer;
  l, r, x, xr, q: array[0..1000] of Integer;
  Inp, O: TextFile;
  i,j: Integer;
begin
  AssignFile(Inp, 'dunes.in');
  Reset(Inp);
  Readln(Inp, n, m);
  For i := 0 to n-1 do
    Readln(Inp, l[i], r[i], x[i]);
  For i := 0 to m-1 do
    Readln(Inp, q[i]);
  CloseFile(Inp);

  for i := 0 to m-1 do begin
    xr[i] := 0;
    for j := 0 to n-1 do
      if (l[j] <= q[i]) and (r[j] >= q[i]) then
        if (q[i] mod 2) = (l[j] mod 2) then
          xr[i] := xr[i] + x[j]
        else
          xr[i] := xr[i] - x[j];
  end;

  AssignFile(O, 'dunes.out');
  Rewrite(O);
  for i := 0 to m-1 do
    Writeln(O, xr[i]);
  CloseFile(O);
end.
