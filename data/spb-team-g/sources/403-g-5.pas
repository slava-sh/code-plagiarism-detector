var i, n, k,j:longint;
a: array [1..19000] of longint;
f1,f2:text;
begin
assign(f1, 'merlin.in');
assign(f2, 'merlin.out');
reset(f1);
rewrite(f2);
readln(f1, n);
for i:= 1 to n do read(f1, a[i]);
for i:= 1 to n do
 for j:= 1 to n do if ((a[i]=a[j]) and (i<>j)) then inc(k);
writeln(f2, ((n - (k div 2)) div 3) + n mod 2);
close(f1);
close(f2);
end.