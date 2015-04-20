{$R-, Q-, T-, S-, I-, O+}
{$M 50000000}
var
  n,m,i,e,x,y,z,totalAns,ans1,ans2 : longint;
  any : boolean;
  best,a,next,last,finish,cost : array [0..200000] of longint;
  tc,reached : array [0..200000] of boolean;
  mar : array [0..6000,0..6000] of boolean;
  procedure dfscalc(x : longint);
  var p : longint;
  begin
    if (a[x] = 2) then TC[i] := true;
    if mar[i][x] then exit;
    mar[i][x] := true;
    if (a[i] = 1) and (a[x] = 1) then reached[x] := true;
    p := last[x];
    while (p > 0) do
    begin
      if not mar[i][finish[p]] then dfscalc(finish[p]);
      p := next[p];
    end;
  end;
  procedure realdfs(x : longint; carry : int64);
  var p : longint;
  begin
    if (carry >= totalAns) or (carry >= best[x]) or (not TC[x]) then exit;
    best[x] := carry;
    if (a[x] = 2) and (carry < totalAns) then
    begin
      totalAns := carry;
      ans1 := i;
      ans2 := x;
    end;
    p := last[x];
    while (p > 0) do
    begin
      realdfs(finish[p], carry + cost[p]);
      p := next[p];
    end;
  end;
begin
  assign(input,'secure.in');reset(input);
  assign(output,'secure.out');rewrite(output);
  totalAns := maxlongint;
  readln(n, m);
  for i := 1 to n do read(a[i]);
  for i := 1 to n do best[i] := maxlongint;
  for i := 1 to m do
  begin
    readln(x, y, z);
    inc(e);
    next[e] := last[x];
    last[x] := e;
    finish[e] := y;
    cost[e] := z;
    inc(e);
    next[e] := last[y];
    last[y] := e;
    finish[e] := x;
    cost[e] := z;
  end;
  for i := 1 to n do
    dfscalc(i);
  any := false;
  for i := 1 to n do
    if (a[i]=1) and (tc[i]) then realdfs(i,0);
  if totalAns=maxlongint then writeln(-1) else writeln(ans1,' ',ans2,' ',totalAns);
  close(input);
  close(output);
end.