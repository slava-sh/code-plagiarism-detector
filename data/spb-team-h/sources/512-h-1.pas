var
  a, b: array[1..3, 1..1000] of string;
  c: array[1..1000] of string;
  i, j, n, k: longint;
  x: char;
procedure qsorta(l, r: longint);
var
  i, j: longint;
  x, y: string;
begin
  i := l; j := r; x := a[1, random(r - l + 1) + l];
  repeat
    while x > a[1, i] do inc(i);
    while x < a[1, j] do dec(j);
    if i <= j then
    y := a[1, i]; a[1, i] := a[1, j]; a[1, j] := y;
    y := a[2, i]; a[2, i] := a[2, j]; a[2, j] := y;
    y := a[3, i]; a[3, i] := a[3, j]; a[3, j] := y;
    inc(i); dec(j);
  until i >= j;
  if l < j then qsorta(l, j);
  if i < r then qsorta(i, r);
end;

procedure qsortb(l, r: longint);
var
  i, j: longint;
  x, y: string;
begin
  i := l; j := r; x := b[2, random(r - l + 1) + l];
  repeat
    while x > b[2, i] do inc(i);
    while x < b[2, j] do dec(j);
    if i <= j then
    y := b[1, i]; b[1, i] := b[1, j]; b[1, j] := y;
    y := b[2, i]; b[2, i] := b[2, j]; b[2, j] := y;
    y := b[3, i]; b[3, i] := b[3, j]; b[3, j] := y;
    inc(i); dec(j);
  until i >= j;
  if l < j then qsortb(l, j);
  if i < r then qsortb(i, r);
end;

procedure qsortc(l, r: longint);
var
  i, j: longint;
  x, y: string;
begin
  i := l; j := r; x := c[random(r - l + 1) + l];
  repeat
    while x > c[i] do inc(i);
    while x < c[j] do dec(j);
    if i <= j then
    y := c[i]; c[i] := c[j]; c[j] := y;
    inc(i); dec(j);
  until i >= j;
  if l < j then qsortc(l, j);
  if i < r then qsortc(i, r);
end;

BEGIN
  assign(input, 'names.in');
  assign(output, 'names.out');
  reset(input);
  rewrite(output);

  readln(n);
  for i := 1 to n do
  begin
    a[1, i] := '';
    a[2, i] := '';
    a[3, i] := '';
    read(x);
    while x <> ' ' do
    begin
      a[1, i] := a[1, i] + x;
      read(x);
    end;
    read(x);
    while x <> ' ' do
    begin
      a[2, i] := a[2, i] + x;
      read(x);
    end;
    readln(a[3, i]);
    b[1, i] := a[1, i]; b[2, i] := a[2, i]; b[3, i] := a[3, i];
  end;
  qsorta(1, n);
  qsortb(1, n);
  j := 1;
  for i := 1 to n do
  begin
    k := i;
    while (a[1, i] > b[2, k]) and (k <= n) do
      inc(k);
    if a[1, i] = b[2, k] then
    begin
      c[j] := '';
      c[j] := b[1, k] + ' ' + b[2, k] + ' ' + b[3, k];
      inc(j);
      c[j] := '';
      c[j] := a[3, i] + ' ' + a[1, i] + ' ' + a[2, i];
      inc(j);
    end
    else if k > n then
      begin
      c[j] := '';
      c[j] := a[1, i] + ' ' + a[2, i] + ' ' + a[3, i];
      inc(j);
    if (k < n) and (a[1, i] <> b[2, k]) then
    begin
      c[j] := '';
      c[j] := a[1, i] + ' ' + a[2, i] + ' ' + a[3, i];
      inc(j);
      end;
    end;
  end;
  qsortc(1, n);
  for i := 1 to n do
  begin
    writeln(c[i]);
  end;
  close(input);
  close(output);
end.

