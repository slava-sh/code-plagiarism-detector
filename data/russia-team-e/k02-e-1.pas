{$Q+,R+}

var
	ar: array[1..1000, 1..100] of longint;
	f: boolean;
	i, j, n, m, kod: longint;
	sp, len: array[1..1000] of longint;
	cnt: int64;

procedure print(gor, op, numb: int64);
var s: string;
begin
	write('+', gor);
	write('(', op, ')');
	str(numb, s);
	if length(s) = 3 then
		writeln(s);
	if length(s) = 4 then
		writeln(s[1], s[2], '-', s[3], s[4]);
	if length(s) = 5 then
		writeln(s[1], s[2], s[3], '-', s[4], s[5]);
	if length(s) = 6 then
		writeln(s[1], s[2], '-', s[3], s[4], '-', s[5], s[6]);
	if length(s) = 7 then
		writeln(s[1], s[2], s[3], '-', s[4], s[5], '-', s[6], s[7]);
end;


function rec(ind, x, t2: int64): boolean;
var i, j: longint; t, a, numb: int64;
begin
        t := t2 div 1000;
	if x div t < 100 then begin
		rec := false;
		exit;
	end;
	for i := 1 to len[ind] do begin
	        t := t2 div 1000;
		for j := 1 to 3 do begin
			a := x div t;
			numb := x mod t;
			if (a = ar[ind, i]) and (numb * 10 div t <> 0) then begin
				print(ind, a, numb);
				rec := true;
				exit;
			end;
			t := t div 10;
		end;
	end;
	rec := false;
end;
		
				


function fix(x: int64): boolean;
var i: longint; t, a: int64;
begin
	t := 10000000000;
	f := false;
	if x div t = 0 then begin
		fix := false;
		exit;
	end;	
	for i := 1 to 3 do begin
		a := x div t;
		if sp[a] > 0 then
			f := rec(a, x - a * t, t);
		if f then begin
			fix := true;
			exit;
		end;	
		t := t div 10;
	end;	
	fix := false;
end;

begin
	assign(input, 'numbers.in'); reset(input);
	assign(output, 'numbers.out'); rewrite(output);

	readln(n);
	for i := 1 to n do begin
		read(kod);
                readln(len[kod]);
		sp[kod] := i;
		for j := 1 to len[kod] do
			readln(ar[kod, j]);
	end;
	readln(m);
	for i := 1 to m do begin
		readln(cnt);
		if not fix(cnt) then
			writeln('Incorrect');
	end;	
end.

