program qq;

var
  f, f1: text;
  a: array [1..2, 1..1000] of int64;
  l, r, x: array [1..1000] of integer;
  n, m, i, j: integer;

begin
  assign(f, 'dunes.in');
  reset(f);
  readln(f, n, m);
  for i := 1 to n do 
  begin
    readln(f, l[i], r[i], x[i]);
  end;
  for i := 1 to m do 
  begin
    readln(f, a[1, i]);
  end;
  close(f);
  for i := 1 to n do 
  begin
    for j := 1 to m do 
    begin
      if (a[1, j] >= l[i]) and (a[1, j] <= r[i]) then 
        if a[1, j] mod 2 = l[i] mod 2 then a[2, j] := a[2, j] + x[i] else a[2, j] := a[2, j] - x[i];
    end;
  end;
  assign(f1, 'dunes.out');
  rewrite(f1);
  for i := 1 to m do 
  begin
    writeln(f1, a[2, i]);
  end;
  close(f1);
end.