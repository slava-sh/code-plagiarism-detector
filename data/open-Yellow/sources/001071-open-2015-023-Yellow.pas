program porblemYellow;

var	t: array[ 0..200000 ] of longInt;

function f( l, r: longInt ): longInt;
var	i, res: longInt;
begin
	res := 1;
	for i := l + 1 to r do
		if ( t[i] <> t[i - 1] ) then
			inc( res );
	
	exit( res );
end;

var	n, m, i, p, x, ans: longInt;

begin
	readln( n );
	for i := 1 to n do
		read( t[i] );
		
	t[0] := 1000000001;
	t[n + 1] := 1000000001;
	
	ans := f( 1, n );
	
	readln( m );
	for i := 1 to m do
	begin
		readln( p, x );
		
		dec( ans, f( p - 1, p + 1 ) );
		
		t[p] := x;
		
		inc( ans, f( p - 1, p + 1 ) );
		
		writeln( ans );
	end;
end.
