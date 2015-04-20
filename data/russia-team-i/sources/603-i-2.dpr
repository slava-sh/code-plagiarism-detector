{$R-,S-,Q-,I-,O+}
{$M 32000000}

{$APPTYPE CONSOLE}

uses Math;
const
  maxn = round(1e5) + 200;
  inf = round(1e9);
  md = inf + 7;
var
     n, d, ans, i, j, cur : longint;
     a : array [1..maxn] of longint;

  procedure Sort(l, r : longint);
  var
     i, j, t, x : longint;
  begin
    i := l;
    j := r;
    x := a[l + random(r - l + 1)];
    repeat
      while x > a[i] do inc(i);
      while x < a[j] do dec(j);
      if i <= j then
      begin
        t := a[i]; a[i] := a[j]; a[j] := t;
        inc(i); dec(j);
      end;
    until i > j;
    if i < r then sort(i, r);
    if l < j then sort(l, j);
  end;

begin
  reset(input, 'sochi.in');
  rewrite(output, 'sochi.out');
  readln(n, d);
  for i := 1 to n do read(a[i]);
  Sort(1, n);
  ans := a[n];
  if n > 1 then ans := max(ans, a[n] + a[n - 1] - 2 * d);
  if n > 2 then
  begin
    j := 0;
    for i := 1 to n do
    if a[i] >= 2 * d then
    begin
      j := i;
      break;
    end;
    cur := 0;
    if n - j + 1 >= 3 then
    begin
      cur := a[j] - d + a[j + 1] - d;
      for i := j + 2 to n do
      if a[i] >= 3 * d then cur := cur + a[i] - 2 * d;
    end;
    ans := max(ans, cur); 
  end;

  writeln(ans);
end.
