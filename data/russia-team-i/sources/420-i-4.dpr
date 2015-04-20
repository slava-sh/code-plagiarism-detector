{$APPTYPE CONSOLE}

uses
  SysUtils;

var
    n, d, i, x, max1, max2, max :longint;
    s :int64;

begin
    reset(input, 'sochi.in');
    rewrite(output, 'sochi.out');
    read(n, d);
    s := 0; max1 := 0; max2 := 0; max := 0;
    for i := 1 to n do
        begin
            read(x);
            if x > max then
                max := x;
            if x >= 3*d then
                s := s + x - 2*d
            else if (x >= 2*d) then
                if x > max1 then
                    begin
                        max2 := max1;
                        max1 := x - d;
                    end
                else if x > max2 then
                    max2 := x - d;
        end;
if s <> 0 then
  begin
    if max1 = 0 then
        s := s + 2*d
    else if max2 = 0 then
        s := s + d;
    s := s + max1 + max2;
  end
else
    begin
    s := max1 + max2;

if (s = 0) or (max1 + max2 < max) or (max2 = 0) then
 s := max;
end;
    if s < max then
    s := max;
    writeln(s);
end.
