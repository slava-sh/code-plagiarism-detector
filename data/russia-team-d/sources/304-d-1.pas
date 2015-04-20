uses math;

Const PROB = 'fence';
{$OPTIMIZATION ON}
{$ifndef HOME}
    {$Q-}{$R-}
{$else}
    {$Q+}{$R+}
{$endif}

var a: array[ 1..100000 ] of longInt;

procedure qsort( l, r: longInt );
var i, j, t, med: longInt;
begin
    if ( l < r ) then
    begin
        i := l;
        j := r;
        med := a[ l + random(r-l+1) ];
        while ( i <= j ) do
        begin
            while ( a[i] < med ) do
                inc( i );
            while ( a[j] > med ) do
                dec( j );
                
            if ( i <= j ) then
            begin
                t := a[i];
                a[i] := a[j];
                a[j] := t;
                
                inc( i );
                dec( j );
            end;
        end;
        
        qsort( l, j );
        qsort( i, r );
    end;
end;

var n, i, l, r, c, k: longInt;
    p: int64;

Begin
    {$ifndef HOME}
    Assign(input, PROB + '.in'); Reset(input);
    Assign(output, PROB + '.out'); Rewrite(output);
    {$endif}
    
    readln( n, k );
    for i := 1 to n do
        read( a[i] );
        
    qsort( 1, n );
    
    l := 0;
    r := a[1];
    while ( l < r ) do
    begin
        c := ( l + r + 1 ) div 2;
        
        p := 0;
        for i := 1 to n do
            p := max( a[i], p + c );
            
        if ( p > k ) then
            r := c - 1
        else
            l := c;
    end;
    
    writeln( l );
    
    Close(input); Close(output);
End.
