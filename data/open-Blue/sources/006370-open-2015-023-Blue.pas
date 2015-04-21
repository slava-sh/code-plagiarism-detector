program problemBlue_brute;

type	tTrieNode =	record
						next: array[ 'a'..'c' ] of longInt;
					end;
					
var	t: array[ 1..1000000 ] of tTrieNode;
	ok: array[ 1..1000000 ] of boolean;
	id: array[ 1..1000, 1..1000 ] of longInt;
	strs, curStrs: array[ 1..20000 ] of longInt;
	tw: longInt = 1;
	n, l, ans: longInt;
	s: ansistring;


function newTrieNode(): longInt;
begin
	inc( tw );
	
	exit( tw );
end;

procedure addSubstrings( l: longInt );
var	v, i: longInt;
begin
	v := 1;
	for i := l to n do
	begin
		if ( t[v].next[ s[i] ] = 0 ) then
			t[v].next[ s[i] ] := newTrieNode();
		
		v := t[v].next[ s[i] ];
		
		id[l][i] := v;
	end;
end;

procedure brute( p, cur: longInt );
var	i: longInt;
	f: boolean;
begin
	if ( cur >= ans ) then
		exit();

	if ( p > n ) then
	begin
		ans := cur;
		
		move( curStrs, strs, 4 * ans );
		
		exit();
	end;
	
	for i := p + l - 1 downto p do
	begin
		f := ok[ id[p][i] ];
		
		if ( not f ) then
		begin
			ok[ id[p][i] ] := true;
			inc( cur );
			curStrs[cur] := id[p][i];
		end;
		
		brute( i + 1, cur );
		
		if ( not f ) then
		begin
			ok[ id[p][i] ] := false;
			dec( cur );
		end;
	end;
end;

var	i, j, k: longInt;

begin
	readln( l );
	readln( s );
	n := length( s );
	
	ans := (n + l - 1) div l + 1;
	
	for i := 1 to n do
		addSubstrings( i );
	
	brute( 1, 0 );
	
	for i := 1 to ans do
		ok[ strs[i] ] := true;
	
	writeln( ans );
	for i := 1 to n do
		for j := i to n do
			if ( ok[ id[i][j] ] ) then
			begin
				ok[ id[i][j] ] := false;
				
				for k := i to j do
					write( s[k] );
				writeln();
			end;
end.
