Const PROB = 'sochi';
{$OPTIMIZATION ON}
{$ifndef HOME}
    {$Q-}{$R-}
{$else}
    {$Q+}{$R+}
{$endif}

Var n, m, i, tmp, d: LongInt;
    sum: Int64;
Begin
    {$ifndef HOME}
    Assign(input, PROB + '.in'); Reset(input);
    Assign(output, PROB + '.out'); Rewrite(output);
    {$endif}
    
    ReadLn(n, d);
    m := 0;
    sum := 0;
    for i:=1 to n do begin
        Read(tmp);
        if (tmp > 2 * d) then begin
            Inc(m);
            Inc(sum, tmp);
        end;
    end;
    
    if m = 0 then WriteLn(0)
    else WriteLn(sum - 2 * d * (m - 1));
    
    Close(input); Close(output);
End.
