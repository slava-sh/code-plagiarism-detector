var
  k, x, n:integer;
  a: array[1..1000] of integer;
 begin
  assign(input, 'chess.in');
  assign(output, 'chess.out');
  readln(input,k);
  for x:=1 to k do
  begin
    read(input, a[x]);
  end;
  for x:=1 to k do
  begin
    n := n + 1;
    //writeln(output, x,' ', x);
    if (a[x+1] < x+1) then break;
  end;
  writeln(output, n);
  for x:=1 to n do
    writeln(output, x,' ', x);
  close(input);
  close(output);
end.