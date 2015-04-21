{$O+}
program problemRed;

var	fwt: array[ 1..500000 ] of longInt;
	m: longInt;

procedure fwt_update( x, d: longInt );
begin
	while ( x <= 400000 ) do
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
		if ( res + 1 shl i <= 2 * m ) and ( fwt[res + 1 shl i] < k ) then
		begin
			dec( k, fwt[res + 1 shl i] );
			inc( res, 1 shl i );
		end;
		
	exit( res + 1 );
end;

var	u, v, t, uu, vv, tt, cnt, l, r, ll, rr, next, prev, fwt_save, queue, dist: array[ 0..500000 ] of longInt;
	n, d, q, a, b, i, lll, rrr, ccc, ans: longInt;

begin
	fillchar( cnt, sizeOf(cnt), 0 );

	readln( n, m, d );
	for i := 1 to m do
	begin
		readln( u[2 * i - 1], v[2 * i - 1], t[2 * i - 1] );
		u[2 * i] := v[2 * i - 1];
		v[2 * i] := u[2 * i - 1];
		t[2 * i] := t[2 * i - 1];
		
		inc( cnt[ u[2 * i] ] );
		inc( cnt[ v[2 * i] ] );
	end;
	
	l[1] := 1;
	r[1] := 0;
	for i := 2 to n do
	begin
		l[i] := l[i - 1] + cnt[i - 1];
		r[i] := l[i] - 1;
	end;
	
	for i := 1 to 2 * m do
	begin
		inc( r[ u[i] ] );
		uu[ r[ u[i] ] ] := u[i];
		vv[ r[ u[i] ] ] := v[i];
		tt[ r[ u[i] ] ] := t[i];
	end;
	
	for i := 1 to 2 * m do
	begin
		u[i] := uu[i];
		v[i] := vv[i];
		t[i] := tt[i];
	end;
	
	for i := 1 to 2 * m do
	begin
		lll := l[ v[i] ];
		rrr := r[ v[i] ];
		while ( lll < rrr ) do
		begin
			ccc := (lll + rrr) div 2;
			
			if ( t[ccc] < t[i] - d ) then
				lll := ccc + 1
			else
				rrr := ccc;
		end;
		
		ll[i] := lll;
		
		lll := l[ v[i] ];
		rrr := r[ v[i] ];
		while ( lll < rrr ) do
		begin
			ccc := (lll + rrr + 1) div 2;
			
			if ( t[ccc] > t[i] + d ) then
				rrr := ccc - 1
			else
				lll := ccc;
		end;
		
		rr[i] := lll;
	end;
	
	for i := 1 to 2 * m do
		fwt_update( i, +1 );
	
	for i := 1 to 2 * m do
		fwt_save[i] := fwt[i];
	
	readln( q );
	while ( q > 0 ) do
	begin
		for i := 1 to 2 * m do
		begin
			prev[i] := i - 1;
			next[i] := i + 1;
			
			fwt[i] := fwt_save[i];
		end;
	
		readln( a, b );
		
		ll[2 * m + 1] := l[a];
		rr[2 * m + 1] := r[a];
		dist[2 * m + 1] := 0;
		
		ans := -1;
		lll := 1;
		rrr := 1;
		queue[1] := 2 * m + 1;
		while ( lll <= rrr ) and ( ans = -1 ) do
		begin
			i := fwt_getKth( fwt_sum( ll[ queue[lll] ] - 1 ) + 1 );
			while ( i <= rr[ queue[lll] ] ) do
			begin
				if ( v[i] = b ) then
				begin
					ans := dist[ queue[lll] ] + 1;
					
					break;
				end;
				
				dist[i] := dist[ queue[lll] ] + 1;
				inc( rrr );
				queue[rrr] := i;
				
				next[ prev[i] ] := next[i];
				prev[ next[i] ] := prev[i];
				
				fwt_update( i, -1 );
			
				i := next[i];
			end;
			
			inc( lll );
		end;
		
		writeln( ans );
		
		dec( q );
	end;
end.
