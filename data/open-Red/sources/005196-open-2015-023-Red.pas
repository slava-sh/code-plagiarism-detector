{$O+}
program problemRed;
uses math;

var	u, v, t, uu, vv, tt, cnt, l, r, ll, rr, queue, dist, group, groupLeftT, groupL, groupR, groupL_save, groupR_save: array[ 0..500000 ] of longInt;
	used: array[ 0..500000 ] of boolean;
	n, m, d, q, a, b, i, lll, rrr, ccc, ans, lb, rb: longInt;

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
	
	q := 1;
	groupLeftT[1] := t[1];
	groupL_save[1] := 1;
	groupR_save[1] := 1;
	group[1] := 1;
	for i := 2 to 2 * m do
	begin
		if ( u[i] <> u[i - 1] ) or ( t[i] > groupLeftT[q] + 2 * d ) then
		begin
			inc( q );
			groupLeftT[q] := t[i];
			groupL_save[q] := i;
		end;
		
		group[i] := q;
		groupR_save[q] := i;
	end;
	
//	for i := 1 to 2 * m do
//		writeln( u[i], ' ', v[i], ' ', t[i], ' ', group[i] );
	
	groupL[q + 1] := 2 * m + 1;
	
	readln( q );
	while ( q > 0 ) do
	begin
		fillchar( used, sizeOf(used), 0 );
		
		for i := 1 to group[2 * m] do
		begin
			groupL[i] := groupL_save[i];
			groupR[i] := groupR_save[i];
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
			lb := ll[ queue[lll] ];
			rb := rr[ queue[lll] ];
		
//			writeln( u[ queue[lll] ], ' ', v[ queue[lll] ], ' ', t[ queue[lll] ], ' ', ll[ queue[lll] ], ' ', rr[ queue[lll] ] );
		
			if ( lb > groupR[ group[lb] ] ) or ( groupL[ group[lb] ] > groupR[ group[lb] ] ) then
			begin
				if ( groupL[ group[lb] + 1 ] <= groupR[ group[lb] + 1 ] ) then
					i := groupL[ group[lb] + 1 ]
				else
					i := 2 * m + 1;
			end
			else
				i := max( lb, groupL[ group[lb] ] );
			
//			writeln( i, ' ', groupL[ group[ ll[ queue[lll] ] ] ], ' ', groupR[ group[ ll[ queue[lll] ] ] ] );
			
			if ( group[rb] > group[lb] ) then
			begin
				groupR[ group[lb] ] := min( groupR[ group[lb] ], lb - 1 );
				groupL[ group[rb] ] := max( groupL[ group[rb] ], rb + 1 );
			end
			else
			begin
				if ( lb <= groupL[ group[lb] ] ) then
					groupL[ group[lb] ] := max( groupL[ group[lb] ], rb + 1 );
				
				if ( rb >= groupR[ group[lb] ] ) then
					groupR[ group[lb] ] := min( groupR[ group[lb] ], lb - 1 );
			end;
			
			while ( i <= rb ) and ( not used[i] ) do
			begin
				used[i] := true;
			
				if ( v[i] = b ) then
				begin
					ans := dist[ queue[lll] ] + 1;
					
					break;
				end;
				
				dist[i] := dist[ queue[lll] ] + 1;
				inc( rrr );
				queue[rrr] := i;
				
				inc( i );
			end;
			
			inc( lll );
		end;
		
		writeln( ans );
		
		dec( q );
	end;
end.
