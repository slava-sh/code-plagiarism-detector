uses math;

var
	n, m, a: longint;

begin
	assign(input, 'prizes.in'); reset(input);
	assign(output, 'prizes.out'); rewrite(output);

	read(n, m);
	if (n = 2) or (m = 2) then begin
		write(0);
		halt;
	end;	
	if (n = 1) or (m = 1) then begin
		write((max(n, m) - 3) div 4 + 1);
		halt;
	end;	
	a := min(n, m) - 3;
	write(a div 4 + 1);
end.	
