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
	doMove( 'U' );
	doMove( 'R' );
	doMove( 'D' );
	doMove( 'R' );
	
	for i := 1 to 20 do
	begin
		for j := 1 to 2 * i do
			doMove( 'U' );
			
		for j := 1 to 2 * i do
			doMove( 'L' );
		
		doMove( 'U' );
		
		for j := 0 to 2 * i do
			doMove( 'R' );
			
		for j := 0 to 2 * i do
			doMove( 'D' );
		
		doMove( 'R' );
	end;
end.
