{$Q+,R+}

const maxN = 200000;

var
	a: array[1..maxN] of longint;
	l, r, k, i: longint;
	n, m, inf: int64;

procedure swap(var a, b: longint);
var tmp: longint;
begin
	tmp := a; a := b; b := tmp;
end;	

procedure sort(l, r: longint);
var i, j, s: longint;
begin
	if l >= r then exit;
	i := l;
	j := r;
	s := a[(l + r) div 2];
	repeat
		while a[i] < s do inc(i);
		while a[j] > s do dec(j);
		if i <= j then begin
			swap(a[i], a[j]);
			inc(i); dec(j);
		end;
	until i > j;
	sort(i, r);
	sort(l, j);
end;	



begin
	assign(input, 'fence.in'); reset(input);
	assign(output, 'fence.out'); rewrite(output);

	read(n, k);
	for i := 1 to n do
		read(a[i]);
	sort(1, n);	
	l := 0;
	r := a[1] + 1;
	while r - l > 1 do begin
		m := (l + r) div 2;
		inf := (n - 1) * m + a[1];
		if inf > k then 
			r := m
		else
			l := m;
	end;	
	write(l);
end.	
		