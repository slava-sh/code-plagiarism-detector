var
  s, sum, k, i, n: integer;
  a: array  [1..1000] of integer;
  c: array  [1..1000] of integer;

begin
  assign(input, 'conquest.in');
  reset(input);
  assign(output, 'conquest.out');
  rewrite(output);
  readln(n);
  sum := 0;
  for i := 1 to n do
    readln(a[i], c[i]);
    
  for i := 1 to n do
    sum := sum + a[i];
    
  k := 0;
  for i := n downto 1 do
  begin
    sum := sum - a[i];
    while (sum + k) <= a[i] do
    begin
      a[i] := a[i] - 1;
      s := s + c[i];
      k := k + 1;
    end;
  end;
  writeln(s);
end.