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
	for i := 1 to 6000 do
	begin
		if ( odd(i) ) then
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
			
			for j := 1 to i do
			begin
				doMove( 'U' );
				doMove( 'R' );
			end;
		end;
	end;
end.
