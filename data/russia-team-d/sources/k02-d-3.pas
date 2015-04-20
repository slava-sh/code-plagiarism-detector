{$Q+,R+}

uses math;

const maxN = 100100;

var
	a: array[1..maxN] of longint;
	i: longint;
	maxx, l, r, k: int64;
	n, m, inf: int64;

procedure swap(var a, b: longint);
var tmp: longint;
begin
	tmp := a; a := b; b := tmp;
end;	

procedure sort(l, r: longint);
var i, j, s: int64;
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

function ok(x: longint): boolean;
var ind: int64;
begin
	ok := true;
	ind := a[1];
	for i := 2 to n do begin
		ind := max(abs(a[i] - ind), x) + ind;
		if ind > k then begin
			ok := false;
			break;
		end;	
	end;	
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
		if ok(m) then
			l := m
		else
			r := m;	
	end;	
	write(l);
end.	
		