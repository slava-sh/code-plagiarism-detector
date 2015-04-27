program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  o = 29;

var
  n, i, j, t: integer;
  a, b, p: array[0..200001] of int64;
  s: string;

function hash_front(l, r: integer): int64;
begin
  result := a[r] - a[l-1] * p[r-l+1];
end;

function hash_back(l, r: integer): int64;
begin
  result := b[l] - b[r+1] * p[r-l+1];
end;

begin
  reset(input, 'inventory.in');
  rewrite(output, 'inventory.out');
  readln(n);
  p[0] := 1;
  for i := 1 to 200000 do
    p[i] := p[i-1] * o;
  for j := 1 to n do begin
    a[0] := 0;
    readln(s);
    t := length(s);
    b[t * 2 + 1] := 0;
    s := s + s;
    for i := 1 to t * 2 do
      a[i] := a[i-1] * o + ord(s[i]) - ord('a') + 1;
    for i := t * 2 downto 1 do
      b[i] := b[i+1] * o + ord(s[i]) - ord('a') + 1;
    i := 1;
    while (i <= t)and(hash_front(i, i + t - 1) <> hash_back(i, i + t - 1)) do
      inc(i);
    if (hash_front(i, i + t - 1) = hash_back(i, i + t - 1)) then
      writeln(i-1)
    else
      writeln(-1);
  end;
  close(input);
  close(output);
end.
