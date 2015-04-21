program problemCyan;
uses math;

type	tSegment =	record
						x1, y1, x2, y2, id: longInt;
					end;
		tSegArr =	array[ 1..500000 ] of tSegment;

var	fwt: array[ 1..100000 ] of longInt;
	lx1, ly1, lx2, ly2: array[ 1..100000 ] of longInt;
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

function fwt_getKth( k: longInt ): longInt;
var	res, i: longInt;
begin
	res := 0;
	for i := 18 downto 0 do
		if ( res + 1 shl i <= n ) and ( fwt[res + 1 shl i] < k ) then
		begin
			dec( k, fwt[res + 1 shl i] );
			inc( res, 1 shl i );
		end;
	
	exit( res + 1 );
end;

function cross_product( x0, y0, x1, y1, x2, y2: int64 ): int64;
begin
	exit( (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0) );
end;

function intersects( x1, y1, x2, y2, x3, y3, x4, y4: longInt ): boolean;
begin
	if ( x1 = x3 ) and ( y1 = y3 ) then
		exit( false );
	
	if ( x1 = x4 ) and ( y1 = y4 ) then
		exit( false );
	
	if ( x2 = x3 ) and ( y2 = y3 ) then
		exit( false );
	
	if ( x2 = x4 ) and ( y2 = y4 ) then
		exit( false );
	
	if ( max( x1, x2 ) < min( x3, x4 ) ) or ( max( x3, x4 ) < min( x1, x2 ) ) then
		exit( false );
	
	if ( max( y1, y2 ) < min( y3, y4 ) ) or ( max( y3, y4 ) < min( y1, y2 ) ) then
		exit( false );
		
	if ( cross_product( x1, y1, x2, y2, x3, y3 ) = 0 ) or ( cross_product( x1, y1, x2, y2, x4, y4 ) = 0 ) then
		exit( false );
	
	exit( ( cross_product( x1, y1, x2, y2, x3, y3 ) > 0 ) xor ( cross_product( x1, y1, x2, y2, x4, y4 ) > 0 ) );
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

procedure checkIntersection( p, q: longInt );
begin
	if ( intersects( lx1[p], ly1[p], lx2[p], ly2[p], lx1[q], ly1[q], lx2[q], ly2[q] ) ) or ( compareSegments( lx1[p], ly1[p], lx2[p], ly2[p], lx1[q], ly1[q], lx2[q], ly2[q] ) = 1 ) then
	begin
		writeln( 'No' );
		writeln( p, ' ', q );
		
		halt;
	end;
end;

procedure qsortByX1( var a: tSegArr; l, r: longInt );
var	i, j, med: longInt;
	t: tSegment;
begin
	if ( l >= r ) then
		exit();
	
	i := l;
	j := r;
	med := a[ l + random(r - l + 1) ].x1;
	while ( i <= j ) do
	begin
		while ( a[i].x1 < med ) do
			inc( i );
		
		while ( a[j].x1 > med ) do
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
	
	qsortByX1( a, l, j );
	qsortByX1( a, i, r );
end;

procedure qsortBySegment( var a: tSegArr; l, r: longInt );
var	i, j: longInt;
	med, t: tSegment;
begin
	if ( l >= r ) then
		exit();
	
	i := l;
	j := r;
	med := a[ l + random(r - l + 1) ];
	while ( i <= j ) do
	begin
		while ( compareSegments( a[i].x1, a[i].y1, a[i].x2, a[i].y2, med.x1, med.y1, med.x2, med.y2 ) = -1 ) do
			inc( i );
		
		while ( compareSegments( a[j].x1, a[j].y1, a[j].x2, a[j].y2, med.x1, med.y1, med.x2, med.y2 ) = +1 ) do
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
	
	qsortBySegment( a, l, j );
	qsortBySegment( a, i, r );
end;

var	minX, maxX, m, i, j, k, x0, y0, x1, y1, x2, y2, len, p1, p2: longInt;
	segments, seg: tSegArr;
	o, w, firstDiff: array[ 1..100000 ] of longInt;

