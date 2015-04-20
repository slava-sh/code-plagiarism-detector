program rook_fill;

var
  f1, f2: text;
  n, m, i: integer;
  board: array[1..1000] of integer;

begin
  assign(f1, 'chess.in');
  assign(f2, 'chess.out');
  reset(f1);
  readln(f1, m);
  for i := 1 to 1000 do 
  begin
    board[i] := 0;
  end;
  for i := 1 to m do 
  begin
    read(f1, board[i]);
  end;
  n := 1;
  while board[n] >= n do
    n += 1;
  close(f1);
  rewrite(f2);
  writeln(f2, n - 1);
  for i := 1 to n - 1 do 
  begin
    writeln(f2, i, ' ', i);
  end;
  close(f2);
end.