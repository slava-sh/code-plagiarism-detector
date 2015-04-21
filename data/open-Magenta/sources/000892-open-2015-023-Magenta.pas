program problemMagenta;

procedure doMove( c: char );
begin
	writeln( c );
	flush( output );
	
	readln( c );
	
	if ( c <> 'N' ) then
		halt;
end;

var	i, j: longInt;

begin
	while ( true ) do
	begin
		doMove( 'R' );
		doMove( 'R' );
		doMove( 'U' );
	end;
end.
