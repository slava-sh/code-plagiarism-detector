Const PROB = 'che';
      MAXN = 300000;
{$OPTIMIZATION ON}
{$ifndef HOME}
    {$Q-}{$R-}
{$else}
    {$Q+}{$R+}
{$endif}

Var n, d, r, i: LongInt;
    a: Array[1..MAXN] of LongInt;
    res: Int64;
Begin
    {$ifndef HOME}
    Assign(input, PROB + '.in'); Reset(input);
    Assign(output, PROB + '.out'); Rewrite(output);
    {$endif}
    
    ReadLn(n, d);
    for i:=1 to n do Read(a[i]);
    
    res := 0;
    r := 1;
    for i:=1 to n do begin
        if r < i then r := i;
        while (r <= n) and (a[r] - a[i] <= d) do Inc(r);
        Inc(res, n - r + 1);
    end;
    
    WriteLn(res);
    
    Close(input); Close(output);
End.
