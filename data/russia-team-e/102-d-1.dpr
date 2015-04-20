program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;

var
  n, k, l, r, m, i: integer;
  a: array[0..300000] of integer;

function get(m: integer): boolean;
var
  i, tmp: integer;
  ag: integer;
begin
  ag := 0;
  for i := 1 to n do begin
    if a[i] < m then begin
      result := false;
      exit;
    end;
    //tmp := min(ag, a[i] - m);
    //ag := ag + (a[i] - tmp);
    ag := ag + max(0, a[i] - m - ag) + m;
  end;

  result := ag <= k;
end;

procedure qsort(l, r: integer);
var
  i, j, q, t: integer;
begin
  i := l;
  j := r;
  q := a[random(r - l + 1) + l];
  while i <= j do begin
    while q > a[i] do inc(i);
    while q < a[j] do dec(j);
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
  reset(input, 'fence.in');
  rewrite(output, 'fence.out');

  readln(n, k);
  for i := 1 to n do
    read(a[i]);

  qsort(1, n);

  l := 0;
  r := k + 1;
  while l + 1 < r do begin
    m := (l + r) div 2;
    if (get(m)) then
      l := m
    else
      r := m;
  end;
  writeln(l);
end.
 