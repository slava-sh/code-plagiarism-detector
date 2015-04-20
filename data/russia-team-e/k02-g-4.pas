{$Q+,R+}

uses math;

var
	n, m: int64;

begin
	assign(input, 'prizes.in'); reset(input);
	assign(output, 'prizes.out'); rewrite(output);

	read(n, m);
	if (n <= 2) and (m <= 2) then 
		write(0)
	else if (n = 2) or (m = 2) then
		write(0)
	else if (n = 1) or (m = 1) then
		write((max(n, m) - 3) div 4 + 1)
	else
		write((min(n, m) - 3) div 4 + 1);
end.	
