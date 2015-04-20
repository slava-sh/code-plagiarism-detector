program qq;

var
  f, f1: text; 
  n, i, k, a, t: uint64;
  s, g: real;

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
  s := k / n;
  g := Frac(s);
  if g < 0.5 then begin
    for i := 1 to n do 
    begin
      if D[i] > s then t += 1;
    end;
  end
  else
    for i := 1 to n do 
    begin
      if D[i] < s then t += 1;
    end;
  writeln(f1, t);
  close(f);
  close(f1); 
end.