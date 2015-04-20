uses Math;
var
  m, n: longint;
begin
  assign(input, 'prizes.in');
  assign(output, 'prizes.out');
  reset(input);
  rewrite(output);
  read(m, n);
  case min(m, n) of
    1: if max(m, n) <= 2 then write(0) else write(1 + (max(m, n) - 3) div 4);
    2: write(0)
    else write((min(m, n) - 3) div 4 + 1);
  end;
  close(input);
  close(output);
end.