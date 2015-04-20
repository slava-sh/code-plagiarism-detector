program b;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
    n, r, i, l, d :longint;
    s :int64;
    a :array[1..301000] of longint;

begin
    reset(input, 'che.in');
    rewrite(output, 'che.out');
    read(n, d);
    for i := 1 to n do
        read(a[i]);
    s := 0;
    for i := 1 to n - 1 do
        begin
            l := i + 1;
            r := n;
            while l < r do
                if a[(l+r) div 2] - a[i] > d then
                    r := (l+r) div 2
                else
                    l := (l+r) div 2 + 1;
            if a[(l+r) div 2] - a[i] > d then
                s := s + n - l + 1;
        end;
    write(s);
end.
 