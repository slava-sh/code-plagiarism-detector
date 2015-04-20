Const PROB = 'prizes';
{$OPTIMIZATION ON}
{$ifndef HOME}
    {$Q-}{$R-}
{$else}
    {$Q+}{$R+}
{$endif}

Var n, m: LongInt;
Begin
    {$ifndef HOME}
    Assign(input, PROB + '.in'); Reset(input);
    Assign(output, PROB + '.out'); Rewrite(output);
    {$endif}
    
    ReadLn(n, m);
    if (n = 1) or (m = 1) then WriteLn((n + m) div 4)
    else WriteLn(1);
    
    Close(input); Close(output);
End.
