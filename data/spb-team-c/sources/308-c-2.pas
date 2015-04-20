var
  s, sum, k, i, n, j: int64;
  a: array  [1..10000] of int64;
  c: array  [1..10000] of int64;

begin
 assign(input, 'conquest.in');
  reset(input);
  assign(output, 'conquest.out');
  rewrite(output);
  readln(n);
  sum := 0;
  for i := 1 to n do
    readln(a[i], c[i]);
    for i:= 1 to n do
    for j:= 1 to n do
    begin
    if(a[j]=a[j+1]) and (c[j]> c[j+1])then 
    begin
    k:=c[j];
    c[j]:=c[j+1];
    c[j+1]:=k;
    end;
    end;
    
  for i := 1 to n do
    sum := sum + a[i];
  for i:=1 to n do 
  for j:=i to n do
  if (a[i]= a[j]) and (c[i]>c[j]) and(i < j) then
  begin
  k:=c[i];
  c[i]:=c[j];
  c[j]:=k;
  end;
    
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