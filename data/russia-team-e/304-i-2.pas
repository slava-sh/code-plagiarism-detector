Const PROB = 'sochi';
{$OPTIMIZATION ON}
{$ifndef HOME}
    {$Q-}{$R-}
{$else}
    {$Q+}{$R+}
{$endif}

Var n, m, i, tmp, d, maxinp, sndmid, fstmid: LongInt;
    sum: Int64;
Begin
    {$ifndef HOME}
    Assign(input, PROB + '.in'); Reset(input);
    Assign(output, PROB + '.out'); Rewrite(output);
    {$endif}
    
    ReadLn(n, d);
    fstmid := 0;
    sndmid := 0;
    m := 0;
    sum := 0;
    maxinp := 0;
    for i:=1 to n do begin
        Read(tmp);
        if (tmp > 2 * d) and (tmp < 3 * d) then begin
            if tmp >= fstmid then begin
               sndmid := fstmid;
               fstmid := tmp;
            end else if tmp > sndmid then
                sndmid := tmp;
        end else if (tmp >= 3 * d) then begin
            Inc(m);
            Inc(sum, tmp);
        end;
        if tmp > maxinp then maxinp := tmp;
    end;
    
    if fstmid <> 0 then begin
        Inc(m);
        Inc(sum, fstmid);
    end;
    
    if sndmid <> 0 then begin
        Inc(m);
        Inc(sum, sndmid);
    end;
    
    if m = 0 then WriteLn(maxinp)
    else WriteLn(sum - 2 * d * (m - 1));
    
    Close(input); Close(output);
End.
