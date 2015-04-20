program Project2;

{$APPTYPE CONSOLE}

var
  Inp, Outp: TextFile;
  j, V, P, l1, r1, l2, r2, n, m, a, b: integer;
  mass: array of integer;

procedure Petya;
var i, flag, g: integer;
begin
  i:=0;
  flag:=0;
  while (i<=n-1) do
  begin
    g:=mass[i];
    if (a<=g) and (g<=b) then
    begin
      P:=P+1;
      mass[i]:=-1;
      flag:=1;
      break;
    end else
      inc(i);
  end;
  i:=0;
  if (flag=0) then
  begin
  while (i<=n-1) do
  begin
    g:=mass[i];
    if (g>=l1) and (g<=r1) and (g<>-1) then
    begin
      P:=P+1;
      mass[i]:=-1;
      flag:=1;
      break;
    end else
      inc(i);
  end;
  end;
end;

procedure Vasya;
var i, flag, g: integer;
begin
  i:=0;
  flag:=0;
  while (i<=n-1) do
  begin
    g:=mass[i];
    if (a<=g) and (g<=b) then
    begin
      V:=V+1;
      mass[i]:=-1;
      flag:=1;
      break;
    end else
      inc(i);
  end;
  i:=0;
  if (flag = 0) then
  begin
  while (i<=n-1) do
  begin
    g:=mass[i];
    if (g>=l2) and (g<=r2) and (g<>-1) then
    begin
      V:=V+1;
      mass[i]:=-1;
      flag:=1;
      break;
    end else
      inc(i);
  end;
  end;
end;

begin
  AssignFile(inp, 'game.in');
  Reset(Inp);
  AssignFile(outp, 'game.out');
  rewrite(outp);
  readln(inp, n, m);
  readln(inp, l1, r1);
  readln(inp, l2, r2);
  setlength(mass, n);
  for j:=0 to n-1 do
    read(inp, mass[j]);
  b:=r1;
  a:=l2;
  P:=0;
  V:=0;
  for j:=0 to m-1 do
  begin
    if (j mod 2 = 0) then
      Petya
    else
      Vasya;
  end;
  if (P>V) then
    write(outp, 'Petya');
  if (P<V) then
    write(outp, 'Vasya');
  if (P=V) then
    write(outp, 'Draw');
  closeFile(inp);
  closeFile(outp);
end.
