var
  k,a,i:integer;
  //ans: array [1..1000,1..2] of integer;
begin
  assign(input, 'chess.in');
  assign(output, 'chess.out');
  readln(input,k);
  read(input,a);
  i:=0;
  while (a>=i) and (i<=k) do
  begin
  i:=i+1;
  read(input,a);
  //writeln(output, i, ' ', i);
  end;
  writeln(output, i);
  for k:=1 to i do
  writeln(output, k, ' ', k);
  close(input);
  close(output);
end.