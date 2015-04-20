program g;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
    n, m, x :longint;

begin
    reset(input, 'prizes.in');
    rewrite(output, 'prizes.out');
    read(n, m);
    if ((n < m) and (n <> 1)) or (m = 1) then
        x := n
    else
        x := m;
    x := x + 2;
    write(x div 4);
end.
