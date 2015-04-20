var
  mas: array[1..100000000] of integer;
  l: array [1..1000] of integer;
  r: array [1..1000] of integer;
  x: array [1..1000] of integer;
  q: array [1..1000] of integer;
  i, j, n, m: integer;
  f1: text;

begin
  assign(f1, 'dunes.in');
  reset(f1);
  readln(f1, n, m);
  for i := 1 to n do
    readln(f1, l[i], r[i], x[i]);
  for i := 1 to m do 
    readln(f1, q[i]);
     close(f1);
  
  for i := 1 to n do 
  begin
    j := l[i];
    while(j <= r[i]) do 
    begin 
      mas[j] := mas[j] + x[i];
     if(j<r[i]) then   
      mas[j + 1] := mas[j + 1] - x[i];
      j := j + 2;
    end;
  end;
 
  
  assign(f1, 'dunes.out');
  rewrite(f1);
  for i := 1 to m do
    writeln(f1, mas[q[i]]);
  close(f1);
end.