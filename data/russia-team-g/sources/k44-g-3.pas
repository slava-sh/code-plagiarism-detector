uses math;  
var c,q,n,m:longint;
procedure inca(n,m:longint);
begin
c:=(n div 4)+(m div 2)+c;
q:=c;
end;
procedure incc(n:longint);
begin
c:=(n div 4)+c;
end;
procedure incq(n:longint);
begin
q:=(m div 2)+q;
end;

begin 

	assign(input,'prizes.in');reset(input);
	assign(output,'prizes.out');rewrite(output);
read(n,m);

if n>2 then c:=1;
if m>2 then q:=1;
n:=n-2;m:=m-2;
if n mod 4=0 then incc(n) else inca(n,m);
if m mod 4=0 then incq(m) else inca(n,m);
write(min(c,q));
	close(input);
	close(output);
end.