begin
	readln( minX, maxX, n );
	
	m := 0;
	for i := 1 to n do
	begin
		readln( len, x1, y1 );
		
		seg[i].x1 := y1;
		seg[i].id := i;
		
		lx1[i] := -1000000002;
		ly1[i] := 0;
		lx2[i] := x1;
		ly2[i] := y1;
		
		x0 := 0;
		y0 := 0;
		
		for j := 1 to len do
		begin
			readln( x2, y2 );
			
			if ( j > 1 ) and ( cross_product( x0, y0, x1, y1, x2, y2 ) = 0 ) then
			begin
				dec( m );
				x1 := x0;
				y1 := y0;
			end;
			
			inc( m );
			segments[m].x1 := x1;
			segments[m].x2 := x2;
			segments[m].y1 := y1;
			segments[m].y2 := y2;
			segments[m].id := i;
			
			x0 := x1;
			y0 := y1;
			x1 := x2;
			y1 := y2;
		end;
	end;
	
	qsortByX1( seg, 1, n );
	
	for i := 1 to n do
	begin
		o[n + 1 - i] := seg[i].id;
		w[ o[n + 1 - i] ] := n + 1 - i;
	end;
	
	fwt_update( n, +1 );
	for i := n downto 2 do
		if ( seg[i].x1 > seg[i - 1].x1 ) then
		begin
			fwt_update( n + 1 - i, +1 );
			
			firstDiff[n + 1 - i] := -1000000001;
		end;
	
	qsortByX1( segments, 1, m );
	
	i := 1;
	while ( i <= m ) do
	begin
		seg[1] := segments[i];
	
		k := 1;
		while ( i + k <= m ) and ( segments[i + k].x1 = segments[i].x1 ) do
		begin
			inc( k );
			
			seg[k] := segments[i + k - 1];
		end;
		
		qsortBySegment( seg, 1, k );
		
		for j := 1 to k do
			if ( cross_product( lx1[ seg[j].id ], ly1[ seg[j].id ], seg[j].x1, seg[j].y1, seg[j].x2, seg[j].y2 ) > 0 ) then
			begin
				p1 := w[ seg[j].id ];
				p2 := fwt_getKth( fwt_sum( p1 - 1 ) ) + 1;
				
				if ( p1 <> p2 ) then
				begin
					o[p1] := o[p2];
					o[p2] := seg[j].id;
					
					w[ o[p1] ] := p1;
					w[ o[p2] ] := p2;
				end;
				
				if ( fwt_sum( p2 ) = fwt_sum( p2 - 1 ) ) then
				begin
					fwt_update( p2, +1 );
					
					firstDiff[p2] := seg[j].x1;
				end;
			end;
		
		for j := k downto 1 do
			if ( cross_product( lx1[ seg[j].id ], ly1[ seg[j].id ], seg[j].x1, seg[j].y1, seg[j].x2, seg[j].y2 ) < 0 ) then
			begin
				p1 := w[ seg[j].id ];
				p2 := fwt_getKth( fwt_sum( p1 - 1 ) + 1 );
				
				if ( p1 <> p2 ) then
				begin
					o[p1] := o[p2];
					o[p2] := seg[j].id;
					
					w[ o[p1] ] := p1;
					w[ o[p2] ] := p2;
				end;
				
				if ( p2 > 1 ) and ( fwt_sum( p2 - 1 ) = fwt_sum( p2 - 2 ) ) then
				begin
					fwt_update( p2 - 1, +1 );
					
					firstDiff[p2 - 1] := seg[j].x1;
				end;
			end;
		
		for j := 1 to k do
		begin
			lx1[ seg[j].id ] := seg[j].x1;
			ly1[ seg[j].id ] := seg[j].y1;
			lx2[ seg[j].id ] := seg[j].x2;
			ly2[ seg[j].id ] := seg[j].y2;
		end;
		
		for j := 1 to k do
		begin
			p1 := w[ seg[j].id ];
			
			if ( p1 < n ) and ( firstDiff[p1] = seg[j].x1 ) and ( cross_product( seg[j].x1, seg[j].y1, seg[j].x2, seg[j].y2, lx2[ o[p1 + 1] ], ly2[ o[p1 + 1] ] ) = 0 ) and ( fwt_sum( p1 ) > fwt_sum( p1 - 1 ) ) then
				fwt_update( p1, -1 )
			else if ( p1 < n ) then
				checkIntersection( o[p1], o[p1 + 1] );
		end;
		
		inc( i, k );
	end;
	
	writeln( 'Yes' );
end.
