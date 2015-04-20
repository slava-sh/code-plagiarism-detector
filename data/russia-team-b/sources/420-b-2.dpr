program b;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
    n, r, i, s, j :longint;
    a :array[1..301000] of longint;

begin
    reset(input, 'che.in');
    rewrite(output, 'che.out');
    read(n, r);
    for i := 1 to n do
        read(a[i]);
    s := 0;
    for i := 1 to n - 1 do
        begin
            j := i + 1;
            while (a[j] - a[i] <= r) and (j <= n) do
                inc(j);
            s := s + n - j + 1;
        end;
    write(s);
end.
 