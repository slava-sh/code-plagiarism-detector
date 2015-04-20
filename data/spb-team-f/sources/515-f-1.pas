program gcm;

var a, b, pr, g : longint;

	function greatest (a, b : longint) : longint;
	begin;
		if a=0 then greatest:=b
			else greatest := greatest (b mod a, a);
	end;

begin;
	assign (input, 'gcm.in');
	reset (input);
	assign (output, 'gcm.out');
	rewrite (output);

	read (a,b);

	pr := floor(sqrt(a*b));
	g := greatest (a,b);

	while (pr mod g <> 0) do
		pr := pr-1;

	write (pr); write (' ');
	write (a*b/pr);
end.