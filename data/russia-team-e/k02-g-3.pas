uses math;

var
	maxx, minx, n, m, a: int64;

begin
	assign(input, 'prizes.in'); reset(input);
	assign(output, 'prizes.out'); rewrite(output);

	read(n, m);   
	maxx := max(n, m);
	minx := min(n, m);
	if (n = 1) and (m = 1) then begin
		write(0);
		halt;
	end;	
	if (n = 2) or (m = 2) then begin
		write(0);
		halt;
	end;	
	if (n = 1) or (m = 1) then begin
		write((maxx - 3) div 4 + 1);
		halt;
	end;	
	write((minx - 3) div 4 + 1);
end.	
