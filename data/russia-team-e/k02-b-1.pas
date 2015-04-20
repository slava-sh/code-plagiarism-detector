const maxN = 300100;

var
	n, dist, i, l, r, m: longint;
	ans: int64;
	d: array[1..maxN] of longint;

begin
	assign(input, 'che.in'); reset(input);
	assign(output, 'che.out'); rewrite(output);

	read(n, dist);
	for i := 1 to n do
		read(d[i]);
	for i := 1 to n - 1 do begin
		l := i;
		r := n;
		while r - l > 1 do begin
			m := (l + r) div 2;
			if d[m] - d[i] > dist then
				r := m
			else
				l := m;
		end;
		if d[r] - d[i] > dist then
			ans := ans + (n - r + 1);
	end;
	write(ans);
end.	

		 	