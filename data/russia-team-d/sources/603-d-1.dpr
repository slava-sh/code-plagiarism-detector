{$R-,S-,Q-,I-,O+}
{$M 32000000}

{$APPTYPE CONSOLE}

uses Math;
const
  maxn = round(1e5) + 200;
  inf = round(1e9);
  md = inf + 7;
var
   n, k, i, ll, rr, mid : longint;
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

  function check(x : longint) : boolean;
  var
    border : longint;
  begin
    border := a[1];
    for i := 2 to n do border := max(border + x, a[i]);
    check := border <= k;
  end; 

begin
  reset(input, 'fence.in');
  rewrite(output, 'fence.out');
  readln(n, k);
  rr := inf;
  for i := 1 to n do read(a[i]);
  Sort(1, n);

  ll := 1;
  rr := a[1];
  while ll < rr do
  begin
    mid := (ll + rr) shr 1;
    if check(mid) then ll := mid + 1
                  else rr := mid;
  end;
  if not check(ll) then dec(ll);
  writeln(ll);
end.
