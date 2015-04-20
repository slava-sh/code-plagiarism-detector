program chess;

var n, a : longint;
	rdd, q : longint;

begin;

	assign (input, 'chess.in');
	reset (input);
	assign (output, 'chess.out');
	rewrite (output);

	readln (n);
	a := 0;

	repeat
		a := a+1;
		read (rdd);		
	until (rdd<a) or (a=n+1);

	writeln (a-1);
	for q:=1 to a-1 do writeln (q, ' ', q);

	close (output);

end.
