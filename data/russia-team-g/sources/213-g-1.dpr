program GGGGGGGGG;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var a,b,c,d,i,j,k,m,n,res: integer;
begin
    reset(input,'prizes.in');
    rewrite(output,'prizes.out');
    read(n,m);
    if (n = 2) or (m = 2) then
    begin
        res := 0;
        writeln(res);
        exit;
    end;
    if (n = 1) and (m = 1) then
    begin
        res := 0;
        writeln(res);
        exit;
    end;
    if n = 1 then
    begin
        res := (m+1) div 4;
        writeln(res);
        exit;
    end;

    if m = 1 then
    begin
        res := (n + 1) div 4;
        writeln(res);
        exit;
    end;
    k := min(n,m);
    res := (k+1) div 4;
    writeln(res);
    readln;
    readln;
end.
