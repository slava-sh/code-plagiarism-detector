var n, m, d : longint;
begin
    Assign(input,'prizes.in'); reset(input);
    Assign(output,'prizes.out'); rewrite(output);
    Readln(n,m);
    if n > m then begin
        d:=n; n:=m; m:=d;
    end;
    if n=1 then begin
        Writeln((m+1) div 4);
    end else begin
        Writeln((n+1) div 4);
    end;
    Close(input); Close(output);
end.
