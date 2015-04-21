program problemOlive;
uses math;

const	MAGIC = 300;

var	fwt: array[ 1..200000 ] of longInt;
	n: longInt;

procedure fwt_update( x, d: longInt );
begin
	while ( x <= n ) do
	begin
		inc( fwt[x], d );
	
		inc( x, x and -x );
	end;
end;

function fwt_sum( x: longInt ): longInt;
var	res: longInt;
begin
	res := 0;
	while ( x > 0 ) do
	begin
		inc( res, fwt[x] );
	
		dec( x, x and -x );
	end;
	
	exit( res );
end;

var	i, j, l, r: longInt;
	a: array[ 1..200000 ] of longInt;
	ans, cur: int64;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
	
	ans := 0;
	l := -1;
	r := -1;
	
	for i := 1 to min( n, MAGIC ) do
	begin
		fillchar( fwt, 4 * n, 0 );
		
		fwt_update( a[i], +1 );
		
		for j := i + 1 to n do
		begin
			fwt_update( a[j], +1 );
			
			cur := fwt_sum( a[i] - 1 ) + fwt_sum( n ) - fwt_sum( a[j] ) - (j - i);
			
			if ( cur > ans ) then
			begin
				ans := cur;
				l := i;
				r := j;
			end;
		end;
	end;
	
	for i := 1 to n do
	begin
		fwt_update( a[i], +1 );
		
		for j := i + 1 to min( n, i + MAGIC ) do
		begin
			fwt_update( a[j], +1 );
			
			cur := fwt_sum( a[i] - 1 ) + fwt_sum( n ) - fwt_sum( a[j] ) - (j - i);
			
			if ( cur > ans ) then
			begin
				ans := cur;
				l := i;
				r := j;
			end;
		end;
		
		for j := i to min( n, i + MAGIC ) do
			fwt_update( a[j], -1 );
	end;
	
	for j := max( 1, n - MAGIC ) to n do
	begin
		fillchar( fwt, 4 * n, 0 );
		
		fwt_update( a[j], +1 );
		
		for i := j - 1 downto 1 do
		begin
			fwt_update( a[i], +1 );
			
			cur := fwt_sum( a[i] - 1 ) + fwt_sum( n ) - fwt_sum( a[j] ) - (j - i);
			
			if ( cur > ans ) then
			begin
				ans := cur;
				l := i;
				r := j;
			end;
		end;
	end;
	
	writeln( l, ' ', r );
end.
