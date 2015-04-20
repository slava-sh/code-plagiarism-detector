uses math;

Const PROB = 'dwarfs';

{$OPTIMIZATION ON}
{$ifndef HOME}
    {$Q-}{$R-}
{$else}
    {$Q+}{$R+}
{$endif}

type    tEdge = record
                    v, next: longInt;
                end;
                
var first, p, d, fDown, sDown, up, dp: array[ 1..200000 ] of longInt;
    e: array[ 1..500000 ] of tEdge;
    ee: longInt = 0;
    
procedure addEdge( u, v: longInt );
begin
    inc( ee );
    e[ee].v := v;
    e[ee].next := first[u];
    first[u] := ee;
end;

procedure init( v, par, dep: longInt );
var i: longInt;
begin
    d[v] := dep;
    p[v] := par;
    
    fDown[v] := 0;
    sDown[v] := 0;
    
    i := first[v];
    while ( i > 0 ) do
    begin
        if ( e[i].v <> p[v] ) then
        begin
            init( e[i].v, v, d[v] + 1 );
            
            if ( fDown[ e[i].v ] + 1 > fDown[v] ) then
            begin
                sDown[v] := fDown[v];
                fDown[v] := fDown[ e[i].v ] + 1;
            end
            else if ( fDown[ e[i].v ] + 1 > sDown[v] ) then
                sDown[v] := fDown[ e[i].v ] + 1;
        end;
    
        i := e[i].next;
    end;
end;

procedure initUp( v: longInt );
var i: longInt;
begin
    up[v] := 0;
    
    if ( p[v] > 0 ) then
    begin
        up[v] := up[ p[v] ] + 1;
        if ( fDown[ p[v] ] = fDown[v] + 1 ) then
            up[v] := max( up[v], sDown[ up[v] ] + 1 )
        else
            up[v] := max( up[v], fDown[ up[v] ] + 1 );
    end;
    
    i := first[v];
    while ( i > 0 ) do
    begin
        if ( e[i].v <> p[v] ) then
            initUp( e[i].v );
    
        i := e[i].next;
    end;
end;

var n, i, j, u, v, ans: longInt;

Begin
    {$ifndef HOME}
    Assign(input, PROB + '.in'); Reset(input);
    Assign(output, PROB + '.out'); Rewrite(output);
    {$endif}
    
    fillchar( first, sizeOf(first), 0 );
    
    readln( n );
    for i := 1 to n - 1 do
    begin
        readln( u, v );
        
        addEdge( u, v );
        addEdge( v, u );
    end;
    
    readln( u, v );
    
    init( u, 0, 1 );
    initUP( u );
    
    ans := 1;
    dp[v] := fDown[v] + 1;
    
    j := v;
    i := p[v];
    while ( i <> 0 ) do
    begin
        dp[i] := dp[j];
        if ( fDown[i] = fDown[j] + 1 ) then
        begin
            dp[i] := max( dp[i], d[v] - d[i] + 1 + sDown[i] );
            
            ans := max( ans, min( dp[j], d[i] + sDown[i] ) );
        end
        else
        begin
            dp[i] := max( dp[i], d[v] - d[i] + 1 + fDown[i] );
            
            ans := max( ans, min( dp[j], d[i] + fDown[i] ) );
        end;
            
        j := i;
        i := p[i];
    end;
    
    writeln( ans );
    
    Close(input); Close(output);
End.
