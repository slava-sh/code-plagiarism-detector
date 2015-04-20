var
  n, m, a: longint;
begin
  assign(input, 'prizes.in');
  reset(input);
  assign(output, 'prizes.out');
  rewrite(output);
  read(n, m);
  if n > m
    then begin
      a := n;
      n := m;
      m := a;
    end;
  if n = 1
    then writeln((m + 1) div 4)
    else if n = 2
           then writeln(0)
           else writeln(1);
end.