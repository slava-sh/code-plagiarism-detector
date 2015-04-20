program dunes;

var coord : array [1..1000, 1..3] of longint;
	n, m : longint;
	cur : longint;
	q, w : longint;
	res : longint;

	function d (x, y : longint) : longint;
	begin;
		if (y-x mod 2) = 0 then d:=1 else
			if (y-x mod 2) = 2 then d:=1 else
				d:=-1;
	end;

begin;

	assign (input, 'dunes.in');
	reset (input);
	assign (output, 'dunes.out');
	rewrite (output);

	readln (n,m);
	for q:=1 to n do
		readln(coord[q,1], coord[q,2], coord[q,3]);

	for q:=1 to m do begin;
		readln (cur);
		res:=0;

		for w:=1 to n do begin;
			if ((coord[w,1] <= cur) and (coord[w,2] >= cur)) then
			res := res + coord[w,3]*d(coord[w,1], cur);
		end;

		writeln (res);		
	end; 

end.