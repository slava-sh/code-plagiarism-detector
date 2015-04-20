var
  i, n, x, j: longint;

begin
  assign(input, 'chess.in');
  assign(output, 'chess.out');
  reset(input);
  rewrite(output);

  read(n);
  i := 0;
  read(x);
  while i < x do
  begin
    read(x);
    inc(i);
  end;
  writeln(i);
  for j := 1 to i do
  writeln(j, ' ', j);


  close(input);
  close(output);
end.
