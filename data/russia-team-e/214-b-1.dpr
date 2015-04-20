program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
    n, k, l, r, i: integer;
    ans: int64;
    a: array [0 .. 400000] of integer;
begin
    reset(input, 'che.in');
    rewrite(output, 'che.out');
    readln(n, k);
    for i := 1 to n do
        read(a[i]);
    r := 1;
    ans := 0;
    for l := 1 to n do
    begin
        while (r < l) and (a[l] - a[r] > k) do
            inc(r);
        ans := ans + r - 1;
    end;
    writeln(ans);
    readln;
    readln;
end.
 