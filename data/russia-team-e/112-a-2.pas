const
  BIGMOD = 1000000007;

var
  edges: array of array of longint;
  antiedges: array of array of longint;
  part, used: array [0..1000] of boolean;
  z: array [0..1000] of longint;
  n, i, j, k, p: longint;
  check: boolean;

procedure dfs(v: longint);
  var
    i: longint;
  begin
    used[v] := true;
    for i := 0 to length(edges[v]) - 1 do
      if not used[edges[v, i]] then begin
        part[edges[v, i]] := part[v];
        dfs(edges[v, i]);
      end;
    for i := 0 to length(antiedges[v]) - 1 do
      if not used[antiedges[v, i]] then begin
        part[antiedges[v, i]] := not part[v];
        dfs(antiedges[v, i]);
      end;
  end;

begin
  assign(input, 'binary.in');
  reset(input);
  assign(output, 'binary.out');
  rewrite(output);
  read(n);
  setlength(edges, n);
  setlength(antiedges, n);
  for i := 0 to n - 1 do used[i] := false;
  for i := 0 to n - 1 do begin
    read(z[i]);
    if i + z[i] > n then begin
      writeln(0);
      exit;
    end;
  end;
  if z[0] > 0 then begin
    writeln(0);
    exit;
  end;
  for i := 1 to n - 1 do
    if z[i] >= 0 then begin
      for j := 0 to z[i] - 1 do begin
        setlength(edges[j], length(edges[j]) + 1);
        edges[j, length(edges[j]) - 1] := i + j;
        setlength(edges[i + j], length(edges[i + j]) + 1);
        edges[i + j, length(edges[i + j]) - 1] := j;
        end;
      if i + z[i] < n
        then begin
          setlength(antiedges[j], length(antiedges[j]) + 1);
          antiedges[j, length(antiedges[j]) - 1] := i + j;
          setlength(antiedges[i + j], length(antiedges[i + j]) + 1);
          antiedges[i + j, length(antiedges[i + j]) - 1] := j;
        end;
    end;
  k := 0;
  for i := 0 to n - 1 do
    if not used[i] then begin
      dfs(i);
      inc(k);
    end;
  check := true;
  for i := 0 to n - 1 do begin
    for j := 0 to length(edges[i]) - 1 do
      check := check and (part[edges[i, j]] = part[i]);
    for j := 0 to length(antiedges[i]) - 1 do
      check := check and (part[antiedges[i, j]] = not part[i]);
  end;
  if check then begin
    p := 1;
    for i := 1 to k do
      p := (2 * p) mod BIGMOD;
    writeln(p);
  end
  else writeln(0);
end.
