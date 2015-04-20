var a:array[1..100000000] of longint; 
n,r,i,s,j:longint;
begin 
s:=0;
	assign(input,'che.in');reset(input);
	assign(output,'che.out');rewrite(output);
	
	read(n,r);
  

	for i:=n downto 1  do
	 	begin
read(a[i]);
	end;
for i:= 1 to n-1  do
begin
for j:=i to n do
begin
if ((abs(a[i]-a[j])>r) and (a[i]<>a[j])) then inc(s);
end;
end;
	write(s);
	close(input);
	close(output);
end.