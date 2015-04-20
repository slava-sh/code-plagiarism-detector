{$R-,S-,Q-,I-,O+}
{$M 32000000}

{$APPTYPE CONSOLE}

uses Math;
const
  maxn = 3 * round(1e5) + 200;
  inf = round(1e9);
  md = inf + 7;
var
   n, i, r, j, cur, len : longint;
   d : array [1..maxn] of longint;
   ans : int64;
begin
  reset(input, 'che.in');
  rewrite(output, 'che.out');
  readln(n, r);
  for i := 1 to n do read(d[i]);
  ans := 0;
  i := 1; j := 1;
  cur := 0;
  while i <= n do
  begin
    while (j < n) and (cur + d[j + 1] - d[j] <= r) do
    begin
      inc(j);
      cur := cur + d[j] - d[j - 1];
    end;
    if j <= n then
    begin
      len := n - j;
      ans := ans + len;
    end;
    inc(i);
    cur := cur - (d[i] - d[i - 1]);
  end;
  writeln(ans);
end.
