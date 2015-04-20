program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, m, i, mini, tmp1, tmp2, tmp3, j: integer;
  d, p, t: array[-1..6000] of integer;
  a: array[-1..5001, -1..5001] of integer;
  vis: array[-1..10000] of boolean;

begin
  reset(input, 'secure.in');
  rewrite(output, 'secure.out');

  readln(n, m);
  for i := 1 to n do begin
    read(t[i]);
  end;

  for i := 1 to n do
    for j := 1 to n do
      a[i][j] := maxint div 3;

  for i := 1 to m do begin
    readln(tmp1, tmp2, tmp3);
    a[tmp1][tmp2] := tmp3;
    a[tmp2][tmp1] := tmp3;    
  end;

  for i := 1 to n do
    d[i] := maxint;

  for i := 1 to n do begin
    if t[i] = 2 then
      d[i] := 0;
  end;

  while true do begin
    mini := -1;
    for i := 1 to n do
      if not vis[i] then begin
        if (mini = -1) or (d[mini] > d[i]) then
          mini := i;
      end;

    if (mini = -1) or (d[mini] > n * 100001) then break;
    vis[mini] := true;
    if t[mini] = 1 then begin
      while t[p[mini]] <> 2 do p[mini] := p[p[mini]];
      writeln(mini, ' ', p[mini], ' ', d[mini]);
      halt;
    end;

    for i := 1 to n do
      if d[i] > d[mini] + a[mini][i] then begin
        d[i] := d[mini] + a[mini][i];
        p[i] := mini;
      end;
  end;

  writeln(-1);
end.
