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
			for j := 1 to i do
				doMove( 'R' );
				
			for j := 1 to i do
				doMove( 'U' );
		end
		else
		begin
			for j := 1 to i do
				doMove( 'L' );
				
			for j := 1 to i do
				doMove( 'D' );
		end;
	end;
end.
