var
  ans, was: array[0..100000] of boolean;
  a, am: array[0..100000] of longint;
  b, j, m, n, t, mincost, z, k, i: longint;
begin

  read(t);


  for z := 1 to t do
  begin
  read(m, n);
  for i := 1 to n do
   read(am[i]);

  mincost := 1000000009;
  j := 0;
  k := 0;
  fillchar(ans, sizeof(ans),0);
  fillchar(was, sizeof(was),0);



  for i := 1 to m-1 do
  begin
    read(a[i], b);
    if (j = 0) and (b=1) then j := i;
  end;


  if j <> 0 then
  begin

    for i := m - 1 downto j do
      was[a[i]] := true;
    for i := 1 to j-1 do
      if a[i] = 0 then inc(k)
      else dec(am[a[i]]);

    for i := 1 to n do
      if (am[i] <= k)and(was[i] = false) then
      begin
         ans[i] := true;
         if am[i] < mincost then mincost := am[i];
      end;

    k := k - mincost;
    for i := j to m - 1 do
      if a[i] = 0 then inc(k)
      else dec(am[a[i]]);



  end
  else
    for i := 1 to m-1 do
      if a[i] = 0 then inc(k)
      else dec(am[a[i]]);

  for i := 1 to n do
      if am[i] <= k then
         ans[i] := true;

  for i := 1 to n do
   if ans[i] then write('Y') else write('N');
  writeln;
  end;


end.