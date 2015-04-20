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
    if (n < m) then
        x := n
    else
        x := m;
    if (n <> 1) and (m <> 1) then
        x := x + 2
    else
        if n = 1 then
            x := m + 2
        else
            x := n + 2;
    write(x div 4);
end.
