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
	for i := 1 to 10 do
	begin
		for j := 1 to 20 do
			doMove( 'U' );
		
		doMove( 'R' );
		for j := 1 to 20 do
			doMove( 'D' );
		
		doMove( 'R' );
	end;
end.
