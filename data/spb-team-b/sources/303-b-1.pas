var n,i,j:integer;
a:array[0..1000]of integer;
begin
assign(input,'chess.in');
assign(output,'chess.out');
reset(input);
rewrite(output);
readln(n);
i:=0;
while(a[i]>=i)and(i<=n-1)do
begin
 inc(i);
 read(a[i]);
end;
if (i<n) then dec(i)
   else if a[i]<i then dec(i);                         
writeln(i);
for j:=1 to i do
writeln(j,' ',j);
close(input);
close(output);
end.