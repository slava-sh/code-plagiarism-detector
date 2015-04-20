var
  edges: array of array of longint;
  way, wayforward, wayback: array of longint;
  used: array of boolean;
  n, i, u0, v0, u, v, maxway: longint;

function min(a, b: longint): longint;
  begin
    if a < b then min := a else min := b;
  end;

function max(a, b: longint): longint;
  begin
    if a > b then max := a else max := b;
  end;

function dfs(w: longint): longint;
  var
    i, k, maxway: longint;
    center: boolean = false;
  begin
    maxway := 0;
    used[w] := true;
    for i := 0 to length(edges[w]) - 1 do
      if not used[edges[w, i]] then begin
        k := dfs(edges[w, i]);
        if k > maxway then maxway := k;
        if k = -1 then center := true;
      end;
    if w = u0 then center := true;
    if center then begin
      setlength(way, length(way) + 1);
      way[length(way) - 1] := maxway + 1;
      dfs := -1;
    end
    else dfs := maxway + 1;
  end;

begin
  assign(input, 'dwarfs.in');
  reset(input);
  assign(output, 'dwarfs.out');
  rewrite(output);
  read(n);
  setlength(edges, n);
  setlength(used, n);
  for i := 1 to n - 1 do begin
    read(u, v);
    dec(u); dec(v);
    setlength(edges[u], length(edges[u]) + 1);
    edges[u, length(edges[u]) - 1] := v;
    setlength(edges[v], length(edges[v]) + 1);
    edges[v, length(edges[v]) - 1] := u;
  end;
  read(v0, u0);
  dec(u0); dec(v0);
  dfs(v0);
  maxway := 1;
  setlength(wayforward, length(way));
  setlength(wayback, length(way));
  wayforward[0] := way[0];
  for i := 1 to length(way) - 1 do
    wayforward[i] := max(wayforward[i - 1], way[i] + i);
  wayback[length(way) - 1] := way[length(way) - 1];
  for i := length(way) - 2 downto 0 do
    wayback[i] := max(wayback[i + 1], way[i] + length(way) - i);
  for i := 0 to length(way) - 2 do
    maxway := max(maxway, min(wayforward[i], wayback[length(way) - 1 - i]));
  writeln(maxway);
end.