program cyan_brute;
uses math;

function cross_product( x0, y0, x1, y1, x2, y2: int64 ): int64;
begin
	exit( (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0) );
end;

function compareSegmentsAtX( x1, y1, x2, y2, x3, y3, x4, y4, x: longInt ): longInt;
var	yy1, yy2: extended;
begin
	yy1 := y1 + ( (y2 - y1) * int64(x - x1) ) / (x2 - x1);
	yy2 := y3 + ( (y4 - y3) * int64(x - x3) ) / (x4 - x3);
	
	if ( abs(yy1 - yy2) < 1.0e-8 ) then
		exit( 0 )
	else if ( yy1 > yy2 ) then
		exit( -1 )
	else
		exit( 1 );
end;

function intersects( x1, y1, x2, y2, x3, y3, x4, y4: longInt ): boolean;
var	vx, vy, ux, uy, a, b: int64;
begin
	if ( cross_product( x1, y1, x2, y2, x3, y3 ) = 0 ) then
		exit( false );

	if ( cross_product( x1, y1, x2, y2, x4, y4 ) = 0 ) then
		exit( false );

	if ( cross_product( x3, y3, x4, y4, x1, y1 ) = 0 ) then
		exit( false );

	if ( cross_product( x3, y3, x4, y4, x2, y2 ) = 0 ) then
		exit( false );

	vx := x2 - x1;
	vy := y2 - y1;
	ux := x4 - x3;
	uy := y4 - y3;
	
	a := cross_product( 0, 0, x3 - x1, y3 - y1, ux, uy );
	b := cross_product( 0, 0, vx, vy, ux, uy );
	
	if ( b = 0 ) then
		exit( false );
	
	if ( a < 0 ) then
	begin
		a := -a;
		b := -b;
	end;
	
	if ( b < 0 ) then
		exit( false );
	
	exit( a <= b );
end;

function compareSegments( x1, y1, x2, y2, x3, y3, x4, y4: longInt ): longInt;
var	r: longInt;
begin
	if ( cross_product( x1, y1, x2, y2, x3, y3 ) = 0 ) and ( cross_product( x1, y1, x2, y2, x4, y4 ) = 0 ) then
		exit( 0 );
	
	if ( cross_product( 0, 0, x2 - x1, y2 - y1, x4 - x3, y4 - y3 ) = 0 ) then
		exit( compareSegmentsAtX( x1, y1, x2, y2, x3, y3, x4, y4, 0 ) );
	
	r := compareSegmentsAtX( x1, y1, x2, y2, x3, y3, x4, y4, max( x1, x3 ) );
	if ( r = 0 ) then
		r := compareSegmentsAtX( x1, y1, x2, y2, x3, y3, x4, y4, min( x2, x4 ) );
	
	exit( r );
end;

var	n, i, j, u, v: longInt;
	x, y: array[ 1..400, 1..401 ] of longInt;
	len: array[ 1..400 ] of longInt;
	p, q: boolean;

begin
	readln( i, j, n );
	for i := 1 to n do
	begin
		readln( len[i] );
		for j := 1 to len[i] + 1 do
			readln( x[i][j], y[i][j] );
	end;
	
	for i := 1 to n do
		for j := i + 1 to n do
		begin
			p := false;
			q := false;
		
			u := 2;
			v := 2;
			while ( u <= len[i] + 1 ) and ( v <= len[j] + 1 ) do
			begin
				if ( intersects( x[i][u - 1], y[i][u - 1], x[i][u], y[i][u], x[j][v - 1], y[j][v - 1], x[j][v], y[j][v] ) ) then
				begin
					writeln( 'No' );
					writeln( i, ' ', j );
					
					halt;
				end;
			
				if ( compareSegments( x[i][u - 1], y[i][u - 1], x[i][u], y[i][u], x[j][v - 1], y[j][v - 1], x[j][v], y[j][v] ) = -1 ) then
					p := true;
					
				if ( compareSegments( x[i][u - 1], y[i][u - 1], x[i][u], y[i][u], x[j][v - 1], y[j][v - 1], x[j][v], y[j][v] ) = +1 ) then
					q := true;
				
				if ( x[i][u] < x[j][v] ) then
					inc( u )
				else if ( x[j][v] < x[i][u] ) then
					inc( v )
				else
				begin
					inc( u );
					inc( v );
				end;
			end;
			
			if ( p and q ) then
			begin
				writeln( 'No' );
				writeln( i, ' ', j );
				
				halt;
			end;
		end;
	
	writeln( 'Yes' );
end.
