program D;

var
  f1, f2: text;
  n, m, nc, mc, i, j: cardinal;
  dune: array[1..2,1..1000] of integer;
  wind: array[1..3,1..1000] of cardinal;
begin
  assign(f1, 'dunes.in');
  assign(f2, 'dunes.out');
  reset(f1);
  readln(f1,n,m);
  for nc:=1 to n do begin
    readln(f1,wind[1,nc],wind[2,nc],wind[3,nc]);
  end;
  for mc:=1 to m do begin
    readln(f1,dune[1,mc]);
  end;
  close(f1);
  for i:=1 to 1000 do begin
    for j:=1 to m do begin
      if (dune[1,j]>=wind[1,i]) and (dune[1,j]<=wind[2,i]) then begin
        if (dune[1,j]-wind[1,i]) mod 2 = 0 then dune[2,j]:=dune[2,j]+wind[3,i] else dune[2,j]:=dune[2,j]-wind[3,i];
      end;
    end;
  end;
  rewrite(f2);
  i:=1;
  for j:=1 to m do begin
    writeln(f2,dune[2,j]);
  end;
  close(f2);
end.