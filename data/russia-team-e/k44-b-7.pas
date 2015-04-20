var a:array[1..100000000] of longint; 
n,r,i,s,j,max:longint;
procedure maxmax;
begin
for i:=1 to n do
begin
	if(max-a[i])>r then 
	begin
	inc(s);
	end;
	inc(j);
	max:=a[j];
	a[j-1]:=0;
	break;
end;
end;
begin max:=a[1]; 
s:=0;j:=1;
	assign(input,'che.in');reset(input);
	assign(output,'che.out');rewrite(output);
	
	read(n,r);
  

	for i:=n downto 1  do
	 	begin
read(a[i]);
	end;
for j:=1 to n do	
begin
maxmax;
end;
	write(s);
	close(input);
	close(output);
end.