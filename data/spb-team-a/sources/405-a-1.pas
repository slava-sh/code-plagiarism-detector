Var
  x, t: integer;
  abcd: integer;
  ab, cd: integer;
begin
  assign(input, 'abcd.in');
  assign(output, 'abcd.out');
  reset(input);
  rewrite(output);
  readln(input, t);
  for x:=1 to t do
  begin
    readln(input, abcd);
    ab:=abcd div 100;
    cd:=abcd mod 100;
    if (((sqr(ab) + sqr(cd) - 1) mod 7) = 0) then
      writeln(output, 'YES')
    else
      writeln(output, 'NO');
  end;
  close(input);
  close(output);
end.