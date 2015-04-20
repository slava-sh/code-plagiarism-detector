Const PROB = 'virus';
{$OPTIMIZATION ON}
{$ifndef HOME}
    {$Q-}{$R-}
{$else}
    {$Q+}{$R+}
{$endif}

var l, r: longInt;
    f: array[ 0..101, 0..101 ] of char;
    s: array[ 1..1000000, 0..1 ] of longInt;
    
procedure add( x, y: longInt );
begin
    inc( r );
    s[r][0] := x;
    s[r][1] := y;
end;
    
function calc( t: longInt ): longInt;
var x, y, tmpR, tmpL, res: longInt;
begin
    tmpR := r;
    tmpL := l;

    if ( t = 0 ) then
        exit( 1 );

    while ( l <= r ) and ( f[ s[l][0] ][ s[l][1] ] <> '.' ) do
        inc( l );
        
    if ( l > r ) then
        exit( 0 );
        
    x := s[l][0];
    y := s[l][1];
    inc( l );
    
    f[x][y] := '*';
    if ( f[x-1][y] = '.' ) then
        add( x - 1, y );

    if ( f[x+1][y] = '.' ) then
        add( x + 1, y );

    if ( f[x][y-1] = '.' ) then
        add( x, y - 1 );

    if ( f[x][y+1] = '.' ) then
        add( x, y + 1 );
        
    res := calc( t - 1 );
    
    r := tmpR;
    f[x][y] := '#';
    
    inc( res, calc( t ) );
    
    l := tmpL;
    r := tmpR;
    f[x][y] := '.';
    
    exit( res );
end;

var n, m, t, i, j: longInt;

Begin
    {$ifndef HOME}
    Assign(input, PROB + '.in'); Reset(input);
    Assign(output, PROB + '.out'); Rewrite(output);
    {$endif}
    
    fillchar( f, sizeOf(f), '#' );
    
    readln( n, m, t );
    for i := 1 to n do
    begin
        for j := 1 to m do
            read( f[i][j] );
            
        readln();
    end;
    
    l := 1;
    r := 0;
    
    for i := 1 to n do
        for j := 1 to m do
            if ( f[i][j] = '.' ) and ( ( f[i-1][j] = '*' ) or ( f[i+1][j] = '*' ) or ( f[i][j-1] =  '*' ) or ( f[i][j+1] = '*' ) ) then
                add( i, j );
            
    writeln( calc( t ) );
    
    Close(input); Close(output);
End.
