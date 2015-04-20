var a:array[1..10001] of longint; 
n,r,i,s,j:longint;
begin s:=0;
	assign(input,'che.in');reset(input);
	assign(output,'che.out');rewrite(output);
	read(n,r);
         for i:=1 to n do
	   read(a[i]);

	for i:=1 to n do
	 for j:=i to n do
	begin
		
		if abs(a[i]-a[j])>r then inc(s);
	end;
	write(s);
	close(input);
	close(output);
end.