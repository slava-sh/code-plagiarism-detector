var
  a, b, i, n, x: longint;

begin
  assign(input, 'abcd.in');
  assign(output, 'abcd.out');
  reset(input);
  rewrite(output);

  readln(n);
  for i := 1 to n do
  begin
    read(x);
    a := (x - (x mod 100)) div 100;
    b := x mod 100;
    if (a * a + b * b) mod 7 = 1 then
    writeln('YES')
    else
    writeln('NO');
  end;
end.

  close(input);
  close(output);
end.