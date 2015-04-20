program qq;

var
  f, f1: text; 
  n, s, i, k, a, t: uint64;

var
  D: array [1..100000] of uint64;

begin
  assign(f, 'merlin.in'); 
  assign(f1, 'merlin.out'); 
  reset(f); 
  rewrite(f1); 
  readln(f, n);
  for i := 1 to n do 
  begin
    read(f, a);
    k := a + k;
    D[i] := a;
  end;
  s := k div n;
  for i := 1 to n do 
  begin
    if D[i] > s then t += 1;
  end;
  writeln(f1, t);
  close(f);  
  close(f1); 
end.