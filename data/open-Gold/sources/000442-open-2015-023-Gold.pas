{$O+}
program problemGold;
uses math;

var	x: array[ 1..200000 ] of longInt;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l >= r ) then
		exit();
	
	i := l;
	j := r;
	med := x[ l + random(r - l + 1) ];
	while ( i <= j ) do
	begin
		while ( x[i] > med ) do
			inc( i );
			
		while ( x[j] < med ) do
			dec( j );
		
		if ( i <= j ) then
		begin
			t := x[i];
			x[i] := x[j];
			x[j] := t;
			
			inc( i );
			dec( j );
		end;
	end;
	
	qsort( l, j );
	qsort( i, r );
end;

var	n, k, c, d, i, j: longInt;
	a, b: array[ 1..200000 ] of longInt;
	ans, cur: int64;

begin
	readln( n, k, c, d );
	for i := 1 to n do
		readln( a[i], b[i] );
	
	for i := 2 to n do
		x[i - 1] := a[i] - b[i - 1];
	
	qsort( 1, n - 1 );
	
	ans := int64( b[n] - a[1] ) * d;
	
	for i := 1 to min( n, k ) - 1 do
		dec( ans, x[i] * int64(d) );
	
	i := min( n, k ) - 1;
	while ( i < n - 1 ) do
	begin
		cur := 0;
		for j := i + 1 to min( i + k, n ) do
			inc( cur, x[j] );
		
		cur := cur * d;
		if ( cur > c ) then
			dec( ans, cur - c );
		
		inc( i, k );
	end;
	
	writeln( ans );
end.

