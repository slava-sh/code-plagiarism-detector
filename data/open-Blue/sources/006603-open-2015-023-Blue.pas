program problemBlue_brute;

var	n, l: longInt;
	s: ansistring;
	i, j, k: longInt;

begin
	readln( l );
	readln( s );
	n := length( s );
	
	if ( l >= n ) then
	begin
		writeln( 1 );
		writeln( s );
		
		halt;
	end;
	
	writeln( 2 );
	writeln( 'a' );
	writeln( 'b' );
end.
