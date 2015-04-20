program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;

var
  a: array[0..300000] of integer;
  n, d, i: integer;
  ans, sum: int64;

procedure qsort(l, r: integer);
var
  i, j, q, t: integer;
begin
  i := l;
  j := r;
  q := a[random(r - l + 1) + l];
  while i <= j do begin
    while q < a[i] do inc(i);
    while q > a[j] do dec(j);
    if i <= j then begin
      t := a[i];
      a[i] := a[j];
      a[j] := t;

      inc(i);
      dec(j);
    end;
  end;

  if l < j then qsort(l, j);
  if r > i then qsort(i, r);
end;

begin
  reset(input, 'sochi.in');
  rewrite(output, 'sochi.out');

  readln(n, d);

  for i := 1 to n do begin
    read(a[i]);
  end;
  qsort(1, n);

  ans := 0;
  sum := 0;
  for i := 1 to n do begin
    sum := sum + a[i];
    if (i > 1) and (a[i] < d) then break;
    if (i > 2) and (a[i - 2] < 2 * d) then break;
    ans := max(ans, sum - (d * 2) * (i - 1));
  end;
  writeln(ans);
end.
