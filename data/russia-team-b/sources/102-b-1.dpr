program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, l, r, m, i: integer;
  ans: int64;
  a: array[0..500000] of integer;

begin
  reset(input, 'che.in');
  rewrite(output, 'che.out');

  readln(n, m);
  for i := 1 to n do begin
    read(a[i]);
  end;
  a[n + 1] := maxint;

  r := 1;
  for l := 1 to n do begin
    while (r + 1 <= n) and (a[r + 1] - a[l] <= m) do begin
      inc(r);
    end;
    if (a[r + 1] - a[l] <= m) then begin
      continue;
    end;
   // writeln(r);
    ans := ans + (n - r);
  end;
  writeln(ans);

end.
