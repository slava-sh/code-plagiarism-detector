program g;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
    n, m, x, s :longint;

begin
    reset(input, 'prizes.in');
    rewrite(output, 'prizes.out');
    read(n, m);
    if (n < m) then
        x := n
    else
        x := m;
    if n = 1 then
        x := m
    else if m = 1 then
      x := n;
    if x > 2 then
        s := 1;
    x := x - 3;
    s := s + x div 4;
    write(s);
end.
