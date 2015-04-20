{$R-,S-,Q-,I-,O-}
{$M 32000000}

{$APPTYPE CONSOLE}

uses Math;
const
  maxn = 2 * round(1e5) + 200;
  inf = round(1e9);
  md = inf + 7;
var
   n, x, i, a, b, v0, u0, ans, timer : longint;
   fn, nn, ni, pr, h, tin, tout, id : array [1..2 * maxn] of longint;
   path : array of longint;
   t : array [1..4 * maxn] of longint;
   pref, suf, mxp, mxs : array [0..maxn] of longint;

  procedure AddEdge(a, b : longint);
  begin
    inc(x);
    ni[x] := b;
    nn[x] := fn[a];
    fn[a] := x;
  end;

  procedure dfs(v, p, depth : longint);
  var
     u, t : longint;
  begin
    inc(timer);
    tin[v] := timer;
    pr[v] := p;
    h[v] := depth;
    u := fn[v];
    while u > 0 do
    begin
      t := ni[u];
      if t <> p then dfs(t, v, depth + 1);
      u := nn[u];
    end;
    tout[v] := timer;
  end;

  procedure GetPath(v : longint);
  var
     i, tt : longint;
  begin
    setlength(path, length(path) + 1);
    path[length(path) - 1] := v;
    if v = v0 then
    begin
      for i := 0 to (length(path) - 1) div 2 do
      begin
        tt := path[i]; path[i] := path[length(path) - 1 - i]; path[length(path) - 1 - i] := tt;
      end;
      exit;
    end;
    GetPath(pr[v]);
  end;

  procedure build(v, tl, tr : longint);
  var
     tm : longint;
  begin
    if tl = tr then
    begin
      t[v] := h[id[tl]];
      exit;
    end;
    tm := (tl + tr) shr 1;
    build(v shl 1, tl, tm);
    build(v shl 1 + 1, tm + 1, tr);
    t[v] := max(t[v shl 1], t[v shl 1 + 1]);
  end;

  function query(v, tl, tr, ll, rr : longint) : longint;
  var
    tm : longint;
  begin
    if ll > rr then
    begin
      query := -inf;
      exit;
    end;
    if (tl = ll) and (tr = rr) then
    begin
      query := t[v];
      exit;
    end;
    tm := (tl + tr) shr 1;
    query := max(query(v shl 1, tl, tm, ll, min(tm, rr)), query(v shl 1 + 1, tm + 1, tr, max(ll, tm + 1), rr));
  end;

begin
  reset(input, 'dwarfs.in');
  rewrite(output, 'dwarfs.out');
  randomize;
  readln(n);
  x := 0;
  for i := 1 to n - 1 do
  begin
    readln(a, b);
    AddEdge(a, b);
    AddEdge(b, a);
  end;
  readln(v0, u0);

  timer := 0;
  dfs(v0, 0, 0);
  for i := 1 to n do id[tin[i]] := i;
  GetPath(u0);
  build(1, 1, n);

  for i := 0 to length(path) - 1 do
  begin
    if i <> length(path) - 1 then pref[i] := max(query(1, 1, n, tin[path[i]], tin[path[i + 1]] - 1), query(1, 1, n, tout[path[i + 1]] + 1, tout[path[i]])) - h[path[i]]
                             else pref[i] := query(1, 1, n, tin[path[i]], tout[path[i]]) - h[path[i]];

    suf[i] := pref[i];
    pref[i] := pref[i] + h[path[i]];
    suf[i] := suf[i] - h[path[i]] + h[u0];
  end;
  mxp[0] := pref[0];
  for i := 1 to length(path) - 1 do mxp[i] := max(mxp[i - 1], pref[i]);
  mxs[length(path) - 1] := suf[length(path) - 1];
  for i := length(path) - 2 downto 0 do mxs[i] := max(mxs[i + 1], suf[i]);

  ans := 0;
  for i := 0 to length(path) - 2 do ans := max(ans, min(mxp[i], mxs[i + 1]));
  writeln(ans + 1);
end.
