program problemBlue_brute;

var	n, l: longInt;
	s: ansistring;
	i, j, k: longInt;
	kmp: array[ 1..1000000 ] of longInt;

begin
	readln( l );
	readln( s );
	n := length( s );
	
	kmp[1] := 0;
	for i := 2 to n do
	begin
		j := kmp[i - 1];
		while ( j > 0 ) and ( s[j + 1] <> s[i] ) do
			j := kmp[j];
		
		if ( s[j + 1] = s[i] ) then
			kmp[i] := j + 1
		else
			kmp[j] := 0;
	end;
	
	if ( kmp[n] >= n div 2 ) and ( n - kmp[n] <= l ) then
	begin
		writeln( 1 );
		for i := 1 to n - kmp[n] do
			write( s[i] );
		writeln();
	end;
	
	writeln( 2 );
	writeln( 'a' );
	writeln( 'b' );
end.
