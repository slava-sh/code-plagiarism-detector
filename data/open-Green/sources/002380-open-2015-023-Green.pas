{$O+}
program problemGreen;
uses math;

var	primes: array[ 1..100000 ] of int64;
	pow: array[ 1..100000 ] of longInt;
	dp: array[ 0..100000, 0..10 ] of int64;
	k, primeCnt: longInt;
	n: int64;

function dfs2( k, mask, id, mult: longInt; x: int64 ): int64;
var	p, i: longInt;
	res: int64;
begin
	res := dp[mask][k] * ( ( x + 1 ) div 2 );
	if ( id > primeCnt ) then
		exit( res );

	p := ( mask div mult ) mod ( pow[id] + 1 );
	
	for i := 0 to p do
	begin
		res := min( res, dfs2( k, mask - i * mult, id + 1, mult * ( pow[id] + 1 ), x ) );
		
		x := x * primes[id];
	end;
	
	exit( res );
end;
	
function dfs( mask, id, mult: longInt; calc: boolean ): int64;
var	i: longInt;
	res: int64;
begin
	if ( calc ) then
	begin
		if ( mask = 0 ) then
		begin
			for i := 0 to k do
				dp[mask][i] := 1;
		end
		else
		begin
			dp[mask][0] := n + 1;
			for i := 1 to k do
				dp[mask][i] := dfs2( i - 1, mask, 1, 1, 1 );
		end;
	end;
	
	if ( id <= primeCnt ) then
	begin
		for i := 0 to pow[id] do
			res := dfs( mask + i * mult, id + 1, mult * ( pow[id] + 1 ), i > 0 );
	end
	else
		res := dp[mask][k];
	
	exit( res );
end;

var	nn, x: int64;

begin
	readln( n, k );
	
	while ( k > 0 ) and ( n mod 2 = 0 ) do
	begin
		dec( k );
		n := n div 2;
	end;
	
	if ( k = 0 ) then
	begin
		writeln( n );
		
		halt;
	end;
		
	primeCnt := 0;
	
	x := 2;
	nn := n;
	while ( nn div x >= x ) do
	begin
		if ( nn mod x = 0 ) then
		begin
			inc( primeCnt );
			primes[primeCnt] := x;
			pow[primeCnt] := 0;
			
			while ( nn mod x = 0 ) do
			begin
				nn := nn div x;
				inc( pow[primeCnt] );
			end;
		end;
	
		inc( x, 1 );
	end;
	
	if ( nn > 1 ) then
	begin
		inc( primeCnt );
		primes[primeCnt] := nn;
		pow[primeCnt] := 1;
	end;
	
	writeln( dfs( 0, 1, 1, true ) );
end.
