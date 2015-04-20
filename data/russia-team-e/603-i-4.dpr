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
     used : array [1..maxn] of boolean;

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
  randomize;
  readln(n, d);
  for i := 1 to n do read(a[i]);
  Sort(1, n);
  ans := a[n];
  if n > 1 then ans := max(ans, a[n] + a[n - 1] - 2 * d);
  if n > 2 then
  begin
    cur := 0;
    fillchar(used, sizeof(used), false);
    for i := 1 to n do
    if a[i] >= 3 * d then
    begin
      cur := cur + a[i] - 2 * d;
      used[i] := true;
    end;
    j := 0;
    for i := n downto 1 do
    if not used[i] and (a[i] >= 2 * d) then
    begin
      j := i;
      break;
    end;
     if j = 0 then cur := cur + 2 * d
     else
      if (j > 1) and (a[j - 1] >= 2 * d) then cur := cur + a[j] + a[j - 1] - 2 * d
       else
         cur := cur + a[j];
         
    ans := max(ans, cur); 
  end;

  writeln(ans);
end.
