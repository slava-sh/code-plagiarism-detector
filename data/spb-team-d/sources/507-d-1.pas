var n,m,i,j:longint;                   
    y,q,l,r,x: array [1..1000] of longint;



begin

assign(input,'dunes.in');
reset(input);
assign(output,'dunes.out');
rewrite(output);

readln(n,m);
for i:= 1 to n do
	readln(l[i],r[i],x[i]);
for i:= 1 to m do
	readln(q[i]);
for i:= 1 to m do
	y[i]:=0;
for i:= 1 to m do
	for j:=1 to n do                           
		if (q[i] <= r[j])and(q[i]>=l[j]) then begin if ((q[i]-l[j]) mod 2) = 1 then y[i]:=y[i]-x[j]  else y[i]:=y[i]+x[j] end;
for i:=1 to m do
	writeln(y[i]);
end.