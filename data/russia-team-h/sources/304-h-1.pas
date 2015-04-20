uses math;

Const PROB = 'secure';
      inf: int64 = trunc( 1.0e+15 );
{$OPTIMIZATION ON}
{$ifndef HOME}
    {$Q-}{$R-}
{$else}
    {$Q+}{$R+}
{$endif}

var n, m, i, j, u, v, c: longInt;
    e: array[ 1..5000, 1..5000 ] of longInt;
    used: array[ 1..5000 ] of boolean;
    d, start: array[ 1..5000 ] of int64;
    a: array[ 1..5000 ] of longInt;
    ans: int64;

Begin
    {$ifndef HOME}
    Assign(input, PROB + '.in'); Reset(input);
    Assign(output, PROB + '.out'); Rewrite(output);
    {$endif}
    
    readln( n, m );
    
    for i := 1 to n do
        read( a[i] );
    
    for i := 1 to n do
        for j := 1 to n do
            e[i][j] := -1;
    
    for i := 1 to m do
    begin
        readln( u, v, c );
        
        e[u][v] := c;
        e[v][u] := c;
    end;
    
    for i := 1 to n do
        d[i] := inf;
    
    for i := 1 to n do
        if ( a[i] = 1 ) then
        begin
            used[i] := true;
            
            d[i] := 0;
            start[i] := i;
            for j := 1 to n do
                if ( e[i][j] > -1 ) and ( e[i][j] < d[j] ) then
                begin
                    d[j] := e[i][j];
                    start[j] := i;
                end;
        end
        else
            used[i] := false;
            
    while ( true ) do
    begin
        i := 1;
        while ( i <= n ) and ( used[i] or (d[i] = inf) ) do
            inc( i );
            
        if ( i > n ) then
            break;
        
        u := i;
        for i := 1 to n do
            if ( not used[i] ) and ( d[i] < d[u] ) then
                u := i;
                
        used[u] := true;
        for i := 1 to n do
            if ( e[u][i] > -1 ) and ( d[u] + e[u][i] < d[i] ) then
            begin
                d[i] := d[u] + e[u][i];
                start[i] := start[u];
            end;
    end;
    
    ans := inf;
    for i := 1 to n do
        if ( a[i] = 2 ) and ( d[i] < ans ) then
        begin
            ans := d[i];
            u := start[i];
            v := i;
        end;
        
    if ( ans = inf ) then
        writeln( -1 )
    else
        writeln( u, ' ', v, ' ', ans );
    
    Close(input); Close(output);
End.